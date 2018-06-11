#pragma once
#include "stdafx.h"

#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>



class strzal
{
private:
	sf::Vector2f currpos;
	sf::Sprite sprt;
	sf::Texture tex;
	static int cnt;
	void zniszcz();
	
public:
	sf::Sprite& getref();
	strzal(const sf::Vector2f& x) ;
	void update();
	float getposx();
	float getposy();
	~strzal() { std::cout << "usuniety pocisk" << std::endl; cnt--; };
	
};

