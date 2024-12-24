#include <iostream>

class Person{
public:
    int* age;
    int* height;
    int* salary;

    // Constructor
    Person(int a, int h, int s) : age{new int(25)}, height{new int(170)}, salary{new int(90000)}{
        this->age = new int(a);
        this->height = new int(h);
        this->salary = new int(s);
        std::cout << "NEW Person MADE" <<std::endl;
    }

    // Destructor
    ~Person(){
        delete age;
        delete height;
        delete salary;

        std::cout << "Person has died (object destroyed)" << std::endl;
    }

    // Setter
    void setDetails(int a, int h, int s) {
    *age = a;
    *height = h;
    *salary = s;
}

    // method
    void about() const {
        std::cout << "Age: " << *age << " years" << std::endl;
        std::cout << "Height: " << *height << " cm" << std::endl;
        std::cout << "Salary: $" << *salary << std::endl;
    }
};

int main(){
    Person p1 = Person(45, 175, 50000);
    p1.about();
    p1.setDetails(45, 175, 60000);
    p1.about();
    return 0;
}