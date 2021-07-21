// Projekt tablicowanie funkcji
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
#include <string.h>
#include <windows.h>

void menu(void);
// W tej wersji programu uzyto dwie osobne tablice znakow,
// w wersji docelowej naglowek moze miec postac
// void tablicowanie1(char tabWyniki[][3][10], int *pN);
void tablicowanie1(char xLan[100][10],char funLan[100][10], int *pN);
void tablicowanie2(char xLan[100][10],char funLan[100][10], int *pN);
void przegladanieTabFun(char xLan[100][10],char funLan[100][10], int N);
int nalezyDoDziedziny(double x);
double obliczFun( double x);
void gotoxy(short x, short y);
void funDrukLan(double,double,double,double,char[100][3][10]);
double wczytajLiczbeDouble();
int wczytajLiczbeInt();
void wczytywanieDanychWariant1(double *a, double *b, double *delta, int *n);
void wczytywanieDanychWariant2(double *a, double *b, double *delta, int *n);


int main()
{
int j;
int tab[20]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
int start, koniec;
start=0;
//funDrukLan();
// Przyklad u¿ycia funkcji gotoxy() ustawiaj¹cej kursor
/*
while(1)
{
koniec=start+4;
system("cls");
for(j=start;j<koniec;j++)
{
gotoxy(20,5+j%2);
printf(" tab[%d]=%d",j,tab[j]);
}
start++;
getchar();
}*/
while(1){
menu();}// wywolanie funkcji menu
return 0;
}

double wczytajLiczbeDouble()
{
	double liczba=0;
	double cyfra;
	char wczyt[8];
	int ipi;
	int k;
	int kropki;
	int test;
	int rzad=1;
	do
	{
		kropki=0;
		k=1;
		
		for(ipi=0;ipi<8;ipi++)
		{
			wczyt[ipi]=getch();
			printf("%c",wczyt[ipi]);
		}
		for(ipi=0;ipi<8;ipi++)
		{
			test=wczyt[ipi];
			if((test==45||test==43)&&(ipi==0))
			{
				//printf("\n Wszystko jest git.");
				//printf("%d",test);
			}
			else if(test==46||test==44)
			{
				kropki++;
			}
			else if(test>=48&&test<=57)
			{
				//printf("\n Wszystko jest git.");
				//printf("%d",test);
			}
			else
			{
				printf("\n %d",test);
				printf("\n Blad wprowadzania danych");
				k=0;
			}
		}
		if(kropki>1)
		{
			printf("\n Blad wprowadzania danych");
			k=0;
		}
	}while(k==0);
	for(ipi=7;ipi>=0;ipi--)
	{
		cyfra=0;
		test=wczyt[ipi];
		if(test>=48&&test<=57)
		{
			if(test==48)cyfra=0;
			else if(test==49)cyfra=1;
			else if(test==50)cyfra=2;
			else if(test==51)cyfra=3;
			else if(test==52)cyfra=4;
			else if(test==53)cyfra=5;
			else if(test==54)cyfra=6;
			else if(test==55)cyfra=7;
			else if(test==56)cyfra=8;
			else if(test==57)cyfra=9;
			else rzad=rzad/10;
			liczba=liczba+(cyfra*rzad);
			rzad*=10;
		}
		if(test==46)
		{
			liczba=liczba/rzad;
			rzad=1;
		}
		if(test==45)liczba=liczba*(-1);
	}
	printf("\n %lf",liczba);
	return liczba;
}

