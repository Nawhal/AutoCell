#include "configgameoflifeautomatonwindow.h"
#include "ui_configgameoflifeautomatonwindow.h"
#include "simulationwindow.h"

ConfigGameOfLifeAutomatonWindow::ConfigGameOfLifeAutomatonWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ConfigGameOfLifeAutomatonWindow)
{
    ui->setupUi(this);
}

void ConfigGameOfLifeAutomatonWindow::previousWindow()
{
    // TODO
}

void ConfigGameOfLifeAutomatonWindow::saveConfig()
{
    // TODO
}

void ConfigGameOfLifeAutomatonWindow::launchAutomaton()
{
    SimulationWindow window;
    window.show();
    this->close();
}

ConfigGameOfLifeAutomatonWindow::~ConfigGameOfLifeAutomatonWindow()
{
    delete ui;
}
