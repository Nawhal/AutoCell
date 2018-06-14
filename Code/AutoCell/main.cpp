#include "mainwindow.h"
#include <QApplication>
#include <iostream>
#include "state.h"
#include "cell.h"
#include "automaton.h"
#include "elementaryAutomaton.h"
#include "gameOfLifeAutomaton.h"
#include "dayAndNightAutomaton.h"
#include "xmlautomatondatamanager.h"

using namespace std;

void cellEvol(int line, int column,State& s,GameOfLifeAutomaton& gol){
    cout<<endl<<"Cell : "<<line<<"-"<<column<<endl;
    cout<<"Value : "<<s.getCellValue(line,column)<<endl;
    cout<<"Nb neighbs : "<<s.getNbOfLivingNeighbors(line,column)<<endl;
    cout<<"Will die : "<<gol.willDie(line,column,s)<<endl;
    cout<<"Will be born : "<<gol.willBeBorn(line,column,s)<<endl;
}

int main (int argc, char *argv[])
{
    State* s = new State(5,6);
    State* s1 = new State(*s);
    s1->changeCell(1, 1, Cell(true));
    State* s2 = new State(*s1);
    Cell* c = new Cell();
    cout << "Cell : " << *c;
    cout << "\ns" << *s;
    cout << "\ns1" << *s1;
    cout << "\ns2" << *s2;

    cout << "\n is in grid 0 - 0 :" << s1->isInGrid(0, 0);
    cout << "\n is in grid 4 - 5 :" << s1->isInGrid(4, 5);
    cout << "\n is in grid 4 - 6 :" << s1->isInGrid(4, 6);
    cout << "\n is in grid 5 - 0 :" << s1->isInGrid(5, 0);


    ElementaryAutomaton* ea = new ElementaryAutomaton(30);
    cout << "\n" << *ea;

    cout << "\n TEST ELEMENTARY";

    int nb = 12;
    int cols = 9;
    State* eas = new State(1, cols);
    eas->changeCell(0, 5, Cell(true));
    for (int i = 0; i < nb; ++i) {
        cout << "\nEtape " << i << *eas;
        ea->applyTransition(*eas);
    }


    cout << "\n TEST GOL";
    nb = 8;
    int lines = 10;
    cols = 10;
    GameOfLifeAutomaton *gol = new GameOfLifeAutomaton(2,3);

    State* golState = new State(lines, cols);
    golState->changeCell(0, 1, Cell(true));
    golState->changeCell(1, 2, Cell(true));
    golState->changeCell(2, 0, Cell(true));
    golState->changeCell(2, 1, Cell(true));
    golState->changeCell(2, 2, Cell(true));/*
    golState->changeCell(3, 5, Cell(true));
    golState->changeCell(3, 4, Cell(true));
    golState->changeCell(3, 6, Cell(true));
    golState->changeCell(4, 3, Cell(true));
    golState->changeCell(4, 4, Cell(true));
    golState->changeCell(4, 6, Cell(true));
    golState->changeCell(4, 7, Cell(true));
    golState->changeCell(5, 4, Cell(true));
    golState->changeCell(5, 5, Cell(true));
    golState->changeCell(5, 6, Cell(true));
    golState->changeCell(6, 5, Cell(true));*/

//    cellEvol(2,5,*golState,*gol);
//    cellEvol(0,0,*golState,*gol);
//    cellEvol(3,5,*golState,*gol);
//    cellEvol(2,6,*golState,*gol);
//    cellEvol(2,4,*golState,*gol);
//    cellEvol(3,6,*golState,*gol);

    for (int i = 0; i < nb; ++i) {
        cout << "\nEtape " << i << *golState;
        gol->applyTransition(*golState);
    }

    cout << "\n TEST DaN";
    nb = 8;
    lines = 10;
    cols = 10;
    DayAndNightAutomaton *dan = new DayAndNightAutomaton();

    State* danState = new State(lines, cols);
    danState->changeCell(0, 1, Cell(true));
    danState->changeCell(1, 2, Cell(true));
    danState->changeCell(2, 0, Cell(true));
    danState->changeCell(2, 1, Cell(true));
    danState->changeCell(2, 2, Cell(true));

    cellEvol(0,1,*danState,*gol);
    cellEvol(1,2,*danState,*gol);
    cellEvol(2,0,*danState,*gol);
    cellEvol(2,1,*danState,*gol);
    cellEvol(2,2,*danState,*gol);

    for (int i = 0; i < nb; ++i) {
        cout << "\nEtape " << i << *danState;
        dan->applyTransition(*danState);
        delay(1000);
    }

    XmlAutomatonDataManager& man = XmlAutomatonDataManager::getInstance();
    State* wState = new State(10,8);

    wState->changeCell(9, 7, Cell(true));
    wState->changeCell(8, 7, Cell(true));
    wState->changeCell(5, 3, Cell(true));
    wState->changeCell(5, 7, Cell(true));
    wState->changeCell(0, 0, Cell(true));
    cout << "\nWriting"<< *wState;
    man.writeState(*wState,"C:/Users/Chaves-001/Documents/GitHub/AutoCell/xmlExamples","state.xml");

    State rState = man.readState("C:/Users/Chaves-001/Documents/GitHub/AutoCell/xmlExamples","readTest.xml");
    cout << "\nReading"<< rState;

    //ElementaryAutomaton* eawrite = new ElementaryAutomaton(20);
    ElementaryAutomaton eaRead = man.readElementaryAutomaton("C:/Users/Chaves-001/Documents/GitHub/AutoCell/xmlExamples","eaWriteTest.xml");
    cout << "\nReading ea"<< eaRead;

    //GameOfLifeAutomaton writeGol(5,9);
    GameOfLifeAutomaton golRead = man.readGameOfLifeAutomaton("C:/Users/Chaves-001/Documents/GitHub/AutoCell/xmlExamples","golWriteTest.xml");
    cout << "\nReading gol"<< golRead;

    delete golState;
    delete gol;
    man.endInstance();

    int n;
    cin >> n;
    return 0;

    /*
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
    */
}
