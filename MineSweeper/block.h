#pragma once
#include <graphics.h>

// ɨ��ʱ�ĵؿ�
class block
{
public:

	int dig=0;		// 0��û���ڣ�1�Ǳ��ڣ�2�����޷����ڣ�3��׼����
	int mine=0;		// 0��û�У�1������
	char type=0;	// 0�ǿո�1~8�����֣�X����

	void typeset(int i, int j);		// ���õؿ��type
	void chain(int i, int j);		// �����ڿ��ؿ�
	int check(int i,int j);			// �����������������Ҽ���˫����
};

