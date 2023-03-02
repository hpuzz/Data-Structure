#include<stdio.h>
#include<stdlib.h>
#define OK 0
#define ERROR -1
#define MAX 1000
typedef int DataType;//线性表中的数据类型，可修改
typedef struct Sq {//线性表中元素+长度组成，元素用数组表示
	DataType* element;
	int length;
};
//初始化函数
int InitSq(struct Sq* l) {
	l->element = (DataType*)malloc(MAX * sizeof(DataType));//为线性表的元素动态分配内存空间，初始为0
	l->length = 0;//初始化为0
	if (!l->element) {
		return ERROR;//创建失败返回1
	}
	return OK;
}
//销毁线性表,将申请的内存空间销毁
void DestoryList(struct Sq* l) {
	free(l->element);
}
//清空线性表，长度置为零
void ClearList(struct Sq* l) {
	l->length = 0;
}
//求线性表长度
int LenList(struct Sq* l) {
	return l->length;
}
//是否为空表
int EmptyList(struct Sq* l) {
	if (l->length == 0)
		return 1;
	return 0;
}
//顺序表的取值，给定第几个元素，返回元素值
int GetEle(struct Sq* l, int i) {
	if (i<0 || i>l->length)
		return ERROR;
	return l->element[i-1];
}
//查找某个元素是否存在,若存在返回是第几个元素
int GetIndex(struct Sq* l, DataType x) {
	for (int i = 0; i < l->length; i++) {
		if (l->element[i] == x) {
			return i+1;
		}
	}
	return OK;
}
//元素插入在指定位置(非下标)插入某个元素
int InsertEle(struct Sq* l, DataType x, int i) {
	if (i < 1||i>(l->length)+1)//l->length表示当前最后一个元素，+1表示可以在最后一个元素之后追加
		return ERROR;
	if (l->length >= MAX)
		return ERROR;
	//开始循环遍历移动
	for (int j = (l->length - 1); j >= (i - 1); j--) {
		l->element[j + 1] = l->element[j];
	}
	l->element[i - 1] = x;
	l->length+=1;
	return OK;
}
//删除线性表中的第i个元素
int DeletEle(struct Sq* l, int i) {
	if (i<1 || i>l->length) {
		return ERROR;
	}
	//l->element[i - 1] = 0;
	for (int j = i-1; j < l->length; j++) {
		l->element[j] = l->element[j - 1];
	}
	l->length--;
	return OK;
}
int main() {
	struct Sq list;//创建实例
	//struct Sq* L = (struct Sq*)malloc(sizeof(struct Sq));//创建一个结构体指针
	//初始化该列表
	//printf("%d", sizeof(list));
	struct Sq* p = &list;
	int a=InitSq(p);
	int b = InsertEle(p, 5, 1);
	printf("%d\n", p->element[0]);
	printf("%d", GetEle(p, 2));
	int c = DeletEle(p, 1);
	printf("%d\n", p->element[0]);
	printf("%d %d %d\n", a,b,c);
	printf("%d", sizeof(list));
	DestoryList(p);
	printf("\n%d", sizeof(list));
	return 0;
}