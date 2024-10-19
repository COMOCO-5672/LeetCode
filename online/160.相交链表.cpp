/*
 * @lc app=leetcode.cn id=160 lang=cpp
 *
 * [160] 相交链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <vector>

using namespace std;

class Solution {
public:
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    if (!headA || !headB)
      return nullptr;

    ListNode *pA = headA;
    ListNode *pB = headB;

    while (pA != pB) {
      pA = pA ? pA->next : headB;
      pB = pB ? pB->next : headA;
    }

    return pA;
  }
};
// @lc code=end
