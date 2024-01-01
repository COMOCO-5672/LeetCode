#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 链表节点的定义
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

// 输出链表
void printList(ListNode *head) {
  while (head) {
    cout << head->val << " ";
    head = head->next;
  }
  cout << endl;
}

// 释放链表内存
void deleteList(ListNode *head) {
  while (head) {
    ListNode *temp = head;
    head = head->next;
    delete temp;
  }
}

ListNode *removeNthFromEnd(ListNode *head, int n) {
  if (!head || n <= 0) {
    return head;
  }

  ListNode *dummy = new ListNode(0);
  dummy->next = head;

  ListNode *fast = dummy;
  ListNode *slow = dummy;

  for (int i = 0; i <= n; ++i) {
    if (!fast) {
      delete dummy;
      return head;
    }
    fast = fast->next;
  }

  while (fast) {
    fast = fast->next;
    slow = fast->next;
  }

  ListNode *temp = slow->next;
  slow->next = slow->next->next;
  delete temp;

  ListNode *result = dummy->next;

  delete dummy;
  return result;
}

int main() {
  // 示例用法
  ListNode *head = new ListNode(1);
  head->next = new ListNode(2);
  head->next->next = new ListNode(3);
  head->next->next->next = new ListNode(4);
  head->next->next->next->next = new ListNode(5);

  int n = 2;

  cout << "Original List: ";
  printList(head);

  ListNode *result = removeNthFromEnd(head, n);

  cout << "List after removing the " << n << "th node from the end: ";
  printList(result);

  // 释放内存
  deleteList(result);
  return 0;
}
