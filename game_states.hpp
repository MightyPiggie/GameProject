#ifndef GAME_STATES_HPP
#define GAME_STATES_HPP

/**
 * @brief The enum state has the differant states the game is in at a certain moment of time.
 *
 */
enum state {MENU, GAME, DEAD, RESTART,SHOP, LOADING};

/**
 * @brief The enum object_states has the differant types a object can be.
 *
 */
enum object_states {DEADLY, OBSTACLE, NON_OBSTACLE, FLOATING , COIN};

#endif
