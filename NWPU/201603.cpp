/*
���ʽ�������˼�룺
���ݴ���������ջ��һ�������������һ�������������
������̣�������˳��������ʽ�ַ���
1����ǰ�γɲ�������ջ ��
2����ǰ�ǲ�����������ջ�п�
ջ����ʱ��ջ���������ȼ�>=��ǰ���ȼ����ͽ�������ջ�е�ǰ2���������ó������㣬��ɾ����Ȼ���������Ľ��ѹ�������ջ��
��ǰ���ž���ջ�� 
**/ 
#include<bits/stdc++.h>
using namespace std;
//�ж��ǲ���������1�����֡�С���㷵��0 
int isOperate(char ch){
	if(ch=='+'||ch=='-'||ch=='*'||ch=='/'){
		return 1;
	}else return 0;
}
//�жϷ������ȼ�
int prior(char ch){
	if(ch=='-'||ch=='+')return 1;
	else return 2;
}
//��������
double isWhatComputer(char ch,double n1,double n2){
	if(ch=='+'){
		return n1+n2;
	}else if(ch=='-'){
		return n1-n2;
	}else if(ch=='*'){
		return n1*n2;
	}else if(ch=='/'){
		//cout<<"*"<<n1<<"*"<<n2<<"*"<<endl;
		//cout<<"*"<<n1/n2<<"*"<<endl;
		return n1/n2;
	}
}

int computer(string str){
	stack<char>op;
    stack<double>num;
	int sz=str.size();
	string numstr="";
	double num1,num2,num3;
	char temp; 
	for(int i=0;i<sz;i++){
		if(!isOperate(str[i])){
			numstr+=str[i];
		}else{
			//sscanf(numstr.c_str(),"%lf","&num1");//���� 
			num1=stod(numstr);
			//num1=atof(numstr.c_str());���� 
			num.push(num1);
			numstr="";
			
			if(!op.empty()){
				temp=op.top();
				if(prior(temp)>=prior(str[i])){
					op.pop();
					num2=num.top();num.pop();
					num1=num.top();num.pop();
					num3=isWhatComputer(temp,num1,num2);
					num.push(num3);
			    }
			}
			op.push(str[i]);
		}
	}
	
	num1=atof(numstr.c_str());
	//cout<<"**end"<<num1<<"**end"<<endl;
	num.push(num1);
	numstr="";
	
	while(!op.empty()){
		temp=op.top();op.pop();
		num2=num.top();num.pop();
		num1=num.top();num.pop();
		num3=isWhatComputer(temp,num1,num2);
		num.push(num3);
	}
	//printf("%.1f\n",num.top());
	if(num.top()-int(num.top())<=1e-6) printf("%.0f\n",num.top());
    else printf("%.1f\n",num.top());
	return 0;
}
 
int main(){
	int n;
	cin>>n;
	while(n--){
		string str;
        cin>>str;
        computer(str);
	}
	return 0;
}


