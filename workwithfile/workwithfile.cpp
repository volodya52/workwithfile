// workwithfile.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
#include <cmath>


struct Parallelogram {
    double a;
    double b;
    double alpha;
};

bool isSquare(const Parallelogram& p) {
    return p.a == p.b && p.alpha == 90;
}

int main() {
    std::ifstream inputFile("INPUT.txt");
    std::ofstream outputFile("Rezultat.txt");

    if (!inputFile) {
        std::cout << "Unable to open input file.";
        return 1;
    }

    Parallelogram parallelograms[50];
    int count = 0;

    while (count < 50 && inputFile >> parallelograms[count].a >> parallelograms[count].b >> parallelograms[count].alpha) {
        count++;
    }

    inputFile.close();

    for (int i = 0; i < count; i++) {
        if (isSquare(parallelograms[i])) {
            outputFile << "Result " << parallelograms[i].a << " " << parallelograms[i].alpha << " gradusov" << std::endl;
        }
    }

    outputFile.close();

    std::cout << "All good :))";
    return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
