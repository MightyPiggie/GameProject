#include "player.hpp"

void player::draw() {
    texture.loadFromFile(filename);
    sprite.setTexture(texture);
    sprite.setPosition(position);
    window.draw(sprite);
}

void player::move() {

    if (position.x != float(window_width)/4 && sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        position += sf::Vector2f{-movement_speed, 0};
    }
    else if (position.x != float(window_width)*3/4 - movement_speed && sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        position += sf::Vector2f{movement_speed, 0};
    }
    else if(position.y != 0 && sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        position += sf::Vector2f{0, -movement_speed};
    }
    else if(position.y != float(window_height) - movement_speed && sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        position += sf::Vector2f{0, +movement_speed};
    }
}




//class action {
//private:
//    std::function< bool() > condition;
//    std::function< void() > work;
//public:
//    action(
//            sf::Keyboard::Key key,
//            std::function< void() > work
//    ) :
//            condition(
//                    [ key ]()->bool { return sf::Keyboard::isKeyPressed( key ); }
//            ),
//            work(work)
//    {}
//};
