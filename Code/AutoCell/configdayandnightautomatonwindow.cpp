#include "configdayandnightautomatonwindow.h"
#include "ui_configdayandnightautomatonwindow.h"
#include "simulationwindow.h"

ConfigDayAndNightAutomatonWindow::ConfigDayAndNightAutomatonWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ConfigDayAndNightAutomatonWindow)
{
    ui->setupUi(this);
}

void ConfigDayAndNightAutomatonWindow::previousWindow()
{
    // TODO
}

void ConfigDayAndNightAutomatonWindow::saveConfig()
{
    // TODO
}

void ConfigDayAndNightAutomatonWindow::launchAutomaton()
{
    SimulationWindow window;
    window.show();
    this->close();
}

ConfigDayAndNightAutomatonWindow::~ConfigDayAndNightAutomatonWindow()
{
    delete ui;
}
