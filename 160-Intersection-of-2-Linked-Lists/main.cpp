/* 
Time Complexity = O(N)
 Space Complexity = O(1)
 where N is the number of nodes in the linked lists.
 */
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* tempA = headA;
        ListNode* tempB = headB;
        while(tempA!=tempB)
        {
            if(tempA==NULL)
                tempA=headB;
            else
                tempA=tempA->next;
            
            if(tempB==NULL)
                tempB=headA;
            else
                tempB=tempB->next;
        }
        return tempA;
    }
};


/* 
Time Complexity = O(N)
 Space Complexity = O(1)
 where N is the number of nodes in the linked lists.
 */

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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* Curr = headA;
        int lenA = 0;
        while (Curr != NULL) {
            Curr = Curr->next;
            lenA++; //Counter to get the length of LL A
        }
        Curr = headB;
        int lenB = 0;
        while (Curr != NULL) {
            Curr = Curr->next;
            lenB++; //Counter to get the length of LL B
        }    
        while (lenA > lenB) {
            headA = headA->next;
            lenA--; //Skipping the elements till we have equal number of elements from end of the LL for LL a and b
        }
        while (lenB > lenA) {
            headB = headB->next;
            lenB--; //Skipping the elements till we have equal number of elements from end of the LL for LL a and b
        }
        
        while (headA != headB) {
            headA = headA->next;
            headB = headB->next; //Move the heads until the heads point to the same Node i.e the intersection point
        }
        return headA; //headB also OK, both at the same location
            
    }
};