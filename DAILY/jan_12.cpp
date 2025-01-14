#include <iostream>
#include <map>
#include <vector>
#include <utility>
#include <algorithm>
#include <unordered_map>
#include <set> 
#include <stack>
#include <queue>
using std::string, std::stack, std::queue;

/*
PROBLEM STATEMENT 1 -->
Find the uncommon characters of the two given strings S1 and S2. Here uncommon characters mean thast either the character is present in one string or it is present in the other string but not in both. The string contains only lowercase characters and can contain duplicates

eg - 
input = 
characters
alphabets
O/P - bclpr
*/

/*
METHOD 1 - 
Time Complexity - O((n + m)*logm)
Space Complexity - O(m)
*/
std::string UncommonString1(std::string str1, std::string str2) {
    std::map<char, std::vector<bool>> hashmap;
    int ptr1 = 0;
    int ptr2 = 0;

    while (ptr1 < str1.length() || ptr2 < str2.length()) {
        if (ptr1 < str1.length()) {
            // Ensure the vector is initialized with size 2
            if (hashmap.find(str1[ptr1]) == hashmap.end()) {
                hashmap[str1[ptr1]] = {false, false};
            }
            hashmap[str1[ptr1]][0] = true;
            ptr1++;
        }
        if (ptr2 < str2.length()) {
            // Ensure the vector is initialized with size 2
            if (hashmap.find(str2[ptr2]) == hashmap.end()) {
                hashmap[str2[ptr2]] = {false, false};
            }
            hashmap[str2[ptr2]][1] = true;
            ptr2++;
        }
    }

    std::string myAns = "";
    for (auto val : hashmap) {
        if (val.second[0] != val.second[1]) {
            myAns += val.first;
        }
    }
    return myAns;
}

/*
METHOD 2
Using a hashtable. For every character, give them 1, 2, 3.
1 - appears only in string 1
2 - appears only in string 2
3 - appears in both

T.C - O(length of string1 + length of string2 + 26) ~ O(N) N - const
S.C - O(N)
*/

std::string UncommonString2(const std::string& str1, const std::string& str2) {
    // Initialize a fixed-size array for tracking character states
    std::vector<int> hashtable(26, 0);

    // Process string 1
    for (char s : str1) {
        int index = s - 'a';
        if (hashtable[index] == 0) {
            hashtable[index] = 1; // Mark as appearing in str1
        }
    }

    // Process string 2
    for (char s : str2) {
        int index = s - 'a';
        if (hashtable[index] == 0) {
            hashtable[index] = 2; // Mark as appearing in str2
        } else if (hashtable[index] == 1) {
            hashtable[index] = 3; // Mark as appearing in both
        }
    }

    // Construct the final answer string
    std::string finalAns;
    for (int i = 0; i < 26; ++i) {
        if (hashtable[i] == 1 || hashtable[i] == 2) {
            finalAns += (char)(i + 'a'); // Add the character to the result
        }
    }

    return finalAns;
}

/*
PROBLEM STATEMENT 2 ->
Given an array with repeated elements. the task is to find the maximum distance between two occurences of an element
eg - INPUT - 6
ARR - [1 1 2 2 2 1]
O/P - 5
*/

/*
METHOD 1 : 
Time Complexity : O(nsquare) --> In reality lesser than n square
Space Complexity : O(1)
*/
int maxDistanceBetween1(std::vector<int> vect){
    int currDiff = 0;
    for(int ptr1 = 0; ptr1 < vect.size() - 1; ptr1+=1){
        int ptr2 = vect.size() - 1;
        while(ptr2 > ptr1){
            if(ptr2 - ptr1 < currDiff){
                break;
            }
            if(vect[ptr1] == vect[ptr2]){
                currDiff = (ptr2 - ptr1 > currDiff) ? ptr2 - ptr1 : currDiff;
                break;
            }
            ptr2-=1;
        }
    }
    return currDiff;
}

/*
METHOD 2
Using a hashmap

Time Complexity - O(N)
Space Complexity - O(N)
*/
int maxDistanceBetween2(std::vector<int> vect){
    // We will use 1 based indexing
    std::unordered_map<int, int> hashmap;
    int maxDiff = 0;
    for(int i = 0; i < vect.size(); i+=1){
        if(hashmap[vect[i]] > 0){
            maxDiff = (i - hashmap[vect[i]] > maxDiff) ? (i - hashmap[vect[i]] + 1) : maxDiff; 
        }else{
            hashmap[vect[i]] = i+1;
        }
    }
    return maxDiff;
}

/*
Given two strings S1 and S2, find all the characters that are common between the two strings and print them with their minimum frequency (i.e., the frequency of each character in the output should be the smaller of its frequency in the two strings). The output should be sorted in lexicographical order. Both strings contain only lowercase English letters and may have duplicates.

eg - 
S1 = "geeksforgeeks"  
S2 = "practiceforgeeks"
eegkks

Example:
In S1, the character e appears 4 times.
In S2, the character e appears 2 times.
The output for e should be 2 times (the smaller count).
*/

string commonLowestFrequency(string str1, string str2) {
    std::unordered_map<char, int> hashmap1;
    std::unordered_map<char, int> hashmap2;
    std::set<char> common;

    // Count frequency of characters in str1
    for (int i = 0; i < str1.length(); i++) {
        hashmap1[str1[i]]++;
    }

    // Count frequency of characters in str2 and find common characters
    for (int i = 0; i < str2.length(); i++) {
        hashmap2[str2[i]]++;
        if (hashmap1.find(str2[i]) != hashmap1.end()) {
            common.insert(str2[i]); // Add to common set if present in both
        }
    }

    string finalStr = "";
    // Construct the result string based on the minimum frequency of common characters
    for (char x : common) {
        int times = std::min(hashmap1[x], hashmap2[x]); // Use the minimum frequency
        while (times > 0) {
            finalStr += x;
            times--;
        }
    }

    return finalStr;
}

/*
PROBLEM STATEMENT 4 ->
You are given a string s.

You can perform the following process on s any number of times:

Choose an index i in the string such that there is at least one character to the left of index i that is equal to s[i], and at least one character to the right that is also equal to s[i].
Delete the closest character to the left of index i that is equal to s[i].
Delete the closest character to the right of index i that is equal to s[i].
Return the minimum length of the final string s that you can achieve.

EG - 
Input: s = "abaacbcbb"

Output: 5

Explanation:
We do the following operations:

Choose index 2, then remove the characters at indices 0 and 3. The resulting string is s = "bacbcbb".
Choose index 3, then remove the characters at indices 0 and 5. The resulting string is s = "acbcb".
*/
int minimumLength(string s) {
    queue<char> qu1;
    queue<char> qu2;

}


int main(){
    string S1 = "geeksforgeeks";  
    string S2 = "practiceforgeeks";
    std::cout << commonLowestFrequency(S1, S2) << '\n';
    return 0;
}