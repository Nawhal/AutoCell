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
#include <iostream>
#include <QTimer>
#include "QObject"

#define STOPPED 0
#define RUNNING 1
#define STEPRUNNING 2
#define PAUSED 3

/**
 * @brief The Simulator class holds everything necessary to simulate an automaton.
 */
class Simulator: public QObject {
    Q_OBJECT
    private:
        Automaton* automaton;
        unsigned int delayMilliSeconds = 100;
        State currentState;
        int simState = STOPPED;

    public:
        QTimer *timer;

        /**
         * Constructor that receives a pointer to the automaton and the state to simulate.
         *
         * @param autom The automaton to simulate.
         * @param s The initial state to simulate.
         */
        Simulator(QObject* parent, Automaton* autom, State s);

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

        /**
         * Continues running or pauses the simulation if pause button pressed.
         *
         */
        void updateRun();
};

#endif //_SIMULATOR_H
