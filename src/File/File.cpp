//
// Created by user on 11.12.2020.
//

#include "File.h"

File::File(string file_path) {
    m_file_path = File::resolve_path(Constants::directory_path, std::move(file_path));
}

bool File::check_file_exists() const {
    if(m_file_path.length() == 0) {
        return false;
    }

    std::ifstream file;
    file.open(m_file_path);

    bool is_open = file.is_open();

    file.close();

    return is_open;
}

const string& File::get_file_path() const {
    return m_file_path;
}

string File::resolve_path(string left, string right) {
    if(right.at(0) == '/') {
        return right;
    }

    int pos = 0;
    while (pos != -1) {
        pos = right.find("../");
        if(pos != -1) {
            int remove_to = left.rfind('/');
            if(remove_to != 0) {
                left = left.substr(0, remove_to);
            }

            right = right.substr(pos + 3);

            continue;
        }

        pos = right.find("./");
        if(pos != -1) {
            right = right.substr(pos + 2);

            continue;
        }
    }

    return (left + "/" + right);
}

json File::to_json() const {
    return json();
}

xml File::to_xml() const {
    return xml();
}
