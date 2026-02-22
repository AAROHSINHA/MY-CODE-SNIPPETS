#include <iostream>
using namespace std;

void reverseArray(int* arr, int length);
int secondLargest(int* arr, int length);
bool checkPalindrome(string str);

int main(){
    int arr[5] = {1, 2, 3, 4, 5};
    for(int num : arr) cout << num << " ";
    cout << endl;
    reverseArray(arr, 5);
    for(int num : arr) cout << num << " ";
    cout << endl;

    return 0;
}

// Q1. Reverse an array in-place
// Given an array of integers, reverse the array without using extra space.
// Example: [1, 2, 3, 4, 5] → [5, 4, 3, 2, 1]
// Write a function that takes the array and its size.
void reverseArray(int* arr, int length){
    int low = 0;
    int high = length - 1;
    while(high >= low){
        int temp = arr[low];
        arr[low] = arr[high];
        arr[high] = temp;
        low++;
        high--;
    }
}


// Q2. Find the second largest element in an array
// Given an array of integers, find the second largest distinct element.
// If it does not exist, return -1.
// Example: [10, 5, 20, 20, 8] → 10
// Write a function that returns the answer.


// Q3. Check if a string is a palindrome
// Given a string, check whether it is a palindrome (same forwards and backwards).
// Ignore case.
// Example: "Level" → true, "hello" → false
