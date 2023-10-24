//C program to input a year and month and display the calender 
#include<stdio.h>
#include<conio.h>
int main()
{
	int year,month_num;
	const char *month_name="";
	int jan_1st_day,month_days,sum_of_days=0;
	int days_of_month[]={31,28,31,30,31,30,31,31,30,31,30,31};
	printf("Enter a year: ");
	scanf("%d",&year);
	printf("\nEnter the month number: ");
	scanf("%d",&month_num);
	
	/*using Zeller's formula to find on  which day 
	january 1st lies for the years between 2000 and 2100 ;
	obtained from online references*/
	 if(year>=2000 && year<=2099)
	 {
	 	double y=(year%100)/4;
	 	double copy=y;
	 	int count=0;
	 	while(copy>0)
	 	{
	 		copy/=10;
	 		count++;
		 }
		 if(count!=1)
		 	y++;
		int y1=(int)y;
		jan_1st_day=6+(year%100)+y1;
		jan_1st_day%=7;
	 }
	 
	 /*using zellers formula to find on which day Jan 1st
	 lies for the remaining years i.e above 1000 and below 2000*/
	 else
	 {
	 	jan_1st_day=year+(year/4)-(year/100)+(year/400)+((13*13+8)/5)+1;
	 	jan_1st_day%=7;
	 	jan_1st_day-=1;
	}
	
	/*Using switch case to find month name 
	from the month number that the user entered*/
	switch(month_num)
	{
		case 1:
			month_name="January";
			break;
		case 2:
			month_name="February";
			break;
		case 3:
			month_name="March";
			break;
		case 4:
			month_name="April";
			break;
		case 5:
			month_name="May";
			break;
		case 6:
			month_name="June";
			break;
		case 7:
			month_name="July";
			break;
		case 8:
			month_name="August";
			break;
		case 9:
			month_name="September";
			break;
		case 10:
			month_name="October";
			break;
		case 11:
			month_name="November";
			break;
		case 12:
			month_name="December";
			break;
		default:
			printf("You have entered an invalid month number");		
	}
	
	//To find how many days are there in each month
	if(month_num==2) //for the month february
	//checking if the entered year is leap year or not
		if(year%4==0 &&year%100!=0||year%400==0)//leap year condition
		{
			month_days=29; //leap year
			days_of_month[1]=29;
		}
		else
			month_days=28; //not leap year
	else if(month_num==1||month_num==3||month_num==5||month_num==7||month_num==8||month_num==10||month_num==12)
		month_days=31;
	else
		month_days=30;
		
	/*To find on which day the date 1st 
	lies for the months other than january*/
	for(int i=0;i<month_num-1;i++)
		sum_of_days+=days_of_month[i];
	sum_of_days%=7;
	sum_of_days+=jan_1st_day;
	if(sum_of_days>=7)
		sum_of_days-=7;
		
	//Printing the calender in a formatted way
	int date=1;
	printf("\n------------------------------------------------------\n");
	printf("\t\t\t %s %d \n",month_name,year);
	printf("\n------------------------------------------------------\n");
	printf("Sun \t Mon \t Tue \t Wed \t Thur \t Fri \t Sat");
	printf("\n------------------------------------------------------\n");
	//print the dates of the entered month 
	for(int i=0;i<8;i++)
	{
		for(int j=0;j<7;j++)
		{
			if(i==0&&sum_of_days>=7)
				continue;
			if(date>month_days)
				break;
			if(i==0 && j<sum_of_days)
				printf(" \t ");
			else
				if(date<9)
					printf("%d \t ",date++);
				else
					printf("%d \t",date++);
		}
		if(date>month_days)
			break;
		printf("\n");
	}
	printf("\n");
	printf("\n------------------------------------------------------\n");
	getch();
}

	
	 
	
