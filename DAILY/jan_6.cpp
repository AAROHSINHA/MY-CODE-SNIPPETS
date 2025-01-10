#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

/*
PROBLEM STATEMENT 1 - 
Take as input N the size of an array. Take N more inputs and store that in an array. Take as input a number M
Write a recursive function which returns the last index at which M is found in the array and -1 if M is not found
anywhere. Print the value returned

eg - 
N = 7
[86 -16 77 65 45 77 28]
M = 77
*/

int getLastIndex(int* arr, int N, int M){
    if(N == 0){
        return -1;
    }
    if(arr[N - 1] == M){
        return N;
    }
    return getLastIndex(arr, N-1, M);
}

/*
PROBLEM STATEMENT 2 - 
Given a set of distinct integers nums. Return all possible subsets (the power set)/

eg - 
nums = [1, 2, 3]
output - [
[1], [2], [3], [1, 2], [2, 3], [1, 3], [1, 2, 3], []
]
*/
void getSubsets(std::vector<int> nums){
    
}

/*
PROBLEM STATEMENT 3 - 
Take following as input
A number (N1)
A number (N2)
Write a function which returns the LCM of N1 and N2. Ptint the value

eg - 4, 6 ---> 12
*/
// Method 1 - hashmap
int findLCM(int num1, int num2){
    std::unordered_map<int, int> hashmap;
    while(num1 > 1){
        for(int i = 2; i <= num1; i+=1){
            if(num1%i == 0){
                hashmap[i]+=1;
                num1/=i;
                break;
            }
        }
    }
    while(num2 > 1){
        for(int i = 2; i <= num2; i+=1){
            if(num2%i == 0){
                hashmap[i]+=1;
                num2/=i;
                break;
            }
        }
    }


    int lcm = 1;
    for(auto val : hashmap){
          std::cout << val.first << " " << val.second << '\n';
        if(val.second%2==0){
            lcm *= (val.first * val.second);
        }else{
            if(val.second > 1){
                lcm *= (val.first * (val.second - 1));
            }else{
                lcm *= val.first;
            }
        }
    }
return lcm;
}

int LCM(int a, int b)
{
    int greater = std::max(a, b);
    int smallest = std::min(a, b);
    for (int i = greater; ; i += greater) {
        if (i % smallest  == 0)
            return i;
    }
}

int main(){
    std::cout << "Hello WOrld" << std::endl;
     std::cout << LCM(8, 12) << std::endl;
         std::cout << "Hello WOrld" << std::endl;
    /*
    For problem 1 - 
    int N;
    std::cout << "Enter the number of elements - ";
    std::cin >> N;
    
    int* arr = new int[N];
    for(int i = 0; i < N; i+=1){
        int num;
        std::cout << "Enter number of insert - ";
        std::cin >> num;
        arr[i] = num;
    }

    int M;
    std::cout << "Enter number to search - ";
    std::cin >> M;
    std::cout << "Output - "<< getLastIndex(arr, N, M) << std::endl;

    delete[] arr;
    */
    return 0;
}