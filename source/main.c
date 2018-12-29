#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef struct card
{
	char* face;
	char* suit;
}card;

void start(const card* const wDeck, int *z, int *moneypl, int *moneysum, int *moneyco);
void shuffle(card* const wDeck);
void bet(int *moneypl, int mode);
int select();
void money(int *(*moneypl), int *(*moneysum), int *(*moneyco));
void turn(card* const wDeck, int turn);
void show(int i, int f, card* const wDeck);
void fillDeck(card  *wDeck, const char* wFace[], const char* wSuit[]);
int compare(card  *wDeck);
int main()
{
	int z = 0;
	int moneypl = 2000;
	int moneyco = 2000;
	int moneysum = 0;

	card  deck[52];
	char choose;
	const char *face[] = { "1","2","3","4","5","6","7","8","9","10","J","Q","K" };
	const char *suit[] = { "紅心","方塊","梅花","黑桃" };
	srand(time(NULL));
	fillDeck(deck, face, suit);
	int Cmoney, Pmoney;

	start(deck, &z, &moneypl, &moneysum, &moneyco);

	system("pause");
	return 0;
}

void start(const card* const wDeck, int *z, int *moneypl, int *moneysum, int *moneyco)
{
	int raise;
	int mode;
	char choose;



開始:

	printf("是否要開始新賽局(y/n)\n");

	scanf_s("%c", &choose);
	if (choose == 'y')
	{
		shuffle(wDeck, &z);
		//==========================================第一次下注
		turn(wDeck, 1);
		mode = select();
		if (mode == 1)
		{
			(*moneypl) -= 100;
			(*moneyco) -= 100;
			(*moneysum) += 200;
		}
		else if (mode == 2)
		{
		加注1:
			printf("\n請輸入要加注到多少");
			scanf_s("%d", &raise);
			if (raise > (*moneypl))
			{
				printf("\n你根本沒這麼多錢好嗎\n");
				goto 加注1;
			}
			printf("\n");
			(*moneypl) -= raise;
			(*moneyco) -= raise;
			(*moneysum) += 2 * raise;
		}
		else if (mode == 3)
		{
			if ((*moneypl) > (*moneyco))
			{
				(*moneysum) += (*moneyco);
				(*moneysum) += (*moneyco);
				(*moneyco) = 0;
				(*moneypl) = (*moneypl) - (*moneyco);
			}
			if ((*moneypl) = (*moneyco))
			{
				(*moneysum) += (*moneypl);
				(*moneysum) += (*moneyco);
				(*moneyco) = 0;
				(*moneypl) = 0;
			}
			if ((*moneypl) < (*moneyco))
			{
				(*moneysum) += (*moneypl);
				(*moneysum) += (*moneypl);
				(*moneyco) = (*moneyco) - (*moneypl);
				(*moneypl) = 0;
			}
		}
		else if (mode == 4)
		{
			(*moneyco) += (*moneysum);
			(*moneysum) = 0;
			getchar();
			goto 結束;
		}
		money(&(*moneypl), &(*moneysum), &(*moneyco));
		printf("\n\n===================第1輪下注結束===================\n\n");
		//==========================================第二次下注
		turn(wDeck, 2);
		mode = select();
		if (mode == 1)
		{
			(*moneypl) -= 100;
			(*moneyco) -= 100;
			(*moneysum) += 200;
		}
		else if (mode == 2)
		{
			{
			加注2:
				printf("\n請輸入要加注到多少");
				scanf_s("%d", &raise);
				if (raise > (*moneypl))
				{
					printf("\n你根本沒這麼多錢好嗎\n");
					goto 加注2;
				}
				printf("\n");
				(*moneypl) -= raise;
				(*moneyco) -= raise;
				(*moneysum) += 2 * raise;
			}
		}
		else if (mode == 3)
		{
			if ((*moneypl) > (*moneyco))
			{
				(*moneysum) += (*moneyco);
				(*moneysum) += (*moneyco);
				(*moneyco) = 0;
				(*moneypl) = (*moneypl) - (*moneyco);
			}
			if ((*moneypl) = (*moneyco))
			{
				(*moneysum) += (*moneypl);
				(*moneysum) += (*moneyco);
				(*moneyco) = 0;
				(*moneypl) = 0;
			}
			if ((*moneypl) < (*moneyco))
			{
				(*moneysum) += (*moneypl);
				(*moneysum) += (*moneypl);
				(*moneyco) = (*moneyco) - (*moneypl);
				(*moneypl) = 0;
			}
		}
		else if (mode == 4)
		{
			(*moneyco) += (*moneysum);
			(*moneysum) = 0;
			getchar();
			goto 結束;
		}
		money(&(*moneypl), &(*moneysum), &(*moneyco));
		printf("\n\n===================第2輪下注結束===================\n\n");
		//==========================================第三次下注
		turn(wDeck, 3);
		mode = select();
		if (mode == 1)
		{
			(*moneypl) -= 100;
			(*moneyco) -= 100;
			(*moneysum) += 200;
		}
		else if (mode == 2)
		{
			{
			加注3:
				printf("\n請輸入要加注到多少");
				scanf_s("%d", &raise);
				if (raise > (*moneypl))
				{
					printf("\n你根本沒這麼多錢好嗎\n");
					goto 加注3;
				}
				printf("\n");
				(*moneypl) -= raise;
				(*moneyco) -= raise;
				(*moneysum) += 2 * raise;
			}
		}
		else if (mode == 3)
		{
			if ((*moneypl) > (*moneyco))
			{
				(*moneysum) += (*moneyco);
				(*moneysum) += (*moneyco);
				(*moneyco) = 0;
				(*moneypl) = (*moneypl) - (*moneyco);
			}
			if ((*moneypl) = (*moneyco))
			{
				(*moneysum) += (*moneypl);
				(*moneysum) += (*moneyco);
				(*moneyco) = 0;
				(*moneypl) = 0;
			}
			if ((*moneypl) < (*moneyco))
			{
				(*moneysum) += (*moneypl);
				(*moneysum) += (*moneypl);
				(*moneyco) = (*moneyco) - (*moneypl);
				(*moneypl) = 0;
			}
		}
		else if (mode == 4)
		{
			(*moneyco) += (*moneysum);
			(*moneysum) = 0;
			getchar();
			goto 結束;
		}
		money(&(*moneypl), &(*moneysum), &(*moneyco));
		printf("\n\n===================第3輪下注結束===================\n\n");
		//==========================================第四次下注
		turn(wDeck, 4);
		mode = select();
		if (mode == 1)
		{
			(*moneypl) -= 100;
			(*moneyco) -= 100;
			(*moneysum) += 200;
		}
		else if (mode == 2)
		{
			{
			加注4:
				printf("\n請輸入要加注到多少");
				scanf_s("%d", &raise);
				if (raise > (*moneypl))
				{
					printf("\n你根本沒這麼多錢好嗎\n");
					goto 加注4;
				}
				printf("\n");
				(*moneypl) -= raise;
				(*moneyco) -= raise;
				(*moneysum) += 2 * raise;
			}
		}
		else if (mode == 3)
		{
			if ((*moneypl) > (*moneyco))
			{
				(*moneysum) += (*moneyco);
				(*moneysum) += (*moneyco);
				(*moneyco) = 0;
				(*moneypl) = (*moneypl) - (*moneyco);
			}
			if ((*moneypl) = (*moneyco))
			{
				(*moneysum) += (*moneypl);
				(*moneysum) += (*moneyco);
				(*moneyco) = 0;
				(*moneypl) = 0;
			}
			if ((*moneypl) < (*moneyco))
			{
				(*moneysum) += (*moneypl);
				(*moneysum) += (*moneypl);
				(*moneyco) = (*moneyco) - (*moneypl);
				(*moneypl) = 0;
			}
		}
		else if (mode == 4)
		{
			(*moneyco) += (*moneysum);
			(*moneysum) = 0;
			getchar();
			goto 結束;
		}
		money(&(*moneypl), &(*moneysum), &(*moneyco));
		printf("\n\n===================第4輪下注結束===================\n\n");
		//==========================================第五次下注
		mode = select();
		if (mode == 1)
		{
			(*moneypl) -= 100;
			(*moneyco) -= 100;
			(*moneysum) += 200;
		}
		else if (mode == 2)
		{
			{
			加注5:
				printf("\n請輸入要加注到多少");
				scanf_s("%d", &raise);
				if (raise > (*moneypl))
				{
					printf("\n你根本沒這麼多錢好嗎\n");
					goto 加注5;
				}
				printf("\n");
				(*moneypl) -= raise;
				(*moneyco) -= raise;
				(*moneysum) += 2 * raise;
			}
		}
		else if (mode == 3)
		{
			if ((*moneypl) > (*moneyco))
			{
				(*moneysum) += (*moneyco);
				(*moneysum) += (*moneyco);
				(*moneyco) = 0;
				(*moneypl) = (*moneypl) - (*moneyco);
			}
			if ((*moneypl) = (*moneyco))
			{
				(*moneysum) += (*moneypl);
				(*moneysum) += (*moneyco);
				(*moneyco) = 0;
				(*moneypl) = 0;
			}
			if ((*moneypl) < (*moneyco))
			{
				(*moneysum) += (*moneypl);
				(*moneysum) += (*moneypl);
				(*moneyco) = (*moneyco) - (*moneypl);
				(*moneypl) = 0;
			}
		}
		else if (mode == 4)
		{
			(*moneyco) += (*moneysum);
			(*moneysum) = 0;
			getchar();
			goto 結束;
		}
		money(&(*moneypl), &(*moneysum), &(*moneyco));
		printf("\n\n===================第5輪下注結束===================\n\n");
		getchar();
		goto 結束;

	結束:
		printf("\n\n=====================此局結算===================\n\n");

		if (compare(wDeck) == 1)
		{
			(*moneypl) += (*moneysum);
			(*moneysum) = 0;
		}
		else
		{
			(*moneyco) += (*moneysum);
			(*moneysum) = 0;
		}
		money(&(*moneypl), &(*moneysum), &(*moneyco));
		if ((*moneyco) <= 0 || (*moneypl) <= 0)
		{
			goto 總結;
		}
		goto 開始;
	}

	else
	{
	總結:
		printf("=====================總結算=====================\n");
		if ((*moneyco) <= 0)
		{
			printf("電腦破產\n");
		}
		else
		{
			printf("玩家破產\n");
		}
	}
}

