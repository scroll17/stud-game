//
// Created by user on 11.01.2021.
//

#ifndef STUD_GAME_STRING_H
#define STUD_GAME_STRING_H

#include "nlohmann/json.hpp"

#include <cstring>  // strlen

#include <locale>   // wstring_convert
#include <codecvt>  // codecvt_utf8_utf16
#include <string>   // wstring

namespace utils {
    namespace string {
        // 1.5 times slower
        int find(const char *str, const char *sub_str);

        // 400 times faster
        int rfind(const char *str, const char *sub_str);

        std::wstring convert_to_ws(const std::string& str);

        std::string *json_arr_to_string(const nlohmann::basic_json<>& json_arr, int rows);
    }
}

#endif //STUD_GAME_STRING_H
