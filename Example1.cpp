#include<vector>
#include<string>
#include<iostream>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string> &tokens){ 
        int j=0;
    	int result;
	while(tokens.size()!=1){
            if(Is_num(tokens[j])){
                j++;
            }
            else{
		int a,b;
                a=atoi(tokens[j-2].c_str());//把string数字变为int
                b=atoi(tokens[j-1].c_str());//把string数字变为int
                result=Judge(a,b,tokens[j]);               
                tokens.erase(tokens.begin()+j-2,tokens.begin()+j+1);//清除运算后数字和符号
		char c[20];
		my_itoa(result,c);//int to char
		//_itoa(result,c,10);//int to char
		if(tokens.size()!=0){
			int k=j-2;
			tokens.insert(tokens.begin()+k,string(c)); //插入新运算后符号
		}
		else
			tokens.push_back(string(c));
                j=0;
            }
        }
    	cout<<atoi(tokens[0].c_str())<<endl;
	return atoi(tokens[0].c_str());
    }
public:
    int Judge(int a,int b,string c){ //判断运算
        if(c=="+") return a+b;
		else if(c=="-") return a-b;
        else if(c=="*") return a*b;
        else if(c=="/") return a/b;
    }
	bool Is_num(string a){          //判断是否为数字
		int i;
		for(i=0;i<a.size();i++)
			if(a[i]<'0'||a[i]>'9') break;
		if (i>=a.size()) return true;
		else return false;
	}
	void my_itoa(int n,char a[]){    // int to char
		if(n==0) {
			a[0]='0';a[1]='\0';
			return;
		}
		int i=0;
		while(n!=0){
			a[i]=char(n%10+'0');
			n/=10;
			i++;
		}

		for(int j=0;j<=(i-1)/2;j++)
			swap(a[j],a[i-1-j]);
		a[i]='\0';
	}
};
int main(){
	string a[]={"4", "13","5","+"  ,"5", "/", "+"};
	vector<string> m; 
	for(int i=0;i<7;i++)
		m.push_back(a[i]);
	Solution x;
	x.evalRPN(m);


	return 0;
}
