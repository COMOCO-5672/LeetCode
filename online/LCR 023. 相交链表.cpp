//
// Created by EDY on 2/6/2024.
//


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == nullptr || headB == nullptr)
        {
            return nullptr;
        }

        auto Alink = headA;
        auto Blink = headB;
        while (Alink != Blink)
        {
            Alink = !Alink ? headB : Alink->next;
            Blink = !Blink ? headA : Blink->next;
        }
        return Alink;
    }
};