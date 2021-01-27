#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#include<conio.h>
#define size 600000//IP地址文件行数 
typedef struct IP//定义ip结构体 
{
	int a1,a2,a3,a4;//起始地址 
	int b1,b2,b3,b4;//结束地址 
	char ipmessage[100];//地址所属地信息 
}ip;
ip line[size];//定义IP所在行的位置 
int p1,p2,p3,p4,q1,q2,q3,q4,i,j,j1,y,z,x;
int p11[100000],p22[100000],p33[100000],p44[100000];//多个IP地址的输入 
int r[10];
int t,e,k,g;
char a[100];
int fsize()
{
	int N=1;
	FILE *fp;
	char flag;
	fp=fopen("ip.txt","r");
	if(fp==NULL)
	{
		printf("error open!\n");
		exit(0);	
	}//打开文件
	while(!feof(fp))
	{
		flag=fgetc(fp);
		if(flag=='\n')
			N++;
	}
	fclose(fp);
	return N; 
}//计算文件行数 
int compare(int m1,int m2,int m3,int m4,int n1,int n2,int n3,int n4)
{
	int p=1;
	if(m1>n1)
		p=0;
	else if(m1==n1)
	{
		if(m2>n2)
			p=0;
		else if(m2==n2)
		{
			if(m3>n3)
				p=0;
			else if(m3==n3)
			{
				if(m4>n4)
					p=0;
			}
		}
	}
	return p;
}//比较得到地址值 
void country(char s[100])
{
	j=0;
	z=strlen(s);
	for(i=0;i<z;i++)
	{
		if(s[i]=='|')
			r[j++]=i;
	}
	for(i=0;i<r[0];i++)
		printf("%c",s[i]);
	printf(" ");
}//只输出国家 
void province(char s[100])
{
	j=0;
	z=strlen(s);
	for(i=0;i<z;i++)
	{
		if(s[i]=='|')
			r[j++]=i;
	}
	for(i=r[1]+1;i<r[2];i++)
		printf("%c",s[i]);
	printf(" ");
}//只输出省份 
void city(char s[100])
{
	j=0;
	z=strlen(s);
	for(i=0;i<z;i++)
	{
		if(s[i]=='|')
			r[j++]=i;
	}
	for(i=r[2]+1;i<r[3];i++)
		printf("%c",s[i]);
	printf(" ");
}//只输出城市 
void ISP(char s[100])
{
	j=0;
	z=strlen(s);
	for(i=0;i<z;i++)
	{
		if(s[i]=='|')
			r[j++]=i;
	}
	for(i=r[3]+1;i<z;i++)
		printf("%c",s[i]);
	printf(" ");
}//只输出ISP 
void collect()
{
	void function();//调用整个程序驱动函数 
	system("cls");
	system("color F3");
	FILE *fp;
	fp=fopen("collection.txt","a+");
	if(fp==NULL)
	{
		printf("error open\n");
		exit(0);
	}
	while(fgets(a,100,fp))
	{
		printf("%s",a);
	}//打开我的收藏所在的IP地址查询结果写入文件 
	fclose(fp);
	printf("\n\n\n****************************************1.返回桌面	2.退出***************************************\n");
	scanf("%d",&t);
	system("cls");
	if(t==1)
	{
		function();
	}
	else
	{
		printf("\n\n\n\n\n\n");
		printf("\t\t\t\t\t1.确定	2.取消\n");
		scanf("%d",&k);
		if(k==1)
			exit(0);
		else
			collect();//调用collect收藏函数 
	}
}// 我的收藏 
void findip1()
{
	compare;
	country;
	province;
	city;
	ISP;
	void function();
	int row=fsize();
	printf("\t\t\t\t****请选择您的查询范围:****\n");
	scanf("%d",&y);
	do
	{
		system("cls");
		system("color E3");
		printf("\t\t\t\t****请输入您要查询的IP地址:****\n");
		scanf("%d.%d.%d.%d",&p1,&p2,&p3,&p4); 
		do{
			if(p1>=0&&p1<=255&&p2>=0&&p2<=255&&p3>=0&&p3<=255&&p4>=0&&p4<=255)
				break;
			else
			{
				printf("\n\n");
				printf("\t\t\t您输入的数据不合理，请重新输入:\n");
				scanf("%d.%d.%d.%d",&p1,&p2,&p3,&p4);
			}
		}while(1);
		system("cls");
		FILE *fp;
		fp=fopen("collection.txt","a+");
		for(j=1;j<=row;j++)//查找输出对应IP地址的所属地 
		{
			if(compare(line[j].a1,line[j].a2,line[j].a3,line[j].a4,p1,p2,p3,p4)==1&&compare(p1,p2,p3,p4,line[j].b1,line[j].b2,line[j].b3,line[j].b4)==1)
			{
				//自定义输出 
				if(y==1)
				{
					printf("\t\t\t\t**查询结果输出格式为:IP地址 国家|区域|省份|城市|ISP**\n");
					printf("%d.%d.%d.%d	%s\n",p1,p2,p3,p4,line[j].ipmessage);
					break;
				}
				else if(y==2)
				{
					printf("%d.%d.%d.%d	",p1,p2,p3,p4);
					country(line[j].ipmessage);
					printf("\n");
					break;
				}
				else if(y==3)
				{
					printf("%d.%d.%d.%d	",p1,p2,p3,p4);
					province(line[j].ipmessage);
					printf("\n");
					break;
				}
				else if(y==4)
				{
					printf("%d.%d.%d.%d	",p1,p2,p3,p4);
					city(line[j].ipmessage);
					printf("\n");
					break;
				}
				else if(y==5)
				{
					printf("%d.%d.%d.%d	",p1,p2,p3,p4);
					ISP(line[j].ipmessage);
					printf("\n");
					break;
				}
			}
		}
		printf("您是否要保存查询结果 1.yes 2.no\n");
		scanf("%d",&k);
		if(k==1)
		{
			if(fp==NULL)
				printf("error open!\n");	
			fprintf(fp,"%d.%d.%d.%d %s",p1,p2,p3,p4,line[j].ipmessage);
			fputs("\n",fp);	
		}//对查询结果进行保存 
		fclose(fp);
		printf("您是否要继续查询	1.yes 2.no\n");
		scanf("%d",&z);
		if(z==2)
		{
			system("cls");
			printf("\n\n\n\n\n\n");
			printf("\t\t\t\t1.返回桌面	2.退出\n");
			scanf("%d",&t);
			system("cls");
			if(t==1)
			{
				function();
			}
			else
				break; 
		}
		else
			continue;
		system("cls");
	}while(1);
}//执行一组IP地址查询
void findip2()
{
	void function();
	int row=fsize();
	compare;
	int n=0;
	do
	{
		system("cls");
		system("color E3");
		printf("\t\t\t\t****请输入您要查询的IP地址:*****\n");
		printf("\t\t\t\t****结束输入请输入520.20.13.14**\n\n");
		while(scanf("%d.%d.%d.%d",&p1,&p2,&p3,&p4)!=EOF)
		{
			if(p1==520&&p2==20&&p3==13&&p4==14)
				break;
			else
			{
				do{
					if(p1>=0&&p1<=255&&p2>=0&&p2<=255&&p3>=0&&p3<=255&&p4>=0&&p4<=255)
						break;
					else
					{
						printf("\n\n");
						printf("\t\t\t您输入的数据不合理，请重新输入:\n");
						scanf("%d.%d.%d.%d",&p1,&p2,&p3,&p4);
					}
				}while(1);
				n++;
				p11[n]=p1;
				p22[n]=p2;
				p33[n]=p3;
				p44[n]=p4;
			}
		}
		printf("********************************您是否要保存查询结果 1.yes 2.no***************************\n");
		scanf("%d",&k);
		system("cls");
		printf("\t\t\t\t**查询结果输出格式为:IP地址 国家|区域|省份|城市|ISP**\n");
		FILE *fp;
		fp=fopen("collection.txt","a+");
		if(fp==NULL)
			printf("error open!\n");	
		for(j=1;j<=n;j++)
		{
			for(j1=1;j1<=row;j1++)//查找输出对应IP地址的所属地 
			{
				if(compare(line[j1].a1,line[j1].a2,line[j1].a3,line[j1].a4,p11[j],p22[j],p33[j],p44[j])==1&&compare(p11[j],p22[j],p33[j],p44[j],line[j1].b1,line[j1].b2,line[j1].b3,line[j1].b4)==1)
				{
					printf("%d.%d.%d.%d	%s\n",p11[j],p22[j],p33[j],p44[j],line[j1].ipmessage);
					if(k==1)
					{
						fprintf(fp,"%d.%d.%d.%d %s",p11[j],p22[j],p33[j],p44[j],line[j1].ipmessage);
						fputs("\n",fp);	//对查询结果进行保存 
					}
				}
			}
		}
		fclose(fp);
		printf("您是否要继续查询	1.yes 2.no\n");
		scanf("%d",&z);
		if(z==2)
		{
			system("cls");
			printf("\n\n\n\n\n\n");
			printf("\t\t\t\t1.返回桌面	2.退出\n");
			scanf("%d",&t);
			system("cls");
			if(t==1)
			{
				function();
			}
			else
				break;
		}
		else
			continue;
		system("cls");
	}while(1);
}//执行多组IP地址查询
void findip3()
{
	void function();
	int row=fsize();
	compare;
	do
	{
		system("cls");
		system("color E3");
		printf("\t\t\t\t****请输入您要查询的IP地址:****\n\n");
		printf("例如：219.235.224.1-219.236.1.1\n");
		scanf("%d.%d.%d.%d-%d.%d.%d.%d",&p1,&p2,&p3,&p4,&q1,&q2,&q3,&q4); 
		do{
			if(p1>=0&&p1<=255&&p2>=0&&p2<=255&&p3>=0&&p3<=255&&p4>=0&&p4<=255&&q1>=0&&q1<=255&&q2>=0&&q2<=255&&q3>=0&&q3<=255&&q4>=0&&q4<=255)
				break;
			else
			{
				printf("\n\n");
				printf("\t\t\t您输入的数据不合理，请重新输入:\n");
				scanf("%d.%d.%d.%d-%d.%d.%d.%d",&p1,&p2,&p3,&p4,&q1,&q2,&q3,&q4);
			}
		}while(1);
		printf("******************************您是否要保存查询结果 1.yes 2.no************************\n");
		scanf("%d",&k);
		system("cls");
		printf("\t\t\t\t**查询结果输出格式为:IP地址 国家|区域|省份|城市|ISP**\n");
		FILE *fp;
		fp=fopen("collection.txt","a+");
		for(j=1;j<=row;j++)//查找输出对应IP地址的所属地 
		{
			if(compare(line[j].a1,line[j].a2,line[j].a3,line[j].a4,p1,p2,p3,p4)==1&&compare(line[j].b1,line[j].b2,line[j].b3,line[j].b4,p1,p2,p3,p4)==0)
			{
				if(compare(q1,q2,q3,q4,line[j].b1,line[j].b2,line[j].b3,line[j].b4)==1)
				{
					printf("%d.%d.%d.%d-%d.%d.%d.%d %s\n",p1,p2,p3,p4,q1,q2,q3,q4,line[j].ipmessage);
					if(k==1)
					{
						if(fp==NULL)
							printf("error open!\n");	
						fprintf(fp,"%d.%d.%d.%d-%d.%d.%d.%d %s\n",p1,p2,p3,p4,q1,q2,q3,q4,line[j].ipmessage);
						fputs("\n",fp);	
					}
				}
				else if(compare(q1,q2,q3,q4,line[j].b1,line[j].b2,line[j].b3,line[j].b4)==0)
				{
					printf("%d.%d.%d.%d-%d.%d.%d.%d %s\n",p1,p2,p3,p4,line[j].b1,line[j].b2,line[j].b3,line[j].b4,line[j].ipmessage);
					if(k==1)
					{
						if(fp==NULL)
							printf("error open!\n");	
						fprintf(fp,"%d.%d.%d.%d-%d.%d.%d.%d %s\n",p1,p2,p3,p4,line[j].b1,line[j].b2,line[j].b3,line[j].b4,line[j].ipmessage);
					}
				}
			}
			else if(compare(line[j].a1,line[j].a2,line[j].a3,line[j].a4,p1,p2,p3,p4)==0&&compare(q1,q2,q3,q4,line[j].b1,line[j].b2,line[j].b3,line[j].b4)==0)
			{
				printf("%d.%d.%d.%d-%d.%d.%d.%d %s\n",line[j].a1,line[j].a2,line[j].a3,line[j].a4,line[j].b1,line[j].b2,line[j].b3,line[j].b4,line[j].ipmessage);
				if(k==1)
					{
						if(fp==NULL)
							printf("error open!\n");
						fprintf(fp,"%d.%d.%d.%d-%d.%d.%d.%d %s\n",line[j].a1,line[j].a2,line[j].a3,line[j].a4,line[j].b1,line[j].b2,line[j].b3,line[j].b4,line[j].ipmessage);
					}
			}
			else if(compare(line[j].a1,line[j].a2,line[j].a3,line[j].a4,q1,q2,q3,q4)==1&&compare(line[j].b1,line[j].b2,line[j].b3,line[j].b4,q1,q2,q3,q4)==0&&compare(line[j].a1,line[j].a2,line[j].a3,line[j].a4,p1,p2,p3,p4)==0)
			{
				printf("%d.%d.%d.%d-%d.%d.%d.%d %s\n",line[j].a1,line[j].a2,line[j].a3,line[j].a4,q1,q2,q3,q4,line[j].ipmessage);
				if(k==1)
					{
						if(fp==NULL)
							printf("error open!\n");	
						fprintf(fp,"%d.%d.%d.%d-%d.%d.%d.%d %s\n",line[j].a1,line[j].a2,line[j].a3,line[j].a4,q1,q2,q3,q4,line[j].ipmessage);
					}
			}
		}//调用IP地址比较函数，查找结果 
		fclose(fp);
		printf("您是否要继续查询	1.yes 2.no\n");
		scanf("%d",&z);
		if(z==2)
		{
			system("cls");
			printf("\n\n\n\n\n\n");
			printf("\t\t\t\t1.返回桌面	2.退出\n");
			scanf("%d",&t);
			system("cls");
			if(t==1)
			{
				function();
			}
			else
				break;
		}
		else
			continue;
		system("cls");
	}while(1);
}//执行IP地址段查询 
void function()
{
	compare;
	country;
	province;
	city;
	ISP;
	FILE *fp;
	i=1;
	fp=fopen("ip.txt","r");
	if(fp==NULL)
	{
		printf("error open!\n");
		exit(0);	
	}//打开IP地址存储文件 
	while (fscanf(fp,"%d.%d.%d.%d|%d.%d.%d.%d|%s\n",&line[i].a1,&line[i].a2,&line[i].a3,&line[i].a4,&line[i].b1,&line[i].b2,&line[i].b3,&line[i].b4,&line[i].ipmessage)!= EOF)
	{
		i++;				
	}//读取文件 
	fclose(fp); 
	system("color F0");
	system("IP地址查询系统");
	printf("\n\n\n\n\n\n");
	printf("\t\t\t\t\t欢迎进入IP地址查询系统\n");
	Sleep(5000);
	system("cls");
	system("color F4");
	printf("\n\n\n\n\n\n");
	printf("\t\t\t\t	~~~~~~~~Welcome!~~~~~~\n");
	printf("\t\t\t\t	   ***		***\n");
	printf("\t\t\t\t	 ********************\n");
	printf("\t\t\t\t	  ******************\n");
	printf("\t\t\t\t	   ****************\n");
	printf("\t\t\t\t	      ***********\n");
	printf("\t\t\t\t	  	  ***\n");
	printf("\t\t\t\t	  	   *\n");
	system("pause");
	system("cls");
	system("color B0");
	printf("\n\n\n");
	printf("\t\t\t\t	*********************************\n");
	printf("\t\t\t\t	*	1.一组IP地址查询	*\n");
	printf("\t\t\t\t	*	2.多组IP地址查询	*\n");
	printf("\t\t\t\t	*	3.IP地址段查询		*\n");
	printf("\t\t\t\t	*	4.我的收藏		*\n");
	printf("\t\t\t\t	*	5.退出系统		*\n");
	printf("\t\t\t\t	*********************************\n");
	printf("\t\t\t\t	请输入要操作的编号:");
	scanf("%d",&x);//主界面（桌面） 
	do{
		if(x>=1&&x<=5)
			break;
		else
		{
			printf("\n\n");
			printf("\t\t\t您输入的数据不合理，请重新输入:\n");
			scanf("%d",&x);	
		}
	}while(1);
	if(x==1)
	{
		system("cls");
		printf("\n\n\n\n\n");
		printf("\t\t\t\t****1.全部范围****\n");
		printf("\t\t\t\t****2.国家****\n");
		printf("\t\t\t\t****3.省份****\n");
		printf("\t\t\t\t****4.城市****\n");
		printf("\t\t\t\t****5.ISP****\n\n\n");
	}//自定义查询页面 
	switch(x)
	{
		case 1:
			findip1();
			system("pause");
			system("cls");
			break;
		case 2:
			findip2();
			system("pause");
			system("cls");
			break;
		case 3:
			findip3();
			system("pause");
			system("cls");
			break;
		case 4:
			collect();
			system("pause");
			system("cls");
			break;
		case 5:
			exit(0);
	}//主界面5种操作的执行	
}// 整个程序的驱动 
int main()
{
	function();//调用整个程序驱动函数 
	return 0;
}
