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




/* ----- ﾌﾟﾛﾄﾀｲﾌﾟ宣言 ----- */

