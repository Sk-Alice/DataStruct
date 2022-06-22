#include <iostream>
#include <algorithm>
#include <Windows.h>

#define LIST_INIT_SIZE 100
#define LISTNCREMENT 10

using namespace std;

template <class T>
struct SeqList
{
	T* element;
	int capacity;
	int listSize;
};

void initMenu();
SeqList<int>* initList();
bool distroyList(SeqList<int>*&);
bool clearList(SeqList<int>*&);
bool isEmpty(SeqList<int>*&);
int getLength(SeqList<int>*&);
int getElement(SeqList<int>*&, int);
int getPosition(SeqList<int>*&, int);
int getPreElement(SeqList<int>*&, int);
int getSeqElement(SeqList<int>*&, int);
bool insertElement(SeqList<int>*&, int, int);
bool deleteElement(SeqList<int>*&, int);
void printElement(SeqList<int>*&);
void megerList(SeqList<int>*&, SeqList<int>*&);

int main()
{
	initMenu();
	SeqList<int>* arrayList = nullptr;

	int choice;
	cout << "������������룺";
	cin >> choice;

	while (choice > 0)
	{
		switch (choice)
		{
		case 1://��ʼ�����Ա�ռ�
		{
			arrayList = initList();
			break;
		}
		case 2://�������Ա�
		{
			bool isTrue = distroyList(arrayList);
			if (isTrue)
			{
				cout << "���ٳɹ���" << endl;
			}
			else
			{
				cout << "����ʧ�ܣ�" << endl;
				exit(1);
			}
			break;
		}
		case 3://������Ա�
		{
			bool isTrue = clearList(arrayList);
			if (isTrue)
			{
				cout << "��ճɹ���" << endl;
			}
			else
			{
				cout << "���ʧ�ܣ�" << endl;
				exit(1);
			}
			break;
		}
		case 4://�ж����Ա��Ƿ�Ϊ��
		{
			bool isTrue = isEmpty(arrayList);
			if (isTrue)
			{
				cout << "�ñ�Ϊ��" << endl;
			}
			else
			{
				cout << "�ñ�Ϊ��" << endl;
			}
			break;
		}
		case 5://�����Ա�ĳ���
		{
			if (arrayList->element == nullptr)
			{
				cout << "���ȳ�ʼ��˳���!" << endl;
				break;
			}
			cout << "���Ա�ĳ���Ϊ��" << getLength(arrayList) << endl;
			break;
		}
		case 6://��ȡ���Ա���ָ��λ�õ�Ԫ��
		{
			if (arrayList->element == nullptr)
			{
				cout << "���ȳ�ʼ��˳���!" << endl;
				break;
			}
			if (isEmpty(arrayList))
			{
				cout << "����Ϊ˳������Ԫ�أ�" << endl;
				break;
			}
			int index;
			cout << "������Ҫ����Ԫ�ص�λ�ã�";
			cin >> index;
			int temp = getElement(arrayList, index);
			if (temp == -1)
			{
				cerr << "����Խ�磡" << endl;
			}
			else
			{
				cout << "��Ԫ��Ϊ��" << temp << endl;
			}
			break;
		}
		case 7://��ȡ���Ա�Ԫ�ص�λ��
		{
			if (arrayList->element == nullptr)
			{
				cout << "���ȳ�ʼ��˳���!" << endl;
				break;
			}
			if (isEmpty(arrayList))
			{
				cout << "����Ϊ˳������Ԫ�أ�" << endl;
				break;
			}
			int num;
			cout << "��������Ҫ���ҵ�Ԫ�أ�";
			cin >> num;
			int temp = getPosition(arrayList, num);
			if (temp == -1)
			{
				cerr << "���Ա���û�и�Ԫ�أ�" << endl;
			}
			else
			{
				cout << "��Ԫ�ص��±�Ϊ��" << temp << endl;
			}
			break;
		}
		case 8://��ǰ��
		{
			if (arrayList->element == nullptr)
			{
				cout << "���ȳ�ʼ��˳���!" << endl;
				break;
			}
			if (isEmpty(arrayList))
			{
				cout << "����Ϊ˳������Ԫ�أ�" << endl;
				break;
			}
			int num;
			cout << "��������ǰ����Ԫ�أ�";
			cin >> num;
			int temp = getPreElement(arrayList, num);
			if (temp == -1)
			{
				cout << "��Ԫ��û��ǰ����" << endl;
			}
			else if (temp == -2)
			{
				cerr << "���Ա���û�и�Ԫ��!" << endl;
			}
			else
			{
				cout << "��Ԫ�ص�ǰ��Ϊ��" << temp << endl;
			}
			break;
		}
		case 9://����
		{
			if (arrayList->element == nullptr)
			{
				cout << "���ȳ�ʼ��˳���!" << endl;
				break;
			}
			if (isEmpty(arrayList))
			{
				cout << "����Ϊ˳������Ԫ�أ�" << endl;
				break;
			}
			int num;
			cout << "���������̵�Ԫ�أ�";
			cin >> num;
			int temp = getSeqElement(arrayList, num);
			if (temp == -1)
			{
				cout << "��Ԫ��û�к�̣�" << endl;
			}
			else if (temp == -2)
			{
				cerr << "���Ա���û�и�Ԫ��!" << endl;
			}
			else
			{
				cout << "��Ԫ�صĺ��Ϊ��" << temp << endl;
			}
			break;
		}
		case 10://�����Ա�ָ��λ�ò���Ԫ��
		{
			if (arrayList->element == nullptr)
			{
				cout << "���ȳ�ʼ��˳���!" << endl;
				break;
			}
			int index, num;
			cout << "������Ҫ�����λ���±���Ԫ�أ�end of -1����";
			cin >> index >> num;
			while (index != -1)
			{
				bool isTrue = insertElement(arrayList, index, num);
				if (!isTrue)
				{
					cerr << "������룡" << endl;
					exit(1);
				}
				else
				{
					cout << "����ɹ���" << endl;
					cout << "������Ҫ�����λ���±���Ԫ�أ�end of -1����";
					cin >> index >> num;
				}
			}
			break;
		}
		case 11://ɾ�����Ա�ָ��λ�õ�Ԫ��
		{
			if (arrayList->element == nullptr)
			{
				cout << "���ȳ�ʼ��˳���!" << endl;
				break;
			}
			if (isEmpty(arrayList))
			{
				cout << "��˳����ѿգ�" << endl;
				break;
			}
			int index;
			cout << "������Ҫɾ����λ�ã�";
			cin >> index;
			bool isTrue = deleteElement(arrayList, index);
			if (!isTrue)
			{
				cerr << "ɾ��ʧ�ܣ�" << endl;
				exit(1);
			}
			else
			{
				cout << "ɾ���ɹ���" << endl;
			}
			{}
			break;
		}
		case 12://��ʾ���Ա�
		{
			if (arrayList->element == nullptr)
			{
				cout << "���ȳ�ʼ��˳���!" << endl;
				break;
			}
			if (isEmpty(arrayList))
			{
				cout << "����Ϊ˳������Ԫ�أ�" << endl;
				break;
			}
			printElement(arrayList);
			break;
		}
		case 13://�ϲ������ǵݼ���������Ա�
		{
			if (arrayList->element == nullptr)
			{
				cout << "���ȳ�ʼ��˳���!" << endl;
				break;
			}
			if (isEmpty(arrayList))
			{
				cout << "����Ϊ˳������Ԫ�أ�" << endl;
				break;
			}
			cout << "�Զ�����һ���µ����Ա�" << endl;
			SeqList<int>* myList = initList();
			int index, num;
			cout << "������Ҫ�����λ���±���Ԫ�أ�end of -1����";
			cin >> index >> num;
			while (index != -1)
			{
				insertElement(myList, index, num);
				cout << "������Ҫ�����λ���±���Ԫ�أ�end of -1����";
				cin >> index >> num;
			}
			megerList(arrayList, myList);
			break;
		}
		default:
			break;
		}
		Sleep(1000);
		system("cls");
		initMenu();
		cout << "������������룺";
		cin >> choice;
	}
	cout << "�����˳�!" << endl;
	return 0;
}

