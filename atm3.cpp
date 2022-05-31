#include"stdio.h"
#include"stdlib.h"
#include"string.h"


void InitialPassword();//��ʼ�����뺯��
void homePage();//���Ĳ˵�ҳ
void loadData();//��ʼ��
void saveData();

void WithdrawMoney();//ȡ��ҵ��
void TransferMoney();//ת��ҵ��
void Enquiry();//��ѯҵ��
void EnquiryBalance();//��ѯ���
void EnquiryInformation();//��ѯ������Ϣ


void ChangeInformation();//�޸���Ϣѡ��ҳ
void ChangeUser();//�޸��û�����
void ChangeAccountNum();//�޸��˻�
void Changephone();//�޸���ϵ�绰
void ChangePassword();//�޸�����




int n;




//�û���Ϣ
struct Account
{
	char name[100];
	char username[21];
	char phonenum[12];
	char password[7];
	float balance=10000.00;

	struct Account* next;
};

typedef struct Account Account;

Account* head = NULL;
Account* tail = NULL;
Account* curAccount;



int findAccount2(Account A)
{
	Account* curP = head;
	while (curP != NULL)
	{
		if (strcmp(curP->username, A.username) == 0)
		{
			curAccount = curP;
			return 1;
		}
		curP = curP->next;
	}
	return 0;
}



//���ҵ�ǰ�˻�
int findAccount1(Account a)
{
	Account* curP = head;
	while (curP != NULL)
	{
		if (strcmp(curP->username, a.username) == 0)
		{
			curAccount = curP;
			return 1;
		}
		curP = curP->next;
	}
	return 0;
}

//��ʼ������
void InitialPassword()
{
	strcpy(curAccount->password, "000000");
}

//��֤��ǰ�˻�����
int findAccount(Account a)
{
	Account* curP = head;
	while (curP != NULL)
	{
		if (strcmp(curP->password, a.password) == 0)
		{
			curAccount = curP;
			return 1;
		}
		curP = curP->next;
	}
	return 0;
}


//ȡ��ҵ��
void WithdrawMoney()
{
	int a;
	printf("��������Ҫȡ���Ľ��\t");
	printf("���Ϊ100������\n");
	scanf("%d", &a);
	if (a % 100)
	{
		printf("���Ϊ100������!����������\n");
	}
	else
	{
		printf("ȡ��ɹ�\n");
	}
}

//ת��ҵ��
void TransferMoney()
{
	int a;
	printf("��������Ҫת�˵��˻�\t");
	printf("���Ϊ100������\n");
	scanf("%d", &a);
	if (a%100)
	{
		printf("���Ϊ100������!����������\n");
	}
	else
	{
		printf("ת�˳ɹ�\n");
	}
}

//��ѯҵ��ҳ
void Enquiry()
{

	int a, k = 0;
	while (k < 3)
	{
		printf("\n\t1����ѯ��û��������ϣ�\n");
		printf("\n\t2����ѯ������Ϣ\n");
		printf("\n\t3��������ҳ\n");
		printf("\n\t0���˳�ϵͳ\n");
		scanf("%d", &a);
		switch (a)
		{
		case 1:
			EnquiryBalance();
			k == 3;
			break;
		case 2:
			EnquiryInformation();
			k == 3;
			break;
		case 3:
			homePage();
			k == 3;
			break;
		case 0:
			k == 3;
			saveData();
			exit(0);
		default:
			k++;
			break;
		}
	}
}

//��ѯ���
void EnquiryBalance()
{
	printf("\t�������Ϊ��\n\t\t%lf\n",&curAccount->balance);
	printf("\n");
	int a,k = 0;
	while (k < 3)
	{
		printf("\n\t1��������һҳ\n");
		printf("\n\t2��������ҳ\n");
		printf("\n\t0���˳�ϵͳ\n");
		scanf("%d", &a);
		switch (a)
		{
		case 1:
			Enquiry();
			k == 3;
			break;
		case 2:
			homePage();
			k == 3;
			break;
		case 0:
			k == 3;
			saveData();
			exit(0);
		default:
			k++;
			break;
		}
	}
}

