#include "level.hpp"

#include "simple_functions.hpp"
#include <iostream>

level::level(sf::RenderWindow& window,
            game_settings& game_setting,
            state& state_t):
        window(window),
        game_setting(game_setting),
        state_t(state_t)
    {
        players.emplace_back(std::make_shared<player>(window , sf::Vector2f( 960.0, 960.0 ), sf::Vector2f{ 59.0, 0.0 }, game_setting, state_t));

        for(int i = 0; i <= int(window.getSize().y / 60); i++){
            build_line(window.getSize().y - (60 * i), i < 5);
        }

    }


void level::update(){
    players[0]->update();
    if(game_setting.started){
        for(auto& player : players){
            /// Dit is alleen de player die update
            player->lower();
            player->update();
                for(auto& line : lines){
                    /// Check of het object je dood maakt
                    player->check_dead(objects, line);
                    }
            }
        /// Update de lines. In line update je dan ook weer de objecten van de line.
        for(auto& line : lines){
            line->lower();
        }
        lines[0]->lower_obstakels();
        lines[0]->update();

        
        /// Hou het aantal ticks bij om nieuwe lines te maken.
        if(ticks % 60 == 0) {
            build_line();
            for(unsigned int index = 0; index < lines.size(); index++)
                if(lines[index]->get_position().y <= window.getSize().y/2) {
                    lines.erase(lines.begin() + index);
                    break;
                }
            }
        }
        ticks +=1;

    sf::Event event{};
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::KeyPressed) {
            if(state_t == GAME){
                for(auto& player : players){
                    /// Dit zou niet meer hoeven omdat het als een refrence wordt meegegeven.
//                    std::vector<std::shared_ptr<object>> objects = {};
//                    for(auto& line : lines){
//                        std::vector<std::shared_ptr<object>> & object = line->get_objects();
//                        objects.insert(objects.begin(), object.begin(), object.end());
//                    }
                    player->move(objects);
                }
            }
        }
    }
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
        std::shared_ptr<line> create_rails_line = std::make_shared<line>(window, sf::Vector2f{window.getSize().x/4.f, height},  sf::Vector2f{window.getSize().x/2.f, 59.0}, RAILS, NON_OBSTACLE, "rails_sprite",objects);
        lines.emplace_back(create_rails_line);
    }
    // Roads
    else if(line_type == 2 && force_grass_line == false) {  //todo WATER MUST BE CHANGED TO DEADLY
        std::shared_ptr<line> create_roads_line = std::make_shared<line>(window, sf::Vector2f{window.getSize().x/4.f, height},  sf::Vector2f{window.getSize().x/2.f, 59.0}, ROAD, NON_OBSTACLE, "roads_sprite",objects);
        lines.emplace_back(create_roads_line);
    }
    // Water
    else if(line_type == 3 && force_grass_line == false) {
        std::shared_ptr<line> create_water_line = std::make_shared<line>(window, sf::Vector2f{window.getSize().x/4.f, height},  sf::Vector2f{window.getSize().x/2.f, 59.0}, WATER, DEADLY, "water_sprite",objects);
        lines.emplace_back(create_water_line);
    }
    // Grass
    else if((line_type == 1 || 4) || force_grass_line == true) {
        // TODO No coins first 5
        std::shared_ptr<line> create_grass_line = std::make_shared<line>(window, sf::Vector2f{window.getSize().x/4.f, height},  sf::Vector2f{window.getSize().x/2.f, 59.0}, GRASS, NON_OBSTACLE, "grass_sprite",objects);
        lines.emplace_back(create_grass_line);
    }
}

