//#pragma once

//���ޯ��ү���ޗp��`
#ifdef _DEBUG
#define AST() {\
	CHAR ast_msg[256];\
	wsprintf(ast_msg, "%s %d�s��\0", __FILE__, __LINE__);\
	MessageBox(0, ast_msg, "�A�T�[�g�\��", MB_OK);\
	}
#else
#define AST()
#endif


// �萔
#define SCREEN_SIZE_X	800			//��ذ݂�X���W
#define SCREEN_SIZE_Y	600			//��ذ݂�Y���W

#define MAP_CHIP_SIZE	16			//���߂̑傫��
#define MAP_X			22			//���߂̐�
#define MAP_Y			17

//���W
struct XY
{
	int x;					// X���W
	int y;					// Y���W
};

/* ----- �������ߐ錾 ----- */

bool SystemInit(void);			// ���ьn�̏�����

XY MainControl(void);		// �ړ��֘A

void GameDraw(void);			// �`��֘A
