# Algorithm-JiuZhang-Basic-05-Linked-List
九章算法基础班 - 链表

### 前言

- 面试出题频率
  - 链表 > 广度深度优先搜素 > 动态规划
- 大纲
  - Dummy Node in Linked List
  - Basic Linked List Skills
  - Two Pointers in Linked List (Fast-slow pointers)

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
eturn previous;
```
