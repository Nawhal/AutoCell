/**
 * AutoCell
 * @file Simulator.cpp
 */


#include "simulator.h"

/**
 * Simulator implementation;
 */

/**
 * Constructor implementation.
 */
Simulator::Simulator(QObject* parent, Automaton* autom, State s) : QObject(parent), automaton(autom), currentState(s) {
    timer = new QTimer(this);
    timer->setInterval(delayMilliSeconds);
    connect(timer, SIGNAL(timeout()), this, SLOT(updateRun()));
}

/**
 * Display method implementation.
 *
 */
void Simulator::display() {
    std::cout << *automaton;
}

void Simulator::updateRun() {
    if(simState != RUNNING)
        timer->stop();
        //run();
}

/**
 * Run method implementation.
 *
 */
void Simulator::run() {
    std::cout << "run()" << std::endl;
    if(simState != RUNNING) {
        simState = RUNNING;
        //QTimer::singleShot(delayMilliSeconds, this, SLOT(updateRun()));
        timer->start();
    }

    applyTransition();
    display();
}

/**
 * Pause method implementation.
 *
 */
void Simulator::pause() {
    simState = PAUSED;
}

/**
 * StepRun method implementation.
 *
 */
void Simulator::stepRun() {
    simState = STEPRUNNING;
    applyTransition();
    display();
    simState = PAUSED;
}
