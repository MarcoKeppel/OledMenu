#include "Window.h"
#include "../OledMenu/OledMenu.h"

Window::Window(OledMenu *oledMenu, int id, char* name, char* message, void(*drawFunction)(Window *w), void(*handleClick)(Window *w, int btnMillis)) {

    this->oledMenu = oledMenu;
    this->id = id;
    this->name = name;
    this->message = message;
    this->drawFunction = drawFunction;
    this->handleClick = handleClick;
}