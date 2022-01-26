#include "level.hpp"

#include "simple_functions.hpp"

level::level(sf::RenderWindow& window,
            game_settings& game_setting,
            state& state_t):
        window(window),
        game_setting(game_setting),
        state_t(state_t)
    {
        players.emplace_back(std::make_shared<player>(window , sf::Vector2f( 960.0, 960.0 ), sf::Vector2f{ 59.0, 59.0 }, game_setting, state_t));

        for(int i = 0; i <= int(window.getSize().y / 60); i++){
            build_line(window.getSize().y - (60 * i), i < 5);
        }
    }

void level::update(){
    for(auto& line : lines){
        line->lower();
        line->update();
    }
    for(auto& player : players){
        player->lower();
        player->update();
    }

    if(ticks % 60 == 0) {
        build_line();
    }
    ticks +=1;
}

void level::draw(){
    for(auto& line : lines){
        line->draw();
    }
    for(auto& player : players){
        player->draw();
    }
}

void level::build_line(float height, bool force_grass_line) {
    unsigned int line_type = random_int_between_range(0,4);
    // Rails
    if(line_type == 0 && force_grass_line == false) {
        lines.push_back(std::make_shared<line>(window, sf::Vector2f{window.getSize().x/4.f, height},  sf::Vector2f{window.getSize().x/2.f, 59.0}, RAILS, NON_OBSTACLE, "rails_sprite"));
    }
    // Roads
    else if(line_type == 2 && force_grass_line == false) {  //todo WATER MUST BE CHANGED TO DEADLY
        lines.push_back(std::make_shared<line>(window, sf::Vector2f{window.getSize().x/4.f, height},  sf::Vector2f{window.getSize().x/2.f, 59.0}, ROAD, NON_OBSTACLE, "roads_sprite"));
    }
    // Water
    else if(line_type == 3 && force_grass_line == false) {
        lines.push_back(std::make_shared<line>(window, sf::Vector2f{window.getSize().x/4.f, height},  sf::Vector2f{window.getSize().x/2.f, 59.0}, WATER, NON_OBSTACLE, "water_sprite"));
    }
    // Grass
    else if((line_type == 1 || 4) || force_grass_line == true) {
        // TODO No coins first 5
        lines.push_back(std::make_shared<line>(window, sf::Vector2f{window.getSize().x/4.f, height},  sf::Vector2f{window.getSize().x/2.f, 59.0}, GRASS, NON_OBSTACLE, "grass_sprite"));
    }
}