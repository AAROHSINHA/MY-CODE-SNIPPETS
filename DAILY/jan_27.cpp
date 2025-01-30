#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/*
PROBLEM STATEMENT 1 -->
Best Time to buy and sell a stock
*/

/*
Method 1 - Brute Force
*/
int maxProfit1(vector<int>& prices) {
    int maxProfitMade = 0;
    for(int i = 0; i < prices.size() - 1; i+=1){
        for(int j = i + 1; j < prices.size(); j+=1){
            int currMade = prices[j] - prices[i];
            if(currMade >= maxProfitMade) maxProfitMade = currMade;
        }
    }        
    return maxProfitMade;
}

/*
Method 2 -->
Prefix Array
*/
int maxProfit2(vector<int>& prices){
    vector<int> prefixArr(prices.size(), -1);
    if(prices.size() >= 2){
        prefixArr[prices.size() - 1] = prices[prices.size() - 1];
    }
    for(int i = prices.size() - 2; i >= 0; i-=1){
        prefixArr[i] = max(prefixArr[i + 1], prices[i]);
    }
    int maxMade = 0;
    for(int i = 0; i < prices.size(); i+=1){
        if(prefixArr[i] - prices[i] > maxMade){
            maxMade = prefixArr[i] - prices[i];
        }
    }
    return maxMade;
}

/*
Method 3 -->
Using Two Pointers
*/
int maxProfit3(vector<int>& prices){
    int low = 0;
    int high = low + 1;
    int maxPrice = 0;
    while(high < prices.size() && high > low){
        if(prices[high] < prices[low]){
            low = high;
        }else{
            maxPrice = max(prices[high] - prices[low], maxPrice);
        }

        high++;
    }
    return maxPrice;
}

/*
PROBLEM STATEMENT 2 -->
Given an array A[] of N positive integers, where each integer ranges from 1 to N. Some elements might be repeated, while others might be missing from the array. Your task is to count the frequency of each integer from 1 to N.
Note: expected time complexity o(n) with space complexity - o(1)
*/
/*
Method 1 - Use HashMap
=> Although space complexity comes O(N) but good for practice
*/
void getFreq1(vector<int>& arr){
    unordered_map<int, int> hashmap;
    for(int a : arr) hashmap[a]+=1;
    for(int i = 1; i <= arr.size(); i+=1){
        arr[i - 1] = hashmap[i];
    }
}

/*
Method 2 - increase the array by adding a virtual array
*/
void getFreq2(vector<int>& arr){
    int N = arr.size();
    for(int i = 0; i < N; i+=1){
        arr.push_back(0);
    }
    for(int i = 0; i < N; i+=1){
        arr[arr[i] + N - 1]+=1;
    }
    arr.erase(arr.begin(), arr.begin() + N);
}

/*
Method 3 --> OPTIMAL ONE
*/
void getFreq3(vector<int>& arr) {
      int i = 0;
      int N = arr.size();
      int P = N;
        while (i<N)
        {
            // If this element is already processed,
            // then nothing to do
            if (arr[i] <= 0 || arr[i]>N || arr[i]>P)
            {
                i++;
                continue;
            }
     
            // Find index corresponding to this element
            // For example, index for 5 is 4
            int elementIndex = arr[i]-1;
     
            // If the elementIndex has an element that is not
            // processed yet, then first store that element
            // to arr[i] so that we don't lose anything.
            if (arr[elementIndex] > 0)
            {
                arr[i] = arr[elementIndex];
     
                // After storing arr[elementIndex], change it
                // to store initial count of 'arr[i]'
                arr[elementIndex] = -1;
            }
            else
            {
                // If this is NOT first occurrence of arr[i],
                // then decrement its count.
                arr[elementIndex]--;
     
                // And initialize arr[i] as 0 means the element
                // 'i+1' is not seen so far
                arr[i] = 0;
                i++;
            }
        }
        for(int i=0;i<N;i++) {
            if(arr[i] < 0) arr[i] = -arr[i];
            else arr[i]=0;
        }
    }

/*
PROBLEM STATEMENT 3 -->
Repeating Binary Search
*/




int main(){
    vector<int> vec1 = {2, 3, 2, 3, 5};
    for(int a : vec1) std::cout << a << " ";
    std::cout << '\n';

    getFreq3(vec1);
    for(int a : vec1) std::cout << a << " ";
    std::cout << '\n';
    return 0;
}