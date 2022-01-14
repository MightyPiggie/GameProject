#ifndef GAME_SCREEN_HPP
#define GAME_SCREEN_HPP

class leftwindow : public drawable{
protected:
    sf::RectangleShape rect;
    buttons & quit;
public:
    leftwindow(sf::RenderWindow & window, unsigned int width, unsigned int height, buttons & quit):
            drawable(window, {0,0}, Vector2f_from_unsigned_ints(width/4, height)), quit(quit){}
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
    enum state {MENU, SPEL, DOOD, SHOP};
public:
    void loop(){
        std::cout << width << ", " << height << std::endl;
        window.setKeyRepeatEnabled(false);
        window.setFramerateLimit(60);
        state state_t = SPEL;
        switch(state_t){
            case SPEL:{
                buttons quit(window, {30,30}, {120,60}, sf::Color::Green);
                leftwindow left(window,width, height, quit);
                rightwindow right(window,width, height);
                game game_window(window, width, height);
                std::vector<drawable *> objects = {&left, &right, &game_window, &quit};
                while (window.isOpen()) {
                    for (auto &object : objects) {
                        object->update();
                    }
                    for (auto &object : objects) {
                        object->draw();
                    }
                    //clearing the window and drawing all the objects again.
                    window.display();
                    sf::sleep(sf::milliseconds(20));
                    sf::Event event{};
                    while (window.pollEvent(event)) {
                        if (event.type == sf::Event::Closed) {
                            window.close();
                        }
                    }
                    window.clear();
                }
            }break;
            case MENU:{

            }break;
            case DOOD:{

            }break;
            case SHOP:{

            }break;

        }
    }
};

#endif