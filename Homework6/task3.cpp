#include <experimental/filesystem>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <iostream>
#include <chrono>
#include <clocale>

void Directory_Check(const std::experimental::filesystem::path& _path)
{
	if (std::experimental::filesystem::exists(_path) && std::experimental::filesystem::is_directory(_path))
	{
		for (const auto& entry : std::experimental::filesystem::directory_iterator(_path))
		{
			auto filename = entry.path().filename().string();
			auto time = std::experimental::filesystem::last_write_time(_path);
			std::time_t cftime = decltype(time)::clock::to_time_t(time);
			std::cout << "��� �����: " << filename << std::endl;
			std::cout << "����������: " << _path.extension().string() << std::endl;
			std::cout << "��������� ����� ��������� �����: " << std::asctime(std::localtime(&cftime)) << std::endl;
		}
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	std::string path_str;
	std::cout << "������� ���� �����: ";
	std::cin >> path_str;
	std::experimental::filesystem::path File = path_str;
	if (!std::experimental::filesystem::exists(File))
	{
		std::cerr << "���� " << path_str << " �� ����������" << std::endl;
		return EXIT_FAILURE;
	}
	Directory_Check(File);
	system("pause");
	return EXIT_SUCCESS;
}