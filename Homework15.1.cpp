// Homework15.1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <list>
#include <future>
#include <vector>

void smallell(std::list<int>::iterator end, std::list<int>::iterator begin, std::promise<std::list<int>::iterator> prom) {
    std::list<int>::iterator smallest = begin;

    for (auto it = begin; it != end; it++) {
        if (*smallest > *it) {
            smallest = it;
        }
    }
    prom.set_value(smallest);
}


int main()
{
    std::list<int> listforsort{ 10, 5, 45, 1, 49, 92, 32, 6, 2, 6, 31, 70 };
    int sizel = listforsort.size();
    int templ;
    for (auto it : listforsort) {
        std::cout << it << "\t";
    }
    std::cout << std::endl;


    for (auto itl = listforsort.begin(); itl != listforsort.end(); itl++) {
        std::promise<std::list<int>::iterator> proms;
        std::future<std::list<int>::iterator> futres = proms.get_future();
        auto f = std::async(smallell, listforsort.end(), itl, std::move(proms));
        std::list<int>::iterator ittemp = futres.get();
        templ = *itl;
        *itl = *ittemp;
        *ittemp = templ;
    }
    for (auto it : listforsort) {
        std::cout << it << "\t";
    }
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
