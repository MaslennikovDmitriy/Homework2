#include <iostream>
#include <fstream>
#include <cstdlib>
#include <random>

const int str_size = 8;

int main()
{
    setlocale(LC_ALL, "Russian");
    std::random_device rd;
    std::mt19937 mersenne(rd());
    std::ofstream F1("task2.txt", std::ios_base::trunc);
    for (int i = 0; i < 20; i++)
    {
        std::uniform_int_distribution<> un_distrib(10000000, 99999999);
        F1 << un_distrib(mersenne) << std::endl;
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