#ifndef WINDOWMANAGER_H
#define WINDOWMANAGER_H

#include <QWidget>
#include <vector>

class WindowManager
{
    private:
        std::vector<QWidget*> windows;

        /**
         * Removes the given window from windows.
         *
         * @param window The window to remove.
         */
        void removeWindowFromWindows(QWidget *window);

        /**
         * Deletes the singleton if windows is empty.
         */
        void freeIfEmpty();

        /**
         * Unique instance of WindowManager.
         */
        static WindowManager* instance;

        /**
         * Default constructor.
         *
         */
        WindowManager() {}

        /**
         * Default destructor.
         *
         */
        ~WindowManager();

        /**
         * Default copy constructor.
         *
         * @param wm The WindowManager to copy.
         */
        WindowManager(const WindowManager& wm) {}

        /**
         * Default basic assignment operator overload.
         *
         * @param wm The WindowManager to be assigned.
         * @return The WindowManager assigned.
         */
        WindowManager& operator=(const WindowManager& wm) {}

        /**
         * The method to delete the only instance of WindowManager.
         *
         */
        static void freeInstance();

    public:
        /**
         * Opens the given window.
         *
         * @param window The window to open.
         */
        void openWindow(QWidget *window);

        /**
         * Closes the given window.
         *
         * @param window The window to close.
         */
        void closeWindow(QWidget *window);

        /**
         * Removes the given window from windows and deletes the singleton if windows becomes empty.
         *
         * @param window The window to remove.
         */
        void removeWindow(QWidget *window);

        /**
         * Returns the only instance of the WindowManager class.
         *
         * @return The single object of WindowManager.
         */
        static WindowManager& getInstance();
};

#endif // WINDOWMANAGER_H
