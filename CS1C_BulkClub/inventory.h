#ifndef INVENTORY_H
#define INVENTORY_H
#include "item.h"

class Inventory {
private:
    Item* inv;

public:
    Inventory();
    ~Inventory();
};

#endif // INVENTORY_H
