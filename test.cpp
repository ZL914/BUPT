#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <easyx.h>
#include <conio.h>//ʹ��getch()

#define ROW1 9;
#define COL1 9;
#define NUM1 10;
// �Ѷ�һ����������
#define ROW2 16;
#define COL2 16;
#define NUM2 40;
// �Ѷȶ�����������
#define ROW3 16;
#define COL3 30;
#define NUM3 99;
// �Ѷ�������������

int row = 0;
int col = 0;
int num = 0;
int result = 0;

void creat(int hang, int lie, int num, char** arr, int x, int y);//��������
void free1(char** arr, int hang, int lie);//�ͷſռ�
char** fenpei(int hang, int lie, char** arr);//���ٿռ�
void comparison(int hang, int lie, char** arr1, char** arr2);//�����������
char findleinum(int x, int y, int hang, int lie, char** arr);//������Χ����
void print1(char* ha, char* li, char* le);//��Ҫ�����Զ�������д�ӡ
void print2(int hang, int lie, int num, char* zl, char* lxy);//��Ϸ��ʼǰ��ӡ
void print3(int hang, int lie, int num, char** arr, char* zl, char* lxy);//ÿ�β����������ӡ
int operate(int hang, int lie, int num, int* leftlei, int x, int y, int z, char** arr1, char** arr2);//��Ϸ����
void expandleitian(int x, int y, int hang, int lie, char** arr1, char** arr2);//�ݹ��ѯ

