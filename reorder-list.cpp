/**
 * Definition of singly-linked-list:
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *        this->val = val;
 *        this->next = NULL;
 *     }
 * }
 */

class Solution {
public:
    /**
     * @param head: The head of linked list.
     * @return: nothing
     */
    void reorderList(ListNode * head) {
        // write your code here
        auto reverse = [](ListNode* head){
            ListNode* newNode = NULL;
            while (head) {
                ListNode* temp = head->next;
                head->next = newNode;
                newNode = head;
                head = temp;
            }
            return newNode;
        };
        
        auto findMid = [](ListNode* head){
            ListNode* slow = head;
            ListNode* fast = head->next;
            while (fast != NULL && fast->next != NULL) {
                slow = slow->next;
                fast = fast->next->next;
            }
            return slow;
        };
        
        auto merge = [](ListNode* head, ListNode* tail) {
            int index = 0;
            ListNode* dummy = new ListNode(0);
            cout<<head->val<<" "<<tail->val;
            while(head != NULL && tail != NULL) {
                if (index % 2 == 0){
                    dummy->next = head;
                    head = head->next;
                } else {
                    dummy->next = tail;
                    tail = tail->next;
                }
                dummy = dummy->next;
                index++;
            }
            if (head != NULL) {
                dummy->next = head;
            }
            if (tail != NULL) {
                dummy->next = tail;
            }
        };
        
        if (head == NULL || head->next == NULL)
            return;
            
        ListNode* mid = findMid(head);
        ListNode* tail = reverse(mid->next);
        mid->next = NULL;
        merge(head, tail);
    }
};
