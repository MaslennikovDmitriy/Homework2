#include <iostream>
#include <clocale>
#include <vector>

using namespace std;

void print_size_and_capacity(const std::vector<int>& v)
{
    std::cout << "size = " << v.size() << "; capacity = " << v.capacity() << std::endl;
}
int main()
{
    setlocale(LC_ALL, "Russian");
    vector<int> v1(100);
    vector<int> v2(128);
    vector<int> v3(200);
    v1.resize(101);
    v2.resize(129);
    v3.resize(100000000);
    print_size_and_capacity(v1);
    print_size_and_capacity(v2);
    print_size_and_capacity(v3); //при нехватке памяти для размещения новых элементов значение capacity увеличивается на величину, равную половине первоначальной ёмкости. Если после увеличения ёмкости всё ещё не хватает, то она увеличивается до нужного размера

    vector<int> v4;
    v4.reserve(150);
    v4.resize(227);
    print_size_and_capacity(v4); // аналогично предыдущей ситуации, значение емкости увеличивается на величину, равную половине зарезервированной ёмкости. Если после увеличения ёмкости всё ещё не хватает, то она увеличивается до нужного размера

    vector<char> v5;
    cout << "Максимальный размер вектора v5: " << v5.max_size() << endl;
    v5.resize(214748364);
    cout << "Ёмкость вектора v5: " << v5.capacity() << endl;
    /*
    max_size возвращает теоретическое максимальное число элементов, но не говорит о количестве необходимой памяти.
    При превышении некоторого количества элементов получаем исключение bad_alloc, потому что вектор не может выделить достаточно памяти для хранения всех элементов.
    */
    return EXIT_SUCCESS;
}