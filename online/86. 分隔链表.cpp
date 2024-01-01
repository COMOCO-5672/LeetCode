#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

ListNode *partition(ListNode *head, int x) {
  ListNode *beforeHead = new ListNode(0);
  ListNode *afterHead = new ListNode(0);

  ListNode *before = beforeHead;
  ListNode *after = afterHead;

  while (head) {
    if (head->val < x) {
      before->next = head;
      before = before->next;
    } else {
      after->next = head;
      after = after->next;
    }
    head = head->next;
  }

  before->next = afterHead->next;
  after->next = NULL;

  ListNode *result = beforeHead->next;

  delete beforeHead;
  delete afterHead;
  return result;
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
  head->next = new ListNode(4);
  head->next->next = new ListNode(3);
  head->next->next->next = new ListNode(2);
  head->next->next->next->next = new ListNode(5);
  head->next->next->next->next->next = new ListNode(2);

  int x = 3;

  cout << "Original List: ";
  printList(head);

  ListNode *result = partition(head, x);

  cout << "List after partitioning around " << x << ": ";
  printList(result);

  // 释放内存
  deleteList(result);
  return 0;
}
