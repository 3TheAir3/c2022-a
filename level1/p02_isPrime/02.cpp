#include<stdio.h>
#include<stdbool.h>
int main(){
	int N;
	bool isPrime=true;
	printf("����һ������");
	scanf("%d",&N);
	for(int i=2;i<=N/2;i++){//һ����N�������д���N/2�������ӣ���Ϊ2����С�������ӣ�
		if(!(N%i)){//ѭ���б�i�Ƿ�ΪN��������
			isPrime=false;
			break;
		}
	}
	if(!isPrime||N==1){
		printf("It is not prime");
	}else{
		printf("It is prime");
	}
	return 0;
}
