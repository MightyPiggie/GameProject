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
     * @param position The position where the label will be placed on the screen.
     * @param text_string The string that will be placed ontop of the label.
     * @param size_char The size of the text.
     * @param background_text_color The color behind the text.
     * @param rectangle_display If this is true there will be a solid rectangle behind the text.
     * @param text_color The color of the displayed text.
     */
    label(sf::RenderWindow &window,
        sf::Vector2f position,
        std::string text_string,
        int size_char,
        sf::Color background_text_color,
        bool rectangle_display = true,
        sf::Color text_color = sf::Color::Black);

    /**
     * @brief The draw function will draw the labels and update the position and size.
     * 
     */
    void draw() override;

    /**
     * @brief The update_text function will update the text displayed on the label when called.
     * 
     * @param new_value The new text that will be displayed ontop of the label.
     */
    void update_text(std::string new_value);
};
#endif
