#include "configelementaryautomatonwindow.h"
#include "ui_configelementaryautomatonwindow.h"
#include "simulationwindow.h"
#include "windowmanager.h"
#include "mainwindow.h"

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
    // TODO
}

void ConfigElementaryAutomatonWindow::launchAutomaton()
{
    SimulationWindow *sw = new SimulationWindow();
    // TODO setup window
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
