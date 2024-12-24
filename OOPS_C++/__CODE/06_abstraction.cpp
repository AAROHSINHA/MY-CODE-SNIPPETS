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

int main(){
    Employee employee1 = Employee("Jeremy Renner", "Marvel Studios", 38);
    Employee employee2 = Employee("Tom Holland", "Marvel Studios", 25);
    employee1.AskForPromotion();
    employee2.AskForPromotion();
    
    return 0;
}