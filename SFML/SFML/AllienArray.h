#pragma once
#include "stdafx.h"

#include <SFML/Graphics.hpp>
#include <vector>
#include "Wytworcza.h"


class AlienArray
{
private:
	const int lxmargines= 55;
	const int uymargines = 50;
	const int ssize = 50;
	int right, ymove;
	stworzKosmite fac;
	std::vector<std::shared_ptr<Kosmita>>ptrvec;
public:
	AlienArray():right(1), ymove(0) {};
	sf::Sprite& sref(int n)const;
	void dodaj1();
	void dodaj2();
	void fillarray();
	int vecsize()const;
	sf::Vector2f getPos(int)const;
	void ArrayMove();
	void KillAllien(int);
	
};