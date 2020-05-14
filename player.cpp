// ﾌﾟﾚｲﾔｰの移動処理 & 移動制御 //

// 2020.05.12
// Kuwata

#include "DxLib.h"
#include "player.h"



// 変数
int gameCNT;		//ｹﾞｰﾑが動いているか確認用のｶｳﾝﾄ

int mapImage[272][352];		//ﾏｯﾌﾟ

int playerImage;	//ﾌﾟﾚｲﾔｰ
XY playerPos;		//P1の位置(X,Y)

int speed;		//歩く速さ
int Cr;				//ｷｬﾗの色

/* ｹﾞｰﾑﾙｰﾌﾟ */
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	//ｼｽﾃﾑの初期化
	if (!SystemInit())
	{
		return -1;
	}


	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		ClsDrawScreen();	//画面消去

		gameCNT++;

		MainControl();			//移動処理

		GameDraw();			//描画処理
		ScreenFlip();
	}
	DxLib_End(); // DxLibの終了

	return true;
}

/* 定義 */

//ｼｽﾃﾑ系の初期化
bool SystemInit(void)
{
	//ｼｽﾃﾑの初期化
	SetWindowText("1916015_Kuwata Masato");
	SetGraphMode(SCREEN_SIZE_X, SCREEN_SIZE_Y, MAP_CHIP_SIZE);
	ChangeWindowMode(true);

	//DXﾗｲﾌﾞﾗﾘの初期化
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


//移動関連
void MainControl(void)
{
	//左
	if (playerPos.x >= 0)
	{
		if (CheckHitKey(KEY_INPUT_A))
		{
			playerPos.x -= speed;
		}
	}
	

	//右
	if (CheckHitKey(KEY_INPUT_D))
	{
		playerPos.x += speed;
	}

	//上
	if (CheckHitKey(KEY_INPUT_W))
	{
		playerPos.y -= speed;
	}

	//下
	if (CheckHitKey(KEY_INPUT_S))
	{
		playerPos.y += speed;
	}
}


//描画関連
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