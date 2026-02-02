#include <iostream>
#include <vector>
#include <unordered_map>
#include <utility>
#include <set>
#include <algorithm>
using namespace std;

// 0. print 2d matrix
void printMatrix(vector<vector<int>> mat){
    for(vector<int> vec : mat){
        for(int num : vec) cout << num << " ";
        cout << "\n";
    }
}
// 0. print vector
void printVector(vector<int> vec){
    for(int num : vec) cout << num << " ";
    cout << "\n";
}

// 1. max element in each row
vector<int> maxEachRow(vector<vector<int>> mat){
    vector<int> res;
    for(int i = 0; i < mat.size(); i+=1){
        int maxNum = mat[i][0];
        for(int j = 0; j < mat[i].size(); j+=1){
            if(mat[i][j] > maxNum) maxNum = mat[i][j];
        }
        res.push_back(maxNum);
    }
    return res;
}

// 2. Matrix Transpose
vector<vector<int>> matrixTranspose(vector<vector<int>> mat){
    vector<vector<int>> res;
    for(int i = 0; i < mat[0].size(); i+=1){
        vector<int> vec;
        for(int j = 0; j < mat.size(); j+=1){
            vec.push_back(mat[j][i]);
        }
        res.push_back(vec);
    }
    return res;
}

// 3. Count Unique Elements in a Matrix
int uniqueInMatrix(vector<vector<int>> matrix){
    unordered_map<int, int> freqMap;
    for(vector<int> vec : matrix){
        for(int num : vec) freqMap[num]+=1; 
    }

    int count = 0;
    for(auto val : freqMap){
        if(val.second == 1) count++;
    }
    return count;
}

// 4. First Row With Maximum Sum
int rowWithMaxSum(vector<vector<int>> matrix){
    int maxSum = 0;
    int maxRow = -1;
    int i = 0;
    for(vector<int> vec : matrix){
        int sum = 0;
        for(int num : vec){
            sum += num;
        }

        if(maxRow == -1 || (maxSum > sum)){
            maxSum  = sum;
            maxRow = i + 1; // assumption of 1 based indexing required for row numbers
        }
        i++;
    }
    return maxRow;
}

// 5. Spiral Traversal (Read-Only)
vector<int> spiralTraversal(vector<vector<int>> matrix){
    vector<int> answer;
    int forward = 1;
    for(int i = 0; i < matrix.size(); i+=1){
        if(forward == 1){
            for(int j = 0; j < matrix[i].size(); j+=1) answer.push_back(matrix[i][j]);
        }else{
            for(int j = matrix[i].size() - 1; j >= 0; j-=1) answer.push_back(matrix[i][j]);
        }
        forward*=-1;
    }
    return answer;
}

// 6. Two Sum (Index Version) - Given a vector and a target sum, return indices of two elements whose sum equals target.
pair<int, int> twoSum(vector<int> vec, int target){
    int low = 0;
    int high = vec.size() - 1;
    while(high > low){
        int sum = vec[low] + vec[high];
        if(sum == target) return make_pair(low, high);
        else if(sum > target) high-=1;
        else low+=1;
    }
    return make_pair(-1, -1);
}

// 7. Group Anagrams
struct MapHash {
    size_t operator()(const unordered_map<char, int>& m) const {
        size_t hash = 0;

        for (const auto& p : m) {
            // combine key and value hashes
            size_t h1 = std::hash<char>{}(p.first);
            size_t h2 = std::hash<int>{}(p.second);

            // standard hash combine
            hash ^= h1 ^ (h2 << 1);
        }

        return hash;
    }
};

vector<vector<string>> groupAnagrams(vector<string> vec){
    unordered_map<unordered_map<char, int>, vector<string>, MapHash> hashMap;
    for(string str : vec){
        // make unordered map for it
        unordered_map<char, int> freqMap;
        for(char s : str) freqMap[s]++;

        // update hashMap
        if(hashMap.find(freqMap)!=hashMap.end()){
            hashMap[freqMap].push_back(str);
        }else{
            vector<string> v = {str};
            hashMap[freqMap] = v;
        }
    }
    
    // answer
    vector<vector<string>> answer;
    for(auto val : hashMap){
        vector<string> v; 
        for(string str : val.second){
            v.push_back(str);
        }
        answer.push_back(v);
    }
    return answer;
}

