#pragma once
#include <graphics.h>
#define STRLEN 200

// ���Ե�İ�ť
class button
{
public:
	int left;			// ��ť�������
	int top;			// ��ť��������
	int right;			// ��ť�Ҳ�����
	int bottom;			// ��ť�ײ�����
	TCHAR str[STRLEN];	// ��ť�ڲ�����

	int check();		// ��ⰴť�Ƿ񱻰���
	void print();		// ���ư�ť

	button(int x1, int y1, int x2, int y2, const TCHAR* s);	// ���캯��
};

