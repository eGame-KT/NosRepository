// ��ڲ԰�̈ړ����� & �ړ����� //

// 2020.05.12
// Kuwata

#include "DxLib.h"
#include "player.h"



// �ϐ�
int gameCNT;		//�ްт������Ă��邩�m�F�p�̶���

int mapImage[272][352];		//ϯ��

int playerImage;	//��ڲ԰
XY playerPos;		//P1�̈ʒu(X,Y)

int speed;		//��������
int Cr;				//��ׂ̐F

/* �ް�ٰ�� */
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	//���т̏�����
	if (!SystemInit())
	{
		return -1;
	}


	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		ClsDrawScreen();	//��ʏ���

		gameCNT++;

		MainControl();			//�ړ�����

		GameDraw();			//�`�揈��
		ScreenFlip();
	}
	DxLib_End(); // DxLib�̏I��

	return true;
}

/* ��` */

//���ьn�̏�����
bool SystemInit(void)
{
	//���т̏�����
	SetWindowText("1916015_Kuwata Masato");
	SetGraphMode(SCREEN_SIZE_X, SCREEN_SIZE_Y, MAP_CHIP_SIZE);
	ChangeWindowMode(true);

	//DXײ���؂̏�����
	if (DxLib_Init() == -1)
	{
		return  false;
	}
	SetDrawScreen(DX_SCREEN_BACK);
	//for (int y = 0; y < MAP_Y; y++)
	//{
	//	for (int x = 0; x < MAP_X; x++)
	//	{
	//		LoadDivGraph("Nos_image/park01.png", 39, MAP_X, MAP_Y, MAP_CHIP_SIZE, MAP_CHIP_SIZE, mapImage[0]);
	//	}

	//}
	

	Cr = GetColor(200, 0, 0);
	gameCNT = 0;
	speed = 4;
	playerPos = { SCREEN_SIZE_X / 2 ,SCREEN_SIZE_Y / 2 };

	return true;
}


//�ړ��֘A
void MainControl(void)
{
	//��
	if (playerPos.x >= 0)
	{
		if (CheckHitKey(KEY_INPUT_A))
		{
			playerPos.x -= speed;
		}
	}
	

	//�E
	if (CheckHitKey(KEY_INPUT_D))
	{
		playerPos.x += speed;
	}

	//��
	if (CheckHitKey(KEY_INPUT_W))
	{
		playerPos.y -= speed;
	}

	//��
	if (CheckHitKey(KEY_INPUT_S))
	{
		playerPos.y += speed;
	}
}


//�`��֘A
void GameDraw(void)
{
	//for (int y = 0; y < MAP_Y; y++)
	//{
	//	for (int x = 0; x < MAP_X; x++)
	//	{
	//		DrawGraph(0, 0, mapImage[y][x], true);
	//	}
	//}
	DrawCircle(playerPos.x,  playerPos.y, 16, Cr, true);
	DrawFormatString(0, 0, 0xFFFFFF, "gameCNT : %d", gameCNT);
}