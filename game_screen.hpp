#ifndef GAME_SCREEN_HPP
#define GAME_SCREEN_HPP

class leftwindow : public drawable{
protected:
    sf::RectangleShape rect;
public:
    leftwindow(sf::RenderWindow & window, unsigned int width, unsigned int height):
            drawable(window, {0,0}, Vector2f_from_unsigned_ints(width/4, height)){}
    void draw() override{
        rect.setPosition(position);
        rect.setSize(size);
        rect.setFillColor(sf::Color::Cyan);
        window.draw(rect);
    }
};

class rightwindow : public drawable{
protected:
    sf::RectangleShape rect;
public:
    rightwindow(sf::RenderWindow & window, unsigned int width, unsigned int height):
            drawable(window, Vector2f_from_unsigned_ints(width/4*3,0), Vector2f_from_unsigned_ints(width/4, height)){}
    void draw() override{
        rect.setPosition(position);
        rect.setSize(size);
        rect.setFillColor(sf::Color::Cyan);
        window.draw(rect);
    }
};

class game : public drawable{
protected:
    sf::RectangleShape rect;
    unsigned int width;
    unsigned int height;
public:
    game(sf::RenderWindow & window, unsigned int width, unsigned int height):
        drawable(window, Vector2f_from_unsigned_ints(width/4,0), Vector2f_from_unsigned_ints(width/2, height)), width(width/2), height(height){
        std::cout << width/2 << ", " << height << std::endl;
    }
    void draw() override{
        rect.setPosition(position);
        rect.setSize(size);
        rect.setFillColor(sf::Color::Green);
        window.draw(rect);
    }
};

class gamewindow{
private:
    sf::RenderWindow window{ sf::VideoMode( 800,600,32), "SFML window" , sf::Style::Fullscreen};
    unsigned int width = sf::VideoMode::getDesktopMode().width;
    unsigned int  height =  sf::VideoMode::getDesktopMode().height;
public:
    void loop(){
         std::cout << width << ", " << height << std::endl;
        window.setKeyRepeatEnabled(false);
        window.setFramerateLimit(60);
        leftwindow left(window,width, height);
        rightwindow right(window,width, height);
        game game_window(window, width, height);
        std::vector<drawable *> objects = {&left, &right, &game_window};
        while (window.isOpen()) {
            for( auto & object : objects ){

                object->draw();
            }
            //clearing the window and drawing all the objects again.
            window.display();
            sf::sleep( sf::milliseconds( 100 ));
            sf::Event event{};
            while( window.pollEvent(event) ){
                if( event.type == sf::Event::Closed ){
                    window.close();
                }
            }
            window.clear();
        }
    }
};

#endif