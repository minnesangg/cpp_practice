#include "menuItem.h"
#include "order.h"
#include "cafe.h"

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

    return 0;
}
