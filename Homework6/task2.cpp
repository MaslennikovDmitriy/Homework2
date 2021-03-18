#include <iostream>
#include <fstream>
#include <cstdlib>
#include <conio.h>

const int str_size = 10;

int main()
{
    setlocale(LC_ALL, "Russian");
    std::ofstream F1("task2.txt", std::ios_base::trunc);
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < str_size; j++) {
            F1 << rand() % 10;
        }
        F1 << "\n";
    }
    F1.close();

    std::cout << "Введите номер строки, которую нужно вывести (до 20): ";
    int n = 0;
    std::cin >> n;
    std::ifstream file("task2.txt");

    if (n > 1)
    {
        file.seekg((n - 1) * (str_size + 2));
    }
    else
    {
        file.seekg(0);
    }
    char str[11];
    file.getline(str, str_size + 1);
    std::cout << "Строка №" << n << ": " << str << std::endl;
    file.close();
    return EXIT_SUCCESS;
}