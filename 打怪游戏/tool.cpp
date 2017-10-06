#include"tool.h"
int Player::attack()
{
	int chose;
	cout << "请选择攻击方式:" << endl;
	cout << "A:普攻" << "      " << "Q:技能一";
	grade > 1 ? cout << s_open1 << endl : cout << s_close << endl;
	cout << "W:技能二";
	grade > 2 ? cout << s_open2 : cout << s_close;
	cout << "  " << "E:技能三";
	grade > 4 ? cout << s_open3 << endl : cout << s_close << endl;
	cin >> chose;
	switch (chose)
	{
	case 'A':
	case 'a':
		return phyattack; break;
	case 'q':
	case 'Q':
		return phyattack + spellattack; break;
	case 'W':
	case 'w':
		return phyattack + spellattack + 5; break;
	case 'e':
	case 'E':
		return phyattack + spellattack + 10; break;
	default:
		return phyattack; break;
	}
}
void hit(Player *player, Monster *monster)
{
	int hurt, truehurt;
	hurt = player->attack();
	if (typeid(*player) == typeid(Master))
		truehurt = hurt - monster->spelldefnese;
	else
		truehurt = hurt - monster->phydefense;
	if (truehurt <= 0) truehurt = 1;
	monster->blood -= truehurt;
	if (monster->getblood() > 0)
	{
		hurt = monster->attacks;
		truehurt = monster->attacks - player->defense;
		player->blood -= truehurt;
	}
}
int Player::getexp_up(int exp)
{
	crentexp += exp;
	if (crentexp > needexp&&grade<=20)
	{
		grade++;
		crentexp -= needexp;
		needexp *= 1.5;
		defense = defense*0.6 + grade;
		phyattack = phyattack*0.6 + grade;
		spellattack = spellattack*0.6 + grade;
		foolblood = foolblood*0.6 + grade;
		blood = foolblood;
	}
	return 0;
}
void gotoxy(int x, int y)
{
	HANDLE hout;
	COORD coor;
	hout=GetStdHandle(STD_OUTPUT_HANDLE);
	coor.X = x;
	coor.Y = y;
	SetConsoleCursorPosition(hout, coor);
}
void Player::display()
{
	system("cls");
	cout << "人物名称：" << name << endl;
	cout << "等级:" << grade << endl;
	cout << "经验值:" << crentexp << "/" << needexp<<endl;
	cout << "血量:" << foolblood << endl;
	cout << "物理攻击:" << phyattack << endl;
	cout << "法术攻击:" << spellattack << endl;
}
Master::Master()
{
	defense=5;
	phyattack = 5;
	spellattack = 10;
	blood = 5;
	foolblood = 5;
	grade = 0;
	crentexp = 0;
	needexp = 10;
	name = "法师";
	s_open1 = "凤舞";
	s_open2 = "荆棘花开";
	s_open3 = "月伴离人";
}
Warrior::Warrior()
{
	defense = 10;
	phyattack = 5;
	spellattack = 5;
	blood = 10;
	foolblood = 10;
	grade = 0;
	crentexp = 0;
	needexp = 10;
	name = "战士";
	s_open1 = "鞭笞";
	s_open2 = "负重前行";
	s_open3 = "不死心";
}
Shooter::Shooter()
{
	defense = 5;
	phyattack = 15;
	spellattack = 5;
	blood = 5;
	foolblood = 5;
	grade = 0;
	crentexp = 0;
	needexp = 10;
	name = "射手";
	s_open1 = "潜行";
	s_open2 = "利眼";
	s_open3 = "以身之力";
}
Little_monster::Little_monster()
{
	blood = 5;
	phydefense = 2;
	spelldefnese = 2;
	attacks = 2;
	expce = 10;
	foolblood = 5;
}
Midium_monster::Midium_monster()
{
	blood = 20;
	phydefense = 20;
	spelldefnese = 20;
	attacks = 20;
	expce = 30;
	foolblood = 20;
}
Big_monster::Big_monster()
{
	blood = 40;
	phydefense = 35;
	spelldefnese = 35;
	attacks = 30;
	expce = 40;
	foolblood = 30;
}
