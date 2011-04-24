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
V_NODE *delete_link(V_NODE *head);
V_NODE *add_link(V_NODE *head);
void print_link(V_NODE *head);
int get_choice(void);
void print_list(void);
void print_word(void);

void save_link(V_NODE *p)
{
   FILE *fp;
   fp = fopen("text1","w+");
   if(fp == NULL)
   {
            perror("opening:");
            exit(0);
   
   }
   while(p !=NULL)
   {
            fprintf(fp,"%d\t%s\n",p->number,p->name);
            p = p->next;
   }

   fclose(fp);

}
V_NODE *load_link(void)
{
    FILE *fp;
    int num;
    char na[20];
    V_NODE *p = NULL;
    V_NODE *head = NULL;
    fp = fopen("text1","r+");
    if(fp == NULL)
    {
                perror("open");
                exit(0);

    }
    if(fscanf(fp,"%d%s",&num,na)!=EOF)
    {
        
        p = malloc(sizeof(V_NODE));
        if(p == NULL)
        {
                perror("malloc");
                exit(0);
        }
        p->number = num;
        strcpy(p->name,na);
        p->next = NULL;
        head = p;


    }
    while(fscanf(fp,"%d%s",&num,na)!= EOF)
    {
        
        p->next = malloc(sizeof(V_NODE));
        if(p->next == NULL)
        {
                perror("malloc");
                exit(0);
        }
        p->next->number = num;
        strcpy(p->next->name,na);
        p->next->next = NULL;
        p = p->next;


    }
    return head;


}
int main(void)
{
    V_NODE *head=NULL;
    int  flag = 0;
    print_word();
    
    head = load_link();
    while (!flag) 
    {
        print_list();
        switch(get_choice())
        {
                case 1 : head = add_link(head);break;
                case 2 : head = delete_link(head);break;
                case 3 : print_link(head);break;
                case 4 : save_link(head);break;
                case 5 : flag = 1;break;
                default: break;
        }

        getchar();
    }
    return 0;


    //int n = 0;
    //printf("Input a number\n");
    //scanf("%d",&n);
    //head = create_link(n);
    //print_link(head);
    //head = delete_link(head);
    //print_link(head);
    //head = add_link(head); 
    //print_link(head);
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
int get_choice(void)
{
       char choice[20]; 
       scanf("%s",choice);
       return atoi(choice);
}

void print_list(void)
{
        printf("Please make a choice\n");
        printf("1.Add node\n");
        printf("2.delete node\n");
        printf("3.print link\n");
        printf("4.save\n");
        printf("5.exit\n");
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

    for (i = 1; i < n; i++) 
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

V_NODE *add_link(V_NODE *head)
{
    V_NODE *p = NULL;
    V_NODE *ptr = head;
    p = malloc(sizeof(V_NODE));
    if (p == NULL) 
    {
        perror("malloc");
        exit(0);
    }
    printf("input number");
    scanf("%d",&p->number);
    printf("input name\n");
    scanf("%s",p->name);
    p->next = NULL;
    if(ptr == NULL)
    {
        return p;
    
    }
    if (p->number < ptr->number) 
    {
        p->next = ptr;
        head = p;
        return head;
    }
    while ((ptr->next !=NULL)&&(p->number > ptr->next->number)) 
    {
        ptr = ptr->next;
    }
    p->next = ptr->next;
    ptr->next = p;
    return head;
}

V_NODE *delete_link(V_NODE *head)
{
    int num = 0;
    V_NODE *p = head;
    V_NODE *ptr = NULL;
    if (head == NULL) 
    {
        printf("empty link\n");
        return NULL;
    }
    printf("Please input num of node to delete:\n");
    scanf("%d",&num);
    if (num == head->number) 
    {
        head = head->next;
        free(p);
        return head;
    }
    
    while ((p->next !=NULL) && (p->next->number != num)) 
    {
        p = p->next;

    }
    if (p->next == NULL) 
    {
        printf("NO number match!\n");

    }
    else 
    {
        ptr = p->next;
        p->next = p->next->next;
        free(ptr);
    }
    return head;
}

void print_link(V_NODE *p)
{
    if (p == NULL) 
    {
        printf("link empty\n");
    }
    printf("student infor\n");
    printf("number\tname\n");
    while (p != NULL) 
    {
        printf("%d\t%s\n",p->number,p->name);
        p = p->next;
    }
    printf("\n");
}
