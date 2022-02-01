//
// Created by Isaak van Luijk on 19/01/2022.
//

#ifndef LABEL_HPP
#define LABEL_HPP

#include <SFML/Graphics.hpp>
#include <string>

#include "drawable.hpp"

/// label class, heritage van drawable
class label : public drawable{
protected:
    std::string text_string;
    int size_char;
    bool rectangle_display;
    sf::Color text_color;
    sf::Color background_text_color;

    sf::RectangleShape rect_SFML;
    sf::Font font_text;
    sf::Text text_SFML;
public:
    /**
     * @brief Construct a new label object
     * 
     * @param window A reference to the window where everything is drawn on.
     * @param position 
     * @param text_string 
     * @param size_char 
     * @param background_text_color 
     * @param rectangle_display 
     * @param text_color 
     */
    label(sf::RenderWindow &window,
        sf::Vector2f position,
        std::string text_string,
        int size_char,
        sf::Color background_text_color,
        bool rectangle_display = true,
        sf::Color text_color = sf::Color::Black);

    /**
     * @brief 
     * 
     */
    void draw() override;

    /**
     * @brief 
     * 
     * @param new_value 
     */
    void update_text(std::string new_value);
};
#endif
