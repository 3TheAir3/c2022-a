//����main���ּ��߼����ִ���
#include"HEAD.h"
#include"HEAD_G.h"
int gamemode = 0;//����ģʽ��1Ϊ˫�ˣ�2Ϊ�˻�
int gamer_color = -1;//�˻�ģʽ�������ɫ
int AI_Estimation_BLACK;//����ȫ�ֹ�ֵ
int AI_Estimation_WHITE;//����ȫ�ֹ�ֵ
int AI_ThinkWidth[4] = { 15,-1,15,-1 };//AI��������
chess chessmap[15][15];//�����Ϣ
chess_pos chess_pos_cursor = { 0,0 };//������������
int chess_draw_list[15 * 15][3] = { 0 };//��Ⱦ�������У�������Ⱦ�����ݣ�0�洢������ɫ��1�洢xֵ��2�洢yֵ(1-15)
int count = 0;//��������
int l5_b = 0;
int l5_w = 0;
int l4_b = 0;
int l4_w = 0;
int d4_b = 0;
int d4_w = 0;
int l3_b = 0;
int l3_w = 0;
int d3_b = 0;
int d3_w = 0;
bool isWin = false;//��ʤ�ж�
int main() {
	printf("��������Ϸ\n");
	printf("������ӣ���R������\n");
	printf("��ѡ������ģʽ��1˫��ģʽ 2�˻�ģʽ 0�˳�\n");
	std::cin >> gamemode;
	switch (gamemode)
	{
	case 0:
		return 0;
		break;
	case 1:
		running(1);
		break;
	case 2:
		printf("��ѡ������ִ�ӣ�1���� 2���ף���");
		std::cin >> gamer_color;
		if (gamer_color!=1&&gamer_color!=2)
		{
			printf("�������\n");
			return -1;
			break;
		}else{
			if (gamer_color==2)
			{
				AI_ThinkWidth[0] = 7;
				AI_ThinkWidth[1] = 7;
				AI_ThinkWidth[2] = 7;
				AI_ThinkWidth[3] = 7;
			}
			running(2);
			break;
		}
	default:
		printf("�������\n");
		return -1;
		break;
	}
	return 0;
}
void winchack(int nowchess[3]) {//�����������Ӱ˸�����ͳ��������
	int cnt = 1;
	if (count) {
		for (int i = -1; nowchess[1] - 1 + i >= 0 && chessmap[nowchess[1] - 1 + i][nowchess[2] - 1].chesskind == nowchess[0]; i--)//��
		{
			cnt++;
			if (cnt == 5) {
				isWin = true;
				return;
			}
		}
		for (int i = 1; nowchess[1] - 1 + i < 15 && chessmap[nowchess[1] - 1 + i][nowchess[2] - 1].chesskind == nowchess[0]; i++)//��
		{
			cnt++;
			if (cnt == 5) {
				isWin = true;
				return;
			}
		}
		cnt = 1;
		for (int i = -1; nowchess[2] - 1 + i >= 0 && chessmap[nowchess[1] - 1][nowchess[2] - 1 + i].chesskind == nowchess[0]; i--)//��
		{
			cnt++;
			if (cnt == 5) {
				isWin = true;
				return;
			}
		}
		for (int i = 1; nowchess[2] - 1 + i < 15 && chessmap[nowchess[1] - 1][nowchess[2] - 1 + i].chesskind == nowchess[0]; i++)//��
		{
			cnt++;
			if (cnt == 5) {
				isWin = true;
				return;
			}
		}
		cnt = 1;
		for (int i = -1; (nowchess[1] - 1 + i >= 0 && nowchess[2] - 1 + i >= 0) && chessmap[nowchess[1] - 1 + i][nowchess[2] - 1 + i].chesskind == nowchess[0]; i--)//����
		{
			cnt++;
			if (cnt == 5) {
				isWin = true;
				return;
			}
		}
		for (int i = 1; (nowchess[1] - 1 + i < 15 && nowchess[2] - 1 + i < 15) && chessmap[nowchess[1] - 1 + i][nowchess[2] - 1 + i].chesskind == nowchess[0]; i++)//����
		{
			cnt++;
			if (cnt == 5) {
				isWin = true;
				return;
			}
		}
		cnt = 1;
		for (int i = -1; (nowchess[1] - 1 - i < 15 && nowchess[2] - 1 + i >= 0) && chessmap[nowchess[1] - 1 - i][nowchess[2] - 1 + i].chesskind == nowchess[0]; i--)//����
		{
			cnt++;
			if (cnt == 5) {
				isWin = true;
				return;
			}
		}
		for (int i = 1; (nowchess[1] - 1 - i >= 0 && nowchess[2] - 1 + i < 15) && chessmap[nowchess[1] - 1 - i][nowchess[2] - 1 + i].chesskind == nowchess[0]; i++)//����
		{
			cnt++;
			if (cnt == 5) {
				isWin = true;
				return;
			}
		}
	}
	return;
}
int AI_Analysis(int cnt, int btw, int dis_1, int dis_2,int i) {//���ݴ��������������ͣ���������
	int able = btw + cnt + dis_1 + dis_2;//able�жϵ�ǰ�����Ƿ��л������
	if (cnt == 5)//�������
	{
		if ((i + 1) % 2)
		{
			l5_b++;
		}
		else {
			l5_w++;
		}
		return 0;
	}
	if (cnt == 4)
	{
		if (able < 5)
		{ 
			return 0;
		}
		if (btw == 0 && (dis_1 > 0 && dis_2 > 0))
		{//�������
			if ((i + 1) % 2)
			{
				l4_b++;
			}
			else {
				l4_w++;
			}
			return 0;
		}
		else {//�������
			if ((i + 1) % 2)
			{
				d4_b++;
			}
			else {
				d4_w++;
			}
			return 0;
		}

	}
	if (cnt == 3)
	{
		if (able < 5)
		{
			return 0;
		}
		if (btw < 2 && (dis_1 > 1 && dis_2 > 1))
		{//�������
			if ((i + 1) % 2)
			{
				l3_b++;
			}
			else {
				l3_w++;
			}
			return 25;
		}
		else {//�������
			if ((i + 1) % 2)
			{
				d3_b++;
			}
			else {
				d3_w++;
			}
			return 12;
		}
	}
	if (cnt == 2)
	{
		if (able < 5)
		{
			return 0;
		}
		if (btw < 3 && (dis_1 > 1 && dis_2 > 1))
		{//������
			return 6;
		}
		else {//�߶����
			return 4;
		}
	}
	if (cnt == 1)
	{
		if (able < 5)
		{
			return 0;
		}
		else {
			return 1;
		}
	}
}
void AI_Estimate() {
	int Estimate_BLACK = 0;
	int Estimate_WHITE = 0;
	int i = 0;
	//����Ⱦ���н����Ĵα������ֱ��ÿ���Ӻ��������ζԽ��ĸ��������֣������ջ���Ϊȫ�ֺڰ׷�����
	for (int done[15][15] = { 0 }; i < count; i++)//����
	{
		int nowchess[3] = { chess_draw_list[i][0],chess_draw_list[i][1],chess_draw_list[i][2] };
		if (i == 0 || !done[nowchess[1] - 1][nowchess[2] - 1]) {
			done[nowchess[1] - 1][nowchess[2] - 1] = true;
			int pcnt = 0;//����ͳ��
			int cnt = 1;//ͬɫ����
			int btw = 0;//�����
			int dis_1 = 0;//��ɫ�Ӿ���
			int dis_2 = 0;
			int temp_dis = 0;
			for (int i = 1; i <= 4 && cnt + btw < 5; i++)//��
			{
				if (chessmap[nowchess[1] - 1 - i][nowchess[2] - 1].chesskind == abs(nowchess[0] / 2 - 2) || nowchess[1] - i < 1) {
					break;
				}
				else if (chessmap[nowchess[1] - 1 - i][nowchess[2] - 1].chesskind == nowchess[0]) {
					if (cnt + temp_dis + btw >= 5)
					{
						break;
					}
					done[nowchess[1] - 1 - i][nowchess[2] - 1] = true;
					btw += temp_dis;
					temp_dis = 0;
					cnt++;
				}
				else if (chessmap[nowchess[1] - 1 - i][nowchess[2] - 1].chesskind == EMPTY) {
					temp_dis++;
				}
			}
			dis_1 += temp_dis;
			temp_dis = 0;
			for (int i = 1; i <= 4 && cnt + btw < 5; i++)//��
			{
				if (chessmap[nowchess[1] - 1 + i][nowchess[2] - 1].chesskind == abs(nowchess[0] / 2 - 2) || nowchess[1] + i > 14) {
					break;
				}
				else if (chessmap[nowchess[1] - 1 + i][nowchess[2] - 1].chesskind == nowchess[0]) {
					if (cnt + temp_dis + btw >= 5)
					{
						break;
					}
					done[nowchess[1] - 1 + i][nowchess[2] - 1] = true;
					btw += temp_dis;
					temp_dis = 0;
					cnt++;
				}
				else if (chessmap[nowchess[1] - 1 + i][nowchess[2] - 1].chesskind == EMPTY) {
					temp_dis++;
				}
			}
			dis_2 += temp_dis;
			temp_dis = 0;
			pcnt += AI_Analysis(cnt, btw, dis_1, dis_2,i);

			if (nowchess[0] == BLACK) {
				Estimate_BLACK += pcnt;
			}
			else {
				Estimate_WHITE += pcnt;
			}
		}
	}
	i = 0;
	for (int done[15][15] = { 0 }; i < count; i++)//����
	{
		int nowchess[3] = { chess_draw_list[i][0],chess_draw_list[i][1],chess_draw_list[i][2] };
		if (i == 0 || !done[nowchess[1] - 1][nowchess[2] - 1]) {
			done[nowchess[1] - 1][nowchess[2] - 1] = true;
			int pcnt = 0;//����ͳ��
			int cnt = 1;//ͬɫ����
			int btw = 0;//�����
			int dis_1 = 0;//��ɫ�Ӿ���
			int dis_2 = 0;
			int temp_dis = 0;
			for (int i = 1; i <= 4 && cnt + btw < 5; i++)//��
			{
				if (chessmap[nowchess[1] - 1][nowchess[2] - 1 - i].chesskind == abs(nowchess[0] / 2 - 2) || nowchess[2] - i < 1) {
					break;
				}
				else if (chessmap[nowchess[1] - 1][nowchess[2] - 1 - i].chesskind == nowchess[0]) {
					if (cnt + temp_dis + btw >= 5)
					{
						break;
					}
					done[nowchess[1] - 1][nowchess[2] - 1 - i] = true;
					btw += temp_dis;
					temp_dis = 0;
					cnt++;
				}
				else if (chessmap[nowchess[1] - 1][nowchess[2] - 1 - i].chesskind == EMPTY) {
					temp_dis++;
				}
			}
			dis_1 += temp_dis;
			temp_dis = 0;
			for (int i = 1; i <= 4 && cnt + btw < 5; i++)//��
			{
				if (chessmap[nowchess[1] - 1][nowchess[2] - 1 + i].chesskind == abs(nowchess[0] / 2 - 2) || nowchess[2] + i > 14) {
					break;
				}
				else if (chessmap[nowchess[1] - 1][nowchess[2] - 1 + i].chesskind == nowchess[0]) {
					if (cnt + temp_dis + btw >= 5)
					{
						break;
					}
					done[nowchess[1] - 1][nowchess[2] - 1 + i] = true;
					btw += temp_dis;
					temp_dis = 0;
					cnt++;
				}
				else if (chessmap[nowchess[1] - 1][nowchess[2] - 1 + i].chesskind == EMPTY) {
					temp_dis++;
				}
			}
			dis_2 += temp_dis;
			temp_dis = 0;
			pcnt += AI_Analysis(cnt, btw, dis_1, dis_2,i);

			if (nowchess[0] == BLACK) {
				Estimate_BLACK += pcnt;
			}
			else {
				Estimate_WHITE += pcnt;
			}
		}
	}
	i = 0;
	for (int done[15][15] = { 0 }; i < count; i++)//����"\"
	{
		int nowchess[3] = { chess_draw_list[i][0],chess_draw_list[i][1],chess_draw_list[i][2] };
		if (i == 0 || !done[nowchess[1] - 1][nowchess[2] - 1]) {
			done[nowchess[1] - 1][nowchess[2] - 1] = true;
			int pcnt = 0;//����ͳ��
			int cnt = 1;//ͬɫ����
			int btw = 0;//�����
			int dis_1 = 0;//��ɫ�Ӿ���
			int dis_2 = 0;
			int temp_dis = 0;
			for (int i = 1; i <= 4 && cnt + btw < 5; i++)//����
			{
				if (chessmap[nowchess[1] - 1 - i][nowchess[2] - 1 - i].chesskind == abs(nowchess[0] / 2 - 2) || ((nowchess[1] - i < 1) || (nowchess[2] - i < 1))) {
					break;
				}
				else if (chessmap[nowchess[1] - 1 - i][nowchess[2] - 1 - i].chesskind == nowchess[0]) {
					if (cnt + temp_dis + btw >= 5)
					{
						break;
					}
					done[nowchess[1] - 1 - i][nowchess[2] - 1 - i] = true;
					btw += temp_dis;
					temp_dis = 0;
					cnt++;
				}
				else if (chessmap[nowchess[1] - 1 - i][nowchess[2] - 1 - i].chesskind == EMPTY) {
					temp_dis++;
				}
			}
			dis_1 += temp_dis;
			temp_dis = 0;
			for (int i = 1; i <= 4 && cnt + btw < 5; i++)//����
			{
				if (chessmap[nowchess[1] - 1 + i][nowchess[2] - 1 + i].chesskind == abs(nowchess[0] / 2 - 2) || ((nowchess[1] + i > 14) || (nowchess[2] + i > 14))) {
					break;
				}
				else if (chessmap[nowchess[1] - 1 + i][nowchess[2] - 1 + i].chesskind == nowchess[0]) {
					if (cnt + temp_dis + btw >= 5)
					{
						break;
					}
					done[nowchess[1] - 1 + i][nowchess[2] - 1 + i] = true;
					btw += temp_dis;
					temp_dis = 0;
					cnt++;
				}
				else if (chessmap[nowchess[1] - 1 + i][nowchess[2] - 1 + i].chesskind == EMPTY) {
					temp_dis++;
				}
			}
			dis_2 += temp_dis;
			temp_dis = 0;
			pcnt += AI_Analysis(cnt, btw, dis_1, dis_2,i);

			if (nowchess[0] == BLACK) {
				Estimate_BLACK += pcnt;
			}
			else {
				Estimate_WHITE += pcnt;
			}
		}
	}
	i = 0;
	for (int done[15][15] = { 0 }; i < count; i++)//����"/"
	{
		int nowchess[3] = { chess_draw_list[i][0],chess_draw_list[i][1],chess_draw_list[i][2] };
		if (i == 0 || !done[nowchess[1] - 1][nowchess[2] - 1]) {
			done[nowchess[1] - 1][nowchess[2] - 1] = true;
			int pcnt = 0;//����ͳ��
			int cnt = 1;//ͬɫ����
			int btw = 0;//�����
			int dis_1 = 0;//��ɫ�Ӿ���
			int dis_2 = 0;
			int temp_dis = 0;
			for (int i = 1; i <= 4 && cnt + btw < 5; i++)//����
			{
				if (chessmap[nowchess[1] - 1 - i][nowchess[2] - 1 + i].chesskind == abs(nowchess[0] / 2 - 2) || ((nowchess[1] - i < 1) || (nowchess[2] + i > 14))) {
					break;
				}
				else if (chessmap[nowchess[1] - 1 - i][nowchess[2] - 1 + i].chesskind == nowchess[0]) {
					if (cnt + temp_dis + btw >= 5)
					{
						break;
					}
					done[nowchess[1] - 1 - i][nowchess[2] - 1 + i] = true;
					btw += temp_dis;
					temp_dis = 0;
					cnt++;
				}
				else if (chessmap[nowchess[1] - 1 - i][nowchess[2] - 1 + i].chesskind == EMPTY) {
					temp_dis++;
				}
			}
			dis_1 += temp_dis;
			temp_dis = 0;
			for (int i = 1; i <= 4 && cnt + btw < 5; i++)//����
			{
				if (chessmap[nowchess[1] - 1 + i][nowchess[2] - 1 - i].chesskind == abs(nowchess[0] / 2 - 2) || ((nowchess[1] + i > 14) || (nowchess[2] - i < 1))) {
					break;
				}
				else if (chessmap[nowchess[1] - 1 + i][nowchess[2] - 1 - i].chesskind == nowchess[0]) {
					if (cnt + temp_dis + btw >= 5)
					{
						break;
					}
					done[nowchess[1] - 1 + i][nowchess[2] - 1 - i] = true;
					btw += temp_dis;
					temp_dis = 0;
					cnt++;
				}
				else if (chessmap[nowchess[1] - 1 + i][nowchess[2] - 1 - i].chesskind == EMPTY) {
					temp_dis++;
				}
			}
			dis_2 += temp_dis;
			temp_dis = 0;
			pcnt += AI_Analysis(cnt, btw, dis_1, dis_2,i);
			if (nowchess[0] == BLACK) {
				Estimate_BLACK += pcnt;
			}
			else {
				Estimate_WHITE += pcnt;
			}
		}
	}
	if (count % 2) {
		if (l5_w||l5_b)
		{
			if (l5_w && l5_b)
			{
				chessmap[chess_draw_list[count - 1][1] - 1][chess_draw_list[count - 1][2] - 1].chesskind = EMPTY;
				chessmap[chess_draw_list[count - 2][1] - 1][chess_draw_list[count - 2][2] - 1].chesskind = EMPTY;
				chessmap[chess_draw_list[count - 3][1] - 1][chess_draw_list[count - 3][2] - 1].chesskind = EMPTY;
				chessmap[chess_draw_list[count - 4][1] - 1][chess_draw_list[count - 4][2] - 1].chesskind = EMPTY;
				int i = 4;
				for (; !isWin && i > 0; i--)
				{
					winchack(chess_draw_list[count - i]);
					if (i % 2)
					{
						chessmap[chess_draw_list[count - i][1] - 1][chess_draw_list[count - i][2] - 1].chesskind = BLACK;
					}
					else {
						chessmap[chess_draw_list[count - i][1] - 1][chess_draw_list[count - i][2] - 1].chesskind = WHITE;
					}
				}
				i++;
				if (isWin)
				{
					if (i % 2)
					{
						Estimate_BLACK += 11000;
					}
					else {
						Estimate_WHITE += 11000;
					}
				}
				i--;
				for (; i > 0; i--)
				{
					if (i % 2)
					{
						chessmap[chess_draw_list[count - i][1] - 1][chess_draw_list[count - i][2] - 1].chesskind = BLACK;
					}
					else {
						chessmap[chess_draw_list[count - i][1] - 1][chess_draw_list[count - i][2] - 1].chesskind = WHITE;
					}
				}
				isWin = false;
			}
			else {
				if (l5_w)
				{
					Estimate_WHITE += 11000;
				}
				else {
					Estimate_BLACK += 11000;
				}
			}
		}
		else if (l4_w || d4_w)
		{
			Estimate_WHITE += 10000;
		}
		else if (l3_w && !(d4_b || l4_b))
		{
			Estimate_WHITE += 9000;
		}
		else if ((d4_b == 2) || l4_b)
		{
			Estimate_BLACK += 8000;
		}
		else if (d4_b && l3_b)
		{
			Estimate_BLACK += 7000;
		}
		else if (l3_b==2&&((!l3_w)||(!d3_w)))
		{
			Estimate_BLACK += 6000;
		}
	}
	else {
		if (l5_w || l5_b)
		{
			if (l5_w && l5_b)
			{
				chessmap[chess_draw_list[count - 1][1] - 1][chess_draw_list[count - 1][2] - 1].chesskind = EMPTY;
				chessmap[chess_draw_list[count - 2][1] - 1][chess_draw_list[count - 2][2] - 1].chesskind = EMPTY;
				chessmap[chess_draw_list[count - 3][1] - 1][chess_draw_list[count - 3][2] - 1].chesskind = EMPTY;
				chessmap[chess_draw_list[count - 4][1] - 1][chess_draw_list[count - 4][2] - 1].chesskind = EMPTY;
				int i = 4;
				for (; !isWin&&i>0 ; i--)
				{
					winchack(chess_draw_list[count - i]);
					if (i%2)
					{
						chessmap[chess_draw_list[count - i][1] - 1][chess_draw_list[count - i][2] - 1].chesskind = WHITE;
					}
					else {
						chessmap[chess_draw_list[count - i][1] - 1][chess_draw_list[count - i][2] - 1].chesskind = BLACK;
					}
				}
				i++;
				if (isWin)
					{
					if (i%2)
					{
						Estimate_WHITE += 11000;
					}
					else {
						Estimate_BLACK += 11000;
					}
				}
				i--;
				for (; i > 0; i--)
				{
					if (i % 2)
					{
						chessmap[chess_draw_list[count - i][1] - 1][chess_draw_list[count - i][2] - 1].chesskind = WHITE;
					}
					else {
						chessmap[chess_draw_list[count - i][1] - 1][chess_draw_list[count - i][2] - 1].chesskind = BLACK;
					}
				}
				isWin = false;
			}
			else {
				if (l5_w)
				{
					Estimate_WHITE += 11000;
				}
				else {
					Estimate_BLACK += 11000;
				}
			}
		}
		else if (l4_b || d4_b)
		{
			Estimate_BLACK += 10000;
		}
		else if (l3_b && !(d4_w || l4_w))
		{
			Estimate_BLACK += 9000;
		}
		else if ((d4_w == 2) || l4_w)
		{
			Estimate_WHITE += 8000;
		}
		else if (d4_w && l3_w)
		{
			Estimate_WHITE += 7000;
		}
		else if (l3_w == 2 && ((!l3_b) || (!d3_b)))
		{
			Estimate_WHITE += 6000;
		}
	}
	AI_Estimation_BLACK = Estimate_BLACK;
	AI_Estimation_WHITE = Estimate_WHITE;
	l5_b = 0;
	l5_w = 0;
	l4_b = 0;
	l4_w = 0;
	d4_b = 0;
	d4_w = 0;
	l3_b = 0;
	l3_w = 0;
	d3_b = 0;
	d3_w = 0;
}
struct judgetree* AI_Judgetree_MakeTree(int height) {//�����ӽڵ�����ʾ��
	struct judgetree* newroot = new struct judgetree;
	newroot->donepos.xpos = -1;
	newroot->donepos.ypos = -1;
	if (height % 2)
	{
		newroot->expectation = INT_MAX;
	}
	else {
		newroot->expectation = INT_MIN;
	}
	newroot->bor_node = NULL;
	newroot->kid_node = NULL;
	newroot->listend = newroot;
	return newroot;
}
void AI_Judgetree_AddNode(struct judgetree* root, chess_pos newchess, int height) {

	if (root->listend == root)
	{
		if (height % 2)
		{
			root->listend->expectation = INT_MAX;
		}
		else {
			root->listend->expectation = INT_MIN;
		}
		root->listend->donepos = newchess;
		root->listend->bor_node = AI_Judgetree_MakeTree(height);
		root->listend = root->listend->bor_node;
		return;
	}
	else {
		root->listend->donepos = newchess;
		if (height % 2)
		{
			root->listend->expectation = INT_MAX;
		}
		else {
			root->listend->expectation = INT_MIN;
		}
		root->listend->bor_node = AI_Judgetree_MakeTree(height);
		root->listend = root->listend->bor_node;
	}

}
void AI_Judgetree_BuildTree(struct judgetree* root, int height,int gd_expectation) {
	if (height < 3)//�����ʹ��GPU���ʹ�AI������ԣ���4�����Ѿ��Ǽ�����
	{
		for (int i = AI_ThinkWidth[0]; i <= AI_ThinkWidth[1]; i++)//���������ڱ������п���
		{
			for (int j = AI_ThinkWidth[2]; j <= AI_ThinkWidth[3]; j++)
			{
				if (chessmap[j][i].chesskind == EMPTY)
				{
					chess_pos adding;
					adding.xpos = j;
					adding.ypos = i;
					AI_Judgetree_AddNode(root, adding, height);
				}
			}
		}
		for (struct judgetree* i = root; i->bor_node != NULL; i = i->bor_node)
		{
			if (count % 2)
			{
				chess_draw_list[count][0] = WHITE;
				chessmap[i->donepos.xpos][i->donepos.ypos].chesskind = WHITE;
			}
			else {
				chess_draw_list[count][0] = BLACK;
				chessmap[i->donepos.xpos][i->donepos.ypos].chesskind = BLACK;
			}
			//�����п������ν���
			chess_draw_list[count][1] = i->donepos.xpos + 1;
			chess_draw_list[count][2] = i->donepos.ypos + 1;
			count++;
			i->kid_node = AI_Judgetree_MakeTree(height);
			AI_Judgetree_BuildTree(i->kid_node, height + 1,root->expectation);//�˴����еݹ�
			i->expectation = i->kid_node->expectation;
			AI_JudgeTree_Delete(i->kid_node);//ʵʱɾ�������ڴ�
			i->kid_node = NULL;
			//��֦
			if (height % 2) {
				if (i->expectation < gd_expectation)
				{
					root->expectation = INT_MIN;
					count--;
					chessmap[i->donepos.xpos][i->donepos.ypos].chesskind = EMPTY;
					return;
				}
			}
			else {
				if (i->expectation > gd_expectation)
				{
					root->expectation = INT_MAX;
					count--;
					chessmap[i->donepos.xpos][i->donepos.ypos].chesskind = EMPTY;
					return;
				}
			}
			if (height % 2)//���µ�ǰ��������ֵ
			{
				if (root->expectation > i->expectation) 
				{
					root->expectation = i->expectation;
				}
			}
			else {
				if (root->expectation < i->expectation)
				{
					root->expectation = i->expectation;
				}
			}
			count--;
			chessmap[i->donepos.xpos][i->donepos.ypos].chesskind = EMPTY;
		}
	}
	else {//������ÿ�ֿ��ܾ�������
		for (int i = AI_ThinkWidth[0]; i <= AI_ThinkWidth[1]; i++)
		{
			for (int j = AI_ThinkWidth[2]; j <= AI_ThinkWidth[3]; j++)
			{
				if (chessmap[j][i].chesskind == EMPTY)
				{
					chess_pos adding;
					adding.xpos = j;
					adding.ypos = i;
					AI_Judgetree_AddNode(root, adding, height);
				}
			}
		}
		if (count % 2)
		{
			chess_draw_list[count][0] = WHITE;
		}
		else {
			chess_draw_list[count][0] = BLACK;
		}
		for (struct judgetree* i = root; i->bor_node != NULL; i = i->bor_node)
		{
			if (count % 2)
			{
				chessmap[i->donepos.xpos][i->donepos.ypos].chesskind = WHITE;
			}
			else {
				chessmap[i->donepos.xpos][i->donepos.ypos].chesskind = BLACK;
			}
			chess_draw_list[count][1] = i->donepos.xpos + 1;
			chess_draw_list[count][2] = i->donepos.ypos + 1;
			count++;
			AI_Estimate();
			if (count % 2)
			{
				i->expectation = AI_Estimation_WHITE - AI_Estimation_BLACK;
			}
			else {
				i->expectation = AI_Estimation_BLACK - AI_Estimation_WHITE;
			}
			if (i->expectation < gd_expectation)
			{
				root->expectation = INT_MIN;
				chessmap[i->donepos.xpos][i->donepos.ypos].chesskind = EMPTY;
				count--;
				return;
			}
			count--;
			chessmap[i->donepos.xpos][i->donepos.ypos].chesskind = EMPTY;
			if (root->expectation > i->expectation)
			{
				root->expectation = i->expectation;
			}
		}
	}

}
void AI_JudgeTree_Choose(struct judgetree* root) {//ִ�д˺���ʱ����ǳ������������߼�ΪAI��������
	int expectation = INT_MIN;
	chess_pos nextchess;
	nextchess.xpos = -1;
	nextchess.ypos = -1;
	for (struct judgetree* i = root; i != root->listend; i = i->bor_node)
	{
		if (i->expectation == root->expectation)
		{
			expectation = i->expectation;
			nextchess = i->donepos;
		}
	}
	if (nextchess.xpos != -1 && nextchess.ypos != -1) {
		if (chessmap[nextchess.xpos][nextchess.ypos].chesskind == EMPTY) {
			if (count % 2) {
				chessmap[nextchess.xpos][nextchess.ypos].chesskind = WHITE;
				chess_draw_list[count][0] = WHITE;
				chess_draw_list[count][1] = nextchess.xpos + 1;
				chess_draw_list[count][2] = nextchess.ypos + 1;
			}
			else {
				chessmap[nextchess.xpos][nextchess.ypos].chesskind = BLACK;
				chess_draw_list[count][0] = BLACK;
				chess_draw_list[count][1] = nextchess.xpos + 1;
				chess_draw_list[count][2] = nextchess.ypos + 1;
			}
			if (nextchess.xpos - 1 < AI_ThinkWidth[2]) {
				AI_ThinkWidth[2] = nextchess.xpos - 3;
				if (AI_ThinkWidth[2] < 0)
				{
					AI_ThinkWidth[2] = 0;
				}
			}
			if (nextchess.xpos - 1 > AI_ThinkWidth[3]) {
				AI_ThinkWidth[3] = nextchess.xpos + 1;
				if (AI_ThinkWidth[3] > 14)
				{
					AI_ThinkWidth[3] = 14;
				}
			}
			if (nextchess.ypos - 1 < AI_ThinkWidth[0]) {
				AI_ThinkWidth[0] = nextchess.ypos - 3;
				if (AI_ThinkWidth[0] < 0)
				{
					AI_ThinkWidth[0] = 0;
				}
			}
			if (nextchess.ypos - 1 > AI_ThinkWidth[1]) {
				AI_ThinkWidth[1] = nextchess.ypos + 1;
				if (AI_ThinkWidth[1] > 14)
				{
					AI_ThinkWidth[1] = 14;
				}
			}
			count++;
		}
	}
}
void AI_JudgeTree_Delete(struct judgetree* root) {
	for (struct judgetree* i = root; i != NULL;)
	{
		struct judgetree* temp = i;
		i = i->bor_node;
		if (!(temp->kid_node))
		{
			delete temp;
		}
		else {
			AI_JudgeTree_Delete(temp->kid_node);
			delete temp;
		}
	}
	return;
}
void AI_Running() {
	struct judgetree* judgetree = AI_Judgetree_MakeTree(0);
	AI_Judgetree_BuildTree(judgetree, 0,INT_MAX);
	AI_JudgeTree_Choose(judgetree);
	AI_JudgeTree_Delete(judgetree);
	return;
}