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
	recond("��ʼ��Ϸ...");
	system("CLS");
	total = 0;n = 0;b = false;
	while (cin >> n)
	{
		if (n == 0)
		{
			cout << "�������������1�����!";
			recond("�������������1�����");
			continue;
		}
		else if (n > GET)
		{
			cout << "�㲻�����߶���" << GET << "�����";
			recond("��������˶���" + to_string(GET) + "�����");
			continue;
		}
		else if (n >= MAX - total)
		{
			cout << "�㲻�����߶��ڵ�ǰʣ���" << MAX - total << "�����";
			recond("��������˶��ڵ�ǰʣ���" + to_string(MAX - total) + "�����");
			continue;
		}
		total += n;
		cout << "����������ж�:" << endl;
		cout << "��ǰ�ܹ�ȡ�˻����:" << total << " �ܹ��л��:" << MAX << " ��ʣ��" << MAX - total << endl;
		if (total == MAX - 1 || total == MAX)
		{
			cout << "�����ˣ�" << endl;
			recond("�������");
			++computer_win;
			break;
		}
		else if (total >= MAX - 1)
		{
			cout << "��������ˣ�" << endl;
			recond("���������");
			++player_win;
			break;
		}
		else
		{
			for (i = GET;i >= 1;i--)
			{
				if (total + i < MAX - 1)
				{
					cout << "���������" << i << "�����" << endl;
					recond("�����������" + to_string(i) + "�����");
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
				cout << "���������������׼������1�����" << endl;
				recond("�����������1�����");
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
	cout << "�����Ȩ��Ϣ:\n" << "Hatch Game\n" << \
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
	cout << "���Զ�����?����1�Զ��壬����0����Ĭ�ϴ���";
	cin >> n;
	if (n)
	{
		cout << "������ÿ������ö��ٸ����:";
		cin >> GET;
		recond("����Զ���ÿ�������" + to_string(GET) + "�����");
		cout << "�������ܹ��ж��ٸ����:";
		cin >> MAX;
		recond("����Զ���ÿ���ܹ���" + to_string(GET) + "�����");
	}
	cout << "��ǰ�����Ӯ��" << computer_win << "�֣����Ӯ��" << player_win << "�֡�";
	cout << "��Ϸ����:" << endl;
	cout << "1.�ܹ���" << MAX << "�����" << endl;
	cout << "2.ÿ���˿������ȡ��" << GET << "�����" << endl;
	cout << "�˻�����" << endl;
	cout << "������1����ʼ��Ϸ��0���˳���Ϸ:";
	cin >> n;
	if (n)
		play();
	cout << "������һ��������1����,����0�˳�:";
	cin >> n;
	if (n)
		goto main_func;
	return 0;
}