#include "GameOfLifeAutomaton.h"

void GameOfLifeAutomaton::applyTransition(State& currentState) const
 {
     if (currentState.getNbLine() > GameOfLifeAutomaton::getStateMaxNbLine()
        || currentState.getNbColumn() > GameOfLifeAutomaton::getStateMaxNbColumn()){
            throw AutomatonException("Dimension incorrecte");
    }

    for(unsigned int i = 0; i < currentState.getNbLine() ;++i){
        for(unsigned int j = 0; j < currentState.getNbColumn() ;++j){
            if(currentState.getCellValue(i,j) && willDie(i,j,currentState)){
                currentState.changeCell(i,j,Cell(false));
            }else if (!currentState.getCellValue(i,j) && willBeBorn(i,j,currentState)){
                currentState.changeCell(i,j,Cell(true));
            }
        }
    }

 }


void GameOfLifeAutomaton::print(std::ostream& os) const
{
    os<<"Game of life Automaton :\n";
    os<<"A cell will continue to live if "<<this->getMinToNotDie()<<" to "<<this->getMaxToNotDie()<<" neigbors are alive\n";
    os<<"A cell will be born if "<<GameOfLifeAutomaton::getNbToBeBorn()<<" neighbors are alive\n";
}

bool GameOfLifeAutomaton::willBeBorn(unsigned int line, unsigned int column,State& s) const
{
    if(s.getCellValue(line,column)){ // if already living
        return false;
    }else{
        if(s.getNbOfLivingNeighbors(line,column)==GameOfLifeAutomaton::getNbToBeBorn()){
            return true;
        }
        return false;
    }
}

bool GameOfLifeAutomaton::willDie(unsigned int line, unsigned int column,State& s) const
{
   if(!s.getCellValue(line,column)){ // if already dead
        return false;
    }else{
        int nbNeigbors = s.getNbOfLivingNeighbors(line,column);
        if(nbNeigbors < this->getMinToNotDie() || nbNeigbors > this->getMaxToNotDie()){
            return true;
        }
        return false;
    }
}


