// ��ͷ�ļ�

// ͷ�ļ�
#pragma once
#include <graphics.h>				// easyX��ͼ����
#include <time.h>					// ����ʱ�䣬���ڼ�ʱ�������������
#include <stdlib.h>					// ���������
#include <stdio.h>					// �����ļ��������
#include "item.h"					// ��itemͷ�ļ�
#include "button.h"					// ��buttonͷ�ļ�
#include "mode.h"					// ��modeͷ�ļ�
#include "block.h"					// ��blockͷ�ļ�

// ��
#define LENTH 1600					// ���ڳ���
#define WIDTH 900					// ���ڿ��
#define MIDX LENTH/2				// �����е������
#define MIDY WIDTH/2				// �����е�������
#define ROUNDRATE 30				// ��ťԲ���Ļ���
#define STRLEN 200					// �ַ�������

// ��������
void load();						// ��ȡ�ļ���Ϣ
void initImage();					// Ԥ����ͼƬ�����崰��
void initGame();					// ��Ϸ��ʼ��
void EndGame();						// ��Ϸ������β����
void paint();						// ������Ϸ����
int inGame();						// ��Ϸ�ڲ����Լ���ת
int welcome();						// ���Ƴ�ʼ�����Լ���ת
int Set();							// �������ý����Լ���ת
int Help();							// ���ư��������Լ���ת
int Diff();							// �����ѶȽ����Լ���ת
int Stats();						// ����ͳ�ƽ����Լ���ת
int Reset();						// ѯ���Ƿ�����ͳ������
int Quit();							// ѯ���Ƿ��˳���Ϸ
int End();							// ѯ���Ƿ������Ϸ�����س�ʼ����
int Restart();						// ѯ���Ƿ�ʼ�µ���Ϸ
int Win();							// ��Ϸʤ��ʱ����
int Fail();							// ��Ϸʧ��ʱ����

// ȫ�ֱ���
extern int game;					// �����Ϸ״̬��0��������1����ת��-1���˳�
extern int Ox;						// �ؿ�����ԭ�������
extern int Oy;						// �ؿ�����ԭ��������
extern int safe;					// ��ȫ�ڿ��ؿ���
extern int danger;					// δ��ǵ�����
extern int win1, win2, win3;		// �������м����߼�ʤ������
extern int lose1, lose2, lose3;		// �������м����߼�ʧ�ܾ���

extern clock_t Tstart, Tnow, Tpass;		// ��¼��ʼ����ǰʱ�䣬���Դ˼��㾭��ʱ��
extern clock_t Tbest1, Tbest2, Tbest3;	// �������м����߼�����¼

extern IMAGE img1;					// ���崰��

extern ExMessage m;					// ��¼�����Ϣ�Ľṹ��

extern Mode mode;					// ģʽ�������������ȡ���ȡ�������

extern item title;					// ��Ϸ����ͼƬ
extern item author;					// ��Ϸ����ͼƬ
extern item undig;					// δ�ڿ��ĵؿ�ͼƬ
extern item ready;					// ׼���ڿ��ĵؿ�ͼƬ��������ʾ��
extern item flag;					// ��ǵĵؿ�ͼƬ
extern item dig0;					// �ڿ��Ŀյؿ�ͼƬ
extern item dig1;					// �ڿ���1�ؿ�ͼƬ
extern item dig2;					// �ڿ���2�ؿ�ͼƬ
extern item dig3;					// �ڿ���3�ؿ�ͼƬ
extern item dig4;					// �ڿ���4�ؿ�ͼƬ
extern item dig5;					// �ڿ���5�ؿ�ͼƬ
extern item dig6;					// �ڿ���6�ؿ�ͼƬ
extern item dig7;					// �ڿ���7�ؿ�ͼƬ
extern item dig8;					// �ڿ���8�ؿ�ͼƬ
extern item digX;					// �ڿ��ĵ��׵ؿ�ͼƬ

extern block** map;					// ���еؿ�

extern button start;				// ��ʼ��ť
extern button set;					// ���ð�ť
extern button help;					// ������ť
extern button quit;					// �˳���ť
extern button back;					// ���ذ�ť
extern button diff;					// �ѶȰ�ť
extern button stats;				// ͳ�ư�ť
extern button reset;				// ���ð�ť
extern button easy;					// ������ť
extern button mid;					// �м���ť
extern button hard;					// �߼���ť
extern button custom;				// �Զ��尴ť