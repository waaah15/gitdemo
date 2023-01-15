#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>
#define max 50
/*���������ջ*/
struct operstack {
	char sign[50];
	int top;
};

void inito(struct operstack* oper) {/*��ʼ�������ջ*/
	oper->top = -1;
}




void inter_oper(struct operstack* oper, char s) {/*�������ջ*/
	if (oper->top < 49) {
		oper->top++;
		oper->sign[oper->top] = s;
	}
}

char oper_read(struct operstack* oper) {/*��ȡ�����ջ*/
	char d;
	d = oper->sign[oper->top];
	return d;

}
char oper_out(struct operstack* oper) {/*�������վ*/
	char a;
	a = oper->sign[oper->top];
	oper->top--;
	return a;
}

/*��������ջ*/
struct datastack {
	double data[50];
	int top;
};

void initd(struct datastack* num) {/*��ʼ������ջ*/
	num->top = -1;
}




void inter_datastack(struct datastack* num, double number) {/*������ջ*/
	int cm;
	cm = num->top;
	if (num->top < 49) {
		num->top++;
		num->data[cm] = number;
	}
	else return;
}

double num_read(struct datastack* num) {/*��ȡ����ջ*/
	double e;
	e = num->data[num->top];
	return e;

}
double datastack_out(struct datastack* num) {/*���ݳ�ջ*/
	double f;
	f = num->data[num->top];
	num->top--;
	return f;
}

/*�������ȼ��ж�*/
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
/*��������*/
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
/*����һ�����磬����ͦ��������*/
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