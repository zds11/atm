#include"stdio.h"
#include"stdlib.h"
#include"string.h"
#include"time.h"
#include"cstdio"
#include"windows.h"
#include"conio.h"
#include"iostream"
#include"cstdlib"
#include"ctime"
#include"cmath"



//��궨λ
HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
COORD coord;

void start();

//����
void C_Sign_Up();                      //����ע��
void C_Sign_In();                      //���ĵ�¼ 
void C_Main_Menu();                    //�������˵�ҳ
void C_DepositMoney();                 //���Ĵ��ҵ��
void C_DepositMoney1();                //���Ĵ��ʧ��ѡ��
void C_DepositMoney2();                //���Ĵ��ɹ�ѡ��
void C_Withdraw_Money();               //����ȡ��ҵ��
void C_Withdraw_Money1();              //����ȡ��ʧ��ѡ��
void C_Withdraw_Money2();              //����ȡ��ɹ�ѡ��
void C_Transfer_Money();               //����ת��ҵ��
void C_Transfer_Money1();              //����ת��ʧ��ѡ��
void C_Transfer_Money2();              //����ת��ʧ��ѡ��
void C_Enquiry();                      //���Ĳ�ѯҵ��
void C_Enquiry_balance();              //���Ĳ�ѯ�ඹ
void C_Enquiry_Information();          //���Ĳ�ѯ������Ϣ
void C_Enquiry_Record();               //���Ĳ�ѯ��ˮ��¼
void C_Change_Information();           //�����޸���Ϣѡ��ҳ
void C_Change_User();                  //�����޸��û�����
void C_Change_AccountNum();            //�����޸��˻�
void C_Change_phone();                 //�����޸���ϵ�绰
void C_Change_Password();              //�����޸�����

//English
void E_Sign_Up();                      //Ӣ��ע��
void E_Sign_In();                      //Ӣ�ĵ�¼ 
void E_Main_Menu();                    //Ӣ�Ĳ˵�ҳ
void E_DepositMoney();                 //Ӣ�Ĵ��ҵ��
void E_Withdraw_Money();               //Ӣ��ȡ��ҵ��
void E_Transfer_Money();               //Ӣ��ת��ҵ��
void E_Enquiry();                      //Ӣ�Ĳ�ѯҵ��
void E_Enquiry_balance();              //Ӣ�Ĳ�ѯ��� 
void E_Enquiry_Information();          //Ӣ�Ĳ�ѯ������Ϣ
void E_Enquiry_Record();               //Ӣ�Ĳ�ѯ��ˮ��¼
void E_Change_Information();           //Ӣ���޸���Ϣѡ��ҳ
void E_Change_User();                  //Ӣ���޸��û�����
void E_Change_AccountNum();            //Ӣ���޸��˻�
void E_Change_phone();                 //Ӣ���޸���ϵ�绰
void E_Change_Password();              //Ӣ���޸�����

//CE
void gotoxy();
void getPassword();
void CE_Time();                       //ϵͳʱ��
void CE_Close_Account();              //ע���˻�ѡ��ҳ
void CE_Close_Account1();             //ע���˻�
void CE_Save_User_Data();             //�����û�����
void CE_Save_Transaction_Data();      //���潻������
void CE_Initial_Password();           //��ʼ�����뺯��
void CE_Initialize_User_Data();       //��ʼ���û�����
void CE_Initialize_Transaction_Data();//��ʼ����������
void CE_Set_Name();                   //��Ӣ����������
void CE_Set_Password();               //��Ӣ����������
void CE_Set_PhoneNumber();            //��Ӣ�����õ绰����
void CE_Add_Account_Number();         //��Ӣ�������˻����뺯��
void CE_Deposit_Transaction();        //����
void CE_Withdraw_Transaction();       //ȡ���
void CE_Transfer_Transaction();       //ת�˽���        
void hide();
void print_wall();
void print_snake();
bool is_correct();
bool print_food();
bool go_ahead();
void locate();
 

int Language, Sin, Bank;
int Random_Number;           //�����
int ACCOUNT;                 //��ǰ�˺���ֵ
int TACCOUNT;                //��ǰ�Է��˺���ֵ
int SXF;                     //������
float SXFmoey;               //�����ѽ��
int AccountNum1 = 1231231000;//ע������ 
int TCSm, TCSn;
char str[50];
//�û���Ϣ����
struct Account
{
	//char bank[100];//����
	char name[100];//�û�����
	char account_number[50];//�˻��˺�
	char phone_number[12];//�绰����
	char password[10];//����
	float balance;//��� 

	struct Account* next;
};

//������Ϣ����
struct Trade
{
	char Taccount_number[50];//�˻��˺�
	char Time[100];//ʱ��
	char Operation[100];//��������
	char TarUse[50];//Ŀ���˻��˺�
	float Money;//��������

	struct Trade* Tnext;
};

typedef struct Account Account;
typedef struct Trade Trade;

//�û���Ϣ
Account* Pset = (Account*)malloc(sizeof(Account));
Account* head = NULL;
Account* tail = NULL;
Account* curAccount;
Account* curAccountO;
Account IV;

//������Ϣ
Trade* Thead = NULL;
Trade* Ttail = NULL;
Trade* TcurAccount;
Trade TA;
char tmp1[100];

//ѡ����
void gotoxy(int xpos, int ypos)
{
	COORD scrn;
	HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);
	scrn.X = xpos; scrn.Y = ypos;
	SetConsoleCursorPosition(hOuput, scrn);
}
using namespace std;


//���
void locate(int x, int y)
{
	coord.X = y;
	coord.Y = x;
	SetConsoleCursorPosition(hout, coord);
};
//���ع��
void hide()
{
	CONSOLE_CURSOR_INFO cursor_info = { 1,0 };
	SetConsoleCursorInfo(hout, &cursor_info);
}
//�Ǻ�����
void getPassword(char* storePw, int maxPwLen)
{
	char c = '\0';          //����û������ÿ���ַ�
	char* pc = storePw;    //Ϊ����ָ�������ַ�����ÿ���ַ�
	int pwlen = 0;          //��ǰpassword�ĳ���

	while (1)
	{
		c = getch();

		//����û����»س�����ֹͣѭ��
		if (c == '\r')
			break;

		//���û��������Ч�ַ��������봮�������ǿ��ַ�'\0'
		if (pwlen >= 0 && pwlen < maxPwLen - 1 && c)
		{
			*pc = c;
			pc++;
			pwlen++;
			putchar('*');
		}
	}
}

//���ҵ�ǰ�˻�
int findAccount(Account IV1)//��¼ʱ���ҵ�ǰ�˻�
{
	Account* curP = head;
	Trade* TcurP = Thead;
	while (curP != NULL)
	{
		if (strcmp(curP->account_number, IV1.account_number) == 0)
		{
			return 1;
		}
		curP = curP->next;
	}
	return 0;
}

//��֤��ǰ�˻�����
int findPassword(Account IV1)//��¼ʱ���ҵ�ǰ�˻�����
{
	Account* curP = head;
	while (curP != NULL)
	{
		if (strcmp(curP->account_number, IV1.account_number) == 0 && strcmp(curP->password, IV1.password) == 0)
		{
			curAccount = curP;
			return 1;
		}
		curP = curP->next;
	}
	return 0;
}

//�����Ƿ������˻�
int findAccount2(Account IV)
{
	Account* curP = head;
	while (curP != NULL)
	{
		if (strcmp(curP->account_number, IV.account_number) == 0)
		{
			return 1;
		}
		curP = curP->next;
	}
	return 0;
}

//����ת�˶���
int findAccount3(Account TT)
{
	Account* curP = head;
	while (curP != NULL)
	{
		if (strcmp(curAccount->account_number, TT.account_number) == 0)
		{
			int b, k = 0;
			if (Language == 1)
				printf("\n���ܸ��Լ�ת�ˣ�\n");
			else
				printf("\nYou can't transfer money to yourself!\n");
			while (k < 3)
			{
				if (Language == 1)
				{
					printf("\n\n\n\t\t��1���ٴ�����Է��˻�����");
					printf("\n\n\n\t\t��2��������ҳ");
					printf("\n\n\n\t\t��0���˳�ϵͳ\n\n");
				}
				else
				{
					printf("\n\n\n\t\t��1��Re-enter the account number of the other party");
					printf("\n\n\n\t\t��2��Return to the homepage");
					printf("\n\n\n\t\t��0��Exit the system\n\n");
				}
				scanf("%d", &b);
				switch (b)
				{
				case 1:
					system("cls");
					if (Language == 1)
						C_Transfer_Money();
					else
						E_Transfer_Money();
					k = 3;
					break;
				case 2:
					system("cls");
					C_Main_Menu();
					k = 3;
					break;
				case 0:
					k = 3;
					CE_Save_User_Data();
					exit(0);
				default:
					k++;
					break;
				}
			}
		}
		else if (strcmp(curP->account_number, TT.account_number) == 0)
		{
			curAccountO = curP;//��ǰת�˶����˻�
			return 1;
		}
		curP = curP->next;
	}
	return 0;
}

//ʱ��
void CE_Time()
{
	time_t t = time(0);
	Random_Number = time(0) % 4 + 1;
	char tmp[20];
	strftime(tmp, sizeof(tmp), "%Y/%m/%d/%X", localtime(&t));
	strftime(tmp1, sizeof(tmp), "%Y-%m-%d", localtime(&t));
	strcpy(TA.Time, tmp);
}

//ע��
void CE_Close_Account()
{
	printf("\n\n\t�Ƿ�ע�����˻���\n\n\t");
	int aaa, k1 = 1;
	while (k1)
	{
		k1 = 0;
		printf("\n\n\t\t��1��ע��\n");
		printf("\n\n\t\t��2��������ҳ\n");
		printf("\n\n\t\t��0���˳�ϵͳ\n");
		scanf("%d", &aaa);
		switch (aaa)
		{
		case 1:
			system("cls");
			CE_Close_Account1();
			break;
		case 2:
			system("cls");
			C_Main_Menu();
			break;
		case 0:
			system("cls");
			CE_Save_User_Data();
			exit(0);
			break;
		default:
			system("cls");
			printf("\n\n\t\t�������\n");
			k1 = 1;
			break;
		}
	}
}

//ע��
void CE_Close_Account1()
{
	printf("\n\n\t\tע���ɹ�����ӭ���´ι��١�\n");
	strcpy(curAccount->name, "XXXX");
	strcpy(curAccount->account_number, "XXXX");
	strcpy(curAccount->phone_number, "XXXX");
	strcpy(curAccount->password, "XXXX");
	CE_Save_User_Data();
	exit(0);

}

