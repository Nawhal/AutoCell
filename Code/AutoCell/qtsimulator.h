#ifndef QTSIMULATOR_H
#define QTSIMULATOR_H

#include "simulator.h"
#include "simulationwindow.h"

class SimulationWindow;

class QtSimulator : public Simulator
{
    private:
        SimulationWindow* simulationWindow;

    public:
        /**
         * Constructor that receives a pointer to the automaton, the state to simulate and the window to update.
         *
         * @param autom The automaton to simulate.
         * @param s The initial state to simulate.
         * @param sw The window to update.
         */
        QtSimulator(Automaton* autom, State s, SimulationWindow* sw) : Simulator(autom, s), simulationWindow(sw) { }

        /**
         * Displays the simulation in the simulationWindow
         */
        void display();
};

#endif // QTSIMULATOR_H
