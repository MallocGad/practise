#include"tool.h"
int Player::attack()
{
	int chose;
	cout << "��ѡ�񹥻���ʽ:" << endl;
	cout << "A:�չ�" << "      " << "Q:����һ";
	grade > 1 ? cout << s_open1 << endl : cout << s_close << endl;
	cout << "W:���ܶ�";
	grade > 2 ? cout << s_open2 : cout << s_close;
	cout << "  " << "E:������";
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
	cout << "�������ƣ�" << name << endl;
	cout << "�ȼ�:" << grade << endl;
	cout << "����ֵ:" << crentexp << "/" << needexp<<endl;
	cout << "Ѫ��:" << foolblood << endl;
	cout << "������:" << phyattack << endl;
	cout << "��������:" << spellattack << endl;
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
	name = "��ʦ";
	s_open1 = "����";
	s_open2 = "��������";
	s_open3 = "�°�����";
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
	name = "սʿ";
	s_open1 = "����";
	s_open2 = "����ǰ��";
	s_open3 = "������";
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
	name = "����";
	s_open1 = "Ǳ��";
	s_open2 = "����";
	s_open3 = "����֮��";
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
