/**
 * Name: 扑克洗牌与发牌
 * Author: Terry
 * Description: 
 * 模拟除了大小王之外的52张扑克牌洗牌
 * 并依次将发出的牌按照花色排序后输出
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int deck[52];
int playerCards[4][13] = {0};

/**
 * 交换函数
 */
void swap(int *num1, int *num2)
{
    int temp;
    temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

/**
 * 洗牌函数，实现洗牌
 */
void shuffle(int *deck, int length)
{
    int i, j;
    srand(time(NULL)); //初始化随机种子
    for (i = 0; i < length; i++)
    {
        j = rand() % 52;
        swap(deck + i, deck + j);
    }
}

/**
 * 发牌函数
 */
void dealer(int *deck, int length, int playersCards[][13])
{
    int i, j = 0;
    int count = 0;
    for (i = 0; i < length; i++)
    {
        switch (i % 4)
        {
        case 0:
            playersCards[0][j] = deck[i];
            break;
        case 1:
            playersCards[1][j] = deck[i];
            break;
        case 2:
            playersCards[2][j] = deck[i];
            break;
        default:
            playersCards[3][j] = deck[i];
        }
        count++;
        if (count % 4 == 0)
            j++;
    }
}

/**
 * 按花色排序
 */
void sort(int *a, int length)
{
    int i, j;
    for (j = 0; j < length - 1; j++)
    {
        for (i = 0; i < length - 1; i++)
        {
            if (a[i] > a[i + 1])
                swap(&a[i], &a[i + 1]);
        }
    }
}

void displayValues(int card)
{
    int value = (card - 1) % 13;
    if (value < 9)
        printf("%d", value + 2);
    else
        switch (value)
        {
        case 9:
            printf("J");
            break;
        case 10:
            printf("Q");
            break;
        case 11:
            printf("K");
            break;
        case 12:
            printf("A");
            break;
        }
}

void displaySuits(int card)
{
    char *suits[] = {"黑桃", "红桃", "梅花", "方块"};
    int suit = (card - 1) / 13;
    printf("%s", suits[suit]);
}

void display(int *cards, int length)
{
    for (int i = 0; i < length; i++)
    {
        displaySuits(cards[i]);
        displayValues(cards[i]);
    }
}

int main()
{
    int deck[52];
    // 四个玩家的手牌
    int playersCards[4][13] = {0};
    for (int i = 0; i < 52; i++)
    {
        deck[i] = i + 1;
    }
    for (int i = 0; i < 3; i++)
    {
        shuffle(deck, 52);
    }
    dealer(deck, 52, playersCards);
    for (int i = 0; i < 4; i++)
    {
        sort(playersCards[i], 13);
        printf("\n\n玩家%d的牌是: \n", i + 1);
        display(playersCards[i], 13);
    }
    return 0;
}