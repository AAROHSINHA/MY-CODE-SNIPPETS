#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <algorithm>
#include <map>
using namespace std;

// 1. write a program that in n integers and prints it
void inputAndOutput(int n){
    if(n <= 0) return;
    for(int i = 0; i < n; i+=1){
        int num;
        cout << "Enter Integer " << i + 1 << " - ";
        cin >> num;
        cout << "Square Of Number " << num << " is " << num*num << endl;
    }
}

// 2. Take an integer n and print sum of its digits
int sumOfDigits(int num){
    int sum = 0;
    while(num > 0){
        int digit = num % 10;
        sum += digit;
        num /= 10;
    }
    return sum;
}

// 3. Take n as an input and store n numbers in array. print maximum and minimum
// from a separate for loop
void StoreArrMaxMin(int size){
    int* arr = new int[size];
    // taking in inputs in array
    for(int i = 0; i < size; i+=1){
        cout << "Enter number " << i + 1 << " - ";
        cin >> arr[i];
    }

    int minNum = arr[0];
    int maxNum = arr[0];
    for(int i = 0; i < size; i+=1){
        minNum = min(arr[i], minNum);
        maxNum = max(arr[i], maxNum);
    }

    cout << "Minumum - " << minNum << "\n";
    cout << "Maximum - " << maxNum << "\n";
    delete[] arr; 
 
}

// 4. check if a number is prime or not
bool checkPrime(int num){
    if(num <= 1) return false;
    for(int i = 2; i <= num/2; i+=1){
        if(num % i == 0) return false;
    }
    return true;
}

// 5. take a vector as a input and print the second largest number
int secondLargest(vector<int> nums){
    int size = nums.size();
    int firstLargest = nums[0];
    int secondLargest = nums[0];
    for(int i = 0; i < size; i+=1){
        if(nums[i] >= firstLargest){
            secondLargest = firstLargest;
            firstLargest = nums[i];
        }else if(nums[i] > secondLargest){
            secondLargest = nums[i];
        }
    }
    return secondLargest;
}

// 6. Rotate Vector by K
void RotateRightByK1(vector<int>& nums, int k){
    k = k % nums.size();

    vector<int> newVec;
    // storing last k elements at beginning
    for(int i = nums.size() - k; i < nums.size(); i+=1){
        newVec.push_back(nums[i]);
    }
    // storing rest elements after them
    for(int i = 0; i < nums.size() - k; i+=1){
        newVec.push_back(nums[i]);
    }
    nums = newVec;
}


void rotateInVector(vector<int>& nums, int start, int end){
    while(end > start){
        int temp = nums[start];
        nums[start] = nums[end];
        nums[end] = temp;
        end-=1;
        start+=1;
    }
}

void RotateRightByK2(vector<int>& nums, int k){
    if(k > nums.size()) return;
    int pivot = nums.size() - k;
    rotateInVector(nums, 0, pivot - 1);
    rotateInVector(nums, pivot, nums.size() - 1);
    rotateInVector(nums, 0, nums.size() - 1);
}

// 7. remove duplicates
// solution 1 - brute force O(n2)
vector<int> removeDuplicates1(vector<int>& nums){
    vector<int> uniqueVec;
    for(int i = 0; i < nums.size(); i+=1){
        int num = nums[i];
        bool contains = false;
        for(int j = 0; j < uniqueVec.size(); j+=1){
            if(uniqueVec[j] == num){
                contains = true;
                break;
            }
        }
        if(!contains) uniqueVec.push_back(num);
    }
    return uniqueVec;
}

// i am stuck here man
// see if the question is of sorted, we can get in o(n) by equating arr[i] == arr[i - 1]
// but if here its unsorted, using a set sorts it right?
// please specify if its sorted or not

// 8. check if vector is sorted
bool checkSorted(vector<int>& nums){
    for(int i = 1; i < nums.size(); i+=1){
        if(nums[i] >= nums[i - 1]) continue;
        else return false;
    }
    return true;
}

// 9. Two Sum
bool hasTwoSum(const vector<int>& v, int target){
    int low = 0;
    int high = v.size() - 1;
    while(high > low){
        int sum = v[low] + v[high];
        if(sum == target) return true;
        if(sum > target) low += 1;
        else high -= 1;
        low += 1;
        high -= 1;
    }
    return false;
}

// 10. write a function that prints frequency of each element
void printFrequency(vector<int>& nums){
    unordered_map<int, int> freqMap;
    for(int num: nums) freqMap[num]+=1;
    for(auto val : freqMap){
        cout << val.first << " - " << val.second << endl;
    }
}

// 11. first non repeating element
int firstNonRepeatingElement(vector<int> nums){
    unordered_map<int, int> freqMap;
    for(int num : nums) freqMap[num]+=1;
    for(int num : nums){
        if(freqMap[num] == 1) return num;
    }
    return -1;
}



// 12. Are 2 vector equal (ignoring order)
bool areEqualIgnoreOrder(vector<int>& arr1, vector<int>& arr2){
    unordered_map<int, int> freqMap;
    for(int num : arr1) freqMap[num]++;
    for(int num : arr2) freqMap[num]--;
    for(auto val : freqMap) {
        if(val.second != 0) return false;
    }
    return true;    
}

// 13. Intersection of 2 vectors (order doesnt matter)
vector<int> intersection(const vector<int>& arr1, const vector<int>& arr2){
    unordered_map<int, int> freqMap;
    vector<int> newVec;
    for(int num : arr1) freqMap[num]++;
    for(int num : arr2) freqMap[num]--;
    for(auto val : freqMap) {
        newVec.push_back(val.first);
    }
    return newVec;
}

// 14. subarray with 0 sum - will try

