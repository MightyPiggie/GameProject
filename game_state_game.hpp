#ifndef GAME_STATE_GAME_HPP
#define GAME_STATE_GAME_HPP

#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>
#include <map>
#include <string>

#include "drawable.hpp"
#include "window_part.hpp"
#include "label.hpp"
#include "sprite_factory.hpp"
#include "buttons.hpp"
#include "game_settings.hpp"
#include "level.hpp"


/// game_state_game class, heritage van drawable
class game_state_game : public drawable{
private:
    game_settings & gameSettings;
    state & state_t;
    unsigned int width;
    unsigned int height;
    std::vector<std::shared_ptr<label>> labels;
    std::vector<std::shared_ptr<drawable>> drawables;
    std::vector<std::shared_ptr<drawable>> drawables1;
    level level1;

public:
    /**
     * @brief Construct a new game state game object
     * 
     * @param window 
     * @param width 
     * @param height 
     * @param gameSettings 
     * @param state_t 
     */
    game_state_game(sf::RenderWindow & window,
                    unsigned int width,
                    unsigned int height,
                    game_settings & gameSettings,
                    state & state_t);
//    ~game_state_game();
    sf::Texture screenshot_gamescreen;

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

    /**
     * @brief 
     * 
     */
    void destructor();

    /**
     * @brief 
     * 
     * @param rhs 
     * @return std::shared_ptr<game_state_game> 
     */
    std::shared_ptr<game_state_game> operator= (std::shared_ptr<game_state_game> rhs){
        return rhs;
    }
};

#endif