////////////////////////////GROCERY PROJECT BY MR.KHAN///////////////////////
#include"stdio.h"
#include"conio.h"
#include"string.h"
#include"dos.h"

char Pname[][20]={"suger","milk","vegetable masala","washing powder","salt","chilli","poha","oil","tooth pest","rice","vinegar","soap","shabu","rava","paneer","aata","dishwosher","pickle","ghee","dal"};
int Pprice[]={40,70,20,118,40,500,40,120,75,60,57,186,90,85,74,205,56,150,320,77};
char Pq[][20]={"Kg","Ltr","Packet","Kg","Packet","Kg","Kg","Kg","Packet","Kg","Bottle","Bundle","Kg","Kg","Kg","Kg","Bunch","Kg","Kg","Kg"};
int sugerP=40,milkP=70,vegetable_masalaP=20,washing_powderP=118,saltP=40,chilliP=500,pohaP=40,oilP=120,tooth_pestP=75,riceP=60,vinegarP=57,soapP=186,shabuP=90,ravaP=85,paneerP=74,aataP=205,dishwosherP=56,pickleP=150,gheeP=320,dalP=77;

void Psearch();
void product_list();
void discount_details();
void product_input();
void gen_bill();
void Home_interface();
int size=0;

void main()
{
	int ch;
	clrscr();

	size=sizeof(Pname)/sizeof(Pname[0]);

	home:
	Home_interface();

	printf("\n\n\t   Enter Your choice : ");
	scanf("%d",&ch);

	if(ch==1)
	{
	  product_list();
	  goto home;
	}
	else if(ch==2)
	{
	   Psearch();
	   goto home;
	}
	else if(ch==3)
	{
		gen_bill();
		goto home;
	}
	else if(ch==4)
	{
		discount_details();
		goto home;
	}
	else if(ch==5)
	{
		printf("\n\t   Please Wait, Exiting.....");
		delay(1200);
		goto exit;
	}
	else
	{
		printf("\n\t   Invalid Choice....!");
	}


getch();
exit:
}

void Home_interface()
{
	clrscr();
	printf("\n\t***************************************************************");
	printf("\n\t||                                                           ||");
	printf("\n\t||   	       WELCOME TO AMAN KIRANA SHOP		     ||");
	printf("\n\t||                                                           ||");
	printf("\n\t***************************************************************\n");

	printf("\n\t   ||-----MENUES:-----------------------------------------||");
	printf("\n\t   ||                                                  	  ||");
	printf("\n\t   || PRESS 1 : TO SEE THE PRODUCT AND THIER PRICE LIST.  ||");
	printf("\n\t   ||							  ||");
	printf("\n\t   || PRESS 2 : To SEARCH PRICE OF PRODUCT.	   	  ||");
	printf("\n\t   ||                                                  	  ||");
	printf("\n\t   || PRESS 3 : To GENERATE GROCERY BILL.                 ||");
	printf("\n\t   ||	  		 		                  ||");
	printf("\n\t   || PRESS 4 : TO KNOW DISCOUNT RATE.			  ||");
	printf("\n\t   || 					                  ||");
	printf("\n\t   || PRESS 5 :	TO EXIT					  ||");
	printf("\n\t   ||-----------------------------------------------------||");

}

//void product_input()

