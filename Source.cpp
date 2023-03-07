#include "List.h"
#include <iostream>
#include <Windows.h>
#include <ctime>


using namespace std;


void ListMenu()
{
    cout << "\t\t\t Меню\n";
    cout << "1 - заполнение списка (или добавлнеие элементов \nв конец, если список заполнен) методом push_back. \n";
    cout << "--------------------------------------------------\n";
    cout << "2 - удаление первого элемента матодом pop_front. \n";
    cout << "--------------------------------------------------\n";
    cout << "3 - добавление значения в начало списка методом push_front. \n";
    cout << "--------------------------------------------------\n";
    cout << "4 - добавление значения по индексу методом insert. \n";
    cout << "--------------------------------------------------\n";
    cout << "5 - удаление значения по индексу методом removeAt. \n";
    cout << "--------------------------------------------------\n";
    cout << "6 - отчистка списка методом clear \n(прим. после заверщения программы деструктор отчистит список самостоятельно). \n";
    cout << "--------------------------------------------------\n";
    cout << "0 - выход из программы.\n";
    cout << "--------------------------------------------------\n";
    cout << "Введите номер меню: ";
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
            cout << "Введите размер списка: ";
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
            cout << "Введите значение которое нужно добавить в начало списка: ";
            cin >> value;

            ls.push_front(value);
            break;
        case 4:
            cout << "Введите значение которое нужно добавить: ";
            cin >> value;
            cout << "\nВведите индекс списка в который нужно вставить значение: ";
            cin >> index;

            ls.insert(value, index);
            break;
        case 5:
            cout << "\nВведите индекс в котором нужно удалить значение: ";
            cin >> index;

            ls.removeAt(index);
            break;
        case 6:
            ls.clear();
            break;
        case 0:
            cout << "Выход из программы";
            Sleep(240);
            cout << ".";
            Sleep(240);
            cout << ".";
            Sleep(240);
            cout << ". \n";
            state = false;
            break;
        default:
            cout << "Такой пункт меню отсутствует, попробуйте снова: ";
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
        cout << i << " значение в списке: " << ls[i] << endl;
    }
    cout << endl;
}