//��ѯ������Ϣ
void EnquiryInformation()
{
	printf("\t������\n\t\t%s\n", curAccount->name);
	printf("\t�˺ţ�\n\t\t%s\n", curAccount->username);
	printf("\t��ϵ�绰��\n\t\t%s\n", curAccount->phonenum);
	printf("\n");
	int a, k = 0;
	while (k < 3)
	{
		printf("\n\t1��������һҳ\n");
		printf("\n\t2��������ҳ\n");
		printf("\n\t0���˳�ϵͳ\n");
		scanf("%d", &a);
		switch (a)
		{
		case 1:
			Enquiry();
			k == 3;
			break;
		case 2:
			homePage();
			k == 3;
			break;
		case 0:
			k == 3;
			saveData();
			exit(0);
		default:
			k++;
			break;
		}
	}
}

//�޸��û�
void ChangeUser()
{
	int a,k = 0;
	char Password[100];
	while (k<3)
	{
		printf("���������룺\n");
		scanf("%s", Password);
		if (strcmp(Password, curAccount->password) == 0)
		{
			printf("���������û�����:\n");
			scanf("%s", curAccount->name);
			printf("\n");
			printf("�û������޸ĳɹ���\n");
			saveData();
			k = 3;

			int k2 = 0;
			while (k2 < 3)
			{
				printf("\n\t1��������һҳ\n");
				printf("\n\t2��������ҳ\n");
				printf("\n\t0���˳�ϵͳ\n");
				scanf("%d", &a);
				switch (a)
				{
				case 1:
					ChangeInformation();
					k == 3;
					break;
				case 2:
					homePage();
					k == 3;
					break;
				case 0:
					k == 3;
					saveData();
					exit(0);
				default:
					k++;
					break;
				}
			}
		}
		else
		{
			k++;
			printf("�����������! \t%d\t�밴����ʾ�������룺\n",3-k);
		}
	}
}

//�޸��˻�
void ChangeAccountNum()
{
	system("cls");
	int a, k = 0;
	char Password[100];
	while (k < 3)
	{
		printf("���������룺\n");
		scanf("%s", Password);
		system("cls");
		if (strcmp(Password, curAccount->password) == 0)
		{
			printf("���������˻�����:\n");
			scanf("%s", curAccount->username);
			system("cls");
			printf("\n");
			printf("�˻������޸ĳɹ���\n");
			saveData();
			k = 3;

			int k2 = 0;
			while (k2 < 3)
			{
				printf("\n\t1��������һҳ\n");
				printf("\n\t2��������ҳ\n");
				printf("\n\t0���˳�ϵͳ\n");
				scanf("%d", &a);
				switch (a)
				{
				case 1:
					ChangeInformation();
					k2 == 3;
					break;
				case 2:
					homePage();
					k2 == 3;
					break;
				case 0:
					k2 == 3;
					saveData();
					exit(0);
				default:
					k2++;
					break;
				}
			}
		}
		else
		{
			k++;
			system("cls");
			printf("�����������! \t%d\t�밴����ʾ�������룺\n", 3 - k);
		}
	}
}


//�޸���ϵ�绰
void Changephone()
{
	system("cls");
	int a, k = 0;
	char Password[100];
	while (k < 3)
	{
		printf("���������룺\n");
		scanf("%s", Password);
		system("cls");
		if (strcmp(Password, curAccount->password) == 0)
		{
			printf("����������ϵ�绰����:\n");
			scanf("%s", curAccount->phonenum);
			system("cls");
			printf("\n");
			printf("��ϵ�绰�޸ĳɹ���\n");
			saveData();
			k = 3;

			int k2 = 0;
			while (k2 < 3)
			{
				printf("\n\t1��������һҳ\n");
				printf("\n\t2��������ҳ\n");
				printf("\n\t0���˳�ϵͳ\n");
				scanf("%d", &a);
				switch (a)
				{
				case 1:
					ChangeInformation();
					k2 == 3;
					break;
				case 2:
					homePage();
					k2 == 3;
					break;
				case 0:
					k2 == 3;
					saveData();
					exit(0);
				default:
					k2++;
					break;
				}
			}
		}
		else
		{
			k++;
			system("cls");
			printf("�����������! \t%d\t�밴����ʾ�������룺\n", 3 - k);
		}
	}
}


