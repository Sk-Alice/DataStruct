#include <stdio.h>
#include <iostream>
#include <vector>
#define MAXSIZE 125000

using namespace std;

struct Triple
{
    int x;
    int y;
    int value;
};

struct TsMatrix
{
    Triple data[MAXSIZE + 1];
    int mu;
    int nu;
    int tu;
};

void initMenu();
bool creatMatrix(TsMatrix*&);
bool destoryMatrix(TsMatrix*&);
void showMatrix(TsMatrix*&);
TsMatrix* transMatrix(TsMatrix*&);
TsMatrix* qTransMatrix(TsMatrix*&);

int main()
{
    TsMatrix* matrix = new TsMatrix();
    initMenu();

    int choice;
    cout << "�����������(end of -1)��";
    cin >> choice;

    while (choice != -1)
    {
        switch (choice)
        {
        case 1:
            if (creatMatrix(matrix))
                cout << "�����ɹ���" << endl;
            break;
        case 2:
            if (destoryMatrix(matrix))
                cout << "���ٳɹ���" << endl;
            break;
        case 3:
            showMatrix(matrix);
            break;
        case 4:
        {
            TsMatrix* newMatrix = transMatrix(matrix);
            cout << "ת�óɹ���" << endl;
            showMatrix(newMatrix);
            break;
        }
        case 5:
        {
            TsMatrix* newMatrix = qTransMatrix(matrix);
            cout << "ת�óɹ���" << endl;
            showMatrix(newMatrix);
            break;
        }
        default:
            break;
        }

        cout << "�����������(end of -1)��";
        cin >> choice;
    }

    return 0;
}

void initMenu()
{
    cout << "1.��������" << endl;
    cout << "2.���پ���" << endl;
    cout << "3.�������" << endl;
    cout << "4.ת�þ���" << endl;
    cout << "5.����ת�þ���" << endl;
}

bool creatMatrix(TsMatrix*& matrix)
{
    cout << "���������������������������Ԫ�ظ���:" << endl;
    cin >> matrix->mu >> matrix->nu >> matrix->tu;

    while (matrix->mu * matrix->nu < matrix->tu)
    {
        cout << "������󣬷���Ԫ�ظ���ҪС�ڵ�������������������������!" << endl;
        cin >> matrix->mu >> matrix->nu >> matrix->tu;
    }

    vector<int> tmpX(matrix->tu + 5), tmpY(matrix->tu + 5), tmpVal(matrix->tu + 5);
    cout << "�밴��x, y, value��˳������Ԫ��" << endl;

    for (int i = 1; i <= matrix->tu; i++)
    {
        cin >> tmpX[i] >> tmpY[i] >> tmpVal[i];
        while (tmpX[i] > matrix->mu || tmpY[i] > matrix->nu)
        {
            cout << "��������±�Խ�磬���������룡" << endl;
            cin >> tmpX[i] >> tmpY[i] >> tmpVal[i];
        }
        while (tmpX[i] < tmpX[i - 1] || (tmpX[i] == tmpX[i - 1] && tmpY[i] < tmpX[i - 1]))
        {
            cout << "��������±�����ʱҪ�������룬����������!" << endl;
            cin >> tmpX[i] >> tmpY[i] >> tmpVal[i];
        }
        for (int j = 1; j < i; j++)
        {
            while (tmpX[i] == tmpX[j] && tmpY[i] == tmpY[j])
            {
                cout << "�������������±��ظ������������룡" << endl;
                cin >> tmpX[i] >> tmpY[i] >> tmpVal[i];
                j = 1;
            }
        }
        matrix->data[i].x = tmpX[i];
        matrix->data[i].y = tmpY[i];
        matrix->data[i].value = tmpVal[i];
    }
    return true;
}

bool destoryMatrix(TsMatrix*& matrix)
{
    delete matrix->data;
    matrix->mu = 0;
    matrix->nu = 0;
    matrix->tu = 0;
    return true;
}

void showMatrix(TsMatrix*& matrix)
{
    int k = 1;
    for (int i = 1; i <= matrix->mu; i++)
    {
        for (int j = 1; j <= matrix->nu; j++)
        {
            if (i == matrix->data[k].x && j == matrix->data[k].y)
                cout << matrix->data[k++].value << "\t";
            else
                cout << 0 << "\t";
        }
        cout << endl;
    }
}

TsMatrix* transMatrix(TsMatrix*& matrix)
{
    TsMatrix* newMatrix = new TsMatrix();
    newMatrix->mu = matrix->nu;
    newMatrix->nu = matrix->mu;
    newMatrix->tu = matrix->tu;

    if (newMatrix->tu)
    {
        int t = 1;
        for (int i = 1; i <= matrix->nu; i++)
        {
            for (int j = 1; j <= matrix->tu; j++)
            {
                if (matrix->data[j].y == i)
                {
                    newMatrix->data[t].x = matrix->data[j].y;
                    newMatrix->data[t].y = matrix->data[j].x;
                    newMatrix->data[t].value = matrix->data[j].value;
                    t++;
                }
            }
        }
    }
    return newMatrix;
}

TsMatrix* qTransMatrix(TsMatrix*& matrix)
{
    TsMatrix* newMatrix = new TsMatrix();
    newMatrix->mu = matrix->nu;
    newMatrix->nu = matrix->mu;
    newMatrix->tu = matrix->tu;
    vector<int> num(matrix->nu + 5), cpot(matrix->nu + 5);

    if (newMatrix->tu)
    {
        for (int i = 1; i <= matrix->tu; i++)
        {
            num[matrix->data[i].y]++;
        }
        cpot[1] = 1;
        for (int i = 2; i <= matrix->nu; i++)
        {
            cpot[i] = cpot[i - 1] + num[i - 1];
        }
        for (int i = 1; i <= matrix->tu; i++)
        {
            int col = matrix->data[i].y;
            int t = cpot[col];
            newMatrix->data[t].x = matrix->data[i].y;
            newMatrix->data[t].y = matrix->data[i].x;
            newMatrix->data[t].value = matrix->data[i].value;
            cpot[col]++;
        }
    }
    return newMatrix;
}