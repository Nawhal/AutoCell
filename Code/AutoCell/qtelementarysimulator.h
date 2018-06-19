#ifndef QTELEMENTARYSIMULATOR_H
#define QTELEMENTARYSIMULATOR_H

#include "elementarySimulator.h"
#include "simulationwindow.h"

class QtElementarySimulator : public ElementarySimulator
{
    private:
        SimulationWindow* simulationWindow;

    public:
        /**
         * Constructor that receives a pointer to the automaton, the state to simulate and the window to update.
         *
         * @param autom The automaton to simulate.
         * @param s The initial state to simulate.
         * @param stateNb The number of states to generate for the automaton
         * @param sw The window to update.
         */
        QtElementarySimulator(Automaton* autom, State s, unsigned int stateNb, SimulationWindow* sw) : ElementarySimulator(autom, s, stateNb), simulationWindow(sw) { }

        /**
         * Displays the simulation in the simulationWindow.
         */
        void display();
};

#endif // QTELEMENTARYSIMULATOR_H
