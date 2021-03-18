#include <chrono>
#include <iostream>
#include <vector>
#include <algorithm>
#include <clocale>
#include <queue>
#include <list>
#include <string>

void sort(std::vector <int>& v1, std::vector <std::string>& v2)
{
	for (std::size_t i = 0; i < v1.size() - 1; ++i)
	{
		for (std::size_t j = i + 1; j < v1.size(); ++j)
		{
			if (v1[i] > v1[j])
			{
				std::swap(v1[i], v1[j]);
				std::swap(v2[i], v2[j]);
			}
		}
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	const auto size = 10000U;
	std::vector<int> v(size, 0);
	for (std::size_t i = 0; i < v.size(); ++i)
	{
		v[i] = v.size() - i;
	}
	auto now1 = std::chrono::system_clock::now();
	std::sort(v.begin(), v.end());
	auto end1 = std::chrono::system_clock::now();
	auto elapsed1 = std::chrono::duration_cast<std::chrono::milliseconds>(end1 - now1);
	//std::cout << "Время работы сортировки вектора(std::vector) (в миллисекундах): " << elapsed1.count() << std::endl;

	int a[10000U];
	for (std::size_t i = 0; i < 10000U; ++i)
	{
		a[i] = 10000U - i;
	}
	auto now2 = std::chrono::system_clock::now();
	std::sort(std::begin(a), std::end(a));
	auto end2 = std::chrono::system_clock::now();
	auto elapsed2 = std::chrono::duration_cast<std::chrono::milliseconds>(end2 - now2);
	//std::cout << "Время работы сортировки статического массива(std::array) (в миллисекундах): " << elapsed2.count() << std::endl;

	std::priority_queue<int> pq;
	auto now3 = std::chrono::system_clock::now();
	for (std::size_t i = 0; i < 10000U; ++i)
	{
		pq.push(i);
	}
	auto end3 = std::chrono::system_clock::now();
	auto elapsed3 = std::chrono::duration_cast<std::chrono::milliseconds>(end3 - now3);
	//std::cout << "Время работы сортировки приоритетной очереди(std::priority_queue) (в миллисекундах): " << elapsed3.count() << std::endl;

	std::deque<int> d(size, 0);
	for (std::size_t i = 0; i < d.size(); ++i)
	{
		d[i] = d.size() - i;
	}
	auto now4 = std::chrono::system_clock::now();
	std::sort(d.begin(), d.end());
	auto end4 = std::chrono::system_clock::now();
	auto elapsed4 = std::chrono::duration_cast<std::chrono::milliseconds>(end4 - now4);
	//std::cout << "Время работы сортировки двусторонней очереди(std::deque) (в миллисекундах): " << elapsed4.count() << std::endl;

	std::list<int> l;
	for (std::size_t i = 0; i < 10000U; ++i)
	{
		l.push_back(10000U - i);
	}
	auto now5 = std::chrono::system_clock::now();
	l.sort();
	auto end5 = std::chrono::system_clock::now();
	auto elapsed5 = std::chrono::duration_cast<std::chrono::milliseconds>(end5 - now5);
	//std::cout << "Время работы сортировки двусвязного списка (std::list) (в миллисекундах): " << elapsed5.count() << std::endl;

	std::vector<int> v1(5);
	std::vector<std::string> v2(5);
	v1[0] = elapsed1.count();
	v2[0] = "std::vector";

	v1[1] = elapsed2.count();
	v2[1] = "std::array";

	v1[2] = elapsed3.count();
	v2[2] = "std::priority_queue";

	v1[3] = elapsed4.count();
	v2[3] = "std::deque";

	v1[4] = elapsed5.count();
	v2[4] = "std::list";
	sort(v1, v2);

	for (std::size_t i = 0; i < v1.size(); ++i)
	{
		std::cout << i + 1 << "-ое место: " << v2[i] << "; время работы: " << v1[i] << " миллисекунд" << std::endl;
	}
	system("pause");
	return EXIT_SUCCESS;
}