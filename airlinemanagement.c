#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<strings.h>
#include<windows.h>
int capacity=4,waitingqueue=2;
struct reservation
{
	int idno;
	char destination [20];
	char from [20];
	char name[20];
 long long int no;

}x[4],wait[2];
 
 struct node
{
    int info;
    struct node *link;
}*front=NULL,*rear=NULL;

	int memory=1;

void insert(int item)
{
    struct node *tmp;
    tmp=(struct node *)malloc(sizeof(struct node));
    if(tmp==NULL)
    {
        memory=0;
        return;
    }
    else
    {memory=1;
	}
    tmp->info = item;
    tmp->link=NULL;
    if(front==NULL)      /*If Queue is empty*/
        front=tmp;
    rear=tmp;
}

int del()
{
    struct node *tmp;
    int item;
    tmp=front;
    item=tmp->info;
    front=front->link;
    free(tmp);
    return item;
}

int id=0,m=1,m2=1, wid=20,n=1,a=0,b=0;
int i,z,wl,mid,n2=0;
int ab,q,w;

int base()
{
int flag;	
system("cls");
   printf ("\n\n                          ================== Menu =======================");
   printf ("\n                            =========== 1. Airline Enquiry ================");
   printf ("\n                            =========== 2. Airline Reservation=============");
   printf ("\n                            =========== 3. Update Ticket ==================");                    // Menu For Airlines
   printf ("\n                            =========== 4. Cancel Ticket===================");
   /*printf ("\n                          =========== 5. Waiting to confirm check========");*/
   printf ("\n                            =========== 5. Quit Application================");
   printf ("\n                            ===============================================");
   printf("\n\nEnter Your Choice from (1-5) = ");
   scanf("%d",&a);                                   
   fflush(stdin);
   system("cls");
   switch(a)
   {
   	case 1:

		flag=0; 
   		printf("                            Enter Your Ticket ID : ");
   		scanf("%d",&z);
   		for(q=0;q<capacity;q++)
   		{
   			
	   		if(z==x[q].idno) //yaha for loop lagao x.idno == z...agr mile to confirmed na mile toh waiting list mei chck kro....agr vaha bhi na ho toh not found
	   		{
			 	printf("                              Status:Confirmed");
	   			printf("\n                            Your Name : %s",x[q].name);
	   			printf("\n                            Your Mobile No. : %lld",x[q].no);                             // Airlines Enquiry Case
	   			printf("\n                            Destination : %s",x[q].destination);
	   			printf("\n                            From : %s",x[q].from);
	   			flag=1;
	   			break;
	   		}
	   	}
	   	for(w=0;w<waitingqueue;w++)
	   	{
		
	   		if(z==wait[w].idno) 
	   		{
			 	printf("                              Status: Waiting");
	   			printf("\n                            Your Name : %s",wait[w].name);
	   			printf("\n                            Your Mobile No. : %lld",wait[w].no);                             // Airlines Enquiry Case
	   			printf("\n                            Destination : %s",wait[w].destination);
	   			printf("\n                            From : %s",wait[w].from);
	   			flag=1;
	   			break;
	   		}
	   	}
   		
		if(flag==0)
		   	printf("No Entry Found");	
		   break;
   	case 2:
   		
   		if(m==1)
   		{
	   id=1;
	   m=0;
	   }	
   		if(n<=capacity)
        {
            printf("\n                            Enter Destination :");
            gets(x[id].destination);
            printf("\n                            Enter From :");                                                // Airlines Registration Case
            gets(x[id].from);
            printf("\n                            Enter Your Name :");
            gets(x[id].name);
            printf("\n                            Enter Your Phone Number :");
            scanf("%lld",&x[id].no);
            printf("\n\n                          Succesfully Booked  Your Ticket ID : %d  !!",id);
            x[id].idno=id;
            id++;
            a++;
            n++;
		}      
        else
        {
            printf("tickets are full");
            printf("\nEnter 1 to apply for waiting list, else press 0:");
            scanf("%d",&wl);
            if(wl==1)
            {
                if(n2<waitingqueue)
                {
                	if(m2==1)
   					{
					   wid=21;
					   m2=0;
					}
                    printf("\n                            Enter Destination :");
                    gets(wait[n2].destination);
                    printf("\n                            Enter From :");                                                // Airlines waiting list 
                    gets(wait[n2].from);
                    printf("\n                            Enter Your Name :");
                    gets(wait[n2].name);
                    printf("\n                            Enter Your Phone Number :");
                    scanf("%lld",&wait[n2].no);
                    printf("\n\n                            Succesfully waitlisted  Your Ticket ID : %d  !!",wid);
                    mid=wait[wid].no;
                    insert(n2);
                    wait[n2].idno=wid;
                    wid++;
                    n2++;
                    
                }
                else
                    {
                       printf("Waiting list also full");
                       printf("\nSorry for inconvinience, Please try after sometime");
                    }
       	 }
	}
   				break;
   	case 3:

   			printf("                            Enter Your Ticket ID : ");
   		scanf("%d",&z);
   		fflush(stdin);
   			if(z<=id)
   		{
   		printf("\n                            Enter Destination :");
   		gets(x[z].destination);
   		printf("\n                            Enter From :");                                         // Airlines Update Case
   		gets(x[z].from);
   		printf("\n                            Enter Your Name :");
   		gets(x[z].name);
   		printf("\n                            Enter Your Phone Number :");
   		scanf("%lld",&x[z].no);
   		}
		   else
		   {
		   	printf("No Entry Found");
			}	
   			
	   		break;
	case 4:

		printf("                            Enter Your Ticket ID : ");
   		scanf("%d",&z);
   		
   		ab=del();
   		                                                     ///que ko array se link kro
   		int abc=0;
   				strcpy(x[z].destination,wait[ab].destination);
   				strcpy(x[z].from,wait[ab].from);                                                                   // Airlines Cancel Case
   				strcpy(x[z].name,wait[ab].name);                                                                   //cancel seat updated by queued waitlist person
   				x[z].no=wait[ab].no;
   				x[z].idno=wait[abc].idno;
   				abc++;
            
   		printf("\n                            Your Booking Is Cancelled !!");

				break;

   /* case 5:
        
        printf("Enter Your id:");
        scanf("%d",cid);
        for(i=0;i<capacity;i++)                                                     
        {
            if(cid<=id)
            {
                printf("status: Confirmed");
                printf("Name:%s",x[i].name);
                printf("From:%s",x[i].from);
                printf("Destination:%s",x[i].destination);
                printf("id:%lld",cid);
                break;
            }
        }
        if(i==capacity)
        {
            printf("Status:Waiting");
        }
        break;*/
	case 5:
	exit(500);                                                                          // To Exit To Program

				break;
	default:
	printf("Wrong Choice");                                                           // Default Case (needed compulsory)
	getch();
	base();

			break;

}
getch();
base();
return(0);

}

int main()
{

printf("\n\n                                 Welcome To R.A.D.A. Airlines    ");
 printf ("\n                            .....................................");
 printf ("\n                            .....................................");
 printf ("\n                            .....................................");
 printf ("\n                            ==== AIRLINE RESERVATION SYSTEM =====");
 printf ("\n                            .....................................");
 printf ("\n                            .....................................");
 printf ("\n                            .....................................");
 printf ("\n                                 Press Any Key To Continue");
getch();
    base();
	return(0);
}

