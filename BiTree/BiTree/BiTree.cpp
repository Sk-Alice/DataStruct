#include <iostream>
#include <string>
#include <queue>
#define STACK_INIT_SIZE 100

using namespace std;

struct BiTree
{
    BiTree* lchild;
    BiTree* rchild;
    char data;
};

void InitMenu();
BiTree* DLR_CreateBiTree(BiTree*);
void DLR(BiTree*);
void LDR_1(BiTree*);
void LDR_2(BiTree*);
void LRD(BiTree*);
void LevelOrder(BiTree*);
int Depth(BiTree*);

int main()
{
    BiTree* root = nullptr;
    int choice = 0;
    InitMenu();

    cout << "�����������(end of -1)��";
    cin >> choice;

    while (choice != -1)
    {
        char tmp = getchar();
        switch (choice)
        {
        case 1:
            cout << "������Ԫ�����ݣ�" << endl;
            root = DLR_CreateBiTree(root);
            cout << "�����ɹ���" << endl;
            break;
        case 2:
            cout << "���������������" << endl;
            DLR(root);
            cout << endl;
            break;
        case 3:
            cout << "���������������" << endl;
            LDR_1(root);
            cout << endl;
            break;
        case 4:
            cout << "���������������" << endl;
            LDR_2(root);
            cout << endl;
            break;
        case 5:
            cout << "���������������" << endl;
            LRD(root);
            cout << endl;
            break;
        case 6:
            cout << "��α�����������" << endl;
            LevelOrder(root);
            cout << endl;
            break;
        case 7:
            cout << "�������Ϊ��" << Depth(root) << endl;
            break;
        default:
            break;
        }

        cout << "�����������(end of -1)��";
        cin >> choice;
    }
    return 0;
}

void InitMenu()
{
    cout << "1.����������" << endl;
    cout << "2.�������������" << endl;
    cout << "3.�������������1" << endl;
    cout << "4.�������������2" << endl;
    cout << "5.�������������" << endl;
    cout << "6.��α���������" << endl;
    cout << "7.���ض����������" << endl;
}

BiTree* DLR_CreateBiTree(BiTree* root)
{
    char c;
    c = getchar();
    char tmp = getchar();
    if (c == ' ') {
        return nullptr;
    }

    root = new BiTree();
    root->data = c;
    root->lchild = DLR_CreateBiTree(root->lchild);
    root->rchild = DLR_CreateBiTree(root->rchild);
    return root;
}

void DLR(BiTree* root)
{
    if (root)
    {
        cout << root->data << "\t";
        DLR(root->lchild);
        DLR(root->rchild);
    }
}

void LDR_1(BiTree* root) 
{
    BiTree* bt = root;
    BiTree* st[STACK_INIT_SIZE];
    int top = 0;

    while (bt || top != 0)
    {
        while (bt)
        {
            st[top++] = bt;
            bt = bt->lchild;
        }
        if (st)
        {
            bt = st[--top];
            cout << bt->data << "\t";
            bt = bt->rchild;
        }
    }
}

void LDR_2(BiTree* root) 
{
    BiTree* bt = root;
    BiTree* st[STACK_INIT_SIZE];
    int top = 0;

    while (bt || top != 0)
    {
        if (bt)
        {
            st[top++] = bt;
            bt = bt->lchild;
        }
        else 
        {
            bt = st[--top];
            cout << bt->data << "\t";
            bt = bt->rchild;
        }
    }
}

void LRD(BiTree* root)
{
    if (root)
    {
        LRD(root->lchild);
        LRD(root->rchild);
        cout << root->data << "\t";
    }
}

void LevelOrder(BiTree* root)
{
    queue<BiTree*> q;
    q.push(root);

    while (!q.empty())
    {
        BiTree* bt = q.front();
        q.pop();
        cout << bt->data << "\t";

        if (bt->lchild) q.push(bt->lchild);
        if (bt->rchild) q.push(bt->rchild);
    }
}

int Depth(BiTree* root)
{
    if (root == nullptr)
    {
        return 0;
    }

    int hl = Depth(root->lchild);
    int hr = Depth(root->rchild);
    return max(hl, hr) + 1;
}
