#include<bits/stdc++.h>
using namespace std;

class Node{
  public:
  int data;
  Node* next;
  
  Node(int data1, Node* next1){
      data = data1;
      next = next1;
  }
  
  Node(int data1){
      data = data1;
      next = nullptr;
  }
  
};


Node* convertArr2LL(vector<int> arr){
    Node* head = new Node(arr[0]);
    Node* temp = head;
    int n = arr.size();
    for(int i = 1; i < n; i++){
        Node* newNode = new Node(arr[i]);
        temp -> next = newNode;
        temp = newNode;
    }
    
    return head;
}

void printLL(Node* head){
    Node* temp = head;
    
    while(temp -> next != nullptr){
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << temp -> data;
}


int lengthOfLL(Node* head){
    int count = 0;
    Node* temp = head;
    
    while(temp -> next != nullptr){
        count++;
        temp = temp -> next;
    }
    
    return count;
}


bool checkIfPresent(Node* head, int value){
    Node* temp = head;
    
    while(temp -> next != nullptr){
        if(temp -> data == value) return true;
        temp = temp -> next;
    }
    
    return false;
}


//Function to delete the first node i.e head
Node* deleteHead(Node* head){
    head = head -> next;
    return head;
}

//Function to delete the last node i.e tail
void deleteTail(Node* head){
    Node* temp = head;
    Node* prev = temp;
    while(temp -> next != nullptr){
        prev = temp;
        temp = temp -> next;
    }
    
    prev -> next = nullptr;
}


//Function to delete kth element in the linked list, 0 indexed
void deleteKthElement(Node* head, int k){
    Node* temp = head;
    int count = 0;
    
    while(count != k-1){
        temp = temp -> next;
        count++;
    }
    Node* temp1 = temp -> next;
    temp -> next = temp1 -> next;
    temp1 -> next = nullptr;
}


//Function to delete a node with a specific value
void deleteValueElement(Node* head, int value){
    Node* temp = head;
    Node* prev = temp;
    
    while(temp -> data != value){
        prev = temp;
        temp = temp -> next;
    }
    
    prev -> next = temp -> next;
    temp -> next = nullptr;
}


int main(){
    vector<int> arr = {1,2,3,4,5,6};
    Node* head = convertArr2LL(arr);
    // head = deleteHead(head);
    // deleteTail(head);
    // cout << head -> data;
    // deleteKthElement(head, 2);
    deleteValueElement(head, 4);
    printLL(head);
}