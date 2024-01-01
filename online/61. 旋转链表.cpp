#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

ListNode *rotateRight(ListNode *head, int k) {
  if (!head || k == 0) {
    return head;
  }

  int length = 1;
  ListNode *tail = head;
  while (tail->next) {
    length++;
    tail = tail->next;
  }

  k = k % length;

  if (k == 0) {
    return head; // 不需要旋转
  }

  ListNode *newHeadPrev = head;
  for (int i = 0; i < length - k - 1; ++i) {
    newHeadPrev = newHeadPrev->next;
  }

  // 新的头结点
  ListNode *newHead = newHeadPrev->next;
  // 断开连接
  newHeadPrev->next = NULL;
  // 将原来的尾部连接到原来的头部
  tail->next = head;
  return newHead;
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

  int k = 2;

  cout << "Original List: ";
  printList(head);

  ListNode *result = rotateRight(head, k);

  cout << "List after rotating right by " << k << " positions: ";
  printList(result);

  // 释放内存
  deleteList(result);
  return 0;
}
