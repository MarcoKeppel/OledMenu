#ifndef _OLEDMENU_H_
#define _OLEDMENU_H_

#include "../ListMenu/ListMenu.h"
#include "../PageMenu/PageMenu.h"
#include "../AlertWindow/AlertWindow.h"

#include <Adafruit_SSD1306.h>

#define MAX_N_MENU 6
#define WINDOW_STACK_SIZE 4     // TODO implement windows stack management and windows handling

class Menu;

class OledMenu {

    public:

        Adafruit_SSD1306 *display;

        Menu *menu[MAX_N_MENU];

        void init(Adafruit_SSD1306 *display);

        int currentMenu;

        void addMenu(Menu *m);
        void handleMenu();
        void changeMenu();

        void clearOled();
        void handleClick(int btnMillis);

        // TODO Window parent class
        AlertWindow *windowStack[WINDOW_STACK_SIZE];
        int windowStackPtr;

        void displayWindow(AlertWindow *w);
        void dismissWindow();

    private:
        int nMenu;
        // TODO: move methods to private block
};

#endif
