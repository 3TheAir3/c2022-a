#include<stdio.h>
#include<math.h>
//����û��������ĸ�Ч�㷨...
int main(){
	int a;
	int b;
	int c;
	int cnt=0;
	for(a=1;a<=9;a++){
		for(b=0;b<=9;b++){
			for(c=0;c<=9;c++){
				if(a*100+b*10+c==pow(a,3)+pow(b,3)+pow(c,3)){
					cnt++;
					printf("��%d��ˮ�ɻ���Ϊ��%d%d%d\n",cnt,a,b,c);
				}
			}
		}
	}
	return 0;
}
