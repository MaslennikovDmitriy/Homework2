//#include <boost/filesystem.hpp>
//#include <filesystem>
#include <fstream>
#include <locale>
#include <iostream>
#include <string>
#include <vector>
#include "json.hpp"

using nlohmann::json;


// Текстовые файлы с данными о каждом человеке создаю в папке с проектом, т.к. не получилось создать директорию ни с помощью filesystem, ни с помощью boost::filesystem
// Ошибка undefined reference to `boost::filesystem::path::codecvt()'

struct Human
{
    std::string name;
    int age;
    double weight;

    friend std::istream& operator>> (std::istream& in, Human& human);
};

std::istream& operator>> (std::istream& in, Human& human)
{
    std::cout << "Введите имя: ";
    in >> human.name;
    std::cout << "Введите возраст: ";
    in >> human.age;
    std::cout << "Введите вес: ";
    in >> human.weight;
    return in;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    std::vector<Human> h_vec(5);

    for (size_t i = 0; i < h_vec.size(); i++) {
        std::cout << "Введите данные о " << i + 1 << " человеке: " << std::endl;
        std::cin >> h_vec[i];
        std::cout << std::endl;
    }

    json js;

    //    boost::filesystem::path p = boost::filesystem::current_path();
    //    boost::filesystem::create_directory(p / "task4");

    std::string outFile;
    for (size_t i = 0; i < h_vec.size(); i++) {
        outFile = "task4_" + std::to_string(i + 1) + ".txt";
        std::ofstream out_1(outFile);
        if (!out_1.is_open()) {
            std::cerr << "Can not open: " << outFile << std::endl;
            return EXIT_FAILURE;
        }
        js["name"] = h_vec[i].name;
        js["age"] = h_vec[i].age;
        js["weight"] = h_vec[i].weight;
        for (auto iterator = js.begin(); iterator != js.end(); ++iterator) {
            out_1 << iterator.key() << ": " << iterator.value() << "\n";
        }
        out_1.close();
    }
    system("pause");
    return EXIT_SUCCESS;
}