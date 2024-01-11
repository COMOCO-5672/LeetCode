#include <queue>

using namespace std;

int main() {
  // 不写后面两个参数默认为vector，less
  priority_queue<int> pq1;
  // 建立一个优先级队列(大堆)，数据类型是int，利用vector容器实现，less（降序）实现
  priority_queue<int, vector<int>, less<int>> pq2;
  // 建立一个优先级队列(小堆)，数据类型是int，利用vector容器实现，greater（降序）实现
  priority_queue<int, vector<int>, greater<int>> pq3;

  return 0;
}