//�޸�����
void ChangePassword()
{
	system("cls");
	int a, k = 0;
	char Password[100];
	while (k < 3)
	{
		printf("���������룺\n");
		scanf("%s", Password);
		system("cls");
		if (strcmp(Password, curAccount->password) == 0)
		{
			printf("������������:\n");
			scanf("%s", curAccount->password);
			system("cls");
			printf("\n");
			printf("�����޸ĳɹ���\n");
			saveData();
			k = 3;

			int k2 = 0;
			while (k2 < 3)
			{
				printf("\n\t1��������һҳ\n");
				printf("\n\t2��������ҳ\n");
				printf("\n\t0���˳�ϵͳ\n");
				scanf("%d", &a);
				switch (a)
				{
				case 1:
					ChangeInformation();
					k2 == 3;
					break;
				case 2:
					homePage();
					k2 == 3;
					break;
				case 0:
					k2 == 3;
					saveData();
					exit(0);
				default:
					k2++;
					break;
				}
			}
		}
		else
		{
			k++;
			system("cls");
			printf("�����������! \t%d\t�밴����ʾ�������룺\n", 3 - k);
		}
	}
}


//�޸���Ϣѡ��ҳ
void ChangeInformation()
{
	system("cls");
	int a, k2 =1;
	while (k2)
	{
		printf("\n\t1.�޸��û�\n");
		printf("\n\t2.�޸��˺�\n");
		printf("\n\t3.�޸���ϵ�绰\n");
		printf("\n\t4.�޸�����\n");
		printf("\n\t9.������һҳ\n");
		printf("\n\t0.�˳�ϵͳ\n");
		scanf("%d", &a);

		switch (a)
		{
		case 1:
			ChangeUser();
			k2 = 0;
			break;
		case 2:
			ChangeAccountNum();
			k2 = 0;
			break;
		case 3:
			Changephone();
			k2 = 0;
			break;
		case 4:
			ChangePassword();
			k2 = 0;
			break;
		case 9:
			homePage();
			k2 = 0;
			break;
		case 0:
			saveData();
			exit(0);
		default:
			system("cls");
			printf("�������\t�밴����ʾ�������룺\n");
			break;
		}
	}
}

//���Ĳ˵�ҳ
void homePage()
{
	int a, k1 = 1;
	while (k1)
	{
		k1 = 0;
		printf("\n\t1.ȡ�û��������ϣ�\n");
		printf("\n\t2.ת�ʣ�û��������ϣ�\n");
		printf("\n\t3.��ѯ\n");
		printf("\n\t4.�޸ĸ�������\n");
		printf("\n\t0.�˳�ϵͳ\n");
		scanf("%d", &a);
		switch (a)
		{
		case 1:
			WithdrawMoney();
			break;
		case 2:
			TransferMoney();
			break;
		case 3:
			Enquiry();
			break;
		case 4:
			ChangeInformation();
			break;
		case 0:
			saveData();
			exit(0);
			break;
		default:
			printf("�������\n");
			k1 = 1;
			break;
		}
	}
}

