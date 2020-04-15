#include "Game.h"

Player::Player()//构造函数
{
	n = 0;
	for (int i = 0; i < 20; i++)
	{
		isChoose[i] = 0;
	}
	for (int i = 0; i < 15; ++i)
	{
		count[i] = 0;
	}
}
Player::~Player()
{

}

void Player::sort()
{
	int tra;
	int tag;
	for (int i = 0; i < n-1; ++i)
	{
		tag = i;
		tra = pai[i];
		for (int j =i+1; j < n; ++j)
		{
			if (pai[j] < tra)
			{
				tra = pai[j];
				tag = j;
			}
		}
		pai[tag] = pai[i];
		pai[i] = tra;
	}
}
void Player::counting()
{
	for (int i = 0; i < n; ++i)
	{
		int h;
		int j = pai[i];
		if (j == 52)
			count[13]++;
		else if (j == 53)
			count[14]++;
		else
		{
			h = j / 4;
			count[h]++;
		}
	}
}

void Player::checker()
{
	cout << "玩家:" << name << "的牌有:" << endl;
	for (int i = 0; i <= 7; i++)
	{
		cout << dec << count[i] << "个" << i + 3 << ",";
	}
	cout << dec << count[8] << "个" << "J" << ",";
	cout << dec << count[9] << "个" << "Q" << ",";
	cout << dec << count[10] << "个" << "K" << ",";
	cout << dec << count[11] << "个" << "A" << ",";
	cout << dec << count[12] << "个" << "2" << ",";
	cout << dec << count[13] << "个" << "小王" << ",";
	cout << dec << count[14] << "个" << "大王" << ",";
	cout << endl;
}