void Psearch()
{
	char p[30];
	int i,choice;
	clrscr();

	again:
	clrscr();
	printf("\n\n\t______________SERCH A PRODUCT______________");
	printf("\n\n\tENTER THE PRODUCT : ");
	fflush(stdin);
	gets(p);
	printf("\n\t");

	for(i=0;i<size;i++)
	{
		if(strcmp(p,Pname[i])==0)
		{
			delay(1000);
			printf("\n\t|--------------------|------------|-------------|");
			printf("\n\t|  PRODUCT           |   PRICE    |   QUANTITY  |");
			printf("\n\t|--------------------|------------|-------------|");
			printf("\n\t|						|");
			printf("\n\t|--------------------|------------|-------------|");
			gotoxy(9,11);
			printf("|  %s",p);
			gotoxy(30,11);
			printf("|    %d Rs",Pprice[i]);
			gotoxy(43,11);
			printf("|  Per %s",Pq[i]);
			break;
		}

		if(i==size-1 && strcmp(p,Pname[i])!=0)
		{
			delay(1000);
			printf("\n\n\t Sorry......!");
			printf("\n\n\t Product Is Not Available");
		}
	}

	delay(2000);
	printf("\n\n\n\n\tPRESS 1 : For YES or PRESS 2 : For NO");
	printf("\n\n\tDo You Want To Search Again : ");
	scanf("%d",&choice);

	if(choice==1)
	{
		goto again;
	}
	else
	return;

}


void product_list()
{

	int i,x,y;
	clrscr();

	x=6,y=6;
	size=sizeof(Pname)/sizeof(Pname[i]);

	printf("\n\t\t    AMAN KIRANA STORE PRODUCT RATES ");


	printf("\n\t______________________________________________________________");
	printf("\n\t|   PRODUCT			 PRICE	       QUANTITY      |");
	printf("\n\t|____________________________________________________________|\n");

       for(i=0;i<size;i++)
       {
	gotoxy(x,y);
	printf("\t|    %s ",Pname[i]);
	gotoxy(x+36,y);
	printf("%d",Pprice[i]);
	gotoxy(x+39,y);
	printf(" Rs");
	gotoxy(x+50,y);
	printf("Per %s",Pq[i]);
	gotoxy(x+64,y);
	printf("|");
	y++;
       }
       getch();

}

