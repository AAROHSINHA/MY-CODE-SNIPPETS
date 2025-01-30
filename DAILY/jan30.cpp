#include <iostream>
#include <cctype>
#include <algorithm>
#include <vector>
using namespace std;

/*
PROBLEM STATEMENT 1 -->
Given a Pointer/Reference to the head of a doubly linked list of N nodes. The task is to sort the doubly linked list 
in both increasing and non-increasing order
*/
class Node{
public:
    int data;
    Node* next;
    Node* prev;
    Node(int x){
        this->data = x;
        this->next = NULL;
        this->prev = NULL;
    }
};
// helper function - traversal
void TraverseLinkedList(Node* head){
    Node* tempPtr = head;
    while(tempPtr!=NULL){
        std::cout << tempPtr->data << " ";
        tempPtr = tempPtr->next;
    }
    std::cout << '\n';
}

/*
Given a string S consisting of uppercase and lowercase characters. The task is to sort the uppercase and lowercase letters separately
such that if the ith place in the original string had an Uppercase character then it should not have a lowercase character after being sorted
and  vice versa

I/P - defRTSersUXI
O/P - deeIRSfrsTUX
*/

/*
METHOD 1
1. Make a position string. A string which will contain 0 for uppercase and 1 for lowercase. like abA = 001
2. Then store the uppercase and lowercases seperately and then sort them
3. Now use two pointers and take reference to the position string and return a new string
*/
string sortUpperLower(string str){
    string positionStr = "";
    string lower = "";
    string upper = "";
    for(char s : str){
        if(isupper(s)){
            upper += s;
            positionStr += "1";
        }else{
            lower += s;
            positionStr += "0";
        }
    }
    sort(lower.begin(), lower.end());
    sort(upper.begin(), upper.end());
    int lowerPtr = 0;
    int upperPtr = 0;
    string res = "";
    for(char x : positionStr){
        if(x == '1'){
            res+=upper[upperPtr++];
        }else{
            res+=lower[lowerPtr++];
        }
    }
    return res;
}

/*
PROBLEM STATEMENT 3 -->
Given a string S consisting of latin letters, arrange all its letters in lexographical order
using Counting Sort

I/P - 5
-> edsab
O/P - abdes
*/

/*
COUNTING SORT THEORY - 
Suppose arr = [1, 0, 3, 1, 3, 1]
1. First get max of the array and make a new array of that size+1. max = 3 -> [_ _ _ _]
2. Now store the frequencies according to the indexes (its easy just think about it) - [1, 3, 0, 2]
3. Now add from left to right actively (prefixSum) - [1, 3, 0, 2] --> [1, 4, 4, 6]
4. Now right shift the array by 1 - [0, 1, 4, 4]. These show the starting of the index elements. look below the meaning
5. [0, 1, 4, 4] --> Index 0 starts at 0 index, 3 starts at index 4
    0  1  2  3

6. Make a new array of size arr.size(). Then start iterating on arr. first element is 1. the [0 1 4 4][1] = 1
so place a 1 at index 1 at new array and increment its position in second array by 1. [0 2 4 4], Do this
*/
// example
vector<int> CountingSort(vector<int> arr) {
    int maxNum = INT_MIN;
    for (int a : arr) maxNum = max(maxNum, a);
    vector<int> indexVec(maxNum + 1, 0);

    // Frequency count
    for (int a : arr) indexVec[a]++;

    // Prefix sum (compute positions)
    for (int i = 1; i < indexVec.size(); i++) {
        indexVec[i] += indexVec[i - 1];
    }

    // Place elements in the correct position
    vector<int> ans(arr.size(), -1);
    for (int i = arr.size() - 1; i >= 0; i--) {
        int ind = indexVec[arr[i]] - 1;  // Find the position for arr[i]
        ans[ind] = arr[i];
        indexVec[arr[i]]--;  // Decrement the position for the next occurrence
    }

    return ans;
}



int main(){
    

    TraverseLinkedList(head);
    return 0;
}