int main()
{
    int level = 0;
    int leftlei = num;
    int operatecount = 0;
    
    char ha[2];
    char li[2];
    char le[2];
    srand(time(0));
    //�����ͼ���ı���⣬������ɫ
    initgraph(1000, 750);
    setbkcolor(RGB(37, 229, 31));
    cleardevice();
    HWND hnd = GetHWnd();//��ȡ����
    SetWindowText(hnd, "ɨ��");//�޸ı���
    while (1)
    {
        int m = 0;
        int n = 0;
        int l = 0;
        IMAGE img;
        loadimage(&img, "D://CODE//ͼ�λ�//11//sl.jpeg", 1000, 750);
        putimage(0, 0, &img);
        //���õȼ�ѡ��
        setlinestyle(PS_SOLID, 2);
        setfillcolor(YELLOW);
        fillrectangle(150, 50, 250, 100);
        fillrectangle(350, 50, 450, 100);
        fillrectangle(550, 50, 650, 100);
        fillrectangle(750, 50, 850, 100);
        settextcolor(RGB(128, 128, 99));
        settextstyle(25, 0, "����");
        char arr1[] = "��";
        char arr2[] = "�Զ���";
        int width1 = 100 / 2 - textwidth(arr1) / 2;
        int width2 = 100 / 2 - textwidth(arr2) / 2;
        int height = 50 / 2 - textheight(arr1) / 2;
        setbkmode(TRANSPARENT);
        outtextxy(150 + width1, 50 + height, "��");
        outtextxy(350 + width1, 50 + height, "�е�");
        outtextxy(550 + width1, 50 + height, "����");
        outtextxy(750 + width2, 50 + height, "�Զ���");

        //���ѡ���Ѷ�
        int end = 0;//ѭ��������־
        while (end == 0)
        {
            ExMessage msg;
            if (peekmessage(&msg, EX_MOUSE))
            {
                switch (msg.message)
                {
                case WM_LBUTTONDOWN:
                    if (msg.x > 150 && msg.x < 250 && msg.y>50 && msg.y < 100)
                    {
                        row = ROW1;
                        col = COL1;
                        num = NUM1;
                        end = 1;
                    }
                    if (msg.x > 350 && msg.x < 450 && msg.y>50 && msg.y < 100)
                    {
                        row = ROW2;
                        col = COL2;
                        num = NUM2;
                        end = 2;
                    }
                    if (msg.x > 550 && msg.x < 650 && msg.y>50 && msg.y < 100)
                    {
                        row = ROW3;
                        col = COL3;
                        num = NUM3;
                        end = 3;
                    }
                    if (msg.x > 750 && msg.x < 850 && msg.y>50 && msg.y < 100)
                    {
                        setlinestyle(PS_SOLID, 2);
                        setfillcolor(YELLOW);
                        fillrectangle(250, 120, 360, 150);
                        fillrectangle(380, 120, 490, 150);
                        fillrectangle(510, 120, 620, 150);
                        fillrectangle(640, 120, 750, 150);
                        setbkmode(TRANSPARENT);
                        outtextxy(255, 125, "�У�0");
                        outtextxy(340, 120, "+");
                        outtextxy(340, 135, "-");

                        outtextxy(385, 125, "�У�0");
                        outtextxy(465, 122, "+");
                        outtextxy(465, 135, "-");

                        outtextxy(515, 125, "�ף�0");
                        outtextxy(590, 120, "+");
                        outtextxy(590, 135, "-");

                        width1 = 110 / 2 - textwidth(arr1) / 2;
                        height = 30 / 2 - textheight(arr1) / 2;
                        outtextxy(640 + width1, 120 + height, "ȷ��");
                        //�Զ�������
                        while (end == 0)
                        {
                            if (peekmessage(&msg, EX_MOUSE))
                            {
                                switch (msg.message)
                                {
                                case WM_LBUTTONDOWN:
                                    if (msg.x > 640 && msg.x < 750 && msg.y>120 && msg.y < 150)
                                    {
                                        end = 4;
                                        row = m;
                                        col = n;
                                        num = l;
                                    }
                                    else if (msg.x > 340 && msg.x < 360 && msg.y>120 && msg.y < 135)
                                        m++;
                                    else if (msg.x > 340 && msg.x < 360 && msg.y>135 && msg.y < 150)
                                        m--;
                                    else if (msg.x > 465 && msg.x < 490 && msg.y>120 && msg.y < 135)
                                        n++;
                                    else if (msg.x > 465 && msg.x < 490 && msg.y>135 && msg.y < 150)
                                        n--;
                                    else if (msg.x > 590 && msg.x < 620 && msg.y>120 && msg.y < 135)
                                        l++;
                                    else if (msg.x > 590 && msg.x < 620 && msg.y>135 && msg.y < 150)
                                        l--;
                                    sprintf(ha, "%d", m);
                                    sprintf(li, "%d", n);
                                    sprintf(le, "%d", l);
                                    cleardevice();
                                    BeginBatchDraw();//��������ͼ
                                    print1(ha, li, le);
                                    FlushBatchDraw();//������������ͼ
                                    break;
                                default:
                                    break;
                                }
                            }//ȷ����ť
                        }

                    }
                    break;
                default:
                    break;
                }
            }
        }
        leftlei = num;
        char zl[2];
        char lxy[2];
        sprintf(zl, "%d", leftlei);
        sprintf(lxy, "%d", operatecount);
        setlinestyle(PS_SOLID, 2);
        setfillcolor(YELLOW);
        fillrectangle(300, 170, 450, 205);
        fillrectangle(505, 170, 655, 205);
        setbkmode(TRANSPARENT);
        outtextxy(315, 177, "ʱ�䣺");
        outtextxy(520, 177, "���ף�");
        outtextxy(410, 177, lxy);
        outtextxy(615, 177, zl);//��һ�����

        //����ռ䣬�ж��Ƿ�ɹ�
        char** game = NULL;
        char** gameing = NULL;
        char** gamecomparison = NULL;
        game = fenpei(row, col, game);
        gameing = fenpei(row, col, game);
        gamecomparison = fenpei(row, col, game);
        if (game == NULL)
        {
            HWND hnd = GetHWnd();
            int isok = MessageBox(hnd, "��Ϸ����ʧ�ܣ����Ժ�����\n", "��ʾ", MB_OK);//��Ϸ������ʾ
            return -1;
        }
        if (gameing == NULL)
        {
            HWND hnd = GetHWnd();
            int isok = MessageBox(hnd, "��Ϸ����ʧ�ܣ����Ժ�����\n", "��ʾ", MB_OK);//��Ϸ������ʾ
            return -1;
        }
        if (gamecomparison == NULL)
        {
            HWND hnd = GetHWnd();
            int isok = MessageBox(hnd, "��Ϸ����ʧ�ܣ����Ժ�����\n", "��ʾ", MB_OK);//��Ϸ������ʾ
            return -1;
        }
        //������Ϸ
        int i = 0;
        int j = 0;
        for (i = 0; i < row; i++)
        {
            for (j = 0; j < col; j++)
            {
                gameing[i][j] = '.';
                game[i][j] = '.';
            }
        }
        BeginBatchDraw();//��������ͼ
        print2(row, col, num, zl, lxy);//��ӡ��ʼ����
        FlushBatchDraw();//������������ͼ
        int count = 0;
        int x = 0;
        int y = 0;
        int z = 0;
        flushmessage();
        int win = 0;
        int flag = 0;
        int time = 0;
        char ab[20] = { 0 };
        while (win == 0)
        {
            ExMessage msg;
            while (!peekmessage(&msg, EX_MOUSE))
            {
                Sleep(1000);
                time++;
                sprintf(ab, "%d", time);
                BeginBatchDraw();//��������ͼ
                print3(row, col, num, gameing, zl, ab);
                FlushBatchDraw();//������������ͼ
                cleardevice();
            }
            switch (msg.message)
            {
            case WM_LBUTTONDOWN:
                z = 1;
                flag = 0;
                if (end == 1)
                {
                    if (msg.x > 410 && msg.x < 590 && msg.y>360 && msg.y < 540)
                    {
                        operatecount++;
                        y = (msg.x - 410) / 20;
                        x = (msg.y - 360) / 20;
                    }
                    else {
                        flag = 1;
                    }
                }
                if (end == 2)
                {
                    if (msg.x > 340 && msg.x < 660 && msg.y>290 && msg.y < 610)
                    {
                        operatecount++;
                        y = (msg.x - 340) / 20;
                        x = (msg.y - 290) / 20;
                    }
                    else {
                        flag = 1;
                    }
                }
                if (end == 3)
                {
                    if (msg.x > 200 && msg.x < 800 && msg.y>280 && msg.y < 600)
                    {
                        operatecount++;
                        y = (msg.x - 200) / 20;
                        x = (msg.y - 280) / 20;
                    }
                    else {
                        flag = 1;
                    }
                }
                if (end == 4)
                {
                    if (msg.x > 300 && msg.x < 300 + 20 * col && msg.y>300 && msg.y < 300 + 20 * row)
                    {
                        operatecount++;
                        y = (msg.x - 300) / 20;
                        x = (msg.y - 300) / 20;
                    }
                    else {
                        flag = 1;
                    }
                }
                if (flag == 0)
                {
                    if (count == 0)
                    {
                        creat(row, col, num, game, x + 1, y + 1);
                        comparison(row, col, game, gamecomparison);
                        count++;
                    }
                    result = operate(row, col, num, &leftlei, x + 1, y + 1, z, gameing, gamecomparison);
                }
                if (result == -1)
                {
                    int i = 0;
                    int j = 0;
                    for (i = 0; i < row; i++)
                    {
                        for (j = 0; j < col; j++)
                        {
                            if (gamecomparison[i][j] == '*')
                            {
                                gameing[i][j] = gamecomparison[i][j];
                            }
                        }
                    }
                    HWND hnd = GetHWnd();
                    sprintf(zl, "%d", leftlei);
                    sprintf(lxy, "%d", operatecount);
                    BeginBatchDraw();//��������ͼ
                    print3(row, col, num, gameing, zl, ab);
                    FlushBatchDraw();//������������ͼ
                    int isok = MessageBox(hnd, "��Ϸ������ʧ�ܣ�", "��ʾ", MB_OK);//��Ϸ������ʾ
                    win = 1;
                } // ���ײ���
                if (result == 0)
                {
                    for (i = 0; i < row; i++)
                    {
                        for (j = 0; j < col; j++)
                        {
                            if (gamecomparison[i][j] != '*')
                            {
                                if (gameing[i][j] == '.' || gameing[i][j] == '!' || gameing[i][j] == '?')
                                {
                                    win = 0;
                                    break;
                                }
                                else
                                {
                                    win = 1;
                                }
                            }
                        }
                        if (win == 0)
                        {
                            sprintf(zl, "%d", leftlei);
                            sprintf(lxy, "%d", operatecount);
                            BeginBatchDraw();//��������ͼ
                            print3(row, col, num, gameing, zl, ab);
                            FlushBatchDraw();//������������ͼ
                            break;
                        }
                    } // �ж��Ƿ����ȫ����
                    if (win == 1)
                    {
                        int i = 0;
                        int j = 0;
                        for (i = 0; i < row; i++)
                        {
                            for (j = 0; j < col; j++)
                            {
                                if (gamecomparison[i][j] == '*')
                                {
                                    gameing[i][j] = gamecomparison[i][j];
                                }
                            }
                        }
                        HWND hnd = GetHWnd();
                        int isok = MessageBox(hnd, "��Ϸ������ʤ����", "��ʾ", MB_OK);//��Ϸ������ʾ
                        sprintf(zl, "%d", leftlei);
                        sprintf(lxy, "%d", operatecount);
                        BeginBatchDraw();//��������ͼ
                        print3(row, col, num, gameing, zl, ab);
                        FlushBatchDraw();//������������ͼ
                    }
                }
                break;
            case WM_RBUTTONDOWN:
                z = 2;
                flag = 0;
                if (end == 1)
                {
                    if (msg.x > 410 && msg.x < 590 && msg.y>360 && msg.y < 540)
                    {
                        operatecount++;
                        y = (msg.x - 410) / 20;
                        x = (msg.y - 360) / 20;
                    }
                    else {
                        flag = 1;
                    }
                }
                if (end == 2)
                {
                    if (msg.x > 340 && msg.x < 660 && msg.y>290 && msg.y < 610)
                    {
                        operatecount++;
                        y = (msg.x - 340) / 20;
                        x = (msg.y - 290) / 20;
                    }
                    else {
                        flag = 1;
                    }
                }
                if (end == 3)
                {
                    if (msg.x > 200 && msg.x < 520 && msg.y>280 && msg.y < 880)
                    {
                        operatecount++;
                        y = (msg.x - 200) / 20;
                        x = (msg.y - 280) / 20;
                    }
                    else {
                        flag = 1;
                    }
                }
                if (end == 4)
                {
                    if (msg.x > 300 && msg.x < 300 + 20 * col && msg.y>300 && msg.y < 300 + 20 * row)
                    {
                        operatecount++;
                        y = (msg.x - 300) / 20;
                        x = (msg.y - 300) / 20;
                    }
                    else {
                        flag = 1;
                    }
                }
                if (flag == 0)
                {
                    result = operate(row, col, num, &leftlei, x + 1, y + 1, z, gameing, gamecomparison);
                }
                if (result == -1)
                {
                    int i = 0;
                    int j = 0;
                    for (i = 0; i < row; i++)
                    {
                        for (j = 0; j < col; j++)
                        {
                            if (gamecomparison[i][j] == '*')
                            {
                                gameing[i][j] = gamecomparison[i][j];
                            }
                        }
                    }
                    HWND hnd = GetHWnd();
                    int isok = MessageBox(hnd, "��Ϸ������ʧ�ܣ�", "��ʾ", MB_OK);//��Ϸ������ʾ
                    sprintf(zl, "%d", leftlei);
                    sprintf(lxy, "%d", operatecount);
                    BeginBatchDraw();//��������ͼ
                    print3(row, col, num, gameing, zl, ab);
                    FlushBatchDraw();//������������ͼ
                    win = 1;
                } // ���ײ���
                if (result == 0)
                {
                    for (i = 0; i < row; i++)
                    {
                        for (j = 0; j < col; j++)
                        {
                            if (gamecomparison[i][j] != '*')
                            {
                                if (gameing[i][j] == '.' || gameing[i][j] == '!' || gameing[i][j] == '?')
                                {
                                    win = 0;
                                    break;
                                }
                                else
                                {
                                    win = 1;
                                }
                            }
                        }
                        if (win == 0)
                        {
                            sprintf(zl, "%d", leftlei);
                            sprintf(lxy, "%d", operatecount);
                            BeginBatchDraw();//��������ͼ
                            print3(row, col, num, gameing, zl, ab);
                            FlushBatchDraw();//������������ͼ
                            break;
                        }
                    } // �ж��Ƿ����ȫ����
                    if (win == 1)
                    {
                        int i = 0;
                        int j = 0;
                        for (i = 0; i < row; i++)
                        {
                            for (j = 0; j < col; j++)
                            {
                                if (gamecomparison[i][j] == '*')
                                {
                                    gameing[i][j] = gamecomparison[i][j];
                                }
                            }
                        }
                        HWND hnd = GetHWnd();
                        int isok = MessageBox(hnd, "��Ϸ������ʤ����", "��ʾ", MB_OK);//��Ϸ������ʾ
                        sprintf(zl, "%d", leftlei);
                        sprintf(lxy, "%d", operatecount);
                        BeginBatchDraw();//��������ͼ
                        print3(row, col, num, gameing, zl, ab);
                        FlushBatchDraw();//������������ͼ
                    }
                }
                break;
            case WM_MBUTTONDOWN:
                flag = 0;
                z = 9;
                if (end == 1)
                {
                    if (msg.x > 410 && msg.x < 590 && msg.y>360 && msg.y < 540)
                    {
                        operatecount++;
                        y = (msg.x - 410) / 20;
                        x = (msg.y - 360) / 20;
                    }
                    else {
                        flag = 1;
                    }
                }
                if (end == 2)
                {
                    if (msg.x > 340 && msg.x < 660 && msg.y>290 && msg.y < 610)
                    {
                        operatecount++;
                        y = (msg.x - 340) / 20;
                        x = (msg.y - 290) / 20;
                    }
                    else {
                        flag = 1;
                    }
                }
                if (end == 3)
                {
                    if (msg.x > 200 && msg.x < 520 && msg.y>280 && msg.y < 880)
                    {
                        operatecount++;
                        y = (msg.x - 200) / 20;
                        x = (msg.y - 280) / 20;
                    }
                    else {
                        flag = 1;
                    }
                }
                if (end == 4)
                {
                    if (msg.x > 300 && msg.x < 300 + 20 * col && msg.y>300 && msg.y < 300 + 20 * row)
                    {
                        operatecount++;
                        y = (msg.x - 300) / 20;
                        x = (msg.y - 300) / 20;
                    }
                    else {
                        flag = 1;
                    }
                }
                if (flag == 0)
                {
                    result = operate(row, col, num, &leftlei, x + 1, y + 1, z, gameing, gamecomparison);
                }
                if (result == -1)
                {
                    int i = 0;
                    int j = 0;
                    for (i = 0; i < row; i++)
                    {
                        for (j = 0; j < col; j++)
                        {
                            if (gamecomparison[i][j] == '*')
                            {
                                gameing[i][j] = gamecomparison[i][j];
                            }
                        }
                    }
                    HWND hnd = GetHWnd();
                    int isok = MessageBox(hnd, "��Ϸ������ʧ�ܣ�", "��ʾ", MB_OK);//��Ϸ������ʾ
                    sprintf(zl, "%d", leftlei);
                    sprintf(lxy, "%d", operatecount);
                    BeginBatchDraw();//��������ͼ
                    print3(row, col, num, gameing, zl, ab);
                    FlushBatchDraw();//������������ͼ
                    win = 1;
                } // ���ײ���
                if (result == 0)
                {
                    for (i = 0; i < row; i++)
                    {
                        for (j = 0; j < col; j++)
                        {
                            if (gamecomparison[i][j] != '*')
                            {
                                if (gameing[i][j] == '.' || gameing[i][j] == '!' || gameing[i][j] == '?')
                                {
                                    win = 0;
                                    break;
                                }
                                else
                                {
                                    win = 1;
                                }
                            }
                        }
                        if (win == 0)
                        {
                            sprintf(zl, "%d", leftlei);
                            sprintf(lxy, "%d", operatecount);
                            BeginBatchDraw();//��������ͼ
                            print3(row, col, num, gameing, zl, ab);
                            FlushBatchDraw();//������������ͼ
                            break;
                        }
                    } // �ж��Ƿ����ȫ����
                    if (win == 1)
                    {
                        int i = 0;
                        int j = 0;
                        for (i = 0; i < row; i++)
                        {
                            for (j = 0; j < col; j++)
                            {
                                if (gamecomparison[i][j] == '*')
                                {
                                    gameing[i][j] = gamecomparison[i][j];
                                }
                            }
                        }
                        HWND hnd = GetHWnd();
                        int isok = MessageBox(hnd, "��Ϸ������ʤ����", "��ʾ", MB_OK);//��Ϸ������ʾ
                        sprintf(zl, "%d", leftlei);
                        sprintf(lxy, "%d", operatecount);
                        BeginBatchDraw();//��������ͼ
                        print3(row, col, num, gameing, zl, ab);
                        FlushBatchDraw();//������������ͼ
                    }
                }
                break;
            }
        }
        free1(game, row, col);
        free1(gameing, row, col);
        free1(gamecomparison, row, col);//��Ϸ�����ͷ��ڴ�
    }
    getchar();//��ʾ���棬������
    closegraph();//�رմ���
    return 0;
}

