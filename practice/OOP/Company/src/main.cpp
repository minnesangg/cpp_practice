#include "intern.h"
#include "engineer.h"
#include "manager.h"

int main(){
    Employee* employees[] = {
        new Manager("John", 30, 5000, 5), 
        new Engineer("Alice", 25, 3000, 3), 
        new Intern("Bob", 20, 1000, "Alice")
    };

    for(Employee* employee : employees){
        employee->print_info(*employee);
    }

    for(Employee* employee : employees){
        delete employee;
    }
    
    return 0;
}