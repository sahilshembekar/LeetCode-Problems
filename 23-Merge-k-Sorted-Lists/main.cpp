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

