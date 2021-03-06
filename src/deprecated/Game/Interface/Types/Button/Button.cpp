//
// Created by user on 09.02.2021.
//

#include "Button.h"
#include "../../../../../Game/Interface/Types/Button/Button.h"


Button::Button(const sf::Vector2f& size, const string& str): Element(size), m_str(str) {
    m_border_color = sf::Color::Black;
}

Button::~Button() {
    delete m_button;
    delete m_text;
}

// PUBLIC VOID
void Button::draw(sf::RenderWindow& window) {
    if(!m_builded) throw Exception(Exception::ElementNotBuild);

    window.draw(*m_button);
    window.draw(*m_text);
}

// PUBLIC GET
sf::FloatRect Button::get_bounds() const {
    if(m_button != nullptr) {
        return m_button->getGlobalBounds();
    }

    throw Exception(Exception::ElementNotBuild);
}

// PUBLIC SET
Button& Button::build() {
    if(m_builded) return (*this);

//    if(m_position.x != 0 && !m_actual_x_bounds) {
//        calculate_bounds_x();
//        origin_x_to_center(get_bounds());
//
//        turn_on_boundary(1);
//    }
//    if(m_position.y != 0 && !m_actual_y_bounds) {
//        calculate_bounds_y();
//        origin_y_to_center(get_bounds());
//
//        turn_on_boundary(0);
//    }

    /// RECTANGLE SHAPE
    m_button = m_button == nullptr
      ? new sf::RectangleShape()
      : m_button;

//    calculate_bounds();
//    auto size = sf::Vector2f(m_bounds.width + 20, m_bounds.height + 20);
//
//    cout << "-------------" << endl;
//    cout << "size.x = " << size.x << endl;
//    cout << "size.y = " << size.y << endl;
//    cout << "-------------" << endl;
//    cout << "m_size.x = " << m_size.x << endl;
//    cout << "m_size.y = " << m_size.y << endl;

    m_button->setSize(m_size);
    m_button->setFillColor(m_bg_color);

    m_button->setOutlineThickness(m_border_width);
    m_button->setOutlineColor(m_border_color);

//    cout << "m_button BUILD " << endl;
//    cout << "m_position.x = " << m_position.x << endl;
//    cout << "m_position.y = " << m_position.y << endl;

    m_button->setPosition(m_position);
    m_button->setOrigin(m_origin);

    /// TEXT
    m_text = m_text == nullptr
      ? new sf::Text
      : m_text;

    m_text->setFont(Game::get_game_font());
    m_text->setString(sf::String::fromUtf8(m_str.begin(), m_str.end()));

    m_text->setCharacterSize(m_text_size);
    m_text->setFillColor(m_text_color);

    button_text_to_center();

    turn_on_building();
    return (*this);
}

Button& Button::set_text(const string& text) {
    m_str = text;

    turn_off_building();
    return (*this);
}

Button& Button::set_text_size(int size) {
    m_text_size = size;

    turn_off_building();
    return (*this);
}

Button& Button::set_text_color(const sf::Color& color) {
    m_text_color = color;

    turn_off_building();
    return (*this);
}

Button& Button::to_center(const sf::Vector2u& window_size) {
    if(!m_builded) throw Exception(Exception::ElementNotBuild);

    Element::to_center(window_size);
    return (*this);
}

int Button::on_click(const Button::t_callback& cb, const Button::t_callback& after_cb) {
    m_on_click_callbacks.push_back(cb);
    int pos = static_cast<int>(m_on_click_callbacks.size()) - 1;

    m_on_click_callbacks.push_back(after_cb);

    return pos;
}

int Button::on_hover(const Button::t_callback& cb, const Button::t_callback& after_cb) {
    m_on_hover_callbacks.push_back(cb);
    int pos = static_cast<int>(m_on_hover_callbacks.size()) - 1;

    m_on_hover_callbacks.push_back(after_cb);

    return pos;
}

Button& Button::click() {
    call_callbacks(Action::Click);
    return (*this);
}

Button& Button::after_click() {
    call_after_callbacks(Action::Click);
    return (*this);
}

Button& Button::hover() {
    call_callbacks(Action::Hover);
    return (*this);
}

Button& Button::after_hover() {
    call_after_callbacks(Action::Hover);
    return (*this);
}

Button& Button::remove_click(int pos) {
    remove_callback(Action::Click, pos * 2);
    return (*this);
}

Button& Button::remove_hover(int pos) {
    remove_callback(Action::Hover, pos * 2);
    return (*this);
}

// PROTECTED GET
Button::t_callbacks& Button::get_callbacks_by_action(const Action& action) {
    if(action == Click) {
        return m_on_click_callbacks;
    } else if(action == Hover) {
        return m_on_hover_callbacks;
    } else {
        throw std::runtime_error("Invalid argument");
    }
}

// PROTECTED SET
void Button::call_callbacks(const Action& action) {
    t_callbacks& callbacks(get_callbacks_by_action(action));

    if(callbacks.empty()) return;

    const int size = callbacks.size();
    for(int i = 0; i < size; i += 2) {
        auto callback = callbacks.at(i);
        callback(*this);
    }
}

void Button::call_after_callbacks(const Button::Action& action) {
    t_callbacks& callbacks(get_callbacks_by_action(action));

    if(callbacks.empty()) return;

    const int size = callbacks.size();
    for(int i = 1; i < size; i += 2) {
        auto callback = callbacks.at(i);
        callback(*this);
    }
}

void Button::remove_callback(const Action& action, int pos) {
    if(pos % 2 != 0) throw std::runtime_error("Invalid argument");

    t_callbacks& callbacks(get_callbacks_by_action(action));

    if(pos > (callbacks.size() - 2)) {
        throw Exception(Exception::NonExistentPosition);
    }

    callbacks.erase(callbacks.begin() + pos);               /// on callback
    callbacks.erase(callbacks.begin() + pos + 1);   /// after callback
}

void Button::button_text_to_center() {
    if(m_button == nullptr || m_text == nullptr) {
        throw std::runtime_error("Required vars no inited");
    }

    auto text_locals = m_text->getLocalBounds();
    m_text->setOrigin({
        (text_locals.left + text_locals.width / 2.f),
        (text_locals.top + text_locals.height / 2.f)
    });

    auto locals = m_button->getGlobalBounds();
    m_text->setPosition({
        (locals.width / 2.f) + locals.left,
        (locals.height / 2.f) + locals.top
    });
}

void Button::perform_button_actions(const sf::RenderWindow& window, const sf::Event& event, const sf::Vector2i& prev_pos) {
    Button::perform_button_actions(*this, event, window, prev_pos);
}

void Button::perform_button_actions(Button& button, const sf::Event& event, const sf::RenderWindow& window, const sf::Vector2i& prev_pos) {
    if(event.type == sf::Event::MouseButtonPressed) {
        bool on_button = FormInterface::mouse_in(button, window);

        if(on_button) {
            button.click();
        }
    }

    if(event.type == sf::Event::MouseButtonReleased) {
        bool on_button = FormInterface::mouse_in(button, window);

        if(on_button) {
            button.after_click();
        }
    }

    if(event.type == sf::Event::MouseMoved) {
        bool prev_pos_on_button = FormInterface::mouse_in(button, prev_pos);
        bool curr_pos_on_button = FormInterface::mouse_in(button, window);

        if(curr_pos_on_button && !prev_pos_on_button) {
            button.hover();
        }

        if(prev_pos_on_button && !curr_pos_on_button) {
            button.after_hover();
        }
    }
}

Button::Button(const sf::Vector2f &size, const sf::Vector2f &size, const string &str) {

}
