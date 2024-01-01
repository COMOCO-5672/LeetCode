#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 使用快慢指针，如果链表中有环，快指针会追上慢指针。

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

bool hasCycle(ListNode *head) {
  if (!head || !head->next) {
    // 空链表或只有一个节点的链表不可能有环
    return false;
  }

  ListNode *slow = head;       // 慢指针
  ListNode *fast = head->next; // 快指针

  while (slow != fast) {
    if (!fast || !fast->next) {
      // 如果快指针或快指针的下一个节点为空，说明链表没有环
      return false;
    }

    // 慢指针一次走一步，快指针一次走两步
    slow = slow->next;
    fast = fast->next->next;
  }
  // 如果退出循环，说明快指针追上了慢指针，链表有环
  return true;
}

int main() {
  ListNode *head1 = new ListNode(3);
  head1->next = new ListNode(2);
  head1->next->next = new ListNode(0);
  head1->next->next->next = new ListNode(-4);
  head1->next->next->next->next = head1->next; // 构成环

  cout << (hasCycle(head1) ? "true" : "false") << endl; // 输出 true

  ListNode *head2 = new ListNode(1);
  head2->next = new ListNode(2);
  head2->next->next = head2; // 构成环

  cout << (hasCycle(head2) ? "true" : "false") << endl; // 输出 true

  ListNode *head3 = new ListNode(1);

  cout << (hasCycle(head3) ? "true" : "false") << endl; // 输出 false

  return 0;
}
