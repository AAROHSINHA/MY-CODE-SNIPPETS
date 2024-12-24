#include <iostream>

// Class Example - student
class Student{
public:
    std::string Name;
    std::string School;
    int Age;
    
    /*
    Constructor 
    1.  Constructor must be public
    2. Constructor must have same name as the class
    2. Constructor must have no return type
    */
    Student(std::string StudentName, std::string SchoolName, int StudentAge){
        this->Name = StudentName;
        this->School = SchoolName;
        this->Age = StudentAge;
    }

     // class methods
    void IntroduceStudent(){
        std::cout << "Name - " << Name << std::endl;
        std::cout << "School Name - " << School << std::endl;
        std::cout << "Age - " << Age << std::endl;
    }

};

// DEFAULT CONSTRUCTORS TO INITIALIZE THE VARIABLE
class Room{
public:
    int length;
    int width;
    int height;

    // Constructor
    Room() : length{30}, width{20}, height{40}{
    }

    // Methods
    void CalcArea(){
        std::cout << "The area of the room is - " << length*width << std::endl;
    }
    void CalcVolume(){
        std::cout << "The volume of the room is - " << length*width*height << std::endl;
    }
};

int main(){
    // // creating the object
    // Student student1 = Student("Jeremy Rydder", "Global High School", 15);

    // // calling method
    // student1.IntroduceStudent();
    Room room1 = Room();
    room1.CalcArea();
    room1.CalcVolume();
    return 0;
}