#ifndef ELEMENTARYAUTOMATON_H
#define ELEMENTARYAUTOMATON_H

#include <automaton.h>
#define E20 1 // 2^0
#define E21 2 // 2^1
#define E22 4 // 2^2
#define E27 128 //2^7
#define E28 256 //2^8

class ElementaryAutomaton : public Automaton
{

    private:
        static const unsigned int stateMaxNbLine = 1;
        static const unsigned int stateMaxNbColumn = 10;
        static const unsigned int stateWorkingLine = 0;
        static const unsigned int lastRuleIndex = 7;

        // short unsigned int maxNbState; // nb etats, a mettre dans simul
        unsigned int ruleNumber; // regle de transition
        bool ruleTab[lastRuleIndex];

    public:
        ElementaryAutomaton (unsigned int ruleN);
        ElementaryAutomaton (const ElementaryAutomaton& e);
        virtual ~ElementaryAutomaton () {}

        static unsigned int lifeExpectancy (bool left, bool mid, bool right);
        static unsigned int getStateMaxNbLine () { return stateMaxNbLine; }
        static unsigned int getStateMaxNbColumn () { return stateMaxNbColumn; }

        virtual void applyTransition (State& currentState) const;
        unsigned int getRuleNumber () const{ return this->ruleNumber; }
        const bool* getRuleTab () const { return this->ruleTab; }
        void setRule (int ruleN);
        virtual void print (std::ostream& os) const;


    protected:

};

#endif // ELEMENTARYAUTOMATON_H
