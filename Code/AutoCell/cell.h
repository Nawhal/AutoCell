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

/**
 * @brief The Cell class holds a value.
 */
class Cell {
private:
    bool value;

public:
    /**
     * Default Constructor that sets false to the value property.
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

    /**
     * Setter of the cell value
     *
     * @return bool
     */
    void setValue(bool nvalue) { this->value=nvalue; }

};

/**
 * Assignment operator overload.
 *
 * @param o The out stream to write to.
 * @param s The cell to write.
 * @return The out stream with the cell written to.
 */
std::ostream& operator<< (std::ostream& o, const Cell& c);

#endif //_CELL_H
