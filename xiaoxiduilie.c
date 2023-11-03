#include <stdio.h>
#include <stdlib.h>
typedef struct MESSAGE{
	char news[50];
	char senter[20];
	int time[6];
	struct MESSAGE* next;
}message;
message* creatlink();              /*创造链表*/
void prints(message*head);            /*顺序打印*/
void printn(message*head);            /*逆序打印*/
void delenow(message*head);         /*头删*/ 
void deleTD(message*head,char ch[50]);            /*特定内容删*/
void delelate(message*head);          /*尾删*/
void destoryList(message *nu);
int main(){
	message* head;
	int num=0;
	while(1){
		printf("请输入您的选择：\n1--创建一个带空节点的消息队列并输入消息\n2-删除最新消息\n3--删除最早消息\n4--删除指定的消息\n5-顺序打印全部消息\n6-逆序打印全部消息\n7--退出程序\n");
		scanf("%d",&num);
		if(num==1){
			head=creatlink();
			printf("链表创造输入完毕");
		}
		if(num==2){
			delenow(head);
		}
		if(num==3){
			delelate(head);
		}
		if(num==4){
			char ch[50];
			printf("输入需要删除内容"); 
			scanf("%s",ch);
			
			deleTD(head,ch[50]);
		}
		if(num==5){
			
			prints(head);
		}
		if(num==6){
			printn(head);
		}
		if(num==7){
			printf("程序运行结束，再见！");
			destoryList(head);
			break;
		}
	}
	return 0;
}


message* creatlink(){                /*创造链表*/
	message* head;
	head=(message*)malloc(sizeof(message));
	head->next=NULL;
	message* p1=head;    
	char me[50];
	message* prep2=head;
	scanf("%s",me);
	while(me[50]!='#'){
		int i=0;
		message* p2;
		p2=(message*)malloc(sizeof(message));
		p2->next=NULL;
		for(i=0;i<50;i++){
			p2->news[i]=me[i];
		}
		scanf("%s",p2->senter);
		for(i=0;i<6;i++){
			scanf("%d",&p2->time[i]);
		}
		if(p1!=head){
			p2->next=p1;
			p1=p2;
		    prep2->next=p2;
		}
		else {
			p1->next=p2;
			p1=p2;
			
		}
		scanf("%s",me);
	}
}
             

void prints(message* head){              /*顺序打印*/
	message* p=head;
	while(p->news[50]!='#'){
		for(p=head;p!=NULL;p=p->next){
		    printf("%s   %s   ",p->news,p->senter);
		    int i=0;
		    for(i=0;i<5;i++){
			    printf("%d-");
		    }
		printf("%d\n",p->time[5]);
    	}
	}	
}            


void printn(message*head){              /*逆序打印*/
	message* p=head->next;
	message* ppre=head;
	message* p2=p->next;
	message* p2next=p2->next;
	while(p2!=NULL){
		ppre->next=p2;
		p2->next=p;
		p->next=p2next;
		p=p2;
		p2=p2next;
		p2next=p2next->next;
	}
	while(p->news[50]!='#'){
		for(p=head;p!=NULL;p=p->next){
		    printf("%s   %s   ",p->news,p->senter);
		    int i=0;
		    for(i=0;i<5;i++){
			    printf("%d-");
		    }
		printf("%d\n",p->time[5]);
    	}
	}
}           


void delenow(message*head){              /*最新消息删除*/ 
	message* p=head;
	message* m=head->next;
	message* n=m->next;
	p->next=n;
}        


void deleTD(message*head,char ch[50]){               /*特定内容删除*/
	message* p=NULL;
	message* ppre=head;
	while(strcmp(ch,p->news)!=0){
		p=p->next;
		ppre=p;
	}
	ppre->next=p->next;
}          


void delelate(message*head){              /*最早消息删除*/
	message* p=head;
	message* prep=NULL;
	p=head->next;
	prep=head;
	while(p->next!=NULL){
		prep=p;
		p=p->next;
	}
	prep->next=NULL;
} 


void destoryList(message *nu){
	message* qzj;
	while(nu!=NULL){
		qzj=nu;
		nu=nu->next;
		free(qzj);
	}
}     
