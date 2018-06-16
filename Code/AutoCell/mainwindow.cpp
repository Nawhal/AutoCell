#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "configelementaryautomatonwindow.h"
#include "configgameoflifeautomatonwindow.h"
#include "configdayandnightautomatonwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

void MainWindow::configureElementaryAutomaton()
{
    ConfigElementaryAutomatonWindow window;
    window.show();
    this->close();
}

void MainWindow::configureGameOfLifeAutomaton()
{
    // TODO
}

void MainWindow::configureDayAndNightAutomaton()
{
    // TODO
}

void MainWindow::quit()
{
    // TODO
}

MainWindow::~MainWindow()
{
    delete ui;
}