void creat(int hang, int lie, int num, char** arr, int x, int y) // �������뺯��
{
    while (num)
    {
        int i = rand() % hang;
        int j = rand() % lie;
        if (i != x - 1 && j != y - 1 && arr[i][j] != '*')
        {
            arr[i][j] = '*';
            num--;
        }
    }
}

char** fenpei(int hang, int lie, char** arr) // ��̬����ռ�
{
    int i = 0;
    arr = (char**)malloc(hang * sizeof(char*));
    if (arr == NULL)
    {
        return NULL;
    }
    else
    {
        for (i = 0; i < hang; i++)
        {
            arr[i] = (char*)malloc(lie * sizeof(char));
            if (arr[i] == NULL)
            {
                return NULL;
            }
        }
        return arr;
    }
}

void free1(char** arr, int hang, int lie) // �ͷ��ڴ�
{
    int i = 0;
    for (i = 0; i < hang; i++)
    {
        free(arr[i]);
        arr[i] = NULL;
    }
    free(arr);
    arr = NULL;
}

void print1(char* ha, char* li, char* le)//����ʱ��ӡ
{
    IMAGE img;
    loadimage(&img, "D://CODE//ͼ�λ�//11//sl.jpeg", 1000, 750);
    putimage(0, 0, &img);
    setlinestyle(PS_SOLID, 2);
    setfillcolor(YELLOW);
    fillrectangle(150, 50, 250, 100);
    fillrectangle(350, 50, 450, 100);
    fillrectangle(550, 50, 650, 100);
    fillrectangle(750, 50, 850, 100);
    settextcolor(RGB(128, 128, 99));
    settextstyle(25, 0, "����");
    char arr1[] = "��";
    char arr2[] = "�Զ���";
    int width1 = 100 / 2 - textwidth(arr1) / 2;
    int width2 = 100 / 2 - textwidth(arr2) / 2;
    int height = 50 / 2 - textheight(arr1) / 2;
    setbkmode(TRANSPARENT);
    outtextxy(150 + width1, 50 + height, "��");
    outtextxy(350 + width1, 50 + height, "�е�");
    outtextxy(550 + width1, 50 + height, "����");
    outtextxy(750 + width2, 50 + height, "�Զ���");

    setlinestyle(PS_SOLID, 2);
    setfillcolor(YELLOW);
    fillrectangle(250, 120, 360, 150);
    fillrectangle(380, 120, 490, 150);
    fillrectangle(510, 120, 620, 150);
    fillrectangle(640, 120, 750, 150);
    outtextxy(255, 125, "�У�");
    outtextxy(340, 120, "+");
    outtextxy(340, 135, "-");

    outtextxy(385, 125, "�У�");
    outtextxy(465, 122, "+");
    outtextxy(465, 135, "-");

    outtextxy(515, 125, "�ף�");
    outtextxy(590, 120, "+");
    outtextxy(590, 135, "-");

    width1 = 110 / 2 - textwidth(arr1) / 2;
    height = 30 / 2 - textheight(arr1) / 2;
    outtextxy(640 + width1, 120 + height, "ȷ��");
    outtextxy(300, 125, ha);
    outtextxy(430, 125, li);
    outtextxy(560, 125, le);
}

