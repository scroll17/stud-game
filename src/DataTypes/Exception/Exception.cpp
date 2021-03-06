//
// Created by user on 11.12.2020.
//

#include "Exception.h"
#include "../../Engine/Form/index.h"

using namespace data_types;

static map<Exception::Type, string> EXCEPTION_DETAILS {
  { Exception::Type::FileRead, "Error with read file." },
  { Exception::Type::FileOpen, "Cannot open file." },
  { Exception::Type::FileNotExist, "File not found." },
  { Exception::Type::FileNotOpen, "File not open." },
  { Exception::Type::ElementNotBuild, "Element not built yet." },
  { Exception::Type::NonExistentPosition, "Position in the array does not exist." },
  { Exception::Type::RequiredVariableMissing, "Required variable missing." },
  { Exception::Type::ActionBeforeRequired, "Action before required." },
  { Exception::Type::InvalidArgument, "Invalid argument." },
  { Exception::Type::UnknownArgument, "Unknown argument." },
  { Exception::Type::CannotRender, "Cannot render." },
};

Exception::Exception(Exception::Type type, string message): m_error_type(type), m_custom_error_message(std::move(message)) {}

const Exception::Type& Exception::get_error_type() const {
    return m_error_type;
}

const string& Exception::get_error_message() const {
    if(m_custom_error_message.length() > 0) {
        return m_custom_error_message;
    } else {
        return EXCEPTION_DETAILS[m_error_type];
    }
}

void Exception::draw_error() const {
    auto form = new form::templates::ErrorForm { this->get_error_message() };

    form->render(120, form::templates::ErrorForm::empty_frame_cb);

    delete form;
}

const char* Exception::what() const noexcept {
    return this->get_error_message().c_str();
}
