#ifndef GAMEOFLIFEAUTOMATON_H
#define GAMEOFLIFEAUTOMATON_H

#include <Automaton.h>


class GameOfLifeAutomaton : public Automaton
{

    private:
    static const short unsigned int stateMaxNbLine = 10;
    static const short unsigned int stateMaxNbColumn = 10;
    static const unsigned int nbToBeBorn = 3;

    unsigned int minToNotDie;
    unsigned int maxToNotDie;


    public:
        GameOfLifeAutomaton(unsigned int minNd,unsigned int maxNd):minToNotDie(minNd),maxToNotDie(maxNd){}
        virtual ~GameOfLifeAutomaton();

        static unsigned int getNbToBeBorn(){return GameOfLifeAutomaton::nbToBeBorn;}
        static unsigned int getStateMaxNbLine() {return stateMaxNbLine;}
        static unsigned int getStateMaxNbColumn() {return stateMaxNbColumn;}

        unsigned int getMinToNotDie() const{return this->minToNotDie;}
        unsigned int getMaxToNotDie() const{return this->maxToNotDie;}
        void applyTransition(State& currentState) const;
        virtual void print(std::ostream& os) const;
        bool willBeBorn(unsigned int line, unsigned int column,State& s) const;
        bool willDie(unsigned int line, unsigned int column,State& s) const;


    protected:
};

#endif // GAMEOFLIFEAUTOMATON_H