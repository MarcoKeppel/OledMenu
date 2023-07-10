#include "Menu.h"
#include "../OledMenu/OledMenu.h"

Menu::Menu(OledMenu *oledMenu, int id, char *name, int nPage, void(*drawFunction)(Menu *m)) : Menu(oledMenu, id, name, nPage, drawFunction, nullptr) {

}

Menu::Menu(OledMenu *oledMenu, int id, char *name, int nPage, void(*drawFunction)(Menu *m), void(*handleClick)(Menu *m, int btnMillis)) {

    this->oledMenu = oledMenu;
    this->id = id;
    this->name = name;
    this->drawFunction = drawFunction;
    this->handleClick = handleClick;
}

// Default functions

void Menu::defaultTopBar(Menu *m) {

    m->oledMenu->display->print(m->name);
    
    m->oledMenu->display->drawFastHLine(0, 9, 128, 1);
    m->oledMenu->display->setCursor(0, 12);
}

void Menu::defaultDrawFunction(Menu *m) {

    Menu *_m = (Menu*) m;           // The casting is only to keep the method consistent with every other default method in derived classes

    Menu::defaultTopBar(_m);
}

void Menu::defaultHandleClick(Menu *m, int btnMillis) {

    Menu *_m = (Menu*)m;            // The casting is only to keep the method consistent with every other default method in derived classes

    // TODO macro
    // if (btnMillis > BTN_LONG_PRESS) {
    if (btnMillis > 2000) {
        _m->oledMenu->changeMenu();
    }
}
