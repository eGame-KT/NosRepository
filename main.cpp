// ��ڲ԰�̈ړ����� //

// 2020.05.12
// Kuwata

#include "DxLib.h"
#include "main.h"



// �ϐ�
int gameCNT;		//�ްт������Ă��邩�m�F�p�̶���
int player1;		//���񓮂�����
int speed = 4;			//����


// �ް�ٰ��
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	// ----------�@���я���
	SetWindowText("1916015_Kuwata Masato");

	//���я���
	SetGraphMode(SCREEN_SIZE_X, SCREEN_SIZE_Y, 16); // 640*480�ޯ�65536�FӰ�ނɐݒ�
	ChangeWindowMode(true);							// true:window false:�ٽ�ذ�
	if (DxLib_Init() == -1) return -1;				//DXײ���؏���������
	SetDrawScreen(DX_SCREEN_BACK);					//�ЂƂ܂��ޯ��ޯ̧�ɕ`��

	gameCNT = 0;
	player1 = 0;

	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		ClsDrawScreen();	//��ʏ���

		gameCNT++;




		DrawFormatString(0, 0, 0xFFFFFF, "GameoverScene : %d", gameCNT);
		
		ScreenFlip();
	}
	DxLib_End(); // DxLib�̏I��

	return true;
	
}