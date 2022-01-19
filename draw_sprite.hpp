//
// Created by Isaak van Luijk on 19/01/2022.
//

#ifndef V2CPSE2_EXAMPLES_DRAW_SPRITE_HPP
#define V2CPSE2_EXAMPLES_DRAW_SPRITE_HPP

#include "drawable.hpp"

class draw_sprite : public drawable{
protected:
    const std::string filename;
    sf::Texture texture;
    sf::Sprite sprite;
public:
    draw_sprite(sf::RenderWindow & window,
                sf::Vector2f position,
                sf::Vector2f size,
                const std::string filename);

    void draw()override;
};


#endif //V2CPSE2_EXAMPLES_DRAW_SPRITE_HPP
