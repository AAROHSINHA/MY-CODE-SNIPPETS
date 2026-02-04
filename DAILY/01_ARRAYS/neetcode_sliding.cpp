#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <map>
using namespace std;

int maxProfit(vector<int>& prices) {
    int minVal = prices[0];
    int profitMax = 0;
    for(int i = 0; i < prices.size(); i+=1){
        profitMax = max(prices[i] - minVal, profitMax);
        if(prices[i] < minVal) minVal = prices[i];
    }
    return profitMax;
}

int lengthOfLongestSubstring(string s) {
    int maxLength = 0;
    unordered_map<char, int> hashmap;
    int start = 0;
    int end = 0;
    while(end < s.length() && start < s.length()){
        if(hashmap.find(s[end]) == hashmap.end()){
            maxLength = max(maxLength, end - start + 1);
            hashmap[s[end]] = end;
            end++;
        }else{
            int temp = hashmap[s[end]];
            for(int i = start; i <= temp; i++){
                hashmap.erase(s[i]);
            }
            start = temp + 1;
        }
    }        
    return maxLength;
}

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int> res;
    map<int, int> hashmap;
    int i = 0;
    int j = 0;
    while(j < k){
        hashmap[nums[j]]++;
        j++;
    }
    res.push_back(prev(hashmap.end())->first);
    while(j < nums.size() && i < nums.size()){
        // first insert and erase
        auto it = prev(hashmap.end());   // valid element
        int key = it->first;
        res.push_back(key);
        hashmap[nums[i]]-=1;
        if(hashmap[nums[i]] == 0) hashmap.erase(nums[i]);
        // now update
        i++;
        j++;
        hashmap[nums[j]]++;
    }
    return res;
}
bool checkInclusion(string s1, string s2) {
    if (s1.size() > s2.size()) return false;

    map<char, int> hashmap1, hashmap2;
    for (int i = 0; i < s1.size(); i++) {
        hashmap1[s1[i]]++;
        hashmap2[s2[i]]++;
    }

    if (hashmap1 == hashmap2) return true;

    int ptr1 = 0, ptr2 = s1.size();
    while (ptr2 < s2.size()) {
        hashmap2[s2[ptr2]]++;
        hashmap2[s2[ptr1]]--;
        if (hashmap2[s2[ptr1]] == 0)
            hashmap2.erase(s2[ptr1]);

        ptr1++;
        ptr2++;

        if (hashmap1 == hashmap2) return true;
    }

    return false;
}


int main(){
    string s1 = "abc";
    string s2 = "lecabee";
    cout << checkInclusion(s1, s2) << "\n";
    return 0;
}