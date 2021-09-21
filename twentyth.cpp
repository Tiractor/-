#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
vector <int> mass;
vector <int> X {1, 5, 9, 11, -6, -3};
vector <int> Y {1, -12, 0, 5, -6, 2};

// Доп. Функции

void MassBaseInit(){
    mass.push_back(2);
    mass.push_back(2);
    mass.push_back(1);
    mass.push_back(9);
    mass.push_back(9);
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

void PointCustomInit(){
    int N,x,y;
    cin >> N;
    for (int i = 0; i < N; i++){
        cin >> x >> y;
        X.push_back(x);
        Y.push_back(y);
    }
}



// 20 Лаба

char Lab20_First()
{
    vector <int> C,B;
    mass.push_back(mass[mass.size()-1]/2);
    int cou = 1;
    for(int i = 0; i < mass.size(); i++){
        if(mass[i] == mass[i+1]){
            cou++;
        }
        else{
            B.push_back(cou);
            cou=1;
            C.push_back(mass[i]);
        }
    }
    for (int i = 0; i < B.size(); i++){
        cout << B[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < C.size(); i++){
        cout << C[i] << " ";
    }
    cout << endl;
    return ' ';
}

char Lab20_Second()
{
    int L = 2;
    mass.push_back(mass[mass.size()-1]/2);
    int cou = 1;
    for(int i = 0; i < mass.size(); i++){
        if(mass[i] == mass[i+1]){
            cou++;
        }
        else{
            if(cou > L){

                int temp = mass[i-cou+2];
                cout << temp << endl;
                mass[i-cou+2] = 0;
                for(int j = i-cou+2; j < i; j++){
                    if (mass[j] == temp){
                    mass.erase(mass.begin()+j);
                    j--;
                    }
                }
                cou = 1;
            }
        }
    }
    mass.pop_back();
    MassOutput();
    return ' ';
}

char Lab20_Third()
{
    vector <int> C,B;
    int K = 3;
    mass.push_back(mass[mass.size()-1]/2);
    int cou = 1;
    for(int i = 0; i < mass.size(); i++){
        if(mass[i] == mass[i+1]){
            cou++;
        }
        else{
            B.push_back(cou);
            cou=1;
            C.push_back(mass[i]);
        }
    }
    vector <int> array;
    for(int i = 0; i < B.size()-1; i++){
        if(i != K-1){
            for(int j  = 0; j < B[i]; j++){
                array.push_back(C[i]);
            }
        }
        else{
            for(int j  = 0; j < B[B.size()-1]; j++){
                array.push_back(C[B.size()-1]);
            }
        }
    }
    for(int j  = 0; j < B[K-1]; j++){
        array.push_back(C[K-1]);
    }
    mass = array;
    MassOutput();
    return ' ';
}

char Lab20_Fourth()
{

    mass.clear();
    for(int i = 0; i < X.size(); ++i){
    mass.push_back(sqrt(X[i]*X[i]+Y[i]*Y[i]));
    }
    int f = distance(mass.begin(),max_element(mass.begin(),mass.end()));
    cout << X[f] << " " << Y[f];
    return ' ';
}

char Lab20_Fifth()
{
    vector<vector <int>> Perim;
    for(int i = 0; i < X.size(); ++i){
        for(int j = i+1; j < X.size(); ++j){
            for(int g = j+1; g < X.size(); ++g){
                int a =(sqrt(pow(X[i]-X[j],2)+pow(Y[i]-Y[j],2))); // Расстояние между 1 и 2
                int b =(sqrt(pow(X[g]-X[j],2)+pow(Y[g]-Y[j],2))); // Расстояние между 3 и 2
                int с =(sqrt(pow(X[i]-X[g],2)+pow(Y[i]-Y[g],2))); // Расстояние между 3 и 1
                Perim[0].push_back(a+b+с); // Периметр
                Perim[1].push_back(i); // Индекс точки 1
                Perim[2].push_back(j); // Индекс точки 2
                Perim[3].push_back(j); // Индекс точки 3
            }
        }
    }
    int f = distance(mass.begin(),max_element(Perim[0].begin(),Perim[0].end())); // Нужный столбец
    int q = Perim[1][f]; // Индекс нужной точки 1
    int w = Perim[2][f]; // Индекс нужной точки 2
    int e = Perim[3][f]; // Индекс нужной точки 3
    cout << X[q] << " " << Y[q] << endl;
    cout << X[w] << " " << Y[w] << endl;
    cout << X[e] << " " << Y[e] << endl;
    return ' ';
}

int main()
{
    MassBaseInit();
    cout << Lab20_Fifth();
    return 0;
}
