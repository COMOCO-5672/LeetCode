#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// cloneGraph
// 函数用于深度优先搜索，创建节点的克隆，并递归克隆邻居节点。deleteGraph
// 函数用于释放图的内存
class Node {
public:
  int val;
  vector<Node *> neighbors;

  Node(int _val) {
    val = _val;
    neighbors = vector<Node *>();
  }
};

unordered_map<Node *, Node *> cloneMap;

Node *cloneGraph(Node *node) {
  if (!node) {
    return nullptr;
  }

  if (cloneMap.find(node) != cloneMap.end()) {
    return cloneMap[node];
  }

  Node *cloneNode = new Node(node->val);

  cloneMap[node] = cloneNode;

  for (Node *neighbor : node->neighbors) {
    cloneNode->neighbors.emplace_back(cloneGraph(neighbor));
  }
  return cloneNode;
}

// 释放图的内存
void deleteGraph(Node *node) {
  if (!node) {
    return;
  }

  // 递归释放邻居节点
  for (Node *neighbor : node->neighbors) {
    deleteGraph(neighbor);
  }

  // 释放当前节点
  delete node;
}

// 释放图的内存
void deleteGraph(Node *node) {
  if (!node) {
    return;
  }

  // 递归释放邻居节点
  for (Node *neighbor : node->neighbors) {
    deleteGraph(neighbor);
  }

  // 释放当前节点
  delete node;
}

int main() {
  // 示例用法
  Node *node1 = new Node(1);
  Node *node2 = new Node(2);
  Node *node3 = new Node(3);
  Node *node4 = new Node(4);

  node1->neighbors = {node2, node4};
  node2->neighbors = {node1, node3};
  node3->neighbors = {node2, node4};
  node4->neighbors = {node1, node3};

  // 在这里可以进行克隆图后的操作
  Node *clonedNode = cloneGraph(node1);

  // 释放内存
  deleteGraph(node1);
  deleteGraph(clonedNode);
  return 0;
}
