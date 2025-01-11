#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <climits>
using namespace std;

/*
PROBLEM STATEMENT 1 --> 
Given an array of n integers, find the sum of f(a[i], a[j]) of all pairs (i, j) such that  (1 <= i, j <=n)
f(a[i], a[j]) : 
If |a[j] - a[i]| > 1 : a[j] - a[i]
Else If |a[j] - a[i]| <= 1 : 0

eg - {6 6 4 4}
O/P - -8
*/
int getSumCountIteratively(std::vector<int> vec){
    int sum = 0;
    for(int i = 0; i < vec.size(); i+=1){
        for(int j = i+1; j < vec.size(); j+=1){
            if(std::abs(vec[j] - vec[i]) > 1){
                sum += (vec[j] - vec[i]);
            }
        }
    }
    return sum;
}

int getSumRecursively(std::vector<int> vec, int i, int j, int sum) {
    if (i >= vec.size()) {
        return sum; 
    }
    if (j >= vec.size()) {
        return getSumRecursively(vec, i + 1, i + 2, sum); 
    }
    if (std::abs(vec[j] - vec[i]) > 1) {
        sum += vec[j] - vec[i];
    }

    return getSumRecursively(vec, i, j + 1, sum);
}

/*
PROBLEM STATEMENT 2 --> 
Given a string str and another string patt. Find the character in patt that is present at minimum index in str. If no 
character of patt is present in str then print 'No character present'

eg - 
str = "geeksforgeeks"
patt = "set"

Characters of patt are s, e, and t.
e is the first character of patt that appears in str at index 1 (0-based).
Hence, the output is e.
O/P - e
*/

// SPACE COMPELXITY - O(N)
// TIME COMPLEXITY - O(N + m)
char firstOccurring1(string str, string patt){
    std::unordered_map<char, int> hashmap;
    for(char x : patt){
        hashmap[x] += 1;
    }
    for(char s : str){
        if(hashmap[s] > 0){
            return s;
        }
    }
    return '_';
}

// Time complexity - O(N*M), worst case - O(Nsquare)
char firstOccurring2(string str, string patt){
    for(char s : str){
        if(patt.find(s) != std::string::npos){
            return s;
        }
    }
    return '_';
}

// Using set
char firstOccurring3(string str, string patt){
    std::unordered_set<char> charSet(patt.begin(), patt.end());
    for(char s : str){
        if(charSet.find(s) != charSet.end()){
            return s;
        }
    }
    return '_';
}

/*
PROBLEM STATEMENT 3 -
Given an array with positive number, the task ti fnd the largest subsequence from array that contain elements
which are fibonacci numbers
*/

// Algorithm 1
/*
1. Find the max of the array
2. store the fibbonaci numbers in hashmap/hashset till the max
3. check if it is present in the array

TIME COMPLEXITY - O(N + m + N) --> O(N)
SPACE COMPLEXITY - O(N)
*/
vector<int> getFibonacci1(vector<int> fibonacci){
    // finding the max
    int max = INT_MIN;
    for(int x : fibonacci) max = std::max(max, x);

    int fib1 = 0;
    int fib2 = 1;
    std::unordered_set<int> fibSet = {0, 1};
    while(fib2 <= max && fib1 <= max){
        int curr = fib1 + fib2;
        fib1 = fib2;
        fib2 = curr;
        fibSet.insert(curr);
    }

    // finding
    vector<int> finalAns;
    for(int nums : fibonacci){
        if(fibSet.find(nums)!=fibSet.end()){
            finalAns.push_back(nums);
        }
    }
    return finalAns;
}

// ALGORITHM 2
/*
Fibonacci Numbers follow the property, they satisfy the condition -
5x2 + 4
5x2 - 4

SPACE COMPLEXITY = O(1)
TIME COMPLEXITY = O(N*logk)
note that std::sqrt operation takes logk time
*/
bool perfectSquare(int num){
    int sq = std::sqrt(num);
    return sq*sq == num;
}
vector<int> getFibonacci2(vector<int> fibonacci){
    vector<int> finalAns;
    for(int nums : fibonacci){
        int a1 = 5 * (nums*nums) + 4;
        int a2 = 5 * (nums*nums) - 4;
        if(perfectSquare(a1) || perfectSquare(a2)){
            finalAns.push_back(nums);
        }
    }
    return finalAns;
}


int main(){
    std::vector<int> vec = {1, 4, 3, 9, 10, 13, 7};
    std::vector<int> ans = getFibonacci2(vec);
    for(int a : ans){
        std::cout << a << " ";
    }
    std::cout << std::endl;
    return 0;
}