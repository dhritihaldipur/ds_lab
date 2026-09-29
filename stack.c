# include <stdio.h>
#define MAX 5

int stack[MAX];
int top=-1;

void push(int value)
{
    if(top==MAX-1)
        printf("Stack Overflow\n");
    else
    {
        top++;
        stack[top]=value;
        printf("Value Pushed");
    }

}

void pop()
{
    if(top==-1)
        printf("Stack Underflow\n");
    else{
        printf("Element Poppped\n");
        top--;
    }
}
void display()
{
    if (top==-1)
        printf("Stack Empty");
    else
    {
        for(int i=top;i>=0;i--)
        {
            printf("%d\n",stack[i]);
        }
    }
}

int main()
{
    int choice,value;
    while(1)
    {
        printf("Stack Menu:\n");
        printf("1.Push\n");
        printf("2.Pop\n");
        printf("3.Display\n");
        printf("4.Exit\n");

        printf("Enter choice: ");
        scanf("%d",&choice);

        switch (choice)
        {
        case 1:
            printf("Enter Value: ");
            scanf("%d",&value);
            push(value);
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            return 0;

        }
    }
}