int select()
{
	int mode;
	printf("\n\n請輸入執行的動作\n"
		"1為下注100元\n"
		"2為加注\n"
		"3為ALL IN\n"
		"4為棄排\n");
	scanf_s("%d", &mode);
	return mode;
}

void bet(int *moneypl, int mode)
{

}

void money(int *(*moneypl), int *(*moneysum), int *(*moneyco))
{
	printf("\n您現在還剩%d元", &(*(*moneypl)));
	printf("\n電腦還剩%d元", &(*(*moneyco)));
	printf("\n檯面上共有%d元\n\n", &(*(*moneysum)));
}

void turn(card* const wDeck, int turn)
{
	if (turn == 1)
	{
		printf("\n您手上的排:");
		show(0, 1, wDeck);
		printf("\n\n\n");
	}
	else if (turn == 2)
	{
		printf("\n場上的排:");
		show(2, 4, wDeck);
		printf("\n\n您手上的排:");
		show(0, 1, wDeck);
		printf("\n\n\n");

	}
	else if (turn == 3)
	{
		printf("\n場上的排:");
		show(2, 5, wDeck);
		printf("\n\n您手上的排:");
		show(0, 1, wDeck);
		printf("\n\n\n");

	}
	else if (turn == 4)
	{
		printf("\n場上的排:");
		show(2, 6, wDeck);
		printf("\n\n您手上的排:");
		show(0, 1, wDeck);
		printf("\n\n\n");

	}
}

void show(int i, int f, card* const wDeck)
{
	for (int j = i; j <= f; j++)
	{
		printf("%s%-5s", wDeck[j].suit, wDeck[j].face);
	}
}

int compare(card  *wDeck)
{
	//如果玩家勝利
	return 1;
	//如果電腦勝利
	return 0;
}

void shuffle(card* const wDeck, int z)
{
	int j;
	card temp;
	for (int i = 0; i < 52; i++)
	{
		j = rand() % 52;
		temp = wDeck[i];
		wDeck[i] = wDeck[j];
		wDeck[j] = temp;
	}
}

void fillDeck(card  *wDeck, const char* wFace[], const char* wSuit[])
{
	int i;
	for (i = 0; i < 52; i++)
	{
		wDeck[i].face = wFace[i % 13];
		wDeck[i].suit = wSuit[i / 13];
	}
}