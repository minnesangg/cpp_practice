#ifndef MENUITEM_H
#define MENUITEM_H

#include <string>
#include <iostream>

using uint = unsigned int;

class MenuItem{
private:
    std::string name;
    uint price;

public:
    MenuItem();
    MenuItem(std::string name, uint price);
    ~MenuItem();

    std::string get_name() const;
    uint get_price() const;

    void set_name(std::string name);
    void set_price(uint price);

    void print_item() const;

};

#endif