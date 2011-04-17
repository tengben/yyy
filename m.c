#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct node
{
    int number;
    char name[20];
    //char score;
    struct node *next;
};
typedef struct node V_NODE;//起个新名字
V_NODE *create_link(int n);
void print_link(V_NODE *head);

int main(void)
{
    V_NODE *head;
    int n = 0;
    printf("Input a number\n");
    scanf("%d",&n);

    head = create_link(n);
    print_link(head);
    
    //V_NODE stu;//struct node = V_NODE
    //
    //V_NODE *ptr = NULL;
    //
    //
    //ptr = &stu;
    //printf("Please input number:\n");
    //scanf("%d",&ptr->number);
    //printf("name\n");
    //scanf("%s",ptr->name);
    //getchar();
    //printf("score\n");
    //scanf("%c",&ptr->score);

    //ptr->number = 2;
    //stu.number = 2;
    //strcpy(ptr->name,"xu");
    //ptr->score = 80;
    //printf("number: %d\tname:%s\tscore:%c\n",ptr->number,ptr->name,ptr->score);
    return 0;
}

V_NODE *create_link(int n)
{
    V_NODE *p = NULL;
    V_NODE *head = NULL;
    int i = 0;
    p = head = malloc(sizeof(V_NODE));
    if (p==NULL) 
    {
        perror("malloc");
        exit(0);
    }
    p->number = 1;
    strcpy(p->name,"a");
    p->next = NULL;

    for (i = 0; i < n; i++) 
    {
        p->next = malloc(sizeof(V_NODE));
        if (p->next == NULL) 
        {
            perror("malloc");
            exit(0);

        }
        p->next->number = i+1;
        strcpy(p->next->name,"a");
        p->next->next = NULL;
        p = p->next;
    }
    return head;
}

void print_link(V_NODE *p)
{
    while (p != NULL) 
    {
        printf("%d\t%s\n",p->number,p->name);
        p = p->next;
    }
}
