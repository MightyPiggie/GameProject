#ifndef BUTTONS_HPP
#define BUTTONS_HPP

#include <functional>
#include <string>
#include <SFML/Graphics.hpp>

#include "drawable.hpp"

// buttons class, heritage van drawable
class buttons : public drawable{
protected:
    std::function<void(void)> function;
    std::string name;
    sf::RectangleShape rect;
    sf::Color color_button;
    sf::Color hover;
    int char_size;
    sf::Font font;
    sf::Text txt;

public:
    /**
     * @brief Construct a new buttons object
     * 
     * @param window A reference to the window where everything is drawn on.
     * @param char_size The size of the chars of the created button.
     * @param position The position where the button will be placed on the screen.
     * @param function A std::function of what the button should do when pressed.
     * @param name The text which is shown on the button.
     * @param color_button The color of the button.
     * @param hover The color of the button when the mouse is ontop of the button.
     */
    buttons(sf::RenderWindow &window,
             int char_size,
            sf::Vector2f position,
            std::function<void(void)> function,
            std::string name,
            sf::Color color_button,
            sf::Color hover = sf::Color::Black);
    /**
     * @brief The draw function will draw the button on the screen. And it will draw the text ontop of the button.
     * 
     */
    void draw() override;

    /**
     * @brief The update function will check if the mouse is ontop of the button and if its pressed. If it is it will call the function given by the constructor.
     * 
     */
    void update() override;
};

#endif
