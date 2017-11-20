#include"Singer.h"

void main()
{
	int i,s,j,count=0,r=0;
	char flag='1';
	Student *student=(Student*)malloc(sizeof(Student) * PEOPLE);
	system("color A"); //修改文字颜色
	for(i=0;i<PEOPLE;i++) //初始化
	{
		for(j=0;j<MAXSIZE;j++)		{
			student[i].number[j]='0';
		}
		student[i].score=0;
	}

	r=Read_data(student); //从文件里面读数据

	printf("\t\t   ---------------------------------------\n");
	printf("\t------------------------歌手评分系统欢迎您------------------------\n");
	printf("\t\t   ---------------------------------------\n\n");
	while(flag != '0')
	{
		if(count==0)
		{
			printf("\t1 选手信息录入\t2 选手信息查询\t 3选手信息修改\n\n ");
			printf("\t4 选手信息删除\t5 选手信息排序\t 6输出全部\n\n ");
			printf("\t7 开始打分\t8 保存\n\n ");
			count++;
		}

		printf("\t请选择：");
		scanf("%d",&s);
		getchar();
		printf("\n");
		switch(s)
		{
			case 1 : 
				{
					Get_information(&student[Get_peoplecount(student)]);
					break;
				}
			case 2 :
				{
					Select(student);
					break;
				}
			case 3:
				{
					Change(student);
					break;
				}
			case 4:
				{
					Delete(student);
					break;
				}
			case 5:
				{
					Order(student);
					break;
				}
			case 6:
				{
					Print_all(student);
					break;
				}
			case 7:
				{
					Get_score(student);
					break;
				}
			case 8:
				{
					Save(student);
					break;
				}
			default: {printf("\n\t您的输入有误请检查\n\n"); break;}
		}
		printf("\n\t**************************************************\n");
		printf("\t退出请按0：");
		scanf("%c",&flag);
		getchar();
		printf("\t**************************************************\n\n");
	}

}