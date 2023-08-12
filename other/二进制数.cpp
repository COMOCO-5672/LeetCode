/*
问题：
大家都知道，数据在计算机中存储是以二进制的形式存储的。
有一天，小明学了C语言之后，他想知道一个类型为unsigned int 类型的数字，存储在计算机中的二进制串是什么样子的。
你能帮帮小明吗？并且，小明不想要二进制串中前面没有意义的0串，即要去掉前导0.
输入：
第一行，一个数字T（T <= 1000），表示下面要求的数字的个数。
接下来有T行，每行有一个数字n（0 <= n <= 10 ^ 8），表示要求的二进制串。
输出：
输出共T行。每行输出求得的二进制串。
样例输入：
5
23
535
2624
56275
989835
样例输出：
10111
1000010111
101001000000
1101101111010011
11110001101010001011

基本操作函数：
Itoa(int Num,int R) 十进制转任意进制（Int to All Radix）参数：十进制数Num,进制R 作用：利用除留余数法，返回逆序的余数，即返回所要转换的进制数
功能实现函数：
ToAll() 十进制转任意进制 调用函数Itoa
*/
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<string>
#include<set>
#include<list>
#include<vector>
#include<map>
#include<iterator>
#include<algorithm>
#include<bitset>
#include<sstream>
#include<iostream>
using namespace std;
#define Max 100
//**************************************基本操作函数**********************************//
//十进制转任意进制（Int to All Radix）参数：十进制数Num,进制R 作用：利用除留余数法，返回逆序的余数，即返回所要转换的进制数
string Itoa(unsigned int Num, int R)
{
	string remain = "";
	int temp;
	do {
		temp = Num%R;//取余
		Num /= R;
		if (temp >= 10)
			remain += temp - 10 + 'A';//任意进制为大于基数大于10的进制 例如，十六进制
		else remain += temp + '0';
	} while (Num);
	reverse(remain.begin(), remain.end());//逆序
	return remain;
}
//**************************************功能实现函数**********************************//
//十进制转任意进制 调用函数Itoa,自带的itoa
void ToAll()
{
	unsigned int num;char str[Max];
	cin >> num;
	cout << Itoa(num, 2) << endl;
	//cout << itoa(num, str, 2) << endl;
}
//主函数
int main()
{
	int T = 0;
	string S;
	scanf("%d", &T);
	while (T--)
	{
	  ToAll();
	}
	return 0;
}