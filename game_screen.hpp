#ifndef GAME_SCREEN_HPP
#define GAME_SCREEN_HPP 
#include "obstacle.hpp"

class leftwindow : public drawable{
protected:
    sf::RectangleShape rect;
public:
    leftwindow(sf::RenderWindow & window, unsigned int width, unsigned int height):
            drawable(window, {0,0}, Vector2f_from_unsigned_ints(width/4, height)){
        rect.setPosition(position);
        rect.setSize(size);
        rect.setFillColor(sf::Color::Cyan);
    }
    void draw() override{
        window.draw(rect);
    }
};

class rightwindow : public drawable{
protected:
    sf::RectangleShape rect;
public:
    rightwindow(sf::RenderWindow & window, unsigned int width, unsigned int height):
            drawable(window, Vector2f_from_unsigned_ints(width/4*3,0), Vector2f_from_unsigned_ints(width/4, height)){
        rect.setPosition(position);
        rect.setSize(size);
        rect.setFillColor(sf::Color::Cyan);
    }
    void draw() override{
        window.draw(rect);
    }
};

class game : public drawable{
protected:
    sf::RectangleShape rect;
public:
    game(sf::RenderWindow & window, unsigned int width, unsigned int height):
        drawable(window, Vector2f_from_unsigned_ints(width/4,0), Vector2f_from_unsigned_ints(width/2, height)){
        rect.setPosition(position);
        rect.setSize(size);
        rect.setFillColor(sf::Color::Green);
    }
    void draw() override{
        window.draw(rect);
    }
};

class gamewindow{
private:
    unsigned int width = sf::VideoMode::getDesktopMode().width;
    unsigned int  height =  sf::VideoMode::getDesktopMode().height;
    sf::RenderWindow window{ sf::VideoMode( width,height,32), "SFML window" , sf::Style::Fullscreen};
    state state_t;
public:
    void loop(){
        //window settingssettings
        window.setKeyRepeatEnabled(false);
        window.setFramerateLimit(60);

        //start state
        state_t = MENU;
        //knoppen plus wat de knop moet doen
<<<<<<< Updated upstream
        buttons quit(window, {30,30}, {120,60}, sf::Color::Green);
        startbutton start_game(window, Vector2f_from_unsigned_ints(width/2 - 60, height - height/5), {120,60},state_t, sf::Color::Green);
        back_to_menu_button back(window, {30, 120}, {120, 60}, state_t, sf::Color::Green);
        //initialisatie game
        leftwindow left(window,width, height);
        rightwindow right(window,width, height);
        game game_window(window, width, height);
        player player1 {window , sf::Vector2f{ 960.0, 960.0 }, sf::Vector2f{ 0.0, 0.0 }, "res/sprites/player_sprite.png" , width , height};
        obstacle test1 {window, sf::Vector2f{1000.0, 1000.0}, sf::Vector2f{10.0, 10.0}};
=======
        buttons quit(window,  {30,30}, {120,60},[this](){window.close();},"Quit", sf::Color::Green);
        buttons start_game(window, Vector2f_from_unsigned_ints(width/2 - 60, height - height/5), {120,60},[this](){state_t = GAME;},"Start", sf::Color::Green);
        buttons back(window, {30, 120}, {120, 60},[this](){state_t = MENU;},"Menu", sf::Color::Green);
        //initialisatie game
        window_part left(window,{0,0}, {float(width)/4.f, float(height)});
        window_part game_window(window,{float(width)/4.f, 0}, {float(width)/2.f, float(height)}, sf::Color::Cyan);
        window_part right(window, {float(width)*3/4, 0}, {float(width)/4.f, float(height)});
        player player1 {window , sf::Vector2f{ float(width)/2, float(height)*3/5 }, sf::Vector2f{ 0.0, 0.0 }, "res/sprites/player_sprite.png" , width , height};
        obstacle obstacle1 {window, sf::Vector2f{1000.0, 1000.0}, sf::Vector2f{10.0, 10.0}};
>>>>>>> Stashed changes
        //initialistie menu
        menu Menu(window, {0,0}, Vector2f_from_unsigned_ints(width, height));

        //lijst van objecten
        std::vector<drawable *> objects = {};
        std::vector<game_drawable *> gameobjects = {&player1, &obstacle1};
        //gameloop
        while (window.isOpen()) {
            switch (state_t) {
                case GAME: {
<<<<<<< Updated upstream
                    objects = {&left, &right, &game_window, &quit, &back, &player1, &test1};
=======
                    objects = {&left,&right, &quit, &back, &game_window, &player1, &obstacle1};
>>>>>>> Stashed changes
                    for(auto object : gameobjects){
                        object->lower(1);
                    }
                }
                    break;
                case MENU: {
                    objects = {&Menu, &start_game};
                }
                    break;
                case DEAD : case SHOP:
                    break;

            }
            sf::Event event{};
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::KeyPressed) {
                    if(state_t == GAME){
                         player1.move();
                    }

                }
                if (event.type == sf::Event::Closed) {
                    window.close();
                }
            }
            window.clear();
            for (auto &object: objects) {
                object->update();
            }
            for (auto &object: objects) {
                object->draw();
            }
            window.display();
            sf::sleep(sf::milliseconds(20));
        }
    }
};

#endif