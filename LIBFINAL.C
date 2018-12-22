
#include<stdio.h>
#include<conio.h>
#include<malloc.h>
#include<string.h>
struct address
{
	int hno,pin;
	char street[20],city[10],state[15];
};

struct employee
{
	struct address adr;
	int eid;
	char p_name[15],desig[15],ename[15],doj[10],dor[10],dob[10];
	struct employee *nexte,*preve;
};
struct infrastructure
{
	int ano,nof_i;
	char aname[10],specs[30];
	struct infrastructure *nexti,*previ;
};
struct books
{
	int bno,nof_b,edit;
	char yop[10];
	char author[20],bname[30],publisher[30];
	struct books *nextb,*prevb;
};
typedef struct employee emp;
typedef struct infrastructure infra;
typedef struct books book;
emp *lpe,*rpe,*nodee;
infra *lpi,*rpi,*nodei;
book *lpb,*rpb,*nodeb;
static int flag=0;
char ch;

void insert();
void update();
void del();
void search();
void show();
int main()
 {
	int choice,choice2;
	char ch;
	lpe=(emp*)malloc(sizeof(emp));
	lpe->nexte=NULL;
	lpe->preve=NULL;
	lpi=(infra*)malloc(sizeof(infra));
	lpi->nexti=NULL;
	lpi->previ=NULL;
	lpb=(book*)malloc(sizeof(book));
	lpb->nextb=NULL;
	lpb->prevb=NULL;
	printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
	printf("                      Welcome to The Library ERP System\n");
	printf("\n^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
	aa:
	printf("*******************************************\n");
	printf("We have three sections kindly choose one\n1.Books\n2.Employees\n3.Infrastructure ");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
			bo:
			printf("--------------------\n");
			printf("Books Section\n");
			flag=1;
			printf("\nYou can do the following operations:");
			printf("\n1.Insert a new entry\n2.Update a record\n3.Delete a record\n4.Show all the records\n5.Search an entry ");
			scanf("%d",&choice2);
			switch(choice2)
			{
				case 1:
					insert();
					break;
				case 2:
					update();
					break;
				case 3:
					del();
					break;
				case 4:
					show();
					break;
				case 5:
					search();
					break;

				default:

					printf("\nEnter a valid option\n");
					goto bo;
					break;
			}
			break;
		case 2:
			eo:

			printf("--------------------\n");
			printf("Employees Section\n");
			flag=2;
			printf("\nYou can do the following operations:");
			printf("\n1.Insert a new entry\n2.Update a record\n3.Delete a record\n4.Show all the records\n5.Search an entry ");
			scanf("%d",&choice2);
				switch(choice2)
			{
				case 1:
					insert();
					break;
				case 2:
					update();
					break;
				case 3:
					del();
					break;
				case 4:
					show();
					break;
				case 5:
					//search();
					break;
				default:
					printf("\nEnter a valid option\n");
					goto eo;
					break;
			}
			break;
		case 3:
			io:
			printf("--------------------\n");
			printf("Infrastructure Section\n");
			flag=3;
			printf("\nYou can do the following operations:");
			printf("\n1.Insert a new entry\n2.Update a record\n3.Delete a record\n4.Show all the records\n5.Search an entry\n");
			scanf("%d",&choice2);
			switch(choice2)
			{
				case 1:
					insert();
					break;
				case 2:
					update();
					break;
				case 3:
					del();
					break;
				case 4:
					show();
					break;
				case 5:
					search();
					break;
				default:
					printf("\nEnter a valid option\n");
					goto io;
					break;
			}
			break;
		default:
			printf("\nPlease Enter a valid option\n");
			goto aa;
			break;
	}
	printf("\nDo you want to perform some more operations?\n Y for yes\n N for no\n");
	fflush(stdin);
	scanf("%c",&ch);
	printf("\n");
	
	if(ch=='Y'||ch=='y')
	{
		goto aa;
	}
	return(0);
 }
