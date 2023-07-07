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

// Default functions

void ListMenu::defaultTopBar(ListMenu *m) {

    Adafruit_SSD1306* display = m->oledMenu->display;

    m->oledMenu->display->print(m->name);
    // int rad = 3;
    // int margin = 64;
    // int spacing = 12;
    
    // for (int i = 0; i < m->nPage; i++) {
    //     if (i == m->currentPage) {
    //         display->fillCircle(margin + i*spacing, 3, rad, 1); 
    //     }
    //     else {
    //         display->drawCircle(margin + i*spacing, 3, rad, 1); 
    //     }
    // }
  
  m->oledMenu->display->drawFastHLine(0, 9, 128, 1);
  m->oledMenu->display->setCursor(0, 12);
}

void ListMenu::defaultDrawFunction(Menu *m) {

    ListMenu *_m = (ListMenu*)m;

    Adafruit_SSD1306* display = _m->oledMenu->display;
    //drawTopBar(m);
    ListMenu::defaultTopBar(_m);

    if (!_m->isEditing) {

        for (int i = 0; i < _m->nOption; i++) {
            
            if (i == _m->currentOption) {
                _m->oledMenu->display->setTextColor(SSD1306_BLACK);
                _m->oledMenu->display->fillRect(0, display->getCursorY() - 1, 128, 9, SSD1306_WHITE);
                _m->oledMenu->display->print(_m->optionDesc[i]);
                _m->oledMenu->display->setCursor(64, display->getCursorY());
                _m->oledMenu->display->println(*(_m->optionVar[i]));
                _m->oledMenu->display->setTextColor(SSD1306_WHITE);
            }
            else {
                _m->oledMenu->display->print(_m->optionDesc[i]);
                _m->oledMenu->display->setCursor(64, display->getCursorY());
                _m->oledMenu->display->println(*(_m->optionVar[i]));
            }
        }
    }
    else {

        for (int i = 0; i < _m->nOption; i++) {
            
            if (i == _m->currentOption) {
                _m->oledMenu->display->print(_m->optionDesc[i]);
                _m->oledMenu->display->setTextColor(SSD1306_BLACK);
                _m->oledMenu->display->fillRect(63, display->getCursorY() - 1, 65, 9, SSD1306_WHITE);
                _m->oledMenu->display->setCursor(64, display->getCursorY());
                _m->oledMenu->display->println(*(_m->optionVar[i]));
                _m->oledMenu->display->setTextColor(SSD1306_WHITE);
            }
            else {
                _m->oledMenu->display->print(_m->optionDesc[i]);
                _m->oledMenu->display->setCursor(64, display->getCursorY());
                _m->oledMenu->display->println(*(_m->optionVar[i]));
            }
        }
    }
}

void ListMenu::defaultHandleClick(Menu *m, int btnMillis) {

    ListMenu *_m = (ListMenu*)m;

    // TODO macro
    // if (btnMillis > 5000) {
    if (btnMillis > 5000) {

        if (_m->isEditing) {
            _m->enterEditOption(false);
        }
        else {
            _m->enterEditOption(true);
        }
    }
    // TODO macro
    // else if (btnMillis > BTN_LONG_PRESS) {
    else if (btnMillis > 2000) {
        if (_m->isEditing) {
            _m->increaseOption(-1);
        }
        else {
            _m->oledMenu->changeMenu();
        }
    }
    // TODO macro
    // else if (btnMillis > BTN_SHORT_PRESS) {
    else if (btnMillis > 100) {
        if (_m->isEditing) {
            _m->increaseOption(1);
        }
        else {
            _m->changeOption();
        }
    }
}
