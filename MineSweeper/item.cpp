#include "item.h"

// 构造函数
item::item(int x1,int y1)
{
	x = x1;
	y = y1;
}

item title(0, 0);			// 游戏标题图片
item author(250, 0);		// 游戏作者图片
item undig(500, 30);		// 未挖开的地块图片
item ready(600, 30);		// 准备挖开的地块图片（高亮显示）
item flag(700, 30);			// 标记的地块图片
item dig0(800, 30);			// 挖开的空地块图片
item dig1(900, 30);			// 挖开的1地块图片
item dig2(1000, 30);		// 挖开的2地块图片
item dig3(1100, 30);		// 挖开的3地块图片
item dig4(1200, 30);		// 挖开的4地块图片
item dig5(800, 100);		// 挖开的5地块图片
item dig6(900, 100);		// 挖开的6地块图片
item dig7(1000, 100);		// 挖开的7地块图片
item dig8(1100, 100);		// 挖开的8地块图片
item digX(1200, 100);		// 挖开的地雷地块图片