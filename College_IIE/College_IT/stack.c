#include<stdio.h>
#define max_size 4

int stack[max_size];
int top = -1;

void push(int element){
    if (top == max_size - 1){
        printf("Stack Overflow\n");
        return;
    }
    else {
        top++;
        printf("Enter the value: ");
        scanf("%d", &element);
        stack[top] = element;
        printf("Successfully push element...\n");
    }
}

void pop(){
    if (top == -1){
        printf("Stack underflow\n");
        return;
    }
    else {
        int data = stack[top];
        top--;
        printf("%d data is remove from the stack\n", data);
    }
}

void print(){
    if (top == -1){
        printf("Stack underflow\n");
        return;
    }
    else {
        printf("The all elements are: \n");
        for (int i = top; i > -1; i--){
            printf("Element %d is : %d \n", i + 1, stack[i]);
        }
    }
}

int main(){
    // Stack implementation
    
    // push function
    push(10);
    push(15);
    push(3);
    push(54);
    print();
    // for (int i = 0; i < max_size; i++){
    //     printf("Element %d is : %d \n", i + 1, stack[i]);
    // }
    pop();
    pop();
    pop();
    // for (int i = 0; i < max_size; i++){
    //     printf("Element %d is : %d \n", i + 1, stack[i]);
    // }
    print();
}