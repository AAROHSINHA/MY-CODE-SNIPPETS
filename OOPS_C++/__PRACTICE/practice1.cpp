#include <iostream>
using namespace std;

// NOTE --> The problemm statements have been provided below the main() function

// Problem 1
class Student{
public:
    string Name;
    int RollNumber;
    float Marks;

    Student(string studentName, int rollNumber, float marks){
        this->Name = studentName;
        this->RollNumber = rollNumber;
        this->Marks = marks;
    }

    void displayDetails(){
        std::cout << "STUDENT NAME  -> " << this->Name << std::endl;
        std::cout << "STUDENT ROLL  -> " << this->RollNumber << std::endl;
        std::cout << "STUDENT MARKS -> " << this->Marks << std::endl;
        std::cout << "-------------------------" << std::endl;
    }
};

// PROBLEM 2
class BankAccount{
private:
    int AccountNumber;
    string AccountHolderName;

protected:
    float Balance;

public:
    // constructor
    BankAccount(int an, string ahn, float b) 
        : AccountNumber{an}, AccountHolderName{ahn}, Balance{b}{}

    
    // methods
    void deposit(int amount){
        this->Balance += amount;
        std::cout << amount << " has been deposited succesfully to account " << this->AccountNumber << std::endl;
    }
    void withdraw(int amount){
        if(this->Balance >= amount){
            this->Balance -= amount;
            std::cout << amount << " has been deducted succesfully from account " << this->AccountNumber << std::endl;
        }else{
            std::cout << "NOT ENOUGH BALANCE" << std::endl;
        }
    }
    void displayBalance(){
        std::cout << "Current Balance - " << this->Balance << std::endl;
    }

};
class SavingsAccount : public BankAccount{
private:
    float interestRate;
public:
    // constructor
    SavingsAccount(int an, string ahn, float b, float ir)
        : BankAccount(an, ahn, b){
            this->interestRate = ir;
        }

    void addInterest(){
        Balance += (this->interestRate*Balance)/100;
    }
};

// problem 3
class Shape{
protected:
    string Name;
public:
    Shape(string name){
        this->Name = name;
    }

    virtual void Area() = 0; // Pure virtual function
};
class Rectangle : public Shape{
private:
    int length;
    int breadth;
public:
    Rectangle(string name, int l, int b)
    : Shape(name){
        this->length = l;
        this->breadth = b;
    }
    void Area(){
        std::cout << "The Area of this " << Name << " is - " << length*breadth << std::endl;
    }
};
class Circle : public Shape{
private:
    float radius;
public:
    Circle(string name, float r)
    : Shape(name){
        this->radius = r;
    }

    void Area(){
        std::cout << "The Area of this " << Name << " is - " << 3.14 * radius * radius << std::endl;
    }
};

// Problem 3: Shape Hierarchy
// Objective: Implement a shape hierarchy using inheritance.

// Requirements:
// 1. Create a base class `Shape` with attributes:
//    - `name` (string)
// 2. Add a pure virtual method `area()` in the `Shape` class.
// 3. Create derived classes `Rectangle` and `Circle`:
//    - `Rectangle` has attributes `length` and `width`.
//    - `Circle` has an attribute `radius`.
//    - Implement the `area()` method in both classes.
// 4. Write a program to calculate and display the areas of a rectangle and a circle.


int main(){
    /*PROBLEM 1
    // array of 3 student objects
    Student students[] = {
         Student("Marcus Marcus", 135, 78),
        Student("James James", 84, 97),
        Student("Harry Harry", 65, 23)
    };

    for(int i = 0; i < 3; i++){
        students[i].displayDetails();
    }
    */

   /*PROBLEM 2
   BankAccount b1 = BankAccount(12345, "John Taylor", 240.0);
   b1.displayBalance();
   b1.deposit(1000);
   b1.deposit(2000);
   b1.deposit(3000);
   b1.displayBalance();
   b1.withdraw(5000);
   b1.displayBalance();
   b1.withdraw(10000);

   SavingsAccount sb1 = SavingsAccount(23456, "Clara Lroft", 5000, 8.5);
   sb1.displayBalance();
   sb1.addInterest();
   sb1.displayBalance();
    */

   return 0;
}


/*
Problem 1: Student Management System
Objective: Implement a simple system to manage student details.

Requirements:
1. Create a class `Student` with the following attributes:
   - `rollNumber` (integer)
   - `name` (string)
   - `marks` (float)
2. Add methods:
   - A constructor to initialize student details.
   - A method `displayDetails()` to print the student details.
3. Create and display the details of at least 3 students using an array of objects.

---

Problem 2: Bank Account System
Objective: Simulate a basic bank account management system.

Requirements:
1. Create a base class `BankAccount` with attributes:
   - `accountNumber` (integer)
   - `accountHolderName` (string)
   - `balance` (float)
2. Add methods:
   - `deposit(amount)` to add money to the balance.
   - `withdraw(amount)` to deduct money (ensure balance does not go negative).
   - `displayBalance()` to show the current balance.
3. Create a derived class `SavingsAccount` that:
   - Adds an attribute `interestRate` (float).
   - Includes a method `addInterest()` to increase the balance based on the interest rate.
4. Create objects for both classes and demonstrate their functionality.

---

Problem 3: Shape Hierarchy
Objective: Implement a shape hierarchy using inheritance.

Requirements:
1. Create a base class `Shape` with attributes:
   - `name` (string)
2. Add a pure virtual method `area()` in the `Shape` class.
3. Create derived classes `Rectangle` and `Circle`:
   - `Rectangle` has attributes `length` and `width`.
   - `Circle` has an attribute `radius`.
   - Implement the `area()` method in both classes.
4. Write a program to calculate and display the areas of a rectangle and a circle.

*/
