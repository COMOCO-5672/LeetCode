#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// 在这个问题中，由于节点可能会指向之前的节点，所以我们不能直接按顺序创建节点。
// 我们可以通过哈希表来保存原节点和新节点的对应关系，以处理随机指针的指向。

// Definition for a Node.
class Node {
public:
  int val;
  Node *next;
  Node *random;

  Node(int _val) {
    val = _val;
    next = NULL;
    random = NULL;
  }
  Node *copyRandomList(Node *head) {
    if (!head) {
      return NULL;
    }

    unordered_map<Node *, Node *> nodeMap;

    Node *current = head;
    while (current) {
      nodeMap[current] = new Node(current->val);
      current = current->next;
    }

    // 第二遍遍历：设置新节点的next和random指针
    current = head;
    while (current) {
      nodeMap[current]->next = nodeMap[current->next];
      nodeMap[current]->random = nodeMap[current->random];
      current = current->next;
    }
    return nodeMap[head];
  }

  void printList(Node *head) {
    while (head) {
      cout << "[" << head->val << ",";
      if (head->random) {
        cout << head->random->val;
      } else {
        cout << "null";
      }

      cout << "]";
      head = head->next;
    }
    cout << endl;
  }
};

int main() { return 0; }
