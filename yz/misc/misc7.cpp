//#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<stack>
#include<math.h>
#include<string.h>
#define max 100
using namespace std;
char ex[max];/*�洢��׺����ʽ*/

void trans()
{/*����������ʽת��Ϊ��׺����ʽ*/
	char str[max];/*�洢ԭ��������ʽ*/
	char stack[max];/*��Ϊջʹ��*/
	char ch;
	int sum,i,j,t,top=0;
	printf("*****************************************\n");
	printf("*����һ����ֵ�ı���ʽ����#������*\n");
	printf("******************************************\n");
	printf("��������ʽ��");
	i=0;/*��ȡ�û�����ı���ʽ*/
	do{
		i++;
		//cin>>str[i];/*�˲����õ���C++C���ԵĻ��ں���֮�����������һ������*/
		scanf("%c",&str[i]);
	}while(str[i]!='#'&&i!=max);
	sum=i;
	t=1;i=1;
	ch=str[i];i++;
	//
	while(ch!='#')
	{
		switch(ch)
		{
		case'(':/*�ж�Ϊ������*/
			top++;stack[top]=ch;
			break;
		case')':/*�ж�Ϊ������*/
			while(stack[top]!='(')
			{
				ex[t]=stack[top];top--;t++;
			}
			top--;
			break;
		case'+':/*�ж�Ϊ�Ӽ���*/
		case'-':
			while(top!=0&&stack[top]!='(')
			{
				ex[t]=stack[top];
				top--;
				t++;
			}
			top++;
			stack[top]=ch;
			break;
		case'*':/*�ж�Ϊ�˳���*/
		case'/':
			while(stack[top]=='*'||stack[top]=='/')
			{
				ex[t]=stack[top];
				top--;
				t++;
			}
			top++;
			stack[top]=ch;
			break;
		case' ':break;
		default:
			while(ch>='0'&&ch<='9')
			{/*�ж�Ϊ����*/
				ex[t]=ch;t++;
				ch=str[i];i++;
			}
			i--;
			ex[t]=' ';t++;
		}
		ch=str[i];i++;
	}
	while(top!=0)
	{
		ex[t]=stack[top];
		t++;top--;
	}
	ex[t]=' ';
	printf("\n\tԭ������ʽ��");
	for(j=1;j<sum;j++)
		printf("%c",str[j]);
	printf("\n\t�沨��ʽ��",ex);
	for(j=1;j<t;j++)
		printf("%c",ex[j]);
}

void compvalue()
{/*�����׺����ʽ��ֵ*/
	float stack[max],d;/*��Ϊջʹ��*/
	char ch;
	int t=1,top=0;/*tΪex�±꣬topΪstack�±�*/
	ch=ex[t];t++;
	while(ch!=' ')
	{
		switch(ch)
		{
		case'+':
			stack[top-1]=stack[top-1]+stack[top];
			top--;
			break;
		case'-':
			stack[top-1]=stack[top-1]-stack[top];
			top--;
			break;
		case'*':
			stack[top-1]=stack[top-1]*stack[top];
			top--;
			break;
		case'/':
			if(stack[top]!=0)stack[top-1]=stack[top-1]/stack[top];
			else
			{
				printf("\n\t�������!\n");
				exit(0);/*�쳣�˳�*/
			}
			top--;
			break;
		default:
			d=0;
			while(ch>='0'&&ch<='9')
			{
				d=10*d+ch-'0';/*�������ַ�ת��Ϊ��Ӧ����ֵ*/
				ch=ex[t];t++;
			}
			top++;
			stack[top]=d;
		}
		ch=ex[t];
		t++;
	}
	printf("\n\t������:%g\n",stack[top]);
}

int main()
{
	trans();
	compvalue();
	system("pause");
	return 0;
}