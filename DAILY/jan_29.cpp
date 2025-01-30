#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

/*
PROBLEM STATEMENT 1 -->
Given a string S. Check if the given string can be rearranged to form palindrome.

I.P - geeksforgeeks
O/P - yes
*/

/*
BASIC ALGORITHM 1 ->
1. for each even length string to be a palindrome, all characters must be in even frequency
2. for each odd length string to be a palindrome, all characters must be in even freq and only one character can be in odd freq
*/
bool canFormPalindrome(string str){
    unordered_map<char, int> hashmap;
    for(char s : str){
        hashmap[s]+=1;
    }
    int even = 0;
    int odd = 0;

    for(auto val : hashmap){
        if(val.second%2==0) even++;
        else odd++;
    }

    if(str.length()%2==1){
        return odd == 1;
    }else{
        return odd == 0;
    }
}


/*
PROBLEM STATEMENT 2 -->
Given an array A of size N and integer K. Your task is to complete a function countDistinct()
which prints the count of distinct numbers in windows of size K

I/P ->
k = 4
1 2 1 3 4 2 3
O.P - 3 4 4 3
*/
/*
METHOD 1 --> Brute Force Method
*/
int DistinctCount(vector<int> vec, int i , int j){
    unordered_map<int, int> hashmap;
    for(i; i<j; i++){
        hashmap[vec[i]]++;
    }
    return hashmap.size();
}
vector<int> countDistinct1(vector<int> vec, int k){
    int N = vec.size() - k;
    vector<int> ans;
    for(int i = 0; i <= N; i+=1){
       ans.push_back(DistinctCount(vec, i, i+k));
    }
    return ans;
}

/*
METHOD 2 - A more optimal one. 
We can first make a hashmap containing first k elements freq. By this we get distict element.
Every iteration, subtract 1 from the first elmeent of k sized subarray and add 1 to the next elementand get size
*/
vector<int> countDistinct2(vector<int> vec, int k){
    vector<int> arr;
    if(k > vec.size()) return arr;
    unordered_map<int, int> hashmap;
    // filling the first k subarray
    for(int i = 0; i < k; i++){
        hashmap[vec[i]]+=1;
    }
    arr.push_back(hashmap.size());
    int low = 1;
    int high = k;
    while(high < vec.size() && low < vec.size()){
        hashmap[vec[low-1]]-=1;
        if(hashmap[vec[low - 1]] == 0){
            hashmap.erase(vec[low - 1]);
        }
        hashmap[vec[high]]+=1;
        arr.push_back(hashmap.size());
        low++;
        high++;
    }
    return arr;
}



/*
PROBLEMS STATEMENT 3 -->
Given an array of size N. The task is to find the first repeating elements in an array of integers
i.e an element that occurs more than once and whose index of first occurance is smallest

I/P - 1 5 3 4 3 5 6
O/P - 2
*/

/*
METHOD 1 --> Use a hashmap
*/
int smallestIndexRepeating(vector<int> vec){
    unordered_map<int, int> hashmap;
    int num = -1;
    for(int i = 0; i < vec.size(); i++){
        if(hashmap[vec[i]] == 1){
            num = vec[i];
            break;
        }
        hashmap[vec[i]]++;
    }
    
    for(int i = 0; i < vec.size(); i+=1){
        if(vec[i] == num) return i;
    }
    return -1;
}

/*
PROBLEM STATEMENT 4 -->
Given an array A of integers. The task is to complete the function which returns an integer denoting
the length of the longest subsequence such that elements in the subsequence are consecutive integers, the consecutive
numbers can be in any order.

I/P - 1 9 3 10 4 20 2
O/P - 4
*/

/*
Method 1 - SORT AND GET
*/
int longestConsecutiveSubsequece1(vector<int> vec){
    sort(vec.begin(), vec.end());
    int longCount = 0;
    int currCount = 0;
    for(int i = 1; i < vec.size(); i+=1){
        if(vec[i] - vec[i-1] == 1){
            currCount++;
        }else{
            longCount = max(currCount, longCount);
            currCount = 0;
        }
    }
    return ++longCount;
}

int main(){
    vector<int> vect = {1, 4, 10, 20, 3, 7, 2};
    std::cout << longestConsecutiveSubsequece1(vect);
    std::cout << '\n';
    return 0;
}