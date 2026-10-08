#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_STACK 5

struct Student{char id[10],name[50];float gpa;};
struct DNode{struct Student data;struct DNode*prev,*next;};
struct Operation{int type;struct Student data;};
struct Stack{struct Operation op[MAX_STACK];int top;};

void push(struct Stack*s,int t,struct Student d){
 int i;
 if(s->top==MAX_STACK){
  for(i=0;i<MAX_STACK-1;i++)s->op[i]=s->op[i+1];
  s->top=MAX_STACK-1;
 }
 s->op[s->top].type=t;
 s->op[s->top++].data=d;
}

int pop(struct Stack*s,struct Operation*o){
 if(!s->top)return 0;
 *o=s->op[--s->top];
 return 1;
}

struct DNode*insertWithoutStack(struct DNode*h,struct Student s){
 struct DNode*n=malloc(sizeof(struct DNode)),*c;
 if(!n)return h;
 n->data=s;n->prev=n->next=NULL;
 if(!h)return n;
 if(s.gpa>h->data.gpa){
  n->next=h;h->prev=n;return n;
 }
 c=h;
 while(c->next&&c->next->data.gpa>=s.gpa)c=c->next;
 n->next=c->next;n->prev=c;
 if(c->next)c->next->prev=n;
 c->next=n;
 return h;
}

struct DNode*insertSorted(struct DNode*h,struct Student s,
struct Stack*st){
 h=insertWithoutStack(h,s);
 push(st,1,s);
 return h;
}

struct DNode*deleteWithoutStack(struct DNode*h,char id[]){
 struct DNode*c=h;
 while(c){
  if(!strcmp(c->data.id,id)){
   if(!c->prev)h=c->next;
   else c->prev->next=c->next;
   if(c->next)c->next->prev=c->prev;
   free(c);return h;
  }
  c=c->next;
 }
 return h;
}

struct DNode*deleteById(struct DNode*h,char id[],struct Stack*st){
 struct DNode*c=h;
 while(c){
  if(!strcmp(c->data.id,id)){
   struct Student s=c->data;
   h=deleteWithoutStack(h,id);
   push(st,2,s);return h;
  }
  c=c->next;
 }
 printf("no id %s\n",id);
 return h;
}

void printForward(struct DNode*h){
 while(h){
  printf("[%s|%s|%.2f]",h->data.id,h->data.name,h->data.gpa);
  if(h->next)printf(" -> ");
  h=h->next;
 }
 printf(" -> NULL\n");
}

void printBackward(struct DNode*h){
 struct DNode*c=h;
 if(!c){printf("NULL\n");return;}
 while(c->next)c=c->next;
 while(c){
  printf("[%s|%s|%.2f]",c->data.id,c->data.name,c->data.gpa);
  if(c->prev)printf(" -> ");
  c=c->prev;
 }
 printf(" -> NULL\n");
}

struct DNode*undo(struct DNode*h,struct Stack*s){
 struct Operation o;
 if(!pop(s,&o)){printf("no Undo\n");return h;}
 if(o.type==1){
  h=deleteWithoutStack(h,o.data.id);
  printf("Undo: insert %s\n",o.data.id);
 }else{
  h=insertWithoutStack(h,o.data);
  printf("Undo: delete %s\n",o.data.id);
 }
 return h;
}

void freeList(struct DNode*h){
 struct DNode*t;
 while(h){t=h;h=h->next;free(t);}
}

int main(){
 struct DNode*h=NULL;
 struct Stack st;
 struct Student s;
 int ch;
 char id[10];
 st.top=0;

 do{
  printf("\n1.Insert\n2.Delete\n3.Forward\n4.Backward\n5.Undo\n0.Exit\n");
  scanf("%d",&ch);
  switch(ch){
   case 1:
    scanf("%9s%49s%f",s.id,s.name,&s.gpa);
    h=insertSorted(h,s,&st);break;
   case 2:
    scanf("%9s",id);
    h=deleteById(h,id,&st);break;
   case 3:printForward(h);break;
   case 4:printBackward(h);break;
   case 5:h=undo(h,&st);break;
   case 0:printf("Exit\n");break;
   default:printf("Invalid choice\n");
  }
 }while(ch);

 freeList(h);
 return 0;
}
