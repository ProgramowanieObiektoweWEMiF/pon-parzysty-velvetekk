#include "stdafx.h"
#include "AllienArray.h"
#include <memory>
#include <iostream>



sf::Sprite& AlienArray::sref(int n)const
{
	if (n < 30)
	{
		return ptrvec[n]->ref();
	}
}

void AlienArray::dodaj1()
{
	std::shared_ptr<Kosmita1>ptr(fac.stworzKosmite1());
	ptrvec.push_back(ptr);

}

void AlienArray::dodaj2()
{
	std::shared_ptr<Kosmita2>ptr(fac.stworzKosmite2());
	ptrvec.push_back(ptr);
}

void AlienArray::fillarray()
{
	for (int i = 0; i < 30; i++)
	{
		int v = rand() % 100;
		if (v % 2 == 1)
			dodaj1();
		else
			dodaj2();
		
	}
	for (int i = 0; i < (vecsize()/10); i++)
	{
		int dzies = i * 10;
		for (int u = 0; u < (vecsize() / 3); u++)
		{
			int jedn = u;
			int razem = dzies + jedn;
			float x = float(lxmargines + (u*ssize) + 10);
			float y = float(uymargines * (i + 1) + 10);
			ptrvec[razem]->setPos(x, y);
			
		}
	}
	
	
		
	

}

int AlienArray::vecsize()const
{
	return int(ptrvec.size());
}

sf::Vector2f AlienArray::getPos(int i) const
{
	return ptrvec[i]->getpos();
}

void AlienArray::ArrayMove()
{
	if (right == 1)
	{
		for (int i = 0; i < vecsize(); i++)
		{
			ptrvec[i]->updatepos(5 ,0);
			sf::Vector2f vec = ptrvec[i]->getpos();
			if (vec.x >= 770)
			{
				right = 0;
				ymove = 1;
			}
				
		}
	}
	else if (right == 0)
	{
		for (int i = 0; i < vecsize(); i++)
		{
			ptrvec[i]->updatepos(-5, 0);
			sf::Vector2f vec = ptrvec[i]->getpos();
			if (vec.x <= 0)
			{
				right = 1;
				ymove = 1;
			}
				
		}
		if (ymove == 1)
		{
			for (int i = 0; i < vecsize(); i++)
			{
				ptrvec[i]->updatepos(0, 30);
				ymove = 0;
			}
		}
	}
}

void AlienArray::KillAllien(int x)
{
	std::vector<std::shared_ptr<Kosmita>>::iterator it;
	ptrvec[x].reset();
	it = ptrvec.begin();
	for (int i = 0; i < x; i++)
	{
		it++;
	}
	ptrvec.erase(it);
}


