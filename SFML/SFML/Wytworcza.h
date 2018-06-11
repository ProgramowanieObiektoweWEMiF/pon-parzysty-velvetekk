#pragma once

#include "stdafx.h"

#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>

class Kosmita
{
private:
		virtual void kill()=0;
public:
	virtual void setPos(float,float) = 0;
	virtual void ishit()=0;
	virtual sf::Sprite& ref() = 0;
	virtual ~Kosmita() {};
	virtual void updatepos(float, float)=0;
	virtual const sf::Vector2f& getpos()=0;
};

class Kosmita1 :public Kosmita
{
private:
	int hp;
	sf::Sprite sprt;
	sf::Texture txt;
	virtual void kill();
public:
	Kosmita1();
	virtual void setPos(float, float);
	virtual sf::Sprite& ref()override;
	virtual void ishit()override;
	void updatepos(float , float )override;
	const sf::Vector2f& getpos();
	
};

class Kosmita2 :public Kosmita
{
private:
	int hp;
	sf::Sprite sprt;
	sf::Texture txt;
	virtual void kill();
public:
	Kosmita2();
	virtual void setPos(float, float);
	virtual sf::Sprite& ref()override;
	virtual void ishit()override;
	void updatepos(float, float)override;
	const sf::Vector2f& getpos();
};

class stworzKosmite
{
private:
	std::vector<Kosmita*>regvec;
	void reg(Kosmita*);
public:
	Kosmita1* stworzKosmite1();
	Kosmita2* stworzKosmite2();
	
};