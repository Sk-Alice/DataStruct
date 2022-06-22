#include <iostream>
#include <vector>
#include <queue>
#define MAX_VERTEX_NUM 20  // 最大顶点数

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef int Status;	/* Status是函数的类型,其值是函数结果状态代码，如OK等 */
typedef int Boolean; /* Boolean是布尔类型,其值是TRUE或FALSE */

typedef char VertexType; /* 顶点类型应由用户定义 */
typedef int EdgeType; /* 边上的权值类型应由用户定义 */

#define MAXSIZE 9 /* 存储空间初始分配量 */
#define MAXEDGE 15
#define MAXVEX 9
#define INFINITY 65535

using namespace std;

bool vis[MAX_VERTEX_NUM];

// 图的结构定义
struct ALGraph
{
    int vexs[MAX_VERTEX_NUM]; // 顶点数组
    int vexNum, arcNum;  // 图的当前顶点数和弧数
    int arc[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
};

/* 循环队列的顺序存储结构 */
typedef struct
{
    int data[MAXSIZE];
    int front;    	/* 头指针 */
    int rear;		/* 尾指针，若队列不空，指向队列尾元素的下一个位置 */
}Queue;

/* 初始化一个空队列Q */
Status InitQueue(Queue* Q)
{
    Q->front = 0;
    Q->rear = 0;
    return  OK;
}

/* 若队列Q为空队列,则返回TRUE,否则返回FALSE */
Status QueueEmpty(Queue Q)
{
    if (Q.front == Q.rear) /* 队列空的标志 */
        return TRUE;
    else
        return FALSE;
}

/* 若队列未满，则插入元素e为Q新的队尾元素 */
Status EnQueue(Queue* Q, int e)
{
    if ((Q->rear + 1) % MAXSIZE == Q->front)	/* 队列满的判断 */
        return ERROR;
    Q->data[Q->rear] = e;			/* 将元素e赋值给队尾 */
    Q->rear = (Q->rear + 1) % MAXSIZE;/* rear指针向后移一位置， */
                                /* 若到最后则转到数组头部 */
    return  OK;
}

/* 若队列不空，则删除Q中队头元素，用e返回其值 */
Status DeQueue(Queue* Q, int* e)
{
    if (Q->front == Q->rear)			/* 队列空的判断 */
        return ERROR;
    *e = Q->data[Q->front];				/* 将队头元素赋值给e */
    Q->front = (Q->front + 1) % MAXSIZE;	/* front指针向后移一位置， */
                                    /* 若到最后则转到数组头部 */
    return  OK;
}

void initMenu();
bool CreateUDG(ALGraph*);
void printMatrix(ALGraph*);
void DFSM(ALGraph*, int);
void DFS(ALGraph*);
void BFSTraverse(ALGraph*);

int main()
{
    ALGraph* G = new ALGraph();
    int choice;

    initMenu();
    cout << "请输入您的操作：";
    cin >> choice;

    while (choice != -1)
    {
        switch (choice)
        {
        case 1:
            CreateUDG(G);
            cout << "创建成功！" << endl;
            break;
        case 2:
            printMatrix(G);
            break;
        case 3:
            DFS(G);
            cout << endl;
            break;
        case 4:
            BFSTraverse(G);
            cout << endl;
            break;
        case 5:
            exit(0);
        default:
            break;
        }

        cout << "请输入您的操作：";
        cin >> choice;
    }

    return 0;
}

void initMenu() 
{
    cout << "1.构建网图" << endl;
    cout << "2.输出邻接矩阵" << endl;
    cout << "3.深度优先遍历" << endl;
    cout << "4.广度优先遍历" << endl;
    cout << "5.退出" << endl;
}

bool CreateUDG(ALGraph* G)
{
    cout << "输入图的顶点数和边数：" << endl;
    cin >> G->vexNum >> G->arcNum;

    cout << "请输入各个顶点：" << endl;
    for (int i = 1; i <= G->vexNum; i++) 
    {
        int data;
        cin >> data;
        G->vexs[i] = data;
    }

    cout << "请输入邻接点:" << endl;
    for (int i = 1; i <= G->arcNum; i++)
    {
        int m, n;
        cin >> m >> n;
        G->arc[m][n] = 1;
        G->arc[n][m] = 1;
    }

    return true;
}

void printMatrix(ALGraph* G)
{
    for (int i = 1; i <= G->vexNum; ++i) 
    {
        for (int j = 1; j <= G->vexNum; ++j) 
        {
            cout << G->arc[i][j] << " ";
        }
        cout << endl;
    }
}

void DFSM(ALGraph* G, int i)
{
    //设置被输出的结点的值为true
    vis[i] = true;
    cout << G->vexs[i] << " ";
    int j = 0;
    //从0开始遍历寻找第一个邻接结点
    for (j = 1; j <= G->vexNum; j++) {
        if (vis[j] == false && G->arc[i][j] != 0) {
            DFSM(G, j);
        }
    }
}

void DFS(ALGraph* G)
{
    int i, j = 0;
    for (i = 1; i <= G->vexNum; i++) {
        vis[i] = false;
    }

    //寻找第一个非空节点，并以此结点开始递归(题中所给是0结点开始)
    for (i = 1; i <= G->vexNum; i++) {
        for (j = 1; j <= G->vexNum; j++) {
            if (G->arc[i][j] != 0) {
                DFSM(G, i);
                break;
            }
        }
        break;
    }
}

void BFSTraverse(ALGraph* G)
{
    int i, j;
    Queue Q;
    for (i = 1; i <= G->vexNum; i++)
        vis[i] = FALSE;
    InitQueue(&Q);		/* 初始化一辅助用的队列 */
    for (i = 1; i <= G->vexNum; i++)  /* 对每一个顶点做循环 */
    {
        if (!vis[i])	/* 若是未访问过就处理 */
        {
            vis[i] = TRUE;		/* 设置当前顶点访问过 */
            cout << G->vexs[i] << " ";/* 打印顶点，也可以其它操作 */
            EnQueue(&Q, i);		/* 将此顶点入队列 */
            while (!QueueEmpty(Q))	/* 若当前队列不为空 */
            {
                DeQueue(&Q, &i);	/* 将队对元素出队列，赋值给i */
                for (j = 0; j < G->vexNum; j++)
                {
                    /* 判断其它顶点若与当前顶点存在边且未访问过  */
                    if (G->arc[i][j] == 1 && !vis[j])
                    {
                        vis[j] = TRUE;			/* 将找到的此顶点标记为已访问 */
                        cout << G->vexs[j] << " ";/* 打印顶点 */
                        EnQueue(&Q, j);				/* 将找到的此顶点入队列  */
                    }
                }
            }
        }
    }
}

