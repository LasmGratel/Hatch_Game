/*
	Hatch Game
	Copyright (C) 2015 Lasm_Gratel.

	This program is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.

	This program is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#include "headers.h"
uint GET = 32767;
uint MAX = 2147483647;
uint n, total = 0, i, player_win = 0, computer_win = 0, t = 0;
bool b = false;
string recond_str[100000];
void recond(string x)
{
	recond_str[t++] = x;
}
void recond_func()
{
	system("cls");
	for (uint i = 0;i < t;i++) cout << recond_str[i] << endl;
	system("pause");
	system("cls");
	return;
}
void play()
{
	recond(" ");
	recond("开始游戏...");
	system("CLS");
	total = 0;n = 0;b = false;
	while (cin >> n)
	{
		if (n == 0)
		{
			cout << "你必须拿走至少1根火柴!";
			recond("玩家拿走了少于1根火柴");
			continue;
		}
		else if (n > GET)
		{
			cout << "你不能拿走多于" << GET << "根火柴！";
			recond("玩家拿走了多于" + to_string(GET) + "根火柴");
			continue;
		}
		else if (n >= MAX - total)
		{
			cout << "你不能拿走多于当前剩余的" << MAX - total << "根火柴！";
			recond("玩家拿走了多于当前剩余的" + to_string(MAX - total) + "根火柴");
			continue;
		}
		total += n;
		cout << "计算机正在判断:" << endl;
		cout << "当前总共取了火柴数:" << total << " 总共有火柴:" << MAX << " 还剩余" << MAX - total << endl;
		if (total == MAX - 1 || total == MAX)
		{
			cout << "您输了！" << endl;
			recond("玩家输了");
			++computer_win;
			break;
		}
		else if (total >= MAX - 1)
		{
			cout << "计算机输了！" << endl;
			recond("计算机输了");
			++player_win;
			break;
		}
		else
		{
			for (i = GET;i >= 1;i--)
			{
				if (total + i < MAX - 1)
				{
					cout << "计算机拿走" << i << "根火柴" << endl;
					recond("计算机拿走了" + to_string(i) + "根火柴");
					total += i;
					break;
				}
				else
				{
					b = true;
				}
			}
			if (b)
			{
				cout << "计算机别无他法，准备拿走1根火柴。" << endl;
				recond("计算机拿走了1根火柴");
				total += 1;
			}
		}
	}
	recond_func();
}
int main()
{
main_func:
	system("cls");
	cout << "输出版权信息:\n" << "Hatch Game\n" << \
		"Copyright(C) 2015 Lasm_Gratel.\n" << \
		'\n' << \
		"This program is free software : you can redistribute it and / or modify\n" << \
		"it under the terms of the GNU General Public License as published by\n" << \
		"the Free Software Foundation, either version 3 of the License, or\n" << \
		"(at your option) any later version.\n" << \
		'\n' << \
		"This program is distributed in the hope that it will be useful,\n" << \
		"but WITHOUT ANY WARRANTY; without even the implied warranty of\n" << \
		"MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.See the\n" << \
		"GNU General Public License for more details.\n" << \
		'\n' << \
		"You should have received a copy of the GNU General Public License\n" << \
		"along with this program.If not, see <http://www.gnu.org/licenses/>.\n";
	cout << "想自定义吗?输入1自定义，输入0按照默认处理。";
	cin >> n;
	if (n)
	{
		cout << "请输入每次最多拿多少根火柴:";
		cin >> GET;
		recond("玩家自定义每次最多拿" + to_string(GET) + "根火柴");
		cout << "请输入总共有多少根火柴:";
		cin >> MAX;
		recond("玩家自定义每次总共有" + to_string(GET) + "根火柴");
	}
	cout << "当前计算机赢了" << computer_win << "局，玩家赢了" << player_win << "局。";
	cout << "游戏规则:" << endl;
	cout << "1.总共有" << MAX << "个火柴" << endl;
	cout << "2.每个人可以最多取走" << GET << "个火柴。" << endl;
	cout << "人机对弈" << endl;
	cout << "请输入1来开始游戏，0来退出游戏:";
	cin >> n;
	if (n)
		play();
	cout << "想重来一遍吗？输入1重来,输入0退出:";
	cin >> n;
	if (n)
		goto main_func;
	return 0;
}