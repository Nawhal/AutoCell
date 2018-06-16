/**
 * AutoCell
 * @file Simulator.h
 * Class responsible for the simulation methods.
 *
 * The Simulator class implements the methods to simulate and display the different automatons.
 */


#ifndef _SIMULATOR_H
#define _SIMULATOR_H

#include "state.h"
#include "automaton.h"

#define STOPPED 0
#define RUNNING 1
#define STEPRUNNING 2
#define PAUSED 3
#include <QThread>

/**
 * @brief The Simulator class holds everything necessary to simulate an automaton.
 */
class Simulator {
    private:
        Automaton* automaton;
        unsigned int delayMilliSeconds = 100;
        State currentState;
        int simState = STOPPED;

    public:
        /**
         * Constructor that receives a pointer to the automaton and the state to simulate.
         *
         * @param autom The automaton to simulate.
         * @param s The initial state to simulate.
         */
        Simulator(Automaton* autom, State s) : automaton(autom), currentState(s) { }

        /**
         * Update current state to the next one.
         *
         */
        void applyTransition() { automaton->applyTransition(currentState); }

        /**
         * Display the state at the interface.
         *
         */
        virtual void display();

    public slots:
        /**
         * Pause the simulation.
         *
         */
        void pause();

        /**
         * Run the simulation in a continuous way.
         *
         */
        void run();

        /**
         * Run the simulation one step at a time.
         *
         */
        void stepRun();
};

/**
 * Function that produces a delay on the running of the program.
 *
 * @param millisecondsToWait The time in milliseconds to wait.
 */
void delay (int millisecondsToWait);

#endif //_SIMULATOR_H
