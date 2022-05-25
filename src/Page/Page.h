#ifndef _PAGE_H_
#define _PAGE_H_

class PageMenu;

class Page {

    public:

        PageMenu *pageMenu;

        Page(PageMenu *pageMenu, void (*drawFunction)(Page *p));
        Page(PageMenu *pageMenu, void (*drawFunction)(Page *p), void (*handleClick)(Page *p, int btnMillis));

        void (*drawFunction)(Page *p);
        void (*handleClick)(Page *p, int btnMillis);
};

#endif
