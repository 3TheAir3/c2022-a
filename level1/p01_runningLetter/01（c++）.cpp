//������Ϊc++����㣬���������˼��С���
//���������string������ջ�����ķ�������ǰ��׼���ù���һ�е�ջ���ַ�����֮�������
//������ջ�ﵹ�ھ���
#include<stdlib.h>
#include<string>
#include<stack>
#include<iostream>
using namespace std;
int main(){
	string TheString;
	stack<string> Strings;
	stack<string> ReStrings;
	cin>>TheString;
	Strings.push(TheString);
	int len=TheString.length();
	for(int i=0;i<118-len;i++){
		TheString=' '+TheString;
		Strings.push(TheString);
		cout<<TheString;
		system("cls");
	}
	while(1){
		while(!Strings.empty()){
			cout<<Strings.top();
			ReStrings.push(Strings.top());
			Strings.pop();
			system("cls");
		}
		while(!ReStrings.empty()){
			cout<<ReStrings.top();
			Strings.push(ReStrings.top());
			ReStrings.pop();
			system("cls");
		}
	}
	return 0;
}
