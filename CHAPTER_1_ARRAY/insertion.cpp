#include<iostream>
using namespace std;
 
int main(){
    int arr[100],position,n,new_element;
    cout<<"\n enter the no of elements you want to enter\n";
    cin>>n;
    cout<<"\n enter the elements\n";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"Enter the position you want to insert an element\n";
    cin>>position;
    cout<<"\n Enter the element you want to add\n";
    cin>>new_element;
    for(int i=n-1;i>=position-1;i--){
        arr[i+1]=arr[i];
    }
    arr[position-1]=new_element;
    n++;
    for(int i=0;i<n;i++){
        cout<<" "<<arr[i]<<" ";
    }


}