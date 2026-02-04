#include <iostream>
#include <vector>
using namespace std;

// lower and upper bound
int lowerBound(vector<int> nums, int target){
    int low = 0;
    int high = nums.size() - 1;
    int lower_bound = -1;
    while(high >= low){
        int mid = low + (high - low)/2;
        if(nums[mid] >= target){
            lower_bound = mid;
            high = mid - 1;
        }else{
            low = mid + 1;
        }
    }
    return lower_bound;
}

// search matrix
int searchRow(vector<vector<int>>& matrix, int target){
    int low = 0;
    int high = matrix.size() - 1;
    int bound = -1;
    while(high >= low){
        int mid = low + (high - low)/2;
        if(matrix[mid][0] == target) return mid;

        if(matrix[mid][0] < target){
            bound = mid;
            low = mid + 1;
        }else{
            high = mid - 1;
        }
    }
    return bound;
}
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int row = searchRow(matrix, target);
    if(row == -1) return false;
    if(matrix[row][0] == target) return true;

    int low = 0;
    int high = matrix[row].size() - 1;
    while(high >= low){
        int mid = low + (high - low)/2;
        if(matrix[row][mid] == target) return true;
        else if(matrix[row][mid] > target) high = mid - 1;
        else low = mid + 1;
    }
    return false;
}

// koko eating bananas
int HoursTaken(vector<int>& piles, int k){
    int hours = 0;
    for(int height : piles){
        hours += (height + k - 1)/k;
    }
    return hours;
}
int minEatingSpeed(vector<int>& piles, int h) {
    int m = piles[0];
    for(int height : piles) m = max(height, m);
    int currentLeastHours = -1;
    int low = 1;
    int high = m;
    while(high >= low){
        int mid = low + (high - low)/2;
        int hoursTaken = HoursTaken(piles, mid);
        if(hoursTaken > h){
            low = mid + 1;
        }else{
            high = mid - 1;
            currentLeastHours = mid;
        }
    }
    return currentLeastHours;
}

// minimum in rotated sorted
int findMin(vector<int> &nums) {
    int low = 0;
    int high = nums.size() - 1;
    if(nums[low] < nums[high]) return low;
    int mid = -1;
    while(high >= low){
        if(high - low <= 1) return (nums[low] > nums[high]) ? high : low;
        mid = low + (high - low)/2;
        if(nums[low] > nums[mid]) high = mid;
        if(nums[mid] > nums[high]) low = mid;
    }        
    return mid;
}

// search in rotated sorted array
int binarySearch(vector<int>& nums, int low, int high, int target) {
    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (nums[mid] == target) 
            return mid;          
        else if (nums[mid] < target) 
            low = mid + 1;       
        else 
            high = mid - 1;     
    }
    return -1; 
}


int search(vector<int>& nums, int target) {
    int pivot = findMin(nums);
    if(nums[pivot] == target) return pivot;
    if(pivot == 0) return binarySearch(nums, 0, nums.size() - 1, target);
    int low = 0;
    int high = nums.size() - 1;
    if(nums[low] <= target && nums[pivot - 1] >= target) return binarySearch(nums, low, pivot - 1, target);
    return binarySearch(nums, pivot, high, target);
}

int main(){
    vector<int> nums = {1, 3, 5};
    for(int num : nums){
        cout << num << " - " << search(nums, num) << "\n";
    }

    return 0;
}