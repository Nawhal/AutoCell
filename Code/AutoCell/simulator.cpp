/**
 * AutoCell
 * @file Simulator.cpp
 */


#include "simulator.h"

/**
 * Simulator implementation
 */

/**
 * Run method implementation.
 *
 */
void Simulator::run() {
    simState = RUNNING;
    applyTransition();
    display();
}

void Simulator::resetState(State &state)
{
    currentState = state;
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

void Simulator::stop()
{
    simState = STOPPED;
}
