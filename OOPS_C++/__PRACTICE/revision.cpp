#include <iostream>
using namespace std;

class Student {
public:
    string name;
    int age;
    float cgpa;

    void Introduce(){
        cout << this->name << " is " << this->age << " years old and aggregated " << this->cgpa << " CGPA " << endl; 
    }
};

class Game {
private:
    string GameName;
    string GameGenre;
    int GameRating;

public:
    Game(string name, string genre, int rating){
        this->GameName = name;
        this->GameGenre = genre;
        this->GameRating = rating;
    }

    void AboutGame(){
        cout << this->GameName << " " << this->GameGenre << " " << this->GameRating << endl;
    }
};

class College {
private:
    string CollegeType;
    string CollegeName;
    string CollegeLocation;

public:
    // multiple constructors
    // 1. default
    College() : CollegeType("GFTI"), CollegeName("BIT MESRA"), CollegeLocation("JHARKHAND"){}

    // 2. Manual
    College(string type, string name, string location){
        this->CollegeType = type;
        this->CollegeName = name;
        this->CollegeLocation = location;
    }

    void AboutCollege(){
        cout << this->CollegeName << "\n";
        cout << this->CollegeLocation << "\n";
        cout << this->CollegeType << "\n";
    }
};

class Person{
private:
    int* age;
    int* height;
    int* salary;
public:
    Person(): age(new int(18)), height(new int(170)), salary(new int(5999)){}
    Person(int age, int height, int salary){
        this->age = new int(age);
        this->height = new int(height);
        this->salary = new int(salary);
    }
    
    void SetPerson(int newAge, int newHeight, int newSalary){
        *this->age = newAge;
        *this->height = newHeight;
        *this->salary = newSalary;
    }
    
    void about() const {
        std::cout << "Age: " << *age << " years" << std::endl;
        std::cout << "Height: " << *height << " cm" << std::endl;
        std::cout << "Salary: $" << *salary << std::endl;
    }

    // destructor
    ~Person(){
        delete age;
        delete height;
        delete salary;
    }
};

class AbstractEmployee {
protected:
    virtual void AskForPromotion(int age, int salary){
        if(age >= 30 && salary <= 50000){
            cout << "YES YOU WILL BE PROMOTED\n";
        }else{
            cout << "SORRY YOU CAN'T BE PROMOTED RIGHT NOW!\n";
        }
    }
};

class Employee: protected AbstractEmployee{
protected:
    string name;
    string company;
    int age;
    int salary;
public:
    Employee(string name, string company, int age, int salary){
        this->name = name;
        this->company = company;
        this->age = age;
        this->salary = salary;
    }

    void AboutEmployee(){
        cout << "Name : " << this->name << endl;
        cout <<  "Age : " << this->age << endl;
        cout << "Salary : " << this->salary << endl;
    }

    void CheckPromotion() {
        AskForPromotion(this->age, this->salary);
    }
};

class SoftwareEngineer : public Employee {
protected:
    string type;
    string favoriteProgrammingLanguage;
public:
    SoftwareEngineer(string name, string company, int age, int salary, string type, string favoriteProgrammingLanguage) :
    Employee(name, company, age, salary) {
        this->type = type;
        this->favoriteProgrammingLanguage = favoriteProgrammingLanguage;
    }

    void AboutSoftwareEngineer(){
        AboutEmployee();
        cout << "Type : " << this->type << endl;
        cout << "Favorite Programming Language : " << favoriteProgrammingLanguage << endl;
    }
};

struct Project{
    string projectName;
    string description;
};

struct Experience{
    string Organization;
    string Skills;
    int year;
    int period;
};

class SoftwareEngineerResume: public SoftwareEngineer {
protected:
    Project projectList[3]; // maximum 3 projects allowed
    Experience experienceList[2]; // maximum 2 experience credential required
    string skills[5]; // enter 5 skills related to software
public:
    SoftwareEngineerResume(string name, string company, int age, int salary, string type, string favoriteProgrammingLanguage, Project projectList[3], Experience experienceList[2], string skills[5]) :
    SoftwareEngineer(name, company, age, salary, type, favoriteProgrammingLanguage) {
        for (int i = 0; i < 3; i++) {
            this->projectList[i] = projectList[i];
        }
        for (int i = 0; i < 2; i++) {
            this->experienceList[i] = experienceList[i];
        }
        for (int i = 0; i < 5; i++) {
            this->skills[i] = skills[i];
        }
    }

    void showResume(){
        AboutSoftwareEngineer();
        cout << "-------------------------------------------" << endl;
        cout << "----------- PROJECT LIST ------------------" << endl;
        for (int i = 0; i < 3; i++) {
            cout << endl;
            cout << "PROJECT : " << i + 1 << endl;
            cout << "Name : " << this->projectList[i].projectName << endl;
            cout << "Description : " << this->projectList[i].description << endl;
            cout << endl;
        }
        cout << "-------------------------------------------" << endl;
        cout << "------------ EXPERIENCE -------------------" << endl;
        for (int i = 0; i < 2; i++) {
            cout << endl;
            cout << "EXPERIENCE : " << i + 1 << endl;
            cout << "Organization : " << this->experienceList[i].Organization << endl;
            cout << "Skills Learned : " << this->experienceList[i].Skills << endl;
            cout << "Year : " << this->experienceList[i].year << endl;
            cout << "Period : " << this->experienceList[i].period << endl;
            cout << endl;
        }
    }
    
};


int main(){
    Project projectList[3] = {
    {"Asteroids Clone", "Pygame spaceship dodging asteroids with power-ups"},
    {"Stream Central", "TMDB API-based movie/TV browser with async JS"},
    {"Brain Tumor Classifier", "TensorFlow model with Streamlit web app"}
    };

    Experience experienceList[2] = {
        {"Open Source", "C++, OOP, Data Structures", 2024, 6},
        {"Startup XYZ", "React, TypeScript, Node.js", 2025, 8}
    };

    string skills[5] = {"C++", "JavaScript", "React", "Data Structures", "OOP"};
    SoftwareEngineerResume resume1 = SoftwareEngineerResume("Justing Cheng", "TCS", 22, 0, "Backend Developer", "Javascript", projectList, experienceList, skills);

    resume1.showResume();

    return 0;
}