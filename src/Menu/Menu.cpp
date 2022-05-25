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
