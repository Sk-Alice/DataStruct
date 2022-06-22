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
	cout << "������������룺";
	cin >> choice;

	while (choice > 0)
	{
		switch (choice)
		{
		case 1: // ��ʼ������
		{
			int result = initList(head);
			if (result == 1)
			{
				cout << "��ʼ���ɹ���" << endl;
				break;
			}
			else if (result == -1)
			{
				cerr << "��ʼ��ʧ�ܣ�" << endl;
				exit(1);
			}
			break;
		}
		case 2: // ��������
		{
			bool isTrue = distoryList(head);
			if (isTrue)
			{
				cout << "���ٳɹ���" << endl;
				break;
			}
			else
			{
				cerr << "����ʧ�ܣ��˳�����" << endl;
				exit(1);
			}
		}
		case 3: // �������
		{
			bool isTrue = clearList(head);
			if (isTrue)
			{
				cout << "��ճɹ���" << endl;
				break;
			}
			else
			{
				cerr << "���ʧ�ܣ��˳�����" << endl;
				exit(1);
			}
		}
		case 4: // ����ĳ���
		{
			if (head == nullptr)
			{
				cout << "���ȳ�ʼ��������" << endl;
				break;
			}
			int length = getLength(head);
			cout << "������ĳ���Ϊ��" << length << endl;
			break;
		}
		case 5: // ָ��λ�õ�Ԫ��
		{
			if (head == nullptr)
			{
				cout << "���ȳ�ʼ��������" << endl;
				break;
			}
			if (getLength(head) == 0)
			{
				cout << "����Ϊ���������Ԫ�أ�" << endl;
				break;
			}
			int searchPos = -1;
			cout << "������Ҫ����Ԫ�ص�λ��:";
			cin >> searchPos;
			int result = getElement(head, searchPos);
			if (result == -1)
			{
				cerr << "����Խ�磡" << endl;
				break;
			}
			cout << "��Ԫ��Ϊ��" << result << endl;
			break;
		}
		case 6: // �����Ѵ���Ԫ�ص�λ��
		{
			if (head == nullptr)
			{
				cout << "���ȳ�ʼ��������" << endl;
				break;
			}
			if (getLength(head) == 0)
			{
				cout << "����Ϊ���������Ԫ�أ�" << endl;
				break;
			}
			int searchValue = -1;
			cout << "������Ҫ����λ�õ�Ԫ�أ�";
			cin >> searchValue;
			int result = getPosition(head, searchValue);
			if (result == -1)
			{
				cout << "��Ԫ�ز����ڣ�" << endl;
				break;
			}
			cout << "��Ԫ�ص�λ���ǣ�" << result << endl;
			break;
		}
		case 7: // ������Ԫ�ص�ֱ��ǰ��
		{
			if (head == nullptr)
			{
				cout << "���ȳ�ʼ��������" << endl;
				break;
			}
			if (getLength(head) == 0)
			{
				cout << "����Ϊ���������Ԫ�أ�" << endl;
				break;
			}
			int value = -1;
			cout << "������Ҫ����ǰ����Ԫ�أ�";
			cin >> value;
			int result = getPreElement(head, value);
			if (result == 0)
			{
				cout << "��Ԫ��û��ǰ����" << endl;
				break;
			}
			if (result == -1)
			{
				cout << "δ�ҵ���Ԫ�أ�" << endl;
				break;
			}
			cout << "��Ԫ�ص�ǰ���ǣ�" << result << endl;
			break;
		}
		case 8: // ������Ԫ�ص�ֱ�Ӻ��
		{
			if (head == nullptr)
			{
				cout << "���ȳ�ʼ��������" << endl;
				break;
			}
			if (getLength(head) == 0)
			{
				cout << "����Ϊ���������Ԫ�أ�" << endl;
				break;
			}
			int value = -1;
			cout << "������Ҫ���Һ�̵�Ԫ�أ�";
			cin >> value;
			int result = getSeqELement(head, value);
			if (result == 0)
			{
				cout << "��Ԫ��û�к�̣�" << endl;
				break;
			}
			if (result == -1)
			{
				cout << "δ�ҵ���Ԫ�أ�" << endl;
				break;
			}
			cout << "��Ԫ�صĺ���ǣ�" << result << endl;
			break;
		}
		case 9: // �ڵ�i��λ�ò���һ��Ԫ��
		{
			if (head == nullptr)
			{
				cout << "���ȳ�ʼ��������" << endl;
				break;
			}
			int pos = -1;
			int value = -1;
			cout << "������Ҫ�����λ����Ԫ�أ�";
			cin >> pos >> value;
			bool isTrue = insertElement(head, pos, value);
			if (isTrue)
			{
				cout << "����ɹ���" << endl;
				break;
			}
			else
			{
				cout << "����ʧ�ܣ���������λ���Ƿ�Ϸ���" << endl;
				break;
			}
		}
		case 10: // ɾ����i��Ԫ��
		{
			if (head == nullptr)
			{
				cout << "���ȳ�ʼ��������" << endl;
				break;
			}
			if (getLength(head) == 0)
			{
				cout << "�������ѿգ�" << endl;
				break;
			}
			int pos = -1;
			cout << "������Ҫɾ��Ԫ�ص�λ�ã�";
			cin >> pos;
			bool isTrue = deleteElement(head, pos);
			if (isTrue)
			{
				cout << "ɾ���ɹ���" << endl;
				break;
			}
			else
			{
				cout << "ɾ��ʧ�ܣ������λ���Ƿ�Ϸ���" << endl;
				break;
			}
		}
		case 11: // �������Ԫ��
		{
			if (head == nullptr)
			{
				cout << "���ȳ�ʼ��������" << endl;
				break;
			}
			if (getLength(head) == 0)
			{
				cout << "������Ϊ������" << endl;
				break;
			}
			showList(head);
			break;
		}
		case 12: // ��ʼ������β�巨����Ԫ��
		{
			head = creatList(head);
			break;
		}
		case 13: // ʵ�ֵ������������
		{
			if (head == nullptr)
			{
				cout << "���ȳ�ʼ��������" << endl;
				break;
			}
			if (getLength(head) == 0)
			{
				cout << "����Ϊ���������Ԫ�أ�" << endl;
				break;
			}
			if (inverseList(head))
			{
				cout << "����ɹ���" << endl;
				break;
			}
			else
			{
				cout << "����ʧ�ܣ�" << endl;
				break;
			}
		}
		}

		Sleep(700);
		system("cls");
		initMenu();
		cout << "������������룺";
		cin >> choice;
	}

	return 0;
}

