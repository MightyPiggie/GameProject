//
// Created by Isaak van Luijk on 17/01/2022.
//

#include "drawable.hpp"

#include <iostream>

drawable::drawable(sf::RenderWindow & window, sf::Vector2f position, sf::Vector2f size, shitty_fix_enum state_t):
    window(window),
    position(position),
    size(size),
    state_t(state_t)
{}

//TODO Try without the =
bool drawable::within( int x, int a, int b ){
   return ( x >= a ) && ( x <= b );
}

bool drawable::overlaps(drawable* other) {
   if(other->state_t == start_ob) {
      bool x_overlap = within( 
         position.x, 
         other->position.x, 
         other->position.x + other->size.x
      ) || within( 
         other->position.x, 
         position.x, 
         position.x + size.x
      );
      bool y_overlap = within( 
         position.y, 
         other->position.y, 
         other->position.y + other->size.y
      ) || within( 
         other->position.y, 
         position.y, 
         position.y + size.y
      );
      return x_overlap && y_overlap;
   }
   else {
      bool x_overlap = within( 
         position.x, 
         other->position.x, 
         other->position.x + other->size.x
      ) || within( 
         other->position.x, 
         position.x, 
         position.x + size.x
      );
      bool y_overlap = within( 
         position.y, 
         other->position.y-60, 
         other->position.y-60 + other->size.y
      ) || within( 
         other->position.y-60, 
         position.y, 
         position.y + size.y
      );
      return x_overlap && y_overlap;
   }
}

//virtual void drawable::draw()=0;

sf::Vector2f drawable::get_position(){return position;}

sf::Vector2f drawable::get_size(){return size;}

//virtual void drawable::update(){}

game_drawable::game_drawable(sf::RenderWindow & window, sf::Vector2f position, sf::Vector2f size, shitty_fix_enum state_t, object_states object_state):
   drawable(window, position, size, state_t),
   object_state(object_state)
{}

void game_drawable::lower(){
   position.y += 1;
}