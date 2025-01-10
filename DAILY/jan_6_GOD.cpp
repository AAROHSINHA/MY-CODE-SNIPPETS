#include <iostream>

/*
Problem: Recurrence Relation Calculation

    You are given a recurrence relation defined as follows:

    f(n) = n * f(n-1) - (n-1) * f(n-2) + (n-2) * 3

    The function should compute the value of f(n) for a given n. 

    Your task is to write a function that computes f(n) based on this recurrence relation.

    Base Cases:
    - f(0) = 0
    - f(1) = 1
    - f(2) = 1
*/

int RecurrenceRelation(int n){
    if(n == 1 || n == 2) return 1;
    return n*RecurrenceRelation(n - 1) - (n - 1)*RecurrenceRelation(n - 2) + (n - 2)*3;
}

int main(){
    std::cout << RecurrenceRelation(5) << std::endl;
    return 0;
}