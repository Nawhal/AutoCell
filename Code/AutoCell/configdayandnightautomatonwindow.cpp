#include "configdayandnightautomatonwindow.h"
#include "ui_configdayandnightautomatonwindow.h"
#include "mainwindow.h"
#include "simulationwindow.h"
#include "windowmanager.h"
#include "xmlautomatondatamanager.h"

#include <QFileDialog>
#include <string>
#include <stdlib.h>

ConfigDayAndNightAutomatonWindow::ConfigDayAndNightAutomatonWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ConfigDayAndNightAutomatonWindow)
{
    ui->setupUi(this);
}

void ConfigDayAndNightAutomatonWindow::previousWindow()
{
    WindowManager::getInstance().openWindow(new MainWindow());
    WindowManager::getInstance().closeWindow(this);
}

void ConfigDayAndNightAutomatonWindow::saveConfig()
{
    QString completePath = QFileDialog::getSaveFileName(this,
        "Sauvegarder la configuration d'automate jour et nuit", "",
        "eXtensible Markup Language Files (*.xml);;All Files (*)");
    if (completePath.isEmpty()) { return; }
    try {
        bool worked;
        unsigned int columnNb = ui->colNbLineEdit->text().toUInt(&worked);
        if (!worked) { columnNb = 0; }
        unsigned int lineNb = ui->lineNbLineEdit->text().toUInt(&worked);
        if (!worked) { lineNb = 0; }
        unsigned int index = completePath.lastIndexOf("/");
        QString dirPath = completePath.left(index);
        QString fileName = completePath.right(completePath.length() - index - 1);
        XmlAutomatonDataManager::getInstance().writeDayAndNightAutomatonConfig(columnNb, lineNb, dirPath, fileName);
    } catch (std::exception e) { }
}

void ConfigDayAndNightAutomatonWindow::loadConfig()
{
    QString completePath = QFileDialog::getOpenFileName(this,
        "Charger la configuration d'automate jour et nuit", "",
        "eXtensible Markup Language Files (*.xml);;All Files (*)");
    if (completePath.isEmpty()) { return; }
    try {
        unsigned int index = completePath.lastIndexOf("/");
        QString dirPath = completePath.left(index);
        QString fileName = completePath.right(completePath.length() - index - 1);
        unsigned int columnNb;
        unsigned int lineNb;
        std::tie(columnNb, lineNb) = XmlAutomatonDataManager::getInstance().readDayAndNightAutomatonConfig(dirPath, fileName);
        ui->colNbLineEdit->setText(QString::number(columnNb));
        ui->lineNbLineEdit->setText(QString::number(lineNb));
    } catch (std::exception e) { }
}

void ConfigDayAndNightAutomatonWindow::launchAutomaton()
{
    SimulationWindow *sw = new SimulationWindow();
    // TODO setup window
    WindowManager::getInstance().openWindow(sw);
    WindowManager::getInstance().closeWindow(this);
}

ConfigDayAndNightAutomatonWindow::~ConfigDayAndNightAutomatonWindow()
{
    delete ui;
}

void ConfigDayAndNightAutomatonWindow::closeEvent(QCloseEvent *event)
{
    WindowManager::getInstance().removeWindow(this);
    QWidget::closeEvent(event);
}
