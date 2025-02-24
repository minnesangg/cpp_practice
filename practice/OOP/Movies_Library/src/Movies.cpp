#include"Movies.h"
#include<iostream>
#include<fstream>

// MOVIE CLASS
Movie::Movie(const std::string& name, const std::string& genre, int year)
    : movie_name{name}, genre{genre}, year_of_release{year} {
}

void Movie::print_movie() const {
    std::cout << "Movie Name: " << movie_name 
          << ", Genre: " << genre 
          << ", Year of Release: " << year_of_release 
          << std::endl;
}

std::string Movie::get_name() const {
    return movie_name;
}

std::string Movie::get_genre() const {
    return genre;
}

int Movie::get_year() const {
    return year_of_release;
}

// MOVIES CLASS
const std::string FILENAME = "movies.txt";

void Movies::add_movie(const std::string &name, const std::string &genre, int year) {
    movies.emplace_back(name, genre, year);
    save_to_file(FILENAME, name, genre, year);
}

void Movies::load_from_file(const std::string& filename) {
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Error opening file" << std::endl;
        return;
    }

    std::string name, genre;
    int year;
    while (true) {
        if (file.peek() == EOF) break;  
        
        std::getline(file, name, '"');  
        std::getline(file, name, '"');  
        file >> genre >> year;  
        
        file.ignore();  
        movies.emplace_back(name, genre, year);
    }
    file.close();
}

void Movies::save_to_file(const std::string& filename, const std::string &name, const std::string &genre, int year) const {
    std::ofstream file(FILENAME, std::ios::app);
    if(!file){
        std::cerr << "Error opening file" << std::endl;
        return;
    }

    file << "\"" << movie_name << "\" " << genre << " " << year_of_release << std::endl;
    file.close();
}

void Movies::delete_movie(const std::string &name) {
    std::ofstream file(FILENAME);
    if(!file){
        std::cerr << "Error opening file" << std::endl;
        return;
    }
    for(auto it = movies.begin(); it != movies.end(); it++){
        if(it -> get_name() == name){
            movies.erase(it);
            file
            break;
        }
    }
    file.close();
}