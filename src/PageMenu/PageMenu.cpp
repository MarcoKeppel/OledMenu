#include "PageMenu.h"
#include "../OledMenu/OledMenu.h"

// PageMenu::PageMenu(OledMenu *oledMenu, int id, char *name, int nPage, void(*drawFunction)(Menu *m))
//     : PageMenu(oledMenu, id, name, nPage, drawFunction, nullptr) { }

PageMenu::PageMenu(OledMenu *oledMenu, int id, char *name, int nPage, void(*drawFunction)(Menu *m), void(*handleClick)(Menu *m, int btnMillis))
    : Menu(oledMenu, id, name, nPage, drawFunction, handleClick) {

    this->nPage = 0;

    this->currentPage = 0;
}

void PageMenu::addPage(Page *p) {

    if (nPage >= MAX_N_PAGES) return;

    page[nPage] = p;
    
    nPage++;
}

void PageMenu::changePage() {

    currentPage++;
    currentPage %= nPage;

    oledMenu->handleMenu();
}

void PageMenu::drawPage() {

    this->page[currentPage]->drawFunction(this->page[currentPage]);
}

void PageMenu::clickPage(int btnMillis) {

    this->page[currentPage]->handleClick(this->page[currentPage], btnMillis);
}

// Default functions

void PageMenu::defaultTopBar(PageMenu *m) {

    m->oledMenu->display->print(m->name);
    int rad = 3;
    int margin = 64;
    int spacing = 12;
    
    if (m->nPage > 1) {
        for (int i = 0; i < m->nPage; i++) {
        if (i == m->currentPage) {
            m->oledMenu->display->fillCircle(margin + i*spacing, 3, rad, 1); 
        }
        else {
            m->oledMenu->display->drawCircle(margin + i*spacing, 3, rad, 1); 
        }
        }
    }
    
    m->oledMenu->display->drawFastHLine(0, 9, 128, 1);
    m->oledMenu->display->setCursor(0, 12);
}

void PageMenu::defaultDrawFunction(Menu *m) {

    PageMenu *_m = (PageMenu*) m;

    PageMenu::defaultTopBar(_m);

    _m->drawPage();
}

void PageMenu::defaultHandleClick(Menu *m, int btnMillis) {

    PageMenu *_m = (PageMenu*)m;

    // TODO macro
    // if (btnMillis > BTN_LONG_PRESS) {
    if (btnMillis > 2000) {
        _m->oledMenu->changeMenu();
    }
    // TODO macro
    // else if (btnMillis > BTN_SHORT_PRESS) {
    else if (btnMillis > 100) {
        _m->changePage();
    }
}
