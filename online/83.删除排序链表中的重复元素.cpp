/*
 * @lc app=leetcode.cn id=83 lang=cpp
 *
 * [83] 删除排序链表中的重复元素
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

// struct ListNode {
//      int val;
//      ListNode *next;
//      ListNode() : val(0), next(nullptr) {}
//      ListNode(int x) : val(x), next(nullptr) {}
//      ListNode(int x, ListNode *next) : val(x), next(next) {}
// };

#include <iostream>

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head)
        {
            return nullptr;
        }
        std::cout << "start \r\n" << std::endl;
        ListNode* node_ = head;
        ListNode* next_node = head->next;
        while (next_node)
        {
            std::cout << "start1 \r\n" << std::endl;
            if(node_->val == next_node->val)
            {
                std::cout << "val is eq:" << next_node->val << std::endl;
                next_node = next_node->next;
                node_->next = next_node;
                continue;
            }
            std::cout << "val not eq:" << next_node->val << std::endl;
            node_->next = next_node;
            node_ = next_node;
            next_node = next_node->next;
        }
        return head;
    }
};

// int main()
// {
//     std::cout << "hello world";
//     ListNode* node3 = new ListNode(3);
//     ListNode* node2 = new ListNode(2, node3);
//     ListNode* node1 = new ListNode(1, node2);
    
//     Solution a;
//     auto c = a.deleteDuplicates(node1);
//     while (!c)
//     {
//         std::cout << "value " << c->val << "\r\n" << std::endl;
//         c = c->next;
//     }
//     return 0;
// }

// @lc code=end

