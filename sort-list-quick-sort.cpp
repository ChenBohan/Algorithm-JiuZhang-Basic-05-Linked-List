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
        
        ListNode* tail = getTail(head);
        
        ListNode* dummyLeft = new ListNode(0);
        ListNode* dummyMid = new ListNode(0);
        ListNode* dummyRight = new ListNode(0);
        ListNode* leftTail = dummyLeft;
        ListNode* midTail = dummyMid;
        ListNode* rightTail = dummyRight;
        ListNode* node = head;
        
        while (node != NULL) {
            if (node->val < tail->val) {
                // cout<<"left"<<node->val<<endl;
                leftTail->next = node;
                leftTail = leftTail->next;
            } else if (node->val == tail->val) {
                // cout<<"mid"<<node->val<<endl;
                midTail->next = node;
                midTail = midTail->next;
            } else {
                // cout<<"right"<<node->val<<endl;
                rightTail->next = node;
                rightTail = rightTail->next;
            }
            node = node->next;
        }
        
        leftTail->next = NULL;
        midTail->next = NULL;
        rightTail->next = NULL;
        
        // cout<<"left"<<endl;
        // print(dummyLeft->next);
        // cout<<"mid"<<endl;
        // print(dummyMid->next);
        // cout<<"right"<<endl;
        // print(dummyRight->next);

        ListNode* right = sortList(dummyRight->next);
        ListNode* left = sortList(dummyLeft->next);
        
        return concat(left, dummyMid->next, right);
    }
    
    ListNode* concat(ListNode* left, ListNode* mid, ListNode* right) {
        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;
        tail->next = left;
        tail = getTail(tail);
        tail->next = mid;
        tail = getTail(tail);
        tail->next = right;
        return dummy->next;
    }
    
    ListNode* getTail(ListNode* node) {
        if (node == NULL) {
            return NULL;
        }
        while (node->next != NULL) {
            node = node->next;
        }
        return node;
    }

    void print(ListNode* node) {
        while(node != NULL) {
            cout<<node->val<<"->";
            node = node->next;
        }
        cout<<endl;
    }
};
