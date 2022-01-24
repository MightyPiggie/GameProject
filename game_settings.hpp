#ifndef GAME_SETTINGS_HPP
#define GAME_SETTINGS_HPP
struct game_settings{
    uint16_t score = 0;
    uint16_t highscore = 0;
    uint16_t coins = 0;
    bool started = false;
    bool sound = true;
};
#endif