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



int main(){
    vector<int> arr = {1,2,3,4,5,6};
    Node* head = convertArr2LL(arr);
    cout << lengthOfLL(head);
    // printLL(head);
}