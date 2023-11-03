#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <easyx.h>
#include <conio.h>//使用getch()
#include <mmsystem.h>//多媒体播放音乐
#pragma comment(lib,"winmm.lib")

void BGM()
{
	mciSendString("open ./friend.mp3 alias BGM",0,0,0);//alias 取别名
	mciSendString("play BGM", 0, 0, 0);//repeat重复播放
}
void change()
{
	HWND hnd = GetHWnd();//获取标题
	SetWindowText(hnd, "实验");//修改标题
	int isok=MessageBox(hnd, "结束", "提示", MB_OKCANCEL);//游戏结束提示
	if (isok == IDOK)
	{

	}
	else if (isok == IDCANCEL)
	{

	}
}
int main()
{
	//创建窗口
	initgraph(1024, 680);//确定窗口大小,有第三个参数,在第二个参数后面可以加上initgraph(640, 480，EX_NOCLOSE|EX_NOMINIMIZE|EX_SHOWCONSOLE）发给谁谁带痛苦面具
	BGM();
	change();


	//背景
	setbkcolor(WHITE);//设置背景颜色ONE
	cleardevice();// 清屏，设置完颜色后清除之前的黑色，显现白色TWO   必须连用两步




	//画图
	setlinestyle(PS_SOLID,4);//设置线条样式，实线,宽度
	setfillcolor(YELLOW);//设置填充颜色   颜色可用RGB(50,50,50);对应红绿蓝三基色合成
	setlinecolor(RED);//设置线条颜色
	circle(50,50,50);//画圆（圆心坐标和半径）
	fillcircle(50, 160, 50);//有填充圆
	solidcircle(50, 270, 50);//无边框填充




	//绘制文字
	settextcolor(RGB(0,128,99));//设置文字颜色
	settextstyle(25, 0,"楷体");//高度，宽度，字体，0为自适应
	setbkmode(TRANSPARENT);//设置文字背景，透明，不覆盖
	//outtextxy(0, 350, L"谢谢观看！");//第一种加L
	//outtextxy(0, 390, TEXT("谢谢观看！"));//第二种加TEXT
	outtextxy(0, 350, "谢谢观看！");//修改设置





	//文字居中
	fillrectangle(200, 50, 500, 100);
	settextcolor(RGB(128, 128, 99));
	char arr[] = "文字居中";
	int width = 300 / 2 - textwidth(arr) / 2;//计算arr中字符串宽度
	int height = 50 / 2 - textheight(arr) / 2;//计算arr中字符串高度
	outtextxy(200+width,50+height,arr);







	//输出图片
	IMAGE img;
	loadimage(&img, "./test.png",240,120);//加载图片,改变图片大小
	//相对路径：./test.png在当前目录下
	//绝对路径：D:\\CODE\\easyx.cpp\\test.png
	putimage( 400, 0,&img);//输出从0 0开始输出




	//鼠标操作
	/*ExMessage msg;
	while (1)
	{
		if (peekmessage(&msg,EX_MOUSE))
		{
			switch (msg.message)
			{
			case WM_LBUTTONDOWN:
				if (msg.x > 200 && msg.x < 500 && msg.y>50 && msg.y < 100)
				{
					printf("左键已点击\n");
				}
				outtextxy(400, 400, "左键单击");
				printf("坐标:（%d %d）\n",msg.x, msg.y);
				break;
			case WM_RBUTTONDOWN:
				if (msg.x > 200 && msg.x < 500 && msg.y>50 && msg.y < 100)
				{
					printf("右键已点击\n");
				}
				outtextxy(400, 400, "右键单击");
				printf("坐标:（%d %d）\n", msg.x, msg.y);
				break;
			}
		}
	}*/










	int x = 10;
	int y = 10;
	//键盘读取
	while (1)
	{
		cleardevice();
		setfillcolor(BLUE);
		BeginBatchDraw();//缓冲区绘图
		solidcircle(x, y, 30);
		FlushBatchDraw();//结束缓冲区绘图



	    //第一种读取操作
		/*if (GetAsyncKeyState(VK_UP))
		{
			y -= 5;
		}
		if (GetAsyncKeyState(VK_DOWN))
		{
			y += 5;
		}
		if (GetAsyncKeyState(VK_LEFT))
		{
			x -= 5;
		}
		if (GetAsyncKeyState(VK_RIGHT))
		{
			x += 5;
		}
		*/
		



		//第二种操作
		if (_kbhit())
		{
		    char key = _getch();//阻塞，若没有输入则一直等
		    printf("%d %c\n", key, key);
			switch (key)
			{
			case 'w':
			case 'W':
				y -= 5;
				break;
			case 'a':
			case 'A':
				x -= 5;
				break;
			case 's':
			case 'S':
				y += 5;
				break;
			case 'D':
			case 'd':
				x += 5;
				break;//读取上下左右键
			}
		}
	}





	getchar();//显示界面，防闪退
	closegraph();//关闭窗口
	return 0;
}

//椭圆 ellipse()  扇形pie() 多边形polygon() 矩形rectangle() 圆角矩形roundrect() 线line() 点putpixel()