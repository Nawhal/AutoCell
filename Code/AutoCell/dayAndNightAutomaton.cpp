#include "dayAndNightAutomaton.h"

const int DayAndNightAutomaton::nbToBeBornTab[] = {3,6,7,8};

bool DayAndNightAutomaton::willBeBorn (unsigned int line, unsigned int column,State& s) const {
    if (s.getCellValue(line, column)) { // if already living
        return false;
    } else {
        int nbNeighbors = s.getNbOfLivingNeighbors(line, column);
        for(unsigned int i=0;i<DayAndNightAutomaton::nbToBeBornTabSize;++i){
            if ( nbNeighbors == DayAndNightAutomaton::nbToBeBornTab[i]) {
                return true;
            }
        }

        return false;
    }
}

bool DayAndNightAutomaton::willDie (unsigned int line, unsigned int column,State& s) const {
    return this->gol34.willDie(line,column,s) && GameOfLifeAutomaton::willDie(line,column,s);
}
