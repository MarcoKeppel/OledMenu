#ifndef _PAGEMENU_H_
#define _PAGEMENU_H_

#define MAX_N_PAGES 4

#include "../Menu/Menu.h"
#include "../Page/Page.h"

class PageMenu : public Menu {
    
    public:
        
        PageMenu(OledMenu *oledMenu, int id, char *name, int nPage, void(*drawFunction)(Menu *m));
        PageMenu(OledMenu *oledMenu, int id, char *name, int nPage, void(*drawFunction)(Menu *m) = &PageMenu::defaultDrawFunction, void(*handleClick)(Menu *m, int btnMillis) = &PageMenu::defaultHandleClick);

        void addPage(Page *p);
        void changePage();

        void drawPage();
        void clickPage(int btnMillis);

        int nPage;
        int currentPage;

        Page *page[MAX_N_PAGES];

    protected:

        // Default functions
        static void defaultTopBar(PageMenu *m);
        static void defaultDrawFunction(Menu *m);
        static void defaultHandleClick(Menu *m, int btnMillis);
};

#endif
