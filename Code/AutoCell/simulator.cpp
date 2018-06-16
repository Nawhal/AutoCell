/**
 * AutoCell
 * @file Simulator.cpp
 */


#include "simulator.h"

/**
 * Simulator implementation
 */

/**
 * Display method implementation.
 *
 */
void Simulator::display() {

}

/**
 * Run method implementation.
 *
 */
void Simulator::run() {
    simState = RUNNING;
    display();
    delay(delayMilliSeconds);

    while(simState == RUNNING){
        applyTransition();
        display();
        delay(delayMilliSeconds);
    }
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
    display();
    applyTransition();
    display();
    simState = PAUSED;
}
