#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<windows.h>
struct node{
    struct node* forward;
    char name[20];
    int date;
    int line;
    struct node* next;
};
char MenuText[3][300]={
    "[A] Creatlist",
    "[B] Printlist",
    "[Q] Quit",
};

struct node* creatList();
void printString(struct node *head);
void displaymenu(int hilight);
void returnmenu(int mode);

int main(){
struct node *head=NULL;
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
            if(c<='C'&&c>='A'){
                sel=c-'A'+1;
                system("cls");
                displaymenu(sel);
                printf("\ncommand is [%c]",c);
                switch(c)
                {
                    case 'A':
                        head=creatList();
                        sel=1;
                        returnmenu(1);
                        break;

                    case 'B':
                        printString(head);
                        sel=1;
                        returnmenu(2);
                        break;

                    case 'C':
                        sel=1;
                        returnmenu(2);
                        break;
                    default:
                    break;
                }
            }
            else if(c=='\r'){
                switch(sel){
                case 1:
                    printf("command is [%c]\n",'A'+sel-1);
                    head=creatList();
                    sel=1;
                    returnmenu(1);break;

                case 2:
                printf("command is [%c]\n",'A'+sel-1);
                printString(head);
                sel=1;
                returnmenu(2);break;
                }
            }
            else if(c=='q'||c=='Q'){break;}
            Sleep(100);
        }
    }
}

void displaymenu(int hilight){int i;
        printf("\n=============================\n");
        for(i=0;i<3;i++){
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

struct node* creatList(){
    struct node* p1,*p2,*head;
    int n=0;
    head=NULL;
    p1=p2=(struct node*)malloc(sizeof(struct node));
    printf("Sign your name:\n");
    gets(p1->name);
    while (strlen(p1->name)!=0){
        n++;
        p1->line=n;
        printf("Type data:\n");
        scanf("%d",&p1->date);
        if(n==1){p1->forward=NULL;head=p1;}
        else{p2->next=p1;p1->forward=p2;p2=p1;}
        p1=(struct node*)malloc(sizeof(struct node));
        printf("Sign your name:\n");
        getchar();
        gets(p1->name);
    }
    p2->next=NULL;
    
        return head;
       
    
}

void printString(struct node *head){
    struct node*p=head; 
    if(head==NULL){printf("\nNo date.");}//判断第一节点是否有数据
    else{
        do{ 
            printf("\n%d.selflocated:%p, forward_located:%p, name:%s , date:%d,nextlocated: %p\n",p->line,p,p->forward,p->name,p->date,p->next);
            p=p->next;
        }
    while(p!=NULL);
    printf("Done.");
    }//输出到屏幕
}
