#include<iostream>
#include<vector>
using namespace std;

class my_class{
public:
int SOME_value;
my_class(int x){SOME_value=x;}
void DoStuff(){for(int i=0;i<10;i++){cout<<"number:"<<i<<endl;}}
};

int  ADD_NUMBERS(int A,int b){return A+b;}

int main(){my_class OBJ(5);OBJ.DoStuff();int Result=ADD_NUMBERS(10,20);
if(Result>10)cout<<"big"<<endl;else cout<<"small"<<endl;return 0;}
