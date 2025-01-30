#include <iostream>
#include <vector>
#include <unordered_map>


/*
PROBLEM STATEMENT 1 -->
Given 2 arrays of size m and n of distinct elements. Given a value x. The problem is to count
all pairss from both the arrays whose sum is equal to x.
eg - 
input - 4, 4 
1 3 5 7
2 3 5 8
O/P - 2
*/

/*
METHOD 1 (Rough Method)
1. Add all elements in just one vector
2. Then do the two sum with hashmap approach and increase count on condition

T.C - O(3N)
S.C - O(2N)
*/
int CountPairs1(std::vector<int> vec1, std::vector<int> vec2, int target){
    std::vector<int> mainVec;
    for(int x : vec1) mainVec.push_back(x);
    for(int x : vec2) mainVec.push_back(x);
    std::unordered_map<int, int> hashmap;
    int pairCount = 0;
    for(int i = 0; i < mainVec.size(); i++){
        int required = target - mainVec[i];
        if(hashmap[required] > 0){
            pairCount+=hashmap[required];
        }
        hashmap[mainVec[i]]++;
    }
    return pairCount;
}


/*
PROBLEM STATEMENT 2 -->
Given an array arr[] of positive integers. Find the length of the longest sub-sequence such that elements in the subsequence are consecutive integers.

eg - 
2 6 1 9 4 5 3
O.P - 6
*/

/*
METHOD 1 -- 
We can use sorting but this is another method....Using a hashmap
We will store each element in hashmap. And then iterate arr it. For current element, if curr - 1 is present, check for curr+1, curr+2...
and so find a chain
*/
int longestSubsequence1(std::vector<int> vec){
    std::unordered_map<int, int> hashmap;
    for(int a : vec) hashmap[a]+=1;
    int maxLength = 0;
    for(int i = 0; i < vec.size(); i+=1){
        if(hashmap[vec[i] - 1] > 0){
            int length = 2;
            int num = vec[i];
            while(hashmap[num + 1] > 0){
                length++;
                num++;
            }
        maxLength = (maxLength > length) ? maxLength : length;
        }
        
    }
    return maxLength;
}

/*
PROBLEM STATEMENT 3 -->
Given an array which contains all elements occurring k times, but only one occurs 1 time. Find that unique element

eg - 
n = 7 k = 3
6 2 5 2 2 6 6
O/P - 5
*/

/*
METHOD 1 -- Sorting (Just to revise sorting)
T.C - O(Nsquare + m)
S.C = O(1)
*/
void BubbleSort(std::vector<int> &vec){
    for(int i = 0; i < vec.size() - 1; i+=1){
        for(int j = 0; j <  vec.size() - 1 - i; j+=1){
            if(vec[j] > vec[j+1]){
                int temp = vec[j+1];
                vec[j+1] = vec[j];
                vec[j] = temp;
            }
        }
    }
}

int UniqueElement1(std::vector<int> vec){
    BubbleSort(vec);
    for(int i = 1; i < vec.size() - 1; i+=1){
        if(vec[i]!=vec[i-1] && vec[i]!=vec[i+1]){
            return vec[i];
        }
    }
    return -1;
}
/*
METHOD 2 -- Hashmap Method
Count the frequency of each element and then search which is 1

Time Complexity - O(N)
Space Complexity - O(N)
*/
int UniqueElement2(std::vector<int> vec){
    std::unordered_map<int, int> hashmap;
    for(int v : vec) hashmap[v]+=1;
    for(auto val : hashmap){
        if(val.second == 1) return val.first;
    }
    return -1;
}

/*
PROBLEM STATEMENT 4 -->
Given an array A[] of N positive integers, where each integer ranges from 1 to N. Some elements might be repeated, while others might be missing from the array. Your task is to count the frequency of each integer from 1 to N.
Note: expected time complexity o(n) with space complexity - o(1)

eg - 
n = 5
2 3 2 3 5
0/P - 0 2 2 0 1
*/

/*
Method 1 - good old hashmap :)
<=> BUT THIS TAKES O(N) Space which we really want to avoid
*/
std::vector<int> ArrangeFrequency1(std::vector<int> vec, int N){
    std::unordered_map<int, int> hashmap;
    for(int a : vec) hashmap[a]++;
    std::vector<int> ans;
    for(int i = 1; i<=N; i+=1){
        ans.push_back(hashmap[i]);
    }
    return ans;
}

/*
Method 2 
Even though the below solution doesnot have hashmap but due to the vector the space is again O(N) not O(1)
The time is optimal O(N)
*/
std::vector<int> ArrangeFrequency2(std::vector<int> vec, int N){
    std::vector<int> ans(N, 0);
    for(int i = 0; i < vec.size(); i++){
        ans[vec[i] - 1] += 1;
    }
    return ans;
}

/*
Method 3
Again O(N) Space complexity
*/
void ArrangeFrequency3(std::vector<int>& vec, int N){
    for(int i = 0; i < N; i+=1){
        vec.push_back(0);
    }
    /*
    initial vector - [2, 3, 2, 3, 5]
    final vector - [2, 3, 2, 3, 4, 0, 0, 0, 0, 0].
    In these 0s we need to update the frequencies like hashmap then return the second half
    */
    for(int i = 0; i < N; i+=1){
        vec[vec[i] + N - 1]+=1;
    }
    // return std::vector<int>(vec.begin() + N, vec.begin() + 2*N);
    vec.erase(vec.begin(), vec.begin() + N);
}

/*
Method 4 -- 
Inplace updation of frequency
*/
void ArrangeFrequency4(std::vector<int>& vec, int N) {
    // Traverse through the array and mark frequencies
    for (int i = 0; i < N; i++) {
        // Take absolute value to handle negative marks
        int index = abs(vec[i]) - 1; // Map the number to the correct index
        vec[index] = -abs(vec[index]);  // Mark the frequency by flipping the sign
    }

    // Now count frequencies by checking negative markings
    for (int i = 0; i < N; i++) {
        vec[i] = -vec[i];  // Restore and count the frequency
    }
}

/*
PROBLEM STATEMENT 5 -->
Given an array of n integers. Count the total number of subarray having total distinct elements same as that of total distinct elements of the original array

eg - 5
2 1 3 2 3
O/P - 5
*/



int main(){
    std::vector<int> vec = {2, 3, 2, 3, 5};
    ArrangeFrequency3(vec, 5);
    for(int a : vec) std::cout << a << " ";

    std::cout << '\n';
    return 0;

}