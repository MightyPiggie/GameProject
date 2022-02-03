#ifndef LABEL_PLAYER_SETTINGS_HPP
#define LABEL_PLAYER_SETTINGS_HPP

#include "label.hpp"
#include "game_settings.hpp"

// label_player_settings_coins class, heritage van label
class label_player_settings_coins : public label{
protected:
    game_settings & gameSettings;
public:

    /**
     * @brief Construct a new label player settings coins object
     * 
     * @param window A reference to the window where everything is drawn on.
     * @param position The position where the label will be placed on the screen.
     * @param text_string The string that will be placed ontop of the label.
     * @param size_char The size of the text.
     * @param background_text_color The color behind the text.
     * @param gameSettings A reference to all game settings of the game.
     * @param rectangle_display If this is true there will be a solid rectangle behind the text.
     * @param text_color The color of the displayed text.
     */
    label_player_settings_coins(sf::RenderWindow &window,
                                sf::Vector2f position,
                                std::string text_string,
                                int size_char,
                                sf::Color background_text_color,
                                game_settings & gameSettings,
                                bool rectangle_display = true,
                                sf::Color text_color = sf::Color::Black);

    /**
     * @brief The update function will update the text displayed on the label.
     * 
     */
    void update() override;
};

// label_player_settings_highscore class, heritage van label
class label_player_settings_highscore : public label{
protected:
    game_settings & gameSettings;
public:

    /**
     * @brief Construct a new label player settings highscore object
     * 
     * @param window A reference to the window where everything is drawn on.
     * @param position The position where the label will be placed on the screen.
     * @param text_string The string that will be placed ontop of the label.
     * @param size_char The size of the text.
     * @param background_text_color The color behind the text.
     * @param gameSettings A reference to all game settings of the game.
     * @param rectangle_display If this is true there will be a solid rectangle behind the text.
     * @param text_color The color of the displayed text.
     */
    label_player_settings_highscore(sf::RenderWindow &window,
                                sf::Vector2f position,
                                std::string text_string,
                                int size_char,
                                sf::Color background_text_color,
                                game_settings & gameSettings,
                                bool rectangle_display = true,
                                sf::Color text_color = sf::Color::Black);

    /**
     * @brief The update function will update the text displayed on the label.
     * 
     */
    void update() override;
};

// label_player_settings_score class, heritage van label
class label_player_settings_score : public label{
protected:
    game_settings & gameSettings;
public:
    /**
     * @brief Construct a new label player settings score object
     * 
     * @param window A reference to the window where everything is drawn on.
     * @param position The position where the label will be placed on the screen.
     * @param text_string The string that will be placed ontop of the label.
     * @param size_char The size of the text.
     * @param background_text_color The color behind the text.
     * @param gameSettings A reference to all game settings of the game.
     * @param rectangle_display If this is true there will be a solid rectangle behind the text.
     * @param text_color The color of the displayed text.
     */
    label_player_settings_score(sf::RenderWindow &window,
                                    sf::Vector2f position,
                                    std::string text_string,
                                    int size_char,
                                    sf::Color background_text_color,
                                    game_settings & gameSettings,
                                    bool rectangle_display = true,
                                    sf::Color text_color = sf::Color::Black);

    /**
     * @brief The update function will update the text displayed on the label.
     * 
     */
    void update() override;
};


#endif //LABEL_PLAYER_SETTINGS_HPP
