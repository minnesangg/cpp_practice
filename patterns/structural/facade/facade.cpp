#include <iostream>
#include <string>

class Amplifier{
public: 
    void on() {
        std::cout << "Amplifier on!" << std::endl;
    }

    void setVolume(int level){
        std::cout << "Volume: " << level << std::endl;
    }
};

class DVDPlayer{
public: 
    void on() {
        std::cout << "DVD on!" << std::endl;
    }

    void play(const std::string& movie){
        std::cout << "Playing movie: " << movie << std::endl;
    }
};

class Projector{
public: 
    void on() {
        std::cout << "Projector on!" << std::endl;
    }

    void wideScreenMode(){
        std::cout << "Wide screemn mode activated!" << std::endl;
    }
};


class HomeTheaterFacade{
    Amplifier *amp;
    DVDPlayer *dvd;
    Projector *proj;

public: 
    HomeTheaterFacade(Amplifier *a, DVDPlayer *d, Projector *p) : amp(a), dvd(d), proj(p) {}

    void watchMovie(const std::string &movie){
        std::cout << "Preparing to show the movie..." << std::endl;
        amp->on();
        amp->setVolume(5);
        proj->on();
        proj->wideScreenMode();
        dvd->on();
        dvd->play(movie);
    }
};


int main(){
    Amplifier amp;
    DVDPlayer dvd;
    Projector proj;

    HomeTheaterFacade theater(&amp, &dvd, &proj);
    theater.watchMovie("Mr. Robot");
}