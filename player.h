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


#define P_SIZE			32			//ﾌﾟﾚｲﾔｰの大きさ(X,Y)←test時16×16

/* 列挙型 */

//ｼｰﾝ管理用
enum SCENE_ID {
	  SCENE_ID_INIT				//ｹﾞｰﾑ初期化ｼｰﾝ
	, SCENE_ID_TITLE			//ﾀｲﾄﾙｼｰﾝ
	, SCENE_ID_GAME				//ｹﾞｰﾑｼｰﾝ
	, SCENE_ID_GAMEOVER			//ｹﾞｰﾑｵｰﾊﾞｰｼｰﾝ
	, SCENE_ID_MAX
};


/* 構造体 */

//座標
struct XY
{
	int x;					// X座標
	int y;					// Y座標
};


/* ﾌﾟﾛﾄﾀｲﾌﾟ宣言 */

// ｼｽﾃﾑ系の初期化
bool SystemInit(void);			

// 移動関連
void InitScene(void);
void TitleScene(void);
void GameScene(void);			

// 描画関連
void TitleDraw(void);
void GameDraw(void);	

extern XY playerPos;
