/*
表达式运算基本思想：
数据处理：有两个栈，一个保存操作数，一个保存操作符；
计算过程：从左到右顺序遍历表达式字符串
1、当前形成操作数入栈 ；
2、当前是操作符，符号栈判空
栈不空时且栈顶符号优先级>=当前优先级：就将操作数栈中的前2个操作数拿出来运算，并删除，然后把算出来的结果压入操作数栈；
当前符号均入栈； 
**/ 
#include<bits/stdc++.h>
using namespace std;
//判断是操作符返回1，数字、小数点返回0 
int isOperate(char ch){
	if(ch=='+'||ch=='-'||ch=='*'||ch=='/'){
		return 1;
	}else return 0;
}
//判断符号优先级
int prior(char ch){
	if(ch=='-'||ch=='+')return 1;
	else return 2;
}
//四则运算
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
			//sscanf(numstr.c_str(),"%lf","&num1");//不行 
			num1=stod(numstr);
			//num1=atof(numstr.c_str());可以 
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


