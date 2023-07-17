#include "AlertWindow.h"
#include "../OledMenu/OledMenu.h"

AlertWindow::AlertWindow(OledMenu *oledMenu, int id, char* name, char* message, void(*drawFunction)(AlertWindow *w), void(*handleClick)(AlertWindow *w, int btnMillis)) {

    this->oledMenu = oledMenu;
    this->id = id;
    this->name = name;
    this->message = message;
    this->drawFunction = drawFunction;
    this->handleClick = handleClick;
}

// Default functions

void AlertWindow::defaultTopBar(AlertWindow *w) {

    Adafruit_SSD1306* display = w->oledMenu->display;

    int dw = display->width();
    int dh = display->height();

    display->print(w->name);
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
  
    // TODO better expressions
    display->drawFastHLine((dw - (WINDOW_WIDTH)) / 2, ((dh - (WINDOW_HEIGHT)) / 2 + /*padding*/ 1) + 9, WINDOW_WIDTH, 1);
    display->setCursor((dw - (WINDOW_WIDTH)) / 2 + /*padding*/ 1, ((dh - (WINDOW_HEIGHT)) / 2 + /*padding*/ 1) + 12);
}

void AlertWindow::defaultDrawFunction(AlertWindow *w) {

    // ListMenu *_w = (ListMenu*)m;

    Adafruit_SSD1306* display = w->oledMenu->display;

    int dw = display->width();
    int dh = display->height();

    // TODO draw window (make this a separate function?)
    // TODO remove hardcoded display dimensions
    display->fillRect((dw - (2*WINDOW_MARGIN + WINDOW_WIDTH + /*2*border*/ 2*1)) / 2, (dh - (2*WINDOW_MARGIN + WINDOW_HEIGHT + /*2*border*/ 2*1)) / 2, (2*WINDOW_MARGIN + WINDOW_WIDTH + /*2*border*/ 2*1), (2*WINDOW_MARGIN + WINDOW_HEIGHT + /*border*/ 2), 0);
    display->drawRect((dw - (WINDOW_WIDTH + /*2*border*/ 2*1)) / 2, (dh - (WINDOW_HEIGHT + /*2*border*/ 2*1)) / 2, WINDOW_WIDTH + 2, WINDOW_HEIGHT + 2, 1);
    display->setCursor((dw - (WINDOW_WIDTH)) / 2 + /*padding*/ 1, (dh - (WINDOW_HEIGHT)) / 2 + /*padding*/ 1);
    
    AlertWindow::defaultTopBar(w);

    display->print(w->message);
}

void AlertWindow::defaultHandleClick(AlertWindow *w, int btnMillis) {

    // ListMenu *_w = (ListMenu*)m;

    // TODO macro
    // if (btnMillis > BTN_SHORT_PRESS) {
    if (btnMillis > 100) {
        // TODO dismiss window
        w->oledMenu->dismissWindow();
    }
}

