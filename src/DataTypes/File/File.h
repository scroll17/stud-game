//
// Created by user on 11.12.2020.
//

#ifndef STUD_GAME_FILE_H
#define STUD_GAME_FILE_H

#include <fstream> // ifstream
#include <utility>

#include "../../Constants/Constants.h"
#include "../Exception/Exception.h"
#include "../../utils/index.h"

using namespace std;

namespace data_types {

    class File {
        protected:
            string m_file_path;

        public:
            explicit File(const string& file_path);
            virtual ~File() = default;

            bool check_file_exists() const;
            const string& get_file_path() const;

            static string resolve_path(string left, string right);
    };

}

#endif //STUD_GAME_FILE_H
