#include<stdio.h>//ѭ������
#include<stdlib.h>

typedef struct {
	int age;
}student;//ѧ������

typedef struct node{
	student stu;
	struct node *next;
}Node;//����ڵ�����
//������㺯��
Node *creadenode(student *stu) {
	//��������ڴ�ռ�
	Node *node=(Node*)malloc(sizeof(Node));
	if (!node) { 
		return NULL;
	}
	node->stu = *stu;
	node->next = NULL;
	return node;
}
//�������
int inputnode(student* stu) {
	if (!stu) return 0;
	printf("������ѧ��������\n");
	scanf_s("%d",&stu->age);
	return 1;
}
//��ʼ��������
Node* linkinit() {
	//����ͷ�ڵ�
	student stu = { 0 };
	Node* head = creadenode(&stu);
	if (!head)return NULL;
	//��������½�㣬β��
	Node* tail = head;
	printf("�Ƿ���������½�㣬������1����������0\n");
	int tag;
	scanf_s("%d", &tag);
	Node* pnew;
	while (tag != 0) {
		inputnode(&stu);
		pnew = creadenode(&stu);
		if (!pnew)return NULL;
		tail->next = pnew;
		tail = pnew;
		printf("�Ƿ��������½�㣬������1����������0\n");
		scanf_s("%d", &tag);
	}
	tail->next = head;
	//ѭ�����������ڵ�����Ļ����ϣ�����һ����ָ��ͷ���
	return head;
	
}
//��������
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
//�������
void output(student *stu) {
	if (!stu)return;
	printf("ѧ��������%d", stu->age);
}
//��������
void displaylink(Node* head) {
	if (!head) return ;
	Node* p = head->next;
	for (p = head->next; p != head; p = p->next) {
		output(&p->stu);
	}
}
//������
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
	�����½��*/
	displaylink(head);
	deletelink(head);
	return 0;
}