void insert()
 {
	cc:
	switch(flag)
	{
		case 1:
			nodeb=lpb;
			if(nodeb->nextb==NULL)
			{
				nodeb->nextb=(book*)malloc(sizeof(book));
				nodeb->nextb->prevb=nodeb;
				nodeb=nodeb->nextb;
				printf("\nEnter Book No. : ");
				scanf("%d",&nodeb->bno);
				fflush(stdin);
				printf("\nEnter Book Name : ");
				gets(nodeb->bname);
				fflush(stdin);
				printf("\nEnter No. Of Books : ");
				scanf("%d",&nodeb->nof_b);
				fflush(stdin);
				printf("\nEnter Author Name : ");
				fflush(stdin);
				gets(nodeb->author);
				fflush(stdin);
				printf("\nEnter Publisher Name : ");
				gets(nodeb->publisher);
				fflush(stdin);
				printf("\nEnter Edition Of The Book : ");
				scanf("%d",&nodeb->edit);
				fflush(stdin);
				printf("\nEnter The Year Of Publication : ");
				scanf("%s",&nodeb->yop);
				fflush(stdin);
				nodeb->nextb=NULL;
				rpb=nodeb;
			}
			else
			{
				while(nodeb->nextb)
				{
					nodeb=nodeb->nextb;
				}
				if(nodeb->nextb==NULL)
				{
					nodeb->nextb=(book*)malloc(sizeof(book));
					nodeb->nextb->prevb=nodeb;
					nodeb=nodeb->nextb;
					printf("\nEnter Book No. : ");
					scanf("%d",&nodeb->bno);
					fflush(stdin);
					printf("\nEnter Book Name : ");
					gets(nodeb->bname);
					fflush(stdin);
					printf("\nEnter No. Of Books : ");
					scanf("%d",&nodeb->nof_b);
					fflush(stdin);
					printf("\nEnter Author Name : ");
					fflush(stdin);
					gets(nodeb->author);
					fflush(stdin);
					printf("\nEnter Publisher Name : ");
					gets(nodeb->publisher);
					fflush(stdin);
					printf("\nEnter Edition Of The Book : ");
					scanf("%d",&nodeb->edit);
					fflush(stdin);
					printf("\nEnter Year Of Publication : ");
					scanf("%s",&nodeb->yop);
					fflush(stdin);
					nodeb->nextb=NULL;
					rpb=nodeb;
				}
			}
			break;
		case 2:
			nodee=lpe;
			if(nodee->nexte==NULL)
			{
				nodee->nexte=(emp*)malloc(sizeof(emp));
				nodee->nexte->preve=nodee;
				nodee=nodee->nexte;
				printf("\nEnter Employee ID. : ");
				scanf("%d",&nodee->eid);
				fflush(stdin);
				printf("\nEnter Employee Name : ");
				gets(nodee->ename);
				fflush(stdin);
				printf("\nEnter Date Of Birth : ");
				gets(nodee->dob);
				fflush(stdin);
				printf("\nEnter Date Of Joining : ");
				gets(nodee->doj);
				fflush(stdin);
				printf("\nEnter Date Of Retirement : ");
				gets(nodee->dor);
				fflush(stdin);
				printf("\nEnter Father's Name : ");
				gets(nodee->p_name);
				fflush(stdin);
				printf("\nEnter Designation : ");
				gets(nodee->desig);
				fflush(stdin);
				printf("\nEnter House No. : ");
				scanf("%d",&nodee->adr.hno);
				fflush(stdin);
				printf("\nEnter Street Name : ");
				gets(nodee->adr.street);
				fflush(stdin);
				printf("\nEnter  City : ");
				gets(nodee->adr.city);
				fflush(stdin);
				printf("\nEnter State : ");
				gets(nodee->adr.state);
				fflush(stdin);
				printf("\nEnter Pincode :");
				scanf("%d",&nodee->adr.pin);
				nodee->nexte=NULL;
				rpe=nodee;
			}
			else
			{
				while(nodee->nexte)
				{
					nodee=nodee->nexte;
				}
				if(nodee->nexte==NULL)
				{
					nodee->nexte=(emp*)malloc(sizeof(emp));
					nodee->nexte->preve=nodee;
					nodee=nodee->nexte;
					printf("\nEnter Employee ID. : ");
					scanf("%d",&nodee->eid);
					fflush(stdin);
					printf("\nEnter Employee Name : ");
					gets(nodee->ename);
					fflush(stdin);
					printf("\nEnter Date Of Birth : ");
					gets(nodee->dob);
					fflush(stdin);
					printf("\nEnter Date Of Joining : ");
					gets(nodee->doj);
					fflush(stdin);
					printf("\nEnter Date Of Retirement :");
					gets(nodee->dor);
					fflush(stdin);
					printf("\nEnter Father's Name : ");
					gets(nodee->p_name);
					fflush(stdin);
					printf("\nEnter Designation : ");
					gets(nodee->desig);
					fflush(stdin);
					printf("\nEnter House No. : ");
					scanf("%d",&nodee->adr.hno);
					fflush(stdin);
					printf("\nEnter Street Name : ");
					gets(nodee->adr.street);
					fflush(stdin);
					printf("\nEnter  City :");
					gets(nodee->adr.city);
					fflush(stdin);
					printf("\nEnter State : ");
					gets(nodee->adr.state);
					fflush(stdin);
					printf("\nEnter Pincode : ");
					scanf("%d",&nodee->adr.pin);
					nodee->nexte=NULL;
					rpe=nodee;
				}
			}
			 break;
		case 3:
			nodei=lpi;
			if(nodei->nexti==NULL)
			{
				nodei->nexti=(infra*)malloc(sizeof(infra));
				nodei->nexti->previ=nodei;
				nodei=nodei->nexti;
				printf("\nEnter Article No. : ");
				scanf("%d",&nodei->ano);
				fflush(stdin);
				printf("\nEnter Article Name : ");
				gets(nodei->aname);
				fflush(stdin);
				printf("\nEnter No. Of Items : ");
				scanf("%d",&nodei->nof_i);
				fflush(stdin);
				printf("\nEnter Article Specifications : ");
				gets(nodei->specs);
				nodei->nexti=NULL;
				rpi=nodei;
			}
			else
			{
				while(nodei->nexti)
				{
					nodei=nodei->nexti;
				}
				if(nodei->nexti==NULL)
				{
					nodei->nexti=(infra*)malloc(sizeof(infra));
					nodei->nexti->previ=nodei;
					nodei=nodei->nexti;
					printf("\nEnter Article No. : ");
					scanf("%d",&nodei->ano);
					fflush(stdin);
					printf("\nEnter Article Name : ");
					gets(nodei->aname);
					fflush(stdin);
					printf("\nEnter No. Of Items : ");
					scanf("%d",&nodei->nof_i);
					fflush(stdin);
					printf("\nEnter Article Specifications : ");
					gets(nodei->specs);
					nodei->nexti=NULL;
					rpi=nodei;
				}
			}
			break;
	}
	printf("\nDo you want to add more nodes?\n Y for yes \n N for no\n");
	fflush(stdin) ;
	scanf("%c",&ch);
	
	if(ch=='Y'||ch=='y')
	{
		goto cc;
	}
 }
