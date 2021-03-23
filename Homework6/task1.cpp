#include <iostream>
#include <fstream>
#include <cstdio>
#include <string>
#include <clocale>

bool check(char c, char d)
{
    static int i = 0;

    if ((d == '"') && (c != '/'))
    {
        i ? --i : ++i;
    }
    else
    {
        if ((d == '/') && (c == '/') && (!i))
        {
            return true;
        }
        else
        {
            if ((d == '*') && (c == '/') && (!i))
            {
                return true;
            }
            else
            {
                if ((d == '/') && (c == '*') && (!i))
                {
                    return true;
                }
                else return false;
            }
        }
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");
    std::fstream File("test.txt", std::ios::in | std::ios::out);
    if (!File)
    {
        std::cerr << "Невозможно открыть файл!" << std::endl;
        return EXIT_FAILURE;
    }
    char c = ' ';
    char d;
    while (File)
    {
        File.get(d);
        if (check(c, d))
        {
            File.seekg(-2, std::ios::cur);
            File.put(' ');
            File.put(' ');
        }
        c = d;
    }
    std::cout << "Успех, файл очищен от комментариев!" << std::endl;
    system("pause");
    return EXIT_SUCCESS;
}