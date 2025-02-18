/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
    public:
        ListNode* reverseList(ListNode* head) {
            stack<int> stt;
    
            ListNode* temp = head;
            while(temp != nullptr){ //I need to go till temp is null, because if I stop at temp -> next != nullptr then the last node doesn't get updated.
                stt.push(temp -> val);
                temp = temp -> next;
            }
    
            temp = head;
            while(temp != nullptr){
                temp -> val = stt.top();
                stt.pop();
                temp = temp -> next;
            }
    
            return head;
    
        }
    };
    
    //Brute force - 1 => Doesnt work, you can traverse from behind.
    //So if I'm doing it the usual way first I need two pointers start and end 
    //Then swap it's values until start == end.
    //So first I need to find the end node's position. 
    //Then carry on with the usual stuff.
    
    //Brute Force 2 => Use stack
    //Traverse the list, use a stack and push each values into the stack.
    //Since stack if a lifo data structure, popping the values out of it will give the list in reverse order.
    //TC = O(2N)
    //SC = O(N)
    