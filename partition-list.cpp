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
     * @param head: The first node of linked list
     * @param x: An integer
     * @return: A ListNode
     */
    ListNode * partition(ListNode * head, int x) {
        // write your code here
        if (!head) {
            return NULL;
        }
        ListNode* dummyLeft = new ListNode(0);
        ListNode* dummyRight = new ListNode(0);
        ListNode* right = dummyRight;
        ListNode* left = dummyLeft;
        ListNode* node = head;
        
        while(node) {
            if (node->val < x) {
                left->next = node;
                left = left->next;
            } else {
                right->next = node;
                right = right->next;
            }
            node = node->next;
        }
        right->next = NULL;
        left->next = dummyRight->next;
        return dummyLeft->next;
    }
};
