
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

//ALl the global variables and the composite data types will be declared here
typedef struct{
	char name[50];
	int bus_num;
	int num_of_seats;
}pd;

//function prototypes to be used
void reservation(void);							//main reservation function
void viewdetails(void);							//view details of all the bus
void cancel(void);								
void printticket(char name[],int,int,float);	//print ticket 
void specificbus(int);						//print data related to specific train
float charge(int,int);							//charge automatically w.r.t number of seats and bus
void login();


/******************************************FUNCTION DECLARATION**********************************************************/

int main()

{
		system("cls"); 
	printf("\t\t=================================================\n");
	printf("\t\t|                                               |\n");
	printf("\t\t|        -----------------------------          |\n");
	printf("\t\t|           BUS TICKET RERVS. SYSTEM            |\n");
	printf("\t\t|        -----------------------------          |\n");
	printf("\t\t|                                               |\n");
	printf("\t\t|                                               |\n");
	printf("\t\t|                                               |\n");
	printf("\t\t|              BROUGHT TO YOU BY                |\n");
	printf("\t\t|           |  Shisadi and Binita  |            |\n");
	printf("\t\t|                                               |\n");
	printf("\t\t=================================================\n\n\n");
		
	    
	printf(" \n Press any key to continue:");
	
	getch();	
    system("cls");
	login();
	int menu_choice,choice_return;
	start:
	system("cls");
	printf("\n=================================\n");
	printf("    BUS RESERVATION SYSTEM");
	printf("\n=================================");
	printf("\n1>> Reserve A Ticket");
	printf("\n------------------------");
	printf("\n2>> View All Available Bus");
	printf("\n------------------------");
	printf("\n3>> Cancel Reservation");
	printf("\n------------------------");
	printf("\n4>> Exit");
	printf("\n------------------------");
	printf("\n\n-->");
	scanf("%d",&menu_choice);
	switch(menu_choice)
	{
		case 1:
			reservation();		//Function still not added
			break;
		case 2:
			viewdetails();
			printf("\n\nPress any key to go to Main Menu..");
			getch();
			break;
		case 3:
			cancel();
			//function not added. code has been removed due to some errors
			break;
		case 4:
			return(0);
		default:
			printf("\nInvalid choice");
	}
	goto start;
	return(0);
}

/*********************************************VIEWDETAILS()*************************************************/

//The function is yet not completed, need more details to be added!
//timings of the bus are still missing 

void viewdetails(void)
{
	system("cls");
	printf("-----------------------------------------------------------------------------");	
	printf("\nBs.No\tName\t\t\tDestinations\t\tCharges\t\tTime\n");
	printf("-----------------------------------------------------------------------------");
	printf("\n1001\tBiratnaga Express\tKathma to Biratnaga\tRs.1000\t\t9am");
	printf("\n1002\tBiratnaga Express\tBiratnaga To Kathma\tRs.1000\t\t12pm");
	printf("\n1003\tN.P  Express\t\tKathma To N.P\t\tRs.1000\t\t8am");
	printf("\n1004\tN.P  Express\t\tN.P To Kathma\t\tRs.1000\t\t11am");
	printf("\n1005\tNepa City Express\tKathma To Butwal.\tRs.1000\t\t7am");
	printf("\n1006\tNepa City Express\tButwal. To Kathma\tRs.1000\t\t9.30am");
    printf("\n1007\tKohalpur Express\tKathma To Kohalpur..\tRs.1000\t\t1pm");	
    printf("\n1008\tKohalpur Express\tKohalpur.. To Kathma\tRs.1000\t\t4pm");
    printf("\n1009\tThimi Express\t\tKathma To Thimi\t\tRs.1000\t\t3.35pm");
    printf("\n1010\tThimi Express\t\tThimi To Kathma\t\tRs.1000\t\t4.15pm");
    
}

/*********************************************RESERVATION()*************************************************/

void reservation(void)
{
	char confirm;
	int i=0;
	float charges;
	pd passdetails;
	FILE *fp;
	fp=fopen("seats_reserved.txt","a");
	system("cls");
	
	printf("\nEnter Your Name:> ");
	fflush(stdin);
	gets(passdetails.name);
	//error here have to take input of the name 
	printf("\nEnter Number of seats:> ");
	scanf("%d",&passdetails.num_of_seats);
	printf("\n\n>>Press Enter To View Available bus<< ");
	getch();
	system("cls");
	viewdetails();
	printf("\n\nEnter bus number:> ");
	start1:
	scanf("%d",&passdetails.bus_num);
	if(passdetails.bus_num>=1001 && passdetails.bus_num<=1010)
	{
		charges=charge(passdetails.bus_num,passdetails.num_of_seats);
		printticket(passdetails.name,passdetails.num_of_seats,passdetails.bus_num,charges);		
	}
	else
	{
		printf("\nInvalid bus Number! Enter again--> ");
		goto start1;
	}
	
	printf("\n\nConfirm Ticket (y/n):>");
	start:
	scanf(" %c",&confirm);
	if(confirm == 'y')
	{
		fprintf(fp,"%s\t\t%d\t\t%d\t\t%.2f\n",&passdetails.name,passdetails.num_of_seats,passdetails.bus_num,charges);
		printf("==================");
		printf("\n Reservation Done\n");
		printf("==================");
		printf("\nPress any key to go back to Main menu");
	}
	else
	{
		if(confirm=='n'){
			printf("\nReservation Not Done!\nPress any key to go back to  Main menu!");
		}
		else
		{
			printf("\nInvalid choice entered! Enter again-----> ");
			goto start;
		}
	}
	fclose(fp);
	getch();
}

