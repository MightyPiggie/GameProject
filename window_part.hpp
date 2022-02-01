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
    /**
     * @brief Construct a new window part object
     * 
     * @param window A reference to the window where everything is drawn on.
     * @param position 
     * @param size 
     * @param color 
     */
    window_part(sf::RenderWindow& window,
                sf::Vector2f position,
                sf::Vector2f size,
                sf::Color color = sf::Color::Green);
    /**
     * @brief Construct a new window part object
     * 
     * @param window A reference to the window where everything is drawn on.
     * @param position 
     * @param filename 
     */
    window_part(sf::RenderWindow& window,
                sf::Vector2f position,
                std::string filename);
    /**
     * @brief 
     * 
     */
    void draw() override;

    /**
     * @brief 
     * 
     * @param new_scale 
     */
    void rescale(sf::Vector2f new_scale);
    /**
     * @brief 
     * 
     * @param path 
     */
    void new_sprite(std::string path);
    /**
     * @brief 
     * 
     */
    void update() override;
};

/// window_part_player class, heritage van window_part
/// Gamaakt om de game settings over te sturen/ te delen/up to date houden tijdens de game.
class window_part_player : public window_part{
protected:
    std::string filename;
    game_settings & gameSettings;
public:
    /**
     * @brief Construct a new window part player object
     * 
     * @param window A reference to the window where everything is drawn on.
     * @param position 
     * @param filename 
     * @param gameSettings 
     */
    window_part_player(sf::RenderWindow& window,
                       sf::Vector2f position,
                       std::string filename,
                       game_settings & gameSettings);
    /**
     * @brief 
     * 
     */
    void draw() override;
    
    /**
     * @brief 
     * 
     */
    void update() override;
};

#endif
