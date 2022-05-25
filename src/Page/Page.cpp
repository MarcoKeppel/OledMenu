#include "Page.h"
#include "../PageMenu/PageMenu.h"

Page::Page(PageMenu *pageMenu, void (*drawFunction)(Page *p))
    : Page(pageMenu, drawFunction, nullptr) { }

Page::Page(PageMenu *pageMenu, void (*drawFunction)(Page *p), void (*handleClick)(Page *p, int btnMillis)) {

    this->pageMenu = pageMenu;

    this->drawFunction = drawFunction;
    this->handleClick = handleClick;
}
