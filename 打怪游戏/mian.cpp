#include"tool.h"
int main()
{
	Monster *monster;
	Player *player;
	Master master;
	Shooter shooter;
	Warrior warrior;
	Little_monster little;
	Midium_monster midium;
	Big_monster big;
	cout << "��ӭ���������Ϸ:" << endl;
	cout << "============================��\n";
	int chose1,chose2;
	while (1)
	{
		cout << "��ѡ��ؿ�: 1.�� 2.һ�� 3.����" << endl;
		
		while (1)
		{
			(cin >> chose1).get();
		    system("cls");
			switch (chose1)
			{
			case 1:
				monster = &little; break;
			case 2:
				monster = &midium; break;
			case 3:
				monster = &big; break;
			default:
				cout << "�����������������룡" << endl; continue;
				break;
			}
			break;
		}
		while (1)
		{
			system("cls");
			cout << "==========================\n";
			cout << "����ǰ������Ӣ��:(��ѡ��)" << endl;
			cout << "1.��ʦ 2.սʿ 3.����" << endl;
			while (1)
			{
				(cin >> chose2).get();
				switch (chose2)
				{
				case 1:
					player = &master; break;
				case 2:
					player = &warrior; break;
				case 3:
					player = &shooter; break;
				default:
					cout << "����������������\n"; continue;
					break;
				}
				break;
			}
			player->display();
			cout << "�Ƿ�ѡ���Ӣ�۳�ս(Z����,Y����)" << endl;
			if ('z' != cin.get())
				break;
			cin.get();
		}
		while (1)
		{
			hit(player, monster);
			if (player->getbllod() <= 0)
				cout << "Ӣ������:" << endl;
			else if (monster->getblood() <= 0)
				cout << "��Ϸʤ��";
			else
				continue;
			player->getexp_up(monster->retunrexp());
			break;
		}
		cout << "�����밴'y',������˳�" << endl;
		char ch;
		ch=cin.get();
		cin.get();
		if (ch != 'y')
			break;
	}
	return 0;
}