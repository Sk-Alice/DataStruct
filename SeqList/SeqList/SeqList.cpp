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
	cout << "请输入操作代码：";
	cin >> choice;

	while (choice > 0)
	{
		switch (choice)
		{
		case 1://初始化线性表空间
		{
			arrayList = initList();
			break;
		}
		case 2://销毁线性表
		{
			bool isTrue = distroyList(arrayList);
			if (isTrue)
			{
				cout << "销毁成功！" << endl;
			}
			else
			{
				cout << "销毁失败！" << endl;
				exit(1);
			}
			break;
		}
		case 3://清空线性表
		{
			bool isTrue = clearList(arrayList);
			if (isTrue)
			{
				cout << "清空成功！" << endl;
			}
			else
			{
				cout << "清空失败！" << endl;
				exit(1);
			}
			break;
		}
		case 4://判断线性表是否为空
		{
			bool isTrue = isEmpty(arrayList);
			if (isTrue)
			{
				cout << "该表为空" << endl;
			}
			else
			{
				cout << "该表不为空" << endl;
			}
			break;
		}
		case 5://求线性表的长度
		{
			if (arrayList->element == nullptr)
			{
				cout << "请先初始化顺序表!" << endl;
				break;
			}
			cout << "线性表的长度为：" << getLength(arrayList) << endl;
			break;
		}
		case 6://获取线性表中指定位置的元素
		{
			if (arrayList->element == nullptr)
			{
				cout << "请先初始化顺序表!" << endl;
				break;
			}
			if (isEmpty(arrayList))
			{
				cout << "请先为顺序表添加元素！" << endl;
				break;
			}
			int index;
			cout << "请输入要查找元素的位置：";
			cin >> index;
			int temp = getElement(arrayList, index);
			if (temp == -1)
			{
				cerr << "访问越界！" << endl;
			}
			else
			{
				cout << "该元素为：" << temp << endl;
			}
			break;
		}
		case 7://获取线性表元素的位置
		{
			if (arrayList->element == nullptr)
			{
				cout << "请先初始化顺序表!" << endl;
				break;
			}
			if (isEmpty(arrayList))
			{
				cout << "请先为顺序表添加元素！" << endl;
				break;
			}
			int num;
			cout << "请输入您要查找的元素：";
			cin >> num;
			int temp = getPosition(arrayList, num);
			if (temp == -1)
			{
				cerr << "线性表中没有该元素！" << endl;
			}
			else
			{
				cout << "该元素的下标为：" << temp << endl;
			}
			break;
		}
		case 8://求前驱
		{
			if (arrayList->element == nullptr)
			{
				cout << "请先初始化顺序表!" << endl;
				break;
			}
			if (isEmpty(arrayList))
			{
				cout << "请先为顺序表添加元素！" << endl;
				break;
			}
			int num;
			cout << "请输入求前驱的元素：";
			cin >> num;
			int temp = getPreElement(arrayList, num);
			if (temp == -1)
			{
				cout << "该元素没有前驱！" << endl;
			}
			else if (temp == -2)
			{
				cerr << "线性表中没有该元素!" << endl;
			}
			else
			{
				cout << "该元素的前驱为：" << temp << endl;
			}
			break;
		}
		case 9://求后继
		{
			if (arrayList->element == nullptr)
			{
				cout << "请先初始化顺序表!" << endl;
				break;
			}
			if (isEmpty(arrayList))
			{
				cout << "请先为顺序表添加元素！" << endl;
				break;
			}
			int num;
			cout << "请输入求后继的元素：";
			cin >> num;
			int temp = getSeqElement(arrayList, num);
			if (temp == -1)
			{
				cout << "该元素没有后继！" << endl;
			}
			else if (temp == -2)
			{
				cerr << "线性表中没有该元素!" << endl;
			}
			else
			{
				cout << "该元素的后继为：" << temp << endl;
			}
			break;
		}
		case 10://在线性表指定位置插入元素
		{
			if (arrayList->element == nullptr)
			{
				cout << "请先初始化顺序表!" << endl;
				break;
			}
			int index, num;
			cout << "请输入要插入的位置下标与元素（end of -1）：";
			cin >> index >> num;
			while (index != -1)
			{
				bool isTrue = insertElement(arrayList, index, num);
				if (!isTrue)
				{
					cerr << "错误插入！" << endl;
					exit(1);
				}
				else
				{
					cout << "插入成功！" << endl;
					cout << "请输入要插入的位置下标与元素（end of -1）：";
					cin >> index >> num;
				}
			}
			break;
		}
		case 11://删除线性表指定位置的元素
		{
			if (arrayList->element == nullptr)
			{
				cout << "请先初始化顺序表!" << endl;
				break;
			}
			if (isEmpty(arrayList))
			{
				cout << "该顺序表已空！" << endl;
				break;
			}
			int index;
			cout << "请输入要删除的位置：";
			cin >> index;
			bool isTrue = deleteElement(arrayList, index);
			if (!isTrue)
			{
				cerr << "删除失败！" << endl;
				exit(1);
			}
			else
			{
				cout << "删除成功！" << endl;
			}
			{}
			break;
		}
		case 12://显示线性表
		{
			if (arrayList->element == nullptr)
			{
				cout << "请先初始化顺序表!" << endl;
				break;
			}
			if (isEmpty(arrayList))
			{
				cout << "请先为顺序表添加元素！" << endl;
				break;
			}
			printElement(arrayList);
			break;
		}
		case 13://合并两个非递减有序的线性表
		{
			if (arrayList->element == nullptr)
			{
				cout << "请先初始化顺序表!" << endl;
				break;
			}
			if (isEmpty(arrayList))
			{
				cout << "请先为顺序表添加元素！" << endl;
				break;
			}
			cout << "自动创建一个新的线性表！" << endl;
			SeqList<int>* myList = initList();
			int index, num;
			cout << "请输入要插入的位置下标与元素（end of -1）：";
			cin >> index >> num;
			while (index != -1)
			{
				insertElement(myList, index, num);
				cout << "请输入要插入的位置下标与元素（end of -1）：";
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
		cout << "请输入操作代码：";
		cin >> choice;
	}
	cout << "程序退出!" << endl;
	return 0;
}

void initMenu()
{
	cout << "*************************" << endl;
	cout << "1---初始化线性表" << endl;
	cout << "2---销毁线性表" << endl;
	cout << "3---清空线性表" << endl;
	cout << "4---判断线性表是否为空" << endl;
	cout << "5---求线性表的长度" << endl;
	cout << "6---获取线性表中指定位置的元素" << endl;
	cout << "7---获取线性表元素的位置" << endl;
	cout << "8---求前驱" << endl;
	cout << "9---求后继" << endl;
	cout << "10---在线性表指定位置插入元素" << endl;
	cout << "11---删除线性表指定位置的元素" << endl;
	cout << "12---显示线性表" << endl;
	cout << "13---合并两个非递减有序的线性表" << endl;
	cout << "14---退出程序(输入负数)" << endl;
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
		cerr << "初始化失败！" << endl;
		exit(1);
	}

	cout << "初始化成功!" << endl;
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
		{// 没有前驱
			return -1;
		}
		if (arrayList->element[i] == value)
		{// 找到前驱
			temp = i - 1;
			break;
		}
	}
	if (temp == -2)
	{// 没有该元素
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
		{// 没有后继
			return -1;
		}
		if (arrayList->element[i] == value)
		{// 找到后继
			temp = i + 1;
			break;
		}
	}
	if (temp == -2)
	{// 没有该元素
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
	cout << "该线性表的元素为：" << endl;
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

	cout << "合并后的顺序表为：" << endl;
	for (int i = begin; i < newList->listSize; i++)
	{
		cout << newList->element[i] << "\t";
	}
	cout << endl;
}