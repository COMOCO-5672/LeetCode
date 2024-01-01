#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// 删除重复节点的函数
void deleteDuplicateNodes(ListNode *node) {
  while (node) {
    ListNode *temp = node;
    node = node->next;
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

// 释放链表内存
void deleteList(ListNode *head) {
  while (head) {
    ListNode *temp = head;
    head = head->next;
    delete temp;
  }
}

ListNode *deleteDuplicates(ListNode *head) {
  if (!head || !head->next) {
    return head;
  }

  // 创建一个虚拟头节点，简化操作
  ListNode *dummy = new ListNode(0);
  dummy->next = head;

  // 定义指针prev，指向当前不重复的节点
  ListNode *prev = dummy;

  while (prev->next) {
    ListNode *current = prev->next;

    // 找到当前节点的最后一个重复节点
    while (current->next && current->next->val == current->val) {
      current = current->next;
    }

    if (prev->next != current) {
      prev->next = current->next;
      deleteDuplicates(current);
    } else {
      prev = prev->next;
    }
  }

  ListNode *result = dummy->next;
  delete dummy;
  return result;
}

int main() {
  ListNode *head = new ListNode(1);
  head->next = new ListNode(2);
  head->next->next = new ListNode(3);
  head->next->next->next = new ListNode(3);
  head->next->next->next->next = new ListNode(4);
  head->next->next->next->next->next = new ListNode(4);
  head->next->next->next->next->next->next = new ListNode(5);

  cout << "Original List: ";
  printList(head);

  ListNode *result = deleteDuplicates(head);

  cout << "List after deleting duplicates: ";
  printList(result);

  // 释放内存
  deleteList(result);
  return 0;
}
