class drawable {
protected:
    sf::RenderWindow & window;
    sf::Vector2f position;
    sf::Vector2f size;
    //sf::Sprite image;
public:
    drawable(sf::RenderWindow & window, sf::Vector2f position, sf::Vector2f size):
        window(window), position(position), size(size){}
    //virtual bool overlaps() = 0;
    virtual void draw()=0;
    sf::Vector2f get_position(){return position;}
    sf::Vector2f get_size(){return size;}
    virtual void update(){}
};