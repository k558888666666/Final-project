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
	const char *suit[] = { "����","���","����","�®�" };
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



�}�l:

	printf("�O�_�n�}�l�s�ɧ�(y/n)\n");

	scanf_s("%c", &choose);
	if (choose == 'y')
	{
		shuffle(wDeck, &z);
		//==========================================�Ĥ@���U�`
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
		�[�`1:
			printf("\n�п�J�n�[�`��h��");
			scanf_s("%d", &raise);
			if (raise > (*moneypl))
			{
				printf("\n�A�ڥ��S�o��h���n��\n");
				goto �[�`1;
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
			goto ����;
		}
		money(&(*moneypl), &(*moneysum), &(*moneyco));
		printf("\n\n===================��1���U�`����===================\n\n");
		//==========================================�ĤG���U�`
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
			�[�`2:
				printf("\n�п�J�n�[�`��h��");
				scanf_s("%d", &raise);
				if (raise > (*moneypl))
				{
					printf("\n�A�ڥ��S�o��h���n��\n");
					goto �[�`2;
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
			goto ����;
		}
		money(&(*moneypl), &(*moneysum), &(*moneyco));
		printf("\n\n===================��2���U�`����===================\n\n");
		//==========================================�ĤT���U�`
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
			�[�`3:
				printf("\n�п�J�n�[�`��h��");
				scanf_s("%d", &raise);
				if (raise > (*moneypl))
				{
					printf("\n�A�ڥ��S�o��h���n��\n");
					goto �[�`3;
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
			goto ����;
		}
		money(&(*moneypl), &(*moneysum), &(*moneyco));
		printf("\n\n===================��3���U�`����===================\n\n");
		//==========================================�ĥ|���U�`
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
			�[�`4:
				printf("\n�п�J�n�[�`��h��");
				scanf_s("%d", &raise);
				if (raise > (*moneypl))
				{
					printf("\n�A�ڥ��S�o��h���n��\n");
					goto �[�`4;
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
			goto ����;
		}
		money(&(*moneypl), &(*moneysum), &(*moneyco));
		printf("\n\n===================��4���U�`����===================\n\n");
		//==========================================�Ĥ����U�`
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
			�[�`5:
				printf("\n�п�J�n�[�`��h��");
				scanf_s("%d", &raise);
				if (raise > (*moneypl))
				{
					printf("\n�A�ڥ��S�o��h���n��\n");
					goto �[�`5;
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
			goto ����;
		}
		money(&(*moneypl), &(*moneysum), &(*moneyco));
		printf("\n\n===================��5���U�`����===================\n\n");
		getchar();
		goto ����;

	����:
		printf("\n\n=====================��������===================\n\n");

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
			goto �`��;
		}
		goto �}�l;
	}

	else
	{
	�`��:
		printf("=====================�`����=====================\n");
		if ((*moneyco) <= 0)
		{
			printf("�q���}��\n");
		}
		else
		{
			printf("���a�}��\n");
		}
	}
}

int select()
{
	int mode;
	printf("\n\n�п�J���檺�ʧ@\n"
		"1���U�`100��\n"
		"2���[�`\n"
		"3��ALL IN\n"
		"4�����\n");
	scanf_s("%d", &mode);
	return mode;
}

void bet(int *moneypl, int mode)
{

}

void money(int *(*moneypl), int *(*moneysum), int *(*moneyco))
{
	printf("\n�z�{�b�ٳ�%d��", &(*(*moneypl)));
	printf("\n�q���ٳ�%d��", &(*(*moneyco)));
	printf("\n�i���W�@��%d��\n\n", &(*(*moneysum)));
}

void turn(card* const wDeck, int turn)
{
	if (turn == 1)
	{
		printf("\n�z��W����:");
		show(0, 1, wDeck);
		printf("\n\n\n");
	}
	else if (turn == 2)
	{
		printf("\n���W����:");
		show(2, 4, wDeck);
		printf("\n\n�z��W����:");
		show(0, 1, wDeck);
		printf("\n\n\n");

	}
	else if (turn == 3)
	{
		printf("\n���W����:");
		show(2, 5, wDeck);
		printf("\n\n�z��W����:");
		show(0, 1, wDeck);
		printf("\n\n\n");

	}
	else if (turn == 4)
	{
		printf("\n���W����:");
		show(2, 6, wDeck);
		printf("\n\n�z��W����:");
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
	//�p�G���a�ӧQ
	return 1;
	//�p�G�q���ӧQ
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