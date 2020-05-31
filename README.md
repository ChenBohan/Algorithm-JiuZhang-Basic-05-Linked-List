# Algorithm-JiuZhang-Basic-05-Linked-List
九章算法基础班 - 链表

### 前言

- 大纲
  - Dummy Node in Linked List
    - 当链表结构可能发生变化 -> head可能变化 -> 需要dummy node
  - Basic Linked List Skills
  - Two Pointers in Linked List (Fast-slow pointers)
- 面试出题频率
  - 链表 > 广度深度优先搜素 > 动态规划
- 链表与数组相比
  - 灵活：可以随意地更改排列顺序，不需要额外的存储空间(in place)
- Basic Skills in Linked List
  - 1. Insert a Node in Sorted List
  - 2. Remove a Node from Linked List
  - 3. Reverse a Linked List
  - 4. Merge Two Linked Lists
  - 5. Middle of a Linked List

### Remove Duplicates from Sorted List II

- [题目](http://www.lintcode.com/problem/remove-duplicates-from-sorted-list-ii/)
- [答案](http://www.jiuzhang.com/solutions/remove-duplicates-from-sorted-list-ii/)
- Dummy Node
  - 加上一个dummy node在head之前，方便删除原head并return
  
```cpp
ListNode* dummyNode = new ListNode(0);
dummyNode->next = head;

ListNode* previous = dummyNode;
ListNode* current = dummyNode->next;

...

return dummyNode->next;
```

- 访问`.next`前要检查其是否存在
```cpp
while (current) {
    if (current->next && current->val == current->next->val) {
        int val = current->val;
        while (current && current->val == val) {
            current = current->next;
        }
     ...
```

### Reverse Linked List
- [题目](http://www.lintcode.com/problem/reverse-linked-list/)
- [答案](http://www.jiuzhang.com/solutions/reverse-linked-list/)
- 返回值应以NULL结尾，所以previous一开始要指向NULL
```cpp
ListNode* previous = NULL;
ListNode* current = head;
```
- 注意最后的返回值为previous
```cpp
return previous;
```

### Reverse Linked List II
- [题目](http://www.lintcode.com/problem/reverse-linked-list-ii/)
- [答案](http://www.jiuzhang.com/solutions/reverse-linked-list-ii/)
- 思路
  - 找到第m-1个Node
  - 翻转指定区间的链表
  - connect m-1 to n, m to n+1
  - 返回dummy node的下一个节点。
- 注意
  - 开头要排除`m == n`的情况
```cpp
if (!head || m >= n) {
    return head;
}
```
  - 要加上dummy node
  - 不访问node->next->val时，node->next可以为NULL

### Partition List
- [题目](http://www.lintcode.com/problem/partition-list/)
- [答案](http://www.jiuzhang.com/solutions/partition-list/)
- 思路
  - 双指针方法，用两个指针将两个部分分别串起来。最后在将两个部分拼接起来。
    - left指针用来串起来所有小于x的结点，
    - right指针用来串起来所有大于等于x的结点。
    - 得到两个链表，一个是小于x的，一个是大于等于x的，做一个拼接即可。
```cpp
ListNode* dummyLeft = new ListNode(0);
ListNode* dummyRight = new ListNode(0);
ListNode* right = dummyRight;
ListNode* left = dummyLeft;
...
right->next = NULL;
left->next = dummyRight->next;
return dummyLeft->next;
```
- 注意
  - return前要检查链表末尾是否为NULL
```cpp
right->next = NULL;
```

### sort-list

- [题目](https://www.lintcode.com/problem/sort-lis/description)
- O(nlogn)的排序方法
  - quick sort（要掌握）
    - 先整体有序，再局部有序
    - 不稳定，不能保持原相对顺序
    - 时间复杂度平均为O(nlogn)，最坏情况为O(n^2)
    - 空间复杂度O(1)
  - merge sort（要掌握）
    - 先局部有序，再整体有序
    - 稳定排序，能保持相对顺序
    - 时间复杂度，最好最坏都是O(nlogn)
    - 空间复杂度O(n)
  - heap sort
- Merge Sort基本步骤
  - 0.因为递归，所以先判断递归中止条件
    ```cpp
    if (head == NULL || head->next == NULL) {
      return head;
    }
    ```
  - 1.中间切一刀，分为左右两边
    - 求中点：
      - 数组：用中间下标
      - List：快慢指针
        - `fast = head`或`fast = head->next`决定了偶数个点时偏左或者偏右
        ```cpp
        ListNode* findMiddle(ListNode* head) {
          ListNode* slow = head;
          ListNode* fast = head->next;
          if (fast != NULL && fast->next != NULL) {
              fast = fast->next->next;
              slow = slow->next;
          }
          return slow;
        }
        ```
  - 2.递归地sort左右数组（分治法的思想）
    ```cpp
    public ListNode sortList(ListNode head) {
      if (head == null || head.next == null) {
          return head;
      }

      ListNode mid = findMiddle(head);

      ListNode right = sortList(mid.next);
      mid.next = null;
      ListNode left = sortList(head);

      return merge(left, right);
    }
    ```
  - 3.merge数组
    - 设置dummy node `tail`
    - 依次比较两个数组的节点，谁小谁接到tail的list上
    - 直到某一个链表空了以后，把剩下的都接上去
      ```cpp
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
      ```
- quick sort
  - 快排思路
    ```cpp
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

    ListNode* right = sortList(dummyRight->next);
    ListNode* left = sortList(dummyLeft->next);

    return concat(left, dummyMid->next, right);
    ```
  - 注意
    - concat函数要考虑left\mid\right任意一个为NULL的情况
      ```cpp
      ListNode* concat(ListNode* left, ListNode* mid, ListNode* right) {
        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;
        tail->next = left;
        tail = getTail(tail);
        tail->next = mid;
        tail = getTail(tail);
        tail->next = right;### Reorder List
        return dummy->next;
      }
      ```

### Reorder List

- [题目](http://www.lintcode.com/problem/reorder-list/)
- [答案](http://www.jiuzhang.com/solutions/reorder-list/)
- 思路
  - 先找到中点，然后把后半段倒过来，然后前后交替合并
    - reverse：先用temp存head->next，然后让head->next指向head（newNode协助），最后移动至head->next即temp
      ```cpp
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
      ```
    - merge
      ```cpp
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
      ```
