#include "OledMenu.h"

void OledMenu::init(Adafruit_SSD1306 *display) {

  this->display = display;

  currentMenu = 0;

  nMenu = 0;
}

void OledMenu::handleClick(int btnMillis) {

  // TODO: check that function pointer is not nullptr (== nullptr ?)

  (menu[currentMenu]->handleClick) (menu[currentMenu], btnMillis);
}

void OledMenu::addMenu(Menu *m) {

    menu[nMenu++] = m;
}

void OledMenu::handleMenu() {

    clearOled();
    (menu[currentMenu]->drawFunction) (menu[currentMenu]);
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
