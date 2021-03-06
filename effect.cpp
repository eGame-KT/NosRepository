#include "DxLib.h"
#include "effect.h"


// 画面切替ｴﾌｪｸﾄ
bool fadeIn;					//ﾌｪｰﾄﾞｲﾝ用
bool fadeOut;					//ﾌｪｰﾄﾞｱｳﾄ用
int fadeCnt;					//画面切替ｴﾌｪｸﾄ用ｶｳﾝﾀ


// ｴﾌｪｸﾄの初期化
void EffectInit(void)
{
	fadeIn = false;
	fadeOut = false;
	fadeCnt = 0;
}


// ﾌｪｰﾄﾞｲﾝ
bool FadeInScreen(int fadeStep)
{
	fadeCnt += fadeStep;
	if (fadeCnt <= 255)
	{
		SetDrawBright(fadeCnt, fadeCnt, fadeCnt);
		return true;
	}
	else
	{
		SetDrawBright(255, 255, 255);
		fadeCnt = 0;
		fadeIn = false;
		return false;
	}
}


// ﾌｪｰﾄﾞｱｳﾄ
bool FadeOutScreen(int fadeStep)
{
	fadeCnt += fadeStep;
	if (fadeCnt <= 255)
	{
		SetDrawBright(255 - fadeCnt, 255 - fadeCnt, 255 - fadeCnt);
		return true;
	}
	else
	{
		SetDrawBright(0, 0, 0);
		fadeCnt = 0;
		fadeOut = false;
		return false;
	}
}

