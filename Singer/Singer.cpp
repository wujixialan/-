#include"Singer.h"



void Get_information(Student *student)
{
	int j;
	printf("\t请输入选手编号: ");
	scanf("%s",student->number);
	getchar();
	printf("\n\t请输入选手名称: ");
	scanf("%s",student->name);
	getchar();
	printf("\n\t请输入选手性别(Man or  Woman): ");
	scanf("%s",student->sex);
	if(!(strcmp("Man",student->sex)==0 || strcmp("Woman",student->sex)==0))
	{
		printf("\n\t您的输入不符合规范请检查\n");
		for(j=0;j<MAXSIZE;j++)	
		{
			student->number[j]='0';
		}
		return;
	}
	getchar();
}

void Get_score(Student *student)
{
	int i,j,m1,m2,k;
	char number[MAXSIZE];
	float temp[10],sum=0,max,min;
	printf("\t请输入您要打分学生的编号: ");
	scanf("%s",number);
	getchar();
	for(i=0;i<Get_peoplecount(student);i++)
	{
		if(strcmp(number,student[i].number) == 0)
		{
			printf("\n\t请打分: ");
			for(j=0;j<10;j++)
			{
				scanf("%f",&temp[j]);
				getchar();
				if(j==0)
				{
					max=temp[j],min=temp[j],m1=0,m2=0;
				}
				
				else if(temp[j] > max)
				{
					max=temp[j];
					m1=j;
				}
				else if(temp[j] < min)
				{
					min=temp[j];
					m2=j;
				}
			}
			for(k=0;k<10;k++)
			{
				if(k==m1 || k==m2)
				{
					continue;
				}
				else
				{
					sum += temp[k];
				}
			}
			student[i].score=sum/10;
		}
	}
}

void Change(Student *student)
{
	char number[MAXSIZE];
	int i;
	printf("\t请输入您要修改的编号: ");
	scanf("%s",number);
	getchar();
	printf("\n");
	for(i=0;i<Get_peoplecount(student);i++)
	{
		if(strcmp(number,student[i].number) == 0)
		{
			Get_information(&student[i]);
			break;
		}
	}
}

void Delete(Student *student)
{
	char number[MAXSIZE];
	int i,j;
	printf("\t请输入您要删除的编号: ");
	scanf("%s",number);
	getchar();
	for(i=0;i<PEOPLE;i++)
	{
		if(strcmp(number,student[i].number) == 0)
		{
			for(j=0;j<MAXSIZE;j++)
			{
				student[i].number[j]='0';
			}
			for(j=i;j<Get_peoplecount(student);j++)
			{
				student[i]=student[i+1];
			}
			printf("\n\t该选手已经成功删除\n");
			break;
		}
	}
}

void Select(Student *student)
{
	char number[MAXSIZE];
	int i;
	printf("\t请输入您要查询的编号: ");
	scanf("%s",number);
	getchar();
	for(i=0;i<Get_peoplecount(student);i++)
	{
		if(strcmp(number,student[i].number) == 0)
		{
			printf("\n\t编号: %s",student[i].number);
			printf("\t姓名: %s",student[i].name);
			printf("\t性别: %s\n",student[i].sex);
			//printf("分数: %f",student[i].score);
			break;
		}
	}
}

void Order(Student *student) //排序输出
{
	int i,j,k;
	Student temp;
	int n=Get_peoplecount(student);
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(student[i].score > student[j].score)
			{
				temp=student[i];
				student[i]=student[j];
				student[j]=temp;
			}
		}
	}
	for(k=0;k<Get_peoplecount(student);k++)
	{
		printf("\t编号: %s",student[k].number);
		printf("\t姓名: %s",student[k].name);
		printf("\t性别: %s",student[k].sex);
		printf("\t分数: %.2f\n",student[k].score);
	}
}

void Print_all(Student *student)
{
	int i;
	for(i=0;i<Get_peoplecount(student);i++)
	{
		printf("\t编号: %s",student[i].number);
		printf("\t姓名: %s",student[i].name);
		printf("\t性别: %s",student[i].sex);
		printf("\t分数: %.2f\n",student[i].score);
	}
}

int Get_peoplecount(Student *student)
{
	int temp=0,i;
	for(i=0;i<PEOPLE;i++)
	{
		if(student[i].number[0]!='0' && student[i].number[1]!='0' )
		{
			temp++;
		}
	}
	return temp;
}

void Save(Student *student)
{
	FILE *fp;
	int i;
	fp=fopen("Singer.txt","w");
	if(fp == NULL)
	{
		printf("\t该文件无法打开\n\n");
		return ;
	}
	for(i=0;i<Get_peoplecount(student);i++)
	{
		fputs(student[i].number,fp);
		fputs("\t",fp);
		fputs(student[i].name,fp);
		fputs("\t",fp);
		fputs(student[i].sex,fp);
		fputs("\t",fp);
		fprintf(fp,"%.2f",student[i].score);
		fputs("\n",fp);	
	};
	fclose(fp);
	printf("\t该数据已经成功保存，欢迎您的使用\n\n");
}

int Read_data(Student *student)
{
	FILE *fp;
	int i=0,count=0,flag;
	char temp;
	fp=fopen("Singer.txt","r");
	if(fp == NULL)
	{
		printf("\t该文件无法打开\n\n");
		return -1;
	}
	
	while(fscanf(fp,"%s%s%s%f%c",student[i].number,student[i].name,student[i].sex,&student[i].score,&temp) != EOF)
	{
		i++;
		count++;
	};
	fclose(fp);
	return 1;
}