/*
���α׷���: Learning support Program �뵵: �н��� �־� ������ ��
Ȱ�� ��ȹ: Life support program�� �ｺ�ɾ�� ���ư����� ��.
���α׷� �Ⱓ: 2016-11�� 14��~ 2016-12�� 9��
����: �ƾ�, ����������     7��
����: 2013244007 ��â��
2013244010 ȫ��ȣ
2013244068 ������
2013244111 �̼���
�����: ���� �ҽ� ����Ʈ����  �й�: 12�й�  ��米��: ����� ������
*/

#include<stdio.h> //ǥ�� ����� ���̺귯��
#include<windows.h>
#include<stdlib.h>
#include<time.h>
#include <conio.h>
#include <string.h>
#define UP 72//���� ����Ű
#define DOWN 80//�Ʒ��� ����Ű
//================================================================-changun
#define LEFT 75// ���� ����Ű
#define RIGHT 77//������ ����Ű
#define MAX 100 //Changun �� ��� ����� ���� ���
//================================================================-changun
#define ENTER 13//����Ű
#define ESC 27//ESC Ű
//=====sung ho===========
#define WORDCOUNT 1000
#define SUBJECT 8 //���� ��
//=====sung ho===========

//================================================================== - sungho
typedef struct wordlist {
	char name[100]; //�ܾ�
	char mean[200]; //��
}VOCA;
VOCA a[WORDCOUNT];

typedef struct subject {
	char name[20];//�����̸�
	int day_study;//���� ���νð�
	int week_study[7];//��ȭ��������� ���νð�
}STAT;
STAT b[SUBJECT];
//================================================================ - sungho

//================================================================-sungjae
typedef struct user {//����� �Է� �ð� ����ü
	int hour;//��
	int min;//��
	int sec;//��
}USER;
typedef struct plan {
	char pi1[50], pi2[50], pi3[50], pi4[50], pi5[50], pi6[50], pi7[50], pi8[50], pi9[50], pi10[50], pi11[50], pi12[50], pi13[50], pi14[50], pi15[50], pi16[50];
	//pi1~16�迭�� 1�������� 16���������� ��ȹ���� ����
	char c1[10], c2[10], c3[10], c4[10], c5[10], c6[10], c7[10], c8[10], c9[10], c10[10], c11[10], c12[10], c13[10], c14[10], c15[10], c16[10];
	//�޼� üũ�� ���
}PLAN;//PLAN����ü�� ��ȹ ���ڿ� �����ϱ� ���ؼ� ���
typedef struct tt {
	char st1[50], st2[50], st3[50], st4[50], st5[50], st6[50], st7[50], st8[50];
	//1~10���ñ����� �����̸��� �Է¹ޱ� ���� �迭
}TT;
//================================================================-sungjae


//�Լ� �ִ���
//===============================================================-main
void main_menu();
int menu_switch();
//===============================================================-main
//===================================================-changun
void Calculator_Menu(); //���� ���� �޴�
void Matrix_Menu(); //��� ��� �޴�
int calculator_key();// ���� �޴����� =>�� ���� �Լ�
void Matrix_add(); //��� ����
int Matrix_key();  // ��� ��ǥ ��
void Matrix_mul(); // ��� ����
void stop_watch(); //�����ġ
void stopwatch_menu(); //���� ��ġ �޴�
void main_Calculator(); //���� ���� �޴�
int calculator_switch();// �Ϲ� ���⿡�� �¿�� ������ �Լ�
int arithmetic_menu();  //�Ϲ� ���� ����
int calculator(); //��Ģ���� ��� �Լ�
int stack_push2(); //������ ���� ���� �Լ�
void stack_pop(int num); //���� �Լ�
int stack_push(); //������ ���� ���� �Լ�
void stack_calculator_Menu(); // �Ϲ� ���� �޴�
int stack_fix[MAX], top = 0; //stack�� Ȱ���ϱ� ���� ��������
void inverse_matrix_Menu();// ����� ���
						   //==================================================-changun
						   //================================================-SungHo
void gotoxy(int x, int y);//��ǥ �Լ�
void menu_scr(void);//�ܾ��� �޴�ȭ���� ����ϴ� �Լ�
void Function(int y);//�ܾ��� �ش� �޴��� �����ϴ� �Լ�
int MenuChoice(void); //�ܾ��� �޴��� ����Ű�� ȭ��ǥ�� �̵���Ű�� �Լ�
void AddWord(void);//�ܾ��� �ܾ��߰� ���
void SearchWord(void);//�ܾ��� �ܾ�˻� ���
void WordListCheck(void);//�ܾ��� ���峻�� Ȯ�α��
void ProgramRead(void);//�ܾ��� ���ϸ���� �Լ�
void Quiz(void);//�ܾ��� �ܾ� ���� ���
void del(void);//�ܾ��� �ܾ���� ���
void Statistics_Menuscr(void);//�н��� ��� �޴�
void Stat_Function(int y);//�н��� ��� �޴� �������̽�
void Stat_ProgramRead(void);//�н��� ��� ���� ���� ���� �Լ�
int Stat_Menuchoice(void);//�н��� ��� �޴� �������̽�
void AddSubject(void);//�н��� ���ǥ ���� �߰�
void DelSubject(void);//�н��� ��� ���� �������
int WhatDay(void);//���� ���� ��� �Լ�
void Measure(void);//�н��� ���� ���
void StudyCheck(void);//�н��� Ȯ�� ���
void WeekStudyReset(int day);//�ְ� �н��� �ʱ�ȭ
int DayReset(void);//���� �н��� �ʱ�ȭ
void Decision(void);//���� �н��� �ʱ�ȭ �������̽� �޴�
void YesorNo(int x);//���� �н��� �ʱ�ȭ �������̽�
					//================================================-SungHo
					//================================================-seokhoon
void calender();
//================================================-seokhoon
//===============================================-sungjae
int learnchoice();//�н���ȹǥ Ű���� ������ �޴�����
int threemenu1();//��ȹ�Է¸޴� Ű���� ������ ����
int threemenu2();//�޼�üũ�޴� Ű���� ������ ����
int threemenu3();//�޼����޴� Ű���� ������ ����
int threemenu4();//�ð�ǥ�޴� Ű���� ������ ����
int alarm();//�˶��Լ�
int timer();//Ÿ�̸��Լ�
int learn_menu();//�н���ȹǥ �޴��Լ�
void learningplanner();//�н���ȹǥ ��ɼ����Լ�
int planinsertmenu();//��ȹ �Է¸޴�
int planinsert();//��ȹ �Է� �Լ�
int achievementcheckmenu();//�޼�üũ�޴�
int achievementcheck();//�޼�üũ�Լ�
int achievementlookmenu();//�޼����޴�
int achievementrate();//�޼��������Լ�
int timetablemenu();//�ð�ǥ �޴� ���
int timetable();//�ð�ǥ �޴������Լ�
int timetablein();//�ð�ǥ �Է� �Լ�
int timetablelook();//�ð�ǥ ���� �Լ�
					//===============================================-sungjae

					//==================================main�޴���
int main()
{
	int main_switch = 0;  //���ι��� ����ġ ���� �ޱ� ���� ���� - ����� �Է� ��
	int main_end = 0;   //���ι��� �����Ű�� ���� ����
	int num = 0; //���θ޴�
	system("mode con: cols=70 lines=30"); //ũ��
	system("title Learing Support Program");  //���� ��ȭ
	system("color 3F");
	while (1)  //���α׷� �ݺ�
	{  //while �߰�ȣ
		system("cls");

		main_menu();        //���α׷� ���� �޴�
		num = menu_switch(); //�޴����� ������ ��ǥ�� �Է� �޾� Ű����� �����̴� �� ó�� ��Ÿ��
		switch (num)
		{
		case 5:                 //===========-sungjae
			system("cls");
			learningplanner();
			break;    //�н� ��ȹǥ =================-sungjae
		case 6:          //�н� ���ǥ =================-sungho
			system("cls");
			Stat_ProgramRead();
			DayReset();
			WeekStudyReset(WhatDay());
			Statistics_Menuscr();
			Stat_Menuchoice();
			break;//�н� ���ǥ =================-sungho
		case 7: // ���� =======================================changun
			system("cls");
			main_Calculator();
			break;// ���� =======================================changun
		case 8:  //�ܾ��� =================-sungho
			system("cls");
			ProgramRead();
			menu_scr();
			MenuChoice();
			break;          //�ܾ��� =================-sungho
		case 9: //Ÿ�̸� =================-sungjae
			system("cls");
			timer();
			break;//Ÿ�̸� =================-sungjae
		case 10:  //�˶� =================-sungjae
			system("cls");
			alarm();
			break;  //�˶� =================-sungjae
		case 11:  // ��ž��ġ =======================================changun
			system("cls");
			stop_watch();
			break;// ��ž��ġ =======================================changun
		case 12:  //�޷� ================-seokhoon
			system("cls");
			calender();//�޷�   ================-seokhoon
		case 13:
			main_end = 100;
			break;
		default:
			printf("�߸� �����̽��ϴ�.\n");
			break;
		}

		if (main_end == 100)    //���Ḧ ���� ���� if���� ����
		{
			system("cls");
			printf("���α׷��� �����մϴ�.\n");
			exit(1);  //Ż�� ��ɾ�
		}//if�� - ���� �߰�ȣ
	} //while �߰�ȣ
	return 0;
}
//=============================================================-main
void main_menu()
{
	system("title Learing Support Program");  //���� ��ȭ
	system("color 3F");
	printf("=====================================================================\n");
	printf("                    Learing Support Program \n");
	printf("=====================================================================\n");
	gotoxy(18, 5);
	printf(" 1. ��  ��  ��  ȹ  ǥ\n");
	gotoxy(18, 6);
	printf(" 2. ��  ��  ��  ��  ǥ\n");
	gotoxy(18, 7);
	printf(" 3. ��  ��  �� \n");
	gotoxy(18, 8);
	printf(" 4. ��  ��  ��\n");
	gotoxy(18, 9);
	printf(" 5. Ÿ  ��  ��\n");
	gotoxy(18, 10);
	printf(" 6. ��   ��\n");
	gotoxy(18, 11);
	printf(" 7. �� �� �� ġ\n");
	gotoxy(18, 12);
	printf(" 8. ��   ��\n");
	gotoxy(18, 13);
	printf(" 9. ��   ��\n");
}
int menu_switch()
{
	int key;//�Է¹��� Ű�� int���� ������ ����
	int x = 16, y = 5;//ȭ��ǥ�� ���� ��ǥ ���� x :x�� ��ǥ  y:y�� ��ǥ

	while (1)
	{
		key = getch();//Ű�� �Է� ������
		if (key == 0xE0 || key == 0)
			key = getch();
		switch (key)
		{
		case UP: //���� ����Ű�� �Է¹�����
			system("cls");
			main_menu(); //�޴�â�� ����
			y -= 1;	   //ȭ��ǥ("=>")�� y��ǥ�� 1ĭ �Ʒ��� ����
			if (y <= 5)  //ȭ��ǥ("=>")�� y��ǥ�� �޴� �������δ� �ö��� �ʵ��� ����
				y = 5;
			gotoxy(x, y);
			printf("=>");//�ٲ� ��ǥ�� ȭ��ǥ ���
			break;

		case DOWN://�Ʒ��� ����Ű�� �Է¹�����
			system("cls");
			main_menu();//�޴�â�� ����
			y += 1;	   //ȭ��ǥ("=>")�� y��ǥ�� 1ĭ ���� �ø�
			if (y >= 13)  //ȭ��ǥ("=>")�� y��ǥ�� �޴� �Ʒ������δ� �������� �ʵ��� ��
				y = 13;
			gotoxy(x, y);
			printf("=>");//�ٲ� ��ǥ�� ȭ��ǥ ���
			break;

		case ESC:
			system("cls");
			system("color 07");
			return 0;

		case ENTER://����Ű�� �Է¹�����
			return y;
		}

	}

}
//=============================================================-main
//===============================-changun
void main_Calculator()   //���� ���� �޴�
{
	int C_M = 0, CM_M = 0, End_C = 0; //End_C:���ι����� ����޴��� �����ϱ� ���� ���� C_M : ���� �޴� CM_M : ��İ�� �޴� AC_M : �Ϲ� ���� �޴�
	while (1)
	{
		Calculator_Menu();  //���� �޴��� ȣ���ϰ� ����� �Է°��� ��������
		C_M = calculator_key();    //��ǥ���� �����ִ� �Լ�
		switch (C_M)
		{
		case 4:
			Matrix_Menu();       //��� ���� �޴� ����
			CM_M = Matrix_key(); //��� ���⿡�� ���� ��ǥ��
			switch (CM_M)   //======��� ���� ����ġ
			{
			case 4:
				Matrix_add();    //��� ���� ���ϱ�
				break;
			case 6:
				system("cls");
				Matrix_mul();    //��� ���� �Լ�
				break;
			case 8:
				inverse_matrix_Menu();      //����� �޴�
				break;
			case 10:
				main(); //�������� ���ư�����
				break;
			default:
				printf("�߸� �����̽��ϴ�.\n");
				break;
			} //==============��� ���� ����ġ
			break;
		case 6:
			system("cls");
			arithmetic_menu(); //�Ϲ� ���� �޴�
			break;
		case 8:
			End_C = 10; //End_c�� 10�� �־��༭ �ݺ��� Ż��
			break;
		default:
			break;
		}//C_M _ switch�� �߰�ȣ
		if (End_C == 10)
			break;//���� while�� ���� �극��ũ
	}//main_switch_num_case 3: while �߰�ȣ
}

void Calculator_Menu()  //���� �޴�
{
	system("title Calculator");  //���� ��ȭ
	system("color 1F");
	system("cls");
	printf("=====================================================================\n");
	printf("                      C a l c u l a t o r \n");
	printf("=====================================================================\n");
	gotoxy(4, 4);
	printf(" 1.��� ����\n\n");
	gotoxy(4, 6);
	printf(" 2.�Ϲ� ����\n\n");
	gotoxy(4, 8);
	printf(" 3.�ǵ��ư���\n\n");
}
int calculator_key()
{
	int key;//�Է¹��� Ű�� int���� ������ ����
	int x = 2, y = 4;//ȭ��ǥ�� ���� ��ǥ ���� x :x�� ��ǥ  y:y�� ��ǥ

	while (1)
	{
		key = getch();//Ű�� �Է� ������
		if (key == 0xE0 || key == 0)
			key = getch();
		switch (key)
		{
		case UP: //���� ����Ű�� �Է¹�����
			system("cls");
			Calculator_Menu(); //�޴�â�� ����
			y -= 2;	   //ȭ��ǥ("=>")�� y��ǥ�� 2ĭ �Ʒ��� ����
			if (y <= 4)  //ȭ��ǥ("=>")�� y��ǥ�� �޴� �������δ� �ö��� �ʵ��� ����
				y = 4;
			gotoxy(x, y);
			printf("=>");//�ٲ� ��ǥ�� ȭ��ǥ ���
			break;

		case DOWN://�Ʒ��� ����Ű�� �Է¹�����
			system("cls");
			Calculator_Menu();//�޴�â�� ����
			y += 2;	   //ȭ��ǥ("=>")�� y��ǥ�� 2ĭ ���� �ø�
			if (y >= 8)  //ȭ��ǥ("=>")�� y��ǥ�� �޴� �Ʒ������δ� �������� �ʵ��� ��
				y = 8;
			gotoxy(x, y);
			printf("=>");//�ٲ� ��ǥ�� ȭ��ǥ ���
			break;

		case ESC:
			system("cls");
			system("color 07");
			return 0;

		case ENTER://����Ű�� �Է¹�����
			return y;
		}

	}
}

void Matrix_Menu()        //��� ���� �޴�
{
	system("title Matrix Calculator");  //���� ��ȭ
	system("cls");
	printf("=====================================================================\n");
	printf("              M a t r i x  C a l c u l a t o r\n");
	printf("=====================================================================\n");
	gotoxy(4, 4);
	printf(" 1.��� ����\n\n");
	gotoxy(4, 6);
	printf(" 2.��� ����\n\n");
	gotoxy(4, 8);
	printf(" 3.����� ���\n\n");
	gotoxy(4, 10);
	printf(" 4.������\n");
}

