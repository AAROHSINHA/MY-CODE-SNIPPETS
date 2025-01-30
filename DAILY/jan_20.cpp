#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

/*
PROBLEM STATEMENT 1 --> GFG POTD
Given the head a linked list, the task is to reverse every k node in the linked list. If the number of nodes is not a multiple of k then the left-out nodes in the end, should be considered as a group and must be reversed.

Input: head = 1 -> 2 -> 2 -> 4 -> 5 -> 6 -> 7 -> 8, k = 4
Output: 4 -> 2 -> 2 -> 1 -> 8 -> 7 -> 6 -> 5
*/
// CREATE A LINKED LIST
struct Node{
    int data;
    struct Node* next;
    Node(int x){
        this->data = x;
        this->next = nullptr;
    }
};

// HELPER FUNCTION - TRAVERSE A LINKED LIST
void TraverseLinkedList(Node* head){
    Node* tempPtr = head;
    while(tempPtr!=NULL){
        std::cout << tempPtr->data << " ";
        tempPtr = tempPtr->next;
    }
    std::cout << '\n';
}

/*
MEHTOD 1 - Using a vector
*/
vector<int> ReverseKVector(vector<int> vec, int k){
    vector<int> ans;
    int n = vec.size();
    int low = 0;

    while (low < n) {
        int high = min(low + k - 1, n - 1);
        for (int i = high; i >= low; i--) {
            ans.push_back(vec[i]);
        }
        low += k;
    }

    return ans;
}


Node *reverseKGroup1(Node *head, int k) {
    if(k <= 1) return head;
    vector<int> elements;
    Node* tempPtr = head;
    while(tempPtr!=NULL){
        elements.push_back(tempPtr->data);
        tempPtr = tempPtr->next;
    }
    vector<int> revElems = ReverseKVector(elements, k);
    Node* ll = NULL;
    Node* temp = ll;
    for(int a : revElems){
        Node* n = new Node(a);
        if(ll == NULL){
            ll = n;
            temp = ll;
        }else{
            temp->next = n;
            temp = temp->next;
        }
    }
    return ll;
}

/*
PROBLEM STATEMENT 2 -->
Largest subarray of 0's and 1's
Given an array arr of 0s and 1s. Find and return the length of the longest subarray with equal number of 0s and 1s.
*/

/*
METHOD 1 --> BRUTE FORCE METHOD
Time Complexity - O(N2)
Space Complexity - O(1)
*/
int longestSubarray1(vector<int> arr){
    int longestSubarray = 0;
    for(int i = 0; i < arr.size() - 1; i+=1){
        if(arr.size() - i < longestSubarray) break;
        int zC = 0;
        int oC = 0;
        for(int j = i; j < arr.size(); j+=1){
            if(arr[i]==0) zC++;
            if(arr[i]==0) oC++;
            if(zC == oC){
                longestSubarray = max(longestSubarray, j - i);
            }
        }
    }
    return longestSubarray;
}




int main(){
//   Node* head = new Node(2);
// head->next = new Node(7);
// head->next->next = new Node(1);
// head->next->next->next = new Node(5);
// head->next->next->next->next = new Node(8);
// head->next->next->next->next->next = new Node(7);
// head->next->next->next->next->next->next = new Node(4);
// head->next->next->next->next->next->next->next = new Node(6);
// head->next->next->next->next->next->next->next->next = new Node(8);
// head->next->next->next->next->next->next->next->next->next = new Node(2);
// head->next->next->next->next->next->next->next->next->next->next = new Node(8);
// head->next->next->next->next->next->next->next->next->next->next->next = new Node(8);


    vector<int> vec = {1, 0, 1, 1, 1, 0, 0};
    std::cout << longestSubarray1(vec);
    return 0; 
}