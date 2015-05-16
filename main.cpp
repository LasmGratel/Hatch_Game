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
#include <iostream>
using namespace std;
typedef unsigned int uint;
uint GET = 32767;
uint MAX = 2147483647;
uint n, total = 0, i, player_win = 0, computer_win = 0;
bool b = false;
void play()
{
	total = 0;n = 0;
	while (cin >> n)
	{
		if (n == 0)
		{
			cout << "你必须拿走至少1根火柴!";
			continue;
		}
		else if (n > GET)
		{
			cout << "你不能拿走多于" << GET << "根火柴！";
			continue;
		}
		else if (n >= MAX - total)
		{
			cout << "你不能拿走多于当前剩余的" << MAX - total << "根火柴！";
			continue;
		}
		total += n;
		cout << "计算机正在判断:" << endl;
		cout << "当前总共取了火柴数:" << total << " 总共有火柴:" << MAX << " 还剩余" << MAX - total << endl;
		if (total == MAX - 1 || total == MAX)
		{
			cout << "您输了！" << endl;
			++computer_win;
			break;
		}
		else if (total >= MAX - GET + 1)
		{
			cout << "计算机输了！" << endl;
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
				cout << "计算机别无他法，准备拿走3根火柴。" << endl;
				total += 3;
			}
		}
	}
	return;
}
int main()
{
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
		cout << "请输入总共有多少根火柴:";
		cin >> MAX;
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
		play();
	return 0;
}