void comparison(int hang, int lie, char** arr1, char** arr2) // �����洢ÿ��������Ϣ������
{
    char count = 0;
    int i = 0;
    int j = 0;
    for (i = 0; i < hang; i++)
    {
        for (j = 0; j < lie; j++)
        {
            count = findleinum(i, j, hang, lie, arr1);
            arr2[i][j] = count;
        }
    }
}

char findleinum(int x, int y, int hang, int lie, char** arr) // ���comparison����
{
    int num = 0;
    if (arr[x][y] == '*')
    {
        return '*';
    }
    else
    {
        for (int i = x - 1; i <= x + 1; i++)
        {
            for (int j = y - 1; j <= y + 1; j++)
            {
                if (i >= 0 && i < hang && j >= 0 && j < lie)
                {
                    if (arr[i][j] == '*')
                    {
                        num++;
                    }
                }
            }
        }
    }
    return num;
}

void print2(int hang, int lie, int num, char* zl, char* lxy)
{
    IMAGE img;
    loadimage(&img, "D://CODE//ͼ�λ�//11//sl.jpeg", 1000, 750);
    putimage(0, 0, &img);
    setlinestyle(PS_SOLID, 2);
    setfillcolor(YELLOW);
    fillrectangle(150, 50, 250, 100);
    fillrectangle(350, 50, 450, 100);
    fillrectangle(550, 50, 650, 100);
    fillrectangle(750, 50, 850, 100);
    settextcolor(RGB(128, 128, 99));
    settextstyle(25, 0, "����");
    char arr1[] = "��";
    char arr2[] = "�Զ���";
    int width1 = 100 / 2 - textwidth(arr1) / 2;
    int width2 = 100 / 2 - textwidth(arr2) / 2;
    int height = 50 / 2 - textheight(arr1) / 2;
    setbkmode(TRANSPARENT);
    outtextxy(150 + width1, 50 + height, "��");
    outtextxy(350 + width1, 50 + height, "�е�");
    outtextxy(550 + width1, 50 + height, "����");
    outtextxy(750 + width2, 50 + height, "�Զ���");
    fillrectangle(300, 170, 450, 205);
    fillrectangle(505, 170, 655, 205);
    setbkmode(TRANSPARENT);
    outtextxy(315, 177, "ʱ�䣺");
    outtextxy(520, 177, "���ף�");
    outtextxy(405, 177, lxy);
    outtextxy(610, 177, zl);
    setlinestyle(PS_SOLID, 2);
    setfillcolor(YELLOW);

    int i = 0;
    int j = 0;
    setlinestyle(PS_SOLID, 2);
    setfillcolor(RGB(255, 193, 29));
    if (num == 10 && hang == 9 && lie == 9)
    {
        for (i = 0; i < hang; i++)
        {
            for (j = 0; j < lie; j++)
            {
                fillrectangle(410 + j * 20, 360 + i * 20, 410 + (j + 1) * 20, 360 + (i + 1) * 20);
            }
        }
    }
    else if (num == 40 && hang == 16 && lie == 16)
    {
        for (i = 0; i < hang; i++)
        {
            for (j = 0; j < lie; j++)
            {
                fillrectangle(340 + j * 20, 290 + i * 20, 340 + (j + 1) * 20, 290 + (i + 1) * 20);
            }
        }
    }
    else if (num == 99 && hang == 16 && lie == 30)
    {
        for (i = 0; i < hang; i++)
        {
            for (j = 0; j < lie; j++)
            {
                fillrectangle(200 + j * 20, 280 + i * 20, 200 + (j + 1) * 20, 280 + (i + 1) * 20);
            }
        }
    }
    else {
        for (i = 0; i < hang; i++)
        {
            for (j = 0; j < lie; j++)
            {
                fillrectangle(300 + j * 20, 300 + i * 20, 300 + (j + 1) * 20, 300 + (i + 1) * 20);
            }
        }
    }
}

