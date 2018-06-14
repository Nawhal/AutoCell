/**
 * AutoCell
 * @file elementaryAutomaton.cpp
 */


#include "elementaryAutomaton.h"

/**
 * Elementary Automaton implementation
 */

/**
 * Elementary Automaton constructor implementation.
 *
 */
ElementaryAutomaton::ElementaryAutomaton (unsigned int ruleN) : ruleNumber(ruleN)
{
    setRule(ruleN);
}

/**
 * Elementary Automaton copy constructor implementation.
 *
 */
ElementaryAutomaton::ElementaryAutomaton (const ElementaryAutomaton& e)
{
    setRule(e.getRuleNumber());
}

/**
 * setRule method implementation.
 *
 */
void ElementaryAutomaton::setRule (int ruleN) {
    // 255 est le max représentable sur 8 bits, et 8 cas seulements peuvent exister
    // car une cellule à 2 états et 2 voisins au plus, d'ou 2^3 configs possibles
    if (ruleN >= E28) {
        throw AutomatonException("Numero d'automate indefini");
    }
    // on divise successivement la règle pour décomposer en puissance de 2, la plus haute étant 128
    unsigned int p = E27;
    unsigned int num = ruleN;
    int i = lastRuleIndex;
    while (i >= 0) {
        if (num >= p) {
            this->ruleTab[i]=true;
            num -= p;
        }
        else { this->ruleTab[i]=false; }
        i--;
        p = p / 2;
    }
}

/**
 * applyTransition method implementation.
 *
 */
void ElementaryAutomaton::applyTransition(State& currentState) const
{
    if (currentState.getNbLine() > ElementaryAutomaton::getStateMaxNbLine()
            || currentState.getNbColumn() > ElementaryAutomaton::getStateMaxNbColumn()){
        throw AutomatonException("Dimension incorrecte");
    }

    const State* base = new State(currentState);
    for(unsigned int i=0;i<currentState.getNbColumn();++i){
        bool left = base->getCellValue(ElementaryAutomaton::stateWorkingLine,i-1);
        bool mid = base->getCellValue(ElementaryAutomaton::stateWorkingLine,i);
        bool right = base->getCellValue(ElementaryAutomaton::stateWorkingLine,i+1);
        currentState.changeCell(ElementaryAutomaton::stateWorkingLine,i,Cell(ruleTab[lifeExpectancy(left,mid,right)]));
    }

}

/**
 * lifeExpectancy method implementation.
 *
 */
unsigned int ElementaryAutomaton::lifeExpectancy(bool left,bool mid,bool right)
{
    unsigned int indexRes = 0;
    // true = 1 en binaire ici, MSB = left, LSB = right
    if (right) {
        indexRes += E20; // +1 car
    }
    if (mid) {
        indexRes += E21;
    }
    if (left) {
        indexRes += E22;
    }
    return indexRes;
}

/**
 * print method implementation.
 *
 */
void ElementaryAutomaton::print (std::ostream& os) const
{
    os << "Elementary automaton :\n";
    os << "Rule number : " << this->getRuleNumber() << "\n";
    // rule tab
    os << "Rule tab :\n";
    os << "000 : " << this->ruleTab[0] << "\n";
    os << "001 : " << this->ruleTab[1] << "\n";
    os << "010 : " << this->ruleTab[2] << "\n";
    os << "011 : " << this->ruleTab[3] << "\n";
    os << "100 : " << this->ruleTab[4] << "\n";
    os << "101 : " << this->ruleTab[5] << "\n";
    os << "110 : " << this->ruleTab[6] << "\n";
    os << "111 : " << this->ruleTab[7] << "\n";
}
