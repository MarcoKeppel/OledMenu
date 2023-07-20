#ifndef _ALERTWINDOW_H_
#define _ALERTWINDOW_H_

// TODO parameters instead of #define
#define WINDOW_WIDTH  96
#define WINDOW_HEIGHT 48
#define WINDOW_MARGIN 3

#include "../Window/Window.h"


class AlertWindow : public Window {

    public:

        // AlertWindow(/*OledMenu *oledMenu*/, int id, char *name, char* message, void(*drawFunction)(AlertWindow *w));
        AlertWindow(OledMenu *oledMenu, int id, char* name, char* message, void(*drawFunction)(Window *w) = &AlertWindow::defaultDrawFunction, void(*handleClick)(Window *w, int btnMillis) = &AlertWindow::defaultHandleClick);
    
    protected:

        // Default functions
        static void defaultTopBar(Window *w);
        static void defaultDrawFunction(Window *w);
        static void defaultHandleClick(Window *w, int btnMillis);
};

#endif
