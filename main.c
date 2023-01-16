#include<RGG52.H>
#include<intrins.h>



void Delay100ms()
{
	unsigned char i, j, k;


	i = 5;
	j = 52;
	k = 195;
	do
	{
		do
		{
			while (--k);
		} while (--j);
	} while (--i);
}

void main(){
p1^0=1;
	while(1){
		Delay100ms();
		if(p3^4==1){
			~p1^0;
		}
		Delay100ms();
		
	}
}