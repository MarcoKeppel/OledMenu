#ifndef _PAGEMENU_H_
#define _PAGEMENU_H_

#define MAX_N_PAGES 4

#include "../Menu/Menu.h"
#include "../Page/Page.h"

class PageMenu : public Menu {
    
    public:
        
        PageMenu(OledMenu *oledMenu, int id, char *name, int nPage, void(*drawFunction)(Menu *m));
        PageMenu(OledMenu *oledMenu, int id, char *name, int nPage, void(*drawFunction)(Menu *m), void(*handleClick)(Menu *m, int btnMillis));

        void addPage(Page *p);
        void changePage();

        void drawPage();
        void clickPage(int btnMillis);

        int nPage;
        int currentPage;

        Page *page[MAX_N_PAGES];
};

#endif
