#ifndef GAME_STATE_SHOP_HPP
#define GAME_STATE_SHOP_HPP
#include <SFML/Graphics.hpp>

#include "drawable.hpp"
#include "game_states.hpp"
#include "buttons.hpp"
#include "window_part.hpp"

//initialisatie shop
class game_state_shop : public drawable{
private:
    state & state_t;
    std::vector<drawable*> objects;
    window_part shop_window;
    buttons quit_gamewindow;
    buttons back_to_menu_from_gamewindow;
    buttons shop_buy_button;

public:
    game_state_shop(sf::RenderWindow& window, state & state_t,unsigned int width,unsigned int height);
    void draw() override;
    void update() override;


};

#endif
