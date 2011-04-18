#include <stdio.h>
#include<stdlib.h>
struct node
{
    int number;
    struct node *next;
};

typedef struct node V_NODE;

V_NODE *init_link(int n)
{
    V_NODE *head = NULL;
    V_NODE *p = NULL;
    if (n<=0) 
    {
        return NULL;
    }

    head = p = malloc(sizeof(V_NODE));
    if (p == NULL) 
    {
        perror("malloc");
        exit(0);
    }
    p->number = 1;
    p->next = NULL;
    int i = 0;
    for (i = 1 ; i < n; i++) 
    {
        p->next = malloc(sizeof(V_NODE));
        if (p->next == NULL) 
    {
         perror("malloc");
         exit(0);
    }
    p->next->number = i+1;
    p->next->next = NULL;
    p = p->next;

    }
    p->next = head;
    return p;
}
void print_link(V_NODE *p,int n)
{
    int i = 0;
    for (i = 0; i < n; i++) 
    {
        printf("%6d",p->number);
        if ((i+1)%10 == 0) 
        {
                printf("\n");
        }
        p = p->next;
        
    }
    printf("\n");
}
void game_doing(V_NODE *follow)
{
    V_NODE *p = follow->next;
    int interval = 3;
    int counter = 0;
    printf("input the interval:\n");
    scanf("%d",&interval);
    while (follow != follow->next) 
    {
            counter++;
            if(counter == interval)
            {
                    counter = 0;
                    printf("%6d(out)\n",p->number);
                    follow->next = p->next;
                    free(p);
                    p = follow->next;
            }
            else
            {
                    printf("%6d",p->number);
                    p = p->next;
                    follow = follow->next;
            }
    }
    printf("%5d,left!",follow->number);
    printf("\n");

}
int main(int argc, const char *argv[])
{
    //V_NODE *head = NULL;
    V_NODE *rear = NULL;
    int n = 10;

    printf("Please input n:\n");
    scanf("%d",&n);

    rear = init_link(n);
    //head = rear->next;
    //print_link(head,35);
    game_doing(rear);
    return 0;
}
