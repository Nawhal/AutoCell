#include "autocell.h"
#include "elementarySimulator.h"
#include "state.h"

unsigned int AutoCell::dimension = 25;

AutoCell::AutoCell(QWidget* parent): QWidget(parent){

    numl = new QLabel("Numéro");

    num = new QSpinBox(this);
    num->setRange(0,255);
    num->setValue(0);

    numc = new QVBoxLayout();
    numc->addWidget(numl);
    numc->addWidget(num);

    numeroc = new QHBoxLayout();
    numeroc->addLayout(numc);

    for(unsigned int i = 0; i < 8; i++){
        numeroBit[i] = new QLineEdit(this);
        numeroBit[i]->setFixedWidth(20);
        numeroBit[i]->setMaxLength(1);
        numeroBit[i]->setText("0");

        numeroBitl[i] = new QLabel();

        bitc[i] = new QVBoxLayout;
    }

    depart = new QTableWidget(1, dimension, this);
    unsigned int taille = 25;
    depart->setFixedSize(dimension*taille, taille);
    depart->horizontalHeader()->setVisible(false);
    depart->verticalHeader()->setVisible(false);
    depart->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    depart->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    depart->setEditTriggers(QAbstractItemView::NoEditTriggers);

    for(unsigned int i = 0; i < dimension; i++){
        depart->setColumnWidth(i, taille);
        depart->setItem(0, i, new QTableWidgetItem(""));
    }

    simulation = new QPushButton("Simulation");

    etats = new QTableWidget(dimension, dimension, this);
    etats->setFixedSize(dimension*taille, dimension*taille);
    etats->horizontalHeader()->setVisible(false);
    etats->verticalHeader()->setVisible(false);
    etats->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    etats->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    etats->setEditTriggers(QAbstractItemView::NoEditTriggers);

    for(unsigned int i = 0; i < dimension; i++){
        etats->setColumnWidth(i, taille);
        etats->setRowHeight(i, taille);
        for(unsigned int j = 0; j < dimension; j++)
            etats->setItem(j, i, new QTableWidgetItem(""));
    }

    ElementaryAutomaton* ea = new ElementaryAutomaton(30);
    std::cout << "\n" << *ea;

    std::cout << "\n TEST ELEMENTARY";

    int nb = 12;
    int cols = 9;
    State* eas = new State(1, cols);
    eas->changeCell(0, 5, Cell(true));

    ElementarySimulator sim(this, ea, *eas);

    connect(simulation, SIGNAL(clicked()), &sim, SLOT(run()));

    QVBoxLayout* couche = new QVBoxLayout();

    couche = new QVBoxLayout();
    couche->addLayout(numeroc);
    couche->addWidget(depart);
    couche->addWidget(simulation);
    couche->addWidget(etats);

    setLayout(couche);
}