//Ӣ��˵�
void EnglishhomePage()
{
	int a, k = 1;
	while (k)
	{
		k = 0;
		printf("====================��û��������ϣ�\n");
		printf("1.Withdraw money.\t");
		printf("2.Transfer money.\n");
		printf("3.Change password.\n");
		printf("==========\n");
		printf("0.Exit program.\n");
		scanf("%d", &a);
		switch (a)
		{
		case 1:
			WithdrawMoney();
			break;
		case 2:
			TransferMoney();
			break;
		case 3:
			ChangePassword();
			break;
		case 0:
			saveData();
			exit(0);
			break;
		default:
			printf("Error��\n");
			k = 1;
			break;
		}
	}
}

//���ĵ�¼
void ChineseSignIn()
{
	system("cls");
	int m=0,n=0;
	while (m < 3)//3��������˺Ž��˳�ϵͳ
	{
		Account a;
		printf("\n\t�������˺ţ�\n");
		scanf("%s", a.username);
		system("cls");
		if (findAccount1(a))
		{
			while (n<3)//3����������뽫�˳�ϵͳ
			{
				printf("\n\t���������룺\n");
				scanf("%s", a.password);
				system("cls");

				if (findAccount(a))
				{
					m = 3;
					n = 3;
					printf("\n==========��¼�ɹ�==========\n");
					homePage();
					break;
				}
				else
				{
					m++;
					n++;
					if (n==3)
					{
						printf("\n\t���˺��Ѿ������ᣬ����ϵ��̨�һء�\n");
						InitialPassword();
						break;
					}
					else
					{
						printf("\n\t�������  %d�λ�����˺Ž��ᱻ����\n", 3 - n);
					}
				}
			}
		}
		else
		{
			m++;
			printf("\n\tû�в��ҵ����û�!  %d  ���������룺\n",3-m);
			if (m==3)
			{
				printf("\n\t�������˳�ϵͳ\n");
				saveData();
				exit(0);
			}
		}
	}
}

//��ӡ��ǰ����
void printAccount(Account* curP)
{
	printf("%s\t%s\n", curP->username, curP->password);
}

/*void printLinkedList()
{
	Account* curP = head;
	while (curP != NULL)
	{
		printf("%s\t%s\t%s\t%s\n", curP->name, curP->username, curP->iphonenum, curP->password);
		curP = curP->next;
	}
}*/

//��ӡ����
void printLinkedList()
{
	Account* curP = head;
	while (curP != NULL)
	{
		printAccount(curP);
		curP = curP->next;
	}
}

//����ע��
void ChineseSignUp()//����ע�ắ��
{
	int a,k = 0;
	printf("\n\t��ӭע��\n\n");

	Account* P = (Account*)malloc(sizeof(Account));
	P->next = NULL;
	if (head == NULL)
	{
		head = P;
		tail = P;//������ǵ�һ�������Ľ�㣬��ͷ βָ��ָ��������
	}
	else
	{
		tail->next = P; //������ǵ�һ�������Ľ�㣬����һ�����ĺ��ָ��ָ��ǰ���
		printf("�������������\n");
		scanf("%s", P->name);
		Account A;
		printf("�������㼴��ע����˻����롾10λ��\n");
		scanf("%s", A.username);

		
		if (findAccount2(A))
		{
			printf("���˺��Ѿ���ע�᲻����\n");
			exit(0);
		}
		else
		{
			strcpy(P->username,A.username);
		}
		printf("��������ĵ绰���롾11λ��\n");
		scanf("%s", P->phonenum);
		printf("����������˻����롾6λ��\n");
		scanf("%s", P->password);
		saveData();
		while (k<3)
		{
			system("cls");
			printf("\n\t1�����ص�¼\n");
			printf("\n\t0���˳�ϵͳ\n");
			scanf("%d", &a);
			if (a == 1)
			{
				ChineseSignIn();
				break;
			}
			else if (a == 0)
			{
				exit(0);
			}
			else
			{
				k++;
				printf("�����������! \t%d\t�밴����ʾ�������룺\n", 3 - k);
			}
		}
	}
}

