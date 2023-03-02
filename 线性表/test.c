#include<stdio.h>
#include<stdlib.h>
#define OK 0
#define ERROR -1
#define MAX 1000
typedef int DataType;//���Ա��е��������ͣ����޸�
typedef struct Sq {//���Ա���Ԫ��+������ɣ�Ԫ���������ʾ
	DataType* element;
	int length;
};
//��ʼ������
int InitSq(struct Sq* l) {
	l->element = (DataType*)malloc(MAX * sizeof(DataType));//Ϊ���Ա��Ԫ�ض�̬�����ڴ�ռ䣬��ʼΪ0
	l->length = 0;//��ʼ��Ϊ0
	if (!l->element) {
		return ERROR;//����ʧ�ܷ���1
	}
	return OK;
}
//�������Ա�,��������ڴ�ռ�����
void DestoryList(struct Sq* l) {
	free(l->element);
}
//������Ա�������Ϊ��
void ClearList(struct Sq* l) {
	l->length = 0;
}
//�����Ա���
int LenList(struct Sq* l) {
	return l->length;
}
//�Ƿ�Ϊ�ձ�
int EmptyList(struct Sq* l) {
	if (l->length == 0)
		return 1;
	return 0;
}
//˳����ȡֵ�������ڼ���Ԫ�أ�����Ԫ��ֵ
int GetEle(struct Sq* l, int i) {
	if (i<0 || i>l->length)
		return ERROR;
	return l->element[i-1];
}
//����ĳ��Ԫ���Ƿ����,�����ڷ����ǵڼ���Ԫ��
int GetIndex(struct Sq* l, DataType x) {
	for (int i = 0; i < l->length; i++) {
		if (l->element[i] == x) {
			return i+1;
		}
	}
	return OK;
}
//Ԫ�ز�����ָ��λ��(���±�)����ĳ��Ԫ��
int InsertEle(struct Sq* l, DataType x, int i) {
	if (i < 1||i>(l->length)+1)//l->length��ʾ��ǰ���һ��Ԫ�أ�+1��ʾ���������һ��Ԫ��֮��׷��
		return ERROR;
	if (l->length >= MAX)
		return ERROR;
	//��ʼѭ�������ƶ�
	for (int j = (l->length - 1); j >= (i - 1); j--) {
		l->element[j + 1] = l->element[j];
	}
	l->element[i - 1] = x;
	l->length+=1;
	return OK;
}
//ɾ�����Ա��еĵ�i��Ԫ��
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
	struct Sq list;//����ʵ��
	//struct Sq* L = (struct Sq*)malloc(sizeof(struct Sq));//����һ���ṹ��ָ��
	//��ʼ�����б�
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