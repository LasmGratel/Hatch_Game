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
	recond("Start Game...");
	system("CLS");
	total = 0;n = 0;b = false;
	while (cin >> n)
	{
		if (n == 0)
		{
			cout << "You must get at least one match!";
			recond("Player get least one match");
			continue;
		}
		else if (n > GET)
		{
			cout << "You can\'t get more than " << GET << " match!";
			recond("Player get more than " + to_string(GET) + " match");
			continue;
		}
		else if (n >= MAX - total)
		{
			cout << "You can\'t take more than the rest of the current " << MAX - total << " match!";
			recond("Player take more than the rest of the current " + to_string(MAX - total) + " match");
			continue;
		}
		total += n;
		cout << "Computer:" << endl;
		cout << "Total number of get matches:" << total << " Total number of matches:" << MAX << " Remaining " << MAX - total << endl;
		if (total == MAX - 1 || total == MAX)
		{
			cout << "You Lost!!!" << endl;
			recond("Player lost the game");
			++computer_win;
			break;
		}
		else if (total >= MAX - 1)
		{
			cout << "Computer Lost!!!" << endl;
			recond("Computer lost the game");
			++player_win;
			break;
		}
		else
		{
			for (i = GET;i >= 1;i--)
			{
				if (total + i < MAX - 1)
				{
					cout << "Computer get " << i << " match" << endl;
					recond("Computer get " + to_string(i) + " match");
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
				cout << "The computer could, ready to take the 1 match." << endl;
				recond("Computer get 1 match");
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
	cout << "Output Copyright Message:\n" << "Hatch Game\n" << \
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
	cout << "Did you wan\'t to customize?input 1 to customize,or 0 to continue without setting.";
	cin >> n;
	if (n)
	{
		cout << "Please input max get number:";
		cin >> GET;
		recond("Player customize max get number:" + to_string(GET));
		cout << "Please input total matches:";
		cin >> MAX;
		recond("Player customize total matches:" + to_string(GET));
	}
	cout << "Now Computer win " << computer_win << " round,Player win " << player_win << " round.";
	cout << "Game Rule:" << endl;
	cout << "1.There is " << MAX << " matches." << endl;
	cout << "2.You can only get max " << GET << "\'s matches." << endl;
	cout << "Player VS Computer" << endl;
	cout << "Input 1 to play the game,or 0 to exit:";
	cin >> n;
	if (n)
		play();
	cout << "Do you wan\'t to replay?Input 1 to replay,or 0 to exit:";
	cin >> n;
	if (n)
		goto main_func;
	return 0;
}