// ��ڲ԰�̈ړ����� & �ړ����� //

// 2020.05.12
// Kuwata

#include "DxLib.h"
#include "player.h"



// �ϐ�
int gameCNT;		//�ްт������Ă��邩�m�F�p�̶���

XY mapPos;			//ϯ�߂�offset

int playerImage;	//��ڲ԰
XY playerPos;		//P1�̍��W(X,Y)

int speed;			//��������
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
	SetGraphMode(SCREEN_SIZE_X, SCREEN_SIZE_Y, 16);
	ChangeWindowMode(true);

	//DXײ���؂̏�����
	if (DxLib_Init() == -1)
	{
		return  false;
	}
	SetDrawScreen(DX_SCREEN_BACK);

	

	Cr = GetColor(200, 0, 0);
	gameCNT = 0;
	speed = 4;
	playerPos = { SCREEN_SIZE_X / 2 ,SCREEN_SIZE_Y / 2 };
	mapPos = { 0,0 };

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
	if (playerPos.x <= SCREEN_SIZE_X)
	{
		if (CheckHitKey(KEY_INPUT_D))
		{
			playerPos.x += speed;
		}
	}
	

	//��
	if (playerPos.y >= 0)
	{
		if (CheckHitKey(KEY_INPUT_W))
		{
			playerPos.y -= speed;
		}
	}


	//��
	if (playerPos.y <= SCREEN_SIZE_Y)
	{
		if (CheckHitKey(KEY_INPUT_S))
		{
			playerPos.y += speed;
		}
	}
	


}


//�`��֘A
void GameDraw(void)
{
	DrawCircle(-mapPos.x + playerPos.x,  -mapPos.y + playerPos.y, P_SIZE / 2, Cr, true);
	DrawFormatString(0, 0, 0xFFFFFF, "gameCNT : %d", gameCNT);
}