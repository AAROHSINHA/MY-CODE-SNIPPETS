#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <cmath>
#include <algorithm>
using namespace std;

/*
PROBLEM 1 -->
Given an array of N integers. The task is to find the first element that occurs K number of times. If no element
Occurs K times print -1. If multiple numbers, present, find the number whose index is lesser.
I/ P - 
7 2
1 7 4 3 4 8 7
O/P - 7
*/
/*
METHOD 1 - USE Hashmap
Time complexity - O(N)
SPace COmplexity - O(2M)
*/
int occursKTimes(vector<int> vec, int k){
    unordered_map<int, int> hashmap_freq; // for frequency
    unordered_map<int, int> hashmap_index; // for index
    for(int i = 0; i < vec.size(); i++){
        hashmap_freq[vec[i]]++;
        if(hashmap_index.find(vec[i]) == hashmap_index.end()){
            hashmap_index[vec[i]] = i;
        }
    }

    int minIndex = -1;
    int number_at_that_index = -1;
    for(auto val : hashmap_freq){
        if(val.second == k){
            if(minIndex==-1 || minIndex > hashmap_index[val.first]){
                minIndex = hashmap_index[val.first];
                number_at_that_index = val.first;
            }
        }
    }
    return number_at_that_index;

}
/*
TO Improve the space compleity we can do something like use a pair in hashmap which contains
the index and the element and frequency.
*/

/*
PROBLEM STATEMENT 2 -->
Given an array A[] of size N and an integer K. Your task is to complete the function countDistinct() which prints
the count of distinct numbers in all windows of size K in an array

eg - 
I.P - 
K = 4
1 2 1 3 4 2 3
O/P - 3 4 4 3
*/

/*
METHOD 1 BRUTE FORCE.Hashmap for all windows
*/
int distinct(vector<int> nums, int low, int high){
    set<int> hashSet;
    for(int i = low; i < high; i+=1){
        hashSet.insert(nums[i]);
    }
    return hashSet.size();
}

vector<int> countDistinct(vector<int> nums, int K){
    vector<int> counts;
    int k = K;
    for(int i = 0; i < nums.size(); i+=1){
        if(k > nums.size()) break;
        counts.push_back(distinct(nums, i, k));
        k+=1;
    }
    return counts;
}

/*
METHOD 2 - Hashmap
*/

/*
PROBLEM STATEMENT 3 -->
Given an array of names (consisting of lowercase characters) of candidates in an election
A candidate name in array represents a vote casted to the candidate. Print the name of candidate
that recievec max votes. If their is a tie print the lexographically smalelr name

eg - 
andy blake clark
O.P - 1
*/

/*
ALGORITHM - 
1. Store frequencies of each in an hashmap
2. Then iterate the hashmap for max frequency
3. Then store those frequencies elements in an array
4. If one element return it else sort the array (it sorts in lexographical order) and get the first element
*/
int candidateWins(vector<string> names){
    unordered_map<string, int> hashmap;
    for(string name : names){
        hashmap[name]+=1;
    }
    int max_freq = 0;
    for(auto val : hashmap) max_freq = max(max_freq, val.second);
    vector<string> namesVec;
    for(auto val : hashmap){
        if(val.second == max_freq) namesVec.push_back(val.first);
    }
    sort(namesVec.begin(), namesVec.end());
    string name = namesVec[0];
    for(int i = 0; i < names.size(); i+=1){
        if(names[i] == name) return ++i;
    }
    return -1;
}

/*
PROBLEM STATEMENT 3 -->
Alice is fan of mathematics subject and he need help of you to solve the problem.
He has given an number N and two number a and b. He is asked to find how many unique multiples of a and b (including a and b) lie upto N (including N).
*/

/*
=> One method to do this is to use a hasSet or map and store the multiples of a and b and save them.
But this is not optimal for numbers like N = 10^6. Basically if we put our brain to more work, we can see that

if multiples of a = A
   multiples of b = B
then -> unique multiples = A + B - N/lcm(a, b)
This is a big brain move 
*/

/*
=> USEFUL METHOD FOR LCM
--> LCM . HCF = A . B
so, LCM = A.B/LCM
and calculating HCF is easy, basically memorize the recursive function
*/
long long hcf(int a, int b){
    if(b == 0){
        return a;
    }
    return hcf(a, a%b);
}
long long lcm(int hcf, int a, int b){
    return (a*b)/hcf;
}
int commonUniqueMultiples(int a, int b, int N){
    int am = floor(N/a);
    int bm = floor(N/b);
    int lm = floor(N/lcm(hcf(a, b), a, b));
    return am + bm - lm;
}

int main(){
    vector<string> vec = {"Andy", "Blake", "Clarke"};
    std::cout << candidateWins(vec);
    return 0;
}