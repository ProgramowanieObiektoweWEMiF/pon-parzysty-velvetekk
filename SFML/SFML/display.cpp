#include "stdafx.h"
#include "display.h"
#include "AllienArray.h"
#include <memory>
#include <vector>

void Display::diplayshoots()
{
	for (int i = 0; i < int(bulvec.size()); i++)
	{
		window.draw(bulvec[i]->getref());
	}
}

Display::Display()
{
	texture.loadFromFile("grafiki/orzel7.png");
	image.setTexture(texture);
	bullet = 0;
}

void Display::shoot()
{
	sf::Vector2f vec = image.getPosition();
	vec.x += 25.0;
	vec.y -= 25.0;
	std::shared_ptr<strzal>ptr(new strzal(vec));
	bulvec.push_back(ptr);
	std::cout << "pozycja pocisku x = " << vec.x << " y = " << vec.y << std::endl;
}

void Display::shootupdate()
{
	for (int i = 0; i < bulvec.size(); i++)
	{
		int cnt = i;
		bulvec[i]->update();
		int y = bulvec[i]->getposy();
		if (y < 0)
		{
			std::vector<std::shared_ptr<strzal>>::iterator it;
			bulvec[i].reset();
			it = bulvec.begin();
			for (int i = 0; i < cnt; i++)
			{
				it++;
			}
			bulvec.erase(it);

			
		}
			
		
	}
}

void Display::collision()
{
	for (int i = 0; i < AArray.vecsize(); i++)
	{
		int cnt = i;
		for (int u = 0; u < bulvec.size(); u++)
		{
			sf::Sprite& ref = AArray.sref(cnt);
			sf::Sprite& ref2 = bulvec[u]->getref();
			sf::FloatRect R1 = ref.getGlobalBounds();
			sf::FloatRect R2 = ref2.getGlobalBounds();
			if (R1.intersects(R2))
			{
				AArray.KillAllien(cnt);
				DelMissle(u);
				std::cout << "HHHHHHHHHHHHHHHHHHHHHHIIIIIIIIIIIIIIIIIIIIIIIIIIIIITTTTTTTTTTTTTTTTTTTTTTTTTTT" << std::endl;
			}
		}
	}
}

void Display::DelMissle(int n)
{
	std::vector<std::shared_ptr<strzal>>::iterator it;
	bulvec[n].reset();
	it = bulvec.begin();
	for (int i = 0; i < n; i++)
	{
		it++;
	}
	bulvec.erase(it);
}

void Display::isOver()
{
	for (int i = 0; i < AArray.vecsize(); i++)
	{
		if (AArray.getPos(i).y >= 500)
			while (1);
	}
}



void Display::displayarray()
{
	for (int i = 0; i<AArray.vecsize(); i++)
	{

		window.draw(AArray.sref(i));
		std::cout << "narysowano kosmite " << i << std::endl;
		sf::Vector2f vec(AArray.sref(i).getPosition());
		float x = vec.x;
		float y = vec.y;
		std::cout << " x = " << x << " y = " << y << std::endl;
	}

}

Display & Display::GetDisplay()
{
	static Display obraz;
	return obraz;
}

void Display::print()
{
	image.setPosition(400, 550);
	stworzKosmite creator;
	AArray.fillarray();
	std::cout << AArray.vecsize() << std::endl;
	
	


	while (window.isOpen())
	{

		sf::Event events;

		

		while (window.pollEvent(events))
		{
			if (events.type == sf::Event::Closed)
			{
				window.close();
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			{
				if (image.getPosition() != llimit)
					image.move(-10, 0);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			{
				if (image.getPosition() != rlimit)
					image.move(10, 0);
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) window.close();


			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
			{

				shoot();
				bullet++;
			}
		}
		
		window.clear(sf::Color::Black);

		
		collision();
		diplayshoots();
		shootupdate();
		window.draw(image);
		displayarray();
		AArray.ArrayMove();
		window.display();
		isOver();
		
	}

}

