/**
 * Project Untitled
 */


#ifndef _ELEMENTARYSIMULATOR_H
#define _ELEMENTARYSIMULATOR_H

#include "Simulator.h"


class ElementarySimulator: public Simulator {
public: 
    
    void display();
private: 
    State* states;
};

#endif //_ELEMENTARYSIMULATOR_H