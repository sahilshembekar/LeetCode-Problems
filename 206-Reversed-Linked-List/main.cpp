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
    ListNode* reverseList(ListNode* head) {
        if (head == NULL || head->next == NULL) { // Important to add this condition will throw an error otherwise for
            // and empty Linked list where the head is pointed to NULL and head->next isnt there
            return head;
        }
        // 3pointer Appproach
        ListNode *prev = NULL;
        ListNode *curr = head;
        ListNode *fast = head->next;
        
        while (fast!= NULL) {
            curr->next = prev;
            prev = curr;
            curr = fast;
            fast = fast->next;
        }
        //At the end curr will be on the last element point its next to the prev element
        curr->next = prev;
        return curr; //head of the reversed LL
    }
};


//Can also be done by using a dummy head
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* head1 = new ListNode(0);
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next = NULL;
        while(curr!=NULL)
        {
            next=curr->next;
            curr->next = prev;
            prev = curr;
            curr=next;
        }
        head1 = prev;
        return head1;
    }
};
/*

 Time Complexity = O(N)
 Space Complexity = O(N)
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
    ListNode* reverseList(ListNode* head) {
        //base case
        if (head == NULL || head->next == NULL) {
            return head;
        }
        
        //logic
        ListNode *reversed = reverseList(head->next);
        
        head->next->next = head;
        head->next = NULL;
        return reversed;
    }
};