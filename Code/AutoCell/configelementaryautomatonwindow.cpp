#include "configelementaryautomatonwindow.h"
#include "ui_configelementaryautomatonwindow.h"
#include "simulationwindow.h"

ConfigElementaryAutomatonWindow::ConfigElementaryAutomatonWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ConfigElementaryAutomatonWindow)
{
    ui->setupUi(this);
}

void ConfigElementaryAutomatonWindow::previousWindow()
{
    // TODO
}

void ConfigElementaryAutomatonWindow::saveConfig()
{
    // TODO
}

void ConfigElementaryAutomatonWindow::launchAutomaton()
{
    SimulationWindow window;
    window.show();
    this->close();
}

ConfigElementaryAutomatonWindow::~ConfigElementaryAutomatonWindow()
{
    delete ui;
}
