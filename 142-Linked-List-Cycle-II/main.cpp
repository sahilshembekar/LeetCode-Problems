 // Time Complexity = O(N)
 // Space Complexity = O(1)
 // Where N is the number of nodes in the linked list.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *fast = head;
        ListNode *slow = head;
        bool flag = false; // we do this because we dont know if we have a cycle or not
        if (head == NULL){
            return NULL;
        }
        while (fast!=NULL && fast->next != NULL) {
            slow = slow->next;  //1x speed
            fast = fast->next->next; //2x speed
            if (slow == fast) {
                flag = true;
                break;
            }
        }
        if (!flag) { // The cycle does not exist
            return NULL;
        }
        // if the cycle exists
        fast = head; // Put the fast at the head and restart
        while (slow!= fast) {
            slow = slow->next;
            fast = fast->next; // both at 1x speed
        }
        
        return slow; // the point where they meet is start of the cycle // can also return fast
        
    }
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 Time Complexity = O(N)
 Space Complexity = O(1)
 Where N is the number of nodes in the linked list.
 */
//Without flag?
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *fast = head;
        ListNode *slow = head;
        if(head==NULL || head->next==NULL)
            return NULL;
        slow = slow->next;
        fast = fast->next->next;
        while(fast!=slow && fast!=NULL && fast->next!=NULL)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        if(fast==NULL || fast->next==NULL)
            return NULL;
        else
        {
            fast = head;
            while(fast!=slow)
            {
                fast = fast->next;
                slow = slow->next;
            }
            return slow;
        }
    }
};


