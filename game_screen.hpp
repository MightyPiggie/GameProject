#ifndef GAME_SCREEN_HPP
#define GAME_SCREEN_HPP

#include "label.hpp"
#include "obstacle.hpp"

class gamewindow{
private:
    unsigned int width = sf::VideoMode::getDesktopMode().width;
    unsigned int  height =  sf::VideoMode::getDesktopMode().height;
    //unsigned int ticks = 0;
    sf::RenderWindow window{ sf::VideoMode( width,height,32), "SFML window" , sf::Style::Fullscreen};
    state state_t;
    //uint16_t score = 0;
    uint16_t highscore;
    uint16_t coins;
    std::vector<std::string> unlocked_players = {};
    std::vector<std::string> init(){
        return read_values(coins, highscore);
    }
public:
    void run(){
        //window settingssettings
        window.setKeyRepeatEnabled(false);
        window.setFramerateLimit(60);
        unlocked_players = init();

        //sprite factory
        std::ifstream sprite_file("sprite_file.txt");
        sprite_factory sprite_reader;
        std::map<std::string , std::string> sprite_files_map = sprite_reader.spritefile_read(sprite_file);

        //start state
        state_t = MENU;
        //knoppen plus wat de knop moet doen
        ///Knoppen voor de game window.

        ///Knoppen voor de menu window //TODO FIX THIS
        buttons quit_in_menu_window(window,  50, Vector2f_from_unsigned_ints(width/2 - 250, height/2 + 350),[this](){window.close();},"Quit", sf::Color(163 , 235 , 177));
        buttons shop_button_in_menu_window(window,  50, Vector2f_from_unsigned_ints(width/2 + 120, height/2 + 350),[this](){state_t = SHOP;},"Shop", sf::Color(163 , 235 , 177));
//        buttons title_in_menu_window(window, Vector2f_from_unsigned_ints(width/2-250,height/2),{210,10},
//                                     [](){
//                                         sf::SoundBuffer buffer;
//                                         sf::Sound sound;
//                                         buffer.loadFromFile("res/sounds/menu-window-title.wav");
//                                         sound.setBuffer(buffer);
//                                         std::cout << "speel geluid\n";
//                                         sound.play();},
//                                         "Levensmoedige Vogels",
//                                         sf::Color(163 , 235 , 177));
        buttons test_button(window, 50, {120,60},[this](){state_t = SHOP;},"Testtest", sf::Color(163 , 235 , 177));
        label title_in_menu_window(window,{300,40},"Levensmoedige vogel",30,sf::Color(163 , 235 , 177));
        window_part player_icon_menu_window(window, Vector2f_from_unsigned_ints(width/2 -30,height/2 + 80),sprite_files_map["chicken_sprite"]);
        //knoppen plus wat de knop moet doen
        ///Knoppen voor de game window.
        buttons quit_gamewindow(window, 50,  {40,30},  [this](){window.close();},"Quit", sf::Color(163 , 235 , 177));
        buttons back_to_menu_from_gamewindow(window, 50,  {40, 120}, [this](){state_t = MENU;},"Menu", sf::Color(163 , 235 , 177));
             ///Knoppen voor de menu window
        buttons start_game(window, 100,  Vector2f_from_unsigned_ints(width/2 - 60, height - height/5), [this](){state_t = GAME;},"Start", sf::Color(163 , 235 , 177));

        //initialisatie game
        window_part left(window,{0,0}, {float(width)/4.f, float(height)} , sf::Color(33 , 182 , 168));
        window_part right(window, {float(width)*3/4, 0}, {float(width)/4.f, float(height)} , sf::Color(33 , 182 , 168));
        window_part game_window(window,{float(width)/4.f, 0}, sprite_files_map["background_sprite"]);
        player player1 {window , sf::Vector2f{ 960.0, 960.0 }, sf::Vector2f{ 0.0, 0.0 }, sprite_files_map["chicken_sprite"], width , height};
        obstacle test1 {window, sf::Vector2f{960.0, 0.0}, sf::Vector2f{59.0, 59.0} ,OBSTACLE, sprite_files_map["tree_sprite"]};
        obstacle road1 {window, sf::Vector2f{float(width)/4.f, 120.0}, sf::Vector2f{59.0, 59.0} ,NON_OBSTACLE, sprite_files_map["roads_sprite"]};
        label display_coins(window, sf::Vector2f(float(width) - 200.f, 200), std::to_string(coins), 25, sf::Color::Green);
        //initialistie menu
        menu Menu(window, {0,0}, Vector2f_from_unsigned_ints(width, height));

        //lijst van objecten
        std::vector<drawable *> objects = {};
        std::vector<game_drawable *> gameobjects = {&player1, &test1 , &road1};
        //gameloop
        while (window.isOpen()) {
            switch (state_t) {
                case GAME: {
                    objects = {&left,&game_window, &road1, &right, &quit_gamewindow, &back_to_menu_from_gamewindow,&player1, &test1, &display_coins};
                    for(auto object : gameobjects){
                        object->lower();
                    }
//                    ticks +=1;
//                    if(ticks == 60) {
//                        //std::cout << random_int_between_range(0,5) << std::endl;
//                        ticks = 0;
//                        }
                    }
                    //std::cout << coins << std::endl;
                    break;
                case MENU: {
                    objects = {&Menu, &start_game, &title_in_menu_window, &quit_in_menu_window, &shop_button_in_menu_window, &player_icon_menu_window};
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
            for (auto &object: objects) {
                object->draw();
            }
            window.display();
            sf::sleep(sf::milliseconds(20));
        }
    }
};

#endif