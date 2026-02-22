#include <iostream>
#include <cmath>
using namespace std;

// structures are no built in but user definde data types
struct SmartPhone{
    string name;
    int sotrageSpace;
    string color;
    float price;
};
// this structure has no data. It serves as a blueprint, a structure.

// structure with function 
struct Movie{
    string Name;
    int releaseYear;
    float ratings;

    void printMovieInfo(){
        std::cout << "Movie Name - " << this->Name << std::endl;
        std::cout << "Movie Release - " << this->releaseYear << std::endl;
        std::cout << "Movie Ratings - " << std::floor(this->ratings) << "." << this->ratings - std::floor(this->ratings) << std::endl;
    }  
};


int main(){
    SmartPhone smartphone1;
    smartphone1.name = "Samsung Galaxy M12";
    smartphone1.sotrageSpace = 64;
    smartphone1.color = "blue";
    smartphone1.price = 11000.00;

    SmartPhone smartphone2;
    smartphone2.name = "Samsung Galaxy S6 Ultra";
    smartphone2.sotrageSpace = 128;
    smartphone2.color = "black";
    smartphone2.price = 39099.99;

    Movie movie;
    movie.Name = "Avengers: Endgame";
    movie.releaseYear = 2019;
    movie.ratings = 8.1;
    movie.printMovieInfo();

    return 0;
}
