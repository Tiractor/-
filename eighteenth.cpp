#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector <int> mass;

// Доп. Функции

void MassBaseInit() {
    mass.push_back(2);
    mass.push_back(1);
    mass.push_back(9);
    mass.push_back(5);
    mass.push_back(12);
    mass.push_back(2);
}

void MassCustomInit() {
    int N, p;
    cout << "Input lengh of array" << endl;
    cin >> N;
    cout << "Input elements of array" << endl;
    for (int i = 0; i < N; i++) {
        cin >> p;
        mass.push_back(p);
    }
}

void MassOutput() {
    for (int i = 0; i < mass.size(); i++) {
        cout << mass[i] << " ";
    }
    cout << endl;
}

int SrArif(int i) {
    int sum, j;
    sum = 0;
    j = 0;
    for (; j <= i; j++) {
        sum += mass[j];
    }
    return int(sum / j);
}

// 18 Лаба

int Lab18_First()
{
    int Pot;
    int c;
    vector <int> A = { 0, 3, 4, 6 };
    vector <int> B = { 0, 1, 4, 2 };
    cout << "if you want custom array - input 1. Else input 0";
    cin >> c;
    if (c == 1) {
        int N, p;
        A.clear();
        B.clear();
        cout << "Input lengh of array" << endl;
        cin >> N;
        cout << "Input elements of First array" << endl;
        for (int i = 0; i < N; i++) {
            cin >> p;
            A.push_back(p);
        }
        cout << "Input elements of Second array" << endl;
        for (int i = 0; i < N; i++) {
            cin >> p;
            B.push_back(p);
        }
    }

    for (int i = 0; i < A.size(); i++) {
        Pot = A[i];
        A[i] = B[i];
        B[i] = Pot;
    }
    for (int i = 0; i < A.size(); i++) {
        cout << A[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < A.size() - 1; i++) {
        cout << B[i] << " ";
    }
    return B[B.size() - 1];
}

char Lab18_Second()
{
    vector <int> B;
    for (int i = 0; i < mass.size(); i++) {
        B.push_back(SrArif(i));
    }
    for (int i = 0; i < mass.size(); i++) {
        cout << B[i] << " ";
    }
    return ' ';
}

char Lab18_Third()
{
    int c = 0;
    for (int i = 0; i < mass.size(); i++) {
        if (mass[i] % 2 == 1) {
            c = mass[i];
        }
    }
    for (int i = 0; i < mass.size(); i++) {
        if (mass[i] % 2 == 1) {
            mass[i] += c;
        }
    }
    MassOutput();
    return ' ';
}

char Lab18_Fourth()
{
    int a = distance(mass.begin(), max_element(mass.begin(), mass.end()));
    int b = distance(mass.begin(), min_element(mass.begin(), mass.end())) + 1;
    for (int i = b; i < a; i++) {
        mass[i] = 0;
    }
    MassOutput();
    return ' ';
}

char Lab18_Fifth()
{
    sort(mass.begin(), mass.end());
    MassOutput();
    return ' ';
}

void Menu() {
    int c;
    cout << "Input number of question (1-5)";
    cin >> c;
    if (c == 1) cout << Lab18_First();
    else if (c == 2) cout << Lab18_Second();
    else if (c == 3) cout << Lab18_Third();
    else if (c == 4) cout << Lab18_Fourth();
    else if (c == 5) cout << Lab18_Fifth();
}

int main()
{
    int c;
    cout << "If you want custom array - write 1. else write 0 (For questions 2-5)" << endl;
    cin >> c;
    if(c == 0) MassBaseInit();
    if(c == 1) MassCustomInit();
    Menu();
    while (true) {
        cout << endl << endl << "If you want switch question - write 1" << endl << "If you want switch array and switch quesion - write 2" << endl << "If you want end this - write 3" << endl;
        cout <<"If you want watch array - write 4" << endl << "Remember array can be changed after question" << endl;
        cin >> c;
        if (c == 1) Menu();
        else if (c == 2) {
            MassCustomInit();
            Menu();
        }
        else if (c == 3) break;
        else if (c == 4) MassOutput();
    }
    
    
    return 0;
}
