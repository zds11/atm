#include<stdio.h>
#include<stdlib.h> 

struct Account
{
	char name[100];//���� 
	char tel[12];//�绰 
	char idCard[19];//���֤	
	char username[20];//�����˺ſ���
	char password[7];//���� 
	float money;//���
	
	struct Account * next; //��һ���˻����ĵ�ַ 
};
typedef struct Account Account; 

Account * head;//ָ��ͷ����ͷָ��
Account * tail;//ָ��β����βָ�� 

void showMenuEnglish()
{
	
}

void signUpChinese()
{
	//����һ����ڴ�ռ䣬�����ַ��ֵ��ָ��newNodeP�������ֲ�������ȫ�ֱ�����ͬѧ�ǹۿ�Ⱥ�����ƵC�����ڴ���䣩 
	Account * newNodeP=(Account *)malloc(sizeof(Account));
	printf("������������\n"); 
	scanf("%s",newNodeP->name);
	
	printf("������绰��\n");
	scanf("%s",newNodeP->tel); 
	
	printf("���������֤��\n");
	scanf("%s",newNodeP->idCard); 
	
	printf("�������˺ţ�\n");
	scanf("%s",newNodeP->username); //�˺�Ӧ���������и��ģ�Ӧ����ϵͳ���ɵģ�˼����ô����
	
	printf("���������룺\n");
	scanf("%s",newNodeP->password); 
	
	newNodeP->money=0.0f;
	newNodeP->next=NULL;
	
	//��ӽ�㵽������
	if(head==NULL)
	{
		head=newNodeP;
		tail=newNodeP;
	} 
	else
	{
		tail->next=newNodeP;
		tail=newNodeP;
	}
	
	printf("��ӳɹ�\n");
	system("pause");
}

void signInChinese()
{
	
}

void signOut()
{
	exit(0);
}

void showMenuChinese()
{
	while(1)
	{
		system("cls");
		printf("��1������\n");
		printf("��2����¼\n");
		printf("��3���˳�\n");
		int n;
		scanf("%d",&n);
		if(n==1)
		{
			signUpChinese();
		}
		else if(n==2)
		{
			signInChinese();
		}
		else if(n==3)
		{
			signOut();
		}
	}
}

int main()
{
	printf("Press 1, English Service\n");
	printf("��2�����ķ���\n");
	int language;
	scanf("%d",&language);
	if(language==1)
	{
		showMenuEnglish(); //��ʾ���в˵� 
	}
	else if(language==2)
	{
		showMenuChinese(); //��ʾӢ�Ĳ˵� 
	}
	return 0;
}
