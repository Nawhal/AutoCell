/**
 * Project Untitled
 */

#include "elementarySimulator.h"

/**
 * ElementarySimulator implementation.
 */

/**
 * applyTransition method implementation.
 *
 */
void ElementarySimulator::applyTransition()
{
    if (states.size() == stateNb) {
        states.erase(states.begin());
    }
    states.push_back(currentState);
    automaton->applyTransition(currentState);
}

/**
 * resetState method implementation
 *
 */
void ElementarySimulator::resetState(State &state)
{
    states.clear();
    currentState = state;
    states.push_back(currentState);
}
