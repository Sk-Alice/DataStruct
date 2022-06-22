#include <iostream>
#include <vector>
#include <queue>
#define MAX_VERTEX_NUM 20  // ��󶥵���

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef int Status;	/* Status�Ǻ���������,��ֵ�Ǻ������״̬���룬��OK�� */
typedef int Boolean; /* Boolean�ǲ�������,��ֵ��TRUE��FALSE */

typedef char VertexType; /* ��������Ӧ���û����� */
typedef int EdgeType; /* ���ϵ�Ȩֵ����Ӧ���û����� */

#define MAXSIZE 9 /* �洢�ռ��ʼ������ */
#define MAXEDGE 15
#define MAXVEX 9
#define INFINITY 65535

using namespace std;

bool vis[MAX_VERTEX_NUM];

// ͼ�Ľṹ����
struct ALGraph
{
    int vexs[MAX_VERTEX_NUM]; // ��������
    int vexNum, arcNum;  // ͼ�ĵ�ǰ�������ͻ���
    int arc[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
};

/* ѭ�����е�˳��洢�ṹ */
typedef struct
{
    int data[MAXSIZE];
    int front;    	/* ͷָ�� */
    int rear;		/* βָ�룬�����в��գ�ָ�����βԪ�ص���һ��λ�� */
}Queue;

/* ��ʼ��һ���ն���Q */
Status InitQueue(Queue* Q)
{
    Q->front = 0;
    Q->rear = 0;
    return  OK;
}

/* ������QΪ�ն���,�򷵻�TRUE,���򷵻�FALSE */
Status QueueEmpty(Queue Q)
{
    if (Q.front == Q.rear) /* ���пյı�־ */
        return TRUE;
    else
        return FALSE;
}

/* ������δ���������Ԫ��eΪQ�µĶ�βԪ�� */
Status EnQueue(Queue* Q, int e)
{
    if ((Q->rear + 1) % MAXSIZE == Q->front)	/* ���������ж� */
        return ERROR;
    Q->data[Q->rear] = e;			/* ��Ԫ��e��ֵ����β */
    Q->rear = (Q->rear + 1) % MAXSIZE;/* rearָ�������һλ�ã� */
                                /* ���������ת������ͷ�� */
    return  OK;
}

/* �����в��գ���ɾ��Q�ж�ͷԪ�أ���e������ֵ */
Status DeQueue(Queue* Q, int* e)
{
    if (Q->front == Q->rear)			/* ���пյ��ж� */
        return ERROR;
    *e = Q->data[Q->front];				/* ����ͷԪ�ظ�ֵ��e */
    Q->front = (Q->front + 1) % MAXSIZE;	/* frontָ�������һλ�ã� */
                                    /* ���������ת������ͷ�� */
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
    cout << "���������Ĳ�����";
    cin >> choice;

    while (choice != -1)
    {
        switch (choice)
        {
        case 1:
            CreateUDG(G);
            cout << "�����ɹ���" << endl;
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

        cout << "���������Ĳ�����";
        cin >> choice;
    }

    return 0;
}

void initMenu() 
{
    cout << "1.������ͼ" << endl;
    cout << "2.����ڽӾ���" << endl;
    cout << "3.������ȱ���" << endl;
    cout << "4.������ȱ���" << endl;
    cout << "5.�˳�" << endl;
}

bool CreateUDG(ALGraph* G)
{
    cout << "����ͼ�Ķ������ͱ�����" << endl;
    cin >> G->vexNum >> G->arcNum;

    cout << "������������㣺" << endl;
    for (int i = 1; i <= G->vexNum; i++) 
    {
        int data;
        cin >> data;
        G->vexs[i] = data;
    }

    cout << "�������ڽӵ�:" << endl;
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
    //���ñ�����Ľ���ֵΪtrue
    vis[i] = true;
    cout << G->vexs[i] << " ";
    int j = 0;
    //��0��ʼ����Ѱ�ҵ�һ���ڽӽ��
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

    //Ѱ�ҵ�һ���ǿսڵ㣬���Դ˽�㿪ʼ�ݹ�(����������0��㿪ʼ)
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
    InitQueue(&Q);		/* ��ʼ��һ�����õĶ��� */
    for (i = 1; i <= G->vexNum; i++)  /* ��ÿһ��������ѭ�� */
    {
        if (!vis[i])	/* ����δ���ʹ��ʹ��� */
        {
            vis[i] = TRUE;		/* ���õ�ǰ������ʹ� */
            cout << G->vexs[i] << " ";/* ��ӡ���㣬Ҳ������������ */
            EnQueue(&Q, i);		/* ���˶�������� */
            while (!QueueEmpty(Q))	/* ����ǰ���в�Ϊ�� */
            {
                DeQueue(&Q, &i);	/* ���Ӷ�Ԫ�س����У���ֵ��i */
                for (j = 0; j < G->vexNum; j++)
                {
                    /* �ж������������뵱ǰ������ڱ���δ���ʹ�  */
                    if (G->arc[i][j] == 1 && !vis[j])
                    {
                        vis[j] = TRUE;			/* ���ҵ��Ĵ˶�����Ϊ�ѷ��� */
                        cout << G->vexs[j] << " ";/* ��ӡ���� */
                        EnQueue(&Q, j);				/* ���ҵ��Ĵ˶��������  */
                    }
                }
            }
        }
    }
}

