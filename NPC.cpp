#include "DxLib.h"


#define SCREEN_SIZE_X 800	//��ʻ��މ�
#define SCREEN_SIZE_Y 600	//��ʻ��ޏc

bool SystemInit(void);
void GameMain(void);


int NPCImage;
int NPCImage2[12];


// �v���O������ WinMain ����n�܂�܂�
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{

	if (!SystemInit()) return -1;


	if (DxLib_Init() == -1)		// �c�w���C�u��������������
	{
		return -1;			// �G���[���N�����璼���ɏI��
	}

	while (ProcessMessage() == 0 && !CheckHitKey(KEY_INPUT_ESCAPE))
	{
		ClsDrawScreen();

		GameMain();


		//GameCounter++;
		ScreenFlip();
	}


	DxLib_End();				// �c�w���C�u�����g�p�̏I������

	return 0;				// �\�t�g�̏I�� 
}

bool SystemInit(void)
{
	// ���я���
	//SetWindowText;
	SetGraphMode(SCREEN_SIZE_X, SCREEN_SIZE_Y, 16);
	ChangeWindowMode(true);
	if (DxLib_Init() == -1)
	{
		return false;
	}
	SetDrawScreen(DX_SCREEN_BACK);

	NPCImage = LoadGraph("image/sinyuu.png");
	if(LoadDivGraph("image/sinyuu.png", 12, 3, 4, 20, 28, NPCImage2));
	

	return true;
}

void GameMain(void)
{
	DrawGraph(0, 0, NPCImage2[1], true);
}


