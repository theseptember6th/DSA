#include<iostream>
using namespace std;

int Factorial_(int num){
    if(num<0){
        cout<<"\nINVALID NUMBER FOR FACTORIAL.EXITING...";
        exit(0);
    }
    if(num==1 || num==0){
        return 1;
    }
    int factorial=1;
    for(int i=1;i<=num;i++){
        factorial=factorial*i;
    }
    return factorial;
}
int main(){
    int number;
  cout<<"\nenter the factorial you want to find: ";
  cin>>number;
  int result=Factorial_(number);
  cout<<"\nthe factorial is "<<result;
return 0;
}