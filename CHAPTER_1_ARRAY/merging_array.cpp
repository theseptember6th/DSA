#include<iostream>
using namespace std;
 
int main(){
   int *arr1,*arr2,*merg,size1,size2,position=0;
   cout<<"\nenter the size for the array 1\n";
   cin>>size1;
   arr1=new int[size1];
    cout<<"\nenter the size for the array 2\n";
   cin>>size2;
   arr2=new int[size2];

   merg=new int[size1+size2];
   
   cout<<"\n enter the elements of the array 1\n";
   for(int i=0;i<size1;i++){
     cin>>arr1[i];

   }
   cout<<"\nenter the elements of the array 2\n";
   for(int i=0;i<size2;i++){
     cin>>arr2[i];

   }
   cout<<"\n Merging two arrays \n";
     for(int i=0;i<size1;i++){
         merg[i]=arr1[i];
         position=i;
   }
   for(int i=0;i<size2;i++){
     merg[position+1]=arr2[i];
     position++;

   }
   // displaying the merged resulting array
   for(int i=0;i<size1+size2;i++){
    cout<<" "<<merg[i]<<" ";
   }

     
     delete[] arr1;
     delete[] arr2;
     delete[] merg;
}