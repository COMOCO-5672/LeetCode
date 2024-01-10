#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

double
dfs(std::string current, std::string tartget,
    unordered_map<std::string, unordered_map<std::string, double>> &graph,
    unordered_map<std::string, bool> &visited) {

  // 如果当前节点已经访问过，说明存在循环
  if (visited[current]) {
    return -1.0;
  }

  // 如果当前节点就是目标节点，返回1.0
  if (current == tartget) {
    return 1.0;
  }

  // 标记当前节点为已访问
  visited[current] = true;

  // 遍历当前节点的邻居节点
  for (auto neighbor : graph[current]) {
    double result = dfs(neighbor.first, tartget, graph, visited);
    // 如果在邻居节点中找到有效结果，返回当前节点到目标节点的结果
    if (result != -1.0) {
      return result * graph[current][neighbor.first];
    }
  }
  // 如果在邻居节点中没有找到有效结果，返回-1.0
  return -1.0;
}

vector<double> calcEquation(vector<vector<std::string>> &equations,
                            vector<double> &values,
                            vector<vector<std::string>> &queries) {
  unordered_map<std::string, unordered_map<std::string, double>> graph;

  // 构建图
  for (int i = 0; i < equations.size(); ++i) {
    std::string from = equations[i][0];
    std::string to = equations[i][1];

    double value = values[i];

    graph[from][to] = value;
    graph[to][from] = 1.0 / value;
  }

  vector<double> results;

  // 处理每个查询
  for (auto query : queries) {
    std::string start = query[0];
    std::string end = query[1];

    // 如果查询中的节点在图中不存在，直接返回-1.0
    if (graph.find(start) == graph.end() || graph.find(end) == graph.end()) {
      results.push_back(-1.0);
      continue;
    }

    // 初始化 visited 标记
    unordered_map<std::string, bool> visited;
    for (auto &node : graph) {
      visited[node.first] = false;
    }

    // 进行深度优先搜索
    double result = dfs(start, end, graph, visited);
    results.emplace_back(result);
  }
  return results;
}

int main() {
  // 示例用法
  vector<vector<string>> equations = {{"a", "b"}, {"b", "c"}};
  vector<double> values = {2.0, 3.0};
  vector<vector<string>> queries = {
      {"a", "c"}, {"b", "a"}, {"a", "e"}, {"a", "a"}, {"x", "x"}};

  vector<double> results = calcEquation(equations, values, queries);

  cout << "Results: ";
  for (double result : results) {
    cout << result << " ";
  }
  cout << endl;
  return 0;
}
