#include<iostream>
#include<cstring>
using namespace std;

void INPUT(char *infix){
    cout<<"\nEnter the infix ";
    cin>>infix;
    
}

int precedence(char infix){
    char ch=infix;
     int value=0;
            switch(ch){
                case '$':
                case '^':
                value=3;
                return value;

                case '*':
                case '/':
                value=2;
                return value;
               

                case '+':
                case'-':
                value=1;
               return value;

                default:
                cout<<"\ninvalid operator\n";
                return value;
            }
}


void CONVERT(char *infix,char*poststack,int *top_poststack,char*operatorstack,int *top_operatorstack){
    
    int value;
     int length=strlen(infix);
     for(int i=0;i<length;i++){
        if(infix[i]=='('){
               (*top_operatorstack)++;
               operatorstack[*top_operatorstack]=infix[i];
        }
        else if(isalpha(infix[i])){
            *(top_poststack)++;
            poststack[*top_poststack]=infix[i];
        }
        else if(infix[i]==')'){
               while(operatorstack[*top_operatorstack]=='('){
                  *(top_poststack)++;
                  poststack[*top_poststack++]=operatorstack[*top_operatorstack];
                  *(top_poststack)--;
               }
               *(top_poststack)--;
        }
            
        
        else {
            
            while(*top_operatorstack!=-1 && precedence(operatorstack[*top_operatorstack]) >= precedence(infix[i])){
                  poststack[*top_poststack]=operatorstack[*top_operatorstack];
                   *(top_operatorstack)--;
                   *(top_operatorstack)++;
                   operatorstack[*top_operatorstack]=infix[i];
            }
            *(top_operatorstack)++;
            operatorstack[*top_operatorstack] = infix[i];
            
        }
    
    

        
     }

     

     while(*top_operatorstack!=-1){
        (*top_poststack)++;
        poststack[*top_poststack]=operatorstack[*top_operatorstack];
        (*top_operatorstack)--;

     }

    
}
         


void DISPLAY(char *poststack,int *top_poststack){
          for(int i=0;i<=*top_poststack;i++){
            cout<<poststack[i]<<" ";
          }
}



int main(){
    char infix[100];
    char poststack[100];
    int top_poststack=-1;
    char operatorstack[100];
    int top_operatorstack=-1;
    INPUT(infix);
    CONVERT(infix,poststack,&top_poststack,operatorstack,&top_operatorstack);
    DISPLAY(poststack,&top_poststack);
    

    return 0;
}