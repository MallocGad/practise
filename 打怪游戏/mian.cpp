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
	cout << "欢迎来到打怪游戏:" << endl;
	cout << "============================、\n";
	int chose1,chose2;
	while (1)
	{
		cout << "请选择关卡: 1.简单 2.一般 3.困难" << endl;
		
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
				cout << "输入有误请重新输入！" << endl; continue;
				break;
			}
			break;
		}
		while (1)
		{
			system("cls");
			cout << "==========================\n";
			cout << "您当前有三个英雄:(请选择)" << endl;
			cout << "1.法师 2.战士 3.射手" << endl;
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
					cout << "输入有误重新输入\n"; continue;
					break;
				}
				break;
			}
			player->display();
			cout << "是否选择该英雄出战(Z返回,Y继续)" << endl;
			if ('z' != cin.get())
				break;
			cin.get();
		}
		while (1)
		{
			hit(player, monster);
			if (player->getbllod() <= 0)
				cout << "英雄死亡:" << endl;
			else if (monster->getblood() <= 0)
				cout << "游戏胜利";
			else
				continue;
			player->getexp_up(monster->retunrexp());
			break;
		}
		cout << "继续请按'y',任意键退出" << endl;
		char ch;
		ch=cin.get();
		cin.get();
		if (ch != 'y')
			break;
	}
	return 0;
}