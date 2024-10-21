/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* dump = new ListNode(0);
        dump->next = head;
        ListNode* prev = dump;

        while (prev->next && prev->next->next)
        {
            ListNode* frist = prev->next;
            ListNode* second = prev->next->next;

            frist->next = second->next;
            second->next = frist;

            prev->next = second;
            prev = frist;
        }
        return dump->next;   
#if 0

    // 更简洁，但是不推荐，因为对指针在切换的时候容易混淆，不利于思想扩展
         if (!head || !head->next) return head;
        
        ListNode* newHead = head->next;
        head->next = swapPairs(newHead->next);
        newHead->next = head;
        
        return newHead;
#endif
    }
};
// @lc code=end

