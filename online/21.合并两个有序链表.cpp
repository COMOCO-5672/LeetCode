/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 */

#include <iostream>

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
    // 创建一个虚拟头结点
    ListNode *dummy = new ListNode(0);
    // 创建一个指针用于遍历合并后的链表
    ListNode *current = dummy;

    // 遍历两个链表
    while (list1 && list2) {
      if (list1->val < list2->val) {
        current->next = list1;
        list1 = list1->next;
      } else {
        current->next = list2;
        list2 = list2->next;
      }
      current = current->next;
    }

    if (list1) {
      current->next = list1;
    } else {
      current->next = list2;
    }

    return dummy->next;
  }
};

int main() {
  ListNode *l1 = new ListNode(1);
  l1->next = new ListNode(2);
  l1->next->next = new ListNode(4);

  ListNode *l2 = new ListNode(1);
  l2->next = new ListNode(3);
  l2->next->next = new ListNode(4);

  Solution sol;
  ListNode *merged = sol.mergeTwoLists(l1, l2);

  // 输出合并后的链表
  while (merged) {
    std::cout << merged->val << " ";
    merged = merged->next;
  }
  return 0;
}

// @lc code=end
