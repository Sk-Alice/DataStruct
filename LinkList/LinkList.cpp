#include <iostream>
#include <windows.h>

using namespace std;

struct LinkList
{
	LinkList* next;
	int value;
};

void initMenu();
int initList(LinkList*&);
bool distoryList(LinkList*&);
bool clearList(LinkList*&);
int getLength(LinkList*&);
int getElement(LinkList*&, int);
int getPosition(LinkList*&, int);
int getPreElement(LinkList*&, int);
int getSeqELement(LinkList*&, int);
bool insertElement(LinkList*&, int, int);
bool deleteElement(LinkList*&, int);
LinkList* creatList(LinkList*&);
void showList(LinkList*&);
bool inverseList(LinkList*&);

int main()
{
	initMenu();
	LinkList* head = nullptr;

	int choice = 0;
	cout << "请输入操作代码：";
	cin >> choice;

	while (choice > 0)
	{
		switch (choice)
		{
		case 1: // 初始化链表
		{
			int result = initList(head);
			if (result == 1)
			{
				cout << "初始化成功！" << endl;
				break;
			}
			else if (result == -1)
			{
				cerr << "初始化失败！" << endl;
				exit(1);
			}
			break;
		}
		case 2: // 销毁链表
		{
			bool isTrue = distoryList(head);
			if (isTrue)
			{
				cout << "销毁成功！" << endl;
				break;
			}
			else
			{
				cerr << "销毁失败！退出程序！" << endl;
				exit(1);
			}
		}
		case 3: // 请空链表
		{
			bool isTrue = clearList(head);
			if (isTrue)
			{
				cout << "清空成功！" << endl;
				break;
			}
			else
			{
				cerr << "清空失败！退出程序！" << endl;
				exit(1);
			}
		}
		case 4: // 链表的长度
		{
			if (head == nullptr)
			{
				cout << "请先初始化该链表！" << endl;
				break;
			}
			int length = getLength(head);
			cout << "该链表的长度为：" << length << endl;
			break;
		}
		case 5: // 指定位置的元素
		{
			if (head == nullptr)
			{
				cout << "请先初始化该链表！" << endl;
				break;
			}
			if (getLength(head) == 0)
			{
				cout << "请先为该链表添加元素！" << endl;
				break;
			}
			int searchPos = -1;
			cout << "请输入要查找元素的位置:";
			cin >> searchPos;
			int result = getElement(head, searchPos);
			if (result == -1)
			{
				cerr << "访问越界！" << endl;
				break;
			}
			cout << "该元素为：" << result << endl;
			break;
		}
		case 6: // 链表已存在元素的位置
		{
			if (head == nullptr)
			{
				cout << "请先初始化该链表！" << endl;
				break;
			}
			if (getLength(head) == 0)
			{
				cout << "请先为该链表添加元素！" << endl;
				break;
			}
			int searchValue = -1;
			cout << "请输入要查找位置的元素：";
			cin >> searchValue;
			int result = getPosition(head, searchValue);
			if (result == -1)
			{
				cout << "该元素不存在！" << endl;
				break;
			}
			cout << "该元素的位置是：" << result << endl;
			break;
		}
		case 7: // 求输入元素的直接前驱
		{
			if (head == nullptr)
			{
				cout << "请先初始化该链表！" << endl;
				break;
			}
			if (getLength(head) == 0)
			{
				cout << "请先为该链表添加元素！" << endl;
				break;
			}
			int value = -1;
			cout << "请输入要查找前驱的元素：";
			cin >> value;
			int result = getPreElement(head, value);
			if (result == 0)
			{
				cout << "该元素没有前驱！" << endl;
				break;
			}
			if (result == -1)
			{
				cout << "未找到该元素！" << endl;
				break;
			}
			cout << "该元素的前驱是：" << result << endl;
			break;
		}
		case 8: // 求输入元素的直接后继
		{
			if (head == nullptr)
			{
				cout << "请先初始化该链表！" << endl;
				break;
			}
			if (getLength(head) == 0)
			{
				cout << "请先为该链表添加元素！" << endl;
				break;
			}
			int value = -1;
			cout << "请输入要查找后继的元素：";
			cin >> value;
			int result = getSeqELement(head, value);
			if (result == 0)
			{
				cout << "该元素没有后继！" << endl;
				break;
			}
			if (result == -1)
			{
				cout << "未找到该元素！" << endl;
				break;
			}
			cout << "该元素的后继是：" << result << endl;
			break;
		}
		case 9: // 在第i个位置插入一个元素
		{
			if (head == nullptr)
			{
				cout << "请先初始化该链表！" << endl;
				break;
			}
			int pos = -1;
			int value = -1;
			cout << "请输入要插入的位置与元素：";
			cin >> pos >> value;
			bool isTrue = insertElement(head, pos, value);
			if (isTrue)
			{
				cout << "插入成功！" << endl;
				break;
			}
			else
			{
				cout << "插入失败，请检查插入的位置是否合法！" << endl;
				break;
			}
		}
		case 10: // 删除第i个元素
		{
			if (head == nullptr)
			{
				cout << "请先初始化该链表！" << endl;
				break;
			}
			if (getLength(head) == 0)
			{
				cout << "该链表已空！" << endl;
				break;
			}
			int pos = -1;
			cout << "请输入要删除元素的位置：";
			cin >> pos;
			bool isTrue = deleteElement(head, pos);
			if (isTrue)
			{
				cout << "删除成功！" << endl;
				break;
			}
			else
			{
				cout << "删除失败！请检查该位置是否合法！" << endl;
				break;
			}
		}
		case 11: // 输出链表元素
		{
			if (head == nullptr)
			{
				cout << "请先初始化该链表！" << endl;
				break;
			}
			if (getLength(head) == 0)
			{
				cout << "该链表为空链表！" << endl;
				break;
			}
			showList(head);
			break;
		}
		case 12: // 初始化并用尾插法输入元素
		{
			head = creatList(head);
			break;
		}
		case 13: // 实现单链表的逆序存放
		{
			if (head == nullptr)
			{
				cout << "请先初始化该链表！" << endl;
				break;
			}
			if (getLength(head) == 0)
			{
				cout << "请先为该链表添加元素！" << endl;
				break;
			}
			if (inverseList(head))
			{
				cout << "逆序成功！" << endl;
				break;
			}
			else
			{
				cout << "逆序失败！" << endl;
				break;
			}
		}
		}

		Sleep(700);
		system("cls");
		initMenu();
		cout << "请输入操作代码：";
		cin >> choice;
	}

	return 0;
}

