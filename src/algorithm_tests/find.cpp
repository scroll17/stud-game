//
// Created by user on 08.02.2021.
//

#include "iostream"
#include <iomanip>

#include "../DataTypes/Time/Time.h"
#include "../utils/string/string.h"

char str[] = "ZZZ Обратите внимание на разницу между функцией strlen() и оператором sizeof. strlen() выводит количество символов до нуль-т"
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

string str_2 = str;

void find_algorithm_test() {
    double t_v_1, t_v_2;

    char sub_str[] = "ZZ2ZZ";

    Timer t1;

    int result_1 = find(str, sub_str);
    t_v_1 = t1.elapsed();

    t1.reset();

    int result_2 = str_2.find(sub_str);
    t_v_2 = t1.elapsed();

    std::cout << "#1: " << std::fixed << std::setprecision(12) << t_v_1 << "  result: " << result_1 << endl;
    std::cout << "#2: " << std::fixed << std::setprecision(12) << t_v_2 << "  result: " << result_2 << endl;
}

void rfind_algorithm_test() {
    double t_v_1, t_v_2;

    char sub_str[] = "ZZZ";

    Timer t1;

    int result_1 = rfind(str, sub_str);
    t_v_1 = t1.elapsed();

    t1.reset();

    int result_2 = str_2.rfind(sub_str);
    t_v_2 = t1.elapsed();

    std::cout << "#1: " << std::fixed << std::setprecision(12) << t_v_1 << "  result: " << result_1 << endl;
    std::cout << "#2: " << std::fixed << std::setprecision(12) << t_v_2 << "  result: " << result_2 << endl;

}