#include <stdio.h>
#include <stdlib.h>
typedef struct MESSAGE{
	char news[50];
	char senter[20];
	int time[6];
	struct MESSAGE* next;
}message;
message* creatlink();              /*��������*/
void prints(message*head);            /*˳���ӡ*/
void printn(message*head);            /*�����ӡ*/
void delenow(message*head);         /*ͷɾ*/ 
void deleTD(message*head,char ch[50]);            /*�ض�����ɾ*/
void delelate(message*head);          /*βɾ*/
void destoryList(message *nu);
int main(){
	message* head;
	int num=0;
	while(1){
		printf("����������ѡ��\n1--����һ�����սڵ����Ϣ���в�������Ϣ\n2-ɾ��������Ϣ\n3--ɾ��������Ϣ\n4--ɾ��ָ������Ϣ\n5-˳���ӡȫ����Ϣ\n6-�����ӡȫ����Ϣ\n7--�˳�����\n");
		scanf("%d",&num);
		if(num==1){
			head=creatlink();
			printf("�������������");
		}
		if(num==2){
			delenow(head);
		}
		if(num==3){
			delelate(head);
		}
		if(num==4){
			char ch[50];
			printf("������Ҫɾ������"); 
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
			printf("�������н������ټ���");
			destoryList(head);
			break;
		}
	}
	return 0;
}


message* creatlink(){                /*��������*/
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
             

void prints(message* head){              /*˳���ӡ*/
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


void printn(message*head){              /*�����ӡ*/
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


void delenow(message*head){              /*������Ϣɾ��*/ 
	message* p=head;
	message* m=head->next;
	message* n=m->next;
	p->next=n;
}        


void deleTD(message*head,char ch[50]){               /*�ض�����ɾ��*/
	message* p=NULL;
	message* ppre=head;
	while(strcmp(ch,p->news)!=0){
		p=p->next;
		ppre=p;
	}
	ppre->next=p->next;
}          


void delelate(message*head){              /*������Ϣɾ��*/
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