int wczytajLiczbeInt()
{
	int liczba=0;
	int cyfra;
	char wczyt[8];
	int ipi;
	int k;
	int kropki;
	int test;
	
	do
	{
		kropki=0;
		k=1;
		
		for(ipi=0;ipi<8;ipi++)
		{
			wczyt[ipi]=getch();
			printf("%c",wczyt[ipi]);
		}
		for(ipi=0;ipi<8;ipi++)
		{
			test=wczyt[ipi];
			if((test==45||test==43)&&(ipi==0))
			{
				//printf("\n Wszystko jest git.");
				//printf("%d",test);
			}
			else if(test==46||test==44)
			{
				printf("\n Blad wprowadzania danych");
				k=0;
			}
			else if(test>=48&&test<=57)
			{
				//printf("\n Wszystko jest git.");
				//printf("%d",test);
			}
			else
			{
				printf("\n %d",test);
				printf("\n Blad wprowadzania danych");
				k=0;
			}
		}
		if(k==0)printf("\n");
	}while(k==0);
	for(ipi=7;ipi>=0;ipi--)
	{
		cyfra=0;
		int rzad=1;
		test=wczyt[ipi];
		if(test>=48&&test<=57)
		{
			if(test==48)cyfra=0;
			if(test==49)cyfra=1;
			if(test==50)cyfra=2;
			if(test==51)cyfra=3;
			if(test==52)cyfra=4;
			if(test==53)cyfra=5;
			if(test==54)cyfra=6;
			if(test==55)cyfra=7;
			if(test==56)cyfra=8;
			if(test==57)cyfra=9;
			liczba=liczba+(cyfra*rzad);
			rzad*=10;
		}
		if(test==45)liczba=liczba*(-1);
	}
	
	return liczba;
}

void wczytywanieDanychWariant1(double *a,double *b,double *delta,int *n)
{
	int k;
	do
	{
		printf("\n Podaj liczbe a: ");
		*a=wczytajLiczbeDouble();
		printf("\n Podaj liczbe b: ");
		*b=wczytajLiczbeDouble();	
	}while(*a>*b);
	printf("\n Podaj liczbe delta: ");
	*delta=wczytajLiczbeDouble();
	printf("\n Podaj liczbe N z przedzialu 2 do 100: ");
	//n=wczytajLiczbeInt();
	do{
		k=scanf("%d",&n);
	}while(k==0||*n>100||*n<2);
	
}

void wczytywanieDanychWariant2(double *a,double *b,double *delta,int *n)
{
	int k;
	do
	{
		printf("\n Podaj liczbe a: ");
		*a=wczytajLiczbeDouble();
		printf("\n Podaj liczbe b: ");
		*b=wczytajLiczbeDouble();	
	}while(*a>*b);
	printf("\n Podaj liczbe delta: ");
	*delta=wczytajLiczbeDouble();
	printf("\n Podaj liczbe N z przedzialu 2 do 100: ");
	//n=wczytajLiczbeInt();
	do{
		k=scanf("%d",&n);
	}while(k==0||*n>100||*n<2);
	
}

void menu(void)
{ 
char ch;

char xLan[100][10],funLan[100][10];
int N;
system("cls");
int i;
for (i=0;i<8;i++)
printf("\n");
printf(" ============================");
printf("\n 1.Tablicowanie w zadanym przedziale [a,b] w N puktach");
printf("\n 2.Tablicowanie od zadanego punktu a w N punktach co krok delta <- Nic nie bylo o tym w wytycznych wiec tego nie ma");
printf("\n 3.Wyjscie lub ESC");
printf("\n ===========================");
printf("\n Wybierz opcje :");
fflush(stdin);
do {
ch=getch(); }
while ( ch!='1' && ch!= '2'&& ch!='3'&& ch!=27);
if (ch=='1') {
printf("1");
getchar();
system("cls");
tablicowanie1(xLan,funLan, &N);
przegladanieTabFun(xLan,funLan,N);
}
if (ch=='2'){
printf("2");
getchar();
system("cls");
tablicowanie2(xLan,funLan, &N);
przegladanieTabFun(xLan,funLan, N);
}
if (ch==27 || ch=='3') {
printf("3");
getchar();
exit(0);
}


}

void gotoxy(short x, short y) { //definicja funkcji gotoxy()
COORD pos ={x,y};
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}


