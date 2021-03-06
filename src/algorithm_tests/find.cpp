//
// Created by user on 08.02.2021.
//

#include <iostream>
#include <iomanip>

#include "../DataTypes/Time/Time.h"
#include "../utils/string/string.h"

using namespace std;

const string str = "ZZZ Обратите внимание на разницу между функцией strlen() и оператором sizeof. strlen() выводит количество символов до нуль-т"
             "ерминатора, тогда как оператор sizeof возвращает размер целого массива, независимо от того, что в нем находится. "
             "ерминатора, тогда как оператор sizeof возвращает размер целого массива, независимо от того, что в нем находится. "
             "ерминаторZа, тогда каZк оператор sZizeof возвращает размер Zцелого массива, независимо от того, что в нем находится. "
             "ерминатора, тогда как оператор sizeof возвращает размер целого массива, независимо от того, что в нем находится. "
             "ерминатора, тогда кZZак оператор sizeof возвращает размер целого мZассива, независимо оZт того, что в нем находится. "
             "ерминатZора, тогда как оператор sizeof возвращает размер целого массива, независимо от того, что в нем находится. "
             "ерминатора, тогда как оператор ZZ sizeof возвращает размер целZого массива, независимо от того, что в нем находится. "
             "ерминатора, тогда как оператор sizeof возвращаеZт размер целого массива, независимоZ от того, что в нем находится. "
             "ерминаторZа, тогда как оператор sizeof возвращает размер целогоZZ массива, независимо от того, что в нем находится. "
             "ерминатора, тогда как Zоператор sizeof возвращает размер целого массива, независимо от того, что в нем находится. "
             "ерминаторZа, тогда как оператZор sizeof возвZращает размер целого массива, незаZZвисимо от того, что в нем находится. "
             "ерминатора, тогда как оператор sizeof возвращает размер целZZого массива, независимо от того, что в нем находится. "
             "ерминатора, тогда Zкак оператор sizeof возвращает размер целого массива, независимо от того, что в нем находится. "
             "ерминатора, тогда как оператор sizeof возвращает размер целого массива, независимо от того, что в нем находится. "
             "ерминатора, тогда Zкак оператор sizeof возвращает размер целого массива, независимо от того, что в нем находится. "
             "ерминатора, тогда как оператор sizeof возвращZает размер целого массива, независимо от ZZтого, что в нем находится. "
             "ермиZнатора, тогда как оператор sizeof возвращает размер целого массива, независимо от того, что в нем находится. "
             "ерминатора, тогда как оператор sizeof возвращаетZZ размер целого массива, независимо от того, что в нем находится. "
             "ерминатора, тогда как оператор sizeof возвращает размер целого массива, независимо от того, что в нем находится. "
             "ерминатора, тогдZZа как оператор sizeof возвращает размер целого маZссива, независимо от того, что в нем находится. "
             "ерминатора, тZогда как оператор sizeof возвращает размер целого массива, независимо от того, что в нем находится. ZZ2ZZ";

void show_diff(double v_1, double v_2) {
    double diff = v_2 - v_1;

    if(diff < 0) {
        cout << "Алгоритм #1 медленее #2 на "
             << std::fixed << std::setprecision(12)
             << std::abs(diff)
             << endl;
    } else {
        cout << "Алгоритм #1 быстрее #2 на "
             << std::fixed << std::setprecision(12)
             << diff
             << endl;
    }
}

void find_algorithm_test() {
    double t_v_1, t_v_2;

    char sub_str[] = "ZZ2ZZ";
    cout << "@Подстрока для поиска = " << sub_str << endl;

    data_types::Timer t1;

    int result_1 = utils::string::find(str.c_str(), sub_str);
    t_v_1 = t1.elapsed();

    t1.reset();

    int result_2 = str.find(sub_str);
    t_v_2 = t1.elapsed();

    std::cout << "#1: " << std::fixed << std::setprecision(12) << t_v_1 << " результат: " << result_1 << endl;
    std::cout << "#2: " << std::fixed << std::setprecision(12) << t_v_2 << " результат: " << result_2 << endl;

    show_diff(t_v_1, t_v_2);
}

void rfind_algorithm_test() {
    double t_v_1, t_v_2;

    char sub_str[] = "ZZZ";
    cout << "@Подстрока для поиска = " << sub_str << endl;

    data_types::Timer t1;

    int result_1 = utils::string::rfind(str.c_str(), sub_str);
    t_v_1 = t1.elapsed();

    t1.reset();

    int result_2 = str.rfind(sub_str);
    t_v_2 = t1.elapsed();

    std::cout << "#1: " << std::fixed << std::setprecision(12) << t_v_1 << " результат: " << result_1 << endl;
    std::cout << "#2: " << std::fixed << std::setprecision(12) << t_v_2 << " результат: " << result_2 << endl;

    show_diff(t_v_1, t_v_2);
}

int main() {
    cout << "Исходные данные: " << endl << str << "\n\n";

    cout << "1. Поиск с начала строки: " << endl;
    find_algorithm_test();
    cout << "\n";

    cout << "1. Поиск с конца строки: " << endl;
    rfind_algorithm_test();

    return EXIT_SUCCESS;
}