#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <windows.h>
#include <iostream>
#include <sstream>
#include<vector>
#define STAGE_WIDTH 880    //舞台宽度
#define STAGE_HEIGHT 600   //舞台高度
#define MAXLENGTH 100
#define INFO_WIDTH 400
#define POSX  150.0f
#define POSY  400.0f
#define ERROR 0
//枚举定义网格状态
typedef enum CARDSTATE {
	ncNULL,				//空地
	ncUNDOWN,		    //背景方块
	ncMINE,				//地雷
	ncONE,				//数字1
	ncTWO,				//数字2
	ncTHREE,			//数字3
	ncFOUR,				//数字4
	ncFIVE,				//数字5
	ncSIX,				//数字6
	ncSEVEN,			//数字7
	ncEIGHT,			//数字8
	ncFLAG,				//标记
	ncQ,				//问号
	ncX,				//备用
	ncBOMBING,			//爆炸的雷
	ncUNFOUND			//未检测出来的雷
};
using namespace sf;			//SFML中的每个类都位于该命名空间之下，不设定sf命名空间的话，相应的函数前需要用作用域解析符，例如 sf::VideoMode(width* GRIDSIZE, height* GRIDSIZE)
using namespace std;
class Player
{
private:
	string name;//玩家名称
	int count[15];//每种牌的数量
	int pai[20];//记录每张牌的编号
	int n;//玩家牌的数量
	bool isChoose[20];
public:
	int number;//玩家编号
	static int turn;//场上的牌是谁的
	friend class Game;
	Player();
	~Player();
	void sort();//排序
	void counting();//统计
	void checker();//发牌检测
};

class Game
{
public:
	sf::RenderWindow window;
	Game();
	~Game();
	Texture ipokers[54];
	Texture ipokersChoose[54];
	Texture card;
	Texture start;
	Texture chupai;
	Texture buchu;
	Texture background;
	Texture bc;
	Sprite spokers[54]; //精灵对象
	Sprite spokersChoose[54];
	Sprite scard;
	Sprite sstart;
	Sprite schupai;
	Sprite sbuchu;
	Sprite sbackground;
	Sprite sbc;
	int Window_width;
	int Window_height;
	Player player[3];
	int dipai[3];//底牌数组
	bool isStart; // 是否开始
	bool isOver;//是否结束
	int isTurn;//0为不是你的回合，1为是你的回合可以随意出牌，2为是你的回合但有限制
	int playernumber;//是谁的回合
	void Run();

	void Initial();
	void IniData();
	void LoadMediaData();
	void fapai();

	void Input();


	void Logic();
	void isWin();

	void Draw();
	void DrawGrid();
	void DrawButton();
	void DrawGameEnd();
	void Drawcard(float x, float y);
};
