/*
Time Complexity = O(N)
Space Complexity = O(1)
Where N is the number of nodes in the linked list.
*/

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
    bool isPalindrome(ListNode* head) {
        //NULL case
        if (head == NULL) {
            return false;
        }
        if (head->next == NULL) {
            return true;
        }
        
        ListNode *slow = head;
        ListNode *fast = head;
        
        while (slow->next != NULL) {
            slow = slow->next;
        }
        slow = head;
        
        //Subproblem 1 find mid
        while(fast->next !=NULL && fast->next->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        //slow is at mid

        fast = reversed(slow->next);
        //slow->next = NULL;
        
        slow = head;
        while(fast!=NULL) {
            if(slow->val != fast->val) {
                return false;
            }
            slow= slow->next;
            fast= fast->next;
        }

        
        return true;
    }
    ListNode* reversed(ListNode* head) {
    //to reverse
    ListNode* prev = NULL;
    ListNode* curr = head;
    ListNode* fast = head->next;
    while (fast != NULL) {
        curr->next = prev;
        prev = curr;
        curr = fast;
        fast = fast->next;
    }
    curr->next = prev; //For the last element
    return curr;    
    }
    
};