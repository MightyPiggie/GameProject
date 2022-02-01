#include "window_part.hpp"

window_part::window_part(sf::RenderWindow& window, sf::Vector2f position, sf::Vector2f size, sf::Color color):
    drawable(window, position, size)
{
    rect.setPosition(position);
    rect.setSize(size);
    rect.setFillColor(color);
}

window_part::window_part(
        sf::RenderWindow& window, sf::Vector2f position,std::string filename):
    drawable(window, position, {0,0})
{
    rect.setSize(sf::Vector2f(0,0));
    texture.loadFromFile(filename);
    sprite.setTexture(texture);
    sprite.setPosition(position);
}

void window_part::draw(){
    if(rect.getSize() == sf::Vector2f(0,0)) {
        window.draw(sprite);
    }
    else {
        window.draw(rect);
    }
}

void window_part::rescale(sf::Vector2f new_scale){
    sprite.setScale(new_scale);
}
void window_part::new_sprite(std::string path) {
    texture.loadFromFile(path);
    sprite.setTexture(texture);
}

void window_part::update() {
//    std::cout << "Update waardes" << std::endl;
    if(rect.getSize() == sf::Vector2f(0,0)) {
        window.draw(sprite);
    }
}



window_part_player::window_part_player(sf::RenderWindow &window,
                                       sf::Vector2f position,
                                       std::string filename,
                                       game_settings & gameSettings
                                       ):
                                       window_part(window, position, filename),
                                       filename(filename),
                                       gameSettings(gameSettings)
{}

void window_part_player::draw() {
    texture.loadFromFile(filename);
    sprite.setTexture(texture);
    sprite.setPosition(position);
    window.draw(sprite);
}

void window_part_player::update() {
    if(filename != "res/sprites/"+gameSettings.player+"_shop.png"){
        filename = "res/sprites/"+gameSettings.player+"_shop.png";
    }
}
