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

};


// child class of parent/base/super class Employee
// the developer class no has all of the properties, methods and members of employee class
// it can also have its own specific properties
class Developer : public Employee {
public:
    std::string FavProgrammingLanguage;

    // note that we also inherit the constructor of the parent class. So while
    // making constructor for the child class, keep in mind about that.
    // we also have to add the parent parameters to the child constructor 
    Developer(std::string name, std::string company, int age, std::string language)
        : Employee(name, company, age)
    {
        this->FavProgrammingLanguage = language;
    }
    // we dont have to worry for the parent properties in the constructor as they are set up in the parent class
    // : Employee(name, company, age) we just add this for the parent constructor and we are good to go!
    
    void FixBug(){
        std::cout << getName() << " fixed a bug using " << this->FavProgrammingLanguage << std::endl;
    }
    // note that we cannot use the properties of the parent class directly in the child class that is why we use getName.
    // but we can use Age directly as it is in the protected modifier of parent class not in private like the Name.
    // protected members can be used by derived class
    void yearsOnEarth(){
        std::cout << getName() << " has been on Earth since " << 2025 - Age << std::endl;
        // see! we used the age
    }
};

/*
note for use of abstract classes and functions on childrem
1. The inheritance Developer : Employee is private hence we cannot use direct abstracted methods and classes.
2. So we need to set it to public by Developer : public Employee 
*/


// No let's create one more class that inherits from the Employee class
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
};

int main(){
    Developer dev1 = Developer("Robert Rufalo", "Microsoft", 29, "JavaScript");
    dev1.FixBug();
    dev1.yearsOnEarth();
    dev1.AskForPromotion(); // we can use this because we changed the inheritance from private to public
    std::cout << dev1.getName() << std::endl;
    
    std::cout << " " << std::endl;

    Teacher teacher1 = Teacher("Angelina Rose", "Merlin Institution", 42, "History");
    teacher1.IntroduceEmployee();
    teacher1.PrepareLesson();
    teacher1.AskForPromotion();
    std::cout << teacher1.getCompany() << std::endl;


    

    return 0;
}