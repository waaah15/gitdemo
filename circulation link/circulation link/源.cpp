#include<stdio.h>//循环链表
#include<stdlib.h>

typedef struct {
	int age;
}student;//学生类型

typedef struct node{
	student stu;
	struct node *next;
}Node;//定义节点类型
//创建结点函数
Node *creadenode(student *stu) {
	//申请结点的内存空间
	Node *node=(Node*)malloc(sizeof(Node));
	if (!node) { 
		return NULL;
	}
	node->stu = *stu;
	node->next = NULL;
	return node;
}
//传入参数
int inputnode(student* stu) {
	if (!stu) return 0;
	printf("请输入学生的年龄\n");
	scanf_s("%d",&stu->age);
	return 1;
}
//初始化单链表
Node* linkinit() {
	//创建头节点
	student stu = { 0 };
	Node* head = creadenode(&stu);
	if (!head)return NULL;
	//不断添加新结点，尾插
	Node* tail = head;
	printf("是否继续输入新结点，是输入1，否则输入0\n");
	int tag;
	scanf_s("%d", &tag);
	Node* pnew;
	while (tag != 0) {
		inputnode(&stu);
		pnew = creadenode(&stu);
		if (!pnew)return NULL;
		tail->next = pnew;
		tail = pnew;
		printf("是否继续添加新结点，是输入1，否则输入0\n");
		scanf_s("%d", &tag);
	}
	tail->next = head;
	//循环单链表是在单链表的基础上，将下一个再指向头结点
	return head;
	
}
//销毁链表
int deletelink(Node* head) {
	if (!head) return 0;
	Node* p, * q;
	p = head;
	while (p->next != NULL && p->next != head) {
		q = p->next;
		p->next = q->next;
		free(q);
	}
	free(head);
	return 1;
}
//输出数据
void output(student *stu) {
	if (!stu)return;
	printf("学生的年龄%d", stu->age);
}
//遍历链表
void displaylink(Node* head) {
	if (!head) return ;
	Node* p = head->next;
	for (p = head->next; p != head; p = p->next) {
		output(&p->stu);
	}
}
//插入结点
int insetnode(Node* head, Node* pnew, int i) {
	if (!head)return 0;
	if (!pnew)return 0;
	int n = 0;
	Node* p = head;
	for (n = 0; n<i && p->next!=head; n++) {
		p = p->next;
	}
	pnew->next = p->next;
	p->next = pnew;
	return 1;
}

int main() {
	Node* head = linkinit();
	/*student stu;
	inputnode(&stu);
	Node* q = creadenode(&stu);
	insetnode(head, q, );
	插入新结点*/
	displaylink(head);
	deletelink(head);
	return 0;
}