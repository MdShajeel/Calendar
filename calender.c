#include<stdio.h>
int cal(int day,int a[][7],int limit)
{
	int i,j,y,v=1;
	for(j=day;j<7;j++)
	{
		a[0][j]=v;
		v++;
	}
	for(i=1;i<6&&v<=limit;i++)
	{
		y=0;
		for(j=0;j<7&&v<=limit;j++)
		{
			a[i][j]=v++;
			y++;
		}
	}
	return y;
}
int main()
{
	int ref_year=1900,user_year,leap_years=0,total_days,diff_years,day,month_counter=0;
	printf("Enter value for year : ");
	scanf("%d",&user_year);
	if(user_year<1900)
	{
		printf("\nEnter year above 1900");
		return 0;
	}
	diff_years=user_year-ref_year;
	while(ref_year<user_year)
	{
		if( (ref_year%100 == 0 && ref_year%400 == 0) || (ref_year%100 != 0 && ref_year%4== 0)) 
		leap_years++;
		ref_year++;
	}
	total_days=((diff_years-leap_years)*365)+(leap_years*366);
	day=total_days%7;
	int a[6][7]={0},i,j;
	char month[12][20]={"January","Feburary","March","April","May","June","July","August","September","October","November","December"};
	
	label : 
	if(month_counter==0||month_counter==2||month_counter==4||month_counter==6||month_counter==7||month_counter==9||month_counter==11)
		day=cal(day,a,31);
	else if(month_counter==3||month_counter==5||month_counter==8||month_counter==10)
		day=cal(day,a,30);
	else if(month_counter==1&&(ref_year%100 == 0 && ref_year%400 == 0) || (ref_year%100 != 0 && ref_year%4== 0))
		day=cal(day,a,29);
	else
		day=cal(day,a,28);
	printf("%s-%d\n\n",month[month_counter],user_year);
	printf("Mon \tTue \tWed \tThu \tFri \tSat \tSun\n");
	for(i=0;i<6;i++)
	{
		for(j=0;j<7;j++)
		{
			printf("|");
			if(a[i][j]==0)
				printf("  \t");
			else
				printf("%d\t",a[i][j]);
			a[i][j]=0;
		}
		printf("\n");
	}
	month_counter++;
	if(month_counter==12)
	return;
	goto label;
}