int Matrix_key()
{
	int key;//�Է¹��� Ű�� int���� ������ ����
	int x = 2, y = 4;//ȭ��ǥ�� ���� ��ǥ ���� x :x�� ��ǥ  y:y�� ��ǥ

	while (1)
	{
		key = getch();//Ű�� �Է� ������
		if (key == 0xE0 || key == 0)
			key = getch();
		switch (key)
		{
		case UP: //���� ����Ű�� �Է¹�����
			system("cls");
			Matrix_Menu(); //�޴�â�� ����
			y -= 2;	   //ȭ��ǥ("=>")�� y��ǥ�� 2ĭ �Ʒ��� ����
			if (y <= 4)  //ȭ��ǥ("=>")�� y��ǥ�� �޴� �������δ� �ö��� �ʵ��� ����
				y = 4;
			gotoxy(x, y);
			printf("=>");//�ٲ� ��ǥ�� ȭ��ǥ ���
			break;

		case DOWN://�Ʒ��� ����Ű�� �Է¹�����
			system("cls");
			Matrix_Menu();//�޴�â�� ����
			y += 2;	   //ȭ��ǥ("=>")�� y��ǥ�� 2ĭ ���� �ø�
			if (y >= 10)  //ȭ��ǥ("=>")�� y��ǥ�� �޴� �Ʒ������δ� �������� �ʵ��� ��
				y = 10;
			gotoxy(x, y);
			printf("=>");//�ٲ� ��ǥ�� ȭ��ǥ ���
			break;

		case ESC:
			system("cls");
			system("color 07");
			return 0;

		case ENTER://����Ű�� �Է¹�����
			return y;
		}

	}
}

void Matrix_add()  //��� ����
{
	int exone[MAX][MAX];
	int extwo[MAX][MAX];
	int exsum[MAX][MAX];
	int matrix_mrow;
	int matrix_mcolumn;
	int i = 0, j = 0;
	system("cls");
	system("title ��� ����");  //���� ��ȭ
	printf("=====================================================================\n");
	printf("                     M a t r i x   A d d \n");
	printf("=====================================================================\n");
	printf("������ ����� ���� ũ�⿩�� �մϴ�.\n");
	printf("\n");
	printf("���� �� ����� ���� ũ�⸦ �Է����ּ���:");
	printf("\n");
	scanf_s("%d", &matrix_mrow);
	printf("���� �� ����� ���� ũ�⸦ �Է����ּ���:");
	printf("\n");
	scanf_s("%d", &matrix_mcolumn);
	system("pause");

	system("cls");
	system("title ù��° ��� �Է�");  //���� ��ȭ
	printf("=====================================================================\n");
	printf("                     F i r s t   M a t r i x\n");
	printf("=====================================================================\n");
	printf("\n");
	printf("ù��° ��� \n");
	printf("\n");
	for (i = 0; i < matrix_mrow; i++)
		for (j = 0; j < matrix_mcolumn; j++)
		{
			printf("��� A[%d][%d]", i, j);
			scanf("%d", &exone[i][j]);
		}//ù��° ��� �Է�
	system("cls");
	system("title �ι�° ��� �Է�");  //���� ��ȭ
	printf("=====================================================================\n");
	printf("                    S e c o n d   M a t r i x \n");
	printf("=====================================================================\n");
	printf("\n");
	printf("�ι�° ��� \n");
	printf("\n");
	for (i = 0; i < matrix_mrow; i++)
		for (j = 0; j < matrix_mcolumn; j++)
		{
			printf("��� B[%d][%d]", i, j);
			scanf("%d", &extwo[i][j]);
		}//�ι�° ��� �Է�
	system("cls");
	system("title ������� ��");  //���� ��ȭ
	printf("=====================================================================\n");
	printf("                    M a t r i x  Add\n");
	printf("=====================================================================\n");
	printf("\n");
	printf("\n");
	printf("ù��° ���\n");
	for (i = 0; i < matrix_mrow; i++)
	{
		printf("\n");
		for (j = 0; j < matrix_mcolumn; j++)
		{
			printf("%d\t", exone[i][j]);
		} //���� ���
	}//���� ���
	printf("\n");
	printf("\n");
	printf("�ι�° ��� \n");
	for (i = 0; i < matrix_mrow; i++)
	{
		printf("\n");
		for (j = 0; j < matrix_mcolumn; j++)
		{
			printf("%d\t", extwo[i][j]);
		} //���� ���
	}//���� ���


	for (i = 0; i < matrix_mrow; i++)
	{
		for (j = 0; j < matrix_mcolumn; j++)
		{
			exsum[i][j] = exone[i][j] + extwo[i][j];
		}//�ι�° ��� �Է�

	}
	printf("\n");
	printf("\n");
	printf("������ ��� \n");
	printf("\n");
	for (i = 0; i < matrix_mrow; i++)
	{
		for (j = 0; j < matrix_mcolumn; j++)
		{
			printf("%d\t", exsum[i][j]);
		} //���� ���
		printf("\n");
	}//���� ���
	system("PAUSE");

}// void Matrix_add() �Լ� ���� �߰�ȣ

void Matrix_mul()  //��� ���� �Լ�
{
	int exone[MAX][MAX];
	int extwo[MAX][MAX];
	int sum[MAX][MAX];
	int matrix_arow, matrix_acolumn;
	int matrix_bcolumn, matrix_brow;
	int i = 0, j = 0, z = 0;
	system("cls");
	system("title ��� ����");
	printf("=====================================================================\n");
	printf("                      MATRIX MULTIPCATION\n");
	printf("=====================================================================\n");
	printf("\n");
	printf("���ϱ⸦ �� A[m][n], B[m][n]�� A[n]�� B[m]�� ���ƾ� �մϴ�\n ");
	printf("\n");
	printf("���� �� ����� A����� ũ�⸦ �Է����ּ��� A[m][n]:");
	printf("\n");
	scanf_s("%d %d", &matrix_arow, &matrix_acolumn);

	printf("���� �� ����� B����� ũ�⸦ �Է����ּ���:");
	printf("\n");
	scanf_s("%d %d", &matrix_brow, &matrix_bcolumn);
	if (matrix_acolumn != matrix_brow)
	{
		system("cls");
		system("title Error");
		printf("=====================================================================\n");
		printf("                      MATRIX MULTIPCATION\n");
		printf("=====================================================================\n");
		printf("���ϱⰡ �Ұ����� ��� �Դϴ�.\n");
		return;
	}
	system("cls");
	system("title Amatrix");
	printf("=====================================================================\n");
	printf("                         A MATRIX\n");
	printf("=====================================================================\n");
	printf("\n");
	printf("ù��° ��� \n");
	for (i = 0; i < matrix_arow; i++)
		for (j = 0; j < matrix_acolumn; j++)
		{
			printf("exone[%d][%d]", i, j);
			scanf("%d", &exone[i][j]);
		}//ù��° ��� �Է�
	system("cls");
	system("title Bmatrix");
	printf("=====================================================================\n");
	printf("                         B MATRIX\n");
	printf("=====================================================================\n");
	printf("\n");
	printf("�ι�° ��� \n");
	for (i = 0; i < matrix_brow; i++)
		for (j = 0; j < matrix_bcolumn; j++)
		{
			printf("extwo[%d][%d]", i, j);
			scanf("%d", &extwo[i][j]);
		}//�ι�° ��� �Է�
	printf("\n");
	//���� ���� ����
	for (i = 0; i < matrix_arow; i++)
	{
		for (j = 0; j < matrix_bcolumn; j++)
		{
			sum[i][j] = 0;
			for (z = 0; z < matrix_brow; z++)
			{
				sum[i][j] = sum[i][j] + exone[i][z] * extwo[z][j];
			}
		}//������ ��� ���
	}//���� �ʿ��� for��

	system("cls");
	system("title MATRIX MULTIPCATION");
	printf("=====================================================================\n");
	printf("                         MATRIX MULTIPCATION\n");
	printf("=====================================================================\n");
	printf("\n");
	printf("ù��° ���\n");
	for (i = 0; i < matrix_arow; i++)
	{
		printf("\n");
		for (j = 0; j < matrix_acolumn; j++)
			printf("%d \t", exone[i][j]);
	} //ù��° ��� �߰�ȣ

	printf("\n");
	printf("�ι�° ���\n");
	for (i = 0; i < matrix_brow; i++)
	{
		printf("\n");
		for (j = 0; j < matrix_bcolumn; j++)
			printf("%d \t", extwo[i][j]);
	} //�ι�° ��� �߰�ȣ

	printf("\n");
	printf("����� ���� ��\n");
	for (i = 0; i < matrix_acolumn; i++)
	{
		printf("\n");
		for (j = 0; j < matrix_brow; j++)
			printf("%d \t", sum[i][j]);
	} //���� ����ϴ� �߰�ȣ
	printf("\n");
	system("PAUSE");
}//��� ���� �Լ� ����
int arithmetic_menu()
{
	int a = 0, num = 0, count = 0, sum = 0;
	system("cls");
	system("title ��Ģ���� ����");
	while (1)
	{
		stack_calculator_Menu();
		a = calculator_switch();
		switch (a)
		{
		case 2:
			calculator();
			break;
		case 17:
			printf("\n");
			for (; top != 0;)
			{
				sum = stack_push();

			}
			printf("%d \n", sum);
			sum = 0;
			printf("\n");
			system("pause");
			break;
		case 32:
			printf("\n");
			for (; top != -1;)
			{
				sum = stack_push2();
				stack_pop(sum);
			}
			printf("%d", sum);
			sum = 0;
			printf("\n");
			system("pause");
			break;
		case 47:
			sum = 0, stack_fix[MAX] = 0, top = 0;
			printf("Ŭ���� �Ǿ����ϴ�.\n");
			break;
		case 62:
			printf("\n");
			return 0;
		default:
			break;
		}
	}
	return 0;
}

void inverse_matrix_Menu()
{
	float matrix[2][2];
	float inverse[2][2];
	float  det = 0;
	int i = 0, j = 0;
	system("cls");
	system("title ����� ���");
	printf("=====================================================================\n");
	printf("                   i n v e r s e m a t r i x \n");
	printf("=====================================================================\n");

	printf("2X2��ĸ� �˴ϴ�. \n");
	printf("\n");
	for (i = 0; i < 2; i++)
	{
		printf("%d�� �Է� \n", i + 1);
		for (j = 0; j < 2; j++)
		{
			printf("��� A[%d][%d]", i, j);
			scanf("%f", &matrix[i][j]);
		}// ����� ��Ҹ� �Է�
	}
	det = matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
	if (det == 0.0)
	{
		printf("������� �������� �ʽ��ϴ�.\n");
		return 1;
	}// det�� ���ϱ�( a*d - b*c)

	 // ����������� ��ġ��ı��ϱ�
	inverse[0][0] = matrix[1][1] / det;
	inverse[0][1] = -matrix[0][1] / det;
	inverse[1][0] = -matrix[1][0] / det;
	inverse[1][1] = matrix[0][0] / det;

	system("cls");
	printf("=====================================================================\n");
	printf("                   i n v e r s e m a t r i x \n");
	printf("=====================================================================\n");
	// ����� ���
	printf("\n");
	printf("==================== �� �� �� ===================\n");
	printf("�Է��� ���:");
	for (i = 0; i < 2; i++)
	{
		printf("\n");
		for (j = 0; j < 2; j++)
		{
			printf("%.2f ", matrix[i][j]);
		}
	}

	printf("\n");
	printf("�� ����� �����\n");
	for (i = 0; i < 2; i++)
	{
		for (j = 0; j < 2; j++)
		{
			printf("%.2f ", inverse[i][j]);
		}
		printf("\n");
	}
	system("pause");
}




void stack_calculator_Menu()
{
	system("cls");
	printf("=====================================================================\n");
	printf("                      C a l c u l a t o r \n");
	printf("=====================================================================\n");
	gotoxy(4, 3);
	printf("��Ģ ����      ��δ��ϱ�      ��� ����      Ŭ �� ��      ������\n");
	printf("\n");
}

void stack_pop(int num)
{
	stack_fix[top] = num;
	top++;
}
int stack_push()
{
	int x = 0, y = 0, sum = 0;
	top--;
	x = stack_fix[top];
	stack_fix[top] = 0;
	top--;
	y = stack_fix[top];
	stack_fix[top] = 0;
	sum = x + y;

	stack_pop(sum);
	return sum;
}
int stack_push2()
{
	int x = 0, y = 0, sum = 0;
	top--;
	x = stack_fix[top];
	stack_fix[top] = 0;
	top--;
	y = stack_fix[top];
	sum = y - x;
	return sum;
}



int calculator_switch()
{
	int key;//�Է¹��� Ű�� int���� ������ ����
	int x = 2, y = 3;//ȭ��ǥ�� ���� ��ǥ ���� x :x�� ��ǥ  y:y�� ��ǥ

	while (1)
	{
		key = getch();//Ű�� �Է� ������
		if (key == 0xE0 || key == 0)
			key = getch();
		switch (key)
		{
		case LEFT: //���� ����Ű�� �Է¹�����
			system("cls");
			stack_calculator_Menu(); //�޴�â�� ����
			x -= 15;	   //ȭ��ǥ("=>")�� x��ǥ�� 15ĭ �������� �̵�
			if (x <= 2)  //ȭ��ǥ("=>")�� x��ǥ�� �޴� �������δ� ����
				x = 2;
			gotoxy(x, y);
			printf("=>");//�ٲ� ��ǥ�� ȭ��ǥ ���
			break;

		case RIGHT://�Ʒ��� ����Ű�� �Է¹�����
			system("cls");
			stack_calculator_Menu();//�޴�â�� ����
			x += 15;	   //ȭ��ǥ("=>")�� x��ǥ�� 15ĭ ���������� �̵�
			if (x >= 62)  //ȭ��ǥ("=>")�� x��ǥ�� �޴� �����ʴ� �Ȱ��� �̵�
				x = 62;
			gotoxy(x, y);
			printf("=>");//�ٲ� ��ǥ�� ȭ��ǥ ���
			break;

		case ESC:
			system("cls");
			system("color 07");
			return 0;

		case ENTER://����Ű�� �Է¹�����
			return x;
		}

	}

}



int calculator()
{
	int a, b, sum = 0;
	char letter;
	while (1)
	{
		printf("\n");
		printf("\n");
		printf("���������� e�� �Է��ϼ���.\n");
		printf("�������Է� : ");
		scanf("\n%c", &letter);
		if (letter == 'e')
			break;
		printf("ù��° �� �Է�:");
		scanf_s("%d", &a);
		printf("�ι�° �� �Է�:");
		scanf_s("%d", &b);

		switch (letter)
		{
		case '+':
			sum = a + b;
			printf("%d + %d = %d \n", a, b, sum);
			stack_pop(sum);
			break;

		case '-':
			sum = a - b;
			printf("%d - %d = %d \n", a, b, sum);
			stack_pop(sum);
			break;

		case '*':
			sum = a*b;
			printf("%d * %d = %d \n", a, b, sum);
			stack_pop(sum);
			break;

		case '/':
			sum = a / b;
			printf("%d / %d = %d \n", a, b, sum);
			stack_pop(sum);
			break;
		case '%':
			sum = a%b;
			printf("%d %% %d = %d \n", a, b, sum);
			stack_pop(sum);
			break;

		default:
			printf("������ �Է� ����! \n");
			break;
		}
	}
	return 0;
}