//Ӣ��ע��
void EnglishSignUp()//Ӣ��ע�ắ��
{
	printf("Welcome.\n");
	printf("\n");

	Account* P = (Account*)malloc(sizeof(Account));
	P->next = NULL;
	if (head == NULL)
	{
		head = P;
		tail = P;
	}
	else
	{
		tail->next = P;
		printf("please enter your name.\n");
		scanf("%s", P->name);
		printf("please enter your account number.[20 figures]\n");
		scanf("%s", P->username);
		printf("please enter your cell phone number.[11 figures]\n");
		scanf("%s", P->phonenum);
		printf("please setting your account password.[6 figures]\n");
		scanf("%s", P->password);
	}
}

//Ӣ���¼
void EnglishSignIn()
{
	int k = 0;
	while (k < 3)
	{
		Account a;
		printf("please enter your account number.[20 figures]��\n");
		scanf("%s", a.username);

		printf("please enter your account password.[6 figures]��\n");
		scanf("%s", a.password);

		if (findAccount(a))
		{
			k = 3;
			printf("Login successful!\n");
			EnglishhomePage();
		}
		else
		{
			k++;
			if (k!=3)
			{
				printf("Login failed. Please try again.\n");
			}
			else
			{
				printf("Login failed.\n");
				printf("\n");
				printf("EXIT PROGRAM...\n");
			}
		}
	}
}

//��ʼ��
void loadData()//��ʼ������
{
	FILE* fp = fopen("D:/atm.txt", "r");
	if (fp != NULL)
	{
		while (!feof(fp))
		{
			Account* newNodeP = (Account*)malloc(sizeof(Account));
			fscanf(fp, "%s\t%s\t%s\t%s\n", newNodeP->name, newNodeP->username, newNodeP->phonenum, newNodeP->password);
			newNodeP->next = NULL;

			if (head == NULL)
			{
				head = newNodeP;
				tail = newNodeP;
			}
			else
			{
				tail->next = newNodeP;
				tail = newNodeP;
			}
		}
		fclose(fp);
	}
}

//��ʼ����
void start()
{
	int n1,k=1;
	while (k)
	{
		printf("\n��ѡ�����ԣ�\t");
		printf("Please choose language��\n");
		printf("\n\t1������\n");
		printf("\n\t2��English\n");
		printf("\n\t0���˳� Exit\n");
		scanf("%d", &n);

		switch (n)
		{
		case 1:
			system("cls");
			printf("\n\t1���û�ע��\n");
			printf("\n\t2���û���¼\n");
			printf("\n\t������������һҳ\n");
			scanf("%d", &n1);
			k = 0;
			if (n1 == 1)
			{
				ChineseSignUp();//����ע�ắ��
			}
			else if (n1 == 2)
			{
				ChineseSignIn();
			}
			else
				k = 1;
			break;
		case 2:
			system("cls");
			printf("\n\t1��Sign up��û��������ϣ�\n");
			printf("\n\t2��Sign in��û��������ϣ�\n");
			printf("\n\tOthers��Back to previous page��û��������ϣ�\n");
			scanf("%d", &n1);
			k = 0;
			break;
			if (n1 == 1)
			{
				EnglishSignUp();//Ӣ��ע�ắ��
			}
			else if (n1 == 2)
			{
				EnglishSignIn();
			}
			else
				k = 1;
		case 0:
			saveData();
			exit(0);
		default:
			k = 1;
			printf("\n\t���������밴����ʾ�ٴ�����!\t");
			printf("\t");
			printf("Error,please follow the prompts to enter again!\n");
			break;
		}
	}
}


//��������
void saveData()
{
	FILE* fp = fopen("D:/atm.txt", "w");
	if (fp != NULL)
	{
		Account* curP = head;
		while (curP != NULL)
		{
			fprintf(fp, "%s\t%s\t%s\t%s\n", curP->name, curP->username, curP->phonenum, curP->password);
			curP = curP->next;
		}
		fclose(fp);
	}
}

int main()
{
	loadData();
	start();

	printLinkedList();
	saveData();
	return 0;
}
