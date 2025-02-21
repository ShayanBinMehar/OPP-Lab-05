#include <iostream>
#include <string>

using namespace std;

class Movie {
private:
    string title;
    string director;
    int duration; 

public:

Movie() : title(""), director(""), duration(0) {}

    Movie(const string& title, const string& director, int duration)
        : title(title), director(director), duration(duration) {}

    void display() const {
        cout << "Title: " << title << ", Director: " << director
             << ", Duration: " << duration << " minutes" << endl;
    }
};

class CinemaHall {
private:
    string name;
    Movie movies[3]; 
    int numMovies;  
public:
    CinemaHall(const string& name,
               const string& movie1Title, const string& movie1Director, int movie1Duration,
               const string& movie2Title, const string& movie2Director, int movie2Duration,
               const string& movie3Title, const string& movie3Director, int movie3Duration)
        : name(name), numMovies(0) {

        movies[0] = Movie(movie1Title, movie1Director, movie1Duration);
        movies[1] = Movie(movie2Title, movie2Director, movie2Duration);
        movies[2] = Movie(movie3Title, movie3Director, movie3Duration);

        numMovies = 3;
    }

    void displayDetails() const {
        cout << "Cinema Hall: " << name << endl;
        cout << "Movies:" << endl;
        for (int i = 0; i < numMovies; i++) {
            movies[i].display();
        }
    }
};

int main() {
    CinemaHall cinema("Galaxy Cinemas",
                    "Oppenheimer", "Christopher Nolan", 180,
                    "Barbie", "Greta Gerwig", 114,
                    "Mission: Impossible - Dead Reckoning Part One", "Christopher McQuarrie", 163);

    cinema.displayDetails();

    return 0;
}
