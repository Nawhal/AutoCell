/**
 * AutoCell
 * @file Cell.cpp
 */


#include "Cell.h"

/**
 * Cell implementation
 */

std::ostream& operator<<(std::ostream& o, const Cell& c){
     if(c.getValue()){
        return o<<'X';
    }else{
        return o<<'_';
    }
}


