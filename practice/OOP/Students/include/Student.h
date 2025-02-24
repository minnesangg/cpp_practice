#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <vector> 

class Student {
private:
    std::string name;
    int age;
    int avg_score;

public:
    Student(std::string name, int age, int avg_score);
    void print_student() const;
    static Student create_student();  
    void save_to_file() const;
    static void read_from_file();  
};

#endif
