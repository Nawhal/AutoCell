#ifndef CONFIGGAMEOFLIFEAUTOMATONWINDOW_H
#define CONFIGGAMEOFLIFEAUTOMATONWINDOW_H

#include <QWidget>

namespace Ui {
    class ConfigGameOfLifeAutomatonWindow;
}

class ConfigGameOfLifeAutomatonWindow : public QWidget
{
    Q_OBJECT

    public:
        explicit ConfigGameOfLifeAutomatonWindow(QWidget *parent = 0);
        ~ConfigGameOfLifeAutomatonWindow();

    private:
        Ui::ConfigGameOfLifeAutomatonWindow *ui;

    private slots:
        void previousWindow ();
        void saveConfig ();
        void launchAutomaton ();
};

#endif // CONFIGGAMEOFLIFEAUTOMATONWINDOW_H
