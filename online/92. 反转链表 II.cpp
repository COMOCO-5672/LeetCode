#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *reverseBetween(ListNode *head, int m, int n) {
  if (!head || m == n) {
    // 如果链表为空或反转部分长度为 0，直接返回原链表
    return head;
  }

  // 创建一个虚拟头结点，简化操作
  ListNode *dummy = new ListNode(0);
  dummy->next = head;

  // 定义prev指针指向反转部分的前一个结点
  ListNode *prev = dummy;

  for (int i = 0; i < m - 1; ++i) {
    prev = prev->next;
  }

  ListNode *start = prev->next;
  ListNode *then = start->next;

  for (int i = 0; i < n - m; ++i) {
    start->next = then->next;
    then->next = prev->next;
    prev->next = then;
    then = start->next;
  }

  return dummy->next;
}

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

int main() {
  // 示例用法
  ListNode *head = new ListNode(1);
  head->next = new ListNode(2);
  head->next->next = new ListNode(3);
  head->next->next->next = new ListNode(4);
  head->next->next->next->next = new ListNode(5);

  int m = 2, n = 4;

  cout << "Original List: ";
  printList(head);

  ListNode *reversedHead = reverseBetween(head, m, n);

  cout << "Reversed List between " << m << " and " << n << ": ";
  printList(reversedHead);

  // 释放内存
  deleteList(reversedHead);
  return 0;
}
