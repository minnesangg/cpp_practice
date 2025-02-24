#ifndef MOVIES_H
#define MOVIES_H

#include<vector>
#include<string>

class Movie {
private:
    std::string movie_name;
    std::string genre;
    int year_of_release;
    
public:
    Movie(const std::string& name, const std::string& genre, int year);
    
    void print_movie() const;
    std::string get_name() const;
    std::string get_genre() const;
    int get_year() const;
};

class Movies {
private:
    std::vector<Movie> movies;
    
public:
    void add_movie(const std::string& name, const std::string& genre, int year);
    void print_movies() const;
    void delete_movie(const std::string& name);
    void search_movie(const std::string& name) const;
    void save_to_file(const std::string& filename, const std::string& name, const std::string& genre, int year) const;
    void load_from_file(const std::string& filename);
};

#endif