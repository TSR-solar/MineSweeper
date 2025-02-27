#pragma once
#include <graphics.h>

// 扫雷时的地块
class block
{
public:

	int dig=0;		// 0是没被挖，1是被挖，2是旗无法被挖，3是准备挖
	int mine=0;		// 0是没有，1是有雷
	char type=0;	// 0是空格，1~8是数字，X是雷

	void typeset(int i, int j);		// 设置地块的type
	void chain(int i, int j);		// 连锁挖开地块
	int check(int i,int j);			// 检测鼠标操作（左键、右键、双击）
};

