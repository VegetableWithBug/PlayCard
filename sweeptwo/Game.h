#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <windows.h>
#include <iostream>
#include <sstream>
#include<vector>
#define STAGE_WIDTH 880    //��̨���
#define STAGE_HEIGHT 600   //��̨�߶�
#define MAXLENGTH 100
#define INFO_WIDTH 400
#define POSX  150.0f
#define POSY  400.0f
#define ERROR 0
//ö�ٶ�������״̬
typedef enum CARDSTATE {
	ncNULL,				//�յ�
	ncUNDOWN,		    //��������
	ncMINE,				//����
	ncONE,				//����1
	ncTWO,				//����2
	ncTHREE,			//����3
	ncFOUR,				//����4
	ncFIVE,				//����5
	ncSIX,				//����6
	ncSEVEN,			//����7
	ncEIGHT,			//����8
	ncFLAG,				//���
	ncQ,				//�ʺ�
	ncX,				//����
	ncBOMBING,			//��ը����
	ncUNFOUND			//δ����������
};
using namespace sf;			//SFML�е�ÿ���඼λ�ڸ������ռ�֮�£����趨sf�����ռ�Ļ�����Ӧ�ĺ���ǰ��Ҫ������������������� sf::VideoMode(width* GRIDSIZE, height* GRIDSIZE)
using namespace std;
class Player
{
private:
	string name;//�������
	int count[15];//ÿ���Ƶ�����
	int pai[20];//��¼ÿ���Ƶı��
	int n;//����Ƶ�����
	bool isChoose[20];
public:
	int number;//��ұ��
	static int turn;//���ϵ�����˭��
	friend class Game;
	Player();
	~Player();
	void sort();//����
	void counting();//ͳ��
	void checker();//���Ƽ��
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
	Sprite spokers[54]; //�������
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
	int dipai[3];//��������
	bool isStart; // �Ƿ�ʼ
	bool isOver;//�Ƿ����
	int isTurn;//0Ϊ������Ļغϣ�1Ϊ����ĻغϿ���������ƣ�2Ϊ����Ļغϵ�������
	int playernumber;//��˭�Ļغ�
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