void initMenu()
{
	cout << "1---初始化或重置链表" << endl;
	cout << "2---销毁链表" << endl;
	cout << "3---清空链表" << endl;
	cout << "4---链表的长度" << endl;
	cout << "5---指定位置的元素值" << endl;
	cout << "6---链表已存在元素的位置" << endl;
	cout << "7---求输入元素的直接前驱" << endl;
	cout << "8---求输入元素的直接后继" << endl;
	cout << "9---在第i个位置插入一个元素" << endl;
	cout << "10---删除第i个元素" << endl;
	cout << "11---输出链表元素" << endl;
	cout << "12---初始化并用尾插法输入元素" << endl;
	cout << "13---实现单链表的逆序存放" << endl;
}

int initList(LinkList*& head)
{
	try
	{
		head = new LinkList;
		head->next = nullptr;
		return 1;
	}
	catch (bad_alloc)
	{
		return -1;
	}
}

bool distoryList(LinkList*& head)
{
	bool isDistory = false;
	LinkList* curr = head->next;
	while (curr != nullptr)
	{
		LinkList* next = curr->next;
		delete curr;
		curr = next;
	}
	delete head;
	head = nullptr;
	if (head == nullptr)
	{
		isDistory = true;
	}
	return isDistory;
}

bool clearList(LinkList*& head)
{
	bool isClear = false;
	LinkList* curr = head->next;
	while (curr != nullptr)
	{
		LinkList* next = curr->next;
		delete curr;
		curr = next;
	}
	head->next = nullptr;
	if (head->next == nullptr)
	{
		isClear = true;
	}
	return isClear;
}

