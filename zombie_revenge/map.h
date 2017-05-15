#pragma once
#include <SFML/Graphics.hpp>

const int HEIGHT_MAP = 12;//размер карты высота
const int WIDTH_MAP = 21;//размер карты ширина 


sf::String TileMap[HEIGHT_MAP] = {
	"                     ",
	"      s      s       ",
	"    s          ss    ",
	"      s s       s    ",
	"         s           ",
	"      s     s        ",
	"                     ",
	"====0===========0====",
	"                     ",
	"                     ",
    "                     ",
	"                     "
};

class map
{
	sf::Texture map_tex;
	sf::Sprite s_map;
public:	
	map(sf::String F)
	{
		sf::Image im;
		im.loadFromFile(F);
		map_tex.loadFromImage(im);
		s_map.setTexture(map_tex);
	}

	void Draw(sf::RenderWindow& win)
	{
		for (int i = 0; i < HEIGHT_MAP; i++)
		{
			for (int j = 0; j < WIDTH_MAP; j++)
			{
				if (TileMap[i][j] == ' ')
					s_map.setTextureRect(sf::IntRect(0, 0, 63, 63));
				if (TileMap[i][j] == 's')
					s_map.setTextureRect(sf::IntRect(64, 0, 129, 63));
				if (TileMap[i][j] == '0')
					s_map.setTextureRect(sf::IntRect(130, 0, 188, 63));
				if (TileMap[i][j] == '=')
					s_map.setTextureRect(sf::IntRect(190, 0, 253, 63));

				s_map.setPosition(j * 63, i * 63);

				win.draw(s_map);
			}
		}
	}
};
