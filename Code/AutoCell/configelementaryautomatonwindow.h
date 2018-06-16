#ifndef CONFIGELEMENTARYAUTOMATONWINDOW_H
#define CONFIGELEMENTARYAUTOMATONWINDOW_H

#include <QWidget>

namespace Ui {
    class ConfigElementaryAutomatonWindow;
}

class ConfigElementaryAutomatonWindow : public QWidget
{
    Q_OBJECT

    public:
        explicit ConfigElementaryAutomatonWindow(QWidget *parent = 0);
        ~ConfigElementaryAutomatonWindow();

    private:
        Ui::ConfigElementaryAutomatonWindow *ui;

    private slots:
        void previousWindow ();
        void saveConfig ();
        void launchAutomaton ();
};

#endif // CONFIGELEMENTARYAUTOMATONWINDOW_H
