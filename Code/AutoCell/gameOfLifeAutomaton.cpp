/**
 * AutoCell
 * @file gameOfLifeAutomaton.cpp
 */


#include "gameOfLifeAutomaton.h"

/**
 * Automaton implementation
 */

/**
 * isNotInRange method implementation.
 *
 */
bool GameOfLifeAutomaton::isNotInRange(const State& currentState) const{
    return (currentState.getNbLine() > GameOfLifeAutomaton::getStateMaxNbLine()
            || currentState.getNbColumn() > GameOfLifeAutomaton::getStateMaxNbColumn());
}

/**
 * applyTransition method implementation.
 *
 */
void GameOfLifeAutomaton::applyTransition (State& currentState) const
{
    if(isNotInRange(currentState)){
        throw AutomatonException("Dimension incorrecte");
    }

    State old = State(currentState);

    for (unsigned int i = 0; i < currentState.getNbLine(); ++i) {
        for (unsigned int j = 0; j < currentState.getNbColumn(); ++j) {
            if (willDie(i, j, old)) {
                currentState.changeCell(i, j, Cell(false));
            } else if (willBeBorn(i, j, old)) {
                currentState.changeCell(i, j, Cell(true));
            }
        }
    }

}

/**
 * print method implementation.
 *
 */
void GameOfLifeAutomaton::print (std::ostream& os) const
{
    os << "Game of life Automaton :\n";
    os << "A cell will continue to live if " << this->getMinToNotDie() << " to " << this->getMaxToNotDie() << " neighbors are alive\n";
    os << "A cell will be born if " << GameOfLifeAutomaton::getNbToBeBorn() << " neighbors are alive\n";
}

/**
 * willBeBorn method implementation.
 *
 */
bool GameOfLifeAutomaton::willBeBorn (unsigned int line, unsigned int column,State& s) const
{
    if (s.getCellValue(line, column)) { // if already living
        return false;
    }
    if (s.getNbOfLivingNeighbors(line, column) == GameOfLifeAutomaton::getNbToBeBorn()) {
        return true;
    }
    return false;
}

/**
 * willDie method implementation.
 *
 */
bool GameOfLifeAutomaton::willDie (unsigned int line, unsigned int column, State& s) const
{
    if (!s.getCellValue(line, column)) { // if already dead
        return false;
    }
    int nbNeighbors = s.getNbOfLivingNeighbors(line, column);
    if (nbNeighbors < this->getMinToNotDie() || nbNeighbors > this->getMaxToNotDie()) {
        return true;
    }
    return false;
}
