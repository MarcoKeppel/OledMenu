#include "ListMenu.h"
#include "../OledMenu/OledMenu.h"

ListMenu::ListMenu(OledMenu *oledMenu, int id, char *name, int nPage, void(*drawFunction)(Menu *m))
    : ListMenu(oledMenu, id, name, nPage, drawFunction, nullptr) { }

ListMenu::ListMenu(OledMenu *oledMenu, int id, char *name, int nPage, void(*drawFunction)(Menu *m), void(*handleClick)(Menu *m, int btnMillis))
    : Menu(oledMenu, id, name, nPage, drawFunction, handleClick) {

    this->nOption = 0;
    this->isEditing = false;

    this->currentOption = 0;
}

void ListMenu::addOption(char *desc, int *var) {

    if (nOption >= MAX_N_OPTIONS) return;

    optionDesc[nOption] = desc;
    optionVar [nOption] = var;
    
    nOption++;
}

void ListMenu::changeOption() {

    if (isEditing) return;

    currentOption++;
    currentOption %= nOption;

    oledMenu->handleMenu();
}

void ListMenu::enterEditOption(bool edit) {

    isEditing = edit;
    oledMenu->handleMenu();
}

void ListMenu::increaseOption(int inc) {
    
    if (!isEditing) return;

    *(optionVar[currentOption]) += inc;
    oledMenu->handleMenu();
}
