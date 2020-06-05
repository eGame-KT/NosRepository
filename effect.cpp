#include "DxLib.h"
#include "effect.h"


// ‰æ–ÊØ‘Ö´Ìª¸Ä
bool fadeIn;					//Ìª°ÄŞ²İ—p
bool fadeOut;					//Ìª°ÄŞ±³Ä—p
int fadeCnt;					//‰æ–ÊØ‘Ö´Ìª¸Ä—p¶³İÀ


// ´Ìª¸Ä‚Ì‰Šú‰»
void EffectInit(void)
{
	fadeIn = false;
	fadeOut = false;
	fadeCnt = 0;
}


// Ìª°ÄŞ²İ
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


// Ìª°ÄŞ±³Ä
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

