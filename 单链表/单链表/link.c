#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#define OK 1
#define ERROR -1
typedef int DataType;//��ʾ������������ͣ����޸�
//����ṹ���ʾ��㣬ÿ����������������һ����������һ����ָ����
typedef struct Lnode {
	DataType data;//��ʾ�洢������
	struct Lnode* next;//ָ��ָ����һ�����
};
/*
copyright:Zhaozhan
time��20230303��
data structure:link list
*/
//��ʼ������
/*
��������������ͷ�ڵ㣬ͷָ��ָ��ͷ�����ͷ����ָ����Ϊ��
@para1�������������ͷָ���ͷ���
*/
struct Lnode* InitList() {
	struct Lnode* head = (struct Lnode*)malloc(sizeof(struct Lnode));//��ʼ��ͷ��㣬Ϊ������һ��ռ�
	head->data = 0;
	head->next = NULL;
	return head;
}
//�ж��Ƿ�Ϊ�ձ���
/*
�����������������н���һ��ͷ���ʱΪ�ձ���ʱͷ����nextΪnull
@parameter1��ͷָ��
*/
int EmptyList(struct Lnode* l) {
	if (!l->next)
		return 0;
	return 1;
}
//����������ٺ���
/*
�����н�������ͷţ�����ͷ��㣩
@parameter1��ͷָ��
*/
int DestoryList(struct Lnode* l) {
	struct Lnode* p = l;//�׸�Ԫ�ؽ��
	while (p) {
		struct Lnode* q = p;
		p = p->next;
		free(q);
	}
	return OK;
}
//���������պ���
/*
�����������������Ԫ�أ��������ڣ�ͷָ���ͷ����ڣ�����Ϊ��,ע��Ҫ��ͷ����ָ������ΪNULL
@parameter1��ͷָ��
*/
int ClearList(struct Lnode* l) {
	struct Lnode* p = l->next;
	while (p) {
		struct Lnode* q = p;
		p = p->next;
		free(q);
	}
	l->next = NULL;
	return OK;
}
//��������ĺ���
/*
��������������һ������ĳ��ȣ�������ͷ��㣩
@parameter1��ͷָ��
����ֵ��Ҫ����
*/
int LengthList(struct Lnode* l) {
	int i = 0;
	struct Lnode* p = l->next;
	while (p) {
		i++;
		p = p->next;
	}
	return i;
}
//ȡֵ����
/*
�������������ص�i��Ԫ�ص�ֵ
@parameter1:ͷָ��
@parameter2��Ԫ��λ�ã������±꣩
*/
int GetEle(struct Lnode* l, int i) {
	struct Lnode* p = l->next;
	int j = 1;
	while (p && j < i) {
		j++;
		p = p->next;
	}
	if (!p || j > i)//��ָֹ��Ԫ��λ��С��1�ͳ�������
		return ERROR;
	return p->data;
}
//��ֵ���Һ���
/*
�����������������ݷ��ظ����ݵ�λ�ã����±꣩
@parameter1:ͷָ��
@parameter2��Ԫ������
*/
int GetIndex(struct Lnode* l, DataType x) {
	int j = 1;
	struct Lnode* p = l->next;
	while (p && x != p->data) {
		p = p->next;
		j++;
	}
	if (!p)
		return ERROR;
	return j;
}
//�����뺯��
/*
������������ָ��Ԫ��λ�ò���һ���ڵ�
@parameter1:ͷָ��
@parameter2��ָ��λ��
@parameter3��Ԫ������
*/
int InsertNode(struct Lnode* l, int i, DataType x) {
	int j = 0;
	struct Lnode* q = l;
	while (q && j < i - 1) {
		q = q->next;
		j++;
	}
	struct Lnode* p = (struct Lnode*)malloc(sizeof(struct Lnode));//����һ���½ڵ�
	p->data = x;
	p->next = q->next;
	q->next = p;
	if (!q || j > i - 1)
		return ERROR;
	return OK;
}
//ɾ������
/*
����������ɾ��ָ��λ�õĽ��
@parameter1��ͷָ��
@parameter2��ָ��λ��
*/
int DelEle(struct Lnode* l, int i) {
	int j = 1;
	struct Lnode* p = l->next;
	struct Lnode* q = l;
	while (p && j < i) {
		q = p;
		p = p->next;
		j++;
	}
	q->next = p->next;
	free(p);
	if (!p || j > i) {
		return ERROR;
	}
	return OK;
}
//���뺯����ͷ�巨��
/*
����������Խ������Ԫ�أ�Խ����ͷ���
@parameter1:ͷָ��
@parameter2:����Ԫ�ظ���
*/
int InsertEle(struct Lnode* l, int n) {
	for (int j = 0; j < n; j++) {
		struct Lnode* p = (struct Lnode*)malloc(sizeof(struct Lnode));
		scanf("%d", &p->data);
		p->next = l->next;//����������
		//printf("%p", p->next);
		l->next = p;
	}
}
//��ӡ����
void Print(struct Lnode* l) {
	l = l->next;
	while (l)
	{
		printf("%d\n", l->data);
		l = l->next;
	}
}
int main() {
	struct Lnode* l = InitList();//��ʼ��һ��ͷ���
	//printf("%p\n", l->next);//�����Ƿ񴴽��ɹ�
	//���Բ�����
	InsertEle(l, 3);
	//printf("%p", (l ->next->next->next));
	//���Դ�ӡ����
	//Print(l);
	//����ɾ������
	//DelEle(l,3);
	//Print(l);
	//������ָ��λ�ò�����
	InsertNode(l, 3, 4);
	Print(l);
	//���Է���ָ��λ��Ԫ�غ���
	//printf("%d",GetEle(l, 3));
	//���԰�ֵ���Һ���
	/*
	 printf("%d\n", GetIndex(l, 5));
	printf("%d", GetIndex(l, 4));
	*/
	//�����󳤶Ⱥ���
	//printf("%d", LengthList(l));
	//������պ���
	ClearList(l);
	Print(l);
	//����ɾ������
	//DelEle(l, 3);
	//Print(l);
	//�������ٺ���
	//DestoryList(l);
	return 0;
}