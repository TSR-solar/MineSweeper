#pragma once
#include <graphics.h>
#define STRLEN 200

// 可以点的按钮
class button
{
public:
	int left;			// 按钮左侧坐标
	int top;			// 按钮顶部坐标
	int right;			// 按钮右侧坐标
	int bottom;			// 按钮底部坐标
	TCHAR str[STRLEN];	// 按钮内部文字

	int check();		// 检测按钮是否被按下
	void print();		// 绘制按钮

	button(int x1, int y1, int x2, int y2, const TCHAR* s);	// 构造函数
};

