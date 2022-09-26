#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<w32api.h>
#include<stdbool.h>
//#include<graphics.h>
#define N 16
bool isWin=false;//��Ϸ�����ж�
struct location{//�����
	int x;
	int y;
};
char** right(char** map,struct location* player){
	if(player->x==N||map[player->y-1][player->x]=='X'){//����·�������
		return map;
	}
	if(map[player->y-1][player->x]=='!'){
		isWin=true;
		map[player->y-1][player->x]=map[player->y-1][player->x-1];
		map[player->y-1][player->x-1]=' ';
		player->x+=1;
		return map;
	}
	char temp=map[player->y-1][player->x-1];
	map[player->y-1][player->x-1]=map[player->y-1][player->x];
	map[player->y-1][player->x]=temp;
	player->x+=1;
	return map;
}
char** left(char** map,struct location* player){
	if(player->x==1||map[player->y-1][player->x-2]=='X'){
		return map;
	}
	if(map[player->y-1][player->x-2]=='!'){
		isWin=true;
		map[player->y-1][player->x-2]=map[player->y-1][player->x-1];
		map[player->y-1][player->x-1]=' ';
		player->x-=1;
		return map;
	}
	char temp=map[player->y-1][player->x-1];
	map[player->y-1][player->x-1]=map[player->y-1][player->x-2];
	map[player->y-1][player->x-2]=temp;
	player->x-=1;
	return map;
}
char** down(char** map,struct location* player){
	if(player->y==N||map[player->y][player->x-1]=='X'){
		return map;
	}
	if(map[player->y][player->x-1]=='!'){
		isWin=true;
		map[player->y][player->x-1]=map[player->y-1][player->x-1];
		map[player->y-1][player->x-1]=' ';
		player->y+=1;
		return map;
	}
	char temp=map[player->y-1][player->x-1];
	map[player->y-1][player->x-1]=map[player->y][player->x-1];
	map[player->y][player->x-1]=temp;
	player->y+=1;
	return map;
}
char** up(char** map,struct location* player){
	if(player->y==1||map[player->y-2][player->x-1]=='X'){
		return map;
	}
	if(map[player->y-2][player->x-1]=='!'){
		isWin=true;
		map[player->y-2][player->x-1]=map[player->y-1][player->x-1];
		map[player->y-1][player->x-1]=' ';
		player->y-=1;
		return map;
	}
	char temp=map[player->y-1][player->x-1];
	map[player->y-1][player->x-1]=map[player->y-2][player->x-1];
	map[player->y-2][player->x-1]=temp;
	player->y-=1;
	return map;
}
//�ƶ������������ǿ���Ƶ��ˢ��ʵ���ƶ����������Ե�ˢ���ʲ��ߵ�ʱ��ͻ���ִ������˵��������ţ���
//win32api��GetAsyncKeyState������ʶ�����ʱ���̵Ĵ������
void move(char** map,struct location* player){
	int direction;
		direction=GetAsyncKeyState(VK_UP);
		if(direction==-32768){//����INT16_MIN�����ð������ڰ���״̬
			up(map,player);
		}
		direction=GetAsyncKeyState(VK_DOWN);
		if(direction==-32768){
			down(map,player);
		}
		direction=GetAsyncKeyState(VK_LEFT);
		if(direction==-32768){
			left(map,player);
		}
		direction=GetAsyncKeyState(VK_RIGHT);
		if(direction==-32768){
			right(map,player);
		}
}
void printMap(char** map){
	for(int j=0;j<N;j++){
		for(int i=0;i<N;i++){
			printf("%c",map[j][i]);
		}
		printf("\n");
	}
}
int main(){
	char** map;
	map=(char**)malloc(N*sizeof(char*));
	for(int i=0;i<N;i++){
		map[i]=(char*)malloc(N*sizeof(char));
	}
	struct location player;
	player.x=2;
	player.y=2;
	FILE* fmap;
	fmap=fopen("test.txt","r");//ֻ��ģʽ
	if(fmap){//�ж��Ƿ��������ļ�
		for(int j=0;j<N;j++){
			for(int i=0;i<N;i++){
				map[j][i]=getc(fmap);
			}
			getc(fmap);
		}
	}else{
		printf("fail");
		return -1;
	}
	while(1){//����unity��update()�Ĵ���
		Sleep(10);
		move(map,&player);
		printMap(map);
		if(isWin){
			printf("\nyou win!\n");
			break;
		}
		system("cls");
	}
	for(int i=0;i<N;i++){//�ͷ��ڴ�
		free(map[i]);
	}
	free(map);
	return 0;
}
