/*
	Name:���ĺ�������洢��ʾ 
	Author:  ����� 
	Date: 02/11/23 17:51
*/
#include<stdio.h>
#define MaxSize 100
typedef struct CTNode {
	int child;
	struct CTNode *next;
}*ChildPtr,CTNode;

typedef struct {
	in data;
	ChildPtr firstchild,tailchild; 
} CTBox;

typedef struct {
	CTBox nodes[MaxSize];
	int n,r; 
} CTree;

int Location(char data,CTree* T) {
	for(int i = 0; i<T->n; i++)
		if(T->nodes[i].data == data) return i;
	return -1;
}

int CreateTree(CTree* T) {
	ChildPtr p;
	char chr1,chr2;
	int pos1,pos2;
	printf("�����������");
	scanf("%d",&T->n);
	for(int i=0; i<T->n; i++) {
		fflush(stdin);
		scanf("%c",&T->nodes[i].data);
		T->nodes[i].firstchild = NULL;
		T->nodes[i].tailchild = NULL;
	}
	getchar();
	printf("��¼�����ϵ����A,B\n");
	while(1) {
		fflush(stdin);
		scanf("%c,%c",&chr1,&chr2);
		if(chr1 == '#' || chr2 == '#') break;
		pos1 = Location(chr1,T);
		pos2 = Location(chr2,T);
		if(pos1 == -1 || pos2 == -1) {
			printf("������������ԣ�");
			continue;
		}
		if(!(p=(ChildPtr)malloc(sizeof(CTNode)))) return -1;
		p->child = pos2;
		p->next = NULL;
		if(T->nodes[pos1].firstchild == NULL)
			T->nodes[pos1].firstchild =p;
		else
			T->nodes[pos1].tailchild->next = p;
		T->nodes[pos1].tailchild = p;
	}
}

void outputchild(CTree T,int pos) {
	ChildPtr p = T.nodes[pos].firstchild;
	while(p) {
		printf("%c",T.nodes[p->child].data);
		p = p->next;
	}
}
int main() {
	char temp;
	int pos;
	CTree T;
	if(CreateTree(&T))
		printf("�����ɹ�");
	else
		printf("����ʧ��");
	printf("����ϣ��������ӽ��Ľ��");
	fflush(stdin);
	scanf("%c",&temp);
	pos = Location(temp,&T);
	if(pos==-1)
		printf("�ýڵ㲻�������н��");
	else
		outputchild(T,pos);
	return 0;
}
