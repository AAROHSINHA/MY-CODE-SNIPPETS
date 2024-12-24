#include <iostream>

class Employee{
private:
    // These three properties are encapsulated in private class. They are protected in the class now
    std::string Name;
    std::string Company;
    int Age;
public:

    // Setter Functions
    void SetName(std::string newName){
        this->Name = newName;
    }
    void setCompany(std::string newCompany){
        this->Company = newCompany;
    }
    void setAge(int newAge){
        // we can also set some restrictions and conditions for setting the variables
        if(newAge >= 18){
        this->Age = newAge;
        }
    }

    // Getter functions
    std::string getName(){
        return this->Name;
    }
    std::string getCompany(){
        return this->Company;
    }
    int getAge(){
        return this->Age;
    }
    
    // CONSTRUCTOR
    Employee(std::string name, std::string company, int age) : 
            Name{name},
            Company{company},
            Age{age}{

            }

    void IntroduceEmployee(){
        std::cout << "Name - " << Name << std::endl;
        std::cout << "Company Name - " << Company << std::endl;
        std::cout << "Age - " << Age << std::endl;

    }

    // DESTRUCTOR
    ~Employee(){
        std::cout << "DESTRUCTOR CALLED" << std::endl;
    }

};

int main(){
    Employee employee1 = Employee("Jeremy Renner", "Marvel Studios", 38);
    // as the members are encapsulated, we cannot directly access them
    // int age = employee1.Age; --> THIS IS WRONG NOW
    employee1.IntroduceEmployee();
    
    // using the getter and setter functions
    std::cout << employee1.getName() << " - " << employee1.getCompany() << " - " << employee1.getAge() << std::endl;
    employee1.SetName("Henry Cavil");
    employee1.setCompany("DCEU");
    employee1.setAge(30);
    std::cout << employee1.getName() << " - " << employee1.getCompany() << " - " << employee1.getAge() << std::endl;


    return 0;
}