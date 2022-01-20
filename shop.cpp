#include "shop.hpp"

shop::shop(sf::RenderWindow& window,state & state_t, unsigned int width,unsigned int height): drawable(window,
                                                                                                                             {0,0}, {0,0}),
                                                                                                                             state_t(state_t),
                                                                                                                             shop_window(window, {0,0}, {float(width), float(height)}, sf::Color(33,182,168)),
                                                                                                                    quit_gamewindow(window, 50,  {40,30},  [&](){window.close();},"Quit", sf::Color(163 , 235 , 177)),
                                                                                                                    back_to_menu_from_gamewindow(window, 50,  {40, 120}, [&](){state_t = MENU;},"Menu", sf::Color(163 , 235 , 177)),
                                                                                                                    shop_buy_button(window, 50, {float(width)/2-120.f/2, float(height)/2-60.f/2 + 350}, [&](){state_t = SHOP;}, "Buy", sf::Color(163 , 235 , 177)){

//    buttons shop_equip_button(window, {float(width)/2-120.f/2, float(height)/2-60.f/2 + 350}, {120,60}, [this](){state_t = SHOP;}, "Equip", sf::Color(163 , 235 , 177));
    objects = {&shop_window,&quit_gamewindow,&back_to_menu_from_gamewindow, &shop_buy_button};
}

void shop::draw() {
    for(auto &object : objects){
        object->draw();
    }
}

void shop::update() {
    for(auto &object: objects){
        object->update();
    }
    sf::Event event{};
    while (window.pollEvent(event)) {}

}