void initMenu()
{
	cout << "*************************" << endl;
	cout << "1---��ʼ�����Ա�" << endl;
	cout << "2---�������Ա�" << endl;
	cout << "3---������Ա�" << endl;
	cout << "4---�ж����Ա��Ƿ�Ϊ��" << endl;
	cout << "5---�����Ա�ĳ���" << endl;
	cout << "6---��ȡ���Ա���ָ��λ�õ�Ԫ��" << endl;
	cout << "7---��ȡ���Ա�Ԫ�ص�λ��" << endl;
	cout << "8---��ǰ��" << endl;
	cout << "9---����" << endl;
	cout << "10---�����Ա�ָ��λ�ò���Ԫ��" << endl;
	cout << "11---ɾ�����Ա�ָ��λ�õ�Ԫ��" << endl;
	cout << "12---��ʾ���Ա�" << endl;
	cout << "13---�ϲ������ǵݼ���������Ա�" << endl;
	cout << "14---�˳�����(���븺��)" << endl;
	cout << "*************************" << endl;
}

SeqList<int>* initList()
{
	SeqList<int>* MyList = new SeqList<int>();
	try
	{
		MyList->element = new int[LIST_INIT_SIZE];
		MyList->capacity = LIST_INIT_SIZE;
		MyList->listSize = 0;
	}
	catch (bad_alloc)
	{
		cerr << "��ʼ��ʧ�ܣ�" << endl;
		exit(1);
	}

	cout << "��ʼ���ɹ�!" << endl;
	return MyList;
}

bool distroyList(SeqList<int>*& arrayList)
{
	bool isDistory = false;
	delete arrayList->element;
	arrayList->element = nullptr;
	arrayList->capacity = 0;
	arrayList->listSize = 0;
	if (arrayList->element == nullptr)
	{
		isDistory = true;
	}
	return isDistory;
}