void stop_watch()  //��ž ��ġ �Լ�
{
	int hour = 0, min = 0, sec = 0, frame = 0;
	char ch;
	FILE *fp;
	fp = fopen("stopwatch.txt", "w");
	system("cls");
	system("title Stop Watch");  //���� ��ȭ
	system("color 5F");
	printf("=====================================================================\n");
	printf("                       S t o p  W a t c h \n");
	printf("=====================================================================\n");
	system("pause");
	stopwatch_menu();
	while (1)
	{
		printf("%2d : %2d : %2d : %2d", hour, min, sec, frame);
		Sleep(10);
		frame++;
		if (frame == 100)
		{
			sec++;
			frame = 0;
		}
		if (sec == 60)
		{
			min++;
			sec = 0;
		}
		if (min == 60)
		{
			hour++;
			min = 0;
		}

		if (kbhit())
		{
			ch = getch();
			switch (ch)
			{
			case 'S': case 's':
				ch = getch();
				break;
			case 'R': case 'r':
				system("cls");
				stopwatch_menu();
				hour = min = sec = frame = 0;
				break;
			case 'Q': case 'q':
				fprintf(fp, "%2d : %2d : %2d : %2d", hour, min, sec, frame);
				printf("\n");
				fclose(fp);
				return;
			case 'W': case 'w':
				printf("\n");
				printf("\t\t ");
				break;
			default:
				break;
			} //Ű����� ���� �Է� ���� ���� ���� switch
		} // if�� Ű����� ���� �����ΰ� �Է� �޾Ҵٸ�
		printf("\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
	}// �ð��� ���� �ݺ��� �߰�ȣ
} // ��ž��ġ ���� �ڵ� �Լ�
void stopwatch_menu()  //��ž ��ġ �޴�
{
	system("cls");
	printf("=====================================================================\n");
	printf("                       S t o p  W a t c h \n");
	printf("=====================================================================\n");
	printf("S:����/���� \nW: ���\nR:����\nQ:������\n");
	printf("�� : �� : �� :0.01��\n");
}



//================================================-changun

//================================================-SungHo
void gotoxy(int x, int y) //��ǥ�Լ� �ܼ�â�� Ŀ���� ��ǥ����
{
	COORD Pos = { x , y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

int MenuChoice(void)
{
	int key;//�Է¹��� Ű�� int���� ������ ����
	int x = 47, y = 11;//ȭ��ǥ�� ���� ��ǥ ���� x :x�� ��ǥ  y:y�� ��ǥ

	while (1)
	{
		key = getch();
		if (key == 0xE0 || key == 0)
			key = getch();
		switch (key)
		{
		case UP: //���� ����Ű�� �Է¹�����
			system("cls");
			menu_scr();//�޴�â�� ����
			y -= 2;	   //ȭ��ǥ("=>")�� y��ǥ�� 2ĭ �Ʒ��� ����
			if (y <= 11)  //ȭ��ǥ("=>")�� y��ǥ�� �޴� �������δ� �ö��� �ʵ��� �ܾ�˻��� ���� ������ 11������ �ö󰡵��� ����
				y = 11;
			gotoxy(x, y);
			printf("=>");//�ٲ� ��ǥ�� ȭ��ǥ ���
			break;

		case DOWN://�Ʒ��� ����Ű�� �Է¹�����
			system("cls");
			menu_scr();//�޴�â�� ����
			y += 2;	   //ȭ��ǥ("=>")�� y��ǥ�� 2ĭ ���� �ø�
			if (y >= 19)  //ȭ��ǥ("=>")�� y��ǥ�� �޴� �Ʒ������δ� �������� �ʵ��� �ܾ������ ���� ������ 17������ ���������� ����
				y = 19;
			gotoxy(x, y);
			printf("=>");//�ٲ� ��ǥ�� ȭ��ǥ ���
			break;

		case ESC:
			system("cls");
			system("mode con: cols=70 lines=30"); //ũ��
			system("title Learing Support Program");  //���� ��ȭ
			system("color 3F");
			return 0;

		case ENTER://����Ű�� �Է¹�����
			Function(y);
		}

	}

}

void menu_scr(void)//�޴� ȭ���� ���
{
	system("title �ܾ���");//�ܼ��� ������ �ٲ���
	system("color EC");//�ܼ�â�� ������ �ؽ�Ʈ�� ���� �ٲ���  (���:�ؽ�Ʈ) E:���C:����
	system("mode con: cols=115 lines=30");
	printf("=======================================");
	gotoxy(50, 11);
	printf("�ߴܾ� �˻�\n");
	gotoxy(50, 13);
	printf("�ߴܾ� �߰�\n");
	gotoxy(50, 15);
	printf("�ߴܾ��� Ȯ��\n");
	gotoxy(50, 17);
	printf("�ߴܾ� ����\n");
	gotoxy(50, 19);
	printf("�ߴܾ� ����\n");
	gotoxy(46, 23);
	printf("�����α׷� ���� [ESC]\n");

}

void Function(int y)
{
	if (y == 11)//�ܾ� �˻� ȭ��ǥ("=>")�� y��ǥ�� �����ͼ� ȭ��ǥ�� ����Ű�� �޴��� ����
	{
		system("cls");
		SearchWord();
	}
	if (y == 13)//�ܾ� �߰� ����
	{
		system("cls");
		AddWord();
	}
	if (y == 15)//�ܾ� Ȯ�� ����
	{
		system("cls");
		WordListCheck();
	}
	if (y == 17)//�ܾ� ���� ����
	{
		system("cls");
		Quiz();
	}
	if (y == 19)//�ܾ� ���� ����
	{
		system("cls");
		del();
	}

}

void AddWord(void)//�ܾ� �߰� ���
{
	int i = 0, key; //i for�� ���࿡ ���� ���� ,key: ENTERŰ�� ESCŰ�� ���� ���� �������
	int count;
	FILE *fp;
	if ((fp = fopen("Voca.txt", "a")) == NULL)
	{
		fprintf(stderr, "���� Voca.txt�� �� �� �����ϴ�\n", "Voca.txt");
	}
	while (1)
	{
		printf("�߰��Ͻ� �ܾ �Է����ּ���\n");
		gets(a[i].name);
		printf("�ܾ��� ���� �Է����ּ���\n");
		gets(a[i].mean);
		i++;
		printf("�ܾ �� �߰��մϱ�? �߰�[ENTER] ����[ESC]\n");//�ܾ �� �� �߰��ϰ� ���� ��� �߰��� ������ Ű�� �Է¹޾� ������� �ǻ縦 ���´�
		key = getch();										    //ENTER�� �� �߰� ESC�� �Է��ϸ� ���� N
		if (key == 0xE0 || key == 0)
			key = getch();
		if (key == 27)//ESCŰ�� �Է��ϸ�
		{
			system("cls");
			break;   //������ ����:[�ܾ� �˻�]����� ����
		}
		else if (key == 13)//ENTERŰ�� �Է��ϸ� �ܼ�â�� �����ϰ� ����� �ٽ� ó�� ������ ���� �߰��� �ܾ �Է¹���
		{
			system("cls");
		}
		else {//ENTER �� ESC�� �ƴ� Ű�� �Է����� ���
			while (1)
			{
				system("cls");
				printf("�߰�[ENTER] �Ǵ� ����[ESC] Ű�� �Է��ϼ���\n"); //ENTER�� ESC�� �Է��Ҷ����� �ȳ� �޼����� ����
				key = getch();
				if (key == 0xE0 || key == 0);
				key = getch();
				if (key == 13)//Enter�� �Է¹����� �� ������ �������� �ܾ ���� �Է¹ް�
				{
					system("cls");
					break;
				}
				else if (key == 27)//ESC�� ������
				{
					system("cls");
					goto label;   //���� ������ ���������� ����� ����ǰԲ� �Ѵ�.
				}
			}

		}

	}
label:
	count = i;
	//goto ������ ���������� ��
	for (i = 0; i<count; i++) {//�߰��� �ܾ�� ���� �ܾ�� ���� ����Ǿ� �ִ� �ؽ�Ʈ ���� �ȿ� ���� �̾���ش�.
		fputs(a[i].name, fp);
		fputc('\n', fp);//fputs �� �ؽ�Ʈ�� �����Ҷ� ���Ͱ��� �ȹޱ⿡ ������ ���� �ٿ���
		fputs(a[i].mean, fp);
		fputc('\n', fp);
	}
	fclose(fp);
	menu_scr();
}

void SearchWord(void)//�ܾ�˻�
{
	int i = 0, count;//count�� �ҷ��� �ܾ��� ������ ������ ����
	int key;//�Է¹��� Ű ���� �����ϱ� ���� ����
	FILE *fp;
	if ((fp = fopen("Voca.txt", "r")) == NULL)//�б���� �ܾ�� ���� ����� ������ ����.
	{
		fprintf(stderr, "���� Voca.txt�� �� �� �����ϴ�\n", "Voca.txt");
	}
	while (!feof(fp))//�ܾ�� ���� �ҷ��´�.
	{
		fgets(a[i].name, 100, fp);
		a[i].name[strlen(a[i].name) - 1] = '\0';//fgets�� Ư����  �ٰԵǴ� ���๮���� ���Ÿ� ���� �� ���ڷ� �����
		fgets(a[i].mean, 100, fp);
		a[i].mean[strlen(a[i].mean) - 1] = '\0';//fgets�� Ư����  �ٰԵǴ� ���๮���� ���Ÿ� ���� �� ���ڷ� �����
		i++;
	}
	fclose(fp);
	count = i - 1;//�ҷ��� �ܾ��� ���� ����
	while (1) {
		int found = 0;//ã�� �ܾ �־����� �������� üũ�ϱ� ���� ���� �ܾ ã�������� 1�� �����ϰ� ã�� �ܾ �־����� ���� 1���ҵǱ� ������ ã�� �ܾ �����ٸ� count�� ���� ������
		char target[100];
		char esc[8] = "����.";
		printf("ã�� �ܾ� �Ǵ� �ܾ��� �ǹ̸� �Է����ּ���.�����Ϸ��� [����.]�Է�\n");
		gets(target);
		if (!strcmp(esc, target)) {//esc�� ����.�� ������ �ξ��µ� ���� "����."�� �Է��Ѵٸ� ����� ����
			system("cls");
			break;
		}
		for (i = 0; i<count; i++)//�ҷ��� �ܾ��� ����ŭ ���� �˻��� �ؼ�
		{
			found++;
			if (!strcmp(a[i].name, target) || !strcmp(a[i].mean, target))//ã������ �Է��� ��[�ܾ ��]�� �������� �ҷ��� �ܾ��߿� �ִٸ�
			{
				system("cls");//�ܼ�â�� �� �� �����
				printf("%s: %s\n", a[i].name, a[i].mean);//ã�� �ܾ�� ���� �������
				found--;//ã�� �ܾ �־��ٴ°� üũ�ϱ� ���� found���� 1����
			}
			if (found == count)//�� ã�Һ����� ã�� �ܾ ��� found���� count���� �������ٸ�
				printf("ã�� �ܾ �����ϴ�\n");
		}
		while (1) {
			printf("�� ã���ðڽ��ϱ�? [ENTER]ã��,[ESC]����\n");
			key = getch();
			if (key == 27)//ESC�� �Է¹޾�����
			{
				system("cls");
				goto label;//���߷��� Ż��
			}
			else if (key == 13)//ENTER�� �Է¹޾�����
			{
				system("cls");
				break;
			}
			else
			{
				printf("[ENTER]ã��,[ESC]����\n");
			}
		}
	}
label://goto ���� ���������� ��
	menu_scr();
}

void WordListCheck(void)//����� �ܾ ���� Ȯ���ϴ� ���
{
	int i = 0;
	int key;//Ű ���� �����ϱ� ���� ����
	int count;//�ҷ��� �ܾ��� ���� ����
	FILE *fp;
	if ((fp = fopen("Voca.txt", "r")) == NULL)//�ܾ�� ���� ���� �Ǿ��ִ� ������ �б���� ����
	{
		fprintf(stderr, "���� Voca.txt�� �� �� �����ϴ�\n", "Voca.txt");
	}
	while (!feof(fp))//���ϳ��� �ܾ�� ���� ���� �о��
	{
		fgets(a[i].name, 100, fp);
		a[i].name[strlen(a[i].name) - 1] = '\0';
		fgets(a[i].mean, 100, fp);
		a[i].mean[strlen(a[i].mean) - 1] = '\0';
		i++;
	}
	fclose(fp);//������ ����
	count = i - 1;//count�� �ҷ��� �ܾ��� ������ ����
	for (i = 0; i<count; i++)//�ҷ��� �ܾ��� ����ŭ �ܾ�� ���� ���� �������
		printf("[ %s : %s ]\n", a[i].name, a[i].mean);
	printf("\n�����Ͻðڽ��ϱ�?ESC�Է�\n");
	while (1) {
		key = getch();//Ű ���� int������ �Է¹���
		if (key == 27)//ESCŰ�� �Է� �޾�����
		{
			system("cls");
			break;//������ �������� �������
		}
	}
	menu_scr();//�޴��� ���ư�
}

void ProgramRead(void)//���α׷� ���� ����� ������ �������ش�.
{
	int i = 0;
	FILE *fp;
	if ((fp = fopen("Voca.txt", "a")) == NULL)//�̾�� ���� ������ �����ش� ���� ������ ���ٸ� ������ �����Ѵ�.
	{
		fprintf(stderr, "Voca.txt ������ �� �� �����ϴ�.\n", "Voca.txt");
		exit(1);
	}
	fclose(fp);//���� ����
}
void Quiz(void) {//���� ���
	int i = 0, count, j = 0, k, good = 0;//count�� �ҷ��� �ܾ��� ���� �����,good�� ������ ������ �����
	int key;//Ű ���� ������ ����
	char input[100];//����ڿ��� �Է¹��� ���ڰ� �����
	FILE *fp;
	if ((fp = fopen("Voca.txt", "r")) == NULL)//�ܾ�� ���� ����Ǿ� �ִ� ������ �б���� ����
	{
		fprintf(stderr, "���� Voca.txt�� �� �� �����ϴ�\n", "Voca.txt");
	}
	while (!feof(fp))//���Ͽ��� �ܾ�� ���� ���� �о�ͼ� ����ü ������ ����
	{
		fgets(a[i].name, 100, fp);
		a[i].name[strlen(a[i].name) - 1] = '\0'; //fgets�� ���๮�ڸ� �����ϱ� ���� �ι��ڷ� ������ذ�
		fgets(a[i].mean, 100, fp);
		a[i].mean[strlen(a[i].mean) - 1] = '\0';
		i++;
	}
	fclose(fp);//������ �ݾ���
	count = i - 1;//count�� �ҷ��� �ܾ��� ������ ����
	printf("�ܾ� ����� �ܾ��� �ȿ� �ִ� �ܾ��� 5���� �ܾ��� ������ �������� ���ɴϴ�\n\n");
	Sleep(2500);//���� ���� �Լ� 2.5��
	printf("�ܾ��� ������ ���� � �ܾ �����ϰ� �ִ��� �ش��ϴ� �ܾ Ű����� �Է����ּ���\n\n");
	Sleep(2500);
	printf("�׷� �����մϴ�.\n");
	Sleep(1500);//1.5��
	for (j = 0; j<5; j++) {//����� 5������ �����߱⿡ 5�� ����
		srand((unsigned)time(NULL));//�õ尪�� ���� ������ ��������
		i = rand() % count;//0���� count[�ҷ��� �ܾ��� ����]������ ���� �������� ������ ������ i�� ����
		system("cls");
		printf("[%s]�� �����ϱ��?:\n", a[i].mean);//i�� �ε��������� �ϴ� �ܾ��� ���� ������ ������ ����� ����ڿ��� ������
		gets(input);//���� �Է¹���
		if (!strcmp(a[i].name, input))//�Է¹��� ��� �ش� �ε����� �ܾ ���ٸ�
		{
			printf("�����Դϴ�\n");
			Sleep(1000);
			good++;
		}
		else//Ʋ�ȴٸ�
		{
			for (k = 2; k>0; k--)//�� ���� ��ȸ�� �� �ֱ� ���� 2������
			{

				printf("Ʋ���̽��ϴ�. �� ������ ������\n");
				printf("���� ��ȸ [%d]��", k - 1);
				gets(input);
				if (!strcmp(a[i].name, input))//������ ��������
				{
					system("cls");
					printf("�����Դϴ�\n");
					good++;
					break;
				}
			}
		}
	}
	printf("5������ ���� ������ %d�� �Դϴ�\n", good);//������ ������ �������
	while (1)
	{
		printf("�ٽ� �Ͻðڽ��ϱ�? ��ENTER �ƴϿ�ESC\n");
		key = getch();//Ű ���� �Է¹���
		if (key == 13)//ENTER
		{
			system("cls");
			Quiz();//�ٽ� QUIZ�Լ� ����
		}
		if (key == 27)//ESCŰ �Է�
		{
			system("cls");
			break;//�ܼ�â�� �ѹ� �����ְ� ����
		}
		else
		{
			system("cls");
			printf("�߸� �����̽��ϴ� �ٽ��ϱ� ENTER �ƴϿ�ESC");
		}
	}
	menu_scr();//�޴��� ����
}
void del(void)//�ܾ� ���� �Լ�
{
	int i = 0, count;//count�� �ҷ��� �ܾ��� ������ �����
	char target[100];//����ڰ� �Է��� ���ڰ� �����
	FILE *fp;
	if ((fp = fopen("Voca.txt", "r")) == NULL)//�б��� �ܾ�� ���� ����Ǿ� �ִ� �ؽ�Ʈ ������ ����
	{
		fprintf(stderr, "���� Voca.txt�� �� �� �����ϴ�\n", "Voca.txt");
	}
	while (!feof(fp))//����� �ܾ�� ���� �о��
	{
		fgets(a[i].name, 100, fp);
		a[i].name[strlen(a[i].name) - 1] = '\0';
		fgets(a[i].mean, 100, fp);
		a[i].mean[strlen(a[i].mean) - 1] = '\0';
		i++;
	}
	fclose(fp);//���� ����
	count = i - 1;//count�� �ҷ��� �ܾ��� ���� �����
	printf("�����Ͻ� �ܾ �Է��ϼ���\n");
	gets(target);//������ �ܾ �Է¹���
	for (i = 0; i<count; i++)//�ҷ��� �ܾ��� ���� ��ŭ �����˻��ؼ�
	{
		if (!strcmp(a[i].name, target))//�Է��� ���� ��ġ�ϴ°��� �ִٸ�
		{
			printf("[%s]�� �ܾ��忡�� �����մϴ�.\n", a[i].name);
			strcpy(a[i].name, "\0");//�ش� �ܾ ����� ������ �ΰ����� �ٲ���
			strcpy(a[i].mean, "\0");//�ش� ���� ����� ������ �ΰ����� �ٲ���
		}

	}
	if ((fp = fopen("Voca.txt", "w")) == NULL)//�ܾ����� /�ؽ�Ʈ ������ �ٽ� ���� ���� ����
	{
		fprintf(stderr, "���� Voca.txt�� �� �� �����ϴ�\n", "Voca.txt");
	}
	for (i = 0; i<count; i++)
	{
		if ((strcmp(a[i].name, "\0")) != 0)//���� �ܾ ����� ������ ���� �ΰ��� �ƴҰ�츸 ���ŵ� ������ ���
		{
			fputs(a[i].name, fp);
			fputc('\n', fp);//fputs �� �ؽ�Ʈ�� �����Ҷ� ���Ͱ��� �ȹޱ⿡ ������ ���� �ٿ���
			fputs(a[i].mean, fp);
			fputc('\n', fp);
		}
	}
	fclose(fp);//������ ����
	printf("�޴��� ���ư��ϴ�\n");
	Sleep(1000);
	system("cls");
	menu_scr();//�޴��� ���ư�
}


void Statistics_Menuscr(void) //�޴��� ������ִ� �Լ�
{
	system("title ���� �н���");//�ܼ��� ������ �ٲ���
	system("color 9F");//�ܼ�â�� ������ �ؽ�Ʈ�� ���� �ٲ���  (���:�ؽ�Ʈ) 9:�Ķ�F:�Ͼ��
	system("mode con: cols=115 lines=30");//�ܼ� ũ�� ����
	printf("==========================================================================");
	gotoxy(50, 11);
	printf("�߰��� �߰�\n");
	gotoxy(50, 13);
	printf("�߰��� ����\n");
	gotoxy(50, 15);
	printf("���н��� ����\n");
	gotoxy(50, 17);
	printf("���н��� Ȯ��\n");
	gotoxy(46, 23);
	printf("�����α׷� ���� [ESC]\n");
}

int Stat_Menuchoice(void) // �޴� ����
{
	int key;//�Է¹��� Ű�� int���� ������ ����
	int x = 47, y = 11;//ȭ��ǥ�� ���� ��ǥ ���� x :x�� ��ǥ  y:y�� ��ǥ

	while (1)
	{
		key = getch();//Ű ���� int������ �Է¹���
		if (key == 0xE0 || key == 0)
			key = getch();
		switch (key)
		{
		case UP: //���� ����Ű�� �Է¹�����
			system("cls");
			Statistics_Menuscr();//�޴�â�� ����
			y -= 2;	   //ȭ��ǥ("=>")�� y��ǥ�� 2ĭ �Ʒ��� ����
			if (y <= 11)  //ȭ��ǥ("=>")�� y��ǥ�� �޴� �������δ� �ö��� �ʵ��� �ܾ�˻��� ���� ������ 11������ �ö󰡵��� ����
				y = 11;
			gotoxy(x, y);
			printf("=>");//�ٲ� ��ǥ�� ȭ��ǥ ���
			break;

		case DOWN://�Ʒ��� ����Ű�� �Է¹�����
			system("cls");
			Statistics_Menuscr();//�޴�â�� ����
			y += 2;	   //ȭ��ǥ("=>")�� y��ǥ�� 2ĭ ���� �ø�
			if (y >= 17)  //ȭ��ǥ("=>")�� y��ǥ�� �޴� �Ʒ������δ� �������� �ʵ��� �ܾ������ ���� ������ 17������ ���������� ����
				y = 17;
			gotoxy(x, y);
			printf("=>");//�ٲ� ��ǥ�� ȭ��ǥ ���
			break;

		case ESC://ESCŰ�� �Է¹�����
			system("cls");
			system("mode con: cols=70 lines=30"); //ũ��
			system("title Learing Support Program");  //���� ��ȭ
			system("color 3F");
			return 0;//����

		case ENTER://����Ű�� �Է¹�����
			Stat_Function(y);//Function�Լ��� ����
		}

	}
}

void Stat_Function(int y) // �޴� �������̽� =>�� y���� ���� ENTER�� �޾����� ������ �޴��� ����
{
	if (y == 11)//���� �߰�
	{
		system("cls");
		AddSubject();
	}
	if (y == 13)//���� ����
	{
		system("cls");
		DelSubject();

	}
	if (y == 15)//�н��� ����
	{
		system("cls");
		Measure();

	}
	if (y == 17)//�н��� Ȯ��
	{
		system("cls");
		StudyCheck();

	}
}
void Stat_ProgramRead(void) // ó���� �̾�� ���� ��� ������ ������ ��������
{
	int i = 0;
	FILE *fp;
	if ((fp = fopen("SubJect.txt", "a")) == NULL)//�н� ������ ������ ����
	{
		fprintf(stderr, "SubJect.txt ������ �� �� �����ϴ�.\n", "SubJect.txt");
		exit(1);
	}
	fclose(fp);//������ �ݾ���

	if ((fp = fopen("StudyNum.txt", "a")) == NULL) //�н��� ��ġ�� ������ ����
	{
		fprintf(stderr, "StudyNum.txt ������ �� �� �����ϴ�.\n", "StudyNum.txt");
		exit(1);
	}
	fclose(fp);//������ �ݾ���
}

void AddSubject(void) //���� �߰�
{

	int i = 0, j, key, count; //i for�� ���࿡ ���� ���� ,key: ENTERŰ�� ESCŰ�� ���� ���� �������
	int esc;//���� �ݺ��� Ż���
	int fullcount = 0;//������ 8�� ������ ���� �����ϵ��� ���� ������ fullcount��8

	FILE *fp;
	if ((fp = fopen("SubJect.txt", "r")) == NULL)//������ ����Ǿ� �ִ� �ؽ�Ʈ ������ �б���� ������
	{
		fprintf(stderr, "���� SubJect.txt�� �� �� �����ϴ�\n", "SubJect.txt");
		exit(1);
	}
	while (!feof(fp))//������ ����� ������ �о ������� ����ü �迭�� �־���
	{
		fgets(b[i].name, 100, fp);
		b[i].name[strlen(b[i].name) - 1] = '\0';
		i++;
	}
	fclose(fp);//������ �ݾ���

	printf("������ �߰��� �������� Ȯ���ϰڽ��ϴ�.\n\n");
	for (i = 0; i<SUBJECT; i++)
	{
		esc = 0;//���� Ż��� 1�� �Ǹ� Ż���ϰ� �ҰŶ� 0���� �ʱ�ȭ

		if ((strcmp(b[i].name, "\0")) == 0) //���� �̸��� ���� ������ �ΰ��̶�� �ƹ��͵� ���ٸ�
		{
			printf("������ �߰��Ͻ� �� �ֽ��ϴ�.\n\n");
			printf("�߰��Ͻ� ������ �̸��� �Է��� �ּ���\n\n");
			gets(b[i].name);//�����̸��� �־���

			while (1)//����Ұ����� ���� ����
			{
				printf("��� ������ �߰��Ͻðڽ��ϱ�?\n\n��[Enter],�ƴϿ�[ESC]\n");
				key = getch();
				if (key == 13)//enter�� ������
				{
					system("cls");//�� ������ Ż���ؼ� �ٽ� �����߰� ����
					break;
				}
				else if (key == 27)//esc�� ������ �̷����� Ż���ϰ� esc���� 1�� ���ؼ� ���������� Ż����
				{
					esc = 1;
					break;
				}
				else
				{
					system("cls");//enter�� esc�� ����
				}
			}
			if (esc == 1)
			{
				break;//������ ���� Ż��
			}
		}
		else//�о�� ����ü �迭���� �����̸��� �����ϴ� ���� ã�ƺôµ� �ΰ��� �ƴҰ��
		{
			fullcount++;//fullcount���� 1����
			if (fullcount == 8)//������ 8���� �� ���������
			{
				printf("�н��ϰ� �ִ� ������ 8���� �ʰ��մϴ�\n\n");
				Sleep(1500);
				printf("����߽� ���δ� �н��� ũ�� ������ ���� �ʽ��ϴ�.\n\n");
				Sleep(1500);
				printf("�н����� ������ �ٲٰ� �����ø� [���� ����]�޴����� �ٸ� ������ �� ���� ���� ���ּ���\n\n");
				printf("3�� �Ŀ� �޴��� ���ư��ϴ�.\n");
				Sleep(3000);
				break;
			}
		}
	}

	if ((fp = fopen("SubJect.txt", "w")) == NULL)//������ ����Ǵ� �ؽ�Ʈ ������ ���� ���� ������
	{
		fprintf(stderr, "���� SubJect.txt�� �� �� �����ϴ�\n", "SubJect.txt");
	}
	for (i = 0; i<SUBJECT; i++)//�����߰��� �ְ��ѵ��� 8�� ��ŭ �����˻��� �Ѵ�
	{
		if ((strcmp(b[i].name, "\0")) != 0)//���� �����̸��� ����� ������ �ΰ��� �ƴ϶�� �ؽ�Ʈ ���Ͽ� ��������
		{
			fputs(b[i].name, fp);
			fputc('\n', fp);//fputs �� �ؽ�Ʈ�� �����Ҷ� ���Ͱ��� �ȹޱ⿡ ������ ���� �ٿ���
		}
	}
	fclose(fp);//������ ����
	printf("������ ���� �߰��߽��ϴ�.\n");
	Sleep(500);
	Statistics_Menuscr();//�޴��� ���ư�

}


void DelSubject(void) // ���� ����
{
	int i = 0, count;
	int j;
	char target[100];
	FILE *fp, *fp2;
	if ((fp = fopen("SubJect.txt", "r")) == NULL) //�ؽ�Ʈ ���ϳ� ������ ���� �о�ͼ�
	{
		fprintf(stderr, "���� SubJect.txt�� �� �� �����ϴ�\n", "SubJect.txt");
	}
	while (!feof(fp))//�о�°� ������� ����
	{
		fgets(b[i].name, 100, fp);
		b[i].name[strlen(b[i].name) - 1] = '\0';//���� ���� ���Ÿ� ���� �ǳ� �ϳ��� �ΰ����� ����
		i++;
	}
	fclose(fp);//������ ����
	count = i - 1;
	if ((fp2 = fopen("StudyNum.txt", "r")) == NULL) //�н����� ����Ǿ� �ִ� �ؽ�Ʈ ������ �б� ���� ����
	{
		fprintf(stderr, "���� StudyNum.txt�� �� �� �����ϴ�\n", "StudyNum.txt");
	}
	for (i = 0; i<count; i++)//�о�°� ������� ����
	{
		fscanf(fp2, "%d", &b[i].day_study);//�ش� ������ ���� ���η� ��ġ��
		for (j = 0; j<7; j++)//�ش� ������ ��ȭ��������� ������ ���η� ��ġ
			fscanf(fp2, "%d", &b[i].week_study[j]);
	}
	fclose(fp2);//������ ����
	printf("�����Ͻ� ������ �Է��ϼ���\n");
	gets(target);//������ ������ Ÿ�ٿ� ����
	for (i = 0; i<count; i++)//�ҷ��� �ܾ� �� ��ŭ ���� �˻��� ��
	{
		if (!strcmp(b[i].name, target))//�о�ͼ� ����Ǿ� �ִ� ���� ������ �ܾ�� ��ġ�ϸ�
		{
			printf("[%s]�� ���ǥ���� �����մϴ�.\n", b[i].name);
			strcpy(b[i].name, "\0");//�����̸��� null������ ���� ������
			b[i].day_study = 0;
			for (j = 0; j<7; j++)
				b[i].week_study[j] = 0;
		}

	}
	if ((fp = fopen("SubJect.txt", "w")) == NULL)//������� ������ ����Ǿ� �ִ� ������ ����
	{
		fprintf(stderr, "���� SubJect.txt�� �� �� �����ϴ�\n", "SubJect.txt");
	}
	for (i = 0; i<count; i++)//�ҷ��� �ܾ��� �� ��ŭ ���� �˻��� �ؼ�
	{
		if ((strcmp(b[i].name, "\0")) != 0)//������ �ܾ �ƴ� �͸� �ؽ�Ʈ ���Ͽ� ����
		{
			fputs(b[i].name, fp);
			fputc('\n', fp);//fputs �� �ؽ�Ʈ�� �����Ҷ� ���Ͱ��� �ȹޱ⿡ ������ ���� �ٿ���
		}
	}
	fclose(fp);//������ ����
	if ((fp2 = fopen("StudyNum.txt", "w")) == NULL)//���� ���� �н����� ����Ǿ� �ִ� ������ ����
	{
		fprintf(stderr, "���� StudyNum.txt�� �� �� �����ϴ�\n", "StudyNum.txt");
	}
	for (i = 0; i<count; i++) //�ҷ��� �ܾ��� ����ŭ �˻����ؼ�
	{
		if ((strcmp(b[i].name, "\0")) != 0)
		{
			fprintf(fp2, "%d ", b[i].day_study);//������ �ܾ �ƴ� �н����� �н��� ���Ͽ� ����
			for (j = 0; j<7; j++)
				fprintf(fp2, "%d ", b[i].week_study[j]);
		}
	}
	fclose(fp2);//������ �ݾ���
	for (i = 0; i<SUBJECT; i++)
	{
		strcpy(b[i].name, "\0");  //�����Ҷ� ������ ��űⰪ�� ���Ƽ� �ʱ�ȭ ���ϸ� ���� �߰����� �߰����� ���θ� Ȯ���Ҷ� ���� ��⸦ �о  ���� �߻�
		b[i].day_study = 0;
		for (j = 0; j<7; j++)
			b[i].week_study[j] = 0;
	}
	printf("�޴��� ���ư��ϴ�\n");
	Sleep(1000);
	system("cls");
	Statistics_Menuscr();//�޴� ���

}

void Measure(void) //�н��� ����
{
	int hour = 0, min = 0, sec = 0, frame = 0;
	int i = 0, j, count;
	char ch;
	char target[20];
	int measutime = 0;//�����ð� ������ ȯ��
	FILE *fp, *fp2;
	if ((fp = fopen("SubJect.txt", "r")) == NULL) //�н������� ����Ǿ� �ִ� �ؽ�Ʈ ������ �б� ���� ����
	{
		fprintf(stderr, "���� SubJect.txt�� �� �� �����ϴ�\n", "SubJect.txt");
	}
	while (!feof(fp))//�о�°� ������� ����
	{
		fgets(b[i].name, 100, fp);
		b[i].name[strlen(b[i].name) - 1] = '\0';//���� ���� ���Ÿ� ���� �ǳ� �ϳ��� �ΰ����� ����
		i++;
	}
	fclose(fp);//������ ����
	count = i - 1;
	if ((fp2 = fopen("StudyNum.txt", "r")) == NULL) //�н����� ����� �ؽ�Ʈ ������ �б���� ����
	{
		fprintf(stderr, "���� StudyNum.txt�� �� �� �����ϴ�\n", "StudyNum.txt");
	}
	for (i = 0; i<count; i++)//�о�°� ������� ����
	{
		fscanf(fp2, "%d", &b[i].day_study);//�ش� ������ ���� ���η� ��ġ��
		for (j = 0; j<7; j++)//�ش� ������ ��ȭ��������� ������ ���η� ��ġ
			fscanf(fp2, "%d", &b[i].week_study[j]);
	}
	fclose(fp2);//������ ����
	stopwatch_menu();//��ž��ġ �޴� �Լ��� �ҷ���
	while (1)
	{
		printf("%2d : %2d : %2d : %2d", hour, min, sec, frame);
		Sleep(10);
		frame++;
		if (frame == 100)
		{
			sec++;
			frame = 0;
		}
		if (sec == 60)
		{
			min++;
			sec = 0;
		}
		if (min == 60)
		{
			hour++;
			min = 0;
		}

		if (kbhit())
		{
			ch = getch();
			switch (ch)
			{
			case 'S': case 's':   //���� s�� ������ getch ������ Ű�Է��� �޴��� ���ߴٰ� ���� �Է� ������ �ٽ� ���ư�
				ch = getch();
				break;
			case 'R': case 'r':   //����
				system("cls");
				stopwatch_menu();
				hour = min = sec = frame = 0;
				break;
			case 'Q': case 'q':   //������
				goto label;//���� Ż��

			case 'W': case 'w':  //��� �ܼ��� �� ������ �ʸ� ������
				printf("\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
				printf("%2d : %2d : %2d : %2d\n", hour, min, sec, frame);
				printf("�н����� ������ ������ �Է��ϼ���\n");
				measutime = (hour * 60) + min;//���� �ð��� ������ ȯ���ؼ� �����ð������� ����
				gets(target);
				for (i = 0; i<SUBJECT; i++)
				{
					if (!strcmp(b[i].name, target))
					{
						printf("�н����� �����߽��ϴ�.\n");
						b[i].day_study += measutime;//������ ȯ��� �����ð��� ���� ���η�daystudy�� ����
						b[i].week_study[WhatDay()] += measutime;//�ش���񿡼� ���ÿ� �ش��ϴ� ���Ͽ� ������ ���� whatday�� ������ ���ϰ��� ��ȯ
					}
				}
				break;
			default:
				break;
			} //Ű����� ���� �Է� ���� ���� ���� switch
		} // if�� Ű����� ���� �����ΰ� �Է� �޾Ҵٸ�
		printf("\n\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
	}// �ð��� ���� �ݺ��� �߰�ȣ
label:
	if ((fp = fopen("SubJect.txt", "w")) == NULL)//������� ���� ������ ����
	{
		fprintf(stderr, "���� SubJect.txt�� �� �� �����ϴ�\n", "SubJect.txt");
	}
	for (i = 0; i<count; i++)//���ŵ� ���� �����
	{
		if ((strcmp(b[i].name, "\0")) != 0)
		{
			fputs(b[i].name, fp);
			fputc('\n', fp);//fputs �� �ؽ�Ʈ�� �����Ҷ� ���Ͱ��� �ȹޱ⿡ ������ ���� �ٿ���
		}
	}
	fclose(fp);//������ ����
	if ((fp2 = fopen("StudyNum.txt", "w")) == NULL)//���� ���� �н��� ������ ����
	{
		fprintf(stderr, "���� StudyNum.txt�� �� �� �����ϴ�\n", "StudyNum.txt");
	}
	for (i = 0; i<count; i++) //���ŵ� �н��� ���Ͽ� �ٽ� ����
	{
		if ((strcmp(b[i].name, "\0")) != 0)
		{
			fprintf(fp2, "%d ", b[i].day_study);
			for (j = 0; j<7; j++)
				fprintf(fp2, "%d ", b[i].week_study[j]);
		}
	}
	fclose(fp2);//���� ����
	Statistics_Menuscr();//�޴��� ���ư�
}

void StudyCheck(void)//�н����� Ȯ��
{
	int i = 0, j, key, count;
	int weeksum = 0, weekhour = 0, weekminute = 0;//weeksum�ְ����η� �� weekhour�ְ� �� ���νð�[��] weekminute �ְ� �� ���� �ð�[��]
	int dayhour = 0;//���� �н��ð� [��]
	int dayminute = 0;//���� �н��ð� [��]
	double weekaverhour = 0;//�ְ� ��� �н��� [��]
	double weekaverminute = 0;//�ְ� ��� �н��� [��]
	FILE *fp, *fp2;
	if ((fp = fopen("SubJect.txt", "r")) == NULL) //�б���� ������ ����� ������ ����
	{
		fprintf(stderr, "���� SubJect.txt�� �� �� �����ϴ�\n", "SubJect.txt");
	}
	while (!feof(fp))//���ϳ� ������ �о��
	{
		fgets(b[i].name, 100, fp);
		b[i].name[strlen(b[i].name) - 1] = '\0';//���� ���� ���Ÿ� ���� �ǳ� �ϳ��� �ΰ����� ����
		i++;
	}
	fclose(fp);//���� ����
	count = i - 1;//�ҷ��� ������ ������ ����
	if ((fp2 = fopen("StudyNum.txt", "r")) == NULL) // �н����� ����� �ؽ�Ʈ ������ �б���� ����
	{
		fprintf(stderr, "���� StudyNum.txt�� �� �� �����ϴ�\n", "StudyNum.txt");
	}
	for (i = 0; i<SUBJECT; i++)//������ ������� �о��
	{
		fscanf(fp2, "%d", &b[i].day_study);//�ش� ������ ���� ���η� ��ġ��
		for (j = 0; j<7; j++)//�ش� ������ ��ȭ��������� ������ ���η� ��ġ
			fscanf(fp2, "%d", &b[i].week_study[j]);
	}
	fclose(fp2);//������ ����

	printf("======�н��� Ȯ��========\n");
	for (i = 0; i<count; i++)
	{
		dayhour += b[i].day_study / 60;//���� ���η� �ð� �ؽ�Ʈ�� ����Ǿ� �ִ� ������ ȯ��� ���� ���η��� 60���� �����༭ ����
		dayminute = b[i].day_study % 60;//���� ���η� �� �ؽ�Ʈ�� ����Ǿ� �ִ� ������ ȯ��� ���� ���η��� 60���� ������ ����ؼ� ����
		printf("%s�� ���� �н���: %d�ð� %d��\n", b[i].name, dayhour, dayminute);
	}
	for (i = 0; i<count; i++)
	{
		weeksum = 0;//�ְ� �ش� ������ ���η��� ��
		for (j = 0; j<7; j++)//��ȭ����������� ������ ȯ��� ���η��� ���� ���ؼ� weeksum�� ����
			weeksum += b[i].week_study[j];
		weekhour = weeksum / 60;//weeksum�� 60���� ������ �ְ� �� ���η� [��]���
		weekminute = weeksum % 60;//weeksum�� 60���� ����������ؼ� �ְ� �� ���η� [��]���
		printf("%s�� �ְ� �н���: %d�ð� %d��\n", b[i].name, weekhour, weekminute);
		weekaverhour = (weeksum / 7) / 60;//weeksum�� 7�� ����� ������ ȯ��� �ְ� ��� �н����� ���ϰ� �ְ� ���  ���νð� [��]�� ����
		weekaverminute = (weeksum / 7) % 60;//weeksum�� 7�� ����� ������ ȯ��� �ְ� ��� �н����� ���ϰ� �ְ� ��� ���νð� [��]�� ����
		printf("%s�� �ְ� ��� �н���: ��%f�ð� %f��\n", b[i].name, weekaverhour, weekaverminute);
	}
	while (1)
	{
		printf("����� ESC\n");
		key = getch();//Ű ���� �Է¹���
		if (key == 27)
		{
			system("cls");
			break;
		}

	}
	Statistics_Menuscr();//�޴��� ���ư�

}
int WhatDay(void)//���� ����� ���ִ� �Լ�
{
	time_t timer;
	struct tm *t;

	timer = time(NULL); // ���� �ð��� �� ������ ���

	t = localtime(&timer);// �� ������ �ð��� �и��Ͽ� ����ü�� �ֱ�
	return t->tm_wday; // �Ͽ���=0, ������=1, ȭ����=2, ������=3, �����=4, �ݿ���=5, �����=6 Ÿ�� �Լ��� ����Ǿ� ����
}

void WeekStudyReset(int day)//�ְ� �н��� �ʱ�ȭ (�����ϸ��� �ְ� �н����� �ڵ����� �ʱ�ȭ��) (int day)�� WhatDay()�Լ��� ������� �Ű������� ���� �� ���ϰ���
{
	int i = 0;
	int j, count;
	int log;//�����Ͽ� �н����� �ʱ�ȭ �ߴ��� Ȯ�����ִ� ���� �Ź� �����Ͽ� ���α׷��� ų������ �ʱ�ȭ ���� �ʱ� ����
	int first; //������ ���ʷ� ��������� �����Ͽ� ������ 0�� �־��ֱ� ���� ����
	FILE *fp, *fp2;
	if ((fp = fopen("Reset.txt", "a")) == NULL)//�ʱ�ȭ ���θ� �˷��� ������ ����� �κ� ������ �̾�� ���� ��� ������ ������ �������
	{
		fprintf(stderr, "���� Reset.txt�� �� �� �����ϴ�\n", "Reset.txt");
		exit(1);
	}
	fclose(fp);//������ ����


	if ((fp2 = fopen("Reset.txt", "r")) == NULL)//Reset ������ ������(0�Ǵ� 1�� ����ɰ���)�� first������ �ҷ���
	{
		fprintf(stderr, "���� Reset.txt�� �� �� �����ϴ�\n", "Reset.txt");
	}
	fscanf(fp2, "%d", &first);
	fclose(fp2);//������ �ݾ��ְ�

	if ((fp2 = fopen("Reset.txt", "w")) == NULL)//�ٽ� ������� �����ش�
	{
		fprintf(stderr, "���� Reset.txt�� �� �� �����ϴ�\n", "Reset.txt");
	}
	if (!first == 0 || 1)//���ʿ� ������ ��������� ������(0)�� �־��ֱ� ���� if��
	{
		first = 0;                 //�Ʊ� first�� �ҷ��Դ� �����Ͱ� 0�Ǵ� 1�� �ƴ϶�� ���Ͽ� 0�� �־��ֱ� ���� first�� 0�� �־���
		fprintf(fp2, "%d", first);//0�� �־��� first�� ���� ���Ͽ� ����
	}
	fclose(fp2);//���� ����

	if ((fp = fopen("Reset.txt", "r")) == NULL)//������� ������ ���� ����� �κ�
	{
		fprintf(stderr, "���� Reset.txt�� �� �� �����ϴ�\n", "Reset.txt");//�ְ��н����� �ʱ�ȭ ���ΰ� �ִ� Reset������ ���
	}
	fscanf(fp, "%d", &log); //log��� ������ ������
	fclose(fp);
	if (day == 1)//�Ű������� �������� 1�̶�� �� ������ �������̶�� (1�� ������ 2�� ȭ���� '''')
	{
		if (log == 0)//�ʱ�ȭ ���� Ȯ�� ������ �������ε� (0=�н����� �ʱ�ȭ ���� �ʾҴٸ�) �ʱ�ȭ�ϸ� log�� 1�̵ɰ���
		{
			if ((fp = fopen("SubJect.txt", "r")) == NULL) //�б���� ������ ����Ǿ� �ִ� ������ ����
			{
				fprintf(stderr, "���� SubJect.txt�� �� �� �����ϴ�\n", "SubJect.txt");
			}
			while (!feof(fp))//������� ������ �о��
			{
				fgets(b[i].name, 100, fp);
				b[i].name[strlen(b[i].name) - 1] = '\0';//���� ���� ���Ÿ� ���� �ǳ� �ϳ��� �ΰ����� ����
				i++;
			}
			fclose(fp);
			count = i - 1;//�о�� ���� ���� ����
			if ((fp2 = fopen("StudyNum.txt", "r")) == NULL) //�б���� �н����� ����� ������ ����
			{
				fprintf(stderr, "���� StudyNum.txt�� �� �� �����ϴ�\n", "StudyNum.txt");
			}
			for (i = 0; i<count; i++)//�о�� ������ ������ŭ ������� �о��
			{
				fscanf(fp2, "%d", &b[i].day_study);//�ش� ������ ���� ���η� ��ġ��
				for (j = 0; j<7; j++)//�ش� ������ ��ȭ��������� ������ ���η� ��ġ
					fscanf(fp2, "%d", &b[i].week_study[j]);
			}
			fclose(fp2);//������ ����

			for (i = 0; i<count; i++)//�ְ� �н����� ���� 0���� �ʱ�ȭ ����
			{
				for (j = 0; j<7; j++)
					b[i].week_study[j] = 0;
			}

			if ((fp = fopen("SubJect.txt", "w")) == NULL)//���� ���� ���������� ����
			{
				fprintf(stderr, "���� SubJect.txt�� �� �� �����ϴ�\n", "SubJect.txt");
			}
			for (i = 0; i<count; i++)//�о�� ������ ����ŭ ���⵿���� ����
			{
				if ((strcmp(b[i].name, "\0")) != 0)
				{
					fputs(b[i].name, fp);
					fputc('\n', fp);//fputs �� �ؽ�Ʈ�� �����Ҷ� ���Ͱ��� �ȹޱ⿡ ������ ���� �ٿ���
				}
			}
			fclose(fp);//������ ����
			if ((fp2 = fopen("StudyNum.txt", "w")) == NULL)//�н����� ����� ������ ����
			{
				fprintf(stderr, "���� StudyNum.txt�� �� �� �����ϴ�\n", "StudyNum.txt");
			}
			for (i = 0; i<count; i++) //���ŵ� �н����� ���Ͽ� ����
			{
				if ((strcmp(b[i].name, "\0")) != 0)
				{
					fprintf(fp2, "%d ", b[i].day_study);
					for (j = 0; j<7; j++)
						fprintf(fp2, "%d ", b[i].week_study[j]);
				}
			}
			fclose(fp2);//������ ����

			log = 1;//log������ 1�� �ٲٰ� (���� �ʱ�ȭ�� �������ٴ°� �ǹ�)
			if ((fp = fopen("Reset.txt", "w")) == NULL)
			{
				fprintf(stderr, "���� Reset.txt�� �� �� �����ϴ�\n", "Reset.txt");
			}
			fprintf(fp, "%d", log);//0�̾��� ���ϳ� ������ 1�� �����
			fclose(fp);//���� ���� �ٽ� �ҷ��͵� log�� 1�̱� ������ �ʱ�ȭ�� ������� ����
		}
	}
	if (day == 2)//������ ȭ���� �̶��
	{
		log = 0;//�������� ������ ȭ�����̱� ������ �ٽ� log���� 0���� �ٲ㼭 �������ִ� �κ� ���� �����Ͽ� �� ���� �ʱ�ȭ�� �ٽ� ����� �� �ְ��ϱ� ����
		if ((fp = fopen("Reset.txt", "w")) == NULL)
		{
			fprintf(stderr, "���� Reset.txt�� �� �� �����ϴ�\n", "Reset.txt");
		}
		fprintf(fp, "%d", log);
		fclose(fp);//������ ����
	}

}

int DayReset(void)//���� �н��� �ʱ�ȭ
{
	int i = 0, key;
	int x = 28, y = 11;//ȭ��ǥ�� ���� ��ǥ
	printf("�ȳ��ϼ��� �н����� �����ϰ� Ȯ���� �� �ִ� �н� ��� ���α׷��Դϴ�.\n\n");
	Sleep(1300);
	printf("���� ó�� ����Ͻʴϱ�?\n\n");
	Sleep(1500);
	system("cls");
	Decision();


	while (1)
	{
		key = getch();
		if (key == 0xE0 || key == 0)
			key = getch();
		switch (key)
		{
		case LEFT: //���� ����Ű�� �Է¹�����
			system("cls");
			Decision();//�޴�â�� ����
			x -= 40;	   //ȭ��ǥ("��")�� x��ǥ�� 40ĭ �������� �̵�
			if (x <= 28)  //ȭ��ǥ("��")�� x��ǥ�� ��� ���� ����Ű�� �޾Ƶ� ���� �޴����� �����ǵ��� 28������ �̵� �ǵ��� ����
				x = 28;
			gotoxy(x, y);
			printf("��");//�ٲ� ��ǥ�� ȭ��ǥ ���
			break;

		case RIGHT://�Ʒ��� ����Ű�� �Է¹�����
			system("cls");
			Decision();//�޴�â�� ����
			x += 40;	   //ȭ��ǥ("��")�� x��ǥ�� 40ĭ ���������� �̵�
			if (x >= 68)  //ȭ��ǥ("��")�� x��ǥ�� ��� ������ ����Ű�� �޾Ƶ� ������ �޴����� �����ǵ��� 68������ �̵� �ǵ��� ����
				x = 68;
			gotoxy(x, y);
			printf("��");//�ٲ� ��ǥ�� ȭ��ǥ ���
			break;

		case ENTER://����Ű�� �Է¹�����
			YesorNo(x);//�ش��ϴ� ����� �������ִ� �Լ��� ���� ����
			return 0;
		}

	}

}

void Decision(void)//�ʱ�ȭ ���� �޴�
{
	system("mode con: cols=115 lines=25");
	gotoxy(30, 11);
	printf(" �ݿ�ENTER[���� �н��� �ʱ�ȭ]         �ݾƴϿ�[�״�� ����]\n\n");
}

void YesorNo(int x)
{
	int i = 0, j, count;
	FILE *fp, *fp2;
	if (x == 28)//�� �ʱ�ȭ�� ����������
	{
		system("cls");
		printf("�н����� �ʱ�ȭ �մϴ�.\n");
		Sleep(1000);
		if ((fp = fopen("SubJect.txt", "r")) == NULL) //�б���� ������ ����� ������ ����
		{
			fprintf(stderr, "���� SubJect.txt�� �� �� �����ϴ�\n", "SubJect.txt");
		}
		while (!feof(fp))//������� �о��
		{
			fgets(b[i].name, 100, fp);
			b[i].name[strlen(b[i].name) - 1] = '\0';//���� ���� ���Ÿ� ���� �ǳ� �ϳ��� �ΰ����� ����
			i++;
		}
		fclose(fp);//������ ����
		count = i - 1;
		if ((fp2 = fopen("StudyNum.txt", "r")) == NULL) //�н����� ����� ������ �б���� ����
		{
			fprintf(stderr, "���� StudyNum.txt�� �� �� �����ϴ�\n", "StudyNum.txt");
		}
		for (i = 0; i<count; i++)//������ �ҷ��� �� ��ŭ ������� ������ �о��
		{
			fscanf(fp2, "%d", &b[i].day_study);//�ش� ������ ���� ���η� ��ġ��
			for (j = 0; j<7; j++)//�ش� ������ ��ȭ��������� ������ ���η� ��ġ
				fscanf(fp2, "%d", &b[i].week_study[j]);
		}
		fclose(fp2);//������ ����
		for (i = 0; i<count; i++)//���� ���� �н����� �ʱ�ȭ����
			b[i].day_study = 0;

		if ((fp = fopen("SubJect.txt", "w")) == NULL)//���� ���� ������ ����� ������ ����
		{
			fprintf(stderr, "���� SubJect.txt�� �� �� �����ϴ�\n", "SubJect.txt");
		}
		for (i = 0; i<count; i++)//���ŵ� ������ ���Ͽ� ����
		{
			if ((strcmp(b[i].name, "\0")) != 0)
			{
				fputs(b[i].name, fp);
				fputc('\n', fp);//fputs �� �ؽ�Ʈ�� �����Ҷ� ���Ͱ��� �ȹޱ⿡ ������ ���� �ٿ���
			}
		}
		fclose(fp);//������ ����
		if ((fp2 = fopen("StudyNum.txt", "w")) == NULL)//���� ���� �н����� ����� ������ ����
		{
			fprintf(stderr, "���� StudyNum.txt�� �� �� �����ϴ�\n", "StudyNum.txt");
		}
		for (i = 0; i<count; i++) //���ŵ� ������ ����
		{
			if ((strcmp(b[i].name, "\0")) != 0)
			{
				fprintf(fp2, "%d ", b[i].day_study);
				for (j = 0; j<7; j++)
					fprintf(fp2, "%d ", b[i].week_study[j]);
			}
		}
		fclose(fp2);//������ ����
	}

	if (x == 43)//�ƴϿ� ����
	{
		system("cls");
		printf("���α׷��� ���� �մϴ�.\n");
		Sleep(1000);
	}
}
//================================================-SungHo

//================================================-seokhoon
void calender() {
	int year = 0;//���� �Է¹���
	int month = 0;//���� �Է¹���
	int day = 1;//�޷��� �������� ã�� ���� �����̴�(������ �� ������ ��� Ƚ��)
	int everyday = 0;//�Է� �� ������ �� ���� �� ��¥ ��
	int monthday[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };//1~12������ ���ڼ�
																		   //�迭�� ù��°�� �迭�� 0�� �̹Ƿ� 0�� �ְ� 1�� ���� ��¥�� �־� �ް� �迭�� ������ ���߷��ߴ�.
	int yoonyear = 0;//���� ����ġ
	int preyear = 0;//�Է� �� �� ������ �� ��¥ ��
	int i;
	int j;
	int z;//1�� ���� �Է��� �� ���� �ݺ�
	int w;
	int key; // esc
	char swch = 'h';//��¥�� w a s d�� �̵���ų ����ġ�̴�
	int start = 0;
	system("cls");
	printf("�� �⵵�� �Է��Ͻðڳ���?\n");
	scanf("%d", &year);
	printf("�� ���� ���Ͻó���?\n");
	scanf("%d", &month);

	if (month > 12) {
		printf("12�������Դϴ�!\n");
		return;
	}

	while (1) {

		monthday[2] = 28;
		yoonyear = 0;
		preyear = 0;
		everyday = 0;
		day = 1;




		if (((year) % 4 == 0 && (year % 100 != 0 || year % 400 == 0))) {//������ ���
																		//���� 4�⿡ �ѹ�, 100�� ����� �ش� ���, 400�� ����ش� ����
			yoonyear = 1;//�����̸� yoonyear�� 1�� �ٲ��ش�
		}

		for (z = 1; z < year; z++) {//�Է��� �� �� ������ �� �� ���� ���ϴ°��̴�
			if (((z) % 4 == 0 && (z % 100 != 0 || z % 400 == 0))) {
				preyear = (preyear + 366) % 7;
				/*1�� ���� ���� ����ϵ� ������ ��¥�� ������ 366�� ������ 366�� ���Ѵ�, ������ 7�� �ϴ� ������
				�� ������ �޷¿��� �������� �����ϴ� �� �̹Ƿ� �� �ٿ� ��� �Ǵ� 7���� �̸� ������ �ִ°��̴�
				�̸� �������ִ� ������ �Է� ���� �ʹ� ũ�� int �ڷ����� ũ�⸦ �ʰ� �� ���� �ֱ� �����̴�
				*/
			}
			else {
				preyear = (preyear + 365) % 7;
				/*����϶��� 365�� ������ 365�� ���Ѵ�*/
			}
		}

		if (yoonyear == 1) {//yoonyear=1�̸� ����
			monthday[2] = 29;//2�� �޿� �ش��ϴ� monnthday�� �迭���� 28���� 29�� �����Ѵ�
		}

		preyear = preyear + 1;

		for (j = 1; j < month; j++) {//�Է��� ���� �Է��� �� ������ ��¥�� ����Ѵ�
			everyday += (monthday[j]) % 7;
			/*monthday�� 0��°�� ������ 1��° ���� �Է��� �� ������ ������ ������ ���� ���ϸ�
			�Է��� ���� �Է��� �� ������ ��¥�� ���� �� �ִ�. ������ ��쿡�� ������ 2��°�� 28����
			29�� �����Ͽ����Ƿ� ���������� ����� �����ϴ� 7���� �̸� ������ �ִ� ������ ���� �ּ��� ����*/
		}

		day = (preyear + everyday) % 7;
		/*day�� �Է��� �� ���� ���� ��¥�� ��� ���ѰͿ� 7�� �������̴�. 1�� 1�� �������� ��������
		�޷��� 1�� �������� �� ���� ��� ��¥���� ������ �޾� ��ĭ�� �и��� �����̴�. �ٸ� �޷���
		������ 7ĭ �̹Ƿ� ��� ��¥�� 7�� ���� �������� �޷� ù�� 7ĭ���� �и��� ������ �ȴ�*/
		printf("%14d�� %d��\n", year, month);
		printf("  ��  ��  ȭ  ��  ��  ��  ��\n"); //��ȭ������� ���
		for (w = 0; w < day; w++) {
			printf("    ");
		}

		for (i = 1; i <= monthday[month]; i++) {
			printf("%4d", i);//1�� 1���� �Է��� ���� monthday��°�� ũ�⸸ŭ 1�� �����ϸ� ����Ѵ�
			if ((i + day) % 7 == 0) {//7��° ĭ ����

				printf("\n"); //�� ���� ����

			}
		}
		printf("\n");
		printf("������ = a   ������ = d   �۳� = s   ���� = w\n");
		printf("�޴��� ���ư��� = ESC(�����ѹ�ġ��)\n");
		printf("\n");
		getchar();//getchar�� getchar�տ� ����� ������ ��� enterŰ�� �ڵ����� �ԷµǾ��� �����̴�
		swch = getchar();  //swch���� getchar�� ����
		if (swch == 'w') {
			year++;   //w�� �Է½� �� ����
		}


		else if (swch == 's') {
			year--;//s�� �Է½� �� ���� -1���� ����� �̹Ƿ� ���� ó���� �ʿ䰡 ����
		}


		else if (swch == 'd') {
			month++;//d�� �Է½� �� ����
			if (month > 12) {
				//��������� 13���� ���� month�� 13�̻� �Ǹ� ���� �ѹ� ������Ű�� 1�� �ʱ�ȭ ��Ų��
				year++;
				month = 1;
			}
		}
		else if (swch == 'a')
		{//a�� �Է½� �� ����
			month--;
			if (month < 1) {
				//0���� ���� month�� 0���� �Ǹ� ���� �ѹ� ���̰� 12�� �ʱ�ȭ ��Ų��
				year--;
				month = 12;
			}

		}
		key = getch();
		if (key == 27) {
			main();
			break;
		}


	}


}
//==================================================-seokhoon
//====================================================-sungjae
int learnchoice(void)
{
	int key;//�Է¹��� Ű�� int���� ������ ����
	int x = 18, y = 8;//ȭ��ǥ�� ���� ��ǥ ���� x :x�� ��ǥ  y:y�� ��ǥ

	while (1)
	{
		key = getch();
		if (key == 0xE0 || key == 0)
			key = getch();
		switch (key)
		{
		case UP: //���� ����Ű�� �Է¹�����
			system("cls");
			learn_menu();//�޴�â�� ����
			y -= 2;	   //ȭ��ǥ("=>")�� y��ǥ�� 2ĭ �Ʒ��� ����
			if (y <= 8)  //ȭ��ǥ("=>")�� y��ǥ�� �޴� �������δ� �ö��� �ʵ��� �ܾ�˻��� ���� ������ 11������ �ö󰡵��� ����
				y = 8;
			gotoxy(x, y);
			printf("=>");//�ٲ� ��ǥ�� ȭ��ǥ ���
			break;

		case DOWN://�Ʒ��� ����Ű�� �Է¹�����
			system("cls");
			learn_menu();//�޴�â�� ����
			y += 2;	   //ȭ��ǥ("=>")�� y��ǥ�� 2ĭ ���� �ø�
			if (y >= 18)  //ȭ��ǥ("=>")�� y��ǥ�� �޴� �Ʒ������δ� �������� �ʵ��� �ܾ������ ���� ������ 17������ ���������� ����
				y = 18;
			gotoxy(x, y);
			printf("=>");//�ٲ� ��ǥ�� ȭ��ǥ ���
			break;

		case ESC:
			system("cls");
			return 0;

		case ENTER://����Ű�� �Է¹�����
			return y;
		}

	}

}
int threemenu1() {//�н���ȹ�Է� ���ý� ���� ���� �޴��� Ű����� �Է¹޴� �Լ�
	int key;//�Է¹��� Ű�� int���� ������ ����
	int x = 18, y = 8;//ȭ��ǥ�� ���� ��ǥ ���� x :x�� ��ǥ  y:y�� ��ǥ

	while (1)
	{
		key = getch();
		if (key == 0xE0 || key == 0)
			key = getch();
		switch (key)
		{
		case UP: //���� ����Ű�� �Է¹�����
			system("cls");
			planinsertmenu();//�޴�â�� ����
			y -= 2;	   //ȭ��ǥ("=>")�� y��ǥ�� 2ĭ �Ʒ��� ����
			if (y <= 8)  //ȭ��ǥ("=>")�� y��ǥ�� �޴� �������δ� �ö��� �ʵ��� �ܾ�˻��� ���� ������ 11������ �ö󰡵��� ����
				y = 8;
			gotoxy(x, y);
			printf("=>");//�ٲ� ��ǥ�� ȭ��ǥ ���
			break;

		case DOWN://�Ʒ��� ����Ű�� �Է¹�����
			system("cls");
			planinsertmenu();//�޴�â�� ����
			y += 2;	   //ȭ��ǥ("=>")�� y��ǥ�� 2ĭ ���� �ø�
			if (y >= 12)  //ȭ��ǥ("=>")�� y��ǥ�� �޴� �Ʒ������δ� �������� �ʵ��� �ܾ������ ���� ������ 17������ ���������� ����
				y = 12;
			gotoxy(x, y);
			printf("=>");//�ٲ� ��ǥ�� ȭ��ǥ ���
			break;

		case ESC:
			system("cls");
			return 0;

		case ENTER://����Ű�� �Է¹�����
			return y;
		}

	}
}
int threemenu2() {
	int key;//�Է¹��� Ű�� int���� ������ ����
	int x = 18, y = 8;//ȭ��ǥ�� ���� ��ǥ ���� x :x�� ��ǥ  y:y�� ��ǥ

	while (1)
	{
		key = getch();
		if (key == 0xE0 || key == 0)
			key = getch();
		switch (key)
		{
		case UP: //���� ����Ű�� �Է¹�����
			system("cls");
			achievementcheckmenu();//�޴�â�� ����
			y -= 2;	   //ȭ��ǥ("=>")�� y��ǥ�� 2ĭ �Ʒ��� ����
			if (y <= 8)  //ȭ��ǥ("=>")�� y��ǥ�� �޴� �������δ� �ö��� �ʵ��� �ܾ�˻��� ���� ������ 11������ �ö󰡵��� ����
				y = 8;
			gotoxy(x, y);
			printf("=>");//�ٲ� ��ǥ�� ȭ��ǥ ���
			break;

		case DOWN://�Ʒ��� ����Ű�� �Է¹�����
			system("cls");
			achievementcheckmenu();//�޴�â�� ����
			y += 2;	   //ȭ��ǥ("=>")�� y��ǥ�� 2ĭ ���� �ø�
			if (y >= 12)  //ȭ��ǥ("=>")�� y��ǥ�� �޴� �Ʒ������δ� �������� �ʵ��� �ܾ������ ���� ������ 17������ ���������� ����
				y = 12;
			gotoxy(x, y);
			printf("=>");//�ٲ� ��ǥ�� ȭ��ǥ ���
			break;

		case ESC:
			system("cls");
			return 0;

		case ENTER://����Ű�� �Է¹�����
			return y;
		}

	}
}
int threemenu3() {
	int key;//�Է¹��� Ű�� int���� ������ ����
	int x = 18, y = 8;//ȭ��ǥ�� ���� ��ǥ ���� x :x�� ��ǥ  y:y�� ��ǥ

	while (1)
	{
		key = getch();
		if (key == 0xE0 || key == 0)
			key = getch();
		switch (key)
		{
		case UP: //���� ����Ű�� �Է¹�����
			system("cls");
			achievementlookmenu();//�޴�â�� ����
			y -= 2;	   //ȭ��ǥ("=>")�� y��ǥ�� 2ĭ �Ʒ��� ����
			if (y <= 8)  //ȭ��ǥ("=>")�� y��ǥ�� �޴� �������δ� �ö��� �ʵ��� �ܾ�˻��� ���� ������ 11������ �ö󰡵��� ����
				y = 8;
			gotoxy(x, y);
			printf("=>");//�ٲ� ��ǥ�� ȭ��ǥ ���
			break;

		case DOWN://�Ʒ��� ����Ű�� �Է¹�����
			system("cls");
			achievementlookmenu();//�޴�â�� ����
			y += 2;	   //ȭ��ǥ("=>")�� y��ǥ�� 2ĭ ���� �ø�
			if (y >= 12)  //ȭ��ǥ("=>")�� y��ǥ�� �޴� �Ʒ������δ� �������� �ʵ��� �ܾ������ ���� ������ 17������ ���������� ����
				y = 12;
			gotoxy(x, y);
			printf("=>");//�ٲ� ��ǥ�� ȭ��ǥ ���
			break;

		case ESC:
			system("cls");
			return 0;

		case ENTER://����Ű�� �Է¹�����
			return y;
		}

	}
}
int threemenu4() {
	int key;//�Է¹��� Ű�� int���� ������ ����
	int x = 18, y = 8;//ȭ��ǥ�� ���� ��ǥ ���� x :x�� ��ǥ  y:y�� ��ǥ

	while (1)
	{
		key = getch();
		if (key == 0xE0 || key == 0)
			key = getch();
		switch (key)
		{
		case UP: //���� ����Ű�� �Է¹�����
			system("cls");
			timetablemenu();//�޴�â�� ����
			y -= 2;	   //ȭ��ǥ("=>")�� y��ǥ�� 2ĭ �Ʒ��� ����
			if (y <= 8)  //ȭ��ǥ("=>")�� y��ǥ�� �޴� �������δ� �ö��� �ʵ��� �ܾ�˻��� ���� ������ 11������ �ö󰡵��� ����
				y = 8;
			gotoxy(x, y);
			printf("=>");//�ٲ� ��ǥ�� ȭ��ǥ ���
			break;

		case DOWN://�Ʒ��� ����Ű�� �Է¹�����
			system("cls");
			timetablemenu();//�޴�â�� ����
			y += 2;	   //ȭ��ǥ("=>")�� y��ǥ�� 2ĭ ���� �ø�
			if (y >= 12)  //ȭ��ǥ("=>")�� y��ǥ�� �޴� �Ʒ������δ� �������� �ʵ��� �ܾ������ ���� ������ 17������ ���������� ����
				y = 12;
			gotoxy(x, y);
			printf("=>");//�ٲ� ��ǥ�� ȭ��ǥ ���
			break;

		case ESC:
			system("cls");
			return 0;

		case ENTER://����Ű�� �Է¹�����
			return y;
		}

	}
}
int alarm()      //�ð��� �˷��ִ� �Լ�/���ο��� �ּҸ� �޾ƿ� �������ֱ� ���� �����ͷ� ����.
{
	int key = 0;
	USER utime;//����� �Է� �ð����屸��ü
	time_t now;//����ð��� �ޱ����� ����ü
	struct tm *time_;//����ð��� �ޱ����� ����ü
	printf("========================\n");
	printf("==========ALARM=========\n");
	printf("========================\n");
	printf("�˶��� �︮�� �ð��� �Է����ּ���...\n");
	printf("hour : "); scanf("%d", &utime.hour);//����ڰ� �Է��ϴ� ��
	printf("min : "); scanf("%d", &utime.min);//����ڰ� �Է��ϴ� ��
	while (1) {//���ѷ����� ����� �Է½ð��� ����
		now = time(NULL);
		time_ = localtime(&now);//���ýð��� �ҷ�����
		if (_kbhit()) {//Ű���� ���� �Է��ϸ�?
			key = _getch();//�Է°��� int������ key�� ����
			if (key == ESC)//�Է°��� ESC���?
				return 0;//����
		}
		printf("���� �ð� : %2d�� %2d�� %2d��\n", time_->tm_hour, time_->tm_min, time_->tm_sec);//���ýð� ������
		printf("�Է� �ð� : %2d�� %2d��\n", utime.hour, utime.min);//����� �Է½ð�������
		printf("ESC�� �Է��Ͻø� ����˴ϴ�.....\n");
		Sleep(200);
		system("cls");//ȭ������
		if (utime.hour == time_->tm_hour&&utime.min == time_->tm_min)//����� �Է½ð��� ���ٸ� ��������
			break;
	}
	while (1) {
		printf("�˶� ����!!");
		printf("ESC�� ������ ����˴ϴ�.");
		if (_kbhit()) {//Ű���� ���� �Է��ϸ�?
			key = _getch();//�Է°��� int������ key�� ����
			if (key == ESC)//�Է°��� ESC���?
				break;//while�� ����
		}
		Beep(262, 200);/* �� ���� *///�˶��� ���
		Beep(294, 200); /* �� ���� */
		Beep(330, 200); /* �� ���� */
		Beep(349, 200); /* �� ���� */
		Beep(392, 200); /* �� ���� */
		Beep(440, 200); /* �� ���� */
		Beep(494, 200); /* �� ���� */
		Beep(524, 200); /* �� ���� */
		Sleep(500);//0.5�� ����
		system("cls");
	}
	return 0;
}
int timer() {
	int inmin = 0, insec = 0, inhour = 0, key = 0;
	//inmin�� ��,insec�� ��,inhour�� �� �� �����ϴº��� //key�� ����� Ű���� �޴� ����
	printf("Ÿ�̸��� �ð��� �Է����ּ���\n");
	printf("min : ");
	scanf("%d", &inmin);
	printf("sec : ");
	scanf("%d", &insec);

	while (1) {
		if (inmin >= 60)//���� 60�� �Ѵ´ٸ�
		{
			inmin -= 60;//�� -60�� ���ְ�
			inhour++;//�ð��� 1�� ���Ѵ�
		}
		else
			break;//�ƴ϶�� �������´�
	}
	while (1) {
		if (insec >= 60) {//�ʰ� 60�� �Ѵ´ٸ�
			insec -= 60;//�ʿ��� -60�� ���ְ�
			inmin++;//�п� 1�� ���Ѵ�
		}
		else
			break;//�ƴ϶�� �������´�
	}
	if (inmin >= 60)//���� �Ȱ��� ���� ������ ���� 60�ϰ�찡 �վ� �ٽý��ش�
	{
		inmin -= 60;
		inhour++;
	}
	while (1)
	{
		if (_kbhit()) {//Ű���� ���� �Է��ϸ�?
			key = _getch();//�Է°��� int������ key�� ����
			if (key == ESC)//�Է°��� ESC���?
				return 0;//����
		}
		if (insec == 0 && inmin == 0 && inhour != 0)//�ð��� �带�� ���� 0�̵Ǹ� �ð��� 1����
		{
			inhour--;
			inmin = 60;//���� 60���� ������ش�
		}
		if (insec == 0)//�ʰ� 0�̵Ǹ�
		{
			inmin--;//�п��� 1�� ���ְ�
			insec = 60;//�ʸ� 60�� �ʱ�ȭ�����ش�
		}

		printf("��������������\n");
		printf("������ Timer������\n");
		printf("��������������\n");
		printf("��      ��      ��      ��\n");
		printf("��  %2d  ��  %2d  ��  %2d  ��\n", inhour, inmin, insec);//Ÿ�̸� �ð� ���
		printf("��      ��      ��      ��\n");
		printf("��������������\n");
		printf("ESC�� ������ ����˴ϴ�.\n");
		Sleep(1000);//1������
		insec -= 1;//�ð��� �帧�� ��Ÿ��
		system("cls");//ȭ�� �ʱ�ȭ

		if (insec == 0 && inmin == 0 && inhour == 0)//��� 0�̵Ǹ�
			break;//Ÿ�̸�����/
	}

	while (1) {
		if (_kbhit()) {//Ű���� ���� �Է��ϸ�?
			key = _getch();//�Է°��� int������ key�� ����
			if (key == ESC)//�Է°��� ESC���?
				break;//while�� ����
		}
		printf("Ÿ�̸� ����!!!!\n");
		printf("ESC�� ������ ����˴ϴ�.");
		Beep(262, 200);/* �� ���� *///�˶��� ���
		Beep(294, 200); /* �� ���� */
		Beep(330, 200); /* �� ���� */
		Beep(349, 200); /* �� ���� */
		Beep(392, 200); /* �� ���� */
		Beep(440, 200); /* �� ���� */
		Beep(494, 200); /* �� ���� */
		Beep(524, 200); /* �� ���� */
		Sleep(500);
		system("cls");
	}
	return 0;
}
int learn_menu() {
	gotoxy(11, 5);
	printf("==================================\n");
	gotoxy(11, 6);
	printf("         Learning  Planner        \n");
	gotoxy(11, 7);
	printf("==================================\n");
	gotoxy(20, 8);
	printf("1. ��ȹ �Է�\n");
	gotoxy(20, 10);
	printf("2. ��ȹ �޼� üũ\n");
	gotoxy(20, 12);
	printf("3. �޼��� ����\n");
	gotoxy(20, 14);
	printf("4. �ð�ǥ\n");
	gotoxy(20, 16);
	printf("5. ����...\n");

	return 0;
}
void learningplanner()
{
	int b;//b�� ����ڰ� �޴������ϴ� ����
	system("color 3F");
	learn_menu();//�н���ȹǥ�޴����
	b = learnchoice();//Ű���� �޾Ƽ� �޴������� y��ǥ�� b�� ����
	system("cls");
	if (b == 16)
		return;
	switch (b)
	{
	case 8:
		planinsert();//��ȹ�Է�
		break;
	case 10: achievementcheck();//�޼� üũ
		break;
	case 12: achievementrate();//�޼�����
		break;
	case 14: timetable();//�ð�ǥ
		break;
	default:
		break;
	}

}
int planinsertmenu() {
	gotoxy(20, 8);
	printf("1. 1�б� ��ȹ�Է�\n");
	gotoxy(20, 10);
	printf("2. 2�б� ��ȹ�Է�\n");
	gotoxy(20, 12);
	printf("3. ����\n");
	return 0;
}
int planinsert()//��ȹ�Է��Լ�
{
	int a = 0;//�޴����� ����
	PLAN insert;//��ȹ ���� ����ü
	FILE *fpin1 = fopen("plan1.txt", "w+");//1�б� ��ȹ�� ���Ͽ� �����ϱ� ���ؼ� ���� ����������
	FILE *fpin2 = fopen("plan2.txt", "w+");//2�б� ��ȹ�� ���Ͽ� �����ϱ� ���ؼ� ���� ����������
	planinsertmenu();//��ȹ�Է¸޴� ���
	a = threemenu1();//Ű���� �޾Ƽ� �޴������� y��ǥ�� a�� ����
	system("cls");
	if (a == 8)
	{

		printf("1���� ��ȹ :  ");
		scanf("%s", insert.pi1, 50);
		printf("2���� ��ȹ :  ");
		scanf("%s", insert.pi2, 50);
		printf("3���� ��ȹ :  ");
		scanf("%s", insert.pi3, 50);
		printf("4���� ��ȹ :  ");
		scanf("%s", insert.pi4, 50);
		printf("5���� ��ȹ :  ");
		scanf("%s", insert.pi5, 50);
		printf("6���� ��ȹ :  ");
		scanf("%s", insert.pi6, 50);
		printf("7���� ��ȹ :  ");
		scanf("%s", insert.pi7, 50);
		printf("8���� ��ȹ :  ");
		scanf("%s", insert.pi8, 50);
		printf("9���� ��ȹ :  ");
		scanf("%s", insert.pi9, 50);
		printf("10���� ��ȹ : ");
		scanf("%s", insert.pi10, 50);
		printf("11���� ��ȹ : ");
		scanf("%s", insert.pi11, 50);
		printf("12���� ��ȹ : ");
		scanf("%s", insert.pi12, 50);
		printf("13���� ��ȹ : ");
		scanf("%s", insert.pi13, 50);
		printf("14���� ��ȹ : ");
		scanf("%s", insert.pi14, 50);
		printf("15���� ��ȹ : ");
		scanf("%s", insert.pi15, 50);
		printf("16���� ��ȹ : ");
		scanf("%s", insert.pi16, 50);
		fprintf(fpin1, "%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n", insert.pi1, insert.pi2, insert.pi3, insert.pi4, insert.pi5, insert.pi6, insert.pi7, insert.pi8, insert.pi9, insert.pi10, insert.pi11, insert.pi12, insert.pi13, insert.pi14, insert.pi15, insert.pi16);
		//�Է¹��� ���ڿ� ���Ͽ� ����
		fclose(fpin1);
		fclose(fpin2);
		return 0;
	}
	else if (a == 10)
	{
		printf("1���� ��ȹ :  ");
		scanf("%s", insert.pi1, 50);
		printf("2���� ��ȹ :  ");
		scanf("%s", insert.pi2, 50);
		printf("3���� ��ȹ :  ");
		scanf("%s", insert.pi3, 50);
		printf("4���� ��ȹ :  ");
		scanf("%s", insert.pi4, 50);
		printf("5���� ��ȹ :  ");
		scanf("%s", insert.pi5, 50);
		printf("6���� ��ȹ :  ");
		scanf("%s", insert.pi6, 50);
		printf("7���� ��ȹ :  ");
		scanf("%s", insert.pi7, 50);
		printf("8���� ��ȹ :  ");
		scanf("%s", insert.pi8, 50);
		printf("9���� ��ȹ :  ");
		scanf("%s", insert.pi9, 50);
		printf("10���� ��ȹ : ");
		scanf("%s", insert.pi10, 50);
		printf("11���� ��ȹ : ");
		scanf("%s", insert.pi11, 50);
		printf("12���� ��ȹ : ");
		scanf("%s", insert.pi12, 50);
		printf("13���� ��ȹ : ");
		scanf("%s", insert.pi13, 50);
		printf("14���� ��ȹ : ");
		scanf("%s", insert.pi14, 50);
		printf("15���� ��ȹ : ");
		scanf("%s", insert.pi15, 50);
		printf("16���� ��ȹ : ");
		scanf("%s", insert.pi16, 50);
		fprintf(fpin2, "%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n", insert.pi1, insert.pi2, insert.pi3, insert.pi4, insert.pi5, insert.pi6, insert.pi7, insert.pi8, insert.pi9, insert.pi10, insert.pi11, insert.pi12, insert.pi13, insert.pi14, insert.pi15, insert.pi16);
		//�Է¹��� ���ڿ� ���Ͽ� ����
		fclose(fpin1);
		fclose(fpin2);
		return 0;
	}
	else if (a == 12)//3������ ����
		return 0;
	printf("�߸� �Է��ϼ̽��ϴ�.\n");
	fclose(fpin1);
	fclose(fpin2);
	return 0;
}
int achievementcheckmenu() {
	gotoxy(20, 8);
	printf("1. 1�б� �޼�üũ\n");
	gotoxy(20, 10);
	printf("2. 2�б� �޼�üũ\n");
	gotoxy(20, 12);
	printf("3. ����\n");
	return 0;
}
int achievementcheck() {
	int f = 0;
	char c1[10], c2[10], c3[10], c4[10], c5[10], c6[10], c7[10], c8[10], c9[10], c10[10], c11[10], c12[10], c13[10], c14[10], c15[10], c16[10];
	PLAN out;
	FILE *fpout1, *fpout2, *chrate1, *chrate2;
	if ((fpout1 = fopen("plan1.txt", "r")) == NULL) //1�б� �о���� ����������
	{
		system("cls");
		gotoxy(8, 5);
		printf("1�б� ������ �����ϴ�.\n");
		gotoxy(8, 6);
		printf("�������ּ���.\n");
		gotoxy(8, 7);
		printf("3���Ŀ� ����˴ϴ�....\n");
		Sleep(3000);
		return 0;
	}
	if ((fpout2 = fopen("plan2.txt", "r")) == NULL)//2�б� �о���� ����������
	{
		system("cls");
		gotoxy(8, 5);
		printf("2�б� ������ �����ϴ�.\n");
		gotoxy(8, 6);
		printf("�������ּ���.\n");
		gotoxy(8, 7);
		printf("3���Ŀ� ����˴ϴ�....\n");
		Sleep(3000);
		return 0;
	}
	chrate1 = fopen("rate1.txt", "w+");//1�б� �޼�üũ
	chrate2 = fopen("rate2.txt", "w+");//2�б� �޼�üũ
	achievementcheckmenu();//�޼�üũ�޴� ���
	f = threemenu2();//Ű���� �޾Ƽ� �޴������� y��ǥ�� f�� ����
	if (f == 12)
		return 0;
	switch (f) {
	case 8:
		fscanf(fpout1, "%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n", out.pi1, out.pi2, out.pi3, out.pi4, out.pi5, out.pi6, out.pi7, out.pi8, out.pi9, out.pi10, out.pi11, out.pi12, out.pi13, out.pi14, out.pi15, out.pi16);
		system("cls");
		printf("1���� : %s-->�޼������� y / �ƴϸ� n\n", out.pi1);
		scanf(" %s", c1);
		system("cls");
		printf("2���� : %s-->�޼������� y / �ƴϸ� n\n", out.pi2);
		scanf(" %s", c2);
		system("cls");
		printf("3���� : %s-->�޼������� y / �ƴϸ� n\n", out.pi3);
		scanf(" %s", c3);
		system("cls");
		printf("4���� : %s-->�޼������� y / �ƴϸ� n\n", out.pi4);
		scanf(" %s", c4);
		system("cls");
		printf("5���� : %s-->�޼������� y / �ƴϸ� n\n", out.pi5);
		scanf(" %s", c5);
		system("cls");
		printf("6���� : %s-->�޼������� y / �ƴϸ� n\n", out.pi6);
		scanf(" %s", c6);
		system("cls");
		printf("7���� : %s-->�޼������� y / �ƴϸ� n\n", out.pi7);
		scanf(" %s", c7);
		system("cls");
		printf("8���� : %s-->�޼������� y / �ƴϸ� n\n", out.pi8);
		scanf(" %s", c8);
		system("cls");
		printf("9���� : %s-->�޼������� y / �ƴϸ� n\n", out.pi9);
		scanf(" %s", c9);
		system("cls");
		printf("10���� : %s-->�޼������� y / �ƴϸ� n\n", out.pi10);
		scanf(" %s", c10);
		system("cls");
		printf("11���� : %s-->�޼������� y / �ƴϸ� n\n", out.pi11);
		scanf(" %s", c11);
		system("cls");
		printf("12���� : %s-->�޼������� y / �ƴϸ� n\n", out.pi12);
		scanf(" %s", c12);
		system("cls");
		printf("13���� : %s-->�޼������� y / �ƴϸ� n\n", out.pi13);
		scanf(" %s", c13);
		system("cls");
		printf("14���� : %s-->�޼������� y / �ƴϸ� n\n", out.pi14);
		scanf(" %s", c14);
		system("cls");
		printf("15���� : %s-->�޼������� y / �ƴϸ� n\n", out.pi15);
		scanf(" %s", c15);
		system("cls");
		printf("16���� : %s-->�޼������� y / �ƴϸ� n\n", out.pi16);
		scanf(" %s", c16);
		fprintf(chrate1, "%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n", c1, c2, c3, c4, c5, c6, c7, c8, c9, c10, c11, c12, c13, c14, c15, c16);
		//����ڰ� �Է��� �޼�üũ ����
		break;
	case 10:

		fscanf(fpout2, "%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n", out.pi1, out.pi2, out.pi3, out.pi4, out.pi5, out.pi6, out.pi7, out.pi8, out.pi9, out.pi10, out.pi11, out.pi12, out.pi13, out.pi14, out.pi15, out.pi16);
		system("cls");
		printf("1���� : %s-->�޼������� y / �ƴϸ� n\n", out.pi1);
		scanf(" %s", c1);
		system("cls");
		printf("2���� : %s-->�޼������� y / �ƴϸ� n\n", out.pi2);
		scanf(" %s", c2);
		system("cls");
		printf("3���� : %s-->�޼������� y / �ƴϸ� n\n", out.pi3);
		scanf(" %s", c3);
		system("cls");
		printf("4���� : %s-->�޼������� y / �ƴϸ� n\n", out.pi4);
		scanf(" %s", c4);
		system("cls");
		printf("5���� : %s-->�޼������� y / �ƴϸ� n\n", out.pi5);
		scanf(" %s", c5);
		system("cls");
		printf("6���� : %s-->�޼������� y / �ƴϸ� n\n", out.pi6);
		scanf(" %s", c6);
		system("cls");
		printf("7���� : %s-->�޼������� y / �ƴϸ� n\n", out.pi7);
		scanf(" %s", c7);
		system("cls");
		printf("8���� : %s-->�޼������� y / �ƴϸ� n\n", out.pi8);
		scanf(" %s", c8);
		system("cls");
		printf("9���� : %s-->�޼������� y / �ƴϸ� n\n", out.pi9);
		scanf(" %s", c9);
		system("cls");
		printf("10���� : %s-->�޼������� y / �ƴϸ� n\n", out.pi10);
		scanf(" %s", c10);
		system("cls");
		printf("11���� : %s-->�޼������� y / �ƴϸ� n\n", out.pi11);
		scanf(" %s", c11);
		system("cls");
		printf("12���� : %s-->�޼������� y / �ƴϸ� n\n", out.pi12);
		scanf(" %s", c12);
		system("cls");
		printf("13���� : %s-->�޼������� y / �ƴϸ� n\n", out.pi13);
		scanf(" %s", c13);
		system("cls");
		printf("14���� : %s-->�޼������� y / �ƴϸ� n\n", out.pi14);
		scanf(" %s", c14);
		system("cls");
		printf("15���� : %s-->�޼������� y / �ƴϸ� n\n", out.pi15);
		scanf(" %s", c15);
		system("cls");
		printf("16���� : %s-->�޼������� y / �ƴϸ� n\n", out.pi16);
		scanf(" %s", c16);
		fprintf(chrate2, "%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n", c1, c2, c3, c4, c5, c6, c7, c8, c9, c10, c11, c12, c13, c14, c15, c16);
		//����ڰ� �Է��� �޼�üũ ����
		break;
	default:
		break;
	}
	fclose(fpout1);
	fclose(fpout2);
	fclose(chrate1);
	fclose(chrate2);
	return 0;
}
int achievementlookmenu() {
	gotoxy(20, 8);
	printf("1. 1�б� �޼���\n");
	gotoxy(20, 10);
	printf("2. 2�б� �޼���\n");
	gotoxy(20, 12);
	printf("3. ����\n");
	return 0;
}
int achievementrate() {
	int ratesum = 0;//�޼� ���� Ȯ�ο� ������ ����
	int ac;//����� �޴����ú���
	int key;//Ű���� �޾� ����ÿ� ���
	PLAN ch;//�޼�üũ���Ͽ��� �޾ƿ������� ����� ����ü
	FILE *rate1 = fopen("rate1.txt", "r");//1�б� �޼�üũ���� �б�
	FILE *rate2 = fopen("rate2.txt", "r");//2�б� �޼�üũ���� �б�
	achievementlookmenu();//�޴����
	ac = threemenu3();//Ű���� �޾Ƽ� �޴������� y��ǥ�� ac�� ����
	system("cls");
	if (ac == 12)
		return 0;
	switch (ac) {
	case 8:
		fscanf(rate1, "%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n", ch.c1, ch.c2, ch.c3, ch.c4, ch.c5, ch.c6, ch.c7, ch.c8, ch.c9, ch.c10, ch.c11, ch.c12, ch.c13, ch.c14, ch.c15, ch.c16);
		if (strcmp(ch.c1, "y") == 0)//����� y���
			ratesum++;
		if (strcmp(ch.c2, "y") == 0)//����� y���
			ratesum++;
		if (strcmp(ch.c3, "y") == 0)//����� y���
			ratesum++;
		if (strcmp(ch.c4, "y") == 0)//����� y���
			ratesum++;
		if (strcmp(ch.c5, "y") == 0)//����� y���
			ratesum++;
		if (strcmp(ch.c6, "y") == 0)//����� y���
			ratesum++;
		if (strcmp(ch.c7, "y") == 0)//����� y���
			ratesum++;
		if (strcmp(ch.c8, "y") == 0)//����� y���
			ratesum++;
		if (strcmp(ch.c9, "y") == 0)//����� y���
			ratesum++;
		if (strcmp(ch.c10, "y") == 0)//����� y���
			ratesum++;
		if (strcmp(ch.c11, "y") == 0)//����� y���
			ratesum++;
		if (strcmp(ch.c12, "y") == 0)//����� y���
			ratesum++;
		if (strcmp(ch.c13, "y") == 0)//����� y���
			ratesum++;
		if (strcmp(ch.c14, "y") == 0)//����� y���
			ratesum++;
		if (strcmp(ch.c15, "y") == 0)//����� y���
			ratesum++;
		if (strcmp(ch.c16, "y") == 0)//����� y���
			ratesum++;
		gotoxy(20, 10);
		printf("1�б� �޼��� %.2lf%%\n", ((float)ratesum / 16) * 100);//�޼��� �����ֱ�
		fclose(rate1);
		fclose(rate2);
		break;
	case 10:
		fscanf(rate2, "%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n", ch.c1, ch.c2, ch.c3, ch.c4, ch.c5, ch.c6, ch.c7, ch.c8, ch.c9, ch.c10, ch.c11, ch.c12, ch.c13, ch.c14, ch.c15, ch.c16);
		if (strcmp(ch.c1, "y") == 0)//����� y���
			ratesum++;
		if (strcmp(ch.c2, "y") == 0)//����� y���
			ratesum++;
		if (strcmp(ch.c3, "y") == 0)//����� y���
			ratesum++;
		if (strcmp(ch.c4, "y") == 0)//����� y���
			ratesum++;
		if (strcmp(ch.c5, "y") == 0)//����� y���
			ratesum++;
		if (strcmp(ch.c6, "y") == 0)//����� y���
			ratesum++;
		if (strcmp(ch.c7, "y") == 0)//����� y���
			ratesum++;
		if (strcmp(ch.c8, "y") == 0)//����� y���
			ratesum++;
		if (strcmp(ch.c9, "y") == 0)//����� y���
			ratesum++;
		if (strcmp(ch.c10, "y") == 0)//����� y���
			ratesum++;
		if (strcmp(ch.c11, "y") == 0)//����� y���
			ratesum++;
		if (strcmp(ch.c12, "y") == 0)//����� y���
			ratesum++;
		if (strcmp(ch.c13, "y") == 0)//����� y���
			ratesum++;
		if (strcmp(ch.c14, "y") == 0)//����� y���
			ratesum++;
		if (strcmp(ch.c15, "y") == 0)//����� y���
			ratesum++;
		if (strcmp(ch.c16, "y") == 0)//����� y���
			ratesum++;
		gotoxy(20, 10);
		printf("2�б� �޼��� %.2lf%% \n", ((float)ratesum / 16) * 100);//�޼��� �����ֱ�
		fclose(rate1);
		fclose(rate2);
		break;
	default:
		break;
	}
	gotoxy(20, 11);
	printf("ESC�� �Է��Ͻø� ����˴ϴ�.");
	while (1) {
		if (_kbhit()) {//Ű���� ���� �Է��ϸ�?
			key = _getch();//�Է°��� int������ key�� ����
			if (key == ESC)//�Է°��� ESC���?
				return 0;//����
		}
	}
	return 0;
}
int timetablemenu() {
	gotoxy(11, 5);
	printf("==========================================\n");
	gotoxy(11, 6);
	printf("===============time table=================\n");
	gotoxy(11, 7);
	printf("==========================================\n");
	gotoxy(20, 8);
	printf("1.�ð�ǥ �Է�\n");
	gotoxy(20, 10);
	printf("2.�ð�ǥ ����\n");
	gotoxy(20, 12);
	printf("����........");
	return 0;
}
int timetable() {
	int x = 0;
	timetablemenu();//�ð�ǥ�޴����
	x = threemenu4();//Ű���� �޾Ƽ� �޴������� y��ǥ�� x�� ����
	switch (x)
	{
	case 8: timetablein();//�ð�ǥ �Է�
		break;
	case 10: timetablelook();//�ð�ǥ ���
		break;
	case 12:
		return 0;
	default:
		break;
	}
	return 0;
}
int timetablein() {//�ð�ǥ �Է��Լ�

	TT mon, thu, wes, thr, fri;//���Ϻ��� �� ����ü
	FILE *timetable = fopen("timetable.txt", "w+");//�ð�ǥ�� ���Ͽ� �����ϱ� ���� ����������
	system("cls");
	gotoxy(4, 4);
	printf("�����Ϻ��� �ݿ��ϱ����� �ð�ǥ�� �Է��ϼž� �մϴ�.(5��������)\n\n");
	printf("\t\t������1���� : "); scanf("%s", mon.st1);
	printf("\t\t������2���� : "); scanf("%s", mon.st2);
	printf("\t\t������3���� : "); scanf("%s", mon.st3);
	printf("\t\t������4���� : "); scanf("%s", mon.st4);
	printf("\t\t������5���� : "); scanf("%s", mon.st5);
	printf("\t\t������6���� : "); scanf("%s", mon.st6);
	printf("\t\t������7���� : "); scanf("%s", mon.st7);
	printf("\t\t������8���� : "); scanf("%s", mon.st8);
	system("cls");
	gotoxy(0, 6);
	printf("\t\tȭ����1���� : "); scanf("%s", thu.st1);
	printf("\t\tȭ����2���� : "); scanf("%s", thu.st2);
	printf("\t\tȭ����3���� : "); scanf("%s", thu.st3);
	printf("\t\tȭ����4���� : "); scanf("%s", thu.st4);
	printf("\t\tȭ����5���� : "); scanf("%s", thu.st5);
	printf("\t\tȭ����6���� : "); scanf("%s", thu.st6);
	printf("\t\tȭ����7���� : "); scanf("%s", thu.st7);
	printf("\t\tȭ����8���� : "); scanf("%s", thu.st8);
	system("cls");
	gotoxy(0, 6);
	printf("\t\t������1���� : "); scanf("%s", wes.st1);
	printf("\t\t������2���� : "); scanf("%s", wes.st2);
	printf("\t\t������3���� : "); scanf("%s", wes.st3);
	printf("\t\t������4���� : "); scanf("%s", wes.st4);
	printf("\t\t������5���� : "); scanf("%s", wes.st5);
	printf("\t\t������6���� : "); scanf("%s", wes.st6);
	printf("\t\t������7���� : "); scanf("%s", wes.st7);
	printf("\t\t������8���� : "); scanf("%s", wes.st8);
	system("cls");
	gotoxy(0, 6);
	printf("\t\t�����1���� : "); scanf("%s", thr.st1);
	printf("\t\t�����2���� : "); scanf("%s", thr.st2);
	printf("\t\t�����3���� : "); scanf("%s", thr.st3);
	printf("\t\t�����4���� : "); scanf("%s", thr.st4);
	printf("\t\t�����5���� : "); scanf("%s", thr.st5);
	printf("\t\t�����6���� : "); scanf("%s", thr.st6);
	printf("\t\t�����7���� : "); scanf("%s", thr.st7);
	printf("\t\t�����8���� : "); scanf("%s", thr.st8);
	system("cls");
	gotoxy(0, 6);
	printf("\t\t�ݿ���1���� : "); scanf("%s", fri.st1);
	printf("\t\t�ݿ���2���� : "); scanf("%s", fri.st2);
	printf("\t\t�ݿ���3���� : "); scanf("%s", fri.st3);
	printf("\t\t�ݿ���4���� : "); scanf("%s", fri.st4);
	printf("\t\t�ݿ���5���� : "); scanf("%s", fri.st5);
	printf("\t\t�ݿ���6���� : "); scanf("%s", fri.st6);
	printf("\t\t�ݿ���7���� : "); scanf("%s", fri.st7);
	printf("\t\t�ݿ���8���� : "); scanf("%s", fri.st8);
	system("cls");
	fprintf(timetable, "%s %s %s %s %s %s %s %s\n%s %s %s %s %s %s %s %s\n%s %s %s %s %s %s %s %s\n%s %s %s %s %s %s %s %s\n%s %s %s %s %s %s %s %s\n"
		, mon.st1, mon.st2, mon.st3, mon.st4, mon.st5, mon.st6, mon.st7, mon.st8, thu.st1, thu.st2, thu.st3, thu.st4, thu.st5, thu.st6, thu.st7, thu.st8
		, wes.st1, wes.st2, wes.st3, wes.st4, wes.st5, wes.st6, wes.st7, wes.st8, thr.st1, thr.st2, thr.st3, thr.st4, thr.st5, thr.st6, thr.st7, thr.st8
		, fri.st1, fri.st2, fri.st3, fri.st4, fri.st5, fri.st6, fri.st7, fri.st8);
	printf("�ð�ǥ �Է� �Ϸ�!!\n");
	fclose(timetable);
	return 0;
}
int timetablelook() {
	int inkey = 0;//Ű���尪�� �޾Ƽ� �������� �����ϴ� ����
	TT mon, thu, wes, thr, fri;//���Ϻ��� �� ����ü
	FILE *timetablelook;//�ð�ǥ ���� �о���µ� ����ϴ� ����������
	if ((timetablelook = fopen("timetable.txt", "r")) == NULL)
	{
		system("cls");
		gotoxy(8, 5);
		printf("�ð�ǥ ������ �����ϴ�.\n");
		gotoxy(8, 6);
		printf("�������ּ���.\n");
		gotoxy(8, 7);
		printf("3���Ŀ� ����˴ϴ�....\n");
		Sleep(3000);
		return 0;
	}
	fscanf(timetablelook, "%s %s %s %s %s %s %s %s\n%s %s %s %s %s %s %s %s\n%s %s %s %s %s %s %s %s\n%s %s %s %s %s %s %s %s\n%s %s %s %s %s %s %s %s\n"
		, mon.st1, mon.st2, mon.st3, mon.st4, mon.st5, mon.st6, mon.st7, mon.st8, thu.st1, thu.st2, thu.st3, thu.st4, thu.st5, thu.st6, thu.st7, thu.st8
		, wes.st1, wes.st2, wes.st3, wes.st4, wes.st5, wes.st6, wes.st7, wes.st8, thr.st1, thr.st2, thr.st3, thr.st4, thr.st5, thr.st6, thr.st7, thr.st8
		, fri.st1, fri.st2, fri.st3, fri.st4, fri.st5, fri.st6, fri.st7, fri.st8);
	system("cls");
	gotoxy(0, 5);
	printf("����������������������������������������������������������������������");//������������
	gotoxy(0, 6);
	printf("����������    ��    ��    ȭ    ��    ��    ��    ��    ��    ��    ��");
	gotoxy(0, 7);
	printf("����������������������������������������������������������������������");
	gotoxy(0, 8);
	printf("�� 1���æ�%10s��%10s��%10s��%10s��%10s��", mon.st1, thu.st1, wes.st1, thr.st1, fri.st1);
	gotoxy(0, 9);
	printf("����������������������������������������������������������������������");
	gotoxy(0, 10);
	printf("�� 2���æ�%10s��%10s��%10s��%10s��%10s��", mon.st2, thu.st2, wes.st2, thr.st2, fri.st2);
	gotoxy(0, 11);
	printf("����������������������������������������������������������������������");
	gotoxy(0, 12);
	printf("�� 3���æ�%10s��%10s��%10s��%10s��%10s��", mon.st3, thu.st3, wes.st3, thr.st3, fri.st3);
	gotoxy(0, 13);
	printf("����������������������������������������������������������������������");
	gotoxy(0, 14);
	printf("�� 4���æ�%10s��%10s��%10s��%10s��%10s��", mon.st4, thu.st4, wes.st4, thr.st4, fri.st4);
	gotoxy(0, 15);
	printf("����������������������������������������������������������������������");
	gotoxy(0, 16);
	printf("�� 5���æ�%10s��%10s��%10s��%10s��%10s��", mon.st5, thu.st5, wes.st5, thr.st5, fri.st5);
	gotoxy(0, 17);
	printf("����������������������������������������������������������������������");
	gotoxy(0, 18);
	printf("�� 6���æ�%10s��%10s��%10s��%10s��%10s��", mon.st6, thu.st6, wes.st6, thr.st6, fri.st6);
	gotoxy(0, 19);
	printf("����������������������������������������������������������������������");
	gotoxy(0, 20);
	printf("�� 7���æ�%10s��%10s��%10s��%10s��%10s��", mon.st7, thu.st7, wes.st7, thr.st7, fri.st7);
	gotoxy(0, 21);
	printf("����������������������������������������������������������������������");
	gotoxy(0, 22);
	printf("�� 8���æ�%10s��%10s��%10s��%10s��%10s��", mon.st8, thu.st8, wes.st8, thr.st8, fri.st8);
	gotoxy(0, 23);
	printf("����������������������������������������������������������������������");
	gotoxy(0, 24);
	printf("ESC�� �����ø� ����˴ϴ�.");
	while (1) {
		if (_kbhit()) {//Ű���� ���� �Է��ϸ�?
			inkey = _getch();//�Է°��� int������ key�� ����
			if (inkey == ESC)//�Է°��� ESC���?
				break;//while�� ����
		}

	}
	fclose(timetablelook);
	return 0;
}//====================================================-sungjae
