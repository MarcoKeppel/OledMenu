#include "AlertWindow.h"
#include "../OledMenu/OledMenu.h"

AlertWindow::AlertWindow(OledMenu *oledMenu, int id, char* name, char* message, void(*drawFunction)(Window *w), void(*handleClick)(Window *w, int btnMillis))
    : Window(oledMenu, id, name, message, drawFunction, handleClick) {
}

// Default functions

void AlertWindow::defaultTopBar(Window *w) {

    AlertWindow *_w = (AlertWindow*)w;

    Adafruit_SSD1306* display = _w->oledMenu->display;

    int dw = display->width();
    int dh = display->height();

    display->print(w->name);
  
    // TODO better expressions
    display->drawFastHLine((dw - (WINDOW_WIDTH)) / 2, ((dh - (WINDOW_HEIGHT)) / 2 + /*padding*/ 1) + 9, WINDOW_WIDTH, 1);
    display->setCursor((dw - (WINDOW_WIDTH)) / 2 + /*padding*/ 1, ((dh - (WINDOW_HEIGHT)) / 2 + /*padding*/ 1) + 12);
}

void AlertWindow::defaultDrawFunction(Window *w) {

    AlertWindow *_w = (AlertWindow*)w;

    Adafruit_SSD1306* display = w->oledMenu->display;

    int dw = display->width();
    int dh = display->height();

    // TODO draw window (make this a separate function?)
    // TODO remove hardcoded display dimensions
    display->fillRect((dw - (2*WINDOW_MARGIN + WINDOW_WIDTH + /*2*border*/ 2*1)) / 2, (dh - (2*WINDOW_MARGIN + WINDOW_HEIGHT + /*2*border*/ 2*1)) / 2, (2*WINDOW_MARGIN + WINDOW_WIDTH + /*2*border*/ 2*1), (2*WINDOW_MARGIN + WINDOW_HEIGHT + /*border*/ 2), 0);
    display->drawRect((dw - (WINDOW_WIDTH + /*2*border*/ 2*1)) / 2, (dh - (WINDOW_HEIGHT + /*2*border*/ 2*1)) / 2, WINDOW_WIDTH + 2, WINDOW_HEIGHT + 2, 1);
    display->setCursor((dw - (WINDOW_WIDTH)) / 2 + /*padding*/ 1, (dh - (WINDOW_HEIGHT)) / 2 + /*padding*/ 1);
    
    AlertWindow::defaultTopBar(w);

    display->print(_w->message);
}

void AlertWindow::defaultHandleClick(Window *w, int btnMillis) {

    AlertWindow *_w = (AlertWindow*)w;

    // TODO macro
    // if (btnMillis > BTN_SHORT_PRESS) {
    if (btnMillis > 100) {
        // TODO dismiss window
        _w->oledMenu->dismissWindow();
    }
}

