#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>
#define max 50
/*创建运算符栈*/
struct operstack {
	char sign[50];
	int top;
};

void inito(struct operstack* oper) {/*初始化运算符栈*/
	oper->top = -1;
}




void inter_oper(struct operstack* oper, char s) {/*运算符入栈*/
	if (oper->top < 49) {
		oper->top++;
		oper->sign[oper->top] = s;
	}
}

char oper_read(struct operstack* oper) {/*读取运算符栈*/
	char d;
	d = oper->sign[oper->top];
	return d;

}
char oper_out(struct operstack* oper) {/*运算符出站*/
	char a;
	a = oper->sign[oper->top];
	oper->top--;
	return a;
}

/*创建数据栈*/
struct datastack {
	double data[50];
	int top;
};

void initd(struct datastack* num) {/*初始化数据栈*/
	num->top = -1;
}




void inter_datastack(struct datastack* num, double number) {/*数据入栈*/
	int cm;
	cm = num->top;
	if (num->top < 49) {
		num->top++;
		num->data[cm] = number;
	}
	else return;
}

double num_read(struct datastack* num) {/*读取数据栈*/
	double e;
	e = num->data[num->top];
	return e;

}
double datastack_out(struct datastack* num) {/*数据出栈*/
	double f;
	f = num->data[num->top];
	num->top--;
	return f;
}

/*符号优先级判断*/
int priority(char fu) {
	if (fu = '(') {
		return 1;
	}
	if (fu == '+' || fu == '-') {
		return 2;
	}
	if (fu == '*' || fu == '/') {
		return 3;
	}
	if (fu == ')') {
		return 4;
	}
}
/*五则运算*/
int count(double su1, double su2, char c) {
	int sum, i;
	switch (c) {
	case '+': {
		sum = su1 + su2;
		break;
	}
	case'-': {
		sum = su1 - su2;
		break;
	}
	case '*': {
		sum = su1 * su2;
		break;
	}
	case '/': {
		sum = su1 / su2;
		break;
	}
	case'^': {
		for (i = 0; i < su2; i++) {
			sum *= su1;
		}
		break;
	}
	}
}
/*敲了一个上午，终于挺进主函数*/
int main() {
	struct operstack oper;
	struct datastack num;
	int i = 0, j, k, v1, v2, jieguo, d = 0;
	double temp;
	char c[200];
	char a[200] = { 0 };
	char* str = (char*)malloc(sizeof(char) * 200);
	scanf("%s", &c[200]);
	while (c[d] != '\0') {
		str[d++] = c[d++];
	}
	str[d] = '\0';
	while (str[i] != '\0') {
		i++;
		if (str[i] >= '0' && str[i] <= '9') {
			while (str[i] >= '0' && str[i] <= '9' || str[i] == '.') {
				a[j++] = str[i++];
			}
			temp = (double)atof(a);
			inter_datastack(&num, temp);
			while (j > 0) {
				j--;
			}
			i--;
		}
		else if ((oper.top) == -1) {
			inter_oper(&oper, str[i]);
		}
		else if (priority(str[i]) == 1) {
			inter_oper(&oper, str[i]);
		}
		else if (priority(str[i]) == 2) {
			if (priority(oper_read(&oper)) == 1) {
				inter_oper(&oper, str[i]);
			}
			else if (priority(oper_read(&oper)) == 2) {
				while (oper.top >= 0 && num.top >= 1) {
					v2 = datastack_out(&num);
					v1 = datastack_out(&num);
					jieguo = count(v1, v2, oper_out(&oper));
					inter_datastack(&num, jieguo);
				}
				inter_oper(&oper, str[i]);
			}
			else if (priority(oper_read(&oper)) == 3) {
				while (oper.top >= 0 && num.top >= 1) {
					v2 = datastack_out(&num);
					v1 = datastack_out(&num);
					jieguo = count(v1, v2, oper_out(&oper));
					inter_datastack(&num, jieguo);
				}
				inter_oper(&oper, str[i]);
			}

		}
		else if (priority(str[i]) == 3) {
			if (priority(oper_read(&oper)) == 1) {
				inter_oper(&oper, str[i]);
			}
			else if (priority(oper_read(&oper)) == 2) {
				inter_datastack(&num, str[i]);

			}
			else if (priority(oper_read(&oper)) == 3) {
				while (oper.top >= 0 && num.top >= 1) {
					v2 = datastack_out(&num);
					v1 = datastack_out(&num);
					jieguo = count(v1, v2, oper_out(&oper));
					inter_datastack(&num, jieguo);
				}
				inter_oper(&oper, str[i]);
			}
		}
		else if (priority(str[i]) == 4) {
			do {
				v2 = datastack_out(&num);
				v1 = datastack_out(&num);
				jieguo = count(v1, v2, oper_out(&oper));
				inter_datastack(&num, jieguo);
			} while (priority(oper_read(&oper)) != 1);
			oper_out(&oper);
		}


	}



	while (oper.top != -1) {
		v2 = datastack_out(&num);
		v1 = datastack_out(&num);
		jieguo = count(v1, v2, oper_read(&oper));
		inter_datastack(&num, jieguo);
	}
	printf("%lf", num.data[0]);
	return 0;
}