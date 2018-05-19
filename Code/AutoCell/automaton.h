#ifndef AUTOMATON_H
#define AUTOMATON_H

#include "state.h"
#include <string>

class Automaton
{
    private:

    public:
        Automaton() {}
        virtual ~Automaton () = 0; // pure virtual, abstract class

        virtual void applyTransition (State& currentState) const = 0;
        virtual void print (std::ostream& os) const = 0;

    protected:

};

class AutomatonException {
    public:
        AutomatonException (const std::string& message) : info(message) {}
        std::string getInfo () const { return info; }

    private:
        std::string info;
};

inline std::ostream& operator<< (std::ostream &o, const Automaton& a) {
    a.print(o);
    return o;
}

#endif // AUTOMATON_H
