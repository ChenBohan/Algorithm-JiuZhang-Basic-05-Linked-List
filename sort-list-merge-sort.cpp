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
     * @return: You should return the head of the sorted linked list, using constant space complexity.
     */
    ListNode * sortList(ListNode * head) {
        // write your code here
        if (head == NULL || head->next == NULL) {
            return head;
        }
        
        ListNode* midNode = findMiddle(head);
        ListNode* right = midNode->next;
        midNode->next = NULL;
        ListNode* left = head;
        
        left = sortList(left);
        right = sortList(right);
        
        return merge(left, right);
    }
    
    ListNode* findMiddle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;
        if (fast != NULL && fast->next != NULL) {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
    
    ListNode* merge(ListNode* left, ListNode* right) {
        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;
        
        while(left != NULL && right != NULL) {
            if (left->val < right->val) {
                tail->next = left;
                left = left->next;
            } else {
                tail->next = right;
                right = right->next;
            }
            tail = tail->next;
        }
        if (left != NULL) {
            tail->next = left;
        } else {
            tail->next = right;
        }
        return dummy->next;
    }
};
