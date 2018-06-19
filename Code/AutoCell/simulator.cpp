/**
 * AutoCell
 * @file Simulator.cpp
 */


#include "simulator.h"
#include "xmlautomatondatamanager.h"

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

void Simulator::saveAutomaton(QString path, QString fileName)
{
    const char *automatonType = typeOfAutomaton().c_str();

    // Cast impossible...
    /*
    if (strcmp(automatonType, "ElementaryAutomaton") == 0) {
        XmlAutomatonDataManager::getInstance().writeElementaryAutomaton(dynamic_cast<ElementaryAutomaton&>(automaton), path, fileName);
    } else if (strcmp(automatonType, "GameOfLifeAutomaton") == 0) {
        XmlAutomatonDataManager::getInstance().writeGameOfLifeAutomaton(dynamic_cast<GameOfLifeAutomaton&>(automaton), path, fileName);
    }
    */
}

void Simulator::loadAutomaton(QString path, QString fileName)
{
    // TODO
}
