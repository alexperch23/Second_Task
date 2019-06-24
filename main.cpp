#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <windows.h>
using namespace std;

struct coord {
    float x;
    float y;
};

void coutFile(vector <coord> &data, fstream &file) {
    string path;
    cout << "Введите название файла (без расширения .txt): ";
    cin >> path;
    file.open(path + ".txt", ios::in);
    if (!file.is_open()) { // Проверка на наличие нужного файла
        cout << "Данного файла не существует.";
        system("pause");
        return;
    }
    else {
        coord ptr;
        while (!file.eof()) {
            file >> ptr.x;
            file >> ptr.y;
            data.push_back(ptr);
        }
    }
    cout << "Файл считан" << endl;
    file.close();
}

void analiz(vector <coord> data, coord my) {
    for (int i = 0; i < data.size(); i++) {
        if (my.x == data[i].x && my.y == data[i].y) {
            cout << "Точка вершина фигуры \n";
            return;
        }
    }
    float a = (data[0].x - my.x) * (data[1].y - data[0].y) - (data[1].x - data[0].x) * (data[0].y - my.y);
    float b = (data[1].x - my.x) * (data[2].y - data[1].y) - (data[2].x - data[1].x) * (data[1].y - my.y);
    float c = (data[2].x - my.x) * (data[3].y - data[2].y) - (data[3].x - data[2].x) * (data[2].y - my.y);
    float d = (data[3].x - my.x) * (data[0].y - data[3].y) - (data[0].x - data[3].x) * (data[3].y - my.y);
    if ((a > 0 && b > 0 && c > 0 && d > 0) || (a < 0 && b < 0 && c < 0 && d < 0)) {
        cout << "Принадлежит \n";
    }
    else if (a == 0 || b == 0 || c == 0 || d == 0) {
        cout << "Точка лежит на стороне фигуры \n";
    }
    else {
        cout << "Не принадлежит \n";
    }
}

int  main() {
    /*setlocale(LC_ALL, "Russian"); // Компилятор не хочет видеть кирилицу, добавил два варианта на всякий случай
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);*/
    fstream file;
    vector <coord> vect;
    coutFile(vect, file);
    coord my;
    cin >> my.x >> my.y;
    analiz(vect, my);
    system("pause");
    return 0;
}