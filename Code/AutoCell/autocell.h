#ifndef AUTOCELL_H
#define AUTOCELL_H

#include <QTableWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QWidget>
#include <QSpinBox>
#include <QLineEdit>
#include <QLabel>
#include <QIntValidator>
#include <QString>
#include <QHeaderView>
#include <QPushButton>

class AutoCell : public QWidget{
    Q_OBJECT
    QSpinBox* num; // numéro
    QLineEdit* numeroBit[8]; // un QLineEdit par bit
    QLabel* numl;
    QLabel* numeroBitl[8];
    QVBoxLayout* numc;
    QVBoxLayout* bitc[8];
    QHBoxLayout* numeroc;
    QIntValidator* zeroOneValidator;
    QTableWidget* depart;
    QVBoxLayout* couche;
    static unsigned int dimension;
    QPushButton* simulation;
    QTableWidget* etats;
public:
    explicit AutoCell(QWidget* parent = nullptr);
};

#endif // AUTOCELL_H
