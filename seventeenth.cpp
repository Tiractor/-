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

// 17 Лаба

int Lab17_First()
{
    int K, L;
    cout << "Input first and last iterator" << endl;
    cin >> K >> L;
    int Sum, i;
    Sum = 0;
    i = K - 1;
    for (; i < L; i++) {
        Sum += mass[i];
    }
    cout << "Middle arifm this - " << endl;
    return int(Sum / i);
}

int Lab17_Second()
{
    int d = mass[1] - mass[0];
    for (int i = 1; i < mass.size() - 1; i++) {
        if (mass[i + 1] - mass[i] != d) {
            return 0;
        }
    }
    return d;
}

int Lab17_Third()
{
    int min = 9999;
    for (int i = 0; i < mass.size(); i++) {
        if (mass[i] < min && (i + 1) % 2 == 0) {
            min = mass[i];
        }
    }
    return min;
}

int Lab17_Fourth() {
    int local_max = 0;
    for (int i = 1; i < mass.size() - 1; i++) {
        if (mass[i] > mass[i - 1] && mass[i] > mass[i + 1]) {
            local_max = i;
        }
    }
    return local_max + 1;
}

int Lab17_Fifth() {
    for (int i = 0; i < mass.size() - 1; i++) {
        for (int j = i + 1; j < mass.size(); j++) {
            if (mass[i] == mass[j]) {
                cout << i + 1 << " ";
                return j + 1;
            }
        }
    }
    return 0;
}


void Menu() {
    int c;
    cout << "Input number of question (1-5)";
    cin >> c;
    if (c == 1) cout << Lab17_First();
    else if (c == 2) cout << Lab17_Second();
    else if (c == 3) cout << Lab17_Third();
    else if (c == 4) cout << Lab17_Fourth();
    else if (c == 5) cout << Lab17_Fifth();
}

int main()
{
    int c;
    cout << "If you want custom array - write 1. else write 0" << endl;
    cin >> c;
    if(c == 0) MassBaseInit();
    if(c == 1) MassCustomInit();
    Menu();
    while (true) {
        cout << endl << endl << "If you want switch question - write 1" << endl << "If you want switch array and switch quesion - write 2" << endl << "If you want end this - write 3" << endl;
        cin >> c;
        if (c == 1) Menu();
        if (c == 2) {
            MassCustomInit();
            Menu();
        }

        if (c == 3) break;
    }
    
    
    return 0;
}
