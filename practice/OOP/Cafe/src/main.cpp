#include "menuItem.h"
#include "order.h"
#include "cafe.h"
#include "waiter.h"
#include "manager.h"
#include "cook.h"

int main() {
    Cafe myCafe;

    MenuItem coffee("Coffee", 50);
    MenuItem tea("Tea", 40);
    MenuItem cake("Cake", 100);

    myCafe.add_menu_item(coffee);
    myCafe.add_menu_item(tea);
    myCafe.add_menu_item(cake);

    std::cout << "MENU:\n";
    myCafe.print_menu();

    Order order1;
    order1.add_item(coffee);
    order1.add_item(cake);
    order1.calculate_total();

    myCafe.create_order(order1);

    std::cout << "\nORDERS:\n";
    myCafe.print_orders();

    Waiter waiter1("Alice", 22, 30000, 40, 500);
    Waiter waiter2("Bob", 25, 32000, 35, 700);
    Cook cook1("John", 30, 50000, 40, Cook::Skill::Middle);
    Cook cook2("Emma", 28, 55000, 35, Cook::Skill::Sous_Chief);
    Manager manager1("Michael", 40, 70000, 45, 5);

    auto waiters = myCafe.get_waiters();
    waiters.push_back(waiter1);
    waiters.push_back(waiter2);
    myCafe.set_waiters(waiters);

    auto cooks = myCafe.get_cooks();
    cooks.push_back(cook1);
    cooks.push_back(cook2);
    myCafe.set_cooks(cooks);

    auto managers = myCafe.get_managers();
    managers.push_back(manager1);
    myCafe.set_managers(managers);

    std::cout << "\nEMPLOYEES:\n";

    std::cout << "\nWaiters:\n";
    for (const auto& waiter : myCafe.get_waiters()) {
        waiter.print_info();
    }

    std::cout << "\nCooks:\n";
    for (const auto& cook : myCafe.get_cooks()) {
        cook.print_info();
    }

    std::cout << "\nManagers:\n";
    for (const auto& manager : myCafe.get_managers()) {
        manager.print_info();
    }

    return 0;
}
