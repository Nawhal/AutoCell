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

    protected:
        void closeEvent(QCloseEvent *event);

    private:
        Ui::ConfigGameOfLifeAutomatonWindow *ui;

    private slots:
        void previousWindow ();
        void saveConfig ();
        void loadConfig();
        void launchAutomaton ();
};

#endif // CONFIGGAMEOFLIFEAUTOMATONWINDOW_H
