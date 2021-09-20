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

// 17 Лаба

int Lab17_First()
{
    int K,L;
    cin >> K >> L;
    int Sum, i;
    i = K-1;
    for ( ; i < L; i++){
        Sum+=mass[i];
    }
    return int(Sum/i);
}

int Lab17_Second()
{
    int d = mass[1]-mass[0];
    for(int i = 1; i < mass.size()-1; i++){
        if(mass[i+1]-mass[i] != d){
        return 0;
        }
    }
    return d;
}

int Lab17_Third()
{
    int min = 9999;
    for(int i = 0; i < mass.size(); i++){
        if(mass[i] < min && (i+1) % 2 == 0){
        min = mass[i];
        }
    }
    return min;
}

int Lab17_Fourth(){
    int local_max = 0;
    for(int i = 1; i < mass.size()-1; i++){
        if(mass[i] > mass[i-1] && mass[i] > mass[i+1]){
         local_max = i;
        }
    }
    return local_max+1;
}

int Lab17_Fifth(){
    for(int i = 0; i < mass.size()-1; i++){
        for(int j = i+1; j < mass.size(); j++){
            if (mass[i] == mass[j]){
                cout << i+1 <<" ";
                return j+1;
            }
        }
    }
    return 0;
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
    cout << Lab18_Fifth();
    return 0;
}
