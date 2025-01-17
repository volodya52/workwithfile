#include <iostream>
#include <fstream>
#include <cmath>

struct Parallelogram {
    double a;
    double b;
    double alpha;
};

bool isSquare(const Parallelogram& p) {
    return p.a == p.b && std::fabs(p.alpha - 90.0) < 1e-6;
}

int main() {
    std::ifstream inputFile("input.txt");
    std::ofstream outputFile("Rezultat.txt");

    if (!inputFile) {
        std::cerr << "Unable to open input file." << std::endl;
        return 1;
    }

    Parallelogram parallelograms[50];
    int count = 0;

    while (count < 50 && inputFile >> parallelograms[count].a >> parallelograms[count].b >> parallelograms[count].alpha) {
        count++;
    }

    inputFile.close();

    if (count == 0) {
        std::cerr << "No data read from input file." << std::endl;
        return 1;
    }

    bool foundSquare = false;
    for (int i = 0; i < count; i++) {
        if (isSquare(parallelograms[i])) {
            outputFile << "Rezultat " << parallelograms[i].a << " " << parallelograms[i].alpha << " gradusov" << std::endl;
            foundSquare = true;
        }
    }

    outputFile.close();

    if (!foundSquare) {
        std::cerr << "No squares found in the input data." << std::endl;
    }
    else {
        std::cout << "All good :))" << std::endl;
    }

    return 0;
}
