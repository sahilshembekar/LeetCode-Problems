/*
Time Complexity = O(N)
 Space Complexity = O(1)
 where N is the number of nodes in the linked list.
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        //Trying to create appropriate gap between slow and fast pointer
        // when when fast is at NULL slow is at the right place for insertion
        // Move fast until we reach the count 
        // When we want to remove the only element from a 1 member LL, we use a dummy node at the start 
        // then start slow and fast from there
        
        ListNode *dummy = new ListNode(-1);
        
        dummy->next = head;
        ListNode *slow = dummy;
        ListNode *fast = dummy; //Start slow and fast at dummy
        
        //to create an appropriate gap
        int count =0;
        while (count <= n) {
            fast = fast->next;
            count++;
        }
        // Once appropriate gap is created traverse to list till fast reaches NULL
        while (fast!= NULL) {
            slow = slow->next;
            fast = fast->next;
        }
        //Now slow at the correct position to skip/remove the next element
        slow->next = slow->next->next;
        
        return dummy->next; // If we use head here it will give error for 1 member link list input because in that we remove the head itself
        
    }
};