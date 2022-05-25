#include <iostream>
#include <Windows.h>
#include <iomanip> 

using namespace std;

typedef int Info;
struct Elem
{
    Elem* link;
    Info info;
};

void insert(Elem*& L, Info value)
{
    Elem* tmp = new Elem;
    tmp->info = value;

    if (L != NULL)
    {
        Elem* T = L;
        while (T->link != L)
            T = T->link;
        T->link = tmp;
    }
    else
    {
        L = tmp;
    }

    tmp->link = L;
}

void print(Elem* L) 
{
    if (L == NULL)
        return;
    Elem* first = L;
    cout << setw(0) << L->info;
    while (L->link != first)
    {
        L = L->link;
        cout << setw(2) << L->info;
    }
    cout << endl;
}

void remove(Elem*& L)
{
    Elem* T = L;
    while (T->link != L)
        T = T->link;

    if (T != L)
    {
        Elem* tmp = L->link;
        delete L;
        L = tmp;
        T->link = L;
    }
    else
    {
        delete L;
        L = NULL;
    }
}

void increm(Elem* L, Info value)
{
    Elem* first = L;
    while (L->link != first)
    {
        L->info += value;
        L = L->link;
        if (L->link == first)
        {
            L->info += value;
        }
    }
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Elem* L = NULL;

    int N, value, incr;
   
    cout << "¬вед≥ть к≥льк≥сть елемент≥в: "; cin >> N;

    for (int i = 0; i < N; i++)
    {
        cout << "¬вед≥ть значенн€ " << i + 1 << " елементу: "; cin >> value;
        insert(L, value);
    }
    cout << endl;

    cout << "—писок: "; print(L); cout << endl;

    cout << "¬вед≥ть число, на €ке потр≥бно зб≥льшити ≥нформац≥йне поле кожного елементу: ";
    cin >> incr; cout << endl;

    increm(L, incr);

    cout << "«м≥нений список: "; print(L); cout << endl << endl;

    for (int i = 0; i < N; i++)
    {
        remove(L);
    }

    system("pause");
    return 0;
}