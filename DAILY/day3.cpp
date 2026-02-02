#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

void printVector(vector<int>& vec){
    for(int num : vec) cout << num << " ";
    cout << "\n";
}

// 1. Running sum of an array
vector<int> runningSum(vector<int>& nums) {
    vector<int> answer;
    int prevSum = 0;        
    for(int num : nums){
        prevSum += num;
        answer.push_back(prevSum);
    }
    return answer;
}

// 2. Concatenation of Array
vector<int> concatenateArray(vector<int>& nums){
    vector<int> answer(nums.size()*2, 0);
    for(int i = 0; i < nums.size(); i+=1){
        answer[i] = nums[i];
        answer[i + nums.size()] = nums[i];
    }
    return answer;
}

// 3. Kids with greatest number of candies
vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
    vector<bool> answer;
    int maxNum = candies[0];
    for(int num : candies) maxNum = max(num, maxNum);
    for(int num : candies){
        if(num + extraCandies >= maxNum){
            answer.push_back(true);
        }else {
            answer.push_back(false);
        }
    }        
    return answer;
}

// 4. Shuffle array
vector<int> shuffle(vector<int>& nums, int n) {
    int index1 = 0;
    int index2 = n;
    int addIndex1 = 1;
    vector<int> answer;
    while(index2 < nums.size()){
        if(addIndex1 == 1){
            answer.push_back(nums[index1++]);
        }else{
            answer.push_back(nums[index2++]);
        }
        addIndex1*=-1;
    }
    return answer;
}

// 5. rotate array
void reverseArray(vector<int>& nums, int low, int high){
    while(high >= low){
        int temp = nums[low];
        nums[low] = nums[high];
        nums[high] = temp;
        low++;
        high--;
    }
}

void rotate(vector<int>& nums, int k) {
    k = k%nums.size();
    int pivot = nums.size() - k;
    reverseArray(nums, 0, pivot - 1);
    reverseArray(nums, pivot, nums.size() - 1);
    reverseArray(nums, 0, nums.size() - 1);
}


int main(){
    vector<int> res = {1, 2, 3, 4, 5};
    rotate(res, 2);
    printVector(res);
    return 0;
}
