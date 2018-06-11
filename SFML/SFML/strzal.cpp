#include "stdafx.h"
#include "strzal.h"

void strzal::zniszcz()
{
	delete this;
}

sf::Sprite & strzal::getref()
{
	sf::Sprite& ref = sprt;
	return ref;
}

strzal::strzal(const sf::Vector2f & x)
{
	cnt++;
	tex.loadFromFile("grafiki/pocisk.png");
	sprt.setTexture(tex);
	sprt.setPosition(x);

}

void strzal::update()
{
	
	sprt.move(0, -5);
	currpos = sprt.getPosition();
}

float strzal::getposx()
{
	return currpos.x;
}

float strzal::getposy()
{
	return currpos.y;
}



int strzal::cnt = 0;