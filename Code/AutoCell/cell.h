/**
 * AutoCell
 * @file Cell.h
 * An unit cell, the most basic component of a state.
 *
 * The Cell class implements the state's most basic element.
 */


#ifndef _CELL_H
#define _CELL_H

#include <iostream>

class Cell {
private:
    bool value;

public:
    /**
     * Default Constructor, it sets the value property to false.
     *
     *
     */
   Cell() : value(false) { }

    /**
     * Constructor that sets the value property.
     *
     * @param v Value boolean to be stored by a Cell object.
     */
   Cell(const bool v) : value(v) { }

    /**
     * Accessor to the Value property.
     *
     * @return bool
     */
    bool getValue() const { return value; }

};

std::ostream& operator<<(std::ostream& o, const Cell& c);

#endif //_CELL_H
