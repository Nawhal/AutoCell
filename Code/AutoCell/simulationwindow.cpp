#include "simulationwindow.h"
#include "ui_simulationwindow.h"
#include "windowmanager.h"

SimulationWindow::SimulationWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SimulationWindow)
{
    ui->setupUi(this);
}

void SimulationWindow::saveAutomaton()
{
    // TODO
}

SimulationWindow::~SimulationWindow()
{
    delete ui;
}

void SimulationWindow::closeEvent(QCloseEvent *event)
{
    WindowManager::getInstance().removeWindow(this);
    QWidget::closeEvent(event);
}
