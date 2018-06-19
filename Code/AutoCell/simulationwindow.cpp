#include "simulationwindow.h"
#include "ui_simulationwindow.h"
#include "windowmanager.h"
#include "QFileDialog"

SimulationWindow::SimulationWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SimulationWindow)
{
    ui->setupUi(this);
    timer = new QTimer(this);
    QObject::connect(timer, SIGNAL(timeout()), this, SLOT(run()));
    timer->setInterval(1000);
}

void SimulationWindow::saveAutomaton()
{
    QString completePath = QFileDialog::getSaveFileName(this,
        "Sauvegarder l'automate", "",
         "eXtensible Markup Language Files (*.xml);;All Files (*)");
    if (completePath.isEmpty()) { return; }
    try {
        unsigned int index = completePath.lastIndexOf("/");
        QString dirPath = completePath.left(index);
        QString fileName = completePath.right(completePath.length() - index - 1);
        simulator->saveAutomaton(dirPath, fileName);
    } catch (std::exception e) { }
}

void SimulationWindow::loadAutomaton()
{
    QString completePath = QFileDialog::getOpenFileName(this,
        "Charger l'automate", "",
        "eXtensible Markup Language Files (*.xml);;All Files (*)");
    if (completePath.isEmpty()) { return; }
    try {
        unsigned int index = completePath.lastIndexOf("/");
        QString dirPath = completePath.left(index);
        QString fileName = completePath.right(completePath.length() - index - 1);
        simulator->loadAutomaton(dirPath, fileName);
    } catch (std::exception e) { }
}

void SimulationWindow::updateSpeed()
{
    bool worked;
    unsigned int speed = ui->speedLineEdit->text().toUInt(&worked);
    if (!worked) { return; }
    timer->setInterval(speed);
}

SimulationWindow::~SimulationWindow()
{
    delete ui;
    delete simulator;
    delete timer;
}

void SimulationWindow::setup(Simulator *sim, unsigned int nbLines, unsigned int nbCol)
{
    simulator = sim;
    setupTable(nbCol, nbLines);
}

void SimulationWindow::setupTable(unsigned int nbCol, unsigned int nbLines)
{
    ui->tableWidget->setColumnCount(nbCol);
    ui->tableWidget->setRowCount(nbLines);

    const unsigned int width = ui->tableWidget->geometry().width() / nbCol;
    const unsigned int height = ui->tableWidget->geometry().height() / nbLines;
    for (unsigned int i = 0; i < nbCol; i++) {
        ui->tableWidget->setColumnWidth(i, width);
        ui->tableWidget->setRowHeight(i, height);
        for (unsigned j = 0; j < nbLines; j++) {
            ui->tableWidget->setItem(j, i, new QTableWidgetItem(""));
        }
    }
}

void SimulationWindow::setupSimulation()
{
    unsigned int colNb = ui->tableWidget->columnCount();
    unsigned int lineNb =
        strcmp(abi::__cxa_demangle(typeid(*simulator).name(), 0, 0, 0), "QtElementarySimulator") == 0 ?
            1 : ui->tableWidget->rowCount();
    State state(lineNb, colNb);
    for (unsigned int line = 0; line < lineNb; line++) {
        for (unsigned int col = 0; col < colNb; col++) {
            QTableWidgetItem* cell = ui->tableWidget->item(line, col);
            if (cell == nullptr) { continue; }

            state.changeCell(line, col, Cell(cell->text() == "."));
        }
    }
    simulator->resetState(state);
}

void SimulationWindow::setDisplayedAutomatonValues(std::vector< std::vector<bool> > values)
{
    unsigned int nbCol = values[0].size();
    unsigned int nbLines = values.size();

    for (unsigned int i = 0; i < nbLines; i++) {
        for (unsigned j = 0; j < nbCol; j++) {
            QTableWidgetItem* cell = ui->tableWidget->item(i, j);
            if (values[i][j]) {
                cell->setBackgroundColor("black");
                cell->setTextColor("black");
            } else {
                cell->setBackgroundColor("white");
                cell->setTextColor("white");
            }
        }
    }
}

void SimulationWindow::cellActivation(const QModelIndex &index)
{
    if (simulator->getSimState() != STOPPED) { return; }
    if (isOfType(*simulator, "QtElementarySimulator") && index.row() >= 1) { return; }

    QTableWidgetItem* cell = ui->tableWidget->item(index.row(), index.column());
    if (cell->text() == "") {
        // La cellule est désactivée
        cell->setText(".");
        cell->setBackgroundColor("black");
        cell->setTextColor("black");
    } else {
        // La cellule est activée
        cell->setText("");
        cell->setBackgroundColor("white");
        cell->setTextColor("white");
    }
}

void SimulationWindow::closeEvent(QCloseEvent *event)
{
    WindowManager::getInstance().removeWindow(this);
    QWidget::closeEvent(event);
}

void SimulationWindow::playPause()
{
    if (simulator->getSimState() == RUNNING) {
        timer->stop();
        simulator->pause();
    } else {
        if (simulator->getSimState() == STOPPED) {
            setupSimulation();
        }
        simulator->run();
        timer->start();
    }
}

void SimulationWindow::stepByStep()
{
    if (simulator->getSimState() == STOPPED) {
        setupSimulation();
    }
    simulator->stepRun();
}

void SimulationWindow::stop()
{
    timer->stop();
    simulator->stop();
}

void SimulationWindow::run()
{
    simulator->run();
}
