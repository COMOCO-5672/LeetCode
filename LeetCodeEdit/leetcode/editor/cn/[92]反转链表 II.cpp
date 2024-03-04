//给你单链表的头指针 head 和两个整数 left 和 right ，其中 left <= right 。请你反转从位置 left 到位置 right 的链
//表节点，返回 反转后的链表 。
//
// 
//
// 示例 1： 
// 
// 
//输入：head = [1,2,3,4,5], left = 2, right = 4
//输出：[1,4,3,2,5]
// 
//
// 示例 2： 
//
// 
//输入：head = [5], left = 1, right = 1
//输出：[5]
// 
//
// 
//
// 提示： 
//
// 
// 链表中节点数目为 n 
// 1 <= n <= 500 
// -500 <= Node.val <= 500 
// 1 <= left <= right <= n 
// 
//
// 
//
// 进阶： 你可以使用一趟扫描完成反转吗？ 
//
// Related Topics 链表 👍 1733 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (head == nullptr || left >= right) return head;

        ListNode dummy(0);
        dummy.next = head;
        ListNode* pre = &dummy; // 反转部分的前一个节点

        // 移动pre到需要反转部分的前一个节点
        for (int i = 1; i < left; ++i) {
            if (pre == nullptr) return nullptr; // 防止pre为空
            pre = pre->next;
        }

        ListNode* start = pre->next; // 反转部分的起始节点
        ListNode* end = start; // 反转部分的结束节点

        // 移动end到需要反转部分的结束节点
        for (int i = left; i < right; ++i) {
            if (end == nullptr) return nullptr; // 防止end为空
            end = end->next;
        }

        // 反转部分
        ListNode* prev = nullptr;
        ListNode* curr = start;
        while (curr != end) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        ListNode* next = end->next;
        end->next = prev;
        start->next = next;
        pre->next = end;

        return dummy.next;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
