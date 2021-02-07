//
// Created by user on 11.12.2020.
//

#ifndef STUD_GAME_EXCEPTION_H
#define STUD_GAME_EXCEPTION_H

#include "iostream"
#include <map>
#include <SFML/Graphics.hpp>

#include "../Game/Game.h"

using namespace std;

class Exception: public std::exception {
    public:
        enum Type {
            FileRead,
            FileNotExist
        };

        explicit Exception(Type type, string message = "");
        ~Exception() = default;

        const Type& get_error_type() const;
        const string& get_error_message() const;

        void draw_error() const;

        virtual const char* what() const noexcept override final;

    private:
        Type m_error_type;
        const string m_custom_error_message;
};

#endif //STUD_GAME_EXCEPTION_H