/*********************************************CHARGE()*************************************************/

float charge(int bus_num,int num_of_seats)
{
		if (bus_num==1001)
	{
		return(1000.0*num_of_seats);
	}
	if (bus_num==1002)
	{
		return(1000.0*num_of_seats);
	}
	if (bus_num==1003)
	{
		return(1000.0*num_of_seats);
	}
	if (bus_num==1004)
	{
		return(1000.0*num_of_seats);
	}
	if (bus_num==1005)
	{
		return(1000.0*num_of_seats);
	}
	if (bus_num==1006)
	{
		return(1000.0*num_of_seats);
	}
	if (bus_num==1007)
	{
		return(1000.0*num_of_seats);
	}
	if (bus_num==1008)
	{
		return(1000.0*num_of_seats);
	}
	if (bus_num==1009)
	{
		return(1000.0*num_of_seats);
	}
	if (bus_num==1010)
	{
		return(1000.0*num_of_seats);
	}
}


/*********************************************PRINTTICKET()*************************************************/

void printticket(char name[],int num_of_seats,int bus_num,float charges)
{
	system("cls");
	printf("-------------------\n");
	printf("\tTICKET\n");
	printf("-------------------\n\n");
	printf("Name:\t\t\t%s",name);
	printf("\nNumber Of Seats:\t%d",num_of_seats);
	printf("\nBus Number:\t\t%d",bus_num);
	specificbus(bus_num);
	printf("\nCharges:\t\t%.2f",charges);
}

/*********************************************SPECIFICBUS()*************************************************/

void specificbus(int bus_num)
{
	
	if (bus_num==1001)
	{
		printf("\nBus:\t\t\tBiratnaga Express");
		printf("\nDestination:\t\tKathma to Biratnaga");
		printf("\nDeparture:\t\t9am ");
	}
	if (bus_num==1002)
	{
		printf("\nBus:\t\t\tBiratnaga Express");
		printf("\nDestination:\t\tBiratnaga To Kathma");
		printf("\nDeparture:\t\t12pm");
	}
	if (bus_num==1003)
	{
		printf("\nBus:\t\t\tN.P  Express");
		printf("\nDestination:\t\tKathma To N.P");
		printf("\nDeparture:\t\t8am");
	}
	if (bus_num==1004)
	{
		printf("\nBus:\t\t\tN.P  Express");
		printf("\nDestination:\t\tN.P To Kathma");
		printf("\nDeparture:\t\t11am ");
	}
	if (bus_num==1005)
	{
		printf("\nBus:\t\t\tNepa City Express");
		printf("\nDestination:\t\tKathma To Butwal.");
		printf("\nDeparture:\t\t7am");
	}
	if (bus_num==1006)
	{
		printf("\nBus:\t\t\tNepa City Express");
		printf("\nDestination:\t\tButwal. To Kathma");
		printf("\nDeparture:\t\t9.30am ");
	}
	if (bus_num==1007)
	{
		printf("\nBus:\t\t\tKohalpur Express");
		printf("\nDestination:\t\tKathma To Kohalpur..");
		printf("\nDeparture:\t\t1pm ");
	}
	if (bus_num==1008)
	{
		printf("\nBus:\t\t\tKohalpur Express");
		printf("\n Destination:\t\tKohalpur.. To Kathma");
		printf("\nDeparture:\t\t4pm ");
	}
	if (bus_num==1009)
	{
		printf("\nBus:\t\t\tThimi Express");
		printf("\nDestination:\t\tKathma To Thimi");
		printf("\nDeparture:\t\t3.35pm ");
	}
	if (bus_num==1010)
	{
		printf("\nBus:\t\t\tThimi Express");
		printf("\nDestination:\t\t\tThimi To Kathma");
		printf("\nDeparture:\t\t1.15 ");
	}
}

void login()
{
	int a=0,i=0;
    char uname[10],c=' '; 
    char pword[10],code[10];
    char user[10]="user";
    char pass[10]="pass";
    do
{
	
    printf("\n  =======================  LOGIN FORM  =======================\n  ");
    printf(" \n                       ENTER USERNAME:-");
	scanf("%s", &uname); 
	printf(" \n                       ENTER PASSWORD:-");
	while(i<10)
	{
	    pword[i]=getch();
	    c=pword[i];
	    if(c==13) break;
	    else printf("*");
	    i++;
	}
	pword[i]='\0';
	//char code=pword;
	i=0;
	//scanf("%s",&pword); 
		if(strcmp(uname,"user")==0 && strcmp(pword,"pass")==0)
	{
	printf("  \n\n\n       WELCOME TO OUR SYSTEM !! YOUR LOGIN IS SUCCESSFUL");
	printf("\n\n\n\t\t\t\tPress any key to continue...");
	getch();//holds the screen
	break;
	}
	else
	{
		printf("\n        SORRY !!!!  LOGIN IS UNSUCESSFUL");
		a++;
		
		getch();//holds the screen
		system("cls");
	}
}
	while(a<=2);
	if (a>2)
	{
		printf("\nSorry you have entered the wrong username and password for four times!!!");
		
		getch();
		
		}
		system("cls");	
}

void cancel(void)   /* Sorry this function does not work. Coding is not completed. Codes have been removed due to some errors  */
{

	system("cls");
	int busnum;
	printf("-----------------------\n");
		printf("Enter the bus number: \n");
			printf("-----------------------\n");
		fflush(stdin);
		scanf("%i",&busnum);
		printf("\n\nCancelled");  
		getch();
}


              


