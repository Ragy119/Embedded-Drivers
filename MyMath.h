#include<stdio.h>
#include"C:\Users\Ragy Ahmed\Downloads\EMBEDDED\Libraries\types.h"
#define pi 3.14159

u16 fact(u8 number)
{
	u16 sum=1;
	printf("fact func \n");
	for (u8 i=1;i<=number;i++)
	{
		sum=sum*i;
	}
	
	printf("factorial value: %d \n",sum);
	
	return sum;
}


f32 power(f32 x,f32 y)
{
	f32 sum=1;
	printf("power func \n");
	for(f32 i=0;i<y;i++)
	{
		sum=sum*x;
	}
	
	printf("power value: %f \n",sum);
	
	return sum;
}



f32 sinn(f32 deg)
{	
	f32 sum,rad;
	rad=(deg*2*pi)/360;
	sum= rad-((power(rad,3))/fact(3))+((power(rad,5))/fact(5))-((power(rad,7))/fact(7));
	
	return sum;
}


f32 coss(f32 deg)
{
	f32 sum,rad;
	rad=(deg*2*pi)/360;
	sum= 1-((power(rad,2))/fact(2))+((power(rad,4))/fact(4))-((power(rad,6))/fact(6));
	
	return sum;
}