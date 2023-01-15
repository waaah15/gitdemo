//顺序栈的简单操作
#include<stdio.h>
#include<stdlib.h>
#define init_list_size 3
#define list_increment 1
typedef struct {
	int age;
	int hength;
}student;//学生的信息

typedef struct {
	student *stu;//每个数组元素的数据类型
	int stunumber;//学生个数
	int listlength;//链表长度
}squlist;
//初始化一个顺序表
int initlist(squlist* st1) {
	//初始化顺序表，第一步要申请空间
	st1->stu = (student*)malloc(init_list_size * sizeof(student));
	//申请到学生所占用内存的空间，强制类型转换为student的类型
		//第二步，判断是否申请到了空间
	if (!st1->stu) {
		exit(-1);
		//exit函数返回非零的数时，表示为异常退出，返回零时，便是为正常退出。存在于stdlib.h中
	}
	st1->stunumber = 0;
	st1->listlength = init_list_size;
	//第三步，申请到了空间，就要创建一个顺序表
	return 1;
}
//顺序表使用完后就要销毁顺序表
int deletelist(squlist* st1) {
	//1.判断顺序表是否为空
	if (st1->stu == NULL) {
		return 0;
	}
	//2.如果存在，释放顺序表内存
	free(st1->stu);
		//3.释放完内存，恢复表的初始值
	st1->stunumber = 0;
	st1->listlength = 0;
	return 1;
}
//遍历顺序表
void findalllist(squlist* st1) {
	int i = 0;
	for (i = 0; i < st1->stunumber; i++) {
		printf("age = %5d,heigh = %5d\n", st1->stu[i].age, st1->stu[i].hength);
	}
}

//查找链表中的数
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
//打印成员信息函数
void display(student* stu) {
	if (!stu)return;
	printf("age=%d,heigh=%d", stu->age, stu->hength);
}
//增加数组长度
int extantlist(squlist* st1) {
	//1.申请内存
	student *p = (student*)realloc(st1->stu, (st1->listlength + list_increment)*sizeof(student));
	//2.判断是否申请到了内存
	if (!p) { exit(-1); 
	}
    //申请到内存后，更新顺序表内容
	st1->stu = p;
	st1->listlength += list_increment;
	return 1;
}
//复制函数
void copylist(student* s1, student* s2) {
	s1->age = s2->age;
	s1->hength = s2->hength;
}
//在顺序栈的尾部添加
void insetlist(squlist *st1,student *s){
	if (st1->stunumber >= st1->listlength){
		extantlist(st1);
	}
	//2有足够的空间，插入复制的量
	copylist(&st1->stu[st1->stunumber], s);
	//3复制完后，更新顺序表长度
	st1->stunumber++;
}

int main(){
	//添加测试用例
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
	printf("插入元素之后的顺序表\n");
	insetlist(&st1,&s);
	findalllist(&st1);
	deletelist(&st1);
	return 0;
}