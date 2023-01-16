#include<reg51.h>

void Delay100us()		//@11.0592MHz
{
	unsigned char i;

	i = 43;
	while (--i);
}
void main(){
    p1^1=1;
	while(1){
		Delay100us();
		if(p3^4==1){
			~p1^1;
		}
		Delay100us();
	}
	
}