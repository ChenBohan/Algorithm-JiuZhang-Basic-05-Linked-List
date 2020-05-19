# Algorithm-JiuZhang-Basic-05-Linked-List
九章算法基础班 - 链表

### 前言

- 面试出题频率
  - 链表 > 广度深度优先搜素 > 动态规划
- 链表与数组相比
  - 灵活：可以随意地更改排列顺序，不需要额外的存储空间(in place)
- 大纲
  - Dummy Node in Linked List
    - 当链表结构可能发生变化 -> head可能变化 -> 需要dummy node
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
