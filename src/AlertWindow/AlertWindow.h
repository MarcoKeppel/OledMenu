#ifndef __ALERTWINDOW_H__
#define __ALERTWINDOW_H__

// TODO parameters instead of #define
#define WINDOW_WIDTH  96
#define WINDOW_HEIGHT 48
#define WINDOW_MARGIN 3

class OledMenu;

class AlertWindow {

    public:

        OledMenu *oledMenu;

        int id;
        const char *name;
        const char *message;

        void (*drawFunction)(AlertWindow *m);
        void (*handleClick)(AlertWindow *m, int btnMillis);

        // AlertWindow(/*OledMenu *oledMenu*/, int id, char *name, char* message, void(*drawFunction)(AlertWindow *w));
        AlertWindow(OledMenu *oledMenu, int id, char* name, char* message, void(*drawFunction)(AlertWindow *w) = &AlertWindow::defaultDrawFunction, void(*handleClick)(AlertWindow *w, int btnMillis) = &AlertWindow::defaultHandleClick);
    
    protected:

        // Default functions
        static void defaultTopBar(AlertWindow *w);
        static void defaultDrawFunction(AlertWindow *w);
        static void defaultHandleClick(AlertWindow *w, int btnMillis);
};

#endif
