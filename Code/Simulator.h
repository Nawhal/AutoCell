/**
 * AutoCell
 * @file Simulator.h
 * Class responsible for the 
 * 
 * The Simulator class implements the .
 */


#ifndef _SIMULATOR_H
#define _SIMULATOR_H

class Simulator {
private:
    Automaton* automaton;
    unsigned int delayMilliSeconds = 100;
    State currentState;
    
public:
    /**
     * Constructor.
     * 
     * @param autom
     */
    Simulator(Automaton* autom):automaton(autom) { }
    
    /**
     * Update current state to the next one.
     * 
     */
    void applyTransition() { automaton.applyTransition(currentState); }
    
    /**
     * Display the state at the interface.
     * 
     */
    void display();
};

#endif //_SIMULATOR_H