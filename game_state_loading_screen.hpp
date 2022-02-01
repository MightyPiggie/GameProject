#ifndef GAME_STATE_LOADING_SCREEN_HPP
#define GAME_STATE_LOADING_SCREEN_HPP

#include "drawable.hpp"
#include "sound_class.hpp"

class game_state_loading_screen : public drawable{
protected:
    state & state_t;
    sound_class & the_sound_class_loading_screen;

    std::vector<std::shared_ptr<drawable>> objects;
public:
    game_state_loading_screen(sf::RenderWindow & window,
                   state & state_t,
                   sound_class & the_sound_class_loading_screen);

    void draw() override;
    void loading();
};


#endif
