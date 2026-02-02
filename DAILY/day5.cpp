#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

// 1. longest substring without repeating characters
int lengthOfLongestSubstring(string s) {
    int length = 0;
    unordered_map<char, int> freqMap;
    int maxLength = 0;
    int ptr = 0;
    for(int i = 0; i < s.length(); i+=1){
        char curr = s[i];
        if(freqMap.find(curr) == freqMap.end()){
            length+=1;
            freqMap[curr]+=1;
        }else{
            maxLength = max(length, maxLength);
            while(s[ptr]!=curr && ptr < i){
                freqMap[s[ptr]]-=1;
                if(freqMap[s[ptr]] == 0){
                    freqMap.erase(s[ptr]);
                }
                length-=1;
                ptr++;
            }
            ptr+=1;
        }
    }
    return maxLength;
}

// 2. pivot index
int pivotIndex(vector<int>& nums) {
    vector<int> prefixSum;
    vector<int> suffixSum(nums.size(), 0);
    int sSum = 0;
    int pSum = 0;
    for(int i = 0; i < nums.size(); i+=1){
        pSum += nums[i];
        prefixSum.push_back(pSum);
    }
    for(int i = nums.size() - 1; i >= 0; i-=1){
        sSum += nums[i];
        suffixSum[i] = sSum;
    }

    for(int i = 0; i < prefixSum.size(); i+=1){
        if(prefixSum[i] == suffixSum[i]) return i;
    }
    return 0;
}

// 3. Highest altitude
int largestAltitude(vector<int>& gain) {
    int currAltitude = 0;
    int highestAltitude = gain[0];
    for(int i = 0; i < gain.size(); i+=1){
        currAltitude += gain[i];
        if(currAltitude > highestAltitude) highestAltitude = currAltitude;
    }        
    return highestAltitude;
}

// subarray with sum k
int subarraySum1(vector<int>& nums, int k) {
    int answer = 0;
    for(int i = 0; i < nums.size(); i+=1){
        int subSum = 0;
        for(int j = i; j < nums.size(); j+=1){
            subSum += nums[j];
            if(subSum == k){
                answer += 1;
            }
        }
        subSum = 0;
    }
    return answer;
}
int subarraySum(vector<int>& nums, int k) {
    int answer = 0;
    vector<int> prefixSum;
    for(int num : nums){
        if(prefixSum.size() == 0) prefixSum.push_back(num);
        else prefixSum.push_back(num + prefixSum[prefixSum.size() - 1]);
    }
    unordered_map<int, int> hashMap;
    for(int i = 0; i < prefixSum.size(); i+=1){
        if(hashMap.find(prefixSum[i] - k)!=hashMap.end()){
            answer += hashMap[prefixSum[i] - k];
        }
        if(prefixSum[i] == k) answer+=1;

        hashMap[prefixSum[i]]++;
    }
    return answer;
}

// car pooling
bool carPooling(vector<vector<int>>& trips, int capacity) {
    int start = trips[0][1];
    int end = trips[0][2];
    unordered_map<int, int> stopStatus; // at any point, whether board passengers or remove them
    for(vector<int> trip : trips){
        stopStatus[trip[1]] += trip[0];
        stopStatus[-trip[2]] += trip[0];
        if(trip[1] < start) start = trip[1];
        if(trip[2] > end) end = trip[2];
    }        

    int remainingCapacity = capacity;
    for(int i = start; i < end; i+=1){
        if(stopStatus.find(i) == stopStatus.end()) continue;
        // 0. check for same to and from
        if(stopStatus.find(i)!=stopStatus.end() && stopStatus.find(-1*i)!=stopStatus.end()){
            int totalInflow = stopStatus[i] - stopStatus[-1];
            capacity += totalInflow;
            if(capacity < 0) return false;
        }
        
        // 1. check for from
        if(stopStatus.find(i)!=stopStatus.end()){
            capacity -= stopStatus[i];
            if(capacity < 0) return false;
        }
        // 2. check for to
        if(stopStatus.find(-1*i)!=stopStatus.end()){
            capacity += stopStatus[i];
        }
    }

    return true;
    
}

// minimum K
int checkCeil(vector<int>& nums, int k){
    int totalCounts = 0;
    for(int num : nums){
        totalCounts += (num / k);
        totalCounts += (num < k) ? 0 : (num % k);
    }
    return totalCounts;
}
int minimumK(vector<int>& nums) {
    int low = 1;
    int high = nums[0];
    for(int num : nums) high = max(num, high);
    int minAns = -1;
    while(high >= low){
        int k = low + (high - low) / 2;
        int totalCounts = checkCeil(nums, k);
        if(totalCounts <= k*k){
            minAns = minAns == -1 ? k : min(minAns, k);
        high = k - 1;
        }
        else{
        low = k + 1;
    }   
    }
    return minAns;
}

string reverseByType(string s) {
    vector<char> alphabets;
    vector<char> specials;
    for(char a : s){
        if(a >= 97 && a <= 122) alphabets.push_back(a);
        else specials.push_back(a);
    }       
    
    string newStr = "";
    int alphPtr = alphabets.size() - 1;
    int specPtr = specials.size() - 1;
    for(char a : s){
        if(a >= 97 && a <= 122){
            newStr += alphabets[alphPtr--];
        }else{
            newStr+=specials[specPtr--];
        }
    }
    return newStr;
}

int main(){
string str = ")ebc#da@f(";
cout << reverseByType(str) << "\n";
    return 0;
}