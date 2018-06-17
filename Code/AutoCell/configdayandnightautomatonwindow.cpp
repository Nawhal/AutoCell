#include "configdayandnightautomatonwindow.h"
#include "ui_configdayandnightautomatonwindow.h"
#include "mainwindow.h"
#include "simulationwindow.h"
#include "windowmanager.h"

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
    // TODO
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
