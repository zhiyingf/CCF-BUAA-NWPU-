

//�ַ�������Ϊgetline����  

#include <iostream>  

using namespace std;  

int main()  

{  

        char ch[20];  

        cout << "enter a sentence:" << endl;  

        //cin.getline(ch , 20 , '/');  
        cin.getline(ch,20);  
        //getline(ch,20); �� 

        cout << "The sentence is:" << ch << endl;  

        return 0;  

}

/*
//�ַ�����Ϊgetline����  

#include <iostream>  

#include <string>  

using namespace std;  

int main()  

{  

        string str;  
        int x;

        cout << "enter a sentence:" << endl; 
		cin>>x; 
		getchar();//���ջس� 
		getline(cin , str);  
        //getline(cin , str , '/');  

        cout << "The sentence is:" << str << endl;  

        return 0;  

}  
*/
/*
//�ַ�����Ϊgetline����  

#include <iostream>  

#include <string>  

using namespace std;  

int main()  

{  

        //string str;  
        char str[20];

        cout << "enter a sentence:" << endl;  

        //getline(cin , str , '/'); 
		gets(str); 

        cout << "The sentence is:" << str << endl;  

        return 0;  

}  */
