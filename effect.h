//#pragma once

/* ----- �������ߐ錾 ----- */

void EffectInit(void);					// �̪�Ă̏�����
bool FadeInScreen(int fadeStep);		// ̪��޲ݗp
bool FadeOutScreen(int fadeStep);		// ̪��ޱ�ėp


/* ----- ��۰��ى� ----- */

// ��ʐִ̪ؑ��
extern bool fadeIn;						// ̪��޲ݗp
extern bool fadeOut;					// ̪��ޱ�ėp
extern int fadeCnt;						// ��ʐִ̪ؑ�ėp����
