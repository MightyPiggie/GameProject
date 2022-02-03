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
    /**
    * @brief Construct a new game_state_loading_screen object
    *
    * @param state_t A refence to the state of which the game is in.
    * @param the_sound_class_loading_screen A reference to the sound_class object thats needed for the sound.
    */
    game_state_loading_screen(sf::RenderWindow & window,
                   state & state_t,
                   sound_class & the_sound_class_loading_screen);
    
    /**
     * @brief The draw function will call all objects draw function.
     * 
     */
    void draw() override;
    
    /**
    * @brief Load all the music into the buffers.
    *
    */
    void loading();
};


#endif
