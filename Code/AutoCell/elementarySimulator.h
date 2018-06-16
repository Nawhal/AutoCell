/**
 * AutoCell
 * @file elementarySimulator.h
 * Class responsible for the simulation methods for the elementary automaton.
 *
 * The Simulator class implements the methods to simulate and display the elementary automaton.
 */


#ifndef _ELEMENTARYSIMULATOR_H
#define _ELEMENTARYSIMULATOR_H

#include "simulator.h"

/**
 * @brief The ElementarySimulator class holds everything necessary to simulate an elementary automaton.
 */
class ElementarySimulator: public Simulator {
    private:
        State* states;

    public:
        /**
         * Display the state at the interface.
         *
         */
        void display();
};

#endif //_ELEMENTARYSIMULATOR_H
