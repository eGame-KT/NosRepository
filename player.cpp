// ̪��޲݁A̪��ޱ�� //

// 2020.05.20
// Kuwata
// A�L�[�ŃV�[���؂�ւ�
// �\���L�[��player�ړ�

#include "DxLib.h"
#include "player.h"
#include "effect.h"
#include "map.h"


// �ϐ�
// ���ъ֘A
SCENE_ID sceneID;					// ���݂̼�݊i�[�p
SCENE_ID preSceneID;				// ��O�̼��ID���i�[�p
int sceneCounter;					// ��ݗp
		


int playerImage;	//��ڲ԰
XY playerPos;		//P1�̍��W(X,Y)

int speed;			//��������
int Cr;				//��ׂ̐F

/* WinMain */
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	//���т̏�����
	if (!SystemInit())
	{
		return -1;
	}

	/* �ް�ٰ�� */
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		ClsDrawScreen();	//��ʏ���

				//��ݶ����𐧌�
		if (sceneID != preSceneID)
		{
			preSceneID = sceneID;
			sceneCounter = 0;
		}

		//���
		switch (sceneID)
		{
		case SCENE_ID_INIT:
			InitScene();
			break;
			//���ټ��
		case SCENE_ID_TITLE:
			//̪��޲�
			if (fadeIn)
			{
				if(!FadeInScreen(5)) {}		// �̪�ďI����̏���
			}
			else if(fadeOut)
			{
				if (!FadeOutScreen(5))
				{
					// �̪�ďI����̏���
					sceneID = SCENE_ID_GAME;		// ��������Ƽ�݂��ς���Ă���A̪��޲݂�true�ɂ���
					fadeIn = true;
				}
			}
			TitleScene();
			break;

		case SCENE_ID_GAME:
			//̪��޲�
			if (fadeIn)
			{
				if (!FadeInScreen(5)) {}		// �̪�ďI����̏���
			}
			else if (fadeOut)
			{
				if (!FadeOutScreen(5))
				{
					// �̪�ďI����̏���
					sceneID = SCENE_ID_INIT;		// ��������Ƽ�݂��ς���Ă���A̪��޲݂�true�ɂ���
					fadeIn = true;
				}
			}
			GameScene();			//�ړ�����
			break;


		default:
			break;
		}

		sceneCounter++;

	
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

	
	
	//�ϐ��̏�����
	Cr = GetColor(200, 0, 0);
	mapPos = { 0,0 };

	sceneCounter = 0;
	sceneID = SCENE_ID_INIT;
	preSceneID = SCENE_ID_MAX;
	fadeIn = true;

	return true;
}


/* ��� */

//���������
void InitScene(void)
{
	speed = 4;
	playerPos = { SCREEN_SIZE_X / 2 ,SCREEN_SIZE_Y / 2 };
	MapInit();

	sceneID = SCENE_ID_TITLE;
}

//���ټ��
void TitleScene(void)
{
	//��݂̐؂�ւ�
	if (CheckHitKey(KEY_INPUT_A))
	{
		fadeOut = true;
	}
	TitleDraw();
}

//�ްѼ��
void GameScene(void)
{
	//��݂̐؂�ւ�
	if (CheckHitKey(KEY_INPUT_A))
	{
		fadeOut = true;
	}

	//��
	if (playerPos.x >= 0)
	{
		if (CheckHitKey(KEY_INPUT_LEFT))
		{
			playerPos.x -= speed;
		}
	}

	//�E
	if (playerPos.x <= SCREEN_SIZE_X)
	{
		if (CheckHitKey(KEY_INPUT_RIGHT))
		{
			playerPos.x += speed;
		}
	}
	

	//��
	if (playerPos.y >= 0)
	{
		if (CheckHitKey(KEY_INPUT_UP))
		{
			playerPos.y -= speed;
		}
	}


	//��
	if (playerPos.y <= SCREEN_SIZE_Y)
	{
		if (CheckHitKey(KEY_INPUT_DOWN))
		{
			playerPos.y += speed;
		}
	}
	

	GameDraw();			//�`�揈��
}



//�`��֘A
void TitleDraw(void)
{
	//�ړ��͈̘͂g��`��
	DrawBox(100, 100, SCREEN_SIZE_X - 100, SCREEN_SIZE_Y - 100, 0xFF0000, true);
	DrawFormatString(0, 0, 0xFFFFFF, "TitleScene : %d", sceneCounter);
}

void GameDraw(void)
{
	DrawCircle(-mapPos.x + playerPos.x,  -mapPos.y + playerPos.y, P_SIZE / 2, Cr, true);
	DrawFormatString(0, 0, 0xFFFFFF, "GameScene : %d", sceneCounter);
}