#include "drawable.hpp"

/// Drawable constructor
drawable::drawable(sf::RenderWindow & window, sf::Vector2f position, sf::Vector2f size):
    window(window),
    position(position),
    size(size)
{}

/// Kijkt wat er in de drawable is.
bool drawable::within( int x, int a, int b ){
   return ( x >= a ) && ( x <= b );
}

/// Checkt of de drawable overlapt
bool drawable::overlaps(std::shared_ptr<drawable> other) {
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

/// Geeft de positie terug van de drawable.
sf::Vector2f drawable::get_position(){return position;}

/// Geeft de size terug van de drawable.
sf::Vector2f drawable::get_size(){return size;}
