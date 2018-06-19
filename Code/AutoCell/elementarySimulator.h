/**
 * AutoCell
 * @file elementarySimulator.h
 * Class responsible for the simulation methods for the elementary automaton.
 *
 * The Simulator class implements the methods to simulate and display the elementary automaton.
 */


#ifndef _ELEMENTARYSIMULATOR_H
#define _ELEMENTARYSIMULATOR_H

#include <vector>
#include "simulator.h"

/**
 * @brief The ElementarySimulator class holds everything necessary to simulate an elementary automaton.
 * @abstract
 */
class ElementarySimulator: public Simulator {
    protected:
        std::vector<State> states;
        unsigned int stateNb;

    public:
        /**
         * @param autom The automaton of the simulator
         * @param s The first state of the simulator
         * @param stateNb The number of states to generate for the automaton
         */
        ElementarySimulator(Automaton* autom, State s, unsigned int stateNb)
            : Simulator(autom, s), stateNb(stateNb) { states.push_back(currentState); }

        /**
         * Update current state to the next one.
         *
         */
        virtual void applyTransition();

        /**
         * Sets the current state to the
         * @param state
         */
        virtual void resetState(State& state);
};

#endif //_ELEMENTARYSIMULATOR_H
