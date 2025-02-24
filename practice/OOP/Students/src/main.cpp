#include "Student.h"
#include <iostream>
#include <vector>

void menu(){
    std::cout << "1. Add student" << std::endl;
    std::cout << "2. Save to file" << std::endl;
    std::cout << "3. Read from file" << std::endl;
    std::cout << "4. Exit" << std::endl;
}                                                           

void options(){
    std::cout << "Welcome to the student management system" << std::endl;
    std::vector<Student> students;  

    while(true){
        menu();
        int choice;
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        std::cin.ignore();  

        switch(choice){
            case 1:
                {
                    Student student = Student::create_student();
                    students.push_back(student);  
                    student.print_student();
                    break;
                }
            case 2:
                for (const auto& student : students) {
                    student.save_to_file();  
                }
                break;
            case 3:
                Student::read_from_file();  
                break;
            case 4:
                return;
        }
    }
}

int main(){
    options();
    return 0;
}
