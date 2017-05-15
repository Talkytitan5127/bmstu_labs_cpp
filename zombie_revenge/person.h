#include <SFML/Graphics.hpp>
#include <sstream>
class Unit
{

	float x, y;
	int h, w;
	int health;
	bool life;

	sf::Texture texture;
	sf::Sprite sprite;
	sf::String File;

public:
	Unit(float X, float Y, int H, int W, sf::String F)
		:x(X), y(Y), h(H), w(W), File(F)
	{
		sf::Image im;
		im.loadFromFile(F);
		im.createMaskFromColor(sf::Color(255, 255, 255));
		texture.loadFromImage(im);
		sprite.setTexture(texture);
	}
	float GetX()
	{
		return x;
	}
	float GetY()
	{
		return y;
	}
	int GetW()
	{
		return w;
	}
	int GetH()
	{
		return h;
	}
	void ChangeX(float X)
	{
		x = X;
	}
	void ChangeY(float Y)
	{
		y = Y;
	}
	sf::Sprite GetSprite()
	{
		return sprite;
	}
	bool GetLife()
	{
		return life;
	}
	void ChangeLife(bool fl)
	{
		life = fl;
	}
	void ChangeHp()
	{
		health--;
	}
	void Set(int hp, bool l)
	{
		health = hp;
		life = l;
	}
	int GetHealth()
	{
		return health;
	}
	void SetSprite()
	{
		sprite.setPosition(x-GetW()/2, y-GetH()/2);
	}
	virtual void update(float time) = 0;
};

class Player : public Unit
{
	bool isShoot;
	bool isDead;
	int Score;

public:

	Player(float X, float Y, int H, int W, sf::String F)
		:Unit(X, Y, H, W, F)
	{
		Set(4, true);
		Score = 0;
		isShoot = false;
		isDead = false;
	}
	int GetScore()
	{
		return Score;
	}
	void ChangeScore(int b, bool fl)
	{
		if (fl)
			Score += b;
		else
			Score -= b;
	}
	bool Shot()
	{
		return isShoot;
	}

	void ChangeSHot(bool fl)
	{
		isShoot = fl;
	}
	void ChangeDead(bool fl)
	{
		isDead = fl;
	}
	bool GetDead()
	{
		return isDead;
	}

	void move(sf::RenderWindow& win)
	{
		sf::Vector2i Pixelpos = sf::Mouse::getPosition(win);
		sf::Vector2f pos = win.mapPixelToCoords(Pixelpos);
		ChangeX(pos.x);
		ChangeY(pos.y);
	}

	void update(float time)
	{
		if (GetY() > 500 && GetX() > 0 && GetX() < 1280 && GetY() < 720)
			SetSprite();
	
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			isShoot = true;
		}
	}
};

class Bullet : public Unit
{
	float speed;
public:

	Bullet(float X, float Y, int H, int W, sf::String F)
		:Unit(X, Y, H, W, F)
	{
		Set(1, true);
		speed = 5;
	}

	void update(float time)
	{
		ChangeY(GetY() - speed*time);
		if (GetY() < 0)
			ChangeLife(false);
		SetSprite();
		
	}
};


class Enemy : public Unit
{

	
	float speed;
	int bal;
	bool win;
	sf::String name;
public:

	Enemy(float X, float Y, int H, int W, sf::String F)
		:Unit(X, Y, H, W, F) {}
	int GetBal()
	{
		return bal;
	}
	bool GetWin()
	{
		return win;
	}
	void ChangeWin(bool fl)
	{
		win = fl;
	}
	void SetEn(int sp, int hp, bool l, int ba, sf::String nam, bool w)
	{
		speed = sp;
		Set(hp, l);
		bal = ba;
		name = nam;
		win = w;
	}
	float GetSp()
	{
		return speed;
	}
};

class Sim : public Enemy
{
public:
	Sim(float X, float Y, int H, int W, sf::String F)
		:Enemy(X, Y, H, W, F)
	{
		SetEn(1.4, 1, true, 50, "Sim", false);
	}
	void update(float time)
	{
		ChangeY(GetY() + GetSp() * time);
		if (GetY() > 720) 
		{
			ChangeLife(false);
			ChangeWin(true);
		}
		SetSprite();
	}
};

class Car : public Enemy
{
public:
	Car(float X, float Y, int H, int W, sf::String F)
		:Enemy(X, Y, H, W, F)
	{
		SetEn(1.3, 1, true, 150, "Car", false);
	}

	void update(float time)
	{
		ChangeX(GetX() + GetSp()*time);
		if (GetX() > 1280)
			ChangeLife(false);
		
		SetSprite();
	}
};

class Hel : public Enemy
{
public:
	Hel(float X, float Y, int H, int W, sf::String F)
		:Enemy(X, Y, H, W, F)
	{
		SetEn(1.9, 3, true, 100, "Hel", false);
	}
	void update(float time)
	{
		ChangeY(GetY() + GetSp()*time);
		
		if (GetY() > 720)
		{
			ChangeLife(false);
			ChangeWin(true);

		}
		SetSprite();
	}
};

class Cap
{

	sf::Font font;
	sf::Text text;
	int rou = 0;
	sf::Text die;
public:

	Cap(sf::String F, Player hero, int round)
	{
		rou = round;
		font.loadFromFile("ARIAL.TTF");
		text.setFont(font);
		text.setFillColor(sf::Color::Red);
		text.setCharacterSize(30);

		std::ostringstream playerHealthString;
		std::ostringstream PlRound;
		std::ostringstream Scor;
		playerHealthString << hero.GetHealth();
		PlRound << rou;
		Scor << hero.GetScore();

		text.setString("Health: " + playerHealthString.str() + '\t' + "Score: " + Scor.str() + '\t' + "Round: " + PlRound.str());
		text.setPosition(4, 20);
	}
	void Draw(sf::RenderWindow& win)
	{
		win.draw(text);
	}
	void Die(sf::RenderWindow& win)
	{
		die.setFont(font);
		die.setFillColor(sf::Color::Red);
		die.setCharacterSize(60);
		die.setString("YOU DIED");
		die.setPosition(500, 400);
		win.draw(die);
	}

};
