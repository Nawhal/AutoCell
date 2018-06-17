#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "configelementaryautomatonwindow.h"
#include "configgameoflifeautomatonwindow.h"
#include "configdayandnightautomatonwindow.h"
#include "windowmanager.h"

#include <iostream>
#include <QCloseEvent>

MainWindow::MainWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

void MainWindow::configureElementaryAutomaton()
{
    WindowManager::getInstance().openWindow(new ConfigElementaryAutomatonWindow());
    WindowManager::getInstance().closeWindow(this);
}

void MainWindow::configureGameOfLifeAutomaton()
{
    WindowManager::getInstance().openWindow(new ConfigGameOfLifeAutomatonWindow());
    WindowManager::getInstance().closeWindow(this);
}

void MainWindow::configureDayAndNightAutomaton()
{
    WindowManager::getInstance().openWindow(new ConfigDayAndNightAutomatonWindow());
    WindowManager::getInstance().closeWindow(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    WindowManager::getInstance().removeWindow(this);
    QWidget::closeEvent(event);
}
