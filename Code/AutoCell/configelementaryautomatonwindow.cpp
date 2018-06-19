#include "configelementaryautomatonwindow.h"
#include "ui_configelementaryautomatonwindow.h"
#include "simulationwindow.h"
#include "windowmanager.h"
#include "mainwindow.h"
#include "xmlautomatondatamanager.h"
#include "qtelementarysimulator.h"
#include "elementaryAutomaton.h"

#include <QFileDialog>

ConfigElementaryAutomatonWindow::ConfigElementaryAutomatonWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ConfigElementaryAutomatonWindow)
{
    ui->setupUi(this);
}

void ConfigElementaryAutomatonWindow::previousWindow()
{
    WindowManager::getInstance().openWindow(new MainWindow());
    WindowManager::getInstance().closeWindow(this);
}

void ConfigElementaryAutomatonWindow::saveConfig()
{
    QString completePath = QFileDialog::getSaveFileName(this,
        "Sauvegarder la configuration d'automate à 1 dimension", "",
         "eXtensible Markup Language Files (*.xml);;All Files (*)");
    if (completePath.isEmpty()) { return; }
    try {
        bool worked;
        unsigned int cellNb = ui->cellNbLineEdit->text().toUInt(&worked);
        if (!worked) { cellNb = 0; }
        unsigned int stateNb = ui->stateNbLineEdit->text().toUInt(&worked);
        if (!worked) { stateNb = 0; }
        unsigned int ruleNb = ui->ruleLineEdit->text().toUInt(&worked);
        if (!worked) { ruleNb = 0; }
        unsigned int index = completePath.lastIndexOf("/");
        QString dirPath = completePath.left(index);
        QString fileName = completePath.right(completePath.length() - index - 1);
        XmlAutomatonDataManager::getInstance().writeElementaryAutomatonConfig(cellNb, stateNb, ruleNb, dirPath, fileName);
    } catch (std::exception e) { }
}

void ConfigElementaryAutomatonWindow::loadConfig()
{
    QString completePath = QFileDialog::getOpenFileName(this,
        "Charger la configuration d'automate à 1 dimension", "",
        "eXtensible Markup Language Files (*.xml);;All Files (*)");
    if (completePath.isEmpty()) { return; }
    try {
        unsigned int index = completePath.lastIndexOf("/");
        QString dirPath = completePath.left(index);
        QString fileName = completePath.right(completePath.length() - index - 1);
        unsigned int cellNb;
        unsigned int stateNb;
        unsigned int ruleNb;
        std::tie(cellNb, stateNb, ruleNb) = XmlAutomatonDataManager::getInstance().readElementaryAutomatonConfig(dirPath, fileName);
        ui->cellNbLineEdit->setText(QString::number(cellNb));
        ui->stateNbLineEdit->setText(QString::number(stateNb));
        ui->ruleLineEdit->setText(QString::number(ruleNb));
        // TODO tab : bind or set or something
    } catch (std::exception e) { }
}

void ConfigElementaryAutomatonWindow::launchAutomaton()
{
    bool worked;
    unsigned int cellNb = ui->cellNbLineEdit->text().toUInt(&worked);
    if (!worked) { cellNb = 0; }
    unsigned int stateNb = ui->stateNbLineEdit->text().toUInt(&worked);
    if (!worked) { stateNb = 0; }
    unsigned int ruleNb = ui->ruleLineEdit->text().toUInt(&worked);
    if (!worked) { ruleNb = 0; }

    SimulationWindow *sw = new SimulationWindow();
    sw->setup(new QtElementarySimulator(new ElementaryAutomaton(ruleNb), State(1, cellNb), stateNb, sw), stateNb, cellNb);
    WindowManager::getInstance().openWindow(sw);
    WindowManager::getInstance().closeWindow(this);
}

ConfigElementaryAutomatonWindow::~ConfigElementaryAutomatonWindow()
{
    delete ui;
}

void ConfigElementaryAutomatonWindow::closeEvent(QCloseEvent *event)
{
    WindowManager::getInstance().removeWindow(this);
    QWidget::closeEvent(event);
}
