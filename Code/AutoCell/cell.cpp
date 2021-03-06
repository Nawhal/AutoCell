/**
 * AutoCell
 * @file Cell.cpp
 */


#include "cell.h"

/**
 * Cell implementation
 */

/**
 * Assignment operator method implementation.
 *
 */
std::ostream& operator<<(std::ostream& o, const Cell& c) {
    if(c.getValue()) {
        return o << 'X';
    } else {
        return o << '_';
    }
}


