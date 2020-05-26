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
 
#include <iostream>

class Solution {
public:
    /**
     * @param head: ListNode head is the head of the linked list
     * @param m: An integer
     * @param n: An integer
     * @return: The head of the reversed ListNode
     */
    ListNode * reverseBetween(ListNode * head, int m, int n) {
        if (!head || m >= n) {
            return head;
        }
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;
        ListNode* curt = head;
        
        // find m-1 th node
        for (int i = 1; i < m; i++) {
            if (!curt) {
                return NULL;
            }
            prev = curt;
            curt = curt->next;
        }
        ListNode* m_minus_1 = prev;
        ListNode* m_th = curt;
        // std::cout<<"m_minus_1: "<<m_minus_1->val<<std::endl;
        // std::cout<<"m_th: "<<m_th->val<<std::endl;
        print(head);
        if (!curt) {
            return NULL;
        }
        prev = curt;
        curt = curt->next;  // now curt is point to m + 1 th
        
        // reverse m - n
        for(int i = m; i < n; i++) {
            if (!curt) {
                return NULL;
            }
            // std::cout<<prev->val<<" "<<curt->val<<std::endl;
            ListNode* tmp = curt->next;
            curt->next = prev;
            prev = curt;
            curt = tmp;
        }
         // now curt is point to n + 1 th
        ListNode* n_th = prev;
        ListNode* n_plus_1 = curt;
        std::cout<<"n_th: "<<n_th->val<<std::endl;
        // std::cout<<"n_plus_1: "<<n_plus_1->val<<std::endl;
        // std::cout<<n_th->next->val<<std::endl;
        
        // connect m-1 to n, m to n+1
        m_minus_1 -> next = n_th;
        m_th->next = n_plus_1;
        // print(head);
        
        return dummy->next;
    }
    void print(ListNode* head){
        while(head) {
            cout<<head->val<<"->";
            head = head->next;
        }
        cout<<endl;
    }
};
