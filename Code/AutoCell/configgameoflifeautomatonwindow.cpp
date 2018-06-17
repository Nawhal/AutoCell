#include "configgameoflifeautomatonwindow.h"
#include "ui_configgameoflifeautomatonwindow.h"
#include "simulationwindow.h"
#include "windowmanager.h"
#include "mainwindow.h"

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
    // TODO
}

void ConfigGameOfLifeAutomatonWindow::launchAutomaton()
{
    SimulationWindow *sw = new SimulationWindow();
    // TODO setup window
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
