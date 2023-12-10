#include<iostream>
using namespace std;

void display(int*stack,int*x){
     cout<<"\nDISPLAYING THE STACK\n";
     for(int i=0;i<=*x;i++){
           cout<<" "<<stack[i]<<" ";
     }
}



void push(int*stack,int*x,int size){
    if(*x==size-1){
        int choice;
        cout<<"STACK FULL\n";
        // cout<<"\n PRESS 1 to increase the size\n";
        // cin>>choice;
        // if(choice){
        //     int extra;
        //     cout<<"\n Enter the size you want to be further added\n";
        //     cin>>extra;
        //     int *stack1=new int [size+extra];
        //     delete [] stack;
        //     stack=stack1;

        // }
    }
    else{
        int item;
        cout<<"\n ENTER THE ITEM TO BE INSERTED/PUSHED\n";
        cin>>item;
        (*x)++;
        stack[*x]=item;
    }
}

int pop(int *stack,int*x){
    if(*x==-1){
        cout<<"stack empty";
        return 0;
    }
    else{
        int deleted =stack[*x];
        (*x)--;
        return deleted;
    }

}


int main(){
    int size;
    int top=-1;
    cout<<"\nEnter the size for the stack\n";
    cin>>size;
    int *stack=new int[size];
    int choice;
    int deleted_item=0;
    while(1){
        cout<<"\nPRESS 1 TO PUSH\t";
        cout<<"\tPRESS 2 TO POP\n";
        cout<<"PRESS 3 TO DISPLAY\t";
        // cout<<"PRESS  TO INCREASE SIZE\t";
        cout<<"\nPRESS 4 TO EXIT \n";
       
        
        

        cin>>choice;

        switch(choice){
            case 1:
            push(stack,&top,size);
            break;
            
            case 2:
            deleted_item=pop(stack,&top);
            if(deleted_item){
            cout<<"\n THE DELETED ITEM IS "<<deleted_item;
            }
            break;

            case 3:
            display(stack,&top);
            break;

        
            case 4:
            cout<<"\n......EXITING......\n";
            cout<<"\n DELETING THE STACK\n";
             delete [] stack;
            exit(0);

            


            default:
            cout<<"\nINVALID CHOICE\n";
            break;


            
        }
       
    }
    







    delete [] stack;

   return 0;
}