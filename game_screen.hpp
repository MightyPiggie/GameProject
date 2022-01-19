#ifndef GAME_SCREEN_HPP
#define GAME_SCREEN_HPP 


class gamewindow{
private:
    unsigned int width = sf::VideoMode::getDesktopMode().width;
    unsigned int  height =  sf::VideoMode::getDesktopMode().height;
    unsigned int ticks = 0;
    sf::RenderWindow window{ sf::VideoMode( width,height,32), "SFML window" , sf::Style::Fullscreen};
    state state_t;
<<<<<<< HEAD

public:

=======
    //uint16_t score = 0;
    uint16_t highscore;
    uint16_t coins;
    std::vector<std::string> unlocked_players = {};
    std::vector<std::string> init(){
        return read_values(coins, highscore);
    }
public:
>>>>>>> origin/scherm-loop-grid
    void run(){
        //window settingssettings
        window.setKeyRepeatEnabled(false);
        window.setFramerateLimit(60);
        unlocked_players = init();
        //start state
        state_t = MENU;
        //knoppen plus wat de knop moet doen
        ///Knoppen voor de game window.
        buttons quit_gamewindow(window,  {30,30}, {120,60},[this](){window.close();},"Quit", sf::Color(163 , 235 , 177));
        buttons back_to_menu_from_gamewindow(window, {30, 120}, {120, 60},[this](){state_t = MENU;},"Menu", sf::Color(163 , 235 , 177));
<<<<<<< HEAD

=======
        buttons display_coins(window, {float(width) - 200, 40}, {120, 60}, [this](){state_t = SHOP;},"coins", sf::Color(163 , 235 , 177));
>>>>>>> origin/scherm-loop-grid
        ///Knoppen voor de menu window
        buttons start_game(window, Vector2f_from_unsigned_ints(width/2 - 60, height - height/5), {120,60},[this](){state_t = GAME;},"Start", sf::Color(163 , 235 , 177));

        //initialisatie game
        window_part left(window,{0,0}, {float(width)/4.f, float(height)} , sf::Color(33 , 182 , 168));
        window_part right(window, {float(width)*3/4, 0}, {float(width)/4.f, float(height)} , sf::Color(33 , 182 , 168));
        window_part game_window(window,{float(width)/4.f, 0}, {float(width)/2.f, float(height)}, sf::Color(24 , 165 , 88));
        player player1 {window , sf::Vector2f{ 960.0, 960.0 }, sf::Vector2f{ 0.0, 0.0 }, "res/sprites/player_sprite.png" , width , height};
<<<<<<< HEAD
        obstacle test1 {window, sf::Vector2f{1020.0, 0.0}, sf::Vector2f{59.0, 59.0}, "res/sprites/Tree.png"};
=======
        obstacle test1 {window, sf::Vector2f{960.0, 0.0}, sf::Vector2f{60.0, 60.0}};
>>>>>>> origin/scherm-loop-grid
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
<<<<<<< HEAD
                    objects = {&left,&right, &quit_gamewindow, &back_to_menu_from_gamewindow, &player1, &test1};
=======
                    objects = {&left,&right, &quit_gamewindow, &back_to_menu_from_gamewindow, &player1, &test1, &display_coins};
>>>>>>> origin/scherm-loop-grid
                    for(auto object : gameobjects){
                        object->lower(1);
                        }
                    ticks +=1;
                    if(ticks == 60) {
                        std::cout << random_int_between_range(0,5) << std::endl;
                        ticks = 0;
                        }
                    }
<<<<<<< HEAD
=======
                    display_coins.update_coins(coins);
                }
>>>>>>> origin/scherm-loop-grid
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
                        player1.move(gameobjects);
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