#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<windows.h>
struct node{
char name[20];
int date;
int line;
struct node *next;
};
char MenuText[7][300]={
    "[A] Creatlist",
    "[B] Printlist",
    "[C] Checklist",
    "[D] Deletename",
    "[E] Addlist",
    "[F] Change_name_and_date",
    "[Q] Quit",
};

struct node* getstrings();
void printstring(struct node *head);
struct node* checkstring(struct node *head,char *str);
void displaymenu(int hilight);
struct node* delete(struct node* head);
void returnmenu(int mode);
int arrange(struct node* head);
struct node* addstring(struct node *head);
void change(struct node* head);

int main(){
        struct node *head=NULL;
        char filename[30];
        char c=' ';
        int sel=1;
        displaymenu(sel);
        for(;;){
            if(kbhit()){
            //方向盘控制
                if(GetAsyncKeyState(VK_UP)){
                    sel=(sel>1)?sel-1:sel;
                    system("cls");
                    displaymenu(sel);
                }
                if(GetAsyncKeyState(VK_DOWN)){
                    sel=(sel<7)?sel+1:sel;
                    system("cls");
                    displaymenu(sel);
                }
                //字符控制
                c=getch();
                if(c<='z'&&c>='a')c=c-('a'-'A');
                if(c<='F'&&c>='A'){
                    sel=c-'A'+1;
                    system("cls");
                    displaymenu(sel);
                    printf("\ncommand is [%c]",c);
                    switch(c)
                    {
                        case 'A':
                            head=getstrings();
                            sel=1;
                            returnmenu(1);
                            break;

                        case 'B':
                            printstring(head);
                            printf("\ndone.");
                            sel=1;
                            returnmenu(2);
                            break;

                        case 'C':
                            if(head!=NULL){
                                printf("\nWhat are you looking for?\n");
                                gets(filename);
                                struct node* q=checkstring(head,filename);
                                printf("num:%d,date==%d",q->line,q->date);
                            }
                            else{printf("\nYou haven't creatlist.");}
                            sel=1;
                            returnmenu(2);
                            break;
                        case 'D':
                            head=delete(head);
                            sel=1;
                            returnmenu(1);
                            break;
                        case 'E':
                            head=addstring(head);
                            sel=1;
                            returnmenu(1);
                            break;
                        case 'F':
                            change(head);
                            sel=1;
                            returnmenu(1);
                            break;
                        default:
                        break;
                    }
                }
                else if(c=='\r'){
                    switch(sel){
                    case 1:printf("command is [%c]\n",'A'+sel-1);head=getstrings();
                            sel=1;
                            returnmenu(1);break;

                    case 2:printf("command is [%c]\n",'A'+sel-1);printstring(head);
                            sel=1;
                            returnmenu(2);break;

                    case 3:
                        printf("command is [%c]\n",'A'+sel-1);
                        if(head!=NULL){
                            printf("\nWhat are you looking for?\n");
                            gets(filename);
                            struct node* q=checkstring(head,filename);
                            printf("num:%d,date==%d",q->line,q->date);
                        }
                        else{printf("\nYou haven't creatlist.");}
                        sel=1;
                        returnmenu(2);
                        break;
                    case 4:
                        head=delete(head);
                        sel=1;
                        returnmenu(1);
                        break;
                    case 5:
                        head=addstring(head);
                        sel=1;
                        returnmenu(1);
                        break;
                    case 6:
                        change(head);
                        sel=1;
                        returnmenu(1);
                        break;
                    case 7:
                        printf("command is [%c]\n",'A'+sel-1);return 0;break;
                    }
                }
                else if(c=='q'||c=='Q'){break;}
                Sleep(100);
            }
        }
    }

struct node* getstrings(){
    struct node *p1,*p2,*head;
    int n=0;
    p1=p2=(struct node*)malloc(sizeof(struct node));
    head=NULL;
    printf("name:");
    gets(p1->name);
    while(strlen(p1->name)!=0){
        printf("date:");
        scanf("%d",&p1->date);
        n++;
        if(n==1){head=p1;}
        else {p2->next=p1;}
        p1->line=n;
        p2=p1;
        p1=(struct node*)malloc(sizeof(struct node));
        printf("name:");
        getchar();//消空格
        gets(p1->name);
    }
    p2->next=NULL;
    printf("Finish.");
     return head;
}

