#include "builder_biome.hpp"

#include "simple_functions.hpp"

builder_biome::builder_biome(sf::RenderWindow& window,
            game_settings& game_setting,
            state& state_t,
            sound_class & the_sound_class_builder_biome):
        window(window),
        game_setting(game_setting),
        state_t(state_t),
        the_sound_class_builder_biome(the_sound_class_builder_biome)
    {
        players.emplace_back(std::make_shared<player>(window , sf::Vector2f( 960.0, 960.0 ), sf::Vector2f{ 59.0, 0.0 }, game_setting, state_t, the_sound_class_builder_biome));

        for(int i = 0; i <= int(window.getSize().y / 60); i++){
            build_line(window.getSize().y - (60 * i), i < 5);
        }

    }


void builder_biome::update(){
    players[0]->update();
    if(game_setting.started){
        for(auto& player : players){
            /// Dit is alleen de player die update
            player->lower();
            player->update();
                for(auto& line : lines){
                    /// Check of het object je dood maakt
                    player->check_dead(line->objects_for_level, line);
                    }
            }
        /// Update de lines. In line update je dan ook weer de objecten van de line.
        for(auto& line : lines){
            line->lower();
            line->update();
        }

        
        /// Hou het aantal ticks bij om nieuwe lines te maken.
        if(ticks % 60 == 0) {
            build_line();
            for(unsigned int index = 0; index < lines.size(); index++)
                if(lines[index]->get_position().y <= window.getSize().y+60) {
                    lines.erase(lines.begin() + index);
                    break;
                }
        }
    ticks +=1;
    }

    sf::Event event{};
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::KeyPressed) {
            if(state_t == GAME){
                for(auto& player : players){
                    player->move(lines);
                }
            }
        }
    }
}

void builder_biome::draw(){
    for(auto& line : lines){
        line->draw();
    }
    for(auto& player : players){
        player->draw();
    }
}

void builder_biome::build_line(float height, bool force_grass_line) {
    unsigned int line_type = random_int_between_range(0,4);
    // Rails
    if(line_type == 0 && force_grass_line == false) {
        std::shared_ptr<builder_object> create_rails_line = std::make_shared<builder_object>(window, sf::Vector2f{window.getSize().x/4.f, height},  sf::Vector2f{window.getSize().x/2.f, 59.0}, RAILS, NON_OBSTACLE, "rails_sprite");
        lines.emplace_back(create_rails_line);
    }
    // Roads
    else if(line_type == 2 && force_grass_line == false) {
        std::shared_ptr<builder_object> create_roads_line = std::make_shared<builder_object>(window, sf::Vector2f{window.getSize().x/4.f, height},  sf::Vector2f{window.getSize().x/2.f, 59.0}, ROAD, NON_OBSTACLE, "roads_sprite");
        lines.emplace_back(create_roads_line);
    }
    // Water
    else if(line_type == 3 && force_grass_line == false) {
        std::shared_ptr<builder_object> create_water_line = std::make_shared<builder_object>(window, sf::Vector2f{window.getSize().x/4.f, height},  sf::Vector2f{window.getSize().x/2.f, 59.0}, WATER, DEADLY, "water_sprite");
        lines.emplace_back(create_water_line);
    }
    // Grass
    else if((line_type == 1 || 4) || force_grass_line == true) {
        // TODO No coins first 5
        std::shared_ptr<builder_object> create_grass_line = std::make_shared<builder_object>(window, sf::Vector2f{window.getSize().x/4.f, height},  sf::Vector2f{window.getSize().x/2.f, 59.0}, GRASS, NON_OBSTACLE, "grass_sprite");
        lines.emplace_back(create_grass_line);
    }
}

