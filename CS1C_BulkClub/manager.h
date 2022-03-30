#ifndef MANAGER_H
#define MANAGER_H
#include <QDebug>
#include "date.h"

class Manager {
private:

public:
    Manager();

    /*!
     * \brief displays
     * \param day: Date
     */
    void display(Date day);
};

#endif // MANAGER_H
