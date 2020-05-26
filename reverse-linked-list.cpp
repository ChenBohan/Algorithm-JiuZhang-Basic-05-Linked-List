/**
 * Definition of singly-linked-list:
 *
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
     * @param head: n
     * @return: The new head of reversed linked list.
     */
    ListNode * reverse(ListNode * head) {
        ListNode* previous = NULL;
        ListNode* current = head;
        while(current) {
            ListNode* tmp = current->next;
            current->next = previous;
            previous = current;
            current = tmp;
        }
        return previous;
    }
};
