#include "PageMenu.h"
#include "../OledMenu/OledMenu.h"

PageMenu::PageMenu(OledMenu *oledMenu, int id, char *name, int nPage, void(*drawFunction)(Menu *m))
    : PageMenu(oledMenu, id, name, nPage, drawFunction, nullptr) { }

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
