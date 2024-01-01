#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

// 释放链表内存
void deleteList(ListNode *head) {
  while (head) {
    ListNode *temp = head;
    head = head->next;
    delete temp;
  }
}

// 输出链表
void printList(ListNode *head) {
  while (head) {
    cout << head->val << " ";
    head = head->next;
  }
  cout << endl;
}

// 反转链表的函数
ListNode *reverse(ListNode *head) {
  ListNode *prev = NULL;
  ListNode *current = head;

  while (current) {
    ListNode *next = current->next;
    current->next = prev;
    prev = current;
    current = next;
  }

  return prev;
}

ListNode *reverseKGroup(ListNode *head, int k) {
  if (!head || k == 1) {
    return head;
  }

  ListNode *dummy = new ListNode(0);
  dummy->next = head;

  ListNode *prev = dummy;

  while (prev->next) {
    ListNode *start = prev->next;
    ListNode *end = prev->next;

    for (int i = 0; i < k - 1 && end; ++i) {
      end == end->next;
    }

    if (!end) {
      break;
    }

    ListNode *next = end->next;
    end->next = NULL;

    prev->next = reverse(start);
    start->next = next;
    prev = start;
  }

  return dummy->next;
}

int main() {
  // 示例用法
  ListNode *head = new ListNode(1);
  head->next = new ListNode(2);
  head->next->next = new ListNode(3);
  head->next->next->next = new ListNode(4);
  head->next->next->next->next = new ListNode(5);

  int k = 2;

  cout << "Original List: ";
  printList(head);

  ListNode *reversedHead = reverseKGroup(head, k);

  cout << "Reversed List in groups of " << k << ": ";
  printList(reversedHead);

  // 释放内存
  deleteList(reversedHead);
  return 0;
}