int operate(int hang, int lie, int num, int* leftlei, int x, int y, int z, char** arr1, char** arr2) // ɨ�ײ�������
{
    if (x < 1 || x > hang || y < 1 || y > lie)
    {
        return 0;
    } // �ж������Ƿ�Ϸ�
    switch (z)
    {
    case (1):
    {
        if (arr1[x - 1][y - 1] == '!')
        {
            return 0;
        }
        if (arr1[x - 1][y - 1] == '.' || arr1[x - 1][y - 1] == '?')
        {
            if (arr2[x - 1][y - 1] == '*')
            {
                return -1;
            } // ����
            expandleitian(x, y, row, col, arr1, arr2);
        }
        return 0;
    }
    case (2):
    {
        if (arr1[x - 1][y - 1] == '.')
        {
            arr1[x - 1][y - 1] = '!';
            (*leftlei)--;
        }
        else if (arr1[x - 1][y - 1] == '!')
        {
            arr1[x - 1][y - 1] = '?';
            (*leftlei)++;
        }
        else if (arr1[x - 1][y - 1] == '?')
        {
            arr1[x - 1][y - 1] = '.';
        }
        return 0;
    }
    case (9):
    {
        int mark_num = 0; // ��Χ'!'����
        for (int i = x - 2; i <= x; i++)
        {
            for (int j = y - 2; j <= y; j++)
            {
                if (i >= 0 && i < hang && j >= 0 && j < lie)
                {
                    if (arr1[i][j] == '!')
                    {
                        mark_num++;
                    }
                }
            }
        } // �ж���Χ�����
        if (arr1[x - 1][y - 1] == mark_num + '0')
        {
            for (int i = x - 1; i <= x + 1; i++)
            {
                for (int j = y - 1; j <= y + 1; j++)
                {
                    if (i > 0 && i <= hang && j > 0 && j <= lie)
                    {
                        if (arr1[i - 1][j - 1] != '!' && arr2[i - 1][j - 1] == '*')
                            return -1;
                    }
                }
            }
            for (int i = x - 1; i <= x + 1; i++)
            {
                for (int j = y - 1; j <= y + 1; j++)
                {
                    if (i > 0 && i <= hang && j > 0 && j <= lie)
                    {
                        if (arr1[i - 1][j - 1] == '.' || arr1[i - 1][j - 1] == '?')
                        {
                            if (arr2[i - 1][j - 1] == '*')
                            {
                                return -1;
                            }
                            expandleitian(i, j, row, col, arr1, arr2);
                        }
                    }
                }
            }
            return 0;
        }
        else
        {
            return 0;
        }
    }
    default:
    {
        return 0;
        break;
    }
    }
}

