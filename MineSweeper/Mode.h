#pragma once

// 模式参数，包括长度、宽度、地雷数
class Mode
{
public:
	int len = 9;				// 长度
	int wid = 9;				// 宽度
	int mine = 10;				// 地雷数

	void set(int diff);		// 设置难度
};