bool clearList(SeqList<int>*& arrayList)
{
	bool isClear = false;
	arrayList->listSize = 0;
	if (arrayList->listSize == 0)
	{
		isClear = true;
	}
	return isClear;
}

bool isEmpty(SeqList<int>*& arrayList)
{
	if (arrayList->listSize > 0)
	{
		return false;
	}
	return true;
}

int getLength(SeqList<int>*& arrayList)
{
	return arrayList->listSize;
}

int getElement(SeqList<int>*& arrayList, int pos)
{
	if (pos > arrayList->listSize || pos < 0)
	{
		return -1;
	}
	return arrayList->element[pos - 1];
}

int getPosition(SeqList<int>*& arrayList, int value)
{
	for (int i = 0; i < arrayList->listSize; i++)
	{
		if (arrayList->element[i] == value)
		{
			return i + 1;
		}
	}
	return -1;
}

int getPreElement(SeqList<int>*& arrayList, int value)
{
	int temp = -2;
	for (int i = 0; i < arrayList->listSize; i++)
	{
		if (arrayList->element[i] == value && i == 0)
		{// û��ǰ��
			return -1;
		}
		if (arrayList->element[i] == value)
		{// �ҵ�ǰ��
			temp = i - 1;
			break;
		}
	}
	if (temp == -2)
	{// û�и�Ԫ��
		return -2;
	}
	return arrayList->element[temp];
}

int getSeqElement(SeqList<int>*& arrayList, int value)
{
	int temp = -2;
	for (int i = 0; i < arrayList->listSize; i++)
	{
		if (arrayList->element[i] == value && i == arrayList->listSize - 1)
		{// û�к��
			return -1;
		}
		if (arrayList->element[i] == value)
		{// �ҵ����
			temp = i + 1;
			break;
		}
	}
	if (temp == -2)
	{// û�и�Ԫ��
		return -2;
	}
	return arrayList->element[temp];
}

bool insertElement(SeqList<int>*& arrayList, int pos, int value)
{
	if (pos < 1 || pos > arrayList->listSize + 1)
	{
		return false;
	}
	if (arrayList->listSize >= arrayList->capacity)
	{
		try
		{
			int* newbase = new int[LIST_INIT_SIZE + LISTNCREMENT];
			copy(arrayList->element, arrayList->element + LIST_INIT_SIZE, newbase);
			arrayList->element = newbase;
			arrayList->capacity += LISTNCREMENT;
		}
		catch (bad_alloc)
		{
			exit(OVERFLOW);
		}
	}
	for (int i = arrayList->listSize - 1; i >= pos - 1; i--)
	{
		arrayList->element[i + 1] = arrayList->element[i];
	}
	arrayList->element[pos - 1] = value;
	arrayList->listSize++;
	return true;
}

bool deleteElement(SeqList<int>*& arrayList, int pos)
{
	if (pos < 1 || pos > arrayList->listSize)
	{
		return false;
	}

	for (int i = pos - 1; i < arrayList->listSize; i++)
	{
		arrayList->element[i] = arrayList->element[i + 1];
	}
	arrayList->listSize--;
	return true;
}

void printElement(SeqList<int>*& arrayList)
{
	cout << "�����Ա��Ԫ��Ϊ��" << endl;
	for (int i = 0; i < arrayList->listSize; i++)
	{
		cout << arrayList->element[i] << "\t";
	}
	cout << endl;
}

void megerList(SeqList<int>*& arrayList, SeqList<int>*& arrayList2)
{
	int size1 = arrayList->listSize;
	int size2 = arrayList2->listSize;
	int len1 = size1 - 1;
	int len2 = size2 - 1;
	int len = size1 + size2 - 1;
	int begin = 0;

	sort(arrayList->element, arrayList->element + size1);
	sort(arrayList2->element, arrayList2->element + size2);

	SeqList<int>* newList = new SeqList<int>();
	newList->element = new int[size1 + size2]{ -1 };
	newList->listSize = size1 + size2;

	while (len1 >= 0 && len2 >= 0)
	{
		newList->element[len--] = arrayList->element[len1] > arrayList2->element[len2] ? arrayList->element[len1--] : arrayList2->element[len2--];
		int temp = len;
		if (arrayList->element[len1] == newList->element[++temp])
		{
			len1--;
			begin++;
			continue;
		}
		if (arrayList2->element[len2] == newList->element[++temp])
		{
			len2--;
			begin++;
			continue;
		}
	}

	if (len1 >= 0)
	{
		copy(arrayList->element, arrayList->element + (len1 + 1), newList->element);
	}
	if (len2 >= 0)
	{
		copy(arrayList2->element, arrayList2->element + (len2 + 1), newList->element);
	}
	sort(newList->element, newList->element + newList->listSize);

	cout << "�ϲ����˳���Ϊ��" << endl;
	for (int i = begin; i < newList->listSize; i++)
	{
		cout << newList->element[i] << "\t";
	}
	cout << endl;
}