#include<iostream>
using namespace std;
 
int main(){
    int arr[100],position,n;
    cout<<"\n enter the no of elements you want to enter\n";
    cin>>n;
    cout<<"\n enter the elements\n";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"Enter the position you want to delete an element\n";
    cin>>position;
    for(int i=position-1;i<=n-1;i++){
        arr[i]=arr[i+1];
    }
    n--;
    for(int i=0;i<n;i++){
        cout<<" "<<arr[i]<<" ";
    }


}