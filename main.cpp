// ﾌﾟﾚｲﾔｰの移動処理 //

// 2020.05.12
// Kuwata

#include "DxLib.h"
#include "main.h"



// 変数
int gameCNT;		//ｹﾞｰﾑが動いているか確認用のｶｳﾝﾄ
int player1;		//今回動かす者
int speed = 4;			//速さ


// ｹﾞｰﾑﾙｰﾌﾟ
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	// ----------　ｼｽﾃﾑ処理
	SetWindowText("1916015_Kuwata Masato");

	//ｼｽﾃﾑ処理
	SetGraphMode(SCREEN_SIZE_X, SCREEN_SIZE_Y, 16); // 640*480ﾄﾞｯﾄ65536色ﾓｰﾄﾞに設定
	ChangeWindowMode(true);							// true:window false:ﾌﾙｽｸﾘｰﾝ
	if (DxLib_Init() == -1) return -1;				//DXﾗｲﾌﾞﾗﾘ初期化処理
	SetDrawScreen(DX_SCREEN_BACK);					//ひとまずﾊﾞｯｸﾊﾞｯﾌｧに描画

	gameCNT = 0;
	player1 = 0;

	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		ClsDrawScreen();	//画面消去

		gameCNT++;




		DrawFormatString(0, 0, 0xFFFFFF, "GameoverScene : %d", gameCNT);
		
		ScreenFlip();
	}
	DxLib_End(); // DxLibの終了

	return true;
	
}