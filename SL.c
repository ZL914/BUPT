#include <stdio.h>
#include <stdlib.h>

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

void creat(int hang, int lie, int num, char arr[][lie]);                                                        // ��������
void print(int hang, int lie, char arr[][lie]);                                                                 // �������
void comparison(int hang, int lie, char arr1[][lie], char arr2[][lie]);                                         // ������������
char findleinum(int x, int y, int hang, int lie, char arr[][lie]);                                              // ������������������������Χ����
int operate(int hang, int lie, int num, int *leftlei, int x, int y, int z, char arr1[][lie], char arr2[][lie]); // ������������������������Լ�������
void expandleitian(int x, int y, int hang, int lie, char arr1[][lie], char arr2[][lie]);                        // �ݹ�չ��

int main()
{
    int level = 0;
    int m = 0;
    int n = 0;
    int l = 0;
    scanf("%d", &level);
    switch (level)
    {
    case 1:
    {
        row = ROW1;
        col = COL1;
        num = NUM1;
        break;
    }
    case 2:
    {
        row = ROW2;
        col = COL2;
        num = NUM2;
        break;
    }
    case 3:
    {
        row = ROW3;
        col = COL3;
        num = NUM3;
        break;
    }
    case 4:
    {
        scanf("%d %d %d", &m, &n, &l);
        row = m;
        col = n;
        num = l;
        break;
    }
    default:
    {
        break;
    }
    };
    char game[row][col];
    char gamecomparison[row][col];
    char gameing[row][col];
    int i = 0;
    int j = 0;
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            gameing[i][j] = '.';
        }
    }
    creat(row, col, num, game);
    comparison(row, col, game, gamecomparison);
    // �������룬�����鴴��
    int leftlei = num;
    int operatecount = 0;
    int win = 0;
    while (win == 0)
    {
        int x = 0;
        int y = 0;
        int z = 0;
        scanf("%d %d %d", &z, &x, &y);
        result = operate(row, col, num, &leftlei, x, y, z, gameing, gamecomparison);
        operatecount++;
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
            printf("Hit mine, you lose\n");
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
                    break;
                }
            } // �ж��Ƿ����ȫ����
            if (win == 0)
            {
                printf("Game in progress\n");
            }
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
                printf("Game over, you win\n");
            }
        }
        printf("%d %d\n", operatecount, leftlei);
        print(row, col, gameing);
    }
    return 0;
}

void creat(int hang, int lie, int num, char arr[][lie]) // �������뺯��
{
    int i = 0;
    int j = 0;
    int count = 0;
    getchar();
    for (i = 0; i < hang; i++)
    {
        for (j = 0; j < lie; j++)
        {
            scanf("%c", &arr[i][j]);
        }
        getchar();
    }
    return;
}

void print(int hang, int lie, char arr[][lie]) // �����������
{
    int i = 0;
    int j = 0;
    for (i = 0; i < hang; i++)
    {
        for (j = 0; j < lie; j++)
        {
            if (arr[i][j] >= 0 && arr[i][j] < 9)
            {
                printf("%d", arr[i][j]);
            }
            else
            {
                printf("%c", arr[i][j]);
            }
        }
        printf("\n");
    }
}

void comparison(int hang, int lie, char arr1[][lie], char arr2[][lie]) // �����洢ÿ��������Ϣ������
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

char findleinum(int x, int y, int hang, int lie, char arr[][lie]) // ���comparison����
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

int operate(int hang, int lie, int num, int *leftlei, int x, int y, int z, char arr1[][lie], char arr2[][lie]) // ɨ�ײ�������
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
        if (arr1[x - 1][y - 1] == '?' || arr1[x - 1][y - 1] == '.')
        {
            arr1[x - 1][y - 1] = '!';
            (*leftlei)--;
        }
        return 0;
    }
    case (3):
    {
        if (arr1[x - 1][y - 1] == '!' || arr1[x - 1][y - 1] == '.')
        {
            if (arr1[x - 1][y - 1] == '!')
            {
                arr1[x - 1][y - 1] = '?';
                (*leftlei)++;
            }
            if (arr1[x - 1][y - 1] == '.')
            {
                arr1[x - 1][y - 1] = '?';
            }
        }
        return 0;
    }
    case (4):
    {
        if (arr1[x - 1][y - 1] == '!')
        {
            arr1[x - 1][y - 1] = '.';
            (*leftlei)++;
        }
        if (arr1[x - 1][y - 1] == '?')
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
        if (arr1[x - 1][y - 1] == mark_num)
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

void expandleitian(int x, int y, int hang, int lie, char arr1[][lie], char arr2[][lie]) // �ݹ�չ������
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
                if ((arr1[i - 1][j - 1] == '.' || arr1[i - 1][j - 1] == '?' || arr1[i - 1][j - 1] == '!') && i > 0 && i <= hang && j > 0 && j <= lie)
                    expandleitian(i, j, row, col, arr1, arr2);
            }
        }
    }
    return;
}