void initMenu()
{
	cout << "1---��ʼ������������" << endl;
	cout << "2---��������" << endl;
	cout << "3---�������" << endl;
	cout << "4---����ĳ���" << endl;
	cout << "5---ָ��λ�õ�Ԫ��ֵ" << endl;
	cout << "6---�����Ѵ���Ԫ�ص�λ��" << endl;
	cout << "7---������Ԫ�ص�ֱ��ǰ��" << endl;
	cout << "8---������Ԫ�ص�ֱ�Ӻ��" << endl;
	cout << "9---�ڵ�i��λ�ò���һ��Ԫ��" << endl;
	cout << "10---ɾ����i��Ԫ��" << endl;
	cout << "11---�������Ԫ��" << endl;
	cout << "12---��ʼ������β�巨����Ԫ��" << endl;
	cout << "13---ʵ�ֵ������������" << endl;
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
		{ // �ҵ����±�
			return curr->value;
		}
		curr = curr->next;
	}
	return -1;  // û���ҵ����±�
}

int getPosition(LinkList*& head, int _value)
{
	LinkList* curr = head->next;
	int pos = 1;
	while (curr != nullptr)
	{
		if (curr->value == _value)
		{ // �ҵ���Ԫ��
			return pos;
		}
		curr = curr->next;
		pos++;
	}
	return -1;  // û�и�Ԫ��
}

int getPreElement(LinkList*& head, int _value)
{
	LinkList* curr = head->next;

	while (curr->next != nullptr)
	{
		if (curr->value == _value)
		{ // ��һ��Ԫ�أ�û��ǰ��
			return 0;
		}
		if (curr->next->value == _value)
		{ // �ҵ�ǰ��
			return curr->value;
		}
		curr = curr->next;
	}
	return -1;  // û�и�Ԫ��
}

int getSeqELement(LinkList*& head, int _value)
{
	LinkList* curr = head->next;

	while (curr->next != nullptr)
	{
		if (curr->value == _value)
		{ // �õ����
			return curr->next->value;
		}
		curr = curr->next;
	}
	if (curr->next == nullptr && curr->value == _value)
	{ // ���һ��Ԫ�أ�û�к��
		return 0;
	}
	return -1;  // û���ҵ���Ԫ��
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

		cout << "������Ԫ��(end of -1)��";
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
	cout << "����Ԫ��Ϊ��" << endl;
	while (p != nullptr)
	{
		cout << p->value << "\t";
		p = p->next;
	}
	cout << endl;
}

bool inverseList(LinkList*& head)
{// ����ͷ�巨����
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

