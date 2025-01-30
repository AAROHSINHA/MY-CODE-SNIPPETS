#include <iostream>

/*
PRACTICE PROBLEM 1 - GFG POTD-->
Given an integer k, left rotate the linked list k times
*/
struct Node{
    int data;
    struct Node* next;
    Node(int x){
        this->data = x;
        this->next = nullptr;
    }
};

void TraverseLinkedList(Node* head){
    Node* tempPtr = head;
    while(tempPtr!=NULL){
        std::cout << tempPtr->data << ' ';
        tempPtr = tempPtr->next;
    }
    std::cout << '\n';
}

int lengthLL(Node* head) {
    int length = 0;
    Node* tempPtr = head;
    while (tempPtr != NULL) {
        length++;
        tempPtr = tempPtr->next;
    }
    return length;
}

Node* rotate(Node* head, int k) {
    /* 
    STEPS - 
    1. Iterate till the (k-1)th node 
    2. Store its next in a temp Var and make the (k-1th) node null; 
    3. In the tempVar, go till the tail and make its next the real head 
    */
    if (head == NULL || k == 0) return head;

    int length = lengthLL(head);
    k = k % length;
    if (k == 0) return head;

    Node* tempPtr = head;
    for (int i = 1; i < k; i++) {
        tempPtr = tempPtr->next;
    }

    if (tempPtr->next == NULL) return head;
    Node* tempVar = tempPtr->next;
    tempPtr->next = NULL;

    Node* tempPtr2 = tempVar;
    while (tempPtr2->next != NULL) {
        tempPtr2 = tempPtr2->next;
    }
    tempPtr2->next = head;

    return tempVar;
}


int main(){
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    head->next->next->next->next = new Node(50);

    Node* rotatedhead = rotate(head, 2);
    TraverseLinkedList(head);
    TraverseLinkedList(rotatedhead);
    return 0;
}