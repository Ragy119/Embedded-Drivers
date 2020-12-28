#include"types.h"
#include"LCD.h"


void LCD_Write_Number(f64 no)
{
	
	
	u8 temp_DP  = ((u64)(no*100))%100;
	u64 temp    = (u64)no;

	u8 first_no_after_DP  = (temp_DP/10)%10;                  //DP == Decimal point
	u8 second_no_after_DP = temp_DP%10;

	u8 first_no  =	temp%10;
	u8 second_no =	(temp/10)%10;
	u8 third_no  =	(temp/100)%10;
	u8 fourth_no =	(temp/1000)%10;


	if(fourth_no == 0){}
	else
	{
		Write_data(fourth_no+48);
	}

	if(fourth_no == 0 && third_no == 0){}
	else
	{
		Write_data(third_no+48);
	}

	if(fourth_no == 0 && third_no == 0 && second_no == 0){}
	else
	{
		Write_data(second_no+48);
	}

	Write_data(first_no+48);


	if(first_no_after_DP == 0 && second_no_after_DP == 0){}
	else
	{
		Write_data('.');
		Write_data(first_no_after_DP+48);
		Write_data(second_no_after_DP+48);
	}
	
		
	
	
}
