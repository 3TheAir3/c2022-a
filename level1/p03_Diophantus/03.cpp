#include<stdio.h>
const int ages=6*12*7*2;//��ֹ�ø���������ݶ�ʧ��������һ�����з�����ĸ����С������
						//ͬʱע�⵽���ages���ճ���Ӧ�ñ������������������Ա�Ȼ��
						//��������ķŴ�
int main(){
	int childage;
	int teenage;
	int bachelor;
	int sondeath;
	int rAge;
	childage=ages/6;
	teenage=ages/12;
	bachelor=ages/7;
	sondeath=ages/2;
	int nineyears=ages-childage-teenage-bachelor-sondeath;
	//�ų���ages�����з�����ʾ������
	//���õ�������9�꣨nineyears�Ǳ��Ŵ��9�꣩
	rAge=ages/(nineyears/9);//����Ŵ�����Ȼ����ȥ��ages���õ���ʵ����;
	printf("������ͼ��ʱ����������Ϊ��%d",rAge-4);
	return 0;
}
