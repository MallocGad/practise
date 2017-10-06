#pragma once
#include<iostream>
#include<string>
#include<Windows.h>
#include<ctime>
using namespace std;
class Monster;
class Player
{
public:
	int attack();
	void display();
	int getexp_up(int exp);
	int getbllod()
	{
		return blood;
	}
	void foolall()
	{
		blood = foolblood;
	}
protected:
	int defense;
	int phyattack;
	int spellattack;
	int blood;
	int foolblood;
	int crentexp;;
	int needexp;
	int grade;
	string name;
	string s_open1;
	string s_open2;
	string s_open3;
	string s_close = "£¨Î´½âËø£©";
	friend void hit(Player *player,Monster *monster);
};
class Monster
{
public:
	void foolall()
	{
		blood = foolblood;
	}
	int getblood()
	{
		return blood;
	}
	int retunrexp()
	{
		return expce;
	}
	friend void hit(Player *player,Monster *monster);
protected:
	int blood;
	int phydefense;
	int spelldefnese;
    int attacks;
	int expce;
	int foolblood;
};
class Master :public Player
{
public:
	Master();
};
class Warrior :public Player
{
public:
	Warrior();
};
class Shooter :public Player
{
public:
	Shooter();
};
class Little_monster :public Monster
{
public:
	Little_monster();
};
class Midium_monster :public Monster
{
public:
	Midium_monster();
};
class Big_monster :public Monster
{
public:
	Big_monster();
};