int getLength(LinkList*& head)
{
	LinkList* p = head->next;
	int length = 0;
	while (p != nullptr)
	{
		++length;
		p = p->next;
	}
	return length;
}

int getElement(LinkList*& head, int _pos)
{
	int length = getLength(head);
	LinkList* curr = head->next;

	for (int i = 1; i <= length; i++)
	{
		if (i == _pos)
		{ // 找到该下标
			return curr->value;
		}
		curr = curr->next;
	}
	return -1;  // 没有找到该下标
}

int getPosition(LinkList*& head, int _value)
{
	LinkList* curr = head->next;
	int pos = 1;
	while (curr != nullptr)
	{
		if (curr->value == _value)
		{ // 找到该元素
			return pos;
		}
		curr = curr->next;
		pos++;
	}
	return -1;  // 没有该元素
}

int getPreElement(LinkList*& head, int _value)
{
	LinkList* curr = head->next;

	while (curr->next != nullptr)
	{
		if (curr->value == _value)
		{ // 第一个元素，没有前驱
			return 0;
		}
		if (curr->next->value == _value)
		{ // 找到前驱
			return curr->value;
		}
		curr = curr->next;
	}
	return -1;  // 没有该元素
}

int getSeqELement(LinkList*& head, int _value)
{
	LinkList* curr = head->next;

	while (curr->next != nullptr)
	{
		if (curr->value == _value)
		{ // 得到后继
			return curr->next->value;
		}
		curr = curr->next;
	}
	if (curr->next == nullptr && curr->value == _value)
	{ // 最后一个元素，没有后继
		return 0;
	}
	return -1;  // 没有找到该元素
}

bool insertElement(LinkList*& head, int _pos, int _value)
{
	int length = getLength(head);
	LinkList* curr = head;

	LinkList* newNode = new LinkList();
	newNode->next = nullptr;
	newNode->value = _value;

	for (int i = 1; i <= length + 1; i++)
	{
		if (i == _pos)
		{
			newNode->next = curr->next;
			curr->next = newNode;
			return true;
		}
		curr = curr->next;
	}
	return false;
}

bool deleteElement(LinkList*& head, int _pos)
{
	int length = getLength(head);
	LinkList* curr = head->next;
	LinkList* pre = head;

	for (int i = 1; i <= length; i++)
	{
		if (i == _pos)
		{
			pre->next = curr->next;
			delete curr;
			curr = nullptr;

			return true;
		}
		curr = curr->next;
		pre = pre->next;
	}

	return false;
}

LinkList* creatList(LinkList*& head)
{
	LinkList* pre = head;

	while (true)
	{
		LinkList* p = new LinkList();

		cout << "请输入元素(end of -1)：";
		int tempValue = 0;
		cin >> tempValue;
		if (tempValue == -1)
		{
			break;
		}
		p->value = tempValue;

		pre->next = p;
		pre = p;
		p->next = nullptr;
	}
	return head;
}

void showList(LinkList*& head)
{
	LinkList* p = head->next;
	cout << "所有元素为：" << endl;
	while (p != nullptr)
	{
		cout << p->value << "\t";
		p = p->next;
	}
	cout << endl;
}

bool inverseList(LinkList*& head)
{// 采用头插法逆序
	LinkList* curr = head->next;
	LinkList* p = nullptr;
	head->next = nullptr;

	while (curr != nullptr)
	{
		p = curr;
		curr = curr->next;

		p->next = head->next;
		head->next = p;
	}
	if (curr == nullptr)
	{
		return true;
	}
	return false;
}