void update()
{
	int ref_no;
	switch(flag)
	{
		case 1:
			nodeb=lpb;
			printf("Enter the Book No. of the record you want to update :\n");
			scanf("%d",&ref_no);
			while(nodeb->bno!=ref_no)
			{
				if(nodeb==NULL)
				{
				 printf("\nThe record does not exist\n");
				 break;
				}
				else
				nodeb=nodeb->nextb;
			}
			if(nodeb->bno==ref_no)
			{
				printf("Enter the new values for the record with Book No. %d\n",ref_no);
				fflush(stdin);
				printf("\nEnter Book Name : ");
				gets(nodeb->bname);
				fflush(stdin);
				printf("\nEnter No. Of Books : ");
				scanf("%d",&nodeb->nof_b);
				fflush(stdin);
				printf("\nEnter Author Name : ");
				gets(nodeb->author);
				fflush(stdin);
				printf("\nEnter Publisher Name : ");
				gets(nodeb->publisher);
				fflush(stdin);
				printf("\nEnter Edition Of The book : ");
				scanf("%d",&nodeb->edit);
				fflush(stdin);
				printf("\nEnter Year Of Publication : ");
				scanf("%s",&nodeb->yop);
				fflush(stdin);
				printf("\n\nNOTE :\nRecord has been successfully updated.\n");
			}
			break;
		case 2:
			nodee=lpe;
			printf("Enter the Employee Id of the record you want to update : \n");
			scanf("%d",&ref_no);
			while(nodee->eid!=ref_no)
			{
			if(nodee==NULL)
				{
				 printf("\nThe record does not exist\n");
				 break;
				}
			 else	nodee=nodee->nexte;
			}
			if(nodee->eid==ref_no)
			{
				printf("Enter the new values for the record with Employee Id %d\n",ref_no);
					fflush(stdin);
					printf("\nEnter Employee Name : ");
					gets(nodee->ename);
					fflush(stdin);
					printf("\nEnter Date Of Birth : ");
					gets(nodee->dob);
					fflush(stdin);
					printf("\nEnter Date Of Joining : ");
					gets(nodee->doj);
					fflush(stdin);
					printf("Enter Date Of Retirement : ");
					gets(nodee->dor);
					fflush(stdin);
					printf("\nEnter Father's Name : ");
					gets(nodee->p_name);
					fflush(stdin);
					printf("\nEnter Designation : ");
					gets(nodee->desig);
					fflush(stdin);
					printf("\nEnter House No. : ");
					scanf("%d",&nodee->adr.hno);
					fflush(stdin);
					printf("\nEnter Street Name : ");
					gets(nodee->adr.street);
					fflush(stdin);
					printf("\nEnter  City :");
					gets(nodee->adr.city);
					fflush(stdin);
					printf("\nEnter State : ");
					gets(nodee->adr.state);
					fflush(stdin);
					printf("\nEnter Pincode : ");
					scanf("%d",&nodee->adr.pin);
					printf("\n\nNOTE :\nRecord has been successfully updated.\n");

								}
			break;
		case 3:
			nodei=lpi;
			printf("Enter the Article No. of the record you want to update : \n");
			scanf("%d",&ref_no);
			while(nodei->ano!=ref_no)
			{
				if(nodei==NULL)
				{
				 printf("\nThe record does not exist\n");
				 break;
				}
			 else
				nodei=nodei->nexti;
			}
			if(nodei->ano==ref_no)
			{
				printf("Enter the new values for the record with Article No. %d\n",ref_no);
				fflush(stdin);
				printf("\nEnter Article Name : ");
				gets(nodei->aname);
				fflush(stdin);
				printf("\nEnter No. Of Items : ");
				scanf("%d",&nodei->nof_i);
				fflush(stdin);
				printf("\nEnter Article Specifications : ");
				gets(nodei->specs);
				printf("\n\nNOTE :\nRecord has been successfully updated.\n");


			}
			break;
	}

}
void show()
 {
   int ch;
	ss:
	switch(flag)
	 {

	   case 1:
	    dd:
	       if(nodeb==NULL)
	       {printf("There is no node to display in database");}
	       else{
	       printf("\n1.View database from first record \n2.View database from last record\n");
	       fflush(stdin);
	       scanf("%d",&ch);
	       switch(ch)
		{
		  case 1:
		   nodeb=lpb->nextb;

		   while(nodeb)
		    { printf("\n");
		      printf("BOOKNO.          : %d\n",nodeb->bno);
		      printf("BOOK NAME        : %s\n",nodeb->bname);
		      printf("NUMBER OF BOOKS  : %d\n",nodeb->nof_b);
		      printf("AUTHOR NAME      : %s\n",nodeb->author);
		      printf("PUBLISHER NAME   : %s\n",nodeb->publisher);
		      printf("BOOK EDITION     : %d\n",nodeb->edit);
		      printf("PUBLICATION YEAR : %s\n\n",nodeb->yop);
		      printf("/////////////////////////////////////\n");
		      nodeb=nodeb->nextb;
		    }
		   break;

		 case 2:
		  nodeb=rpb;
		  while(nodeb->prevb)
		   {  printf("\n");
		      printf("BOOKNO.          : %d\n",nodeb->bno);
		      printf("BOOK NAME        : %s\n",nodeb->bname);
		      printf("NUMBER OF BOOKS  : %d\n",nodeb->nof_b);
		      printf("AUTHOR NAME      : %s\n",nodeb->author);
		      printf("PUBLISHER NAME   : %s\n",nodeb->publisher);
		      printf("BOOK EDITION     : %d\n",nodeb->edit);
		      printf("PUBLICATION YEAR : %s\n\n",nodeb->yop);
		      printf("/////////////////////////////////////\n");
		      nodeb=nodeb->prevb;
		    }
		  break;

		  default:
		    printf("\nPlease enter a valid option.\n");
		    goto dd;
		    break;
	       }	}
	       break;

	   case 2:
	    ee:
	       if(nodee==NULL)
	       {printf("There is nonode to display in database");}

	       printf("\n1.View database from first record \n2.View database from last record\n");	       fflush(stdin);
	       scanf("%d",&ch);
	       switch(ch)
		{
		  case 1:
		   nodee=lpe->nexte;
		   while(nodee)
		    {   printf("\n");
			printf("EMPLOYEE ID.       : %d\n",nodee->eid);
			printf("EMPLOYEE NAME      : %s\n",nodee->ename);
			printf("DATE OF BIRTH      : %s\n",nodee->dob);
			printf("DATE OF JOINING    : %s\n",nodee->doj);
			printf("DATE Of RETIREMENT : %s\n",nodee->dor);
			printf("FATHER'S NAME      : %s\n",nodee->p_name);
			printf("DESIGNATION        : %s\n",nodee->desig);
			printf("HOUSE NO.          : %d\n",nodee->adr.hno);
			printf("STREET NAME        : %s\n",nodee->adr.street);			fflush(stdin);
			printf("CITY               : %s\n",nodee->adr.city);
			printf("STATE              : %s\n",nodee->adr.state);
			printf("PINCODE            : %d\n",nodee->adr.pin);
			printf("/////////////////////////////////////\n");
			nodee=nodee->nexte;
		    }
		   break;

		  case 2:
		   nodee=rpe;
		   while(nodee->preve)
		    {
		     printf("\n");
		     printf("EMPLOYEE ID.       : %d\n",nodee->eid);
		     printf("EMPLOYEE NAME      : %s\n",nodee->ename);
		     printf("DATE OF BIRTH      : %s\n",nodee->dob);
		     printf("DATE OF JOINING    : %s\n",nodee->doj);
		     printf("DATE Of RETIREMENT : %s\n",nodee->dor);
		     printf("FATHER'S NAME      : %s\n",nodee->p_name);
		     printf("DESIGNATION        : %s\n",nodee->desig);
		     printf("HOUSE NO.          : %d\n",nodee->adr.hno);
		     printf("STREET NAME        : %s\n",nodee->adr.street);			fflush(stdin);
		     printf("CITY               : %s\n",nodee->adr.city);
		     printf("STATE              : %s\n",nodee->adr.state);
		     printf("PINCODE            : %d\n",nodee->adr.pin);
		     printf("/////////////////////////////////////\n");
		     nodee=nodee->nexte;
		    }
		   break;

		  default:
		    printf("\nPlease enter a valid option\n");
		    goto ee;
		    break;
		}
		break;

	   case 3:
	    ff:
	    if(nodei==NULL)
	       {printf("There is nonode to display in database");}

	       printf("\n1.View database from first record \n2.View database from last record\n");
	       fflush(stdin);
	       scanf("%d",&ch);
	       switch(ch)
		{
		  case 1:
		   nodei=lpi->nexti;
		   while(nodei)
		   {printf("\n");
		    printf("ARTICLE NO.  	       : %d\n",nodei->ano);
		    printf("ARTICLE NAME           : %s\n",nodei->aname);
		    printf("NO. OF ITEMS           : %d\n",nodei->nof_i);
		    printf("ARTICLE SPECIFICATIONS : %s\n",nodei->specs);
		    printf("/////////////////////////////////////\n");
		    nodei=nodei->nexti;
		   }
		   break;

		  case 2:
		   nodei=rpi;
		   while(nodei->previ)
		   {printf("\n");
		    printf("ARTICLE NO.  	       : %d\n",nodei->ano);
		    printf("ARTICLE NAME           : %s\n",nodei->aname);
		    printf("NO. OF ITEMS           : %d\n",nodei->nof_i);
		    printf("ARTICLE SPECIFICATIONS : %s\n",nodei->specs);
		    printf("/////////////////////////////////////\n");
		    nodei=nodei->previ;
		   }
		   break;

		default:
		   printf("\nPlease enter a valid option\n");
		   goto ff;
		   break;
		}
		 break;
	  default:
	  printf("\n\nPlease enter a valid option\n");
	  goto ee;
	  break;
	}
 }




