/*
 * High_Score_List.cc
 This class handles player entries and display of the high score list.
 */

#include <SFML/Graphics.hpp>
#include "High_Score_List.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

High_Score_List::High_Score_List()
<<<<<<< HEAD
    : window(sf::VideoMode(1280, 720), "Highscore List"),
      return_button{Button(12,12,0,0,"resources/button_back.png")}
{
    window.setFramerateLimit(60);
    return_button.get_sprite().setPosition(0,0);

    // Background
    background_texture.loadFromFile("resources/menubackground.png");
    background_sprite.setTexture(background_texture);

    font.loadFromFile("resources/arial.ttf");

    score_text1.setFont(font);
    score_text1.setCharacterSize(20);
    score_text1.setStyle(sf::Text::Bold);
    score_text1.setFillColor(sf::Color(255,255,255));
    score_text1.setPosition(400,150);

    score_text2.setFont(font);
    score_text2.setCharacterSize(20);
    score_text2.setStyle(sf::Text::Bold);
    score_text2.setFillColor(sf::Color(255,255,255));
    score_text2.setPosition(400,200);

    score_text3.setFont(font);
    score_text3.setCharacterSize(20);
    score_text3.setStyle(sf::Text::Bold);
    score_text3.setFillColor(sf::Color(255,255,255));
    score_text3.setPosition(400,250);

    score_text4.setFont(font);
    score_text4.setCharacterSize(20);
    score_text4.setStyle(sf::Text::Bold);
    score_text4.setFillColor(sf::Color(255,255,255));
    score_text4.setPosition(400,300);

    score_text5.setFont(font);
    score_text5.setCharacterSize(20);
    score_text5.setStyle(sf::Text::Bold);
    score_text5.setFillColor(sf::Color(255,255,255));
    score_text5.setPosition(400,350);

    score_text6.setFont(font);
    score_text6.setCharacterSize(20);
    score_text6.setStyle(sf::Text::Bold);
    score_text6.setFillColor(sf::Color(255,255,255));
    score_text6.setPosition(400,400);

    score_text7.setFont(font);
    score_text7.setCharacterSize(20);
    score_text7.setStyle(sf::Text::Bold);
    score_text7.setFillColor(sf::Color(255,255,255));
    score_text7.setPosition(400,450);

    score_text8.setFont(font);
    score_text8.setCharacterSize(20);
    score_text8.setStyle(sf::Text::Bold);
    score_text8.setFillColor(sf::Color(255,255,255));
    score_text8.setPosition(400,500);

    score_text9.setFont(font);
    score_text9.setCharacterSize(20);
    score_text9.setStyle(sf::Text::Bold);
    score_text9.setFillColor(sf::Color(255,255,255));
    score_text9.setPosition(400,550);

    score_text10.setFont(font);
    score_text10.setCharacterSize(20);
    score_text10.setStyle(sf::Text::Bold);
    score_text10.setFillColor(sf::Color(255,255,255));
    score_text10.setPosition(400,600);

    show_score();  
}

void High_Score_List::run()
{
    while( window.isOpen() )
    {
	process_events();
	render();
    }
}

void High_Score_List::process_events()
{
    sf::Event event;
    while (window.pollEvent(event))
    {
	switch(event.type)
	{
	case sf::Event::Closed:
	{
	    return;
	}
	case sf::Event::KeyPressed:
	    if (event.key.code == sf::Keyboard::Escape) 
	    {
		window.close();
	    } 
	case sf::Event::MouseButtonPressed:
	{
	    if (event.mouseButton.button == sf::Mouse::Left)
	    {
		if(sf::Mouse::getPosition(window).x > 0 && sf::Mouse::getPosition(window).x < 300 &&
		   sf::Mouse::getPosition(window).y > 0 && sf::Mouse::getPosition(window).y < 120)
		{
		    window.close();
		}
	    }
	    break;
	}
	default:
	    break;
	}
    }
}

void High_Score_List::render()
{
    window.clear();
    window.draw(background_sprite);
    window.draw(return_button.get_sprite());
    window.draw(score_text1);
    window.draw(score_text2);
    window.draw(score_text3);
    window.draw(score_text4);
    window.draw(score_text5);
    window.draw(score_text6);
    window.draw(score_text7);
    window.draw(score_text8);
    window.draw(score_text9);
    window.draw(score_text10);
    window.display();
}

// Sorted insertion of entry pointers to the entries vector
void High_Score_List::add_entry(unique_ptr<Entry> entry)
{
    ifstream infile;
    infile.open("resources/Highscorelist.txt");
    string name{};
    int score{};
    string date{};
    while(infile >> name)
    {
	infile >> score;
	infile >> date;
	entries.push_back(make_unique<Entry>(name, score, date));
    }
    if (entries.empty())
    {
	entries.push_back(move(entry));
    }
    else
    {
	bool inserted{false};
	for(unsigned i{}; i != entries.size(); i++)
	{
	    if(entries.at(i)->get_score() < entry->get_score())
	    {
		entries.insert(entries.begin() + i, move(entry));
		inserted = true;
		break;
	    }
	}
	if (!inserted)
	    entries.push_back(move(entry));
    }
    save_to_file();
}

// Retrieves text from Highscorelist.txt and displays it in the window
void High_Score_List::show_score()
{
    ifstream infile;
    string line1;
    string line2;
    string line3;
    string line4;
    string line5;
    string line6;
    string line7;
    string line8;
    string line9;
    string line10;
    infile.open("resources/Highscorelist.txt");
    getline(infile,line1);
    score_text1.setString(line1);
    getline(infile,line2);
    score_text2.setString(line2);
    getline(infile,line3);
    score_text3.setString(line3);
    getline(infile,line4);
    score_text4.setString(line4);
    getline(infile,line5);
    score_text5.setString(line5);
    getline(infile,line6);
    score_text6.setString(line6);
    getline(infile,line7);
    score_text7.setString(line7);
    getline(infile,line8);
    score_text8.setString(line8);
    getline(infile,line9);
    score_text9.setString(line9);
    getline(infile,line10);
    score_text10.setString(line10);
    infile.close();
}

// Writes the contents of the entries vector to the file Highscorelist.txt
void High_Score_List::save_to_file()
{
  ofstream outfile;
  outfile.open("resources/Highscorelist.txt", ios_base::trunc);
  for(unsigned i{} ; i != entries.size() ; i++)
    {
      string new_entry = entries.at(i)->to_string();
      outfile << new_entry << endl;
    }
    outfile.close();
}

