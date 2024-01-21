/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
 */

// @lc code=start

#include <iostream>
#include <vector>

/**
 *
 * Definition for singly-linked list.
 * */
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {

    // 保存其实指针位置
    ListNode *dummy = new ListNode();
    int carry = 0;
    ListNode *cur = dummy;
    while (l1 || l2 || carry) {
      int s = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;
      carry = s / 10;
      cur->next = new ListNode(s % 10);
      cur = cur->next;
      l1 = l1 ? l1->next : nullptr;
      l2 = l2 ? l2->next : nullptr;
    }
    return dummy->next;
  }
};

// int main() {
//   std::vector<int> l1 = {2, 4, 3}, l2 = {5, 6, 4};
//   Solution solu;
//   solu.addTwoNumbers(l1, l2);
//   return 0;
// }

// @lc code=end
