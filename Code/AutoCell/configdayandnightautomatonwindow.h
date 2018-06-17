#ifndef CONFIGDAYANDNIGHTAUTOMATONWINDOW_H
#define CONFIGDAYANDNIGHTAUTOMATONWINDOW_H

#include <QWidget>

namespace Ui {
    class ConfigDayAndNightAutomatonWindow;
}

class ConfigDayAndNightAutomatonWindow : public QWidget
{
    Q_OBJECT

    public:
        explicit ConfigDayAndNightAutomatonWindow(QWidget *parent = 0);
        ~ConfigDayAndNightAutomatonWindow();

    protected:
        void closeEvent(QCloseEvent *event);

    private:
        Ui::ConfigDayAndNightAutomatonWindow *ui;

    private slots:
        void previousWindow ();
        void loadConfig ();
        void saveConfig ();
        void launchAutomaton ();
};

#endif // CONFIGDAYANDNIGHTAUTOMATONWINDOW_H
