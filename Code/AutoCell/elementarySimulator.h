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
#include "elementaryAutomaton.h"
#include <QObject>

/**
 * @brief The ElementarySimulator class holds everything necessary to simulate an elementary automaton.
 */
class ElementarySimulator: public Simulator {
    private:
        State* states;

    public:
        /**
         * Constructor that receives a pointer to the automaton and the state to simulate.
         *
         * @param autom The automaton to simulate.
         * @param s The initial state to simulate.
         */
        ElementarySimulator(QObject* parent, ElementaryAutomaton* autom, State s) : Simulator(parent, autom, s) { }

        /**
         * Display the state at the interface.
         *
         */
        void display();
};

#endif //_ELEMENTARYSIMULATOR_H
