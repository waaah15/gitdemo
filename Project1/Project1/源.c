//˳��ջ�ļ򵥲���
#include<stdio.h>
#include<stdlib.h>
#define init_list_size 3
#define list_increment 1
typedef struct {
	int age;
	int hength;
}student;//ѧ������Ϣ

typedef struct {
	student *stu;//ÿ������Ԫ�ص���������
	int stunumber;//ѧ������
	int listlength;//������
}squlist;
//��ʼ��һ��˳���
int initlist(squlist* st1) {
	//��ʼ��˳�����һ��Ҫ����ռ�
	st1->stu = (student*)malloc(init_list_size * sizeof(student));
	//���뵽ѧ����ռ���ڴ�Ŀռ䣬ǿ������ת��Ϊstudent������
		//�ڶ������ж��Ƿ����뵽�˿ռ�
	if (!st1->stu) {
		exit(-1);
		//exit�������ط������ʱ����ʾΪ�쳣�˳���������ʱ������Ϊ�����˳���������stdlib.h��
	}
	st1->stunumber = 0;
	st1->listlength = init_list_size;
	//�����������뵽�˿ռ䣬��Ҫ����һ��˳���
	return 1;
}
//˳���ʹ������Ҫ����˳���
int deletelist(squlist* st1) {
	//1.�ж�˳����Ƿ�Ϊ��
	if (st1->stu == NULL) {
		return 0;
	}
	//2.������ڣ��ͷ�˳����ڴ�
	free(st1->stu);
		//3.�ͷ����ڴ棬�ָ���ĳ�ʼֵ
	st1->stunumber = 0;
	st1->listlength = 0;
	return 1;
}
//����˳���
void findalllist(squlist* st1) {
	int i = 0;
	for (i = 0; i < st1->stunumber; i++) {
		printf("age = %5d,heigh = %5d\n", st1->stu[i].age, st1->stu[i].hength);
	}
}

//���������е���
int fineonelist(squlist* st1, student *stu) {
	int k=0;
	while (k < st1->stunumber) {
		if ((st1->stu[k].age == stu->age) && (st1->stu[k].hength == stu->hength)) {
			return 1;
		}
		k++;
	}
	return 0;
}
//��ӡ��Ա��Ϣ����
void display(student* stu) {
	if (!stu)return;
	printf("age=%d,heigh=%d", stu->age, stu->hength);
}
//�������鳤��
int extantlist(squlist* st1) {
	//1.�����ڴ�
	student *p = (student*)realloc(st1->stu, (st1->listlength + list_increment)*sizeof(student));
	//2.�ж��Ƿ����뵽���ڴ�
	if (!p) { exit(-1); 
	}
    //���뵽�ڴ�󣬸���˳�������
	st1->stu = p;
	st1->listlength += list_increment;
	return 1;
}
//���ƺ���
void copylist(student* s1, student* s2) {
	s1->age = s2->age;
	s1->hength = s2->hength;
}
//��˳��ջ��β�����
void insetlist(squlist *st1,student *s){
	if (st1->stunumber >= st1->listlength){
		extantlist(st1);
	}
	//2���㹻�Ŀռ䣬���븴�Ƶ���
	copylist(&st1->stu[st1->stunumber], s);
	//3������󣬸���˳�����
	st1->stunumber++;
}

int main(){
	//��Ӳ�������
	squlist st1;
	student stu;
	initlist(&st1);
	for (int j = 0; j <st1.listlength; j++) {
		scanf_s("%d,%d", &st1.stu[j].age,&st1.stu[j].hength);
		st1.stunumber++;
	}
	findalllist(&st1);
	student s = { 10,10 };
	//fineonelist(&st1,&s);
	display(&s);
	printf("����Ԫ��֮���˳���\n");
	insetlist(&st1,&s);
	findalllist(&st1);
	deletelist(&st1);
	return 0;
}