#include <iostream>
#include <Windows.h>

using namespace std;

typedef struct QNode
{
	int data;
	QNode* next;
}*Queueptr;

struct LinkQueue
{
	Queueptr front;
	Queueptr rear;
};

void initMenu();
bool initQueue(LinkQueue*&);
bool destoryQueue(LinkQueue*&);
int clearQueue(LinkQueue*&);
int isEmpty(LinkQueue*&);
int getLength(LinkQueue*&);
int getHead(LinkQueue*&);
int insertValue(LinkQueue*&, int);
int deleteValue(LinkQueue*&);
void showQueue(LinkQueue*&);

int main()
{
	initMenu();

	LinkQueue* Q = new LinkQueue;
	Q->front = Q->rear = nullptr;
	int choice = 0;
	cout << "请输入您的操作(end of -1)：";
	cin >> choice;

	do
	{
		switch (choice)
		{
		case 1:
		{
			if (initQueue(Q))
				cout << "初始化成功！" << endl;
			else
				cout << "初始化失败！" << endl;
			break;
		}
		case 2:
		{
			if (destoryQueue(Q))
				cout << "销毁成功！" << endl;
			else
				cout << "销毁失败！" << endl;
			break;
		}
		case 3:
		{
			if (!Q->front)
			{
				cout << "该队列未初始化" << endl;
				break;
			}

			if (clearQueue(Q) == 1)
				cout << "清空成功！" << endl;
			break;
		}
		case 4:
		{
			if (!Q->front)
			{
				cout << "该队列未初始化" << endl;
				break;
			}

			if (isEmpty(Q) == 1)
				cout << "队列已空！" << endl;
			else
				cout << "队列不空！" << endl;
			break;
		}
		case 5:
		{
			if (!Q->front)
			{
				cout << "该队列未初始化" << endl;
				break;
			}

			cout << "该队列的长度为：" << getLength(Q) << endl;
			break;
		}
		case 6:
		{
			if (!Q->front)
			{
				cout << "该队列未初始化" << endl;
				break;
			}
			if (Q->front == Q->rear)
			{
				cout << "该队列为空队！" << endl;
				break;
			}

			cout << "队头元素为：" << getHead(Q) << endl;
			break;
		}
		case 7:
		{
			if (!Q->front)
			{
				cout << "该队列未初始化" << endl;
				break;
			}

			int insertNum = 0;
			cout << "请输入入队的元素：";
			cin >> insertNum;
			if (insertValue(Q, insertNum) == 1)
				cout << "入队成功！" << endl;

			break;
		}
		case 8:
		{
			if (!Q->front)
			{
				cout << "该队列未初始化" << endl;
				break;
			}
			if (Q->front == Q->rear)
			{
				cout << "该队列为空队！" << endl;
				break;
			}

			cout << "出队成功！出队元素为:" << deleteValue(Q) << endl;

			break;
		}
		case 9:
		{
			if (!Q->front)
			{
				cout << "该队列未初始化" << endl;
				break;
			}
			if (Q->front == Q->rear)
			{
				cout << "该队列为空！" << endl;
				break;
			}

			showQueue(Q);
			break;
		}
		default:
			break;
		}
		Sleep(700);
		system("cls");
		initMenu();

		cout << "请输入您的操作(end of -1)：";
		cin >> choice;
	} while (choice != -1);
	return 0;
}

void initMenu()
{
	cout << "1.初始化队列" << endl;
	cout << "2.销毁队列" << endl;
	cout << "3.清空队列" << endl;
	cout << "4.队列判空" << endl;
	cout << "5.获取队列长度" << endl;
	cout << "6.获取队头元素" << endl;
	cout << "7.入队元素" << endl;
	cout << "8.出队元素" << endl;
	cout << "9.遍历队列" << endl;
}

bool initQueue(LinkQueue*& Q)
{
	try
	{
		Q->front = Q->rear = new QNode;
		Q->front->next = nullptr;
		return true;
	}
	catch (exception e)
	{
		return false;
	}
}

bool destoryQueue(LinkQueue*& Q)
{
	while (Q->front)
	{
		Q->rear = Q->front->next;
		delete(Q->front);
		Q->front = Q->rear;
	}
	return true;
}

int clearQueue(LinkQueue*& Q)
{
	QNode* p = nullptr;
	QNode* q = nullptr;

	Q->rear = Q->front;
	p = Q->front->next;
	Q->front->next = nullptr;
	while (p)
	{
		q = p->next;
		delete(p);
		p = q;
	}
	return 1;
}

int isEmpty(LinkQueue*& Q)
{
	if (Q->front == Q->rear)
	{
		return 1;
	}
	return 0;
}

int getLength(LinkQueue*& Q)
{
	int count = 0;
	Queueptr q = Q->front;

	while (q != Q->rear)
	{
		count++;
		q = q->next;
	}

	return count;
}

int getHead(LinkQueue*& Q)
{
	return Q->front->next->data;
}

int insertValue(LinkQueue*& Q, int value)
{
	Queueptr p = new  QNode;
	p->next = nullptr;

	p->data = value;
	Q->rear->next = p;
	Q->rear = p;

	return 1;
}

int deleteValue(LinkQueue*& Q)
{
	int ans = 0;
	Queueptr p = Q->front->next;
	ans = p->data;
	Q->front->next = p->next;
	if (Q->rear == p) Q->rear = Q->front;
	delete p;

	return ans;
}

void showQueue(LinkQueue*& Q)
{
	Queueptr p = Q->front->next;

	while (p)
	{
		cout << p->data << "\t";
		p = p->next;
	}
	cout << endl;
}