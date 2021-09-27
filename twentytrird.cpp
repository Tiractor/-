#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <fstream>

using namespace std;
vector <int> mass;
vector <int> X {1, 5, 9, 11, -6, -3};
vector <int> Y {1, -12, 0, 5, -6, 2};
vector<vector <int>> matrix;

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

void MatrixCustomInit(){
    cout << "Input N lengh and M lengh" << endl;
    int N, M, x;
    vector <int> C;
    cin >> N >> M;
    for (int i = 0; i < M; ++i){
        for (int j = 0; j < N; ++j){
            cin >> x;
            matrix[i].push_back(x);
        }
        matrix.push_back(C);
    }
}

void MatrixBaseInit(){
    vector <int> C;
    C.push_back(13);
    C.push_back(14);
    C.push_back(15);
    C.push_back(16);
    matrix.push_back(C);
    C.clear();

    C.push_back(9);
    C.push_back(10);
    C.push_back(11);
    C.push_back(12);
    matrix.push_back(C);
    C.clear();


    C.push_back(5);
    C.push_back(6);
    C.push_back(7);
    C.push_back(8);
    matrix.push_back(C);
    C.clear();

    C.push_back(1);
    C.push_back(2);
    C.push_back(3);
    C.push_back(4);
    matrix.push_back(C);
}

void MatrixOutput(){
    for (int i = 0; i < matrix.size(); i++){
        for (int j = 0; j < matrix[i].size(); j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void MatrixRotate(){
    vector<vector <int>> temp_matrix;
    vector <int> line;
        for (int i = 0; i < matrix[0].size(); ++i){
            for( int j =0; j < matrix.size();++j){
                line.push_back(matrix[j][i]);
            }
            temp_matrix.push_back(line);
            line.clear();
        }
        matrix = temp_matrix;
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

// 23 Лаба

char Lab23_First()
{
    char x;
    cin >> x;
    cout << char(int(x)-1) << " " << char(int(x)+1);
    return ' ';
}

char Lab23_Second()
{
    string x;
    cin >> x;
    for(int i = 0; i < x.size(); ++i){
        x.insert(x.begin()+i+1,' ');
        ++i;
    }
    cout << x;
    return ' ';
}

int Lab23_Third()
{
    string x;
    int z = 0;
    cin >> x;
    for(int i = 0; i < x.size(); ++i){
        if ( x[i] <= 90 && x[i] >= 65) ++z;
    }
    return z;
}

char Lab23_Fourth()
{
    string x = "abbbctr";
    char z = 0;
    cin >> z;
    for(int i = 0; i < x.size(); ++i){
        if ( x[i] == z) {x.insert(x.begin()+i+1,z); i++;}
    }
    cout << x;
    return ' ';
}

char Lab23_Fifth()
{
    string x = "abbbctr";
    string z = "bb";
    int cou = 0;
    for(int i = 0; i < x.size(); ++i){
        bool flag = true;
        if(x[i] == z[0]){
            for(int j = 1; j < z.size(); j++){
                if(x[i+j] != z[j]) flag = false;
            }
            if (flag) cou++;
        }
    }
    cout << cou;
    return ' ';
}

int main()
{
    setlocale(LC_ALL, "Russian");
    MassBaseInit();
    MatrixBaseInit();
    cout << Lab25_First();
    return 0;
}
