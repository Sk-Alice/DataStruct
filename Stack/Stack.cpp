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

    cout << "请输入您的选择(end of -1)：";
    cin >> choice;

    do
    {
        switch (choice)
        {
        case 1:
        {
            if (initStack(S))
            {
                cout << "初始化成功！" << endl;
            }
            else
            {
                cout << "初始化失败！" << endl;
            }
            break;
        }
        case 2:
        {
            if (destoryStack(S))
            {
                cout << "销毁成功！" << endl;
            }
            break;
        }
        case 3:
        {
            if (!S->base)
            {
                cout << "该栈未初始化！" << endl;
                break;
            }
            else if (clearStack(S))
            {
                cout << "清空成功！" << endl;
                break;
            }
            cout << "清空失败！" << endl;
            break;
        }
        case 4:
        {
            int value = isEmpty(S);
            if (value == -1)
            {
                cout << "该栈未初始化！" << endl;
            }
            else if (value == 1)
            {
                cout << "该栈为空！" << endl;
            }
            else
            {
                cout << "该栈不为空!" << endl;
            }
            break;
        }
        case 5:
        {
            int len = getLength(S);
            if (len == -1)
            {
                cout << "该栈未初始化！" << endl;
                break;
            }
            cout << "该栈的长度为：" << len << endl;
            break;
        }
        case 6:
        {
            int value = getTop(S);
            if (value == -1)
            {
                cout << "该栈未初始化！" << endl;
            }
            else if (value == 0)
            {
                cout << "该栈为空栈！" << endl;
            }
            else
            {
                cout << "栈顶元素为：" << value << endl;
            }
            break;
        }
        case 7:
        {
            int value = -1;
            cout << "请输入要推入栈顶的元素：";
            cin >> value;
            int res = push(S, value);
            if (res == -1)
            {
                cout << "该栈未初始化" << endl;
            }
            else if (res == 1)
            {
                cout << "压栈成功！" << endl;
            }
            else
            {
                cout << "压栈失败!" << endl;
            }
            break;
        }
        case 8:
        {
            int res = pop(S);
            if (res == -1)
            {
                cout << "该栈未初始化！" << endl;
                break;
            }
            else if (res == -2)
            {
                cout << "该栈为空栈！" << endl;
                break;
            }
            cout << "删除成功！删除的元素为：" << res << endl;
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
            cout << "请输入要转换的数：";
            cin >> convertNum;
            cout << "该数转为二进制为：" << converseTo2(convertNum) << endl;
            cout << "该数转为八进制为：" << converseTo8(convertNum) << endl;
            cout << "该数转为十六进制为：" << converseTo16(convertNum) << endl;
            break;
        }
        default:
            break;
        }

        Sleep(700);
        system("cls");
        initMenu();

        cout << "请输入您的选择(end of -1)：";
        cin >> choice;
    } while (choice != -1);

    return 0;
}

void initMenu()
{
    cout << "1.初始化栈" << endl;
    cout << "2.销毁栈" << endl;
    cout << "3.清空栈" << endl;
    cout << "4.判断栈是否为空" << endl;
    cout << "5.返回栈长度" << endl;
    cout << "6.返回栈顶元素" << endl;
    cout << "7.插入一个元素" << endl;
    cout << "8.删除一个元素" << endl;
    cout << "9.输出所有元素" << endl;
    cout << "10.进制转换" << endl;
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
        cout << "该栈未初始化！" << endl;
        return;
    }
    else if (S->top == S->base)
    {
        cout << "该栈为空栈！" << endl;
        return;
    }
    int* p = S->base;

    cout << "该栈的所有元素为：" << endl;
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
