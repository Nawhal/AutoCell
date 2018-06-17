#include "windowmanager.h"
#include <algorithm>
#include <typeinfo>
#include <string.h>

/**
 * WindowManager implementation.
 */
WindowManager* WindowManager::instance = nullptr;

/**
 * getInstance method implementation.
 *
 */
WindowManager& WindowManager::getInstance(){
    if(WindowManager::instance==nullptr){
        WindowManager::instance = new WindowManager();
    }
    return *(WindowManager::instance);
}

/**
 * freeInstance method implementation.
 *
 */
void WindowManager::freeInstance(){
    if(nullptr!=WindowManager::instance){
        delete WindowManager::instance;
        WindowManager::instance=nullptr;
    }
}

/**
 * WindowManager destructor implementation.
 */
WindowManager::~WindowManager()
{
    for (std::vector<QWidget*>::iterator it = windows.begin() ; it != windows.end(); ++it) {
        (*it)->close();
        delete *it;
    }
}

void WindowManager::openWindow(QWidget *window)
{
    windows.push_back(window);
    window->show();
}

void WindowManager::closeWindow(QWidget *window)
{
    window->close();
    delete window;
}

void WindowManager::removeWindow(QWidget *window)
{
    removeWindowFromWindows(window);
    freeIfEmpty();
}

void WindowManager::removeWindowFromWindows(QWidget *window)
{
    windows.erase(std::remove_if(windows.begin(), windows.end(), [window](QWidget *w) {
            return strcmp(typeid(*w).name(), typeid(*window).name()) == 0;
        }), windows.end());
}

void WindowManager::freeIfEmpty()
{
    if (windows.empty()) {
        freeInstance();
    }
}
