//����̫���㸴�Ӷȣ����Ӧ����O(N^2)��
//��ͷ������Ĭ�϶����������������Ͱ���ǽ�������֣����õ�������Ͱ�����Ϊ�����ӵĺ�����Ͱ���ŵ�
//������һ���ɸ����
#include<stdio.h>
#include<stdbool.h>
#include<time.h>
bool NotPrime[1000]={};
int main(){
	clock_t start,end;
	start=clock();
	int cnt=0;
	for(int i=2;i<=1000;i++){
		if(!NotPrime[i-1]){
			cnt++;
			printf("%d\n",i);
			for(int j=2;i*j<=1000;j++){
				NotPrime[i*j-1]=true;
			}
		}
	}
	printf("The all primes are:%d\n",cnt);
	end=clock();
	printf("time cost:%ldms",end-start);
}
//1000:144 196 139 165 153 168
//2000:268 293 296 288 239 246
//4000:467 447 462 455 438 455
//8000:746 808 813 700 807 777
//��ʵ�����������ƺ�����O(N)��...��Ϊû��ʵ�ʱ��������飨����ʡ���Ĳ��ֻ�ͦ�ࣩ
