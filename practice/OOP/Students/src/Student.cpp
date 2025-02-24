#include "Student.h"
#include <iostream>
#include <fstream>

const std::string FILE_NAME = "data/student.txt";

Student::Student(std::string name, int age, int avg_score)
    : name(name), age(age), avg_score(avg_score) {}

void Student::print_student() const{
    std::cout << "Name: " << name << std::endl;
    std::cout << "Age: " << age << std::endl;
    std::cout << "Average score: " << avg_score << std::endl;
}

Student Student::create_student(){
    std::string name;
    int age;
    int avg_score;

    std::cout << "Enter name: ";    
    std::getline(std::cin, name);

    std::cout << "Enter age: ";
    std::cin >> age;
    std::cin.ignore();

    std::cout << "Enter student's average score: ";
    std::cin >> avg_score;

    return Student(name, age, avg_score); 
}

void Student::save_to_file() const{
    std::ofstream output_file(FILE_NAME, std::ios::app);

    if(!output_file) {
        std::cerr << "Error opening file." << std::endl;
        return;
    }

    output_file << name << " " << age << " " << avg_score << std::endl;
    output_file.close();
}

void Student::read_from_file(){
    std::ifstream input_file(FILE_NAME);

    if(!input_file) {
        std::cerr << "Error opening file." << std::endl;
        return;
    }

    std::string name;
    int age;
    int avg_score;  

    while (input_file >> name >> age >> avg_score) {
        Student student(name, age, avg_score); 
        student.print_student(); 
    }

    input_file.close();
}
