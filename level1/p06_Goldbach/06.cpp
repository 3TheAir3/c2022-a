//�ڰ�1�ų�������֮��󣬡���°ͺղ�����ִ�����Ϊ����һ����5����������д����������֮�͡���
//д��̫����...
#include<stdio.h>
#include<malloc.h>
#include<stdbool.h>
void primeIn100(bool** con);
int main(){
	int now;
	bool checked[100]={};
	bool* notPrime;
	primeIn100(&notPrime);
	int primes[50];
	int cnt=0;
	for(int i=1;i<100;i++){//��ȡ����
		if(!notPrime[i]){
			primes[cnt]=i+1;
			cnt++;
		}
	}
//��°ͺղ���ĵȼ۱���Ϊ�������ִ��ż�����Ա�ʾΪ������֮��
	for(int i=6;i<=100;i++){
		if(i%2){//����=3+ż��
			 now=i-3;
			 for(int j=0;j<cnt;j++){//��������
			 	for(int k=0;k<cnt;k++){
				 	if(primes[j]+primes[k]==now){
					 	printf("%d=3+%d+%d\n",i,primes[j],primes[k]);
						checked[i-1]=true;
						break;
					 }
				 }
				if(checked[i-1]){//���룬�о�д�����ľ������
					break;
				}
			 }
		}else{//ż��=2+ż��
			now=i-2;
			for(int j=0;j<cnt;j++){
				for(int k=0;k<=cnt;k++){
					if(primes[j]+primes[k]==now){
						printf("%d=2+%d+%d\n",i,primes[j],primes[k]);
						checked[i-1]=true;
						break;
					}
				}
				if(checked[i-1]){
					break;
				}
			}
		}
	}
	return 0;
}
void primeIn100(bool** con){//������05
	*con=(bool*)malloc(100*sizeof(bool));
	for(int i=0;i<100;i++){
		(*con)[i]=false;
	}
	int cnt=0;
	for(int i=2;i<=100;i++){
		if(!(*con)[i-1]){
			cnt++;
			for(int j=2;i*j<=100;j++){
				(*con)[i*j-1]=true;
			}
		}
	}
}
