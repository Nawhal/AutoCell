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
 * @abstract
 */
class Simulator {
    private:
        int simState = STOPPED;

    protected:
        Automaton* automaton;
        unsigned int delayMilliSeconds = 10000;
        State currentState;

    public:
        /**
         * Constructor that receives a pointer to the automaton and the state to simulate.
         *
         * @param autom The automaton to simulate.
         * @param s The initial state to simulate.
         */
        Simulator(Automaton* autom, State s) : automaton(autom), currentState(s) { }

        /**
         * Destructor.
         */
        virtual ~Simulator() { }

        /**
         * Returns the value of simState.
         * @return The value of simState.
         */
        int getSimState() { return simState; }

        /**
         * Sets the current state to the
         * @param state
         */
        virtual void resetState(State& state);

        /**
         * Update current state to the next one.
         *
         */
        virtual void applyTransition() { automaton->applyTransition(currentState); }

        /**
         * Display the state at the interface.
         *
         */
        virtual void display() = 0;

        /**
         * Pause the simulation.
         *
         */
        void pause();

        /**
         * Run the simulation in a continuous way (needs to be called every x milliseconds).
         *
         */
        void run();

        /**
         * Run the simulation one step at a time.
         *
         */
        void stepRun();

        /**
         * Stop the simulation.
         *
         */
        void stop();
};

/**
 * Function that produces a delay on the running of the program.
 *
 * @param millisecondsToWait The time in milliseconds to wait.
 */
void delay (int millisecondsToWait);

#endif //_SIMULATOR_H
