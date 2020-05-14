//#pragma once

//ﾃﾞﾊﾞｯｸﾞﾒｯｾｰｼﾞ用定義
#ifdef _DEBUG
#define AST() {\
	CHAR ast_msg[256];\
	wsprintf(ast_msg, "%s %d行目\0", __FILE__, __LINE__);\
	MessageBox(0, ast_msg, "アサート表示", MB_OK);\
	}
#else
#define AST()
#endif


// 定数
#define SCREEN_SIZE_X	800			//ｽｸﾘｰﾝのX座標
#define SCREEN_SIZE_Y	600			//ｽｸﾘｰﾝのY座標

#define MAP_CHIP_SIZE	16			//ﾁｯﾌﾟの大きさ
#define MAP_X			22			//ﾁｯﾌﾟの数
#define MAP_Y			17

//座標
struct XY
{
	int x;					// X座標
	int y;					// Y座標
};

/* ----- ﾌﾟﾛﾄﾀｲﾌﾟ宣言 ----- */

bool SystemInit(void);			// ｼｽﾃﾑ系の初期化

void MainControl(void);		// 移動関連

void GameDraw(void);			// 描画関連
