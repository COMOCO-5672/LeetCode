#include <iostream>
#include <istream>

using namespace std;

#define MaxVexNum 100 // 顶点最大的值

typedef char VerTexData; // 顶点的数据类型
typedef int EdgeData; // 边权值的类型
typedef struct node // 边节点
{
    int dest; // 目标节点的位置
    EdgeData cost; // 边的权值
    struct node *link; // 下一边链接指针
} EdgeNode;

typedef struct tex_node // 顶点节点
{
    VerTexData data; // 顶点数据域
    EdgeData *adj; // 边链表头指针
} VerTexNode;

typedef struct adj_graph // 图的邻接表
{
    VerTexNode  vexList[MaxVexNum]; // 邻接表
    int n, e; // 图中当前的顶点个数与边数
} AdjGraph;

void CreatGraph(AdjGraph &g) // 创建邻接表
{
    int tail, head, weight;
    std::cout << "输入图的顶点数和边数" << std::endl;
    std::cin << g.n << g.e;
    std::cout << "输入顶点:\n" ;

    for (int i = 0; i < g.n;i++) // 输入顶点信息
    {
        std::cin >> g.vexList[i].data;
        g.vexList[i].adj = NULL;
    }

    std::cout << "逐条边输入，分别输入尾，头，权重:\n";

    for (int i = 0; i < g.e; i++)
    {
        std::cin >> tail >> head >> weight; // 逐条边输入
        EdgeNode  *p = new EdgeNode;
        p->dest = head;
        p->cost = weight;
        p->link = g.vexList[tail].adj;
        g.vexList[tail].adj = p;
    }
}

void ShowGraph(AdjGraph g) // 输出邻接表
{
    for (int i = 0; i < g.n; i++)
    {
        std::cout << g.vexList[i].data;
        EdgeNode *p = g.vexList[i].adj;
        while(p != NULL)
        {
            std::cout << "->(" << p->dest << "," << p->cost << ")";
            p = p->link;
        }
        std::cout << "\n";
    }
}

int main()
{
    AdjGraph G;
    CreatGraph(G);
    ShowGraph(G);
    return 0;
}