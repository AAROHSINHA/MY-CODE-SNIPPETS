#include <iostream>
#include <vector>
#include <unordered_map>

/*
PROBLEM STATEMENT 1 -->
Write - 
1. Bubble Sort
2. Insertion Sort
3. Selection Sort
*/

/*
Bubble sort - keep on swapping adjacent min and max elements in nested loops

Loop 1 - (n - 1) iterations
Loop 2 - (n - 2) iterations
Loop 3 - (n - 3) iteratins
.
.
.
so overall...n + (n - 1) + (n - 2) + .... 1 = n(n-1)/2 = n2
T.C - O(N2)
*/
void BubbleSort(std::vector<int>& vec){
    for(int i = 0; i < vec.size() - 1; i+=1){
        for(int j = 0; j < vec.size() - 1 - i; j+=1){
            if(vec[j] > vec[j+1]){
                int temp = vec[j+1];
                vec[j+1] = vec[j];
                vec[j] = temp;
            }
        }
    }
}

/*
Selection Sort - 
-> Search the current array for minimum element. place it at the 0th index.
Now 0th index has the extreme min element, consider starting from index 1 (as index 0 has its desired element),
now find the minimumest element and place at index 1. Then start at index 2 and so on...
*/
void SelectionSort(std::vector<int>& vec){
    for(int i = 0; i < vec.size(); i+=1){
        int min_elem = vec[i];
        int minIndex = i;
        for(int j = i; j < vec.size(); j+=1){
            if(min_elem > vec[j]){
                min_elem = vec[j];
                minIndex = j;
            }
        }
        // swap
        int temp = vec[i];
        vec[i] = vec[minIndex];
        vec[minIndex] = temp;
    }
}

/*
INSERTION SORT --
1. The first element in the array is assumed to be sorted. Take the second element and store it separately in key.
Compare key with the first element. If the first element is greater than key, then key is placed in front of the first element.
2. Now, the first two elements are sorted.
Take the third element and compare it with the elements on the left of it. Placed it just behind the element smaller than it. If there is no element smaller than it, then place it at the beginning of the array.
*/
void InsertionSort(std::vector<int>& vec) {
    for (int i = 1; i < vec.size(); i++) {
        int currNum = vec[i];
        int j = i - 1;

        // Shift elements of vec[0..i-1] that are greater than currNum
        while (j >= 0 && vec[j] > currNum) {
            vec[j + 1] = vec[j];
            j--;
        }

        // Place currNum in its correct position
        vec[j + 1] = currNum;
    }
}

/*
PROBLEM STATEMENT 2 --
Given an array f positive integers where all numbers occur even number of times except one number which occurs odd number of times. Find the number.

eg - 
size = 5
8 4 4 8 23
O.P - 23
*/

/*
METHOD 1 - Hashmap
*/
int OddFrequency(std::vector<int> vec){
    std::unordered_map<int, int> hashmap;
    for(int v : vec) hashmap[v]+=1;
    // now iterate the hashmap
    for(auto val : hashmap){
        if(val.second%2!=0){
            return val.first;
        }
    }
    return -1;
}

/*
PROBLEM STATEMENT 3 -- 
Youa re given an array A of size N. You need to print the total count of sub-arrays having their sum equal to 0.

eg - 
0 0 5 5 0 0 
O.P - 6
*/




int main(){
    std::vector<int> v = {1, 1, 1, 2, 1, 2, 4, 3, 4, 4, 3};
    std::cout << OddFrequency(v);

    return 0;
}