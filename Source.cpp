#include "List.h"
#include <iostream>
#include <Windows.h>
#include <ctime>


using namespace std;


void ListMenu()
{
    cout << "\t\t\t ����\n";
    cout << "1 - ���������� ������ (��� ���������� ��������� \n� �����, ���� ������ ��������) ������� push_back. \n";
    cout << "--------------------------------------------------\n";
    cout << "2 - �������� ������� �������� ������� pop_front. \n";
    cout << "--------------------------------------------------\n";
    cout << "3 - ���������� �������� � ������ ������ ������� push_front. \n";
    cout << "--------------------------------------------------\n";
    cout << "4 - ���������� �������� �� ������� ������� insert. \n";
    cout << "--------------------------------------------------\n";
    cout << "5 - �������� �������� �� ������� ������� removeAt. \n";
    cout << "--------------------------------------------------\n";
    cout << "6 - �������� ������ ������� clear \n(����. ����� ���������� ��������� ���������� �������� ������ ��������������). \n";
    cout << "--------------------------------------------------\n";
    cout << "0 - ����� �� ���������.\n";
    cout << "--------------------------------------------------\n";
    cout << "������� ����� ����: ";
}

int menu()
{
    ListMenu();
    int Case;
    cin >> Case;
    return Case;
}

void logic(List<int>& ls, int& Case, bool& state)
{
    srand(time(NULL));
    do {
        int value = -1;
        int index;

        if (state) Case = menu();

        state = true;

        switch (Case)
        {
        case 1:
            cout << "������� ������ ������: ";
            int Size;
            cin >> Size;
            for (int i = 0; i < Size; i++)
            {
                ls.push_back(rand() % 100);
            }
            break;
        case 2:
            ls.pop_front();
            break;
        case 3:
            cout << "������� �������� ������� ����� �������� � ������ ������: ";
            cin >> value;

            ls.push_front(value);
            break;
        case 4:
            cout << "������� �������� ������� ����� ��������: ";
            cin >> value;
            cout << "\n������� ������ ������ � ������� ����� �������� ��������: ";
            cin >> index;

            ls.insert(value, index);
            break;
        case 5:
            cout << "\n������� ������ � ������� ����� ������� ��������: ";
            cin >> index;

            ls.removeAt(index);
            break;
        case 6:
            ls.clear();
            break;
        case 0:
            cout << "����� �� ���������";
            Sleep(240);
            cout << ".";
            Sleep(240);
            cout << ".";
            Sleep(240);
            cout << ". \n";
            state = false;
            break;
        default:
            cout << "����� ����� ���� �����������, ���������� �����: ";
            break;
        }

        if (state)
        {
            system("cls");
            output(ls);
        }

    } while (Case);
}

void output(List<int>& ls)
{
    for (int i = 0; i < ls.GetSize(); i++)
    {
        cout << i << " �������� � ������: " << ls[i] << endl;
    }
    cout << endl;
}