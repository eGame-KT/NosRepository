// ﾌｪｰﾄﾞｲﾝ、ﾌｪｰﾄﾞｱｳﾄ //

// 2020.05.20
// Kuwata
// Aキーでシーン切り替え
// 十字キーでplayer移動

#include "DxLib.h"
#include "player.h"
#include "effect.h"
#include "map.h"


// 変数
// ｼｽﾃﾑ関連
SCENE_ID sceneID;					// 現在のｼｰﾝ格納用
SCENE_ID preSceneID;				// 一つ前のｼｰﾝIDを格納用
int sceneCounter;					// ｼｰﾝ用
		


int playerImage;	//ﾌﾟﾚｲﾔｰ
XY playerPos;		//P1の座標(X,Y)

int speed;			//歩く速さ
int Cr;				//ｷｬﾗの色

/* WinMain */
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	//ｼｽﾃﾑの初期化
	if (!SystemInit())
	{
		return -1;
	}

	/* ｹﾞｰﾑﾙｰﾌﾟ */
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		ClsDrawScreen();	//画面消去

				//ｼｰﾝｶｳﾝﾀを制御
		if (sceneID != preSceneID)
		{
			preSceneID = sceneID;
			sceneCounter = 0;
		}

		//ｼｰﾝ
		switch (sceneID)
		{
		case SCENE_ID_INIT:
			InitScene();
			break;
			//ﾀｲﾄﾙｼｰﾝ
		case SCENE_ID_TITLE:
			//ﾌｪｰﾄﾞｲﾝ
			if (fadeIn)
			{
				if(!FadeInScreen(5)) {}		// ｴﾌｪｸﾄ終了後の処理
			}
			else if(fadeOut)
			{
				if (!FadeOutScreen(5))
				{
					// ｴﾌｪｸﾄ終了後の処理
					sceneID = SCENE_ID_GAME;		// しっかりとｼｰﾝが変わってから、ﾌｪｰﾄﾞｲﾝをtrueにする
					fadeIn = true;
				}
			}
			TitleScene();
			break;

		case SCENE_ID_GAME:
			//ﾌｪｰﾄﾞｲﾝ
			if (fadeIn)
			{
				if (!FadeInScreen(5)) {}		// ｴﾌｪｸﾄ終了後の処理
			}
			else if (fadeOut)
			{
				if (!FadeOutScreen(5))
				{
					// ｴﾌｪｸﾄ終了後の処理
					sceneID = SCENE_ID_INIT;		// しっかりとｼｰﾝが変わってから、ﾌｪｰﾄﾞｲﾝをtrueにする
					fadeIn = true;
				}
			}
			GameScene();			//移動処理
			break;


		default:
			break;
		}

		sceneCounter++;

	
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
	SetGraphMode(SCREEN_SIZE_X, SCREEN_SIZE_Y, 16);
	ChangeWindowMode(true);

	//DXﾗｲﾌﾞﾗﾘの初期化
	if (DxLib_Init() == -1)
	{
		return  false;
	}
	SetDrawScreen(DX_SCREEN_BACK);

	
	
	//変数の初期化
	Cr = GetColor(200, 0, 0);
	mapPos = { 0,0 };

	sceneCounter = 0;
	sceneID = SCENE_ID_INIT;
	preSceneID = SCENE_ID_MAX;
	fadeIn = true;

	return true;
}


/* ｼｰﾝ */

//初期化ｼｰﾝ
void InitScene(void)
{
	speed = 4;
	playerPos = { SCREEN_SIZE_X / 2 ,SCREEN_SIZE_Y / 2 };
	MapInit();

	sceneID = SCENE_ID_TITLE;
}

//ﾀｲﾄﾙｼｰﾝ
void TitleScene(void)
{
	//ｼｰﾝの切り替え
	if (CheckHitKey(KEY_INPUT_A))
	{
		fadeOut = true;
	}
	TitleDraw();
}

//ｹﾞｰﾑｼｰﾝ
void GameScene(void)
{
	//ｼｰﾝの切り替え
	if (CheckHitKey(KEY_INPUT_A))
	{
		fadeOut = true;
	}

	//左
	if (playerPos.x >= 0)
	{
		if (CheckHitKey(KEY_INPUT_LEFT))
		{
			playerPos.x -= speed;
		}
	}

	//右
	if (playerPos.x <= SCREEN_SIZE_X)
	{
		if (CheckHitKey(KEY_INPUT_RIGHT))
		{
			playerPos.x += speed;
		}
	}
	

	//上
	if (playerPos.y >= 0)
	{
		if (CheckHitKey(KEY_INPUT_UP))
		{
			playerPos.y -= speed;
		}
	}


	//下
	if (playerPos.y <= SCREEN_SIZE_Y)
	{
		if (CheckHitKey(KEY_INPUT_DOWN))
		{
			playerPos.y += speed;
		}
	}
	

	GameDraw();			//描画処理
}



//描画関連
void TitleDraw(void)
{
	//移動範囲の枠を描画
	DrawBox(100, 100, SCREEN_SIZE_X - 100, SCREEN_SIZE_Y - 100, 0xFF0000, true);
	DrawFormatString(0, 0, 0xFFFFFF, "TitleScene : %d", sceneCounter);
}

void GameDraw(void)
{
	DrawCircle(-mapPos.x + playerPos.x,  -mapPos.y + playerPos.y, P_SIZE / 2, Cr, true);
	DrawFormatString(0, 0, 0xFFFFFF, "GameScene : %d", sceneCounter);
}