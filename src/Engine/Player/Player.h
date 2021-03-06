//
// Created by user on 08.02.2021.
//

#ifndef STUD_GAME_PLAYER_H
#define STUD_GAME_PLAYER_H

#include "SFML/Graphics.hpp"

#include <functional>
#include "../GameMap/GameMap.h"

namespace engine {

    class Player {
        public:
            using t_around_block_cb = function<void(const pair<size_t, size_t>& block)>;
            using Direction = engine::GameMap::Direction;

            enum Axis: int8_t {
                Zero,
                X,
                Y
            };

        protected:
            float m_speed;
            float m_boost;

            float m_animation_boost;
            float m_animation_change_rate;

            float m_dx;
            float m_dy;

            float m_max_animation_frames;
            float m_dx_current_frame;
            float m_dy_current_frame;

            float m_steps_count = 0;

            bool m_run;

            Axis m_prev_axis = Axis::Zero;

            sf::IntRect m_rect_x;
            sf::IntRect m_rect_y;

            sf::Texture m_texture;
            sf::Sprite m_sprite;

            sf::Vector2f m_position;

            const engine::GameMap& m_game_map;

            void calculate_boost(Axis axis, float elapsed_time);
            void calculate_animation(Axis axis, float elapsed_time);
            void calculate_steps_count(float prev_pos_x, float prev_pos_y);

        public:
            explicit Player(const engine::GameMap& game_map);
            virtual ~Player() = default;

            virtual void init() = 0;

            void set_position(float x, float y);

            void collision(Axis axis, float prev_pos);
            void hitting_in_texture();
            void around_blocks(char cell, const t_around_block_cb& cb);

            void update(float elapsed_time);

            void run(bool condition);
            void move(Direction dir);
            void stop(Direction dir);
            void stop_all();

            bool is_run() const;

            float get_steps_count() const;
            sf::FloatRect get_bounds() const;
            const sf::Vector2f& get_position() const;
            const sf::Sprite& get_sprite() const;

            static void move_input(Player& player);
    };

}


#endif //STUD_GAME_PLAYER_H