void tablicowanie1(char xLan[100][10],char funLan[100][10], int *pN)
{ 
	double *a,*b,fx,*delta,x;
	int i,k,*N;
	
	char tabLan[100][3][10];// deklaracja tablicy znakowej zawieraj¹cej 100 wierszy i 3 kolumny po 10 znakow
	printf("\n Wybrano tablicowanie wariant 1");
	printf("\n Tablicowanie w przedziale [a,b] w N punktach");
	printf("\n Skok tablicowania delta jest wynikowy");
	/*
	do{
	do{
	printf("\n Podaj poczatek przedzialu tablicowania a=");
	k=scanf("%lf", &a);
	if (k==0) printf("\n Blad formatu ");
	fflush(stdin);
	}
	while(k==0);
	do {
	printf("\n Podaj koniec przedzialu tablicowania b=");
	k=scanf("%lf", &b);
	if (k==0) printf("\n Blad formatu ");
	fflush(stdin);
	}
	while(k==0);
	if (a>=b) printf("\n Blad: a nie moze byæ wieksze od b");
	}
	while (a>=b);
	do{
	printf("\n Podaj liczbe punktow tablicowania N ( N>1 i N<100");
	printf("\n N=");
	k=scanf("%d", &N);
	if (k==0) printf("\n Blad formatu ");
	fflush(stdin);
	}*/
	wczytywanieDanychWariant1(&a,&b,&delta,&N);
	/*printf("\n %lf",*a);
	printf("\n %lf",*b);
	printf("\n %lf",*delta);
	printf("\n %d",*N);*/
	*delta=(*b-*a)/(*N-1);
	for (i=0;i<*N;i++)
	{
	x=*a+i**delta;
	
	if (nalezyDoDziedziny(x)==1)
	{
		fx=obliczFun(x);
		sprintf(funLan[i], "%8.2f",fx);
	}
	else strcpy(funLan[i], "Poza dziedzina");
	*pN=*N;
	funDrukLan(*a,*b,*delta,fx,tabLan);
	}
}

void tablicowanie2(char xLan[100][10],char funLan[100][10], int *pN)
{
printf("\n Wybrano tablicowanie wariant 2");
fflush(stdin);
getchar();
}

int nalezyDoDziedziny(double x)
{
	if (x>0) return 1;
	else return 0;
}

double obliczFun( double x)
{
	double wynik=0;
	int pip;
	int k;
	k=scanf("%d",&k);
	for(pip=1;pip<k;pip++)
	{
		wynik=wynik+((exp(pip*x)+pow(x,2)-log(pip))/(pow(x,3)-pip));
	}
	return wynik;
}


void przegladanieTabFun(char xLan[100][10],char funLan[100][10],int N)
{
	int i;
	int start,koniec;
	char ch1,ch2;
	char napis[30]=" x[i] y[i] ";
	system("cls");
	printf("\n Funkcja przegladanieTabFun");
	fflush(stdin);
	printf("\n");
	for(i=0;i<25;i++) printf("\315");
	printf("\n %s", napis );
	printf("\n");
	for(i=0;i<25;i++) printf("\315");
	for (i=0; i<N;i++) {
	printf("\n\272 %.8s \272 %.8s \272", xLan[i], funLan[i]);
	getchar();
	}
	getchar();
}


void funDrukLan(double a,double b,double delta,double wynik,char tabLan[100][3][10])
{
	char temp[10];
	sprintf(temp,"%8.2f",a);// przeksztalcenie liczby typu double na lancuch znakow
	strcpy(tabLan[0][0],temp);//zapis do kolumny 0
	strcat(tabLan[0][0],",");//zapis do kolumny 0
	sprintf(temp,"%8.2f",b);
	strcpy(tabLan[0][0],temp);//zapis do kolumny 0
	sprintf(temp,"%8.2f",delta);
	strcpy(tabLan[0][1],temp);//zapis do kolumny 1
	sprintf(temp,"%8.2f",wynik);
	strcpy(tabLan[0][2],temp);//zapis do kolumny 2
	printf(" tabLan[0][0]=%s",tabLan[0][0]) ;
	printf("\n tabLan[0][1]=%s",tabLan[0][1]) ;
	printf("\n tabLan[0][2]=%s",tabLan[0][2]) ;
	getchar();
}
