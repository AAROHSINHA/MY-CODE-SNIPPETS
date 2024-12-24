#include <iostream>

// 1. EXAMPLE OF CLASS - employee class
// access modifiers - private/ public/ protected
class Employee{
public:
    std::string Name;
    std::string Company;
    int Age;

    // class methods
    void IntroduceEmployee(){
        std::cout << "Name - " << Name << std::endl;
        std::cout << "Company Name - " << Company << std::endl;
        std::cout << "Age - " << Age << std::endl;
    }

};

int main(){                                                                                                         
    Employee employee1 = Employee();

    // accessing the function members
    employee1.Name = "Jennifer Brewster";
    employee1.Company = "MCafree Inc.";
    employee1.Age = 27;
    std::cout << employee1.Name << std::endl;
    std::cout << employee1.Company << std::endl;
    std::cout << employee1.Age << std::endl;

    // invoking the class Methods
    employee1.IntroduceEmployee();

    return 0;
}