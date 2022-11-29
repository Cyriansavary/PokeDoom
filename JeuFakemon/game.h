#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "entity.h"

class game
{
private:
	int pos;
	bool pressed, theselect;

	sf::RenderWindow window;
	sf::RectangleShape* winclose;
	sf::Font* font;
	sf::Texture* image;
	sf::Sprite* bg;

	sf::Vector2i pos_mouse;
	sf::Vector2f mouse_coord;

	std::vector<const char*> options;
	std::vector<sf::Vector2f> coords;
	std::vector<sf::Text> texts;
	std::vector<std::size_t> sizes;




public: 
	game(void);


	bool windowIsOpen();
	void windowGame();
	
	void clear();
	void display();
	void set_values();
	int loop_events();
	void draw_all();
	int run_menu();

	void drawEntity(const entity&);

};

