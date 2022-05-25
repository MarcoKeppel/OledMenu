#ifndef _MENU_H_
#define _MENU_H_

class OledMenu;

class Menu {

    public:

        OledMenu *oledMenu;

        int id;
        const char *name;

        void (*drawFunction)(Menu *m);
        void (*handleClick)(Menu *m, int btnMillis);

        Menu(OledMenu *oledMenu, int id, char *name, int nPage, void(*drawFunction)(Menu *m));
        Menu(OledMenu *oledMenu, int id, char *name, int nPage, void(*drawFunction)(Menu *m), void(*handleClick)(Menu *m, int btnMillis));
};

#endif
