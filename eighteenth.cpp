#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector <int> mass;

// Доп. Функции

void MassBaseInit(){
    mass.push_back(2);
    mass.push_back(1);
    mass.push_back(9);
    mass.push_back(5);
    mass.push_back(12);
    mass.push_back(2);
}

void MassCustomInit(){
    int N,p;
    cin >> N;
    for (int i = 0; i < N; i++){
        cin >> p;
        mass.push_back(p);
    }
}

void MassOutput(){
    for (int i = 0; i < mass.size(); i++){
        cout << mass[i] << " ";
    }
    cout << endl;
}

int SrArif(int i){
    int sum,j;
    sum = 0;
    j = 0;
    for(; j <= i; j++){
        sum+=mass[j];
    }
    return int(sum/j);
}

// 18 Лаба

int Lab18_First()
{
    int Pot;
    const int N = 4; // Сюда вводить число N
    int A[N] = {0, 3, 4, 6};
    int B[N] = {0, 1, 4, 2};
    for(int i = 0; i < N; i++){
        Pot = A[i];
        A[i] = B[i];
        B[i] = N;
     }
    for(int i = 0; i < N; i++){
        cout << A[i] << " ";
     }
    cout << endl;
    for(int i = 0; i < N-1; i++){
        cout << B[i] << " ";
     }
    return B[N-1];
}

int Lab18_Second()
{
    const int N = 4;
    int B[N];
    for (int i = 0; i <= N; i++){
        B[i] = SrArif(i);
    }
    for(int i = 0; i < N; i++){
        cout << B[i] << " ";
     }
    return B[N];
}

char Lab18_Third()
{
    int c = 0;
    for (int i = 0; i < mass.size(); i++){
        if (mass[i] % 2 == 1){
            c = mass[i];
        }
    }
    for (int i = 0; i < mass.size(); i++){
        if (mass[i] % 2 == 1){
            mass[i] += c;
        }
    }
    MassOutput();
    return ' ';
}

char Lab18_Fourth()
{
    int a = distance(mass.begin(),max_element(mass.begin(),mass.end()));
    int b = distance(mass.begin(), min_element(mass.begin(), mass.end()))+1;
    for (int i = b; i < a; i++){
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

int main()
{
    MassBaseInit();
    cout << Lab17_First();
    return 0;
}
