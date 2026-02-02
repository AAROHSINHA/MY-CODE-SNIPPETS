#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// 0. print vector
void printVec(vector<int>& nums){
    for(int num : nums) cout << num << " ";
    cout << "\n";
}

// 1. Move zeros to end
void moveZeroes1(vector<int>& nums) {
    int zeroCount = 0;
    for(int ptr = 0; ptr < nums.size() - (zeroCount); ){
        if(nums[ptr] == 0){
            int j = ptr;
            while(j < nums.size() - (zeroCount + 1)){
                int temp = nums[j + 1];
                nums[j + 1] = nums[j];
                nums[j] = temp;
                j++;
            }
            zeroCount+=1;
     
        }else{
            ptr+=1;
        }
    }
}
void moveZeroes(vector<int>& nums) {
    int count = 0;
    int zeroCount = -1;
    for(int i = 0; i < nums.size(); i+=1){
        if(nums[i] == 0){
            zeroCount = i;
            break;
        }
    }
    
    if(zeroCount == -1) return;
    count = zeroCount + 1;
    while(zeroCount < nums.size() && count < nums.size()){
        while(count < nums.size() && nums[count] == 0) count++;
              if (count == nums.size())
            break;
        nums[zeroCount] = nums[count];
        nums[count] = 0;
        zeroCount = zeroCount + 1;
        count = count + 1;
    }

}

// 2. reverse words in a string
string reverseWords(string s) {
    string newStr = "";
    string currWord = "";

    for(int i = 0; i < s.length(); i++) {
        if (currWord.empty() && s[i] == ' ') continue;

        if (s[i] == ' ') {
            if (!currWord.empty()) {
                if (!newStr.empty()) newStr = " " + newStr;
                newStr = currWord + newStr;
                currWord.clear();
            }
        } else {
            currWord += s[i];
        }
    }
    if (!currWord.empty()) {
        if (!newStr.empty()) newStr = " " + newStr;
        newStr = currWord + newStr;
    }

    return newStr;
}

// 3. Valid Palnidrome
bool isPalindrome(string s) {
    string fixedStr = "";
    for(char a : s){
        if((a >= 96 && a <= 122) || (a >= 65 && a <= 90) || (a >= 48 && a <= 57)) fixedStr += tolower(a);
    }
    int low = 0;
    int high = fixedStr.length() - 1;
    while(high >= low){
        if(fixedStr[low]!=fixedStr[high]){
            return false;
        }
        low++;
        high--;
    }
    return true;
}

// product of array except self
vector<int> productExceptSelf(vector<int>& nums) {
    vector<int> answer(nums.size(), 0);
    int zeroCount = 0;
    int product = 1;
    for(int num : nums) {
        zeroCount += num == 0; 
        product *= (num == 0) ? 1 : num;
    }       
    if(zeroCount >= 2) return answer;
    for(int i = 0; i < nums.size(); i+=1){
        if(nums[i] == 0) answer[i] = product;
        else answer[i] = (zeroCount == 0) ? product / nums[i] : 0;
    }
    return answer;
    
}

// best time to buy and sell a stock
int maxProfit(vector<int>& prices) {
    vector<int> prefixMin = {prices[0]};
    vector<int> suffixMax(prices.size(), 0);
    for(int i = 1; i < prices.size(); i++) {
        prefixMin.push_back(min(prices[i], prefixMin[i - 1]));
    } 
    for(int i = prices.size() - 1; i >= 0; i-=1){
        if(i == suffixMax.size() - 1) suffixMax[i] = prices[i];
        else suffixMax[i] = max(suffixMax[i + 1], prices[i]);
    }

    // difference
    int maxDiff = 0;
    for(int i = 0; i < prefixMin.size(); i+=1){
        maxDiff = max(maxDiff, suffixMax[i] - prefixMin[i]);
    }
    return maxDiff;
}

// 6.  Find All Anagrams in a String
vector<int> findAnagrams(string s, string p) {
    unordered_map<char, int> pMap;
    unordered_map<char, int> sMap;
    vector<int> answer;
    int low = 0;
    int high = p.length() - 1;
    for(int i = 0; i <= high; i+=1){
        pMap[p[i]]+=1;
        sMap[s[i]]+=1;
    }

    while((high < s.length())){
        if(high == s.length()) break;
        if(pMap == sMap) answer.push_back(low);
        sMap[s[low]]-=1;
        if (sMap[s[low]] == 0)
    sMap.erase(s[low]);
        low++;
        high++;
        sMap[s[high]]+=1;
    }
    return answer;
}

// 7. sort colors
void sortColors(vector<int>& nums) {
        int r = 0;
        int w = 0;
        int b = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 0){
                r+=1;
            }else if(nums[i] == 1){
                w+=1;
            }else{
                b+=1;
            }
        }
        

        for(int i = 0; i < nums.size(); i++){
            if(i < r){
                nums[i] = 0;
            }else if(i >= r && i < w+r){
                nums[i] = 1;
            }else{
                nums[i] = 2;
            }
        }
    }

int main(){
    string s = "cbaebabacd";
    string p = "abc";
    vector<int> ans = findAnagrams(s, p);
    printVec(ans);
    return 0;
}