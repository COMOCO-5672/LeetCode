//����C++ʵ�ֹ�����������㷨��������������ϵ
//���ߣ�cclplus ���䣺707101557@qq.com
//�������������·�����
//�������Ϊ�����������б�Ҫ�ģ��ҵ�֧�����˺�Ҳ��707101557@qq.com
#include<iostream>
#include<vector>
#include<queue>
#include<memory.h>
 
using namespace std;
 
vector<vector<int>> tree;//����һ����ά����
int flag[10];//�����������˽ڵ�i�ĵڼ����ڵ�
queue<int> M;//����һ������
int ar_tree[8] = { 1,1,1,3,5,3,5,7 };
void BFS(int node) {
	int temp;
	cout << node << " ";
	//�Ӷ�����ȡ����һ���ڵ�
	int m_first = M.front();
	M.pop();
	while(flag[node] < tree[node].size()) {
		temp = tree[node][flag[node]];
		flag[node]++;
		//��temp���������
		M.push(temp);
	}
	if (!M.empty()) {
		BFS(M.front());
	}
}
int main() {
	ios::sync_with_stdio(false);
	memset(flag, 0, sizeof(flag));
	int i,temp;
	tree.resize(10);//ͼ�е������оŸ��ڵ�
	//������
	for (i = 2; i <=9; i++) {
		temp = ar_tree[i - 2];
        cout << "temp:" << temp << " i:" << i <<endl;
		tree[temp].push_back(i);//��ʾ��i���ڵ�Ϊ��temp���ڵ���ӽڵ�
	}
	//BFS
	cout << "BFS���̣�" << endl;
	M.push(1);
	BFS(1);
	cout << endl;
	return 0;
}