void expandleitian(int x, int y, int hang, int lie, char** arr1, char** arr2) // �ݹ�չ������
{
    if (x < 1 || x > hang || y < 1 || y > lie)
    {
        return;
    }
    if (arr2[x - 1][y - 1] == '*')
    {
        return;
    }
    if (arr1[x - 1][y - 1] != '.' && arr1[x - 1][y - 1] != '?')
    {
        return;
    }
    arr1[x - 1][y - 1] = arr2[x - 1][y - 1];
    if (arr1[x - 1][y - 1] > 0)
        return;
    if (arr1[x - 1][y - 1] == 0)
    {
        for (int i = x - 1; i <= x + 1; i++)
        {
            for (int j = y - 1; j <= y + 1; j++)
            {
                if (i > 0 && i <= hang && j > 0 && j <= lie && (arr1[i - 1][j - 1] == '.' || arr1[i - 1][j - 1] == '?' || arr1[i - 1][j - 1] == '!'))
                    expandleitian(i, j, row, col, arr1, arr2);
            }
        }
    }
    return;
}

void print3(int hang, int lie, int num, char** arr, char* zl, char* lxy)
{
    print2(hang, lie, num, zl, lxy);
    setbkmode(TRANSPARENT);
    settextcolor(BLACK);
    settextstyle(20, 0, "����");
    int i = 0;
    int j = 0;
    if (num == 10 && hang == 9 && lie == 9)
    {
        for (i = 0; i < hang; i++)
        {
            for (j = 0; j < lie; j++)
            {
                if (arr[i][j] >= 0 && arr[i][j] <= 9)
                {
                    arr[i][j] += '0';
                }
                if (arr[i][j] != '.')
                    outtextxy((411 + j * 20), (362 + i * 20), arr[i][j]);
            }
        }
    }
    else if (num == 40 && hang == 16 && lie == 16)
    {
        for (i = 0; i < hang; i++)
        {
            for (j = 0; j < lie; j++)
            {
                if (arr[i][j] >= 0 && arr[i][j] <= 9)
                {
                    arr[i][j] += '0';
                }
                if (arr[i][j] != '.')
                    outtextxy((341 + j * 20), (292 + i * 20), arr[i][j]);
            }
        }
    }
    else if (num == 99 && hang == 16 && lie == 30)
    {
        for (i = 0; i < hang; i++)
        {
            for (j = 0; j < lie; j++)
            {
                if (arr[i][j] >= 0 && arr[i][j] <= 9)
                {
                    arr[i][j] += '0';
                }
                if (arr[i][j] != '.')
                    outtextxy((201 + j * 20), (282 + i * 20), arr[i][j]);
            }
        }
    }
    else {
        for (i = 0; i < hang; i++)
        {
            for (j = 0; j < lie; j++)
            {
                if (arr[i][j] >= 0 && arr[i][j] <= 9)
                {
                    arr[i][j] += '0';
                }
                if (arr[i][j] != '.')
                    outtextxy((301 + j * 20), (302 + i * 20), arr[i][j]);
            }

        }
    }
}
