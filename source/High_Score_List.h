/*
 * High_Score_List.h
 This class handles player entries and display of the high score list.
 */

#ifndef HIGH_SCORE_LIST_H
#define HIGH_SCORE_LIST_H

#include <SFML/Graphics.hpp>
#include "Game.h"
#include "Start_Menu.h"
#include "Button.h"
#include "Entry.h"
#include <string>
#include <memory>
#include <vector>

class High_Score_List : public Game, public Entry
{
public:
    High_Score_List();

    void run();
    void show_score();
    void add_entry(std::unique_ptr<Entry>);
    void save_to_file();

protected:
    std::vector<std::unique_ptr<Entry>> entries {};

    sf::RenderWindow window{};
    Button splash_screen {};
    Button return_button {};

    void render();
    void process_events();

    sf::Font caviar {};
    sf::Text highscore_text {};
    sf::Text score_text1 {};
    sf::Text score_text2 {};
    sf::Text score_text3 {};
    sf::Text score_text4 {};
    sf::Text score_text5 {};
    sf::Text score_text6 {};
    sf::Text score_text7 {};
    sf::Text score_text8 {};
    sf::Text score_text9 {};
    sf::Text score_text10 {};
};

#endif 