void del()
  {
  int check;
   int out=0,outi=0,oute=0;
  deldel:
  switch(flag)
   {
    case 1:
	nodeb=lpb->nextb;
	printf("\nEnter BOOK NO. of record you want to delete : \n");
	fflush(stdin);
	scanf("%d",&check);
	while(out!=1&&nodeb)
	{
	 if(nodeb->bno==check)
	 {
	  if(nodeb->prevb==NULL)
	  {
	   if(nodeb->nextb==NULL)
	    {
	     printf("\nNOTE: \nDatabase has only 1 node and that node is being deleted.\n");
	     lpb=NULL;
	     rpb=NULL;
	     free(nodeb);
	     out=1;
	    }
	   else
	    {
	     lpb=nodeb->nextb;
	     lpb->prevb=NULL;
	     free(nodeb);
	     out=1;
	    }
	  }
	  else
	  {
	  if(nodeb->nextb==NULL)
	   {
	    rpb=nodeb->prevb;
	    nodeb->prevb->nextb=NULL;
	    free(nodeb);
	    out=1;
	   }
	  else
	   {
	    nodeb->prevb->nextb=nodeb->nextb;
	    nodeb->nextb->prevb=nodeb->prevb;
	    free(nodeb);
	    out=1;
	   }
	  }
	 printf("\nNOTE:\nRecord with BOOK NO. %d is deleted\n",check);
	  }

	 else
	 nodeb=nodeb->nextb;
	}
	if(nodeb==NULL)
	{printf("\nNOTE :\nSuch a record does not exist in the database");
	}
    break;

   case 2:

   nodee=lpe;
	printf("Enter EMPLOYEE ID. of record you want to delete : ");
	fflush(stdin);
	scanf("%d",&check);
	while(oute!=1&& nodee)
	{
	 if(nodee->eid==check)
	 {
	  if(nodee->preve==NULL)
	  {
	   if(nodee->nexte==NULL)
	    {
	     printf("\nNOTE : \nDatabase has only 1 node and that node is being deleted.\n");
	     free(nodee);
	     oute=1;
	    }
	   else
	    {
	     lpe=nodee->nexte;
	     lpe->preve=NULL;
	     free(nodee);
	     oute=1;
	    }
	  }
	  else
	  {
	  if(nodee->nexte==NULL)
	   {
	    rpe=nodee->preve;
	    nodee->preve->nexte=NULL;
	    free(nodee);
	    oute=1;
	   }
	  else
	   {
	    nodee->preve->nexte=nodee->nexte;
	    nodee->nexte->preve=nodee->preve;
	    free(nodee);
	    oute=1;
	   }
	  }
	 printf("\nNOTE: \nRecord with EMPLOYEE NO. %d is deleted\n",check);
	 }
	 else
	 nodee=nodee->nexte; }
 if(nodee==NULL)
	{printf("\nNOTE: \nSuch a record does not exist in the database.");
	}
    break;

   case 3:
     nodei=lpi;
	printf("Enter ARTICLE NO. of record you want to delete : ");
	fflush(stdin);
	scanf("%d",&check);
	while(outi!=1&&nodei)
	{
	 if(nodei->ano==check)
	 {
	  if(nodei->previ==NULL)
	  {
	   if(nodei->nexti==NULL)
	    {
	     printf("\nNOTE :\nDatabase has only 1 node and that node is being deleted\n");
	     free(nodei);
	     outi=1;
	    }
	   else
	    {
	     lpi=nodei->nexti;
	     lpi->previ=NULL;
	     free(nodei);
	     outi=1;
	    }
	  }
	  else
	  {
	  if(nodei->nexti==NULL)
	   {
	    rpi=nodei->previ;
	    nodei->previ->nexti=NULL;
	    free(nodei);
	    outi=1;
	   }
	  else
	   {
	    nodei->previ->nexti=nodei->nexti;
	    nodei->nexti->previ=nodei->previ;
	    free(nodei);
	    outi=1;
	   }
	  }
	 printf("\nNOTE: \nRecord with ARTICLE NO. %d is deleted.\n",check);
	 }
	 else
	 nodei=nodei->nexti;
   }
   if(nodei==NULL)
	{printf("\nNOTE :\nSuch a record does not exist in the database.");
	}
    break;

    default:
    printf("\n\nPlease enter a valid option.\n");
    goto deldel;
    break;

   }

  }

