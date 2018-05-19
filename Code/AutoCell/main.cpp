#include "mainwindow.h"
#include <QApplication>
#include <iostream>
#include "state.h"
#include "cell.h"
#include "automaton.h"
#include "elementaryAutomaton.h"
using namespace std;

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
