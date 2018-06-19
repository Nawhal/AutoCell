#include "configgameoflifeautomatonwindow.h"
#include "ui_configgameoflifeautomatonwindow.h"
#include "simulationwindow.h"
#include "windowmanager.h"
#include "mainwindow.h"
#include "xmlautomatondatamanager.h"

#include <QFileDialog>

ConfigGameOfLifeAutomatonWindow::ConfigGameOfLifeAutomatonWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ConfigGameOfLifeAutomatonWindow)
{
    ui->setupUi(this);
}

void ConfigGameOfLifeAutomatonWindow::previousWindow()
{
    WindowManager::getInstance().openWindow(new MainWindow());
    WindowManager::getInstance().closeWindow(this);
}

void ConfigGameOfLifeAutomatonWindow::saveConfig()
{
    QString completePath = QFileDialog::getSaveFileName(this,
        "Sauvegarder la configuration d'automate jeu de la vie", "",
        "eXtensible Markup Language Files (*.xml);;All Files (*)");
    if (completePath.isEmpty()) { return; }
    try {
        bool worked;
        unsigned int columnNb = ui->colNbLineEdit->text().toUInt(&worked);
        if (!worked) { columnNb = 0; }
        unsigned int lineNb = ui->lineNbLineEdit->text().toUInt(&worked);
        if (!worked) { lineNb = 0; }
        unsigned int minDeath = ui->minDeathLineEdit->text().toUInt(&worked);
        if (!worked) { minDeath = 0; }
        unsigned int maxDeath = ui->maxDeathLineEdit->text().toUInt(&worked);
        if (!worked) { maxDeath = 0; }
        unsigned int index = completePath.lastIndexOf("/");
        QString dirPath = completePath.left(index);
        QString fileName = completePath.right(completePath.length() - index - 1);
        XmlAutomatonDataManager::getInstance().writeGameOfLifeAutomatonConfig(columnNb, lineNb, minDeath, maxDeath, dirPath, fileName);
    } catch (std::exception e) { }
}

void ConfigGameOfLifeAutomatonWindow::loadConfig()
{
    QString completePath = QFileDialog::getOpenFileName(this,
        "Charger la configuration d'automate jeu de la vie", "",
        "eXtensible Markup Language Files (*.xml);;All Files (*)");
    if (completePath.isEmpty()) { return; }
    try {
        unsigned int index = completePath.lastIndexOf("/");
        QString dirPath = completePath.left(index);
        QString fileName = completePath.right(completePath.length() - index - 1);
        unsigned int columnNb;
        unsigned int lineNb;
        unsigned int minDeath;
        unsigned int maxDeath;
        std::tie(columnNb, lineNb, minDeath, maxDeath) = XmlAutomatonDataManager::getInstance().readGameOfLifeAutomatonConfig(dirPath, fileName);
        ui->colNbLineEdit->setText(QString::number(columnNb));
        ui->lineNbLineEdit->setText(QString::number(lineNb));
        ui->minDeathLineEdit->setText(QString::number(minDeath));
        ui->maxDeathLineEdit->setText(QString::number(maxDeath));
    } catch (std::exception e) { }
}

void ConfigGameOfLifeAutomatonWindow::launchAutomaton()
{
    bool worked;
    unsigned int columnNb = ui->colNbLineEdit->text().toUInt(&worked);
    if (!worked) { columnNb = 0; }
    unsigned int lineNb = ui->lineNbLineEdit->text().toUInt(&worked);
    if (!worked) { lineNb = 0; }
    unsigned int minDeath = ui->minDeathLineEdit->text().toUInt(&worked);
    if (!worked) { minDeath = 0; }
    unsigned int maxDeath = ui->maxDeathLineEdit->text().toUInt(&worked);
    if (!worked) { maxDeath = 0; }

    SimulationWindow *sw = new SimulationWindow();
    sw->setup(new QtSimulator(new GameOfLifeAutomaton(minDeath, maxDeath), State(lineNb, columnNb), sw), lineNb, columnNb);
    WindowManager::getInstance().openWindow(sw);
    WindowManager::getInstance().closeWindow(this);
}

ConfigGameOfLifeAutomatonWindow::~ConfigGameOfLifeAutomatonWindow()
{
    delete ui;
}

void ConfigGameOfLifeAutomatonWindow::closeEvent(QCloseEvent *event)
{
    WindowManager::getInstance().removeWindow(this);
    QWidget::closeEvent(event);
}
