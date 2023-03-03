#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#define OK 1
#define ERROR -1
typedef int DataType;//表示输入的数据类型，可修改
//定义结构体表示结点，每个结点由两部分组成一是数据域，另一个是指针域
typedef struct Lnode {
	DataType data;//表示存储的数据
	struct Lnode* next;//指针指向下一个结点
};
/*
copyright:Zhaozhan
time：20230303；
data structure:link list
*/
//初始化函数
/*
功能描述：生成头节点，头指针指向头结点且头结点的指针域为空
@para1：无需参数生成头指针和头结点
*/
struct Lnode* InitList() {
	struct Lnode* head = (struct Lnode*)malloc(sizeof(struct Lnode));//初始化头结点，为其申请一块空间
	head->data = 0;
	head->next = NULL;
	return head;
}
//判断是否为空表函数
/*
功能描述：当链表中仅有一个头结点时为空表，此时头结点的next为null
@parameter1：头指针
*/
int EmptyList(struct Lnode* l) {
	if (!l->next)
		return 0;
	return 1;
}
//单链表的销毁函数
/*
将所有结点依次释放（包括头结点）
@parameter1：头指针
*/
int DestoryList(struct Lnode* l) {
	struct Lnode* p = l;//首个元素结点
	while (p) {
		struct Lnode* q = p;
		p = p->next;
		free(q);
	}
	return OK;
}
//单链表的清空函数
/*
功能描述：清空所有元素，链表人在，头指针和头结点在，其它为空,注意要将头结点的指针域设为NULL
@parameter1：头指针
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
//求链表表长的函数
/*
功能描述：返回一个链表的长度（不包括头结点）
@parameter1：头指针
返回值需要接收
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
//取值函数
/*
功能描述：返回第i个元素的值
@parameter1:头指针
@parameter2：元素位置（不是下标）
*/
int GetEle(struct Lnode* l, int i) {
	struct Lnode* p = l->next;
	int j = 1;
	while (p && j < i) {
		j++;
		p = p->next;
	}
	if (!p || j > i)//防止指定元素位置小于1和超出长度
		return ERROR;
	return p->data;
}
//按值查找函数
/*
功能描述：输入数据返回该数据的位置（非下标）
@parameter1:头指针
@parameter2：元素数据
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
//结点插入函数
/*
功能描述：在指定元素位置插入一个节点
@parameter1:头指针
@parameter2：指定位置
@parameter3：元素数据
*/
int InsertNode(struct Lnode* l, int i, DataType x) {
	int j = 0;
	struct Lnode* q = l;
	while (q && j < i - 1) {
		q = q->next;
		j++;
	}
	struct Lnode* p = (struct Lnode*)malloc(sizeof(struct Lnode));//创建一个新节点
	p->data = x;
	p->next = q->next;
	q->next = p;
	if (!q || j > i - 1)
		return ERROR;
	return OK;
}
//删除函数
/*
功能描述：删除指定位置的结点
@parameter1：头指针
@parameter2：指定位置
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
//插入函数（头插法）
/*
功能描述：越后来的元素，越靠近头结点
@parameter1:头指针
@parameter2:插入元素个数
*/
int InsertEle(struct Lnode* l, int n) {
	for (int j = 0; j < n; j++) {
		struct Lnode* p = (struct Lnode*)malloc(sizeof(struct Lnode));
		scanf("%d", &p->data);
		p->next = l->next;//精华！！！
		//printf("%p", p->next);
		l->next = p;
	}
}
//打印函数
void Print(struct Lnode* l) {
	l = l->next;
	while (l)
	{
		printf("%d\n", l->data);
		l = l->next;
	}
}
int main() {
	struct Lnode* l = InitList();//初始化一个头结点
	//printf("%p\n", l->next);//测试是否创建成功
	//测试插入结点
	InsertEle(l, 3);
	//printf("%p", (l ->next->next->next));
	//测试打印函数
	//Print(l);
	//测试删除函数
	//DelEle(l,3);
	//Print(l);
	//测试在指定位置插入结点
	InsertNode(l, 3, 4);
	Print(l);
	//测试返回指定位置元素函数
	//printf("%d",GetEle(l, 3));
	//测试按值查找函数
	/*
	 printf("%d\n", GetIndex(l, 5));
	printf("%d", GetIndex(l, 4));
	*/
	//测试求长度函数
	//printf("%d", LengthList(l));
	//测试清空函数
	ClearList(l);
	Print(l);
	//测试删除函数
	//DelEle(l, 3);
	//Print(l);
	//测试销毁函数
	//DestoryList(l);
	return 0;
}