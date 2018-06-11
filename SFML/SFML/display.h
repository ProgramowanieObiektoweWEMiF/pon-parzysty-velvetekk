#pragma once

#include "stdafx.h"

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include "Wytworcza.h"
#include "AllienArray.h"
#include "strzal.h"



class Display
{
private:
	
	sf::Vector2f rlimit{750,550};
	sf::Vector2f llimit{0,550};
	sf::RenderWindow window{ { 800,600, 64 }, "Giera" };
	sf::Texture texture;
	std::vector<std::shared_ptr<strzal>> bulvec;
	sf::Sprite image;
	AlienArray AArray;
	void diplayshoots();
	Display();
	int bullet;
	void shoot();
	void shootupdate();
	void collision();
	void DelMissle(int);
	void isOver();
	public:
	
	void displayarray();
	static Display& GetDisplay();

	void print();
};