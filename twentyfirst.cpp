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


// 21 Лаба

char Lab21_First()
{
    int co = 0; // Счетчик выведенных значений
    int z = 0; // Сдвиг вывода
    int x = 0;// Индекс сдвига столб
    int y = 0;// Индекс сдвига строк
    int Boy = matrix.size()*matrix[0].size(); // Количество элементов в прямоугольной матрице
    while(co < Boy){
        for(; x < matrix.size(); ++x){
            cout << matrix[x][y] << " ";
            co++;
            if(co >= Boy) break;
        }
        if(co >= Boy) break;
        x--;
        y++;
        for(; y < matrix[x].size(); ++y){
            cout << matrix[x][y] << " ";
            co++;
            if(co >= Boy) break;
        }
        if(co >= Boy) break;
        y--;
        x--;
        for(; x > z; --x){
            cout << matrix[x][y] << " ";
            co++;
            if(co >= Boy) break;
        }
        if(co >= Boy) break;
        z++;
        for(; y > z; --y){
            cout << matrix[x][y] << " ";
            co++;
            if(co >= Boy) break;
        }

    }

    return ' ';
}

char Lab21_Second()
{
    int k = 0;
    int sum = 0;
    int pro = 1;
    for (int i = 0; i < matrix[k].size();i++){
        sum += matrix[k][i];
        pro *= matrix[k][i];
    }
    cout << sum << endl << pro;
    return ' ';
}

char Lab21_Third()
{
    int k = 0;
    vector <int> prom;
    int pro = 1;
    for (int j =0; j < matrix.size();++j){
        for (int i = 0; i < matrix[k].size();i++){
            pro *= matrix[j][i];
        }
        prom.push_back(pro);
        pro = 1;
    }
    int f = distance(prom.begin(),max_element(prom.begin(),prom.end()));
    cout << f+1 << endl << prom[f];
    return ' ';
}

char Lab21_Fourth()
{
    double arif = 0;
    for (int i =0; i < matrix[0].size();++i){
        for(int j = 0; j < matrix.size(); ++j){
            arif += matrix[j][i];
        }
        arif /= matrix.size();
        int count = 0;
        for(int j = 0; j < matrix.size(); ++j){
            if(matrix[j][i] > arif){
                count++;
            }
        }
        cout << count << " ";
        arif = 0;
    }
    return ' ';
}

char Lab21_Fifth()
{
    int g = 0;
    bool flag;
    for (int i =0; i < matrix[0].size();++i){
        flag = true;
        for(int j = 0; j < matrix.size(); ++j){
            if (matrix[j][i]%2 == 0) {
                flag = false;
                break;
            }
        }
        if (flag){
            g = i+1;
            break;
        }
    }
    cout << g;
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
