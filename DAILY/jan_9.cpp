#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>

/*
PROBLEM STATEMENT 1 --> 
Given a sorted arrray and a value x, the floor of x is the largest element inarray smaller than or equal to x
Write efficient functions to find floor of x.

arr[] = {10, 12, 19, 25, 30}
x = 20
O/P -> 19
*/

// Linear method.
int getSmallerLinear(int* arr, int n, int x){
    int floor = -1;
    int minDiff = INT_MAX;
    for(int i = 0; i < n; i+=1){
        if(arr[i] > x) continue;
        int currDiff = x - arr[i];
        std::cout << currDiff << std::endl;
        if(currDiff < minDiff){
            minDiff = currDiff;
            floor = arr[i];
        }
    }
    return floor;
}

// Binary Method
int getSmallerBinary(int* arr, int n, int x){
    int low = 0;
    int high = n - 1;
    int floor = -1;
    while(high >= low){
        int mid = low + (high - low)/2;
        if(arr[mid] == x){
            return x;
        }else if(arr[mid] > x){
            high = mid - 1;
        }else{
            floor = arr[mid];
            low = mid + 1;
        }
    }
    return floor;
}

/*
PROBLEM STATEMENT 2 --> 
Merge K sorted linked lists and return it as one sorted list.
eg - 
1 -> 10 -> 20
4 -> 11 -> 13
3 -> 8 -> 9

O.P = 1, 3, 4, 8, 9, 10, 11, 13, 20
*/
// First implementing a linked list class
class Node{
public:
    int val;
    Node* next;
    Node(int data){
        this->val = data;
        this->next = nullptr;
    }
};

// Insert in LL
void Insert(Node* &head, int data){
    Node* n = new Node(data);
    if(head == NULL){
        head = n;
        return;
    }
    Node* tempPtr = head;
    while(tempPtr->next != nullptr){
        tempPtr = tempPtr->next;
    } 
    tempPtr->next = n;
}

// Traverse a linked list
void TraverseLinkedList(Node* head){
    if(head == NULL){
        return;
    }
    Node* tempPtr = head;
    while(tempPtr!=NULL){
        std::cout << tempPtr->val << " ";
        tempPtr = tempPtr->next;
    }
    std::cout << std::endl;
}

// Funciton to merge the sorted ones
/*
method 1 - basically add them all in one array or vector and then sort them.
THough I find this noto very optimal.
*/
Node* MergeSortedLinkedLists(std::vector<Node*> lists){
    std::vector<int> elements;
    // adding elements in vector
    for(Node* head : lists){
        if(head == nullptr){
            continue;
        }
        Node* tempPtr = head;
        while(tempPtr!=NULL){
            elements.push_back(tempPtr->val);
            tempPtr = tempPtr->next;
        }
    }

    // sorting the vector
    std::sort(elements.begin(), elements.end());
    Node* ll = nullptr;
    Node* temp = ll;
    for(int num : elements){
        Node* n = new Node(num);
        if(ll == nullptr){
            ll = n;
            temp = ll;
        }else{
            temp->next = n;
            temp = temp->next;
            
        }
    }

    return ll;

}
/////////////////////////// --> LEARN PRIORITY QUEUE AND IMPLEMENT IT



int main(){
    // int arr[5] = {10, 12, 19, 25, 30};
    // std::cout << getSmallerLinear(arr, 5, 20) << std::endl;
    // std::cout << getSmallerBinary(arr, 5, 25) << std::endl;
    
    Node* head1 = new Node(1);
    head1->next = new Node(10);
    head1->next->next = new Node(20);
    Node* head2 = new Node(4);
    head2->next = new Node(11);
    head2->next->next = new Node(13);
    Node* head3 = new Node(3);
    head3->next = new Node(8);
    head3->next->next = new Node(9);

    std::vector<Node*> lists = {head1, head2, head3};
    Node* finalNode = MergeSortedLinkedLists(lists);
    TraverseLinkedList(finalNode);
    

    return 0;
}