#include "stdafx.h"
#include "Wytworcza.h"
#include <iostream>


void Kosmita1::kill()
{
	delete this;
}

Kosmita1::Kosmita1()
{
	hp = 1;
	txt.loadFromFile("grafiki/kosmita1.png");
	sprt.setTexture(txt);
	std::cout << "powstal kosmita 1!!!" << std::endl;
}

void Kosmita1::setPos(float x, float y)
{
	sf::Vector2f vec(x, y);
	sprt.setPosition(vec);
}

sf::Sprite & Kosmita1::ref()
{
	sf::Sprite& ref = sprt;
	return ref;
}

void Kosmita1::ishit()
{
	hp--;
	if (hp == 0) kill();
}

void Kosmita1::updatepos(float x, float y)
{
	sprt.move(x, y);
}

const sf::Vector2f & Kosmita1::getpos()
{
	return sprt.getPosition();
}

void Kosmita2::kill()
{
	delete this;
}

Kosmita2::Kosmita2()
{
	hp = 2;
	txt.loadFromFile("grafiki/kosmita2.png");
	sprt.setTexture(txt);
	std::cout << "powstal kosmita 2!!!" << std::endl;

}

void Kosmita2::setPos(float x, float y)
{
	sprt.setPosition(x, y);
}

sf::Sprite & Kosmita2::ref()
{
	sf::Sprite& ref = sprt;
	return ref;
}

void Kosmita2::ishit()
{
	hp--;
	if (hp == 0) kill();
}

void Kosmita2::updatepos(float x, float y)
{
	sprt.move(x, y);
}

const sf::Vector2f & Kosmita2::getpos()
{
	return sprt.getPosition();
}

void stworzKosmite::reg(Kosmita *x)
{
	regvec.push_back(x);
}

Kosmita1 * stworzKosmite::stworzKosmite1()
{
	Kosmita1* ptr = new Kosmita1;
	reg(ptr);
	return ptr;
}

Kosmita2 * stworzKosmite::stworzKosmite2()
{
	Kosmita2* ptr = new Kosmita2;
	reg(ptr);
	return ptr;
}


