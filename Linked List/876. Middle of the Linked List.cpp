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
        ListNode* middleNode(ListNode* head) { 
            ListNode* slow = head;
            ListNode* fast = head;
    
            while(fast != nullptr && fast -> next != nullptr){
                fast = fast -> next -> next;
                slow = slow -> next;
            }
    
            return slow;
        }
    };
    
    // Tortoise & Hare Algorithm
    // Use two pointers slow and fast.
    //Increment fast by 2 times and slow by one time. 
    //By the time fast reaches the end of the list, slow would be in the middle. Common sense.
    //For odd length, list ends when fast -> next == nullptr
    //For even length, list ends when fast == nullptr.
    //It should satisfy both the conditions 
    //TC = O(N/2)
    //SC = O(1)