//�����û�����
void CE_Save_User_Data()
{
	FILE* fp = fopen("D:/atm.txt", "w");//�����û�����
	if (fp != NULL)
	{
		Account* curP = head;
		while (curP != NULL)
		{
			fprintf(fp, "%s\t%s\t%s\t%s\t%f\n", curP->account_number, curP->name, curP->phone_number, curP->password, curP->balance);
			curP = curP->next;
		}
		fclose(fp);
	}
}

//���潻������
void CE_Save_Transaction_Data()
{
	FILE* Tfp = fopen("D:/atmtrade.txt", "at+");//���潻������
	if (Tfp != NULL)
	{
		Trade* TcurP = Thead;
		while (TcurP != NULL)
		{
			if (TcurP->Tnext == NULL)
			{
				fprintf(Tfp, "%s\t%s\t%s\t%s\t%f\n", TcurP->Taccount_number, TcurP->Time, TcurP->Operation, TcurP->TarUse, TcurP->Money);
			}
			TcurP = TcurP->Tnext;
		}
		fclose(Tfp);
	}
}

//��ʼ���û���Ϣ
void CE_Initialize_User_Data()
{
	FILE* fp = fopen("D:/atm.txt", "r");
	if (fp != NULL)
	{
		while (!feof(fp))
		{
			Account* newNodeP = (Account*)malloc(sizeof(Account));
			fscanf(fp, "%s\t%s\t%s\t%s\t%f\n", newNodeP->account_number, newNodeP->name, newNodeP->phone_number, newNodeP->password, &newNodeP->balance);
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

//��ʼ��������Ϣ
void CE_Initialize_Transaction_Data()
{
	FILE* Tfp = fopen("D:/atmtrade.txt", "r");
	if (Tfp != NULL)
	{
		while (!feof(Tfp))
		{
			Trade* TnewNodeP = (Trade*)malloc(sizeof(Trade));
			fscanf(Tfp, "%s\t%s\t%s\t%s\t%f\n", TnewNodeP->Taccount_number, TnewNodeP->Time, TnewNodeP->Operation, TnewNodeP->TarUse, &TnewNodeP->Money);
			TnewNodeP->Tnext = NULL;

			if (Thead == NULL)
			{
				Thead = TnewNodeP;
				Ttail = TnewNodeP;
			}
			else
			{
				Ttail->Tnext = TnewNodeP;
				Ttail = TnewNodeP;
			}
		}
		fclose(Tfp);
	}
}

//��ʼ������
void CE_Initial_Password()
{
	strcpy(curAccount->password, "XXXXXX");
}

//��Ӣ����������
void CE_Set_Name()
{
	int a = 0;
	while (a < 3)
	{
		a++;
		if (Language == 1)
		{
			printf("\n\t>>���������������\n");
		}
		else
			printf("\n\t>>Please enter your name:\n");
		scanf("%s", IV.name);
		if (strlen(IV.name) < 100)
		{
			strcpy(Pset->name, IV.name);
			break;
		}
		else
		{
			if (Language == 1)
			{
				system("cls");
				printf("\n\t\t����������ù�����\n\n\t���������ã�\n");
			}
			else
				printf("\n\t\tYour name is set too long.\n\n\tPlease reset it:\n");
		}
	}
}

//��Ӣ����������
void CE_Set_Password()
{
	int a = 0;
	while (a < 3)
	{
		a++;
		if (Language == 1)
		{
			printf("\n\t>>����������˻����롾6λ����\n");
		}
		else
		{
			printf("\n\t>>Please set your account password [6 digits]��\n");
		    char storePassword[10] = { '\0' };    //�洢�û����������
		    printf("\n\n\t\t\t______\b\b\b\b\b\b");
		    getPassword(storePassword, 10);
		    strcpy(IV.password, storePassword);
		}
		if (strlen(IV.password) == 6)
		{
			strcpy(Pset->password, IV.password);
			break;
		}
		else
		{
			if (Language == 1)
			{
				system("cls");
				printf("\n\t\t����Ϊ��λ�����������������\n\n\t���������ã�\n");
			}
			else
				printf("\n\t\tThe password is six digits, your password is set incorrectly��\n\n\tPlease reset it:\n");

		}
	}
}

//��Ӣ�����õ绰��
void CE_Set_PhoneNumber()
{
	int a = 0;
	while (a < 3)
	{
		a++;
		if (Language == 1)
		{
			printf("\n\t>>��������ĵ绰���롾11λ����\n");
		}
		else
		{
			printf("\n\t>>Please enter your phone number [11 digits]:\n");
		    scanf("%s", IV.phone_number);
		}
		if (strlen(IV.phone_number) == 11)
		{
			strcpy(Pset->phone_number, IV.phone_number);
			break;
		}
		else
		{
			if (Language == 1)
			{
				system("cls");
				printf("\n\t\tԤ������ӦΪʮһλ�������Ԥ��������������\n\n\t���������룺\n");
			}
			else
				printf("\n\t\tThe reserved number should be eleven digits, your reserved number is set incorrectly!\n\n\tPlease reset it:\n");
		}
	}
}

//��Ӣ�������˻��˺�
void CE_Add_Account_Number()
{
	switch (Bank)
	{
	    case 1:
		AccountNum1++;
		itoa(AccountNum1, IV.account_number, 10);
		break;
	}
}

//��Ӣ�Ĵ����ˮ��¼
void CE_Deposit_Transaction()
{
	Trade* TP = (Trade*)malloc(sizeof(Trade));
	TP->Tnext = NULL;
	if (Thead == NULL)
	{
		Thead = TP;
		Ttail = TP;
	}
	else
	{
		Ttail->Tnext = TP;
		Ttail = TP;
		strcpy(TP->Taccount_number, curAccount->account_number);
		strcpy(TP->Time, TA.Time);
		strcpy(TP->Operation, "AA");
		TP->Money = TA.Money;
		strcpy(TP->TarUse, "�ɱ��˻����");
		CE_Save_Transaction_Data();
	}
}

//��Ӣ��ȡ����ˮ��¼
void  CE_Withdraw_Transaction()
{
	Trade* TP = (Trade*)malloc(sizeof(Trade));
	TP->Tnext = NULL;
	if (Thead == NULL)
	{
		Thead = TP;
		Ttail = TP;
	}
	else
	{
		Ttail->Tnext = TP;
		Ttail = TP;
		strcpy(TP->Taccount_number, curAccount->account_number);
		strcpy(TP->Time, TA.Time);
		strcpy(TP->Operation, "BB");
		TP->Money = TA.Money;
		strcpy(TP->TarUse, "�ɱ��˻�ȡ��");
		CE_Save_Transaction_Data();
	}
}

//��Ӣ��ת��ת����ˮ��¼
void  CE_Transfer_Transaction()
{
	Trade* TP = (Trade*)malloc(sizeof(Trade));
	TP->Tnext = NULL;
	if (Thead == NULL)
	{
		Thead = TP;
		Ttail = TP;
	}
	else
	{
		Ttail->Tnext = TP;
		Ttail = TP;
		strcpy(TP->Taccount_number, curAccount->account_number);
		strcpy(TP->Time, TA.Time);
		strcpy(TP->Operation, "BA");
		strcpy(TP->TarUse, curAccountO->account_number);
		TP->Money = TA.Money;
		CE_Save_Transaction_Data();
	}


	//ת��ת����ˮ��¼

	Trade* TPi = (Trade*)malloc(sizeof(Trade));//���彻�׽ṹ�� ���� ת��TPi
	TPi->Tnext = NULL;
	if (Thead == NULL)
	{
		Thead = TPi;
		Ttail = TPi;
	}
	else
	{
		Ttail->Tnext = TPi;
		Ttail = TPi;
		strcpy(TPi->Taccount_number, curAccountO->account_number);//��ǰת���˺Ÿ�ֵ��TPi
		strcpy(TPi->Time, TA.Time);//��ǰʱ�丳ֵ��TPi
		strcpy(TPi->Operation, "AB");//��ǰ�������͸�ֵ��TPi
		strcpy(TPi->TarUse, curAccount->account_number);
		TPi->Money = -TA.Money;//��ǰ���׽�ֵ��TPi
		CE_Save_Transaction_Data();
	}
}



//��Ӣ����������ˮ��¼
void CE_SXF_Transaction()
{
	Trade* TP = (Trade*)malloc(sizeof(Trade));
	TP->Tnext = NULL;
	if (Thead == NULL)
	{
		Thead = TP;
		Ttail = TP;
	}
	else
	{
		Ttail->Tnext = TP;
		Ttail = TP; 
		strcpy(TP->Taccount_number, curAccount->account_number);
		strcpy(TP->Time, TA.Time);
		strcpy(TP->Operation, "CC");
		strcpy(TP->TarUse, "���˻�ת��");
		TP->Money = -SXFmoey;
		CE_Save_Transaction_Data();
	}
}
//��Ӣ�Ĵ�ӡ��ˮ
void CE_Print_Transaction()
{
	int k = 0, w = 0;
	Trade* TcurP = Thead;
	if (Language == 1)
		printf("\n���\tʱ�䣺\t\t\t\t�������ͣ�\t\t����������\t���ױ�ע��\n\n");
	else
		printf("\nNum:\tTime:\t\t\t\tTrading Type:\t\tTrading money quantity:\tRemark:\n\n");
	while (TcurP != NULL)//���׼�¼
	{
		if (strcmp(curAccount->account_number, TcurP->Taccount_number) == 0)
		{
			w++;
			TcurAccount = TcurP;
			if (Language == 1)
			{
				if (strcmp(TcurAccount->Operation, "AA") == 0)
				{
					if (TcurAccount->Money < 0)
						printf("\n<%d>\t%s\t\t����\t\t%8.2f\t\t%s\t\n", w, TcurAccount->Time, TcurAccount->Money, TcurAccount->TarUse);
					else
						printf("\n<%d>\t%s\t\t����\t\t+%-8.2f\t\t%s\t\n", w, TcurAccount->Time, TcurAccount->Money, TcurAccount->TarUse);
				}
				else if (strcmp(TcurAccount->Operation, "BB") == 0)
				{
					if (TcurAccount->Money < 0)
						printf("\n<%d>\t%s\t\t֧��\t\t%8.2f\t\t%s\t\n", w, TcurAccount->Time, TcurAccount->Money, TcurAccount->TarUse);
					else
						printf("\n<%d>\t%s\t\t֧��\t\t+%-8.2f\t\t%s\t\n", w, TcurAccount->Time, TcurAccount->Money, TcurAccount->TarUse);
				}
				else if (strcmp(TcurAccount->Operation, "BA") == 0)
				{
					if (TcurAccount->Money < 0)
						printf("\n<%d>\t%s\t\t֧��\t\t%8.2f\t\t%s\t\n", w, TcurAccount->Time, TcurAccount->Money, TcurAccount->TarUse);
					else
						printf("\n<%d>\t%s\t\t֧��\t\t+%-8.2f\t\t%s\t\n", w, TcurAccount->Time, TcurAccount->Money, TcurAccount->TarUse);
				}
				else if (strcmp(TcurAccount->Operation, "AB") == 0)
				{
					if (TcurAccount->Money < 0)
						printf("\n<%d>\t%s\t\t����\t\t%8.2f\t\t%s\t\n", w, TcurAccount->Time, TcurAccount->Money, TcurAccount->TarUse);
					else
						printf("\n<%d>\t%s\t\t����\t\t+%-8.2f\t\t%s\t\n", w, TcurAccount->Time, TcurAccount->Money, TcurAccount->TarUse);
				}
			}
			else
			{
				if (strcmp(TcurAccount->Operation, "AA") == 0)
				{
					if (TcurAccount->Money < 0)
						printf("\n<%d>\t%s\t\tSave\t\t%8.2f\t\t%s\t||\n", w, TcurAccount->Time, TcurAccount->Money, TcurAccount->TarUse);
					else
						printf("\n<%d>\t%s\t\tSave\t\t+%08.2f\t\t%s\t||\n", w, TcurAccount->Time, TcurAccount->Money, TcurAccount->TarUse);
				}
				else if (strcmp(TcurAccount->Operation, "BB") == 0)
				{
					if (TcurAccount->Money < 0)
						printf("\n<%d>\t%s\t\tTake\t\t%8.2f\t\t%s\t||\n", w, TcurAccount->Time, TcurAccount->Money, TcurAccount->TarUse);
					else
						printf("\n<%d>\t%s\t\tTake\t\t+%08.2f\t\t%s\t||\n", w, TcurAccount->Time, TcurAccount->Money, TcurAccount->TarUse);
				}
				else if (strcmp(TcurAccount->Operation, "AB") == 0)
				{
					if (TcurAccount->Money < 0)
						printf("\n<%d>\t%s\t\tSend\t\t%8.2f\t\t%s\t||\n", w, TcurAccount->Time, TcurAccount->Money, TcurAccount->TarUse);
					else
						printf("\n<%d>\t%s\t\tSend\t\t+%08.2f\t\t%s\t||\n", w, TcurAccount->Time, TcurAccount->Money, TcurAccount->TarUse);
				}
				else if (strcmp(TcurAccount->Operation, "BA") == 0)
				{
					if (TcurAccount->Money < 0)
						printf("\n<%d>\t%s\t\tSend\t\t%8.2f\t\t%s\t||\n", w, TcurAccount->Time, TcurAccount->Money, TcurAccount->TarUse);
					else
						printf("\n<%d>\t%s\t\tSend\t\t+%08.2f\t\t%s\t||\n", w, TcurAccount->Time, TcurAccount->Money, TcurAccount->TarUse);
				}
			}

			k++;
		}
		TcurP = TcurP->Tnext;
	}
	if (k == 0)
	{
		if (Language == 1)
			printf("\n\t���޽��׼�¼\n\t\t\n\n");
		else
			printf("\n\tNo transaction record now.\n\t\t\n\n");
	}
}

//ѡ������
void CE_ChooseBank()
{
	int a, k = 1;
	while (k)
	{
		k = 0;
		if (Language == 1)
		{
			printf("\nע���˺��밴��1�����˳��밴��0����\n\n");
			printf("\n\n\t\t��1����������\n");
			printf("\n\n\t\t��0���˳�ϵͳ\n");
			printf("\n\n\t\t\t���ѡ��___\b\b\b");
		}
		else
		{
			printf("\nPlease ע���˺��밴��1�����˳��밴��0����\n\n");
			printf("\n\n\t\t��1��China Construction Bank\n");
			printf("\n\n\t\t��0��Exit the system\n");
			printf("\n\n\t\t\tYour choice��___\b\b\b");
		}
		scanf("%d", &a);
		switch (a)
		{
		case 1:
			Bank = 1;
			break;
		case 2:
			Bank = 2;
			break;
		case 3:
			Bank = 3;
			break;
		case 0:
			system("cls");
			CE_Save_User_Data();
			exit(0);
			break;
		default:
			system("cls");
			printf("\n\n\t\tEnter eroor��\n");
			k = 1;
			break;
		}
	}
}

//����ע��
void C_Sign_Up()//����ע�ắ��
{
	int a, k = 0;
	system("cls");
	printf("\n��ע�᡿\t\t\t\t\t\t\t\t\t\t%s", tmp1);
 
	CE_ChooseBank();
	Pset->next = NULL;//Account* Pset = (Account*)malloc(sizeof(Account));//�Ѷ���
	if (head == NULL)
	{
		head = Pset;
		tail = Pset;//������ǵ�һ�������Ľ�㣬��ͷ βָ��ָ��������
	}
	else
		tail->next = Pset; //������ǵ�һ�������Ľ�㣬����һ�����ĺ��ָ��ָ��ǰ���
	CE_Set_Name();//��ת����������������
	CE_Add_Account_Number();//��ת�����������˻����뺯��
	strcpy(Pset->account_number, IV.account_number);
	CE_Set_PhoneNumber();//��ת����������Ԥ���绰����
	CE_Set_Password();//��ת�������������뺯��
	Pset->balance = 0;
	CE_Save_User_Data();
	while (k < 3)
	{
		system("cls");
		printf("\n\t\tע��ɹ�\n");
		printf("\n\t>>����˻�����Ϊ %s\n", Pset->account_number);
		printf("\n\n\t\t��1�����ص�¼\n");
		printf("\n\n\t\t��0���˳�ϵͳ\n");
		printf("\n\n\t\t\t���ѡ��___\b\b\b");
		scanf("%d", &a);
		if (a == 1)
		{
			system("cls");
			C_Sign_In();
			break;
		}
		else if (a == 0)
		{
			exit(0);
		}
		else
		{
			k++;
			printf("\n�����������! \t%d\t�밴����ʾ�������룺\n", 3 - k);
		}
	}
}

//Ӣ��ע��
void E_Sign_Up()//Ӣ��ע�ắ��
{
	int a, k = 0;
	printf("\nWelcome to register\n\n");

	CE_ChooseBank();
	Pset->next = NULL;
	if (head == NULL)
	{
		head = Pset;
		tail = Pset;
	}
	else
	{
		tail->next = Pset;
		CE_Set_Name();
		CE_Add_Account_Number();
		strcpy(Pset->account_number, IV.account_number);
		CE_Set_PhoneNumber();
		CE_Set_Password();
		Pset->balance = 0;
		CE_Save_User_Data();
		while (k < 3)
		{
			system("cls");
			printf("\n\t\tRegistration Success!\n");
			printf("\n\t>>Your account number is  %s\n", Pset->account_number);
			printf("\n\n\t\t��1�� Return to login\n");
			printf("\n\n\t\t��0�� Exit the system\n");
			printf("\n\n\t\t\tYour chioce��___\b\b\b");
			scanf("%d", &a);
			if (a == 1)
			{
				system("cls");
				E_Sign_In();
				break;
			}
			else if (a == 0)
			{
				exit(0);
			}
			else
			{
				k++;
				printf("\nPassword entered incorrectly! \t%d\tPlease re-enter as prompted:\n", 3 - k);
			}
		}
	}
}

//���ĵ�¼
void C_Sign_In()
{
	system("cls");
	int m = 0, n = 0;
	while (m < 3)//3��������˺Ž��˳�ϵͳ
	{
		Account IV1;//�˻��м����1
		printf("\n����¼��\t\t\t\t\t\t\t\t\t\t%s", tmp1);
	 
		printf("\n\n\n\t>>�������˺ţ�\n");
		printf("\n\n\t\t\t__________\b\b\b\b\b\b\b\b\b\b");
		scanf("%s", IV1.account_number);
		system("cls");
		if (findAccount(IV1))
		{
			while (n < 3)//3����������뽫�˳�ϵͳ
			{
				printf("\n����¼��\t\t\t\t\t\t\t\t\t\t%s", tmp1);
			 
				printf("\n\n\n\t>>���������룺\n");
				char storePassword[10] = { '\0' };    //�洢�û����������
				printf("\n\n\t\t\t______\b\b\b\b\b\b");
				getPassword(storePassword, 10);
				strcpy(IV1.password, storePassword);
				system("cls");
				if (findPassword(IV1))
				{
					m = 3;
					n = 3;
					if (Sin == 1)
						C_Main_Menu();
					
					else
						C_Main_Menu();
					break;
				}
				else
				{
					m++;
					n++;
					if (n == 3)
					{
						printf("\n\n\t���˺��Ѿ������ᣬ����ϵ��̨�һء�\n");
						CE_Initial_Password();
						break;
					}
					else
					{
						printf("\n\n\t�������  %d�λ�����˺Ž��ᱻ����\n", 3 - n);
					}
				}
			}
		}
		else
		{
			m++;
			printf("\n\n\tû�в��ҵ����û�!  %d  ���������룺\n", 3 - m);
			if (m == 3)
			{
				printf("\n\n\t�������˳�ϵͳ\n");
				CE_Save_User_Data();
				exit(0);
			}
		}
	}
}

//Ӣ���¼
void E_Sign_In()
{
	system("cls");
	int m = 0, n = 0;
	while (m < 3)//3��������˺Ž��˳�ϵͳ
	{
		Account IV1;//�˻��м����1
		printf("\nSign in\n==========================================\n");
		printf("\n\n\t>>Please enter account number:\n");
		printf("\n\n\t\t\t__________\b\b\b\b\b\b\b\b\b\b");
		scanf("%s", IV1.account_number);
		system("cls");
		if (findAccount(IV1))
		{
			while (n < 3)//3����������뽫�˳�ϵͳ
			{
				printf("\nSign in\n========================================\n\n\n\t>>>>Please enter password:\n");
				char storePassword[10] = { '\0' };    //�洢�û����������
				printf("\n\n\t\t\t______\b\b\b\b\b\b");
				getPassword(storePassword, 10);
				strcpy(IV1.password, storePassword);
				system("cls");

				if (findPassword(IV1))
				{
					m = 3;
					n = 3;
					printf("\nMenu\n========================================\n");
					E_Main_Menu();
					break;
				}
				else
				{
					m++;
					n++;
					if (n == 3)
					{
						printf("\n\n\tThe account has been frozen, please contact the background to retrieve it.\n");
						CE_Initial_Password();
						break;
					}
					else
					{
						printf("\n\n\tThe password is wrong, the account will be frozen after %d chance\n", 3 - n);
					}
				}
			}
		}
		else
		{
			m++;
			printf("\n\n\tThe user was not found! %d Please re-enter:\n", 3 - m);
			if (m == 3)
			{
				printf("\n\n\tError, logged out\n");
				CE_Save_User_Data();
				exit(0);
			}
		}
	}
}

//���Ĳ˵�ҳ
void C_Main_Menu()//
{
	printf("\n���˵���\t\t\t\t\t\t\t\t\t\t%s", tmp1);
 
	int a, k1 = 1;
	while (k1)
	{
		k1 = 0;
		printf("\n\n\t\t��1�����\n");
		printf("\n\n\t\t��2��ȡ��\n");
		printf("\n\n\t\t��3��ת��\n");
		printf("\n\n\t\t��4����ѯ\n");
		printf("\n\n\t\t��5���޸ĸ�������\n");
		printf("\n\n\t\t��6��ע���˺�\n");
		printf("\n\n\t\t��0���˳�ϵͳ\n");
		printf("\n\n\t\t\t���ѡ��___\b\b\b");
		scanf("%d", &a);
		switch (a)
		{
		case 1:
			system("cls");
			C_DepositMoney();
			break;
		case 2:
			system("cls");
			C_Withdraw_Money();
			break;
		case 3:
			system("cls");
			C_Transfer_Money();
			break;
		case 4:
			system("cls");
			C_Enquiry();
			break;
		case 5:
			system("cls");
			C_Change_Information();
			break;
		case 6:
			system("cls");
			CE_Close_Account();
			break;
		case 0:
			system("cls");
			CE_Save_User_Data();
			exit(0);
			break;
		default:
			system("cls");
			printf("\n���˵���\t\t\t\t\t\t\t\t\t\t%s", tmp1);
		 
			printf("\n\n\t\t�������\n");
			k1 = 1;
			break;
		}
	}
}


//Ӣ��˵�ҳ
void E_Main_Menu()//
{
	int a, k1 = 1;
	while (k1)
	{
		k1 = 0;
		printf("\n\n\t\t��1��Deposit money\n");
		printf("\n\n\t\t��2��Withdraw money\n");
		printf("\n\n\t\t��3��Transfer money\n");
		printf("\n\n\t\t��4��Inquire\n");
		printf("\n\n\t\t��5��Modify personal information\n");
		printf("\n\n\t\t��6��Logout\n");
		printf("\n\n\t\t��0��Exit system\n");
		printf("\n\n\t\t\tYour chioce��___\b\b\b");
		scanf("%d", &a);
		switch (a)
		{
		case 1:
			system("cls");
			E_DepositMoney();
			break;
		case 2:
			system("cls");
			E_Withdraw_Money();
			break;
		case 3:
			system("cls");
			E_Transfer_Money();
			break;
		case 4:
			system("cls");
			E_Enquiry();
			break;
		case 5:
			system("cls");
			E_Change_Information();
			break;
		case 6:
			system("cls");
			CE_Close_Account();
			break;
		case 0:
			system("cls");
			CE_Save_User_Data();
			exit(0);
			break;
		default:
			system("cls");
			printf("\n\n\t\tIncorrect input!\n");
			k1 = 1;
			break;
		}
	}
}

//���Ĵ��ҵ��
void C_DepositMoney()
{
	int a;
	printf("\n\t\t\t����\t\t\t\t\t\t\t\t\t\t%s", tmp1);
 
	printf("\n\n\n\t����ܰ��ʾ��1.�������Ϊ100��������\n\n\t\t     2.���ʽ��ó���10000��");
	printf("\n\n\n\t>>��������Ҫ����Ľ�\n");
	printf("\n\n\t\t\t______\b\b\b\b\b\b");
	scanf("%d", &a);
	if (a % 100 || a > 10000)
	{
		system("cls");
		printf("\n����\t\t\t\t\t\t\t\t\t\t%s", tmp1);
	 
		if (Sin == 1)
		{
			if (a > 10000)
			{
				printf("���ʲ��ó���10000��\n\n");
			}
			else
				printf("�������Ϊ100��������\n\n");
			C_DepositMoney1();//���ʧ��ѡ��
		}
		else if (Sin == 3)
		{
			if (a > 10000)
			{
				printf("\n\n\n\n\n\n\n\n\n\t���ʲ��ó���10000��\n\n");
			}
			else
				printf("\n\n\n\n\n\n\n\n\n\t�������Ϊ100��������\n\n");

		}
	}
	else
	{
		CE_Time();
		TA.Money = a * 1.00;
		curAccount->balance = curAccount->balance + TA.Money;
		system("cls");
		printf("\n����\t\t\t\t\t\t\t\t\t\t%s", tmp1);
	 
		CE_Save_User_Data();
		CE_Deposit_Transaction();
		if (Sin == 1)
		{
			printf("\n\t�������ѳɹ�����%.2fԪ!\n", TA.Money);
			C_DepositMoney2();//���ɹ�ѡ��
		}
		else if (Sin == 3)
		{
			printf("\n\n\n\n\n\n\n\n\n\t�������ѳɹ�����%.2fԪ!\n", TA.Money); 
		}
	}
}

//���ʧ��ѡ��
void C_DepositMoney1()
{
	int k = 0, b;
	while (k < 3)
	{
		printf("\n\n\t\t��1��������������\n");
		printf("\n\n\t\t��2��������ҳ\n");
		printf("\n\n\t\t��0���˳�ϵͳ\n");
		printf("\n\n\t\t\t���ѡ��___\b\b\b");
		scanf("%d", &b);
		switch (b)
		{
		case 1:
			system("cls");
			C_DepositMoney();
			k = 3;
			break;
		case 2:
			system("cls");
			C_Main_Menu();
			k = 3;
			break;
		case 0:
			k = 3;
			CE_Save_User_Data();
			exit(0);
		default:
			k++;
			break;
		}
	}
}

//���ɹ�ѡ��
void C_DepositMoney2()
{
	int k = 0, b;
	while (k < 3)
	{
		printf("\n\n\t\t��1���ٴ�һ��\n");
		printf("\n\n\t\t��2��������ҳ\n");
		printf("\n\n\t\t��0���˳�ϵͳ\n");
		printf("\n\n\t\t\t���ѡ��___\b\b\b");
		scanf("%d", &b);
		switch (b)
		{
		case 1:
			system("cls");
			C_DepositMoney();
			k = 3;
			break;
		case 2:
			system("cls");
			C_Main_Menu();
			k = 3;
			break;
		case 0:
			k = 3;
			CE_Save_User_Data();
			exit(0);
		default:
			k++;
			break;
		}
	}
}



//Ӣ����ҵ��
void E_DepositMoney()
{
	int a;
	printf("\n[Save Beans]\t\t\t\t\t\t\t\t\t\t%s", tmp1);
 
	printf("\n\n\n\t[Reminder] 1. The number of money must be an integer of 100.\n\n\t\t2. A single deposit of beans cannot exceed 10,000.");
	printf("\n\n\n\t>>Please enter the money you want to deposit:\n");
	printf("\n\n\t\t\tYour chioce��___\b\b\b");
	scanf("%d", &a);
	if (a % 100 || a > 10000)
	{
		int k = 0, b;
		system("cls");
		printf("\n[Save Beans]\t\t\t\t\t\t\t\t\t\t%s", tmp1);
	 
		if (a > 10000)
		{
			printf("Single deposit must not exceed 10000.\n\n");
		}
		else
			printf("The amount of money must be an integer of 100.\n\n");
		while (k < 3)
		{
			printf("\n\n\t\t��1��Re-enter the amount of money\n");
			printf("\n\n\t\t��2��Return to homepage\n");
			printf("\n\n\t\t��0��Exit the system\n");
			printf("\n\n\t\t\tYour chioce��___\b\b\b");
			scanf("%d", &b);
			switch (b)
			{
			case 1:
				system("cls");
				E_DepositMoney();
				k = 3;
				break;
			case 2:
				system("cls");
				E_Main_Menu();
				k = 3;
				break;
			case 0:
				k = 3;
				CE_Save_User_Data();
				exit(0);
			default:
				k++;
				break;
			}
		}
	}
	else
	{
		CE_Time();
		TA.Money = a * 1.00;
		curAccount->balance = curAccount->balance + TA.Money;
		system("cls");
		printf("\n[Save Beans]\t\t\t\t\t\t\t\t\t\t%s", tmp1);
	 
		printf("\nYou have successfully deposited %.2f yuan!\n", TA.Money);
		CE_Save_User_Data();
		CE_Deposit_Transaction();
		int k = 0, b;
		while (k < 3)
		{
			printf("\n\n\t\t��1��Save another one\n");
			printf("\n\n\t\t��2��Return to homepage\n");
			printf("\n\n\t\t��0��Exit the system\n");
			printf("\n\n\t\t\tYour chioce��___\b\b\b");
			scanf("%d", &b);
			switch (b)
			{
			case 1:
				system("cls");
				E_DepositMoney();
				k = 3;
				break;
			case 2:
				system("cls");
				E_Main_Menu();
				k = 3;
				break;
			case 0:
				k = 3;
				CE_Save_User_Data();
				exit(0);
			default:
				k++;
				break;
			}
		}
	}
}

//����ȡ��ҵ��
void C_Withdraw_Money()
{
	int a;
	printf("\n��ȡ�\t\t\t\t\t\t\t\t\t\t%s", tmp1);
 
	printf("\n\n\n\t\t����ܰ��ʾ��1.ȡ������Ϊ100��������");
	printf("\n\n\n\t\t\t     2.���ʲ��ó���10000��");
	printf("\n\n\n\t\t>>��������Ҫȡ���Ľ�______\b\b\b\b\b\b");
	scanf("%d", &a);
	if (a % 100 || a > 10000)
	{
		system("cls");
		printf("\n��ȡ�\t\t\t\t\t\t\t\t\t\t%s", tmp1);
	 
		if (Sin == 1)
		{
			if (a > 10000)
			{
				printf("���ʲ��ó���10000��\n\n");
			}
			else
				printf("ȡ������Ϊ100��������\n\n");
			C_Withdraw_Money1();//ȡ��ʧ��ѡ��
		}
		else if (Sin == 3)
		{
			if (a > 10000)
			{
				printf("\n\n\n\n\n\n\n\n\n\t���ʲ��ó���10000��\n\n");
			}
			else
				printf("\n\n\n\n\n\n\n\n\n\tȡ����Ϊ100��������\n\n");
			
		}
	}
	else
	{
		CE_Time();
		TA.Money = a * -1.00;
		if (curAccount->balance + TA.Money < 0)
		{
			system("cls");
			printf("\n��ȡ�\t\t\t\t\t\t\t\t\t\t%s", tmp1);
		 
			if (Sin == 1)
			{
				printf("\n\t����!\n");
				C_Withdraw_Money1();//ȡ��ʧ��ѡ��
			}
			else if (Sin == 3)
			{
				printf("\n\n\n\n\n\n\n\n\n\t����!\n");
			
			}
		}
		else
		{
			curAccount->balance = curAccount->balance + TA.Money;
			system("cls");
			printf("\n��ȡ�\t\t\t\t\t\t\t\t\t\t%s", tmp1);
		 
			CE_Save_User_Data();
			CE_Withdraw_Transaction();
			if (Sin == 1)
			{
				printf("\n\tȡ��ɹ�!\n");
				C_Withdraw_Money2();//ȡ��ɹ�ѡ��
			}
			else if (Sin == 3)
			{
				printf("\n\n\n\n\n\n\n\n\n\tȡ��ɹ�!\n");
			
			}
		}
	}
}

//ȡ��ʧ��ѡ��
void C_Withdraw_Money1()
{
	int k = 0, b;
	while (k < 3)
	{
		printf("\n\n\n\t\t��1����������ȡ����");
		printf("\n\n\n\t\t��2��������ҳ");
		printf("\n\n\n\t\t��0���˳�ϵͳ");
		printf("\n\n\t\t\t���ѡ��___\b\b\b");
		scanf("%d", &b);
		switch (b)
		{
		case 1:
			system("cls");
			C_Withdraw_Money();
			k = 3;
			break;
		case 2:
			system("cls");
			C_Main_Menu();
			k = 3;
			break;
		case 0:
			k = 3;
			CE_Save_User_Data();
			exit(0);
		default:
			k++;
			break;
		}
	}
}

//ȡ��ɹ�ѡ��
void C_Withdraw_Money2()
{
	int k = 0, b;
	while (k < 3)
	{
		printf("\n\n\n\t\t��1���ٴ�ȡǮ");
		printf("\n\n\n\t\t��2��������ҳ");
		printf("\n\n\n\t\t��0���˳�ϵͳ\n\n");
		printf("\n\n\t\t\t���ѡ��___\b\b\b");
		scanf("%d", &b);
		switch (b)
		{
		case 1:
			system("cls");
			C_Withdraw_Money();
			k = 3;
			break;
		case 2:
			system("cls");
			C_Main_Menu();
			k = 3;
			break;
		case 0:
			k = 3;
			CE_Save_User_Data();
			exit(0);
		default:
			k++;
			break;
		}
	}
}


//Ӣ��ȡ��ҵ��
void E_Withdraw_Money()
{
	int a;
	printf("\n��Take money��\t\t\t\t\t\t\t\t\t\t%s", tmp1);
 
	printf("\n\n\n\t\t[Reminder] 1. The number of money must be an integer of 100.");
	printf("\n\n\n\t\t\t2. A single fetch must not exceed 10000.");
	printf("\n\n\n\t\t>>Please enter the money you want to take out:\n\n");
	printf("\n\n\t\t\t______\b\b\b\b\b\b");
	scanf("%d", &a);
	if (a % 100 || a > 10000)
	{
		int k = 0, b;
		system("cls");
		printf("\n��Take money��\t\t\t\t\t\t\t\t\t\t%s", tmp1);
	 
		if (a > 10000)
		{
			printf("Single deposit must not exceed 10000.\n\n");
		}
		else
			printf("The amount of money must be an integer of 100.\n\n");
		while (k < 3)
		{
			printf("\n\n\n\t\t��1�� Re-enter the amount of money");
			printf("\n\n\n\t\t��2�� Return to home page");
			printf("\n\n\n\t\t��0�� Exit the system");
			printf("\n\n\t\t\tYour chioce��___\b\b\b");
			scanf("%d", &b);
			switch (b)
			{
			case 1:
				system("cls");
				E_Withdraw_Money();
				k = 3;
				break;
			case 2:
				system("cls");
				E_Main_Menu();
				k = 3;
				break;
			case 0:
				k = 3;
				CE_Save_User_Data();
				exit(0);
			default:
				k++;
				break;
			}
		}
	}
	else
	{
		CE_Time();
		TA.Money = a * -1.00;
		if (curAccount->balance + TA.Money < 0)
		{
			int k = 0, b;
			system("cls");
			printf("\n��Take money��\t\t\t\t\t\t\t\t\t\t%s", tmp1);
		 
			printf("\nNot enough money!\n");
			while (k < 3)
			{
				printf("\n\n\n\t\t��1�� Re-enter the amount of money");
				printf("\n\n\n\t\t��2�� Return to home page");
				printf("\n\n\n\t\t��0�� Exit the system\n");
				printf("\n\n\t\t\tYour chioce��___\b\b\b");
				scanf("%d", &b);
				switch (b)
				{
				case 1:
					system("cls");
					E_Withdraw_Money();
					k = 3;
					break;
				case 2:
					system("cls");
					E_Main_Menu();
					k = 3;
					break;
				case 0:
					k = 3;
					CE_Save_User_Data();
					exit(0);
				default:
					k++;
					break;
				}
			}
		}
		else
		{
			curAccount->balance = curAccount->balance + TA.Money;
			system("cls");
			printf("\n��Take money��\t\t\t\t\t\t\t\t\t\t%s", tmp1);
		 
			printf("\nGet the money successfully!!!!\n");
			CE_Save_User_Data();
			CE_Withdraw_Transaction();
			int k = 0, b;
			while (k < 3)
			{
				printf("\n\n\n\t\t��1�� Take beans again");
				printf("\n\n\n\t\t��2�� Return to home page");
				printf("\n\n\n\t\t��0�� Exit the system\n\n");
				printf("\n\n\t\t\tYour chioce��___\b\b\b");
				scanf("%d", &b);
				switch (b)
				{
				case 1:
					system("cls");
					E_Withdraw_Money();
					k = 3;
					break;
				case 2:
					system("cls");
					E_Main_Menu();
					k = 3;
					break;
				case 0:
					k = 3;
					CE_Save_User_Data();
					exit(0);
				default:
					k++;
					break;
				}
			}
		}
	}
}

//ת��ҵ��
void C_Transfer_Money()
{
	int a = 100;
	printf("\n\t\t��ת�ˡ�\t\t%s", tmp1);
	printf("\t1������ת�˲��ó���10000Ԫ��\n\t\n");
	printf("\t----------------------------------------------------\n");
	printf("\n\n\n\n\t\t>>��������Ҫת�������˻���__________\b\b\b\b\b\b\b\b\b\b");
	Account TT;//Ŀ���˻�
	scanf("%s", &TT.account_number);
	if (findAccount3(TT))
	{
		ACCOUNT = atoi(curAccount->account_number);//��ǰ�˻�ת��Ϊ��ֵ
		TACCOUNT = atoi(TT.account_number);        //��ǰ�Է��˻�ת��Ϊ��ֵ
		system("cls");
		printf("\n��ת�ˡ�\t\t\t\t\t\t\t\t\t\t%s", tmp1);
	 
		if (Sin == 1)
		{
			printf("\t1������ת�˲��ó���10000Ԫ��\n\t\n");
		
			printf("\t----------------------------------------------------\n");
			printf("\n\n\t\t>>��������Ҫת���Ľ�______\b\b\b\b\b\b");
		}
		else if (Sin == 3)
		{
			printf("\n\n\t\t>>��������Ҫת���Ľ�______\b\b\b\b\b\b");
		}
		scanf("%d", &a);
		if (a > 10000)
		{

			if (Sin == 1)
			{
				printf("\n\t����ת�˲��ó���10000��\n\n");
				C_Transfer_Money1();//ȡ��ʧ��ѡ��
			}
			else if (Sin == 3)
			{
				printf("\n\n\n\n\n\n\n\n\n\t����ת�˲��ó���10000��\n\n");
				
			}
		}
		else
		{
			CE_Time();
			TA.Money = a * -1.00;
			SXFmoey = SXF * 0.01 * a;
			if (curAccount->balance + TA.Money - SXFmoey < 0)
			{
				system("cls");
				printf("\n��ת�ˡ�\t\t\t\t\t\t\t\t\t\t%s", tmp1);
			 

				if (Sin == 1)
				{
					printf("\n\t����!\n");
					C_Transfer_Money1();          //ת��ʧ��ѡ��
				}
				else if (Sin == 3)
				{
					printf("\n\n\n\n\n\n\n\n\n\t����!\n");
					
				}
			}
			else
			{
				system("cls");
				printf("\n��ת�ˡ�\t\t\t\t\t\t\t\t\t\t%s", tmp1);
			 
				curAccount->balance = curAccount->balance + TA.Money - SXFmoey;//��ǰ�˻���ȥת�˽���������
				curAccountO->balance = curAccountO->balance - TA.Money;      //�Է��˻�����ת�˽��
				CE_Transfer_Transaction();
				CE_Save_User_Data();
				if (Sin == 1)
				{
					printf("\n\tת�˳ɹ�!!!!\n");
					C_Transfer_Money2();           //ת�˳ɹ�ѡ��
				}
				else if (Sin == 3)
				{
					printf("\n\n\n\n\n\n\n\n\n\tת�˳ɹ�!!!!\n");
				
				}
			}
		}
	}
	else
	{
		system("cls");
		printf("\n��ת�ˡ�\t\t\t\t\t\t\t\t\t\t%s", tmp1);
	 
		if (Sin == 1)
		{
			printf("\n\t�Է��˻������ڣ�������");
			C_Transfer_Money1();             //ȡ��ʧ��ѡ��
		}
		else if (Sin == 3)
		{
			printf("\n\n\n\n\n\n\n\n\n\t�Է��˻������ڣ�������");
		
		}
	}
}

//ת��ʧ��ѡ��
void C_Transfer_Money1()
{
	int k = 0, b;
	while (k < 3)
	{
		printf("\n\n\n\t\t��1������ת��");
		printf("\n\n\n\t\t��2��������ҳ");
		printf("\n\n\n\t\t��0���˳�ϵͳ\n");
		printf("\n\n\t\t\t���ѡ��___\b\b\b");
		scanf("%d", &b);
		switch (b)
		{
		case 1:
			system("cls");
			C_Transfer_Money();
			k = 3;
			break;
		case 2:
			system("cls");
			C_Main_Menu();
			k = 3;
			break;
		case 0:
			k = 3;
			CE_Save_User_Data();
			exit(0);
		default:
			k++;
			break;
		}
	}
}

//ת�˳ɹ�ѡ��
void C_Transfer_Money2()
{
	int k2 = 0, b;
	while (k2 < 3)
	{
		printf("\n\n\n\t\t��1���ٴ�ת��");
		printf("\n\n\n\t\t��2��������ҳ");
		printf("\n\n\n\t\t��0���˳�ϵͳ\n\n");
		printf("\n\n\t\t\t���ѡ��___\b\b\b");
		scanf("%d", &b);
		switch (b)
		{
		case 1:
			system("cls");
			C_Transfer_Money();
			k2 = 3;
			break;
		case 2:
			system("cls");
			C_Main_Menu();
			k2 = 3;
			break;
		case 0:
			k2 = 3;
			CE_Save_User_Data();
			exit(0);
		default:
			k2++;
			break;
		}
	}
}



//ת��ҵ��
void E_Transfer_Money()
{
	int a = 100;
	printf("\n��Send Beans��\t\t\t\t\t\t\t\t\t\t%s", tmp1);
 
	printf("\n\n\n\t��Reminder��1. No more than 10000 yuan can be sent at a time.\n");
	printf("\n\n\t\t2.Beware of scams.");
	printf("\n\n\t\t>>Please enter the account you want to send to:\n\n");
	printf("\n\n\t\t\t___\b\b\b");
	Account TT;
	scanf("%s", &TT.account_number);
	if (findAccount3(TT))
	{
		system("cls");
		printf("\n��Send Beans��\t\t\t\t\t\t\t\t\t\t%s", tmp1);
	 
		printf("\n\n\n\t��Reminder��1. No more than 10000 yuan can be sent at a time.\n");
		printf("\n\n\t\t2.Beware of scams.");
		printf("\n\n\t\t>>Please enter the amount of money you want to send:\n");
		scanf("%d", &a);
		if (a > 10000)
		{
			printf("\n\tSingle delivery of beans must not exceed 10000\n\t\t\n\n");
			E_Transfer_Money();
		}
		CE_Time();
		TA.Money = a * -1.00;
		if (curAccount->balance + TA.Money < 0)
		{
			int k = 0, b;
			system("cls");
			printf("\n��Send Beans��\t\t\t\t\t\t\t\t\t\t%s", tmp1);
		 
			printf("\nNot enough money!\n");
			while (k < 3)
			{
				printf("\n\n\n\t\t��1�� Re-enter the amount of money");
				printf("\n\n\n\t\t��2�� Return to home page");
				printf("\n\n\n\t\t��0�� Exit the system\n");
				printf("\n\n\t\t\tYour chioce��___\b\b\b");
				scanf("%d", &b);
				switch (b)
				{
				case 1:
					system("cls");
					E_Transfer_Money();
					k = 3;
					break;
				case 2:
					system("cls");
					E_Main_Menu();
					k = 3;
					break;
				case 0:
					k = 3;
					CE_Save_User_Data();
					exit(0);
				default:
					k++;
					break;
				}
			}
		}
		else
		{
			system("cls");
			printf("\n��Send money��\t\t\t\t\t\t\t\t\t\t%s", tmp1);
		 
			printf("\nSuccessful delivery of money!\n");
			curAccount->balance = curAccount->balance + TA.Money;//��ǰ�˻���ȥת�˽��
			curAccountO->balance = curAccountO->balance - TA.Money;//�Է��˻�����ת�˽��
			CE_Transfer_Transaction();
			CE_Save_User_Data();
			int k = 0, b;
			while (k < 3)
			{
				printf("\n\n\n\t\t[1] Transfer money again");
				printf("\n\n\n\t\t[2] Return to the home page");
				printf("\n\n\n\t\t[0] Exit the system\n");
				printf("\n\n\t\t\tYour chioce��___\b\b\b");
				scanf("%d", &b);
				switch (b)
				{
				case 1:
					system("cls");
					E_Transfer_Money();
					k = 3;
					break;
				case 2:
					system("cls");
					E_Main_Menu();
					k = 3;
					break;
				case 0:
					k = 3;
					CE_Save_User_Data();
					exit(0);
				default:
					k++;
					break;
				}
			}
		}
	}
	else
	{
		int b, k = 0;
		system("cls");
		printf("\n��Send money��\t\t\t\t\t\t\t\t\t\t%s", tmp1);
	 
		printf("\nThe account of the other party does not exist!!!!");
		while (k < 3)
		{
			printf("\n\n\n\t\t��1�� Re-enter the other party's account number");
			printf("\n\n\n\t\t��2�� Return to home page");
			printf("\n\n\n\t\t��0�� Exit the system\n\n");
			printf("\n\n\t\t\tYour chioce��___\b\b\b");
			scanf("%d", &b);
			switch (b)
			{
			case 1:
				system("cls");
				E_Transfer_Money();
				k = 3;
				break;
			case 2:
				system("cls");
				E_Main_Menu();
				k = 3;
				break;
			case 0:
				k = 3;
				CE_Save_User_Data();
				exit(0);
			default:
				k++;
				break;
			}
		}
	}
}

//��ѯҵ��ҳ
void C_Enquiry()
{

	int a, k = 0;
	while (k < 3)
	{
		printf("\n����ѯ��\t\t\t\t\t\t\t\t\t\t%s", tmp1);
	 
		printf("\n\n\t\t��1���˻�����ѯ\n");
		printf("\n\n\t\t��2��������Ϣ��ѯ\n");
		printf("\n\n\t\t��3�����׼�¼��ѯ\n");
		printf("\n\n\t\t��4��������ҳ\n");
		printf("\n\n\t\t��0���˳�ϵͳ\n");
		printf("\n\n\t\t\t���ѡ��___\b\b\b");
		scanf("%d", &a);
		switch (a)
		{
		case 1:
			system("cls");
			C_Enquiry_balance();
			k = 3;
			break;
		case 2:
			system("cls");
			C_Enquiry_Information();
			k = 3;
			break;
		case 3:
			system("cls");
			C_Enquiry_Record();
			k = 3;
			break;
		case 4:
			system("cls");
			C_Main_Menu();
			k = 3;
			break;
		case 0:
			system("cls");
			k = 3;
			CE_Save_User_Data();
			exit(0);
		default:
			k++;
			break;
		}
	}
}

//��ѯҵ��ҳ
void E_Enquiry()
{

	int a, k = 0;
	while (k < 3)
	{
		printf("\n��Inquire��\t\t\t\t\t\t\t\t\t\t%s", tmp1);
	 
		printf("\n\n\t\t��1��Account balance inquiry\n");
		printf("\n\n\t\t��2��Personal information query\n");
		printf("\n\n\t\t��3��Transaction record query\n");
		printf("\n\n\t\t��4��Return to homepage\n");
		printf("\n\n\t\t��0��Exit the system\n");
		printf("\n\n\t\t\tYour choice��___\b\b\b");
		scanf("%d", &a);
		switch (a)
		{
		case 1:
			system("cls");
			E_Enquiry_balance();
			k = 3;
			break;
		case 2:
			system("cls");
			E_Enquiry_Information();
			k = 3;
			break;
		case 3:
			system("cls");
			E_Enquiry_Record();
			k = 3;
			break;
		case 4:
			system("cls");
			E_Main_Menu();
			k = 3;
			break;
		case 0:
			system("cls");
			k = 3;
			CE_Save_User_Data();
			exit(0);
		default:
			k++;
			break;
		}
	}
}

//�˻�����ѯ
void C_Enquiry_balance()
{
	printf("\n���˻�����ѯ��\t\t\t\t\t\t\t\t\t\t%s", tmp1);
 
	CE_Time();
	printf("\n\t�������Ϊ��\n\t\t%.2f\n", curAccount->balance);
	printf("\n");
	int a, k = 0;
	while (k < 3)
	{
		printf("\n\n\t\t��1��������һҳ\n");
		printf("\n\n\t\t��2��������ҳ\n");
		printf("\n\n\t\t��0���˳�ϵͳ\n");
		printf("\n\n\t\t\t���ѡ��___\b\b\b");
		scanf("%d", &a);
		switch (a)
		{
		case 1:
			system("cls");
			C_Enquiry();
			k = 3;
			break;
		case 2:
			system("cls");
			C_Main_Menu();
			k = 3;
			break;
		case 0:
			k = 3;
			CE_Save_User_Data();
			exit(0);
		default:
			k++;
			break;
		}
	}
}

//�˻�����ѯ
void E_Enquiry_balance()
{
	printf("\n��Account balance query��\t\t\t\t\t\t\t\t\t\t%s", tmp1);
 
	CE_Time();
	printf("\n\tYour money also include:\n\t\t%.2f\n", curAccount->balance);
	printf("\n");
	int a, k = 0;
	while (k < 3)
	{
		printf("\n\n\t\t��1��Return to the previous page\n");
		printf("\n\n\t\t��2��Return to homepage\n");
		printf("\n\n\t\t��0��Exit the system\n");
		printf("\n\n\t\t\tYour choice��___\b\b\b");
		scanf("%d", &a);
		switch (a)
		{
		case 1:
			system("cls");
			E_Enquiry();
			k = 3;
			break;
		case 2:
			system("cls");
			E_Main_Menu();
			k = 3;
			break;
		case 0:
			k = 3;
			CE_Save_User_Data();
			exit(0);
		default:
			k++;
			break;
		}
	}
}

//������Ϣ��ѯ
void C_Enquiry_Information()
{
	printf("\n��������Ϣ��ѯ��\t\t\t\t\t\t\t\t\t\t%s", tmp1);
 
	printf("\n\t������\n\t\t%s\n", curAccount->name);
	printf("\n\t�˺ţ�\n\t\t%s\n", curAccount->account_number);
	printf("\n\tԤ���ֻ��ţ�\n\t\t%s\n\n", curAccount->phone_number);
	int a, k = 0;
	while (k < 3)
	{
		printf("\n\n\t\t\t��1��������һҳ\n");
		printf("\n\n\t\t\t��2��������ҳ\n");
		printf("\n\n\t\t\t��0���˳�ϵͳ\n");
		printf("\n\n\t\t\t���ѡ��___\b\b\b");
		scanf("%d", &a);
		switch (a)
		{
		case 1:
			system("cls");
			C_Enquiry();
			k = 3;
			break;
		case 2:
			system("cls");
			C_Main_Menu();
			k = 3;
			break;
		case 0:
			k = 3;
			CE_Save_User_Data();
			exit(0);
		default:
			k++;
			break;
		}
	}
}

//������Ϣ��ѯ
void E_Enquiry_Information()
{
	printf("\n��Personal information inquiry��\t\t\t\t\t\t\t\t\t\t%s", tmp1);
 
	printf("\n\tName��\n\t\t%s\n", curAccount->name);
	printf("\n\tAccount number��\n\t\t%s\n", curAccount->account_number);
	printf("\n\tReserved phone number��\n\t\t%s\n\n", curAccount->phone_number);
	int a, k = 0;
	while (k < 3)
	{
		printf("\n\n\t\t\t��1��Return to the previous page\n");
		printf("\n\n\t\t\t��2��Return to homepage\n");
		printf("\n\n\t\t\t��0��Exit the system\n");
		printf("\n\n\t\t\tYour chioce��___\b\b\b");
		scanf("%d", &a);
		switch (a)
		{
		case 1:
			system("cls");
			E_Enquiry();
			k = 3;
			break;
		case 2:
			system("cls");
			E_Main_Menu();
			k = 3;
			break;
		case 0:
			k = 3;
			CE_Save_User_Data();
			exit(0);
		default:
			k++;
			break;
		}
	}
}

//���׼�¼��ѯ
void C_Enquiry_Record()
{
	printf("\n�����׼�¼��ѯ��\t\t\t\t\t\t\t\t\t\t%s", tmp1);
 
	CE_Print_Transaction();
	int a, k = 0;
	while (k < 3)
	{
		printf("\n\n\t\t��1��������һҳ\n");
		printf("\n\n\t\t��2��������ҳ\n");
		printf("\n\n\t\t��0���˳�ϵͳ\n");
		printf("\n\n\t\t\t���ѡ��___\b\b\b");
		scanf("%d", &a);
		switch (a)
		{
		case 1:
			system("cls");
			C_Enquiry();
			k = 3;
			break;
		case 2:
			system("cls");
			C_Main_Menu();
			k = 3;
			break;
		case 0:
			k = 3;
			CE_Save_User_Data();
			exit(0);
		default:
			k++;
			break;
		}
	}
}

//���׼�¼��ѯ
void E_Enquiry_Record()
{
	printf("\n��Transaction record query��\t\t\t\t\t\t\t\t\t\t%s", tmp1);
 
	CE_Print_Transaction();
	int a, k = 0;
	while (k < 3)
	{
		printf("\n\n\t\t��1��Return to the previous page\n");
		printf("\n\n\t\t��2��Return to homepage\n");
		printf("\n\n\t\t��0��Exit the system\n");
		printf("\n\n\t\t\tYour choice��___\b\b\b");
		scanf("%d", &a);
		switch (a)
		{
		case 1:
			system("cls");
			C_Enquiry();
			k = 3;
			break;
		case 2:
			system("cls");
			C_Main_Menu();
			k = 3;
			break;
		case 0:
			k = 3;
			CE_Save_User_Data();
			exit(0);
		default:
			k++;
			break;
		}
	}
}

//�޸���Ϣѡ��ҳ
void C_Change_Information()
{
	system("cls");
	int a, k2 = 1;
	while (k2)
	{
		printf("\n���޸ĸ������ϡ�\t\t\t\t\t\t\t\t\t\t%s", tmp1);
	 
		printf("\n\n\t\t��1���޸��û�����\n");
		printf("\n\n\t\t��2���޸��˻�����\n");
		printf("\n\n\t\t��3���޸���ϵ�绰\n");
		printf("\n\n\t\t��4���޸��˻�����\n");
		printf("\n\n\t\t��9��������һҳ\n");
		printf("\n\n\t\t��0���˳�ϵͳ\n");
		printf("\n\n\t\t\t���ѡ��___\b\b\b");
		scanf("%d", &a);

		switch (a)
		{
		case 1:
			C_Change_User();
			k2 = 0;
			break;
		case 2:
			C_Change_AccountNum();
			k2 = 0;
			break;
		case 3:
			C_Change_phone();
			k2 = 0;
			break;
		case 4:
			C_Change_Password();
			k2 = 0;
			break;
		case 9:
			C_Main_Menu();
			k2 = 0;
			break;
		case 0:
			CE_Save_User_Data();
			exit(0);
		default:
			system("cls");
			printf("�������\t�밴����ʾ�������룺\n");
			break;
		}
	}
}

//�޸���Ϣѡ��ҳ
void E_Change_Information()
{
	system("cls");
	int a, k2 = 1;
	while (k2)
	{

		printf("\n��Modify personal information��\t\t\t\t\t\t\t\t\t\t%s", tmp1);
	 
		printf("\n\n\t\t��1��Modify user name\n");
		printf("\n\n\t\t��2��Modify account number\n");
		printf("\n\n\t\t��3��Modify contact number\n");
		printf("\n\n\t\t��4��Change account password\n");
		printf("\n\n\t\t��9��Go back to the last page\n");
		printf("\n\n\t\t��0��Exit system\n");
		printf("\n\n\t\t\tYour chioce��___\b\b\b");
		scanf("%d", &a);

		switch (a)
		{
		case 1:
			E_Change_User();
			k2 = 0;
			break;
		case 2:
			E_Change_AccountNum();
			k2 = 0;
			break;
		case 3:
			E_Change_phone();
			k2 = 0;
			break;
		case 4:
			E_Change_Password();
			k2 = 0;
			break;
		case 9:
			E_Main_Menu();
			k2 = 0;
			break;
		case 0:
			CE_Save_User_Data();
			exit(0);
		default:
			system("cls");
			printf("input error! \tPlease re-enter as prompted:\n");
			break;
		}
	}
}

//�޸��û�
void C_Change_User()
{
	int a, k = 0;
	char Password[100];
	while (k < 3)
	{
		printf("\n���޸��û����ơ�\t\t\t\t\t\t\t\t\t\t%s", tmp1);
	 
		printf("\n\n\t>>���������룺\n");
		char storePassword[10] = { '\0' };    //�洢�û����������
		printf("\n\n\t\t\t______\b\b\b\b\b\b");
		getPassword(storePassword, 10);
		strcpy(Password, storePassword);
		system("cls");
		printf("\n���޸��û����ơ�\t\t\t\t\t\t\t\t\t\t%s", tmp1);
	 
		if (strcmp(Password, curAccount->password) == 0)
		{
			printf("\n\n\t>>���������û�����:\n");
			printf("\n\n\t___\b\b\b\n");
			scanf("%s", curAccount->name);
			printf("\n���޸��û����ơ�\t\t\t\t\t\t\t\t\t\t%s", tmp1);
		 
			printf("\n\n\t�û������޸ĳɹ���\n");
			CE_Save_User_Data();
			k = 3;

			int k2 = 0;
			while (k2 < 3)
			{
				printf("\n\n\t\t��1��������һҳ\n");
				printf("\n\n\t\t��2��������ҳ\n");
				printf("\n\n\t\t��0���˳�ϵͳ\n");
				printf("\n\n\t\t\t����ѡ��___\b\b\b");
				scanf("%d", &a);
				switch (a)
				{
				case 1:
					system("cls");
					C_Change_Information();
					k = 3;
					break;
				case 2:
					system("cls");
					C_Main_Menu();
					k = 3;
					break;
				case 0:
					k = 3;
					CE_Save_User_Data();
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
			printf("�����������! \t%d\t�밴����ʾ�������룺\n", 3 - k);
		}
	}
}

//�޸��û�
void E_Change_User()
{
	int a, k = 0;
	char Password[100];
	while (k < 3)
	{
		printf("\n��Modify user name��\t\t\t\t\t\t\t\t\t\t%s", tmp1);
	 
		printf("\n\n\t>>Please enter password:\n");
		char storePassword[10] = { '\0' };    //�洢�û����������
		printf("\n\n\t\t\t______\b\b\b\b\b\b");
		getPassword(storePassword, 10);
		strcpy(Password, storePassword);
		system("cls");
		printf("\n��Modify user name��\t\t\t\t\t\t\t\t\t\t%s", tmp1);
	 
		if (strcmp(Password, curAccount->password) == 0)
		{
			printf("\n\n\t>>Please enter a new user name:\n");
			scanf("%s", curAccount->name);
			printf("\n��Modify user name��\t\t\t\t\t\t\t\t\t\t%s", tmp1);
		 
			printf("\n\n\tUser name modified successfully!\n");
			CE_Save_User_Data();
			k = 3;

			int k2 = 0;
			while (k2 < 3)
			{
				printf("\n\n\t\t��1��Return to the previous page\n");
				printf("\n\n\t\t��2��Return to homepage\n");
				printf("\n\n\t\t��0��Exit the system\n");
				printf("\n\n\t\t\tYour chioce��___\b\b\b");
				scanf("%d", &a);
				switch (a)
				{
				case 1:
					system("cls");
					E_Change_Information();
					k = 3;
					break;
				case 2:
					system("cls");
					E_Main_Menu();
					k = 3;
					break;
				case 0:
					k = 3;
					CE_Save_User_Data();
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
			printf("Wrong password entered! \t%d\tPlease re-enter as prompted:\n", 3 - k);
		}
	}
}

//�޸��˻�
void C_Change_AccountNum()
{
	system("cls");
	int a, k = 0;
	char Password[100];
	while (k < 3)
	{
		printf("\n���޸��˻����롿\t\t\t\t\t\t\t\t\t\t%s", tmp1);
	 
		printf("\n\n\n\t>>���������룺\n");
		char storePassword[10] = { '\0' };    //�洢�û����������
		printf("\n\n\t\t\t______\b\b\b\b\b\b");
		getPassword(storePassword, 10);
		strcpy(Password, storePassword);
		system("cls");
		printf("\n���޸��˻����롿\t\t\t\t\t\t\t\t\t\t%s", tmp1);
	 
		if (strcmp(Password, curAccount->password) == 0)
		{
			printf("\n\n\t>>���������˻�����:\n");
			scanf("%s", curAccount->account_number);
			system("cls");
			printf("\n���޸��˻����롿\t\t\t\t\t\t\t\t\t\t%s", tmp1);
		 
			printf("\n\n\t�˻������޸ĳɹ���\n");
			CE_Save_User_Data();
			k = 3;

			int k2 = 0;
			while (k2 < 3)
			{
				printf("\n\n\t\t��1��������һҳ\n");
				printf("\n\n\t\t��2��������ҳ\n");
				printf("\n\n\t\t��0���˳�ϵͳ\n");
				printf("\n\n\t\t\t����ѡ��___\b\b\b");
				scanf("%d", &a);
				switch (a)
				{
				case 1:
					system("cls");
					C_Change_Information();
					k2 = 3;
					break;
				case 2:
					system("cls");
					C_Main_Menu();
					k2 = 3;
					break;
				case 0:
					k2 = 3;
					CE_Save_User_Data();
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
			printf("�����������! \t%d\t�밴����ʾ�������룺\n", 3 - k);
		}
	}
}

//�޸��˻�
void E_Change_AccountNum()
{
	system("cls");
	int a, k = 0;
	char Password[100];
	while (k < 3)
	{
		printf("\n��Modify account number��\t\t\t\t\t\t\t\t\t\t%s", tmp1);
	 
		printf("\n\n\n\t>>Please enter password:\n");
		char storePassword[10] = { '\0' };    //�洢�û����������
		printf("\n\n\t\t\t______\b\b\b\b\b\b");
		getPassword(storePassword, 10);
		strcpy(Password, storePassword);
		system("cls");
		printf("\n��Modify account number��\t\t\t\t\t\t\t\t\t\t%s", tmp1);
	 
		if (strcmp(Password, curAccount->password) == 0)
		{
			printf("\n\n\t>>Please enter new account number:\n");
			scanf("%s", curAccount->account_number);
			system("cls");
			printf("\n��Modify account number��\t\t\t\t\t\t\t\t\t\t%s", tmp1);
		 
			printf("\n\n\tThe account number has been modified successfully!\n");
			CE_Save_User_Data();
			k = 3;

			int k2 = 0;
			while (k2 < 3)
			{
				printf("\n\n\t\t��1��Return to the previous page\n");
				printf("\n\n\t\t��2��Return to homepage\n");
				printf("\n\n\t\t��0��Exit the system\n");
				printf("\n\n\t\t\tYour choice��___\b\b\b");
				scanf("%d", &a);
				switch (a)
				{
				case 1:
					system("cls");
					E_Change_Information();
					k2 = 3;
					break;
				case 2:
					system("cls");
					E_Main_Menu();
					k2 = 3;
					break;
				case 0:
					k2 = 3;
					CE_Save_User_Data();
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
			printf("Wrong password entered! \t%d\tPlease re-enter as prompted:\n", 3 - k);
		}
	}
}

//�޸���ϵ�绰
void C_Change_phone()
{
	system("cls");
	int a, k = 0;
	char Password[100];
	while (k < 3)
	{
		printf("\n���޸���ϵ�绰��\t\t\t\t\t\t\t\t\t\t%s", tmp1);
	 
		printf("\n\n\t>>���������룺\n");
		char storePassword[10] = { '\0' };    //�洢�û����������
		printf("\n\n\t\t\t______\b\b\b\b\b\b");
		getPassword(storePassword, 10);
		strcpy(Password, storePassword);
		system("cls");
		printf("\n���޸���ϵ�绰��\t\t\t\t\t\t\t\t\t\t%s", tmp1);
	 
		if (strcmp(Password, curAccount->password) == 0)
		{
			printf("\n\n\t>>����������ϵ�绰����:\n");
			scanf("%s", curAccount->phone_number);
			system("cls");
			printf("\n���޸���ϵ�绰��\t\t\t\t\t\t\t\t\t\t%s", tmp1);
		 
			printf("\n\n\t��ϵ�绰�޸ĳɹ���\n");
			CE_Save_User_Data();
			k = 3;

			int k2 = 0;
			while (k2 < 3)
			{
				printf("\n\n\t\t��1��������һҳ\n");
				printf("\n\n\t\t��2��������ҳ\n");
				printf("\n\n\t\t��0���˳�ϵͳ\n");
				printf("\n\n\t\t\t����ѡ��___\b\b\b");
				scanf("%d", &a);
				switch (a)
				{
				case 1:
					system("cls");
					C_Change_Information();
					k2 = 3;
					break;
				case 2:
					system("cls");
					C_Main_Menu();
					k2 = 3;
					break;
				case 0:
					k2 = 3;
					CE_Save_User_Data();
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
			printf("�����������! \t%d\t�밴����ʾ�������룺\n", 3 - k);
		}
	}
}

//�޸���ϵ�绰
void E_Change_phone()
{
	system("cls");
	int a, k = 0;
	char Password[100];
	while (k < 3)
	{
		printf("\n[Modify contact number]\t\t\t\t\t\t\t\t\t\t%s", tmp1);
	 
		printf("\n\n\n\t>>Please enter your password:\n");
		char storePassword[10] = { '\0' };    //�洢�û����������
		printf("\n\n\t\t\t______\b\b\b\b\b\b");
		getPassword(storePassword, 10);
		strcpy(Password, storePassword);
		system("cls");
		printf("\n[Modify contact number]\t\t\t\t\t\t\t\t\t\t%s", tmp1);
	 
		if (strcmp(Password, curAccount->password) == 0)
		{
			printf("\n\n\t>>Please enter a new contact phone number:\n");
			scanf("%s", curAccount->phone_number);
			system("cls");
			printf("\n[Modify contact number]\t\t\t\t\t\t\t\t\t\t%s", tmp1);
		 
			printf("\n\n\tContact phone number modified successfully!\n");
			CE_Save_User_Data();
			k = 3;

			int k2 = 0;
			while (k2 < 3)
			{
				printf("\n\n\t\t��1��Go back to the last page\n");
				printf("\n\n\t\t��2��Return to home page\n");
				printf("\n\n\t\t��0��Exit system\n");
				printf("\n\n\t\t\tYour choice��___\b\b\b");
				scanf("%d", &a);
				switch (a)
				{
				case 1:
					system("cls");
					E_Change_Information();
					k2 = 3;
					break;
				case 2:
					system("cls");
					E_Main_Menu();
					k2 = 3;
					break;
				case 0:
					k2 = 3;
					CE_Save_User_Data();
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
			printf("\n\n\tPassword entered incorrectly! \t%d\tPlease re-enter as prompted:\n", 3 - k);
		}
	}
}

//�޸�����
void C_Change_Password()
{
	system("cls");
	int a, k = 0;
	char Password[100];
	while (k < 3)
	{
		printf("\n���޸��˻����롿\t\t\t\t\t\t\t\t\t\t%s", tmp1);
	 
		printf("\n\n\n\t>>������ԭʼ���룺\n");
		char storePassword[10] = { '\0' };    //�洢�û����������
		printf("\n\n\t\t\t______\b\b\b\b\b\b");
		getPassword(storePassword, 10);
		strcpy(Password, storePassword);
		system("cls");
		printf("\n���޸��˻����롿\t\t\t\t\t\t\t\t\t\t%s", tmp1);
	 
		if (strcmp(Password, curAccount->password) == 0)
		{
			printf("\n\n\t>>������������:\n");
			printf("\n\n\t\t\t______\b\b\b\b\b\b");
			getPassword(storePassword, 10);
			strcpy(curAccount->password, storePassword);
			system("cls");
			printf("\n���޸��˻����롿\t\t\t\t\t\t\t\t\t\t%s", tmp1);
		 
			CE_Save_User_Data();
			k = 3;

			int k2 = 0;
			while (k2 < 3)
			{
				printf("\n\n\t\t��1��������һҳ\n");
				printf("\n\n\t\t��2��������ҳ\n");
				printf("\n\n\t\t��0���˳�ϵͳ\n");
				printf("\n\n\t\t\t����ѡ��___\b\b\b");
				scanf("%d", &a);
				switch (a)
				{
				case 1:
					system("cls");
					C_Change_Information();
					k2 = 3;
					break;
				case 2:
					system("cls");
					C_Main_Menu();
					k2 = 3;
					break;
				case 0:
					k2 = 3;
					CE_Save_User_Data();
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
			printf("\n\n\t�����������! \t%d\t�밴����ʾ�������룺\n", 3 - k);
		}
	}
}

//�޸�����
void E_Change_Password()
{
	system("cls");
	int a, k = 0;
	char Password[100];
	while (k < 3)
	{
		printf("\n��Change account password��\t\t\t\t\t\t\t\t\t\t%s", tmp1);
		printf("\n\n\n\t>>Please enter your password:\n");
		char storePassword[10] = { '\0' };    //�洢�û����������
		printf("\n\n\t\t\t______\b\b\b\b\b\b");
		getPassword(storePassword, 10);
		strcpy(Password, storePassword);
		system("cls");
		printf("\n��Change account password��\t\t\t\t\t\t\t\t\t\t%s", tmp1);
		if (strcmp(Password, curAccount->password) == 0)
		{
			printf("\n\n\t>>Please enter a new password:\n");
			printf("\n\n\t\t\t______\b\b\b\b\b\b");
			getPassword(storePassword, 10);
			strcpy(curAccount->password, storePassword);
			system("cls");
			printf("\n��Change account password��\t\t\t\t\t\t\t\t\t\t%s", tmp1);
			
			CE_Save_User_Data();
			k = 3;

			int k2 = 0;
			while (k2 < 3)
			{
				printf("\n\n\t\t��1��Go back to the last page\n");
				printf("\n\n\t\t��2��Return to home page\n");
				printf("\n\n\t\t��0��Exit system\n");
				printf("\n\n\t\t\tYour choice��___\b\b\b");
				scanf("%d", &a);
				switch (a)
				{
				case 1:
					system("cls");
					E_Change_Information();
					k2 = 3;
					break;
				case 2:
					system("cls");
					E_Main_Menu();
					k2 = 3;
					break;
				case 0:
					k2 = 3;
					CE_Save_User_Data();
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
			printf("\n\n\t�����������! \t%d\t�밴����ʾ�������룺\n", 3 - k);
		}
	}
}

//��ʼ����
void start()
{
	printf("\n\t\t\t\t��ӭʹ��ATM\n");

	int k = 1;
	while (k)
	{
		printf("\n\n\t\t��ѡ�����ԣ�\t");
		printf("Please choose language��\n");
		printf("\n\n\t\t\t��1������\n");
		printf("\n\n\t\t\t��2��English\n");
		printf("\n\n\t\t\t��0���˳� Exit\n\n\n\t\t\t");
		printf("\n\n\t\t\t������ѡ��/Your choice��___\b\b\b");
		scanf("%d", &Language);
		switch (Language)
		{
		case 1:
			system("cls");
			printf("\n\n\t\t\t��1���û���¼\n");
			printf("\n\n\t\t\t��2���û�ע��\n");
			printf("\n\n\t\t\t��������������һҳ\n");
			printf("\n\n\t\t\t|����ѡ��___\b\b\b");
			break;
		case 2:
			system("cls");
			printf("\n\n\t\t\t��1��Sign in\n");
			printf("\n\n\t\t\t��2��Sign up\n");
			printf("\n\n\t\t\t��Others��Back to previous page\n");
			printf("\n\n\t\t\tYour choice��___\b\b\b");
			break;
		case 0:
			exit(0);
		default:
			k = 1;
			system("cls");
			printf("\n\n\t\t���������밴����ʾ�ٴ�����!\t\t");
			printf("Error,please follow the prompts to enter again!\n\n");
			break;
		}
		printf("___\b\b\b");
		scanf("%d", &Sin);
		k = 0;
		if (Sin == 1)
		{
			C_Sign_In();//����ע�ắ��
		}
		else if (Sin == 2)
		{
			Sin = 1;
			C_Sign_Up();
		}
		else
			k = 1;
	}
}


int main()
{
	CE_Time();
	CE_Initialize_User_Data();
	CE_Initialize_Transaction_Data();
	start();
	CE_Save_User_Data();
	CE_Save_Transaction_Data();
	return 0;
}