// 8. Row With Maximum 1s
int maxOnes(vector<vector<int>> matrix){
    int maxOneCount = 0;
    int maxRowCount = -1;
    for(int i = 0; i < matrix.size(); i+=1){
        int oneCount = 0;
        for(int nums : matrix[i]) oneCount += 1;
        if(oneCount > maxOneCount){
            maxOneCount = oneCount;
            maxRowCount = i + 1; // 1 based assumpition 
        }
    }
    return maxRowCount;
}

// 9. Longest Subarray With Equal 0s and 1s
int longestSubarrayWith01(vector<int>& vec){
    int currSum = 0;
    for(int i = 0; i < vec.size(); i+=1){
        currSum += (vec[i] == 1) ? -1 : 1;
        vec[i] = currSum;
    }
    unordered_map<int, set<int>> hashMap;
    for(int i = 0; i <vec.size(); i+=1){
        if(hashMap.find(vec[i])!=hashMap.end()){
            hashMap[vec[i]].insert(i);
        }else{
            set<int> s;
            s.insert(i);
            hashMap[vec[i]] = s;
        }
    }

    int longest = 0;
    for(auto val : hashMap){
        int num = val.first;
        int minNum = *val.second.begin();
        // check for absolute 1
        int oneNext = num + 1;
        int oneBefore = num - 1;
        if(hashMap.find(oneNext)!=hashMap.end()){
            set<int> foundSet = hashMap[oneNext];
            int maxNum = *foundSet.rbegin();
            longest = max(longest, maxNum - minNum + 1);
        }
        if(hashMap.find(oneBefore)!=hashMap.end()){
            set<int> foundSet = hashMap[oneBefore];
            int maxNum = *foundSet.rbegin();
            longest = max(longest, maxNum - minNum + 1);
        }
    }
    return longest;

}

// 10. K Most Frequent elements
vector<int> KMostFrequent(vector<int> vec, int k){
    k = k%vec.size();
    unordered_map<int, int> freqMap;
    set<int> freqSet;
    unordered_map<int, vector<int>> hashMap;
    for(int num : vec) freqMap[num]+=1;
    for(auto val : freqMap){
        int num=val.first;
        int freq=val.second;
        if(hashMap.find(freq)!=hashMap.end()){
            hashMap[freq].push_back(num);
        }else{
            vector<int> v = {num};
            hashMap[freq] = v;
        }
        freqSet.insert(freq);
    }

    vector<int> answer;
    auto it = freqSet.end();
    int m = 0;
    while(k > 0){
        it--;
        int freq = *it;
        vector<int> v = hashMap[freq];
        for(int num : v){
            answer.push_back(num);
            k-=1;
        }
    }
    return answer;

}

// 11. reverse words
string reverseWords(string str){
    string newStr = "";
    string currWord = "";
    for(int i = 0; i < str.length(); i+=1){
        if(str[i] == ' '){
            currWord = " " + currWord + newStr;
            newStr = currWord;
            currWord = "";
        }else{
        currWord += str[i];
        }
    }
    currWord += newStr;
    newStr = currWord;
    return newStr;
}

// 12. Check if 2 strings are anagrams
bool checkAnagram(string& str1, string& str2){
    unordered_map<char, int> freqMap;
    for(char s : str1) freqMap[s]+=1;
    for(char t : str2) freqMap[t]-=1;
    for(auto val:freqMap){
        if(val.second!=0) return false;
    }
    return true;
}

// 13. First non repearing character
int firstNonRepeatingChar(string& str){
    unordered_map<char, int> freqMap;
    for(char s : str) freqMap[s]+=1;
    for(int i = 0; i < str.length(); i+=1){
        if(freqMap[str[i]] == 1) return i;
    }
    return -1;
    
}

int main(){
    string str = "This is a wild game of survival";
    cout << reverseWords(str) << "\n";
    return 0;
}