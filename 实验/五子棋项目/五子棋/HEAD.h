#ifndef _HEAD_
#define _HEAD_

#include<iostream>
#include<stdlib.h>
#include<Windows.h>
#define GLEW_STATIC
#include<GL/glew.h>
#include<GLFW/glfw3.h>
#include<math.h>
#include<queue>
extern int gamemode;
const int windowWidth = 720;
const int windowHeight = 720;
const enum kind { EMPTY, WHITE, BLACK };
struct chess {//����
	int chesskind = EMPTY;
};
extern chess chessmap[15][15];//�����߼��жϵ�����

struct chess_pos {
	int xpos;
	int ypos;
};

struct formstatistic {//���ھ�������ͳ��
	int l5_b = 0;//����
	int l5_w = 0;
	int l4_b = 0;//����
	int l4_w = 0;
	int d4_b = 0;//����
	int d4_w = 0;
	int l3_b = 0;//����
	int l3_w = 0;
	int d3_b = 0;//����
	int d3_w = 0;
	int l2_b = 0;//���
	int l2_w = 0;
	int d2_b = 0;//����
	int d2_w = 0;
};

struct judgetree {//������
	chess_pos donepos;
	int expectation;
	int gd_expectation;
	struct judgetree* bor_node;
	struct judgetree* kid_node;
	struct judgetree* listend;
};

extern int AI_ThinkWidth[4];//����AIѡȡ�ֲ����Ž�ķ�Χ,0~4�ֱ�Ϊ��������
extern chess_pos chess_pos_cursor;
extern int count;
extern bool isWin;
extern int chess_draw_list[15 * 15][3];
void winchack(int nowchess[3]);
struct judgetree* AI_MakeTree();
int AI_Analysis(int cnt, int btw, int dis_1, int dis_2);//���ͷ�������
int AI_Calculation(struct formstatistic);//���ֺ���
void AI_Estimate();//��������
void AI_Judgetree_BuildTree(struct judgetree* root, int height);//������������
void AI_JudgeTree_Choose(struct judgetree* root);
void AI_JudgeTree_Delete(struct judgetree* root);
void AI_Running();
#endif 