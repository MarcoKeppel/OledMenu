#ifndef _LISTMENU_H_
#define _LISTMENU_H_

#define MAX_N_OPTIONS 8

#include "../Menu/Menu.h"


class ListMenu : public Menu {

    public:
        
        ListMenu(OledMenu *oledMenu, int id, char *name, int nPage, void(*drawFunction)(Menu *m));
        ListMenu(OledMenu *oledMenu, int id, char *name, int nPage, void(*drawFunction)(Menu *m) = &ListMenu::defaultDrawFunction, void(*handleClick)(Menu *m, int btnMillis) = &ListMenu::defaultHandleClick);

        void addOption(char *desc, int *var);

        void changeOption();

        void enterEditOption(bool edit);

        void increaseOption(int inc);

        int  nOption;
        int currentOption;
        bool isEditing;

        // TODO: make it a linked list or similar
        // TODO: parallel vectors may not be as tidy as objects (vector), std::map, or std::map-like structure
        // TODO: maybe they should not be public
        char *optionDesc[MAX_N_OPTIONS];
        int  *optionVar [MAX_N_OPTIONS];

    private:

        // Default functions
        static void defaultTopBar(ListMenu *m);
        static void defaultDrawFunction(Menu *m);
        static void defaultHandleClick(Menu *m, int btnMillis);
};

#endif
