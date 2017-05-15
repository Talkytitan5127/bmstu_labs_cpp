#include "map.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include "person.h"
#include <vector>
#include <vld.h>

using namespace sf;

int main()
{
	RenderWindow window(VideoMode(1280, 720), "chicken revenge");
	map Map("images/map.png");
	Player heroes(600, 600, 110, 80, "images/player_back.png");
	Clock clock;

	std::vector<Unit*> MasBul;
	std::vector<Enemy*> MasEn;

	heroes.SetSprite();

	int k = 0;
	int sh = 0;
	int round = 1;
	int c1 = 10;
	int c2 = 3;
	int c3 = 3;

	while (window.isOpen())
	{
		
		float time = clock.getElapsedTime().asMicroseconds();
		clock.restart();
		
		k++;
		sh--;
		time = time / 5000;
		
		Cap tex("ARIAL.TTF", heroes, round);
		
		if (k % 700 == 0 && c2 > 0)
		{
			MasEn.push_back(new Car(0, rand() % 220 + 500, 48, 82, "images/tank.png"));
			c2--;
		}

		if (k % 1000 == 500 && c3 > 0)
		{
			MasEn.push_back(new Hel(rand() % 1280, 0, 110, 80, "images/hel.png"));
			c3--;
		}

		if (k % 200 == 30 && c1 > 0)
		{
			MasEn.push_back(new Sim(rand() % 1280, 0, 110, 80, "images/zombie.png"));
			c1--;
		}
		
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed || heroes.GetHealth() == 0)
			{
				for (auto it = MasEn.begin(); it != MasEn.end(); it++)
				{
					delete (*it);
				}
				for (auto it = MasBul.begin(); it != MasBul.end(); it++)
				{
					delete (*it);
				}
				MasEn.clear();
				MasBul.clear();
				window.close();
			}
			if (heroes.Shot() && sh < 0)
			{
				heroes.ChangeSHot(false);
				MasBul.push_back(new Bullet(heroes.GetX(), heroes.GetY(), 16, 16, "images/bullet.png"));
				sh = 10;
			}
		}

		for (auto it = MasBul.begin(); it != MasBul.end();)
		{
			(*it)->update(time);
			for (auto ca = MasEn.begin(); ca != MasEn.end(); ca++)
			{
				if ((*it)->GetSprite().getGlobalBounds().intersects((*ca)->GetSprite().getGlobalBounds()) == true)
				{
					(*it)->ChangeLife(false);
					(*ca)->ChangeHp();
					if ((*ca)->GetHealth() == 0)
					{
						(*ca)->ChangeLife(false);
						heroes.ChangeScore((*ca)->GetBal(), true);
					}
				}
			}
			if ((*it)->GetLife() == false)
			{
				delete *it;
				it = MasBul.erase(it);
			}
			else
			{
				it++;
			}
		}
		for (auto it = MasEn.begin(); it != MasEn.end();)
		{
			(*it)->update(time);

			if ((*it)->GetSprite().getGlobalBounds().intersects(heroes.GetSprite().getGlobalBounds()) == true)
			{
				heroes.ChangeDead(true);
			}

			if ((*it)->GetLife() == false)
			{
				if ((*it)->GetWin() == true)
				{
					heroes.ChangeScore((*it)->GetBal(), false);
				}
				delete *it;
				it = MasEn.erase(it);
			}
			else
			{
				it++;
			}
		}
		
		if (heroes.GetDead())
		{
			std::cout << "you died\n";
			heroes.ChangeHp();
			heroes.ChangeDead(false);
			heroes.ChangeX(600);
			heroes.ChangeY(600);
			heroes.update(time);
			for (auto it = MasEn.begin(); it != MasEn.end(); it++)
			{
				delete (*it);
			}
			for (auto it = MasBul.begin(); it != MasBul.end(); it++)
			{
				delete (*it);
			}
			MasEn.clear();
			MasBul.clear();
			c1 = 12;
			c2 = 3;
			c3 = 3;
			k = 0;
			sh = 0;
		}
		else if (c1 == 0 && c2 == 0 && c3 == 0)
		{
			std::cout << "Good luck\n";
			c1 += rand() % 6;
			c2 += rand() % 2;
			c3 += rand() % 2;
			round++;
			k = 0;
			sh = 0;
			continue;
		}

		heroes.move(window);
		heroes.update(time);

		window.clear();

		Map.Draw(window);
		
		for (auto it = MasBul.begin(); it != MasBul.end(); it++)
			window.draw((*it)->GetSprite());
		for (auto it = MasEn.begin(); it != MasEn.end(); it++)
			window.draw((*it)->GetSprite());
		
		tex.Draw(window);
		if (c1 == 12 && c2 == 3 && c3 == 3)
			tex.Die(window);
		sf::Sprite sp = heroes.GetSprite();
		window.draw(heroes.GetSprite());

		window.display();

	}

	return 0;
}