void printstring(struct node *head){
    struct node*p=head;
    
    if(head==NULL){printf("\nNo date.");}//判断第一节点是否有数据
    else{
        arrange(head);
        do{ 
            printf("\n%d: name:%s , date:%d\n",p->line,p->name,p->date);
            p=p->next;
        }
    while(p!=NULL);
    printf("Done.");
    }//输出到屏幕
}

struct node* checkstring(struct node *head,char *str){
        struct node *p=head,*t=NULL;
        while(p!=NULL){
           if(strcmp(p->name,str)==0){
                t=p;
                break;
            }
            else{p=p->next;}
        }
        if(p==NULL)printf("\nnot exit.");
        return t;//返回对应名字的数据
}

struct node* delete(struct node* head){
    struct node* p1=NULL,*p=NULL;int got=0;
        p=p1=head;
    if(p!=NULL){
        printf("\nWhich one do you want to delete?(Type the order)\n");
        int num;
        scanf("%d",&num);
        while(p!=NULL){
            if(p->line==num){
                if(p==head){
                     head=p->next;p1=head;got=1;
                 }
                else if(p->next==NULL){
                            p1->next=NULL;got=1;
                }
                else{p1->next=p->next;got=1;}
            }
            else p1=p; 
            p=p->next;
        }
    }
    p1=head;
    if(got){printf("\nComplete!\n");}
    else{printf("\nWithout the name\n");}    
    return head;
}

struct node* addstring(struct node *head){
    if(head!=NULL){
        getchar();//消空格
        struct node* q=getstrings();
        int number=arrange(head);
        struct node *p1=NULL,*p2=NULL,*end=NULL;
        p1=p2=q;
        while(p1->next!=NULL){
            p2=p1;
            p1=p1->next;
        }
        end=p1;
        p1=p2=head;
        printf("\nWhere do you want to add it after which node?(Type the number):");
        int q1=0;
        scanf("%d",&q1);
        while(q1<0||q1>number){printf("Error number.");printf("\nWhere do you want to add it after which node?(Type the number):"); scanf("%d",&q1);}
        while(p1!=NULL){
            if(p1->line==q1){
                struct node* temp=NULL;
                temp=p1->next;
                p1->next=q;
                end->next=temp;
                break;
            }
            else{
                if(q1==0){
                    end->next=head;
                    head=q;
                    break;
                }
                else {
                    p2=p1;
                    p1=p1->next;
                }
            }
        }
        arrange(head);
        printf("\nFinish");
    }
    else{printf("\nYou haven't creatlist.");}
    return head;
}

int arrange(struct node* head){
   struct node*p=head;int n=0;
    if(head==NULL){printf("\nNo date in thid listed.");}//判断第一节点是否有数据
    else{
        do{ 
            n++;
            p->line=n;
            p=p->next;
        }
        while(p!=NULL);
    }
    return n;
}

void change(struct node* head){
    if(head!=NULL){
        printf("\nWhich one do you want to change(Type its order)?");
        int num=0;int got=0;
        scanf("%d",&num);
        if(num<=0){printf("\nError number");}
        struct node* p1=NULL,*p2=NULL;
        p1=p2=head;
        while(p1!=NULL){
            if(p1->line==num){
                printf("\nPlease type new name");
                scanf("%s",p1->name);
                printf("\nPlease type new date");
                scanf("%d",&p1->date);
                break;
                got=1;
            }
            else{p2=p1;p1=p1->next;}
        }
        if(got==1)printf("\nFinish.");
        else printf("\nError.");
    }
    else{printf("\nYou haven't creatlist.");}
}

void displaymenu(int hilight){int i;
        printf("\n=============================\n");
        for(i=0;i<7;i++){
            if(i==hilight-1)
                printf("<<%s>>\n",MenuText[i]);
            else
                printf(" %s\n",MenuText[i]);
        }
}

void returnmenu(int mode){
    switch (mode){
        case 1:
            printf("\nWait a second.");
            Sleep(1000);
            break;
        case 2:
            printf("\npress 'q' to exit.");
            for(;;){
                if(kbhit()){
                    char c=getch();
                    if(c=='q'||c=='Q'){
                        break;
                    }
                }
            }    
            break;
        default:
            break;
    }
        system("cls");
            displaymenu(1);
}