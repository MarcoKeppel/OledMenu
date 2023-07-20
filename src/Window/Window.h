#ifndef _WINDOW_H_
#define _WINDOW_H_

class OledMenu;

class Window {

    public:

        Window(OledMenu *oledMenu, int id, char* name, char* message, void(*drawFunction)(Window *w), void(*handleClick)(Window *w, int btnMillis));
        
        OledMenu *oledMenu;

        int id;
        const char *name;
        const char *message;

        void (*drawFunction)(Window *m);
        void (*handleClick)(Window *m, int btnMillis);

};

#endif
