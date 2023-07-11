#include "OledMenu.h"

void OledMenu::init(Adafruit_SSD1306 *display) {

  this->display = display;

  currentMenu = 0;

  nMenu = 0;

  windowStackPtr = 0;
}

void OledMenu::handleClick(int btnMillis) {

  if (windowStackPtr <= 0) {
    // TODO: check that function pointer is not nullptr (== nullptr ?)
    (menu[currentMenu]->handleClick) (menu[currentMenu], btnMillis);
  }
  else {
    // TODO better handling of click event
    (windowStack[windowStackPtr-1]->handleClick) (windowStack[windowStackPtr-1], btnMillis);
  }
}

void OledMenu::addMenu(Menu *m) {

    // TODO handle menu array is full
    menu[nMenu++] = m;
}

void OledMenu::handleMenu() {

    clearOled();
    (menu[currentMenu]->drawFunction) (menu[currentMenu]);

    // TODO better handling of drawing windows
    if (windowStackPtr > 0) {
      (windowStack[windowStackPtr-1]->drawFunction) (windowStack[windowStackPtr-1]);
    }
}

void OledMenu::changeMenu() {

    currentMenu++;
    currentMenu %= nMenu;

    handleMenu();
}

void OledMenu::clearOled() {
  
  display->clearDisplay();
  display->setTextSize(1);
  display->setTextColor(SSD1306_WHITE);
  display->setCursor(0, 0);
}

// TODO make method bool and return false if stack is full
void OledMenu::displayWindow(AlertWindow *w) {

  if (windowStackPtr) return;

  windowStack[windowStackPtr++] = w;

  handleMenu();
}

void OledMenu::dismissWindow() {

  if (windowStackPtr <= 0) return;

  windowStackPtr--;

  handleMenu();
}
