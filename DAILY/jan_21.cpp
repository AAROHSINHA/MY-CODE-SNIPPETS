#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

std::vector<int> sortedByFrequency(std::vector<int> vec) {
    // Step 1: Count frequencies using a hashmap
    std::unordered_map<int, int> hashmap;
    for (int num : vec) {
        hashmap[num]++;
    }

    // Step 2: Copy unique elements into a vector
    std::vector<int> uniqueElements;
    for (const auto& val : hashmap) {
        uniqueElements.push_back(val.first);
    }

    // Step 3: Sort unique elements by frequency, then value
    std::sort(uniqueElements.begin(), uniqueElements.end(), [&](int a, int b) {
        if (hashmap[a] == hashmap[b]) {
            return a < b; // If frequencies are equal, smaller number comes first
        }
        return hashmap[a] > hashmap[b]; // Otherwise, sort by frequency (descending)
    });

    // Step 4: Build the result array
    std::vector<int> finalAns;
    finalAns.reserve(vec.size()); // Reserve space for all elements
    for (const auto& num : uniqueElements) {
        finalAns.insert(finalAns.end(), hashmap[num], num); // Append 'num' hashmap[num] times
    }

    return finalAns;
}

/*
PROBLEM STATEMENT 2 -->
Given two arrays A and B of equal size N,, the task is to find if the given arrays are equal or not.
Two arrays are equal or not. Two arrays are said to be equal if both of them contains same set of element.
Arrangement of the elements may be diffrent though.

I/P - 
1 2 4 5 0
2 4 5 0 1

O/P - 1
*/
bool equalArrays(vector<int> arr1, vector<int> arr2){
    unordered_map<int, int> hashmap;
    for(int a1 : arr1) hashmap[a1]+=1;
    for(int a2 : arr2){
        hashmap[a2]-=1;
    }
    for(auto val : hashmap){
        if(val.second!=0){
            return false;
        }
    }
    return true;
}

/*
PROBLEM STATEMENT 3 -->
Given 2 arrays : arr1[0...m-1] of size m and arr2:[0....n-1] of size n. Task is to check whether arr2[] is a subset
of arr1[] or not. Both the arrays can be unsorted or sorted. It may be assumed elements in arrays are distinct
and do not repeat.

I/P - 
11 1 13 21 3 7
11 3 7 1
O/P - Yes
*/
string isSubset(vector<int> arr1, vector<int> arr2){
    unordered_map<int, int> hashmap1;
    for(int a : arr1) hashmap1[a]++;
    for(int b : arr2){
        if(hashmap1[b] == 0){
            return "NO";
        }
    }
    return "YES";
}

/*
PROBLEM STATEMENT 4 -->
Given an array having both positive and negetive integers. The task is to complete the function maxLen() 
which returns the length of maximum Subarray with 0 sum. The function takes two arguments. an array and n 
where n is the size of the array

I/P - 
8
15 -2 2 -8 1 7 10 23
O/P - 5
*/

/*
Method 1 - Naive Approach the brute force method
TIME COMPLEXITY - O(N)
SPACE COMPLEXITY - O(1)
*/
int maxLen1(vector<int> vec){
    int maxLen = 0;
    for(int i = 0; i < vec.size() - 1; i+=1){
        int sum = 0;
        for(int j = i; j < vec.size(); j+=1){
            sum += vec[j];
            if(sum == 0){
                maxLen = max(maxLen, j - i + 1);
            }else if(sum > 0){
                break;
            }
        }
    }
    return maxLen;
}

/*
METHOD 2 - PREFIX SUM AND HASHMAP
EXPLANATION - (Give a moment to think about)
The idea is based on the observation that for two different indices i and j (where j > i) if the prefix sums Si and Sj are equal, it means that the sum of the elements between indices i+1 and j is zero. This is because:


Sj – Si = arr[i+1] + arr[i+2] + …… + arr[j]
If Si = Sj, then: Sj – Si = 0
This means the subarray from i+1 to j has a sum of zero.


Illustration:


Consider the array arr = {5, 2, -1, 1, 4}. Calculate the prefix sums:


S0 = 5
S1 = 5 + 2 = 7
S2 = 5 + 2 – 1 = 6
S3 = 5 + 2 – 1 + 1 = 7
Here, S1 = S3 = 7. This equality tells us that the subarray from index 2 to 3 (subarray [-1, 1]) sums to zero.
*/
int maxLen2(vector<int> vec) {
    vector<int> prefixSum = {vec[0]};
    for (int i = 1; i < vec.size(); i++) {
        prefixSum.push_back(prefixSum[i - 1] + vec[i]);
    }

    unordered_map<int, int> hashmap; // To store prefixSum and its first occurrence index
    int maxLen = 0;

    for (int i = 0; i < prefixSum.size(); i++) {
        if (prefixSum[i] == 0) {
            // Special case: If prefix sum itself is 0, the subarray from 0 to i has sum 0
            maxLen = max(maxLen, i + 1);
        } else if (hashmap.find(prefixSum[i]) != hashmap.end()) {
            // If prefixSum[i] is already seen, calculate the length of the subarray
            maxLen = max(maxLen, i - hashmap[prefixSum[i]]);
        } else {
            // Otherwise, store the prefix sum and its index
            hashmap[prefixSum[i]] = i;
        }
    }

    return maxLen;
}


int main(){
    vector<int> vec = {15, -2, 2, -8 , 1, 7, 10, 23};
    std::cout << maxLen2(vec) << '\n';
    return 0;
}
