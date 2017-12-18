/*
 * High_Score_List.h
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
    High_Score_List(); // constructor
    //High_Score_List(std::unique_ptr<vector<Entry>>); // constructor

    void run();
    void show_score();
    void add_entry(std::unique_ptr<Entry>);
    void save_to_file();
    //void load_to_file(std::string);

protected:
    std::vector<std::unique_ptr<Entry>> entries {};

    sf::RenderWindow window{};
    Button splash_screen {};
    Button return_button {};

    void render();
    void process_events();

    sf::Font caviar {};
    sf::Text score_text {};
    sf::Text score_text2 {};

};

#endif 
