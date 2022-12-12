/*
Time Complexity = O(NK*LogK)
Space Complexity = O(k)
where k is the number of lists and we are only inserting one element from each list at a time(after removal of one node from queue we add its next to the queue ) then the Space complexity is O(k). 
And also we are traversing NK i.e- N is the average elements in one list, and insertion of node in heap takes logK time. This is how we get Time Complexity od O(NK*Logk).
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
    struct Comp {
        bool operator() (const ListNode* a, const ListNode* b) {
            return a->val > b->val;
        }
    };
    
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // NULL case
        if (lists.size()==0) {
            return NULL;
        }
        priority_queue<ListNode*, vector<ListNode*>, Comp> pq; //min heap using special comp
        for (ListNode* list : lists) {
            // iterate over the lists // we will get the head i.e. start
            if(list != NULL) {
                pq.push(list); // push the head node in the heap
            }
        }
        ListNode* dummy = new ListNode(-1); //dummy at the start of result
        ListNode* curr = dummy; //keep the curr at dummy
        while(!pq.empty()) {
            ListNode* min_element = pq.top(); //smallest element at top
            curr->next = min_element;
            min_element = min_element->next; //move to the next of whichever node we processed
            pq.pop();
            if (min_element != NULL) {
                pq.push(min_element); //push the next element in the heap //it may or may not bubblify
            }
            curr = curr->next;
        }
        return dummy->next;
    }
};

/*
Brute Force approach of merging the lists
Time Complexity = O(N*(square of k))
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* merged = new ListNode(INT_MIN);
        
        for (ListNode* list : lists) {
            merged = merge(merged, list); //merge the lists one by one 
        }
        return merged->next;
    }
    
    ListNode* merge(ListNode* l1, ListNode* l2) { //merging of two Linked List function
        ListNode* dummy = new ListNode(-1); //start at dummy;
        ListNode* curr = dummy; //curr pointer for result
        while (l1 != NULL && l2 != NULL) {
            if (l1->val < l2->val) {
                //means l1 has higher val hence add to result
                curr->next = l1;
                l1 = l1->next;
            }
            else {
                //means l2 has higher val hence add to result
                curr->next = l2;
                l2 = l2->next;
            }
            curr = curr->next; //both the cases we have to move the curr pointer
        }
        //In case we one list finished before the other
        if (l1!=NULL) {
            curr->next = l1; 
            //curr pointer moved in the above while no need to do again
        }
        if (l2!=NULL) {
            curr->next = l2; 
            //curr pointer moved in the above while no need to do again
        }
        return dummy->next;
    }
};