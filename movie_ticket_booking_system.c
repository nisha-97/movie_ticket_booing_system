#include<string.h>
#include<stdio.h>
#include<stdlib.h>
void login()
{
int a=0,i=0;
char uname[10],c=' ';
char pword[10],code[10];
char user[10]="priya";
char pass[10]="priya123";
do
{
printf("\n ++++++++++++++++++++++++++++++ LOGIN FIRST ++++++++++++++++++++++++++++++ ");
printf(" \n\n ENTER USERNAME:-");
scanf("%s", &uname);
printf(" \n\n ENTER PASSWORD:-");
while(i<10)
{

pword[i]=getch();//to hide the input from user getch is used,it takes single character ata a time,getch returns ascii value
c=pword[i];
if(c=='\r') break;//to see if user has pressed enter key
else printf("*");
i++;
}
pword[i]='\0';
//char code=pword;
i=0;//back to 0
if(strcmp(uname,"priya")==0 && strcmp(pword,"priya123")==0)
{
printf(" \n\n\n \t!!!! WELCOME TO OUR BOOKING SYSTEM !!!!\n\t\t LOGIN IS SUCCESSFUL");
printf("\n\n\n\t\t\t\tPress any key to continue...");
getch();//holds the screen
break;
}
else
{
printf("\n SORRY !!!! LOGIN IS UNSUCESSFUL");
a++;
getch();//holds the screen
}
}

while(a<=2);
if (a>2)
{
printf("\nSorry you have entered the wrong username and password for three times!!!");
getch();
}
//system("cls");
}
struct book
{
char code[20];
char name[20];
char date[20];
int cost;
}b;
struct transaction
{
char no_of_person[30];
char cname[30];
char mname[30];

char percost[30];
char totalcost[30];
char mobileno[30];
}t;
int seat = 60 ;
void insert_details();//for inserting movie details
void viewAll(); // for view all data
void find(); // for finding data
void book_ticket(); //for booking tickets
void old_record(); //for view old recorrds of users,booked tickets
void main()
{
login();
int ch;
do{
printf("\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++");
printf("\n");
printf("\n\t ***MOVIE TICKET BOOKING*** ");
printf("\n");
printf("\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++");
printf("\nEnter 1 To Insert Movie");
printf("\nEnter 2 To View All Movie");
printf("\nEnter 3 To Find Movie ");
printf("\nEnter 4 To Book Tickets");
printf("\nEnter 5 To View All Transactions");
printf("\nEnter 0 To Exit ");
printf("\n\nEnter your Choice ::");
scanf("%d",&ch);
system("cls");
switch (ch)
{
case 1 :
insert_details();
break;
case 2:
viewAll();
break;
case 3:
find();
break;
case 4:
book_ticket();
break;

case 5:
old_record();
break;
case 0:
exit(0);
break;
default:
printf("Wrong choice !");
break;
}
}while(ch!=0);
}
void insert_details()
{
FILE *fp;
struct book b;
printf("\nEnter Movie Code :- ");
fflush(stdin);
scanf(" %[^\n]s",b.code);
fflush(stdin);
//scanf("%s",b.code);
printf("Enter Movie Name :- ");
scanf(" %[^\n]s",b.name);

//scanf("%s",b.name);

printf("Enter Show Date:- ");
scanf(" %[^\n]s",b.date);
//scanf("%s",b.date);
fflush(stdin);
printf("Enter Ticket Price:- ");
scanf("%d",&b.cost);
fp=fopen("movierecords.txt","a");
if(fp == NULL)
{
printf("FIle not Found");
}
else
{
fprintf(fp,"\n %s %s %s %d",b.code,b.name,b.date,b.cost);//to insert in file,a means append
printf("Recorded Successfully");
}
printf("\n");
fclose(fp);
//system("cls");
}
void find() //find details
{
int flag=0;
struct book b;
FILE *fp;
char ch[20];
printf("Enter Movie Code :");
scanf("%s",ch);
fp = fopen("movierecords.txt","r");
if(fp == NULL)
{
printf("file does not found !");
exit(1);
}
else
{
while(getc(fp) != EOF)
{
fscanf(fp,"%s %s %s %d",b.code,b.name,b.date,&b.cost);
if(strcmp(b.code,ch) == 0)
{
    flag=1;
printf("\n Record Found\n");
printf("\n\t\tCode ::%s",b.code);
printf("\n\t\tMovie Name ::%s",b.name);
printf("\n\t\tMovie Date ::%s",b.date);
printf("\n\t\tPrice Of Ticket ::%d",b.cost);

}
}
}
if(flag==0)
printf("MOVIE NOT FOUND\n");
getch();
fclose(fp);
//system("cls");
}
void viewAll()
{
char ch;
FILE *fp;
fp = fopen("movierecords.txt","r");
if(fp == NULL)
{
printf("file does not found !");
exit(1);
}
else
{
//system("cls");
char movie_code[]="MOVIE_CODE";
char movie_name[]="MOVIE_NAME";
char show_date[]="SHOW_DATE";
char price[]="PRICE";
//system("cls");
printf(" %10s \t|| %10s \t|| %10s \t|| %10s \n",movie_code,movie_name,show_date,price);
printf("**********************************************************************************\n");
while(getc(fp)!=EOF)
{
fscanf(fp,"%s %s %s %d",b.code,b.name,b.date,&b.cost);
printf("%10s \t||%10s \t\t|| \t%10s \t||%10d \n",b.code,b.name,b.date,b.cost);
}
}
fclose(fp);
}
//for ticket booking
void book_ticket()
{
struct book b;
FILE *fp;
FILE *ufp;
int total_seat,total_amount;
char name[20],mobile[20];
char ch; //used in display all movies
char movie_code[20]; //for searching
// disply all moives by default for movie code
fp = fopen("movierecords.txt","r");
if(fp == NULL)
{
printf("file does not found !");
exit(1);
}
else
{
//system("cls");
char movie_code[]="MOVIE_CODE";
char movie_name[]="MOVIE_NAME";
char show_date[]="SHOW_DATE";
char price[]="PRICE";
system("cls");
printf(" %10s \t|| %10s \t|| %10s \t|| %10s \n",movie_code,movie_name,show_date,price);
printf("**********************************************************************************\n");
while(getc(fp)!=EOF)
{
fscanf(fp,"%s %s %s %d",b.code,b.name,b.date,&b.cost);
printf("%10.9s \t||%10.9s \t\t|| \t%10.16s \t||%10.4d \n",b.code,b.name,b.date,b.cost);
}
}
fclose(fp);
//display ends
printf("\n For Booking ticket, Choose Movie(Enter Movie Code )\n");
printf("\n Enter Movie Code :");
scanf("%s",movie_code);
//system("clear");
fp = fopen("movierecords.txt","r");
if(fp == NULL)
{
printf("file does not found !");
exit(1);

}
else
{
while(getc(fp) != EOF)
{
fscanf(fp,"%s %s %s %d",b.code,b.name,b.date,&b.cost);
if(strcmp(b.code,movie_code) == 0)
{
printf("\n Record Found\n");
printf("\n\t\tCode ::%s",b.code);
printf("\n\t\tMovie name ::%s",b.name);
printf("\n\t\tdate name ::%s",b.date);
printf("\n\t\tPrice of ticket::%d",b.cost);
break;
}
}
}
printf("\n* Fill Deatails *");
printf("\n your Name :");
scanf("%s",name);
printf("\n Mobile Number :");
scanf("%s",mobile);
printf("\n Total Number Of Tickets :");
scanf("%d",&total_seat);
total_amount = b.cost * total_seat;
printf("\n ENJOY MOVIE \n");
printf("\n\t\tName : %s",name);
printf("\n\t\tMobile Number : %s",mobile);
printf("\n\t\tMovie Name : %s",b.name);
printf("\n\t\tTotal Seats : %d",total_seat);
printf("\n\t\tCost Per Ticket : %d",b.cost);
printf("\n\t\tTotal Amount : %d",total_amount);
ufp=fopen("customerrecords.txt","a");
if(ufp == NULL)
{
printf("FIle not Found");
}
else
{
fprintf(ufp,"\n %s %s %d %s %d %d",name,mobile,total_seat,b.name,b.cost,total_amount);//to write in customer file
printf("\n Record inserted Sucessfully to the old record file");
}
printf("\n");
fclose(ufp);
fclose(fp);
}
//for view all user transections
void old_record()
{
char ch;
FILE *fp;
//system("clear");
fp = fopen("customerrecords.txt","r");
if(fp == NULL)
{
printf("file does not found !");
exit(1);
}
else
{
//system("cls");
char mobile_no[]="MOBILE_NO";
char movie_name[]="MOVIE_NAME";
char name[]="NAME";
char percost[]="PER_COST";
char total_cost[]="TOTAL_COST";
char no_of_person[]="NO_OF_PERSON";
printf("\n");
printf(" %10s \t|| %10s || %10s \t|| \t%10s \t|| %10s \t|| \t%10s \
\n",name,mobile_no,no_of_person,movie_name,percost,total_cost);
printf("********************************************************************************************************************************\n");
while(getc(fp)!=EOF)
{
fscanf(fp,"%s %s %s %s %s %s",t.cname,t.mobileno,t.no_of_person,t.mname,t.percost,t.totalcost);
printf("%10s \t|| % 10s \t|| %10s \t\t|| %10s \t\t||%10s \t\t|| %10s \
\n",t.cname,t.mobileno,t.no_of_person,t.mname,t.percost,t.totalcost);
}
}
fclose(fp);
}

