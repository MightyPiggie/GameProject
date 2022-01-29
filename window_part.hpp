#ifndef WINDOW_PART_HPP
#define WINDOW_PART_HPP

#include <SFML/Graphics.hpp>
#include <string>

#include "drawable.hpp"
#include "game_settings.hpp"

/// window_part class, heritage van drawable
class window_part : public drawable{
protected:
    sf::RectangleShape rect;
    sf::Texture texture;
    sf::Sprite sprite;

public:
    window_part(sf::RenderWindow& window,
                sf::Vector2f position,
                sf::Vector2f size,
                sf::Color color = sf::Color::Green);

    window_part(sf::RenderWindow& window,
                sf::Vector2f position,
                std::string filename);

    void draw() override;
    void rescale(sf::Vector2f new_scale);
    void new_sprite(std::string path);
    void update() override;
};

/// window_part_player class, heritage van window_part
/// Gamaakt om de game settings over te sturen/ te delen/up to date houden tijdens de game.
class window_part_player : public window_part{
protected:
    std::string filename;
    game_settings & gameSettings;
public:
    window_part_player(sf::RenderWindow& window,
                       sf::Vector2f position,
                       std::string filename,
                       game_settings & gameSettings);

    void draw() override;
    void update() override;
};

#endif
