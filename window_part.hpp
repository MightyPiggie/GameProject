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
     * @param position Is a x and y coordinate for the top left corner
     * @param size Is a x and y coordinate for the bottom right corner. relative to position
     * @param color The background color. This is of a sf::Color class
     */
    window_part(sf::RenderWindow& window,
                sf::Vector2f position,
                sf::Vector2f size,
                sf::Color color = sf::Color::Green);
    /**
     * @brief Construct a new window part object
     * 
     * @param window A reference to the window where everything is drawn on.
     * @param position The x and y coordinate for the top left corner
     * @param filename the filename for the background
     */
    window_part(sf::RenderWindow& window,
                sf::Vector2f position,
                std::string filename);
    /**
     * @brief This draws the windowpart with a rectangle shape or an image.
     * 
     */
    void draw() override;

    /**
     * @brief This function rescales the image.
     * 
     * @param new_scale are a x and y scale.
     */
    void rescale(sf::Vector2f new_scale);
    /**
     * @brief This function loads a new sprite as background.
     * 
     * @param path is the filename
     */
    void new_sprite(std::string path);

};


class window_part_player : public window_part{
protected:
    std::string filename;
    game_settings & gameSettings;
public:
    /**
     * @brief Construct a new window part player object
     * 
     * @param window A reference to the window where everything is drawn on.
     * @param position A x and y for the top left corner
     * @param filename A filename for the background image
     * @param gameSettings A reference to the gamesettings
     */
    window_part_player(sf::RenderWindow& window,
                       sf::Vector2f position,
                       std::string filename,
                       game_settings & gameSettings);
    /**
     * @brief This function draws the window_part
     * 
     */
    void draw() override;
    
    /**
     * @brief This function loads a new image as background if the image has changed
     * 
     */
    void update() override;
};

#endif
