/**
 * AutoCell
 * @file State.h
 * A state of the Automaton, composed of unit cells.
 * 
 * The State class implements 
 */


#ifndef _STATE_H
#define _STATE_H

class State {
private:
    unsigned int nbLine;
    unsigned int nbColumn;
    Cell* cells;
	
public:
    /**
     * Constructor.
     * 
     * @param col
     * @param lin
     */
    State(unsigned int col, unsigned int lin = 1):nbColumn(col), nbLine(lin) { cells = new Cell[nbColumn][nbLine]; }
    
    /**
     * Destructor.
     * 
     */
    ~State() { delete[] cells; }
    
    /**
     * @param x
     * @param y
     * @param newCell
     */
    void changeCell(unsigned int x, unsigned int y, const Cell newCell) { cells[x][y] = newCell; }
};

#endif //_STATE_H