// 总头文件

// 头文件
#pragma once
#include <graphics.h>				// easyX绘图函数
#include <time.h>					// 设置时间，用于计时器和随机数生成
#include <stdlib.h>					// 随机数生成
#include <stdio.h>					// 用于文件输入输出
#include "item.h"					// 类item头文件
#include "button.h"					// 类button头文件
#include "mode.h"					// 类mode头文件
#include "block.h"					// 类block头文件

// 宏
#define LENTH 1600					// 窗口长度
#define WIDTH 900					// 窗口宽度
#define MIDX LENTH/2				// 窗口中点横坐标
#define MIDY WIDTH/2				// 窗口中点纵坐标
#define ROUNDRATE 30				// 按钮圆弧的弧度
#define STRLEN 200					// 字符串长度

// 函数声明
void load();						// 读取文件信息
void initImage();					// 预绘制图片到缓冲窗口
void initGame();					// 游戏初始化
void EndGame();						// 游戏结束收尾操作
void paint();						// 绘制游戏画面
int inGame();						// 游戏内操作以及跳转
int welcome();						// 绘制初始界面以及跳转
int Set();							// 绘制设置界面以及跳转
int Help();							// 绘制帮助界面以及跳转
int Diff();							// 绘制难度界面以及跳转
int Stats();						// 绘制统计界面以及跳转
int Reset();						// 询问是否重置统计数据
int Quit();							// 询问是否退出游戏
int End();							// 询问是否结束游戏并返回初始界面
int Restart();						// 询问是否开始新的游戏
int Win();							// 游戏胜利时操作
int Fail();							// 游戏失败时操作

// 全局变量
extern int game;					// 检测游戏状态，0是正常，1是跳转，-1是退出
extern int Ox;						// 地块坐标原点横坐标
extern int Oy;						// 地块坐标原点纵坐标
extern int safe;					// 安全挖开地块数
extern int danger;					// 未标记地雷数
extern int win1, win2, win3;		// 初级、中级、高级胜利局数
extern int lose1, lose2, lose3;		// 初级、中级、高级失败局数

extern clock_t Tstart, Tnow, Tpass;		// 记录开始、当前时间，并以此计算经过时间
extern clock_t Tbest1, Tbest2, Tbest3;	// 初级、中级、高级最快纪录

extern IMAGE img1;					// 缓冲窗口

extern ExMessage m;					// 记录鼠标信息的结构体

extern Mode mode;					// 模式参数，包括长度、宽度、地雷数

extern item title;					// 游戏标题图片
extern item author;					// 游戏作者图片
extern item undig;					// 未挖开的地块图片
extern item ready;					// 准备挖开的地块图片（高亮显示）
extern item flag;					// 标记的地块图片
extern item dig0;					// 挖开的空地块图片
extern item dig1;					// 挖开的1地块图片
extern item dig2;					// 挖开的2地块图片
extern item dig3;					// 挖开的3地块图片
extern item dig4;					// 挖开的4地块图片
extern item dig5;					// 挖开的5地块图片
extern item dig6;					// 挖开的6地块图片
extern item dig7;					// 挖开的7地块图片
extern item dig8;					// 挖开的8地块图片
extern item digX;					// 挖开的地雷地块图片

extern block** map;					// 所有地块

extern button start;				// 开始按钮
extern button set;					// 设置按钮
extern button help;					// 帮助按钮
extern button quit;					// 退出按钮
extern button back;					// 返回按钮
extern button diff;					// 难度按钮
extern button stats;				// 统计按钮
extern button reset;				// 重置按钮
extern button easy;					// 初级按钮
extern button mid;					// 中级按钮
extern button hard;					// 高级按钮
extern button custom;				// 自定义按钮