void gen_bill()
{
char product[100][20];
int quantity[20];
int i,j,choice;
double t=0;
int x=6,y=7;
int p=0;
float discount=0;
long double total=0;


///Bill data input///
	clrscr();
	printf("\n\n\t_________________Enter your Purchased Products_________________");

	for(i=0;choice!=0;i++)
	{
		agian:
		printf("\n\n\tEnter Product Name : ");
		fflush(stdin);
		gets(product[i]);

		for(j=0;j<size;j++)
		{
			if(strcmp(product[i],Pname[j])==0)
			{
				break;
			}
			if( strcmp(product[i],Pname[j])!=0 && j==size-1 )
			{
				printf("\n\n\tThis Product is Not Availabl ....!");
				delay(1000);
				goto agian;
			}
		}
		p++;

		again1:
		printf("\n\n\tEnter Quantity OF Product : ");
		scanf("%d",&quantity[i]);

		if(quantity[i]<1)
		{
			 printf("\n\n\tInvalid Quantitiy...!");
			 delay(1000);
			 goto again1;
		}

		printf("\n\tIf You want to Add another one product then enter 1\n\tif you want to generate Bill then enter 0.\n\n\tEnter Your Choice = ");
		scanf("%d",&choice);
		printf("\n\t");

		if(choice==0)
		{
			printf("\n\tPlease wait , Generating Bill......");
			delay(1500);
			break;
		}
	}


//// Bill Generation /////
clrscr();

printf("\n\n\t|------------------AMAN KIRANA STRORE------------------------|\n");
printf("\t|		       			       	             |");
printf("\n\t|  PRODUCT		QAUNTITY	        PRICE        |");
printf("\n\t|------------------------------------------------------------|");

for(i=0;i<p;i++)
{
	if(strcmp(product[i],"suger")==0)
	{
		t=quantity[i]*sugerP;
		total+=t;
		fflush(stdout);
		printf("\n\t|                                               	     |");
		printf("\n\t|                                               	     |");
		gotoxy(x,y-1);
		printf("\n\t|   %s",product[i]);

		gotoxy(x+26,y) ;	//gotoxy(32,7);
		printf("\t %d Kg",quantity[i]);

		gotoxy(x+52,y)  ;	//gotoxy(58,7);
		printf("%l.2f",t);

	}

	if(strcmp(product[i],"milk")==0)
	{
		 t=quantity[i]*milkP;
		 total+=t;
		 fflush(stdout);
		 printf("\n\t|                                               	     |");
		 printf("\n\t|                                               	     |");

		 gotoxy(x,y-1);
		 printf("\n\t|   %s",product[i]);

		 gotoxy(x+26,y);
		 printf("  %d Ltr",quantity[i]);

		 gotoxy(x+52,y);
		 printf("%.2lf",t);
	}

	if(strcmp(product[i],"vegetable masala")==0)
	{
	    t=quantity[i]*vegetable_masalaP;
	    total+=t;
	    fflush(stdout);
	    printf("\n\t|                                               	     |");
	    printf("\n\t|                                               	     |");

		gotoxy(x,y-1);
		 printf("\n\t|   %s",product[i]);

		 gotoxy(x+26,y);
		 printf("  %d Packet",quantity[i]);

		 gotoxy(x+52,y);
		 printf("%.2lf",t);
	}

	if(strcmp(product[i],"washing powder")==0)
	{
		t=quantity[i]*washing_powderP;
		total+=t;
		fflush(stdout);
		printf("\n\t|                                               	     |");
		printf("\n\t|                                               	     |");

		 gotoxy(x,y-1);
		 printf("\n\t|   %s",product[i]);

		 gotoxy(x+26,y);
		 printf("  %d Packet",quantity[i]);

		 gotoxy(x+52,y);
		 printf("%.2lf",t);
	}

	if(strcmp(product[i],"salt")==0)
	{
		t=quantity[i]*saltP;
		total+=t;
		fflush(stdout);
		printf("\n\t|                                               	     |");
		printf("\n\t|                                               	     |");

		 gotoxy(x,y-1);
		 printf("\n\t|   %s",product[i]);

		 gotoxy(x+26,y);
		 printf("  %d Packet",quantity[i]);

		 gotoxy(x+52,y);
		 printf("%.2lf",t);
	}

	if(strcmp(product[i],"chilli")==0)
	{
		t=quantity[i]*chilliP;
		total+=t;
		fflush(stdout);
		printf("\n\t|                                               	     |");
		printf("\n\t|                                               	     |");

		 gotoxy(x,y-1);
		 printf("\n\t|   %s",product[i]);

		 gotoxy(x+26,y);
		 printf("  %d Packet",quantity[i]);

		 gotoxy(x+52,y);
		 printf("%.2lf",t);
	}

	if(strcmp(product[i],"poha")==0)
	{
		t=quantity[i]*pohaP;
		total+=t;
		fflush(stdout);
		printf("\n\t|                                               	     |");
		printf("\n\t|                                               	     |");

		 gotoxy(x,y-1);
		 printf("\n\t|   %s",product[i]);

		 gotoxy(x+26,y);
		 printf("  %d Kg",quantity[i]);

		 gotoxy(x+52,y);
		 printf("%.2lf",t);
	}

	if(strcmp(product[i],"oil")==0)
	{
		t=quantity[i]*oilP;
		total+=t;
		fflush(stdout);
		printf("\n\t|                                               	     |");
		printf("\n\t|                                               	     |");

		 gotoxy(x,y-1);
		 printf("\n\t|   %s",product[i]);

		 gotoxy(x+26,y);
		 printf("  %d Kg",quantity[i]);

		 gotoxy(x+52,y);
		 printf("%.2lf",t);

	}

	if(strcmp(product[i],"tooth pest")==0)
	{
		t=quantity[i]*tooth_pestP;
		total+=t;
		fflush(stdout);
		printf("\n\t|                                               	     |");
		printf("\n\t|                                               	     |");

		 gotoxy(x,y-1);
		 printf("\n\t|   %s",product[i]);

		 gotoxy(x+26,y);
		 printf("  %d Packet",quantity[i]);

		 gotoxy(x+52,y);
		 printf("%.2lf",t);
	}

	if(strcmp(product[i],"rice")==0)
	{
		t=quantity[i]*riceP;
		total+=t;
		fflush(stdout);
		printf("\n\t|                                               	     |");
		printf("\n\t|                                               	     |");

		 gotoxy(x,y-1);
		 printf("\n\t|   %s",product[i]);

		 gotoxy(x+26,y);
		 printf("  %d Kg",quantity[i]);

		 gotoxy(x+52,y);
		 printf("%.2lf",t);
	}

	if(strcmp(product[i],"vinegar")==0)
	{
		t=quantity[i]*vinegarP;
		total+=t;
		fflush(stdout);
		printf("\n\t|                                               	     |");
		printf("\n\t|                                               	     |");

		 gotoxy(x,y-1);
		 printf("\n\t|   %s",product[i]);

		 gotoxy(x+26,y);
		 printf("  %d Packet",quantity[i]);

		 gotoxy(x+52,y);
		 printf("%.2lf",t);
	}


	if(strcmp(product[i],"soap")==0)
	{
		t=quantity[i]*soapP;
		total+=t;
		fflush(stdout);
		printf("\n\t|                                               	     |");
		printf("\n\t|                                               	     |");

		 gotoxy(x,y-1);
		 printf("\n\t|   %s",product[i]);

		 gotoxy(x+26,y);
		 printf("  %d Bundle",quantity[i]);

		 gotoxy(x+52,y);
		 printf("%.2lf",t);
	}

	if(strcmp(product[i],"shabu")==0)
	{
		t=quantity[i]*shabuP;
		total+=t;
		fflush(stdout);
		printf("\n\t|                                               	     |");
		printf("\n\t|                                               	     |");

		 gotoxy(x,y-1);
		 printf("\n\t|   %s",product[i]);

		 gotoxy(x+26,y);
		 printf("  %d Kg",quantity[i]);

		 gotoxy(x+52,y);
		 printf("%.2lf",t);
	}

	if(strcmp(product[i],"rava")==0)
	{
		t=quantity[i]*ravaP;
		total+=t;
		fflush(stdout);
		printf("\n\t|                                               	     |");
		printf("\n\t|                                               	     |");

		gotoxy(x,y-1);
		 printf("\n\t|   %s",product[i]);

		 gotoxy(x+26,y);
		 printf("  %d Kg",quantity[i]);

		 gotoxy(x+52,y);
		 printf("%.2lf",t);
	}

	if(strcmp(product[i],"paneer")==0)
	{
		t=quantity[i]*paneerP;
		total+=t;
		fflush(stdout);
		printf("\n\t|                                               	     |");
		printf("\n\t|                                               	     |");

		 gotoxy(x,y-1);
		 printf("\n\t|   %s",product[i]);

		 gotoxy(x+26,y);
		 printf("  %d Kg",quantity[i]);

		 gotoxy(x+52,y);
		 printf("%.2lf",t);
	}

	if(strcmp(product[i],"aata")==0)
	{
		t=quantity[i]*aataP;
		total+=t;
		fflush(stdout);
		printf("\n\t|                                               	     |");
		printf("\n\t|                                               	     |");

		 gotoxy(x,y-1);
		 printf("\n\t|   %s",product[i]);

		 gotoxy(x+26,y);
		 printf("  %d Packet",quantity[i]);

		 gotoxy(x+52,y);
		 printf("%.2lf",t);
	}

	if(strcmp(product[i],"dishwosher")==0)
	{
		t=quantity[i]*dishwosherP;
		total+=t;
		fflush(stdout);
		printf("\n\t|                                               	     |");
		printf("\n\t|                                               	     |");

		 gotoxy(x,y-1);
		 printf("\n\t|   %s",product[i]);

		 gotoxy(x+26,y);
		 printf("  %d Bunch",quantity[i]);

		 gotoxy(x+52,y);
		 printf("%.2lf",t);
	}

	if(strcmp(product[i],"pickle")==0)
	{
		t=quantity[i]*pickleP;
		total+=t;
		fflush(stdout);
		printf("\n\t|                                               	     |");
		printf("\n\t|                                               	     |");

		 gotoxy(x,y-1);
		 printf("\n\t|   %s",product[i]);

		 gotoxy(x+26,y);
		 printf("  %d Kg",quantity[i]);

		 gotoxy(x+52,y);
		 printf("%.2lf",t);
	}

	if(strcmp(product[i],"ghee")==0)
	{
		t=quantity[i]*gheeP;
		total+=t;
		fflush(stdout);
		printf("\n\t|                                               	     |");
		printf("\n\t|                                               	     |");

		 gotoxy(x,y-1);
		 printf("\n\t|   %s",product[i]);

		 gotoxy(x+26,y);
		 printf("  %d Kg",quantity[i]);

		 gotoxy(x+52,y);
		 printf("%.2lf",t);
	}

	if(strcmp(product[i],"dal")==0)
	{
		t=quantity[i]*dalP;
		total+=t;
		fflush(stdout);
		printf("\n\t|                                               	     |");
		printf("\n\t|                                               	     |");

		 gotoxy(x,y-1);
		 printf("\n\t|   %s",product[i]);

		 gotoxy(x+26,y);
		 printf("  %d Kg",quantity[i]);

		 gotoxy(x+52,y);
		 printf("%.2lf",t);
	}

       y=y+2;
}

	if(total<=1000)
	{
		discount=0.0;
	}
	else if( (total>=5000) && (total<10000) )
	{
		discount=(float)total * 0.05;
	}
	else if( (total>=10000) && (total<15000) )
	{
		discount=(float)total * 0.1;
	}
	else if(total>=15000)
	{
		discount=(float)total * 0.15;
	}

	printf("\n\t|------------------------------------------------------------|");
	printf("\n\t|                                               	     |");
	printf("\n\t|------------------------------------------------------------|");
	printf("\n\t|                                               	     |");
	printf("\n\t|------------------------------------------------------------|");
	printf("\n\t|                                               	     |");
	printf("\n\t|------------------------------------------------------------|");

	gotoxy(x,y-1);
	printf("\n\t|  TOTAL PRODUCTS : %d",p);

	gotoxy(x+37,y);
	printf("TOTAL AMOUNT : %.2Lf",total);

	gotoxy(x+70,y+1);
	printf("\n\t|\t\t\t\t      DISCOUNT : %.2lf",discount);

	gotoxy(x+70,y+3);
	printf("\n\t|\t\t\t\tPAYABLE AMOUNT : %.Lf ",total-discount);


getch();
return;
}

void discount_details()
{
	clrscr();
	printf("\n\n\tFOLLOWING ARE OUR DISCOUNT OFFERS :");

	printf("\n\n\t____________________________________________________");
	printf("\n\t|			 			    |");
	printf("\n\t|       LESS THAN 1000 Rs BILL 0 % DISCOUNT	    |");
	printf("\n\t|___________________________________________________|");
	printf("\n\t|						    |");
	printf("\n\t|	GREATER THAN 5000 Rs BILL 5 % DISCOUNT      |");
	printf("\n\t|___________________________________________________|");
	printf("\n\t|						    |");
	printf("\n\t|	GREATER THAN 10,000 Rs BILL 10 % DISCOUNT   |");
	printf("\n\t|___________________________________________________|");
	printf("\n\t|						    |");
	printf("\n\t|	GREATER THAN 15,000 Rs BILL 15 % DISCOUNT   |");
	printf("\n\t|___________________________________________________|\n\t");
	getch();
}
