#include <iostream>
#include <string.h>
#include <cstring>
#include <Windows.h>
#include <sstream>
#define STACK_INIT_SIZE 100
#define STACK_INCREMENT 10

using namespace std;

struct SqStack
{
    int* base;
    int* top;
    int stackSize;
};

void initMenu();
bool initStack(SqStack*&);
bool destoryStack(SqStack*&);
bool clearStack(SqStack*&);
int isEmpty(SqStack*&);
int getLength(SqStack*&);
int getTop(SqStack*&);
int push(SqStack*&, int);
int pop(SqStack*&);
void showStack(SqStack*&);
string converseTo2(int);
string converseTo8(int);
string converseTo16(int);

int main()
{
    initMenu();
    SqStack* S = new SqStack;
    S->base = nullptr;
    int choice = 0;

    cout << "����������ѡ��(end of -1)��";
    cin >> choice;

    do
    {
        switch (choice)
        {
        case 1:
        {
            if (initStack(S))
            {
                cout << "��ʼ���ɹ���" << endl;
            }
            else
            {
                cout << "��ʼ��ʧ�ܣ�" << endl;
            }
            break;
        }
        case 2:
        {
            if (destoryStack(S))
            {
                cout << "���ٳɹ���" << endl;
            }
            break;
        }
        case 3:
        {
            if (!S->base)
            {
                cout << "��ջδ��ʼ����" << endl;
                break;
            }
            else if (clearStack(S))
            {
                cout << "��ճɹ���" << endl;
                break;
            }
            cout << "���ʧ�ܣ�" << endl;
            break;
        }
        case 4:
        {
            int value = isEmpty(S);
            if (value == -1)
            {
                cout << "��ջδ��ʼ����" << endl;
            }
            else if (value == 1)
            {
                cout << "��ջΪ�գ�" << endl;
            }
            else
            {
                cout << "��ջ��Ϊ��!" << endl;
            }
            break;
        }
        case 5:
        {
            int len = getLength(S);
            if (len == -1)
            {
                cout << "��ջδ��ʼ����" << endl;
                break;
            }
            cout << "��ջ�ĳ���Ϊ��" << len << endl;
            break;
        }
        case 6:
        {
            int value = getTop(S);
            if (value == -1)
            {
                cout << "��ջδ��ʼ����" << endl;
            }
            else if (value == 0)
            {
                cout << "��ջΪ��ջ��" << endl;
            }
            else
            {
                cout << "ջ��Ԫ��Ϊ��" << value << endl;
            }
            break;
        }
        case 7:
        {
            int value = -1;
            cout << "������Ҫ����ջ����Ԫ�أ�";
            cin >> value;
            int res = push(S, value);
            if (res == -1)
            {
                cout << "��ջδ��ʼ��" << endl;
            }
            else if (res == 1)
            {
                cout << "ѹջ�ɹ���" << endl;
            }
            else
            {
                cout << "ѹջʧ��!" << endl;
            }
            break;
        }
        case 8:
        {
            int res = pop(S);
            if (res == -1)
            {
                cout << "��ջδ��ʼ����" << endl;
                break;
            }
            else if (res == -2)
            {
                cout << "��ջΪ��ջ��" << endl;
                break;
            }
            cout << "ɾ���ɹ���ɾ����Ԫ��Ϊ��" << res << endl;
            break;
        }
        case 9:
        {
            showStack(S);
            break;
        }
        case 10:
        {
            int convertNum = -1;
            cout << "������Ҫת��������";
            cin >> convertNum;
            cout << "����תΪ������Ϊ��" << converseTo2(convertNum) << endl;
            cout << "����תΪ�˽���Ϊ��" << converseTo8(convertNum) << endl;
            cout << "����תΪʮ������Ϊ��" << converseTo16(convertNum) << endl;
            break;
        }
        default:
            break;
        }

        Sleep(700);
        system("cls");
        initMenu();

        cout << "����������ѡ��(end of -1)��";
        cin >> choice;
    } while (choice != -1);

    return 0;
}

void initMenu()
{
    cout << "1.��ʼ��ջ" << endl;
    cout << "2.����ջ" << endl;
    cout << "3.���ջ" << endl;
    cout << "4.�ж�ջ�Ƿ�Ϊ��" << endl;
    cout << "5.����ջ����" << endl;
    cout << "6.����ջ��Ԫ��" << endl;
    cout << "7.����һ��Ԫ��" << endl;
    cout << "8.ɾ��һ��Ԫ��" << endl;
    cout << "9.�������Ԫ��" << endl;
    cout << "10.����ת��" << endl;
}

bool initStack(SqStack*& S)
{
    try
    {
        S->base = new int[STACK_INIT_SIZE];
        S->top = S->base;
        S->stackSize = STACK_INIT_SIZE;
        return true;
    }
    catch (exception e)
    {
        return false;
    }
}

bool destoryStack(SqStack*& S)
{
    delete S->base;
    S->base = nullptr;
    S->top = nullptr;
    S->stackSize = 0;

    return true;
}

bool clearStack(SqStack*& S)
{
    S->top = S->base;

    return true;
}

int isEmpty(SqStack*& S)
{
    if (!S->base)
    {
        return -1;
    }
    else if (S->top > S->base)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

int getLength(SqStack*& S)
{
    if (!S->base)
    {
        return -1;
    }

    return S->top - S->base;
}

int getTop(SqStack*& S)
{
    if (!S->base)
    {
        return -1;
    }
    else if (S->base == S->top)
    {
        return 0;
    }

    return *(S->top - 1);
}

int push(SqStack*& S, int value)
{
    if (!S->base)
    {
        return -1;
    }
    if (S->top - S->base == STACK_INIT_SIZE)
    {
        int* temp = S->base;
        S->base = new int[STACK_INIT_SIZE + STACK_INCREMENT];
        memcpy(S->base, temp, STACK_INIT_SIZE);
        S->top = S->base + STACK_INIT_SIZE;
    }
    *S->top = value;
    ++S->top;

    return 1;
}

int pop(SqStack*& S)
{
    if (!S->base)
    {
        return -1;
    }
    else if (S->base == S->top)
    {
        return -2;
    }
    return *--S->top;
}

void showStack(SqStack*& S)
{
    if (!S->base)
    {
        cout << "��ջδ��ʼ����" << endl;
        return;
    }
    else if (S->top == S->base)
    {
        cout << "��ջΪ��ջ��" << endl;
        return;
    }
    int* p = S->base;

    cout << "��ջ������Ԫ��Ϊ��" << endl;
    while (p != S->top)
    {
        cout << *p << "\t";
        p++;
    }
    cout << endl;
}

string converseTo2(int value)
{
    int temp = value;
    SqStack* C = new SqStack;
    initStack(C);
    stringstream ans;

    while (temp != 0)
    {
        push(C, temp % 2);
        temp /= 2;
    }
    while (!isEmpty(C))
    {
        ans << pop(C);
    }
    return ans.str();
}

string converseTo8(int value)
{
    int temp = value;
    SqStack* C = new SqStack;
    initStack(C);
    stringstream ans;

    while (temp != 0)
    {
        push(C, temp % 8);
        temp /= 8;
    }
    while (!isEmpty(C))
    {
        ans << pop(C);
    }
    return ans.str();
}

string converseTo16(int value)
{
    int temp = value;
    SqStack* C = new SqStack;
    initStack(C);
    stringstream ans;

    while (temp != 0)
    {
        push(C, temp % 16);
        temp /= 16;
    }
    while (!isEmpty(C))
    {
        ans << pop(C);
    }
    return ans.str();
}
