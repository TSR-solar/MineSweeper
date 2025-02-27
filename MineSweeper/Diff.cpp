#include "minesweeper.h"

// 绘制难度界面以及跳转
int Diff()
{
	
	FILE* fp1 = fopen("diff.txt", "w");		// 打开文件以保存数据
	cleardevice();							// 清屏

	// 重新绘制标题、作者
	putimage(650, 100, 250, 200, &img1, title.x, title.y);
	putimage(1100, 250, 200, 200, &img1, author.x, author.y);

	// 绘制返回、初级、中级、高级按钮
	back.print();
	easy.print();
	mid.print();
	hard.print();
	custom.print();

	// 循环等待跳转操作
	while (1)
	{

		// 绘制当前难度
		TCHAR s1[STRLEN] = { 0 }, s2[STRLEN] = { 0 }, s3[STRLEN] = { 0 };
		_stprintf(s1, _T("当前长度：%2d"), mode.len);
		_stprintf(s2, _T("当前宽度：%2d"), mode.wid);
		_stprintf(s3, _T("当前地雷数：%2d"), mode.mine);

		outtextxy(300, 400, s1);
		outtextxy(600, 400, s2);
		outtextxy(900, 400, s3);

		// 读取鼠标信息
		m = getmessage(EX_MOUSE);

		// 如果按返回，则保存并返回设置界面
		if (back.check() == 1)
		{
			fprintf(fp1, "%d %d %d", mode.len, mode.wid, mode.mine);
			fclose(fp1);
			return -1;
		}
		// 如果按难度按钮，则设置相应难度
		else if (easy.check() == 1)
		{
			mode.set(1);
		}
		else if (mid.check() == 1)
		{
			mode.set(2);
		}
		else if (hard.check() == 1)
		{
			mode.set(3);
		}
		else if (custom.check() == 1)
		{
			mode.set(4);
		}
	}
}