void search()
{
   int a,no;
		char var[20];
		switch(flag)
	{
		case 1:
			nodeb=lpb;
			sb:
			printf("\nYou can search a book by:-\n");
			printf("1.Book Number\n");
			printf("2.Edition\n");
			printf("3.Year of Publication\n");
			printf("4.Book Name\n");
			printf("5.Author Name\n");
			printf("6.Publisher Name\n");
			printf("Please enter your option : ");
			fflush(stdin);
			scanf("%d",&a);
			switch(a)
			{
				case 1:
					printf("\nEnter the Book Number : \n");
					fflush(stdin);
					scanf("%d",&no);
					fflush(stdin);
					while(nodeb->nextb)
					{     //if(nodeb=NULL)
					//{printf("Data not in node");
					//   break;
					//  }
						if(no==nodeb->bno)
						{
						  printf("\n");
						  printf("BOOKNO.          : %d\n",nodeb->bno);
						  printf("BOOK NAME        : %s\n",nodeb->bname);
						  printf("NUMBER OF BOOKS  : %d\n",nodeb->nof_b);
						  printf("AUTHOR NAME      : %s\n",nodeb->author);
						  printf("PUBLISHER NAME   : %s\n",nodeb->publisher);
						  printf("BOOK EDITION     : %d\n",nodeb->edit);
						  printf("PUBLICATION YEAR : %s\n\n",nodeb->yop);
						  printf("/////////////////////////////////////\n");

						}
						nodeb=nodeb->nextb;
					}
					break;
				case 2:
					printf("Enter Edition Of The Book : \n");
					fflush(stdin);
					scanf("%d",&no);
					fflush(stdin);
					while(nodeb->nextb)
					{
						if(no==nodeb->edit)
						{
						  printf("\n");
						  printf("BOOKNO.          : %d\n",nodeb->bno);
						  printf("BOOK NAME        : %s\n",nodeb->bname);
						  printf("NUMBER OF BOOKS  : %d\n",nodeb->nof_b);
						  printf("AUTHOR NAME      : %s\n",nodeb->author);
						  printf("PUBLISHER NAME   : %s\n",nodeb->publisher);
						  printf("BOOK EDITION     : %d\n",nodeb->edit);
						  printf("PUBLICATION YEAR : %s\n\n",nodeb->yop);
						  printf("/////////////////////////////////////\n");

						}
						nodeb=nodeb->nextb;
					}
					break;
				case 3:
					printf("Enter Year Of Publication : \n");
					fflush(stdin);
					gets(var);
					fflush(stdin);
					while(nodeb->nextb)
					{
						if(strcmp(var,nodeb->yop)==0)
						{
						  printf("\n");
						  printf("BOOKNO.          : %d\n",nodeb->bno);
						  printf("BOOK NAME        : %s\n",nodeb->bname);
						  printf("NUMBER OF BOOKS  : %d\n",nodeb->nof_b);
						  printf("AUTHOR NAME      : %s\n",nodeb->author);
						  printf("PUBLISHER NAME   : %s\n",nodeb->publisher);
						  printf("BOOK EDITION     : %d\n",nodeb->edit);
						  printf("PUBLICATION YEAR : %s\n\n",nodeb->yop);
						  printf("/////////////////////////////////////\n");

						}
						nodeb=nodeb->nextb;
					}
					break;
				case 4:
					printf("Enter Book Name : \n");
					fflush(stdin);
					gets(var);
					fflush(stdin);
					while(nodeb->nextb)
					{
						if(strcmp(var,nodeb->bname)==0)
						{
						  printf("\n");
						  printf("BOOKNO.          : %d\n",nodeb->bno);
						  printf("BOOK NAME        : %s\n",nodeb->bname);
						  printf("NUMBER OF BOOKS  : %d\n",nodeb->nof_b);
						  printf("AUTHOR NAME      : %s\n",nodeb->author);
						  printf("PUBLISHER NAME   : %s\n",nodeb->publisher);
						  printf("BOOK EDITION     : %d\n",nodeb->edit);
						  printf("PUBLICATION YEAR : %s\n\n",nodeb->yop);
						  printf("/////////////////////////////////////\n");

						}
						nodeb=nodeb->nextb;
					}
					break;
				case 5:
					printf("Enter Author Name : \n");
					fflush(stdin);
					gets(var);
					fflush(stdin);
					while(nodeb->nextb)
					{
						if(strcmp(var,nodeb->author)==0)
						{
						  printf("\n");
						  printf("BOOKNO.          : %d\n",nodeb->bno);
						  printf("BOOK NAME        : %s\n",nodeb->bname);
						  printf("NUMBER OF BOOKS  : %d\n",nodeb->nof_b);
						  printf("AUTHOR NAME      : %s\n",nodeb->author);
						  printf("PUBLISHER NAME   : %s\n",nodeb->publisher);
						  printf("BOOK EDITION     : %d\n",nodeb->edit);
						  printf("PUBLICATION YEAR : %s\n\n",nodeb->yop);
						  printf("/////////////////////////////////////\n");

						}
						nodeb=nodeb->nextb;
					}
					break;
				case 6:
					printf("Enter Publisher Name : \n");
					fflush(stdin);
					gets(var);
					fflush(stdin);
					while(nodeb->nextb)
					{
						if(strcmp(var,nodeb->publisher)==0)
						{
						  printf("\n");
						  printf("BOOKNO.          : %d\n",nodeb->bno);
						  printf("BOOK NAME        : %s\n",nodeb->bname);
						  printf("NUMBER OF BOOKS  : %d\n",nodeb->nof_b);
						  printf("AUTHOR NAME      : %s\n",nodeb->author);
						  printf("PUBLISHER NAME   : %s\n",nodeb->publisher);
						  printf("BOOK EDITION     : %d\n",nodeb->edit);
						  printf("PUBLICATION YEAR : %s\n\n",nodeb->yop);
						  printf("/////////////////////////////////////\n");

						}
						nodeb=nodeb->nextb;
					}
					break;
				default:
					printf(" Please enter a valid option.\n");
					goto sb;
					break;
			}
			break;
		case 2:
			nodee=lpe;
			se:
			printf("\nYou can search an employee by:-\n");
			printf("1.Employee ID\n");
			printf("2.Employee Name\n");
			printf("3.Designation\n");
			printf("4.Year Of Joining\n");
			printf("5.Date Of Birth\n");
			printf("6.Year Of Retirement\n");
			printf("Please enter your option : ");
			fflush(stdin);
			scanf("%d",&a);

			switch(a)
			{
				case 1:
					printf("\nEnter Employee Id : \n");
					fflush(stdin);
					scanf("%d",&no);
					fflush(stdin);
					while(nodee->nexte)
					{
						if(no==nodee->eid)
						{
						       printf("\n");
						       printf("EMPLOYEE ID.       : %d\n",nodee->eid);
						       printf("EMPLOYEE NAME      : %s\n",nodee->ename);
						       printf("DATE OF BIRTH      : %s\n",nodee->dob);
						       printf("DATE OF JOINING    : %s\n",nodee->doj);
						       printf("DATE Of RETIREMENT : %s\n",nodee->dor);
						       printf("FATHER'S NAME      : %s\n",nodee->p_name);
						       printf("DESIGNATION        : %s\n",nodee->desig);
						       printf("HOUSE NO.          : %d\n",nodee->adr.hno);
						       printf("STREET NAME        : %s\n",nodee->adr.street);			fflush(stdin);
						       printf("CITY               : %s\n",nodee->adr.city);
						       printf("STATE              : %s\n",nodee->adr.state);
						       printf("PINCODE            : %d\n",nodee->adr.pin);
						       printf("/////////////////////////////////////\n");

						}
						nodee=nodee->nexte;
					}
					break;
				case 2:
					printf("Enter Employee Name : \n");
					fflush(stdin);
					gets(var);
					fflush(stdin);
					while(nodee->nexte)
					{
						if(strcmp(var,nodee->ename)==0)
						{

						       printf("\n");
						       printf("EMPLOYEE ID.       : %d\n",nodee->eid);
						       printf("EMPLOYEE NAME      : %s\n",nodee->ename);
						       printf("DATE OF BIRTH      : %s\n",nodee->dob);
						       printf("DATE OF JOINING    : %s\n",nodee->doj);
						       printf("DATE Of RETIREMENT : %s\n",nodee->dor);
						       printf("FATHER'S NAME      : %s\n",nodee->p_name);
						       printf("DESIGNATION        : %s\n",nodee->desig);
						       printf("HOUSE NO.          : %d\n",nodee->adr.hno);
						       printf("STREET NAME        : %s\n",nodee->adr.street);			fflush(stdin);
						       printf("CITY               : %s\n",nodee->adr.city);
						       printf("STATE              : %s\n",nodee->adr.state);
						       printf("PINCODE            : %d\n",nodee->adr.pin);
						       printf("/////////////////////////////////////\n");

						}
						nodee=nodee->nexte;
					}
					break;
				case 3:
					printf("Enter Designation : \n");
					fflush(stdin);
					gets(var);
					fflush(stdin);
					while(nodee->nexte)
					{
						if(strcmp(var,nodee->desig)==0)
						{

						       printf("\n");
						       printf("EMPLOYEE ID.       : %d\n",nodee->eid);
						       printf("EMPLOYEE NAME      : %s\n",nodee->ename);
						       printf("DATE OF BIRTH      : %s\n",nodee->dob);
						       printf("DATE OF JOINING    : %s\n",nodee->doj);
						       printf("DATE Of RETIREMENT : %s\n",nodee->dor);
						       printf("FATHER'S NAME      : %s\n",nodee->p_name);
						       printf("DESIGNATION        : %s\n",nodee->desig);
						       printf("HOUSE NO.          : %d\n",nodee->adr.hno);
						       printf("STREET NAME        : %s\n",nodee->adr.street);			fflush(stdin);
						       printf("CITY               : %s\n",nodee->adr.city);
						       printf("STATE              : %s\n",nodee->adr.state);
						       printf("PINCODE            : %d\n",nodee->adr.pin);
						       printf("/////////////////////////////////////\n");

						}
						nodee=nodee->nexte;
					}
					break;
				case 4:
					printf("Enter Date Of Joining : \n");
					fflush(stdin);
					gets(var);
					fflush(stdin);
					while(nodee->nexte)
					{
						if(strcmp(var,nodee->doj)==0)
						{

						       printf("\n");
						       printf("EMPLOYEE ID.       : %d\n",nodee->eid);
						       printf("EMPLOYEE NAME      : %s\n",nodee->ename);
						       printf("DATE OF BIRTH      : %s\n",nodee->dob);
						       printf("DATE OF JOINING    : %s\n",nodee->doj);
						       printf("DATE Of RETIREMENT : %s\n",nodee->dor);
						       printf("FATHER'S NAME      : %s\n",nodee->p_name);
						       printf("DESIGNATION        : %s\n",nodee->desig);
						       printf("HOUSE NO.          : %d\n",nodee->adr.hno);
						       printf("STREET NAME        : %s\n",nodee->adr.street);			fflush(stdin);
						       printf("CITY               : %s\n",nodee->adr.city);
						       printf("STATE              : %s\n",nodee->adr.state);
						       printf("PINCODE            : %d\n",nodee->adr.pin);
						       printf("/////////////////////////////////////\n");

						}
						nodee=nodee->nexte;
					}
					break;
				case 5:
					printf("Enter the Date Of Birth : \n");
					fflush(stdin);
					gets(var);
					fflush(stdin);
					while(nodee->nexte)
					{
						if(strcmp(var,nodee->dob)==0)
						{

						       printf("\n");
						       printf("EMPLOYEE ID.       : %d\n",nodee->eid);
						       printf("EMPLOYEE NAME      : %s\n",nodee->ename);
						       printf("DATE OF BIRTH      : %s\n",nodee->dob);
						       printf("DATE OF JOINING    : %s\n",nodee->doj);
						       printf("DATE Of RETIREMENT : %s\n",nodee->dor);
						       printf("FATHER'S NAME      : %s\n",nodee->p_name);
						       printf("DESIGNATION        : %s\n",nodee->desig);
						       printf("HOUSE NO.          : %d\n",nodee->adr.hno);
						       printf("STREET NAME        : %s\n",nodee->adr.street);			fflush(stdin);
						       printf("CITY               : %s\n",nodee->adr.city);
						       printf("STATE              : %s\n",nodee->adr.state);
						       printf("PINCODE            : %d\n",nodee->adr.pin);
						       printf("/////////////////////////////////////\n");

						}
						nodee=nodee->nexte;
					}
					break;
				case 6:
					printf("Enter Date Of Retirement : \n");
					fflush(stdin);
					gets(var);
					fflush(stdin);
					while(nodee->nexte)
					{
						if(strcmp(var,nodee->dor)==0)
						{

						       printf("\n");
						       printf("EMPLOYEE ID.       : %d\n",nodee->eid);
						       printf("EMPLOYEE NAME      : %s\n",nodee->ename);
						       printf("DATE OF BIRTH      : %s\n",nodee->dob);
						       printf("DATE OF JOINING    : %s\n",nodee->doj);
						       printf("DATE Of RETIREMENT : %s\n",nodee->dor);
						       printf("FATHER'S NAME      : %s\n",nodee->p_name);
						       printf("DESIGNATION        : %s\n",nodee->desig);
						       printf("HOUSE NO.          : %d\n",nodee->adr.hno);
						       printf("STREET NAME        : %s\n",nodee->adr.street);			fflush(stdin);
						       printf("CITY               : %s\n",nodee->adr.city);
						       printf("STATE              : %s\n",nodee->adr.state);
						       printf("PINCODE            : %d\n",nodee->adr.pin);
						       printf("/////////////////////////////////////\n");

						}
						nodee=nodee->nexte;
					}
					break;
				default:
					printf(" Please enter a valid option.\n");
					goto se;
					break;
			}
			break;
		case 3:
			nodei=lpi;
			si:
			printf("\nYou can search an article by:-\n");
			printf("1.Article Number\n");
			printf("2.Article Name\n");
			printf("Please enter your option : ");
			fflush(stdin);
			scanf("%d",&a);

			switch(a)
			{
				case 1:
					printf("Enter the article number : \n");
					fflush(stdin);
					scanf("%d",&no);
					fflush(stdin);
					while(nodei->nexti)
					{
						if(no==nodei->ano)
						{
						    printf("\n");
						    printf("ARTICLE NO.  	       : %d\n",nodei->ano);
						    printf("ARTICLE NAME           : %s\n",nodei->aname);
						    printf("NO. OF ITEMS           : %d\n",nodei->nof_i);
						    printf("ARTICLE SPECIFICATIONS : %s\n",nodei->specs);
						    printf("/////////////////////////////////////\n");

						}
						nodei=nodei->nexti;
					}
					break;
				case 2:
					printf("Enter the article name : \n");
					fflush(stdin);
					gets(var);
					fflush(stdin);
					while(nodei->nexti)
					{
						if(strcmp(var,nodei->aname)==0)
						{
						      printf("\n");
						    printf("ARTICLE NO.  	       : %d\n",nodei->ano);
						    printf("ARTICLE NAME           : %s\n",nodei->aname);
						    printf("NO. OF ITEMS           : %d\n",nodei->nof_i);
						    printf("ARTICLE SPECIFICATIONS : %s\n",nodei->specs);
						    printf("/////////////////////////////////////\n");
						}
						nodei=nodei->nexti;
					}
					break;
				default:
					printf("Please enter a valid option.\n");
					goto si;
					break;
			}
			break;

		      }
}

