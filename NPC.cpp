#include "DxLib.h"


#define SCREEN_SIZE_X 800	//画面ｻｲｽﾞ横
#define SCREEN_SIZE_Y 600	//画面ｻｲｽﾞ縦

bool SystemInit(void);
void GameMain(void);


int NPCImage;
int NPCImage2[12];


// プログラムは WinMain から始まります
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{

	if (!SystemInit()) return -1;


	if (DxLib_Init() == -1)		// ＤＸライブラリ初期化処理
	{
		return -1;			// エラーが起きたら直ちに終了
	}

	while (ProcessMessage() == 0 && !CheckHitKey(KEY_INPUT_ESCAPE))
	{
		ClsDrawScreen();

		GameMain();


		//GameCounter++;
		ScreenFlip();
	}


	DxLib_End();				// ＤＸライブラリ使用の終了処理

	return 0;				// ソフトの終了 
}

bool SystemInit(void)
{
	// ｼｽﾃﾑ処理
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


