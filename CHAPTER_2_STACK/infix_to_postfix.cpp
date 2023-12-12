#include<iostream>
#include<cstring>
using namespace std;

void DISPLAY(char array[], int x) {
    for (int i = 0; i <= x; i++) {
        cout << array[i];
    }
}

int precedence(char ch) {
    switch (ch) {
    case '$':
    case '^':
        return 4;
        break;

    case '*':
    case '/':
        return 3;
        break;

    case '+':
    case '-':
        return 2;
        break;

    default:
        
        return 1;
    }
}

void push(char infix1, char array2[], int* x) {
    (*x)++;
    array2[*x] = infix1;
}

char pop(char array[], int* x) {
    char chh = array[*x];
    (*x)--;
    return chh;
}

void CONVERT(char infix[], int len, char operatorstack[], char poststack[]) {
    int tpos = -1;  // top of operator stack
    int tpps = -1;  // top of post stack

    for (int i = 0; i < len; i++) {
        if (infix[i] == '(') {
            push(infix[i], operatorstack, &tpos);
        } else if (isalpha(infix[i])) {
            push(infix[i], poststack, &tpps);
        } else if (infix[i] == ')') {
            while (operatorstack[tpos] != '(') {
                char ch = pop(operatorstack, &tpos);
                push(ch, poststack, &tpps);
            }
            pop(operatorstack, &tpos);  // pop '('
        } else {
            while (tpos != -1 && precedence(operatorstack[tpos]) >= precedence(infix[i])) {
                char ch = pop(operatorstack, &tpos);
                push(ch, poststack, &tpps);
            }
            push(infix[i], operatorstack, &tpos);
        }
    }

    while (tpos != -1) {
        char ch = pop(operatorstack, &tpos);
        push(ch, poststack, &tpps);
    }

    DISPLAY(poststack, tpps);
}

int main() {
    char operatorstack[100];
    char poststack[100];
    char infix[100];
    int length;

    cout << "\nEnter the valid infix expression\n";
    cin >> infix;
    length = strlen(infix);
    CONVERT(infix, length, operatorstack, poststack);

    return 0;
}
