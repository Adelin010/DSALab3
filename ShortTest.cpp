#include <assert.h>
#include <exception>
#include <iostream>

#include "ShortTest.h"
#include "IndexedList.h"
#include "ListIterator.h"


using std::cout;

void testAll() {
    IndexedList list = IndexedList();
    assert(list.isEmpty());
    // list.addToEnd(1);
    // assert(list.size() == 1);
    // list.addToPosition(0,2);
    // list.addToEnd(2);
    // assert(list.size() == 2);
    // assert(list.search(1) == 1);
    // assert(list.search(2) == 1);
    // assert(list.search(4) == 0);
    
    for(int i = 1; i <= 8; ++i){
        list.addToEnd(i);
    }


    list.addToPosition(4, 3000);

    cout << list.search(201);

    // ListIterator it = list.iterator();
    // assert(it.valid());
    // it.next();
    // assert(it.getCurrent() == 1);
    // it.first();
    // assert(it.getCurrent() == 2);
    // assert(list.search(1) == 1);
    // assert(list.setElement(1,3) == 1);
    // assert(list.getElement(1) == 3);
    // assert(list.remove(0) == 2);
    // assert(list.size() == 1);
}