// 15. Group elements by frequency
unordered_map<int, vector<int>> groupByFrequency(const vector<int>& nums){
    unordered_map<int, int> freqMap;
    for(int num : nums) freqMap[num]++;
    unordered_map<int, vector<int>> groupFreq;
    for(auto val : freqMap){
        int number = val.first;
        int freq = val.second;
        if(groupFreq.find(freq)!=groupFreq.end()){
            groupFreq[freq].push_back(number);
        }else{
            vector<int> n = {};
            n.push_back(number);
            groupFreq[freq] = n;
        }
    }
    return groupFreq;
}

// 16. Check if All Elements Are Unique
bool allUnique(const vector<int>& v){
    unordered_map<int, int> freqMap;
    for(int num : v) freqMap[num]+=1;
    for(auto val : freqMap) {
        if(val.second > 1) return false;
    }
    return true;
}

// 17. K most frequent elements
vector<int> kMostFrequent(const vector<int>& v, int k){
    vector<int> answer;
    unordered_map<int, int> freqMap;
    vector<int> freqVector;
    unordered_map<int, vector<int>> freqGroups = groupByFrequency(v);
    for(int num : v) freqMap[num]++;
    for(auto val : freqMap) freqVector.push_back(val.second);
    sort(freqVector.begin(), freqVector.end());
    int last = freqVector.size() - 1;
    while(k > 0){
        int most = freqVector[last];
        vector<int> elems = freqGroups[most];
        for(int num : elems){
            answer.push_back(num);
            k -= 1;
        }

        last -= 1;
        
    }
    return answer;

}

// 18. Replace elements with frequency
vector<int> replaceWithFrequency(const vector<int>& v){
    unordered_map<int, int> freqMap;
    for(int num : v) freqMap[num]+=1;
    vector<int> nums;
    for(int num : v){
        nums.push_back(freqMap[num]);
    }
    return nums;
}

// 19. Count Distinct Elements
int countDistinct(const vector<int>& v){
    unordered_map<int, int> freqMap;
    int count = 0;
    for(int num : v) freqMap[num]+=1;
    for(auto val : freqMap){
        if(val.second == 1) count ++;
    }
    return count;
}

// 20. Move All Zeros to End
void moveZerosToEnd(vector<int>& v) {
    int numZeros = 0;
    for (int i = 0; i < v.size() - numZeros; ) {
        if (v[i] == 0) {
            int zPtr = i + 1;

            while (zPtr < v.size()) {
                v[zPtr - 1] = v[zPtr];
                zPtr++;
            }

            v[v.size() - 1] = 0;
            numZeros += 1;
            // i NOT incremented here
        } else {
            i++; // only move forward if no shift happened
        }
    }
}

// 21. Majority Element (Simple)
int majorityElement(const vector<int>& v){
    unordered_map<int, int> freqMap;
    for(int num : v){
        freqMap[num]+=1;
    }
    for(auto val : freqMap){
        if(val.second > v.size()/2){
            return val.second;
        }
    }
return -1;
}

// 22. Remove All Occurrences of X
void removeAll(vector<int>& v, int x){
    int xCount = 0;
    for(int i = 0; i < v.size() - xCount; ){
        if(v[i] == x){
            int ptr = i + 1;
            while(ptr < v.size()){
                v[ptr - 1] = v[ptr];
                ptr++;
            }
            v[v.size() - 1] = x;
            xCount += 1;
        }else{
            i+=1;
        }
    }

    while(xCount > 0){
        v.pop_back();
        xCount--;
    }
}

// 23. Check if one vector is subset of another
bool isSubset(const vector<int>& a, const vector<int>& b){
    if(b.size() > a.size()) return false;
    int ptr1 = 0;
    int ptr2 = b.size() - 1;
    int bFirst = b[0];
    int bLast = b[b.size() - 1];
    while(ptr2 < a.size()){
        if(a[ptr1] == bFirst && a[ptr2] == bLast){
            bool isSubset = true;
            int bIndex = 0;
            for(int i = ptr1; i < ptr2; i++){
                if(a[i]!=b[bIndex]){
                    isSubset = false;
                    break;
                }
                bIndex++;
            }

            if(isSubset) return true;
        }
        ptr1++;
        ptr2++;
    }
    return false;
}

// 24. Find Element with Maximum Frequency
int maxFrequencyElement(const vector<int>& v){
    unordered_map<int, int> freqMap;
    for(int num : v) freqMap[num]++;
    int maxNum = v[0];
    int maxFreq = 1;
    for(auto val : freqMap){
        if(val.second > maxFreq){
            maxNum= val.first;
            maxFreq = val.second;
        }
    }
    return maxNum;
}

// 25. Sort Elements by Frequency
vector<int> sortByFrequency(const vector<int>& v){
    map<int, int> freqMap;
    map<int, vector<int>> freqGroup;
    for(int num : v) freqMap[num]+=1;
    for(auto val : freqMap){
        int num = val.first;
        int freq = val.second;
        if(freqGroup.find(freq)!=freqGroup.end()){
            freqGroup[freq].push_back(num);
        }else{
            vector<int> v = {};
            v.push_back(num);
            freqGroup[freq] = v;
        }
    }

    vector<int> answer;
    for(auto val : freqGroup){
        vector<int> vec = val.second;
        for(int n : vec){
            answer.push_back(n);
        }
    }
    return answer;
}


int main(){
    vector<int> nums1 = {1, 2, 3, 3, 4, 5, 6, 7, 8, 8, 9};
    vector<int> nums2 = sortByFrequency(nums1);
    for(int num : nums2){
        cout << num << " ";
    }
    cout << endl;
    return 0;
}
