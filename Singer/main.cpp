#include"Singer.h"

void main()
{
	int i,s,j,count=0,r=0;
	char flag='1';
	Student *student=(Student*)malloc(sizeof(Student) * PEOPLE);
	system("color A"); //�޸�������ɫ
	for(i=0;i<PEOPLE;i++) //��ʼ��
	{
		for(j=0;j<MAXSIZE;j++)		{
			student[i].number[j]='0';
		}
		student[i].score=0;
	}

	r=Read_data(student); //���ļ����������

	printf("\t\t   ---------------------------------------\n");
	printf("\t------------------------��������ϵͳ��ӭ��------------------------\n");
	printf("\t\t   ---------------------------------------\n\n");
	while(flag != '0')
	{
		if(count==0)
		{
			printf("\t1 ѡ����Ϣ¼��\t2 ѡ����Ϣ��ѯ\t 3ѡ����Ϣ�޸�\n\n ");
			printf("\t4 ѡ����Ϣɾ��\t5 ѡ����Ϣ����\t 6���ȫ��\n\n ");
			printf("\t7 ��ʼ���\t8 ����\n\n ");
			count++;
		}

		printf("\t��ѡ��");
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
			default: {printf("\n\t����������������\n\n"); break;}
		}
		printf("\n\t**************************************************\n");
		printf("\t�˳��밴0��");
		scanf("%c",&flag);
		getchar();
		printf("\t**************************************************\n\n");
	}

}