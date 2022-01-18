#ifndef GAME_SCREEN_HPP
#define GAME_SCREEN_HPP 


class gamewindow{
private:
    unsigned int width = sf::VideoMode::getDesktopMode().width;
    unsigned int  height =  sf::VideoMode::getDesktopMode().height;
    sf::RenderWindow window{ sf::VideoMode( width,height,32), "SFML window" , sf::Style::Fullscreen};
    state state_t;

public:

    void run(){
        //window settingssettings
        window.setKeyRepeatEnabled(false);
        window.setFramerateLimit(60);

        //start state
        state_t = MENU;
        //knoppen plus wat de knop moet doen
        ///Knoppen voor de game window.
        buttons quit_gamewindow(window,  {30,30}, {120,60},[this](){window.close();},"Quit", sf::Color(163 , 235 , 177));
        buttons back_to_menu_from_gamewindow(window, {30, 120}, {120, 60},[this](){state_t = MENU;},"Menu", sf::Color(163 , 235 , 177));

        ///Knoppen voor de menu window
        buttons start_game(window, Vector2f_from_unsigned_ints(width/2 - 60, height - height/5), {120,60},[this](){state_t = GAME;},"Start", sf::Color(163 , 235 , 177));

        //initialisatie game
        window_part left(window,{0,0}, {float(width)/4.f, float(height)} , sf::Color(33 , 182 , 168));
        window_part right(window, {float(width)*3/4, 0}, {float(width)/4.f, float(height)} , sf::Color(33 , 182 , 168));
        window_part game_window(window,{float(width)/4.f, 0}, {float(width)/2.f, float(height)}, sf::Color(24 , 165 , 88));
        player player1 {window , sf::Vector2f{ 960.0, 960.0 }, sf::Vector2f{ 0.0, 0.0 }, "res/sprites/player_sprite.png" , width , height};
        obstacle test1 {window, sf::Vector2f{960.0, 0.0}, sf::Vector2f{60.0, 60.0}};
        //initialistie menu
        menu Menu(window, {0,0}, Vector2f_from_unsigned_ints(width, height));

        //lijst van objecten
        std::vector<drawable *> objects = {};
         std::vector<game_drawable *> gameobjects = {&player1, &test1};
        //gameloop
        while (window.isOpen()) {
            switch (state_t) {
                case GAME: {
                    //
                    objects = {&left,&right, &quit_gamewindow, &back_to_menu_from_gamewindow, &player1, &test1};
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
            game_window.spritedraw("res/sprites/background.png");
            for (auto &object: objects) {
                object->draw();
            }
            window.display();
            sf::sleep(sf::milliseconds(20));
        }
    }
};

#endif