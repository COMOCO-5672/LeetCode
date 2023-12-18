#include <iostream>
#include <vector>

using namespace std;

// 贪心法，遍历整个节点，如果遇见油量小于里程的，重新计算位置
int canComplateCircuit(std::vector<int> &gas, std::vector<int> &cost) {
  int totalGas = 0;
  int currentGas = 0;
  int startStation = 0;

  for (int i = 0; i < gas.size(); ++i) {
    totalGas += gas[i] - cost[i];
    currentGas += gas[i] - cost[i];

    // 如果当前油量小于0，说明无法从当前加油站出发
    // 重置起始加油站，并重置当前油量
    if (currentGas < 0) {
      startStation = i + 1;
      currentGas = 0;
    }
  }

  // 如果总油量小于0，说明无法绕一圈
  return (totalGas >= 0) ? startStation : -1;
}

int main() {

  std::vector<int> gas = {1, 2, 3, 4, 5};
  std::vector<int> cost = {3, 4, 5, 1, 2};
  int start = canComplateCircuit(gas, cost);
  std::cout << "a:" << start << std::endl;
  return 0;
}
