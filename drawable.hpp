#ifndef DRAWABLE_HPP
#define DRAWABLE_HPP

#include <SFML/Graphics.hpp>
#include <memory>

#include "game_states.hpp"

class drawable {
protected:
    sf::RenderWindow & window;
    sf::Vector2f position;
    sf::Vector2f size;
public:
    drawable(sf::RenderWindow & window, sf::Vector2f position, sf::Vector2f size);
    bool within( int x, int a, int b );
    bool overlaps(std::shared_ptr<drawable> other);
    virtual void draw()=0;
    virtual void update(){}
    sf::Vector2f get_position();
    sf::Vector2f get_size();
    virtual sf::FloatRect getbounds() {return sf::FloatRect{};};
};

#endif
