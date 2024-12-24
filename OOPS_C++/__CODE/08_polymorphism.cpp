#include <iostream>

class AbstractEmployee{
    // any class that gets this AbstractEmployee class assigned is obligated to go through this function
    // using virtual and =0 makes this class abstract class and the method obligatory.
    virtual void AskForPromotion() = 0;
};

// Here we add the abstract class to out main class
class Employee : AbstractEmployee{
private:
    // These three properties are encapsulated in private class. They are protected in the class now
    std::string Name;
    std::string Company;
protected:
    int Age;
public:
    // CONSTRUCTOR
    Employee(std::string name, std::string company, int age) : 
            Name{name},
            Company{company},
            Age{age}{

            }
    void SetName(std::string newName){
        this->Name = newName;
    }
    void setCompany(std::string newCompany){
        this->Company = newCompany;
    }
    void setAge(int newAge){
        if(newAge >= 18){
        this->Age = newAge;
        }
    }
    std::string getName(){
        return this->Name;
    }
    std::string getCompany(){
        return this->Company;
    }
    int getAge(){
        return this->Age;
    }
    

    void IntroduceEmployee(){
        std::cout << "Name - " << Name << std::endl;
        std::cout << "Company Name - " << Company << std::endl;
        std::cout << "Age - " << Age << std::endl;

    }


    // implementing that abstract function
    void AskForPromotion(){
        if(Age >= 30){
            std::cout << Name << " got promoted!!" << std::endl;
        }else{
            std::cout << Name << " cannot be promoted right now..." << std::endl; 
        }
    }

    // instance of this function in the Employee class
    virtual void Work(){
        std::cout << Name << " is checking email, task backlog, performing tasks...." << std::endl;
    }

};


class Developer : public Employee {
public:
    std::string FavProgrammingLanguage;

    Developer(std::string name, std::string company, int age, std::string language)
        : Employee(name, company, age)
    {
        this->FavProgrammingLanguage = language;
    }
    
    void FixBug(){
        std::cout << getName() << " fixed a bug using " << this->FavProgrammingLanguage << std::endl;
    }
    void yearsOnEarth(){
        std::cout << getName() << " has been on Earth since " << 2025 - Age << std::endl;
    }

    // instance of this function which is already in this parent class in the child class also with some altered functionality
    void Work(){
        std::cout << getName() << " is writing code, finding errors, debuging them...." << std::endl;
    }
};

class Teacher : public Employee{
public:
    std::string Subject;

    // Constructor
    Teacher(std::string name, std::string company, int age, std::string subject)
        : Employee(name, company, age) // constructing the parent class
    {
        this->Subject = subject;
    }

    // method
    void PrepareLesson(){
        std::cout << getName() << " is preparing to teach " << Subject << std::endl;
        std::cout << "Even at age of " << Age << ", " << getName() << " teaches so good " << Subject << " for " << getCompany() << std::endl; 
    }

    // instance of this function which is already in this parent class in the child class also with some altered functionality
    void Work(){
        std::cout << getName() << " is evaluating answer sheets, finding wrong answers, remarking them...." << std::endl;
    }
};

int main(){
    // The most common use of polymorphism is when a parent class reference is used 
    // to refer to a child class object.
    Developer dev1 = Developer("Robert Rufalo", "Microsoft", 29, "JavaScript");
    Teacher teacher1 = Teacher("Angelina Rose", "Merlin Institution", 42, "History");
    //dev1.Work(); // we get the work function of the child class Developer rather than Employee
    //teacher1.Work();  // we get the work function of the child class Teacher rather than Employee

    // MEANING OF pointer of base class can hold reference to derived class object
    Employee* e1 = &dev1; 
    Employee* e2 = &teacher1;
    /*
    -----> WITHOUT VIRTUAL CLASS

    e1->Work();
    e2->Work();
    // we see that the function work of the Employee class happens

    
    => e1->Work() != dev1.Work();;
    => e2->Work() != teacher1.Work();;

    */

   // WITH VIRTUAL CLASS
   e1->Work();
   e2->Work();
    return 0;
}