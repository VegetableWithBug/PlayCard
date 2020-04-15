#include "Game.h"



Game::Game()
{
	Window_width = STAGE_WIDTH;
	Window_height = STAGE_HEIGHT;
	window.create(sf::VideoMode(Window_width, Window_height), L"斗地主");
}


Game::~Game()
{
}

void Game::Initial()
{
	window.setFramerateLimit(60);	//每秒设置目标帧数
	isStart = false;
	isOver = false;
	IniData();//初始化数据
	LoadMediaData();//加载素材
	Draw();
}
void Game::LoadMediaData()
{
	if (!card.loadFromFile("images/card/ccard.png")) //加载纹理图片
	{
		cout << "card.png没有找到" << endl;
	}
	if (!start.loadFromFile("images/dizhu.png"))
	{
		cout << "dizhu.png没有找到" << endl;
	}
	if (!chupai.loadFromFile("images/ok.png"))
	{
		cout << "ok.png没有找到" << endl;
	}
	if (!buchu.loadFromFile("images/no.png"))
	{
		cout << "no.png没有找到" << endl;
	}
	if (!background.loadFromFile("images/background2.png"))
	{
		cout << "background.png没有找到" << endl;
	}
	if (!bc.loadFromFile("images/buchu.png"))
	{
		cout << "buchu.png没有找到" << endl;
	}
	for (int i = 0; i < 54; i++)
	{
		char ss[30] = "images/card/card";
		char ssc[30] = "images/cardchoose/card";
		char sss[5] = ".png";
		sprintf_s(ss, "%s%d%s", ss, i, sss);
		sprintf_s(ssc, "%s%d%s", ssc, i, sss);
		if (!ipokers[i].loadFromFile(ss)) //加载纹理图片
		{
			cout << dec << ss << "没有找到" << endl;
		}
		if (!ipokersChoose[i].loadFromFile(ssc)) //加载纹理图片
		{
			cout << dec << ssc << "没有找到" << endl;
		}
	}
	for (int i = 0; i < 54; i++)
	{
		spokers[i].setTexture(ipokers[i]);
		spokersChoose[i].setTexture(ipokersChoose[i]);
	}
	scard.setTexture(card);
	sstart.setTexture(start);
	schupai.setTexture(chupai);
	sbuchu.setTexture(buchu);
	sbackground.setTexture(background);
	sbc.setTexture(bc);
}
void Game::IniData()
{
	srand(time(NULL));
	int *p = new int[54];
	int tran;
	for (int i = 0; i < 54; ++i)
	{
		p[i] = i;
	}
	for (int j = 53; j >= 0; --j)
	{
		int a = rand() % 54;
		tran = p[a];
		p[a] = p[j];
		p[j] = tran;
	}
	for (int i = 0; i < 17; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			player[j].pai[i] = p[i * 3 + j];
			player[j].n++;
		}
	}
	for (int i = 0; i < 3; i++)
	{
		dipai[i] = p[51 + i];
	}
	for (int i = 0; i < 3; ++i)
	{
		player[i].counting();
		player[i].sort();
	}
}
void Game::Input()
{
	sf::Event event;//event types 包括Window、Keyboard、Mouse、Joystick，4类消息
					//通过  bool Window :: pollEvent（sf :: Event＆event） 从窗口顺序询问（ polled ）事件。 
					//如果有一个事件等待处理，该函数将返回true，并且事件变量将填充（filled）事件数据。 
					//如果不是，则该函数返回false。 同样重要的是要注意，一次可能有多个事件; 因此我们必须确保捕获每个可能的事件。 
	

}

void Game::Logic()
{
	isWin();
}

void Game::isWin()
{
	
}

void Game::Draw()
{
	window.clear();
	sbackground.setPosition(0.0f, 0.0f);
	window.draw(sbackground);
	for (int i = 0; i < 3; i++)
	{
		scard.setPosition(POSX + 100.0f + 130.0f*i, 10.0f);
		window.draw(scard);
	}
	//sstart.setPosition(350.0f, 350.0f);
	//window.draw(sstart);
	Drawcard(POSX, POSY);
	window.display();
}

void Game::DrawGrid()
{
	
}
void Game::DrawButton()
{

}
void Game::Run()
{
	do {

		Initial();

		while (window.isOpen() && isOver == false)
		{
			Input();

			Logic();

			Draw();
		}
	} while (!isOver);
	
}
void Game::Drawcard(float x, float y)
{
	for (int i = 0; i <player[0].n; i++)
	{
		if (player[0].isChoose[i] == 0)
		{
			spokers[player[0].pai[i]].setPosition(x, y);
			window.draw(spokers[player[0].pai[i]]);
		}
		else
		{
			spokersChoose[player[0].pai[i]].setPosition(x, y);
			window.draw(spokersChoose[player[0].pai[i]]);
		}
		x += 25.0f;
	}
}

