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


#define P_SIZE			32			//��ڲ԰�̑傫��(X,Y)��test��16�~16

/* �񋓌^ */

//��݊Ǘ��p
enum SCENE_ID {
	  SCENE_ID_INIT				//�ްя��������
	, SCENE_ID_TITLE			//���ټ��
	, SCENE_ID_GAME				//�ްѼ��
	, SCENE_ID_GAMEOVER			//�ްѵ��ް���
	, SCENE_ID_MAX
};


/* �\���� */

//���W
struct XY
{
	int x;					// X���W
	int y;					// Y���W
};


/* �������ߐ錾 */

// ���ьn�̏�����
bool SystemInit(void);			

// �ړ��֘A
void InitScene(void);
void TitleScene(void);
void GameScene(void);			

// �`��֘A
void TitleDraw(void);
void GameDraw(void);	

extern XY playerPos;
