#include <iostream>
using namespace std;

class Person{
public:
    int age;

    // Constructor 1 (no parameters, default value)
    Person() : age{70}{}

    // Constructor 2 (one parameter, the setter)
    Person(int ageee) : age{ageee}{
    }

    Person() : age{100}{}

};

int main(){
    Person p1, p2(30);
    std::cout << p1.age << " " << p2.age << std::endl;
    return 0;
}