
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define EMPTY_FRONT -1
#define EMPTY_REAR -1
#define max 10

struct doctor
{
  int docno;
  char* name;
  char* speciality;
};

int checkdocno (int docno)
{
  return docno>=6;
}

struct token
{
    int tokenno;
    int docno;
    int patientno;
};

int front[5];
int rear[5];

struct token *q[5];

void create_queue (int docno)
{
       q[docno-1]=(struct token*)malloc(max*sizeof(struct token));
       front[docno-1]=EMPTY_FRONT;
       rear[docno-1]=EMPTY_REAR;

}

int isemptyq(int docno)
{   
    return (front[docno-1]>rear[docno-1] || front[docno-1]==EMPTY_FRONT);
}

void nqueue(struct token *q[],int docno,int pno )
{
    if(rear[docno-1]>max)
    {printf("\nMaximum Patient Limit Exceded\n");}
    else
    {  if(front[docno-1]==EMPTY_FRONT)
       {++front[docno-1]; }
       ++rear[docno-1];
       q[docno-1][rear[docno-1]].docno=docno;
       q[docno-1][rear[docno-1]].patientno=pno;
       q[docno-1][rear[docno-1]].tokenno=rear[docno-1]+1;
       printf("\n\nToken Number is %d",q[docno-1][rear[docno-1]].tokenno);
    }
}

void dqueue(struct token *q[],int docno)
{
    if(isemptyq(docno)==1)
    {printf("\nNo Token exists\n");}
    else
    {
        printf("\nPatient Number %d diagnosed successfully\n",q[docno-1][front[docno-1]].patientno);
        front[docno-1]++;    
    }
    
}

struct bill
{
    int billno;
    float amt;
    char* status;
};

struct patient
{ int patientno;
  char* name;
  int age;
  char* gender;
  char* date;
  char* problem;
  char* assigneddoc;
  char* address;
  long int mobileno;

  struct bill bill;
    
  struct patient *next;
};

struct doctor doclist[5];

void createdoclist()
{
  doclist[0].docno=1;
  doclist[0].name=(char*)malloc(30*sizeof(char));
  doclist[0].speciality=(char*)malloc(30*sizeof(char));
  strcpy(doclist[0].name,"Dr.Pullen");
  strcpy(doclist[0].speciality,"Emergency");

  doclist[1].docno=2;
  doclist[1].name=(char*)malloc(30*sizeof(char));
  doclist[1].speciality=(char*)malloc(30*sizeof(char));
  strcpy(doclist[1].name,"Dr.Hamphey");
  strcpy(doclist[1].speciality,"Physician");

  doclist[2].docno=3;
  doclist[2].name=(char*)malloc(30*sizeof(char));
  doclist[2].speciality=(char*)malloc(30*sizeof(char));
  strcpy(doclist[2].name,"Dr.Krishna");
  strcpy(doclist[2].speciality,"ENT");

  doclist[3].docno=4;
  doclist[3].name=(char*)malloc(30*sizeof(char));
  doclist[3].speciality=(char*)malloc(30*sizeof(char));
  strcpy(doclist[3].name,"Dr.Vasu");
  strcpy(doclist[3].speciality,"Cardiologist");

  doclist[4].docno=5;
  doclist[4].name=(char*)malloc(30*sizeof(char));
  doclist[4].speciality=(char*)malloc(30*sizeof(char));
  strcpy(doclist[4].name,"Dr.Jason");
  strcpy(doclist[4].speciality,"Orthopedist");
}

void viewdoclist()
{
  int i=0;
  for(i=0;i<5;i++)
  {
    printf("\nDoctor Number : %d\tDoctor Name : %s \t Speciality : %s ",doclist[i].docno,doclist[i].name,doclist[i].speciality);
  }
}

char* assigndoc(int docnum)
{
  int s=0;
  for(int i=0;i<5;i++)
  {
    if(doclist[i].docno==docnum)
    {  
       s=1;
       return doclist[i].name;
    }
  }
  if(s==0)
  printf("\nInvalid Doctor Number Entered");
}

typedef struct patient *patient ;
patient start,last,new,temp,prev;
int s,billnum=0;

void create()
{
 start = last = NULL ;
 for(int i=0;i<5;i++)
 {
   create_queue(i+1);
 }
}

int isEmpty()
{return start ==NULL ;}

void insert()
{
new = (struct patient*)malloc(sizeof(struct patient) );
new->name = (char*)malloc(30*sizeof(char));
new->address = (char*)malloc(50*sizeof(char));
new->gender = (char*)malloc(10*sizeof(char));
new->problem = (char*)malloc(30*sizeof(char));
new->assigneddoc = (char*)malloc(30*sizeof(char));
new->date = (char*)malloc(30*sizeof(char));
new->bill.status = (char*)malloc(30*sizeof(char));
new -> next = NULL;

int docno;

printf("\n\t\t\t\tEnter Patient Details\n");
printf("\nEnter Patient number               : ");
scanf("%d",&new->patientno);
getchar();
printf("\nEnter Name                         : ");
scanf("%[^\n]%*c",new->name);
printf("\nEnter Age                          : ");
scanf("%d",&new->age);
getchar();
printf("\nEnter Gender                       : ");
scanf("%[^\n]%*c",new->gender);
printf("\nEnter Date of Admission(dd/mm/yyyy): ");
scanf("%[^\n]%*c",new->date);
printf("\nEnter Problem                      : ");
scanf("%[^\n]%*c",new->problem);
printf("\nEnter Doctor Number given above    : ");
scanf("%d",&docno);
strcpy(new->assigneddoc,assigndoc(docno));
printf("\n%s Assigned ",new->assigneddoc);
getchar();
nqueue(q,docno,new->patientno);
printf("\n\nEnter Address                      : ");
scanf("%[^\n]%*c",new->address);
printf("\nEnter Mobile Number                : ");
scanf("%ld",&new->mobileno);
new->bill.billno=00;
new->bill.amt=00;
strcpy(new->bill.status,"NOT ISSUED");

if(isEmpty())
   {
    start=last=new ;
    printf("\n**First Patient Record Entered**\n");
   }

else
  {  last->next = new ;
     last = new ;
     printf("\nEntered as Last Patient Record \n");
  }

}

void display()
{ if( ! isEmpty())
    { 
      temp = start ;

      printf("\n\n\t**Patient Records**");
  
      while( temp!= NULL)
        {
         
          printf("\n\nPatient Number    : %d",temp->patientno);
          printf("\nName              : %s",temp->name);
          printf("\nGender            : %s",temp->gender);
          printf("\nAge               : %d",temp->age);
          printf("\nDate of Admission : %s",temp->date);
          printf("\nProblem           : %s",temp->problem);
          printf("\nDoctor Name       : %s",temp->assigneddoc);
          printf("\nAddress           : %s",temp->address);
          printf("\nMobile Number     : %ld",temp->mobileno);
          printf("\nBill Number       : %d",temp->bill.billno);
          printf("\nAmount            : %f",temp->bill.amt);
          printf("\nBill Status       : %s",temp->bill.status);
          
          temp=temp->next; 
        }
    }
else
printf("\nNo Record Available\n");
}


void delete()
{
  if(isEmpty()==1)
    {
        printf("\nList does not exist\n");
    }
    else
    {
        temp=start;
        while(temp!=last)
        {
            if(temp->patientno % 3==0 && temp->next!=0)
            {
              prev->next=temp->next;
              temp=prev;
            }
            prev=temp;
            temp=temp->next;
          }
          
        }
}


void updatepno(int pno)
{

 if( !isEmpty() )
  {
    temp=prev=start;
    s=0;
    
    while(temp!=NULL && s!=1)
    {
      if(pno==temp->patientno)
      {
        s=1;
        printf("\n\t\t\t\tUpdate Patient Details\n");
        printf("\nPatient number                     : %d",temp->patientno);
        getchar();
        printf("\nEnter Name                         : ");
        scanf("%[^\n]%*c",new->name);
        printf("\nEnter Age                          : ");
        scanf("%d",&new->age);
        getchar();
        printf("\nEnter Gender                       : ");
        scanf("%[^\n]%*c",new->gender);
        printf("\nEnter Date of Admission(dd/mm/yyyy): ");
        scanf("%[^\n]%*c",new->date);
        printf("\nEnter Problem                      : ");
        scanf("%[^\n]%*c",new->problem);
        printf("\nEnter Doctor Name                  : ");
        scanf("%[^\n]%*c",new->assigneddoc);
        printf("\nEnter Address                      : ");
        scanf("%[^\n]%*c",new->address);
        printf("\nEnter Mobile Number                : ");
        scanf("%ld",&new->mobileno);
      }

      temp=temp->next;
    }
  }
  else
  {
    printf("\nNo Patient Record Exists\n");
  }
  
}

void searchpno(int pno)

{
  if( !isEmpty() )
  {
    temp=start;
    s=0;

    printf("\n\nPatient Records with Patient Number: %d",pno);

    while(temp!=NULL)
    {
      if(pno==temp->patientno)
      {
          s=1;
          printf("\n\nPatient Number    : %d",temp->patientno);
          printf("\nName              : %s",temp->name);
          printf("\nGender            : %s",temp->gender);
          printf("\nAge               : %d",temp->age);
          printf("\nDate of Admission : %s",temp->date);
          printf("\nProblem           : %s",temp->problem);
          printf("\nDoctor Name       : %s",temp->assigneddoc);
          printf("\nAddress           : %s",temp->address);
          printf("\nMobile Number     : %ld",temp->mobileno);
          printf("\nBill Number       : %d",temp->bill.billno);
          printf("\nAmount            : %f",temp->bill.amt);
          printf("\nBill Status       : %s",temp->bill.status);

      }

      temp=temp->next;
    }
    if (s==0)
    { printf("\n\nNo Records Found"); }
  }

  else
  {
    printf("\nNo Patient Record Exists\n");
  }
  
}

void searchdoa(char* doa)
{
  if( !isEmpty() )
  {
    temp=start;
    s=0;

    printf("\n\nPatient Records with Date of Admission: %s",doa);

    while(temp!=NULL)
    {
      
      if(strcmp(temp->date,doa)==0)
      {   
          s=1;
          printf("\n\nPatient Number    : %d",temp->patientno);
          printf("\nName              : %s",temp->name);
          printf("\nGender            : %s",temp->gender);
          printf("\nAge               : %d",temp->age);
          printf("\nDate of Admission : %s",temp->date);
          printf("\nProblem           : %s",temp->problem);
          printf("\nDoctor Name       : %s",temp->assigneddoc);
          printf("\nAddress           : %s",temp->address);
          printf("\nMobile Number     : %ld",temp->mobileno);
          printf("\nBill Number       : %d",temp->bill.billno);
          printf("\nAmount            : %f",temp->bill.amt);
          printf("\nBill Status       : %s",temp->bill.status);

      }

      temp=temp->next;
    }

    if (s==0)
    { printf("\n\nNo Records Found"); }
  }

  else
  {
    printf("\nNo Patient Record Exists\n");
  }
  
}

void searchname(char* pna)
{
  if( !isEmpty() )
  {
    temp=start;
    s=0;

    printf("\n\nPatient Records with Name: %s",pna);

    while(temp!=NULL)
    {
      if(strcmp(temp->name,pna)==0)
      {
          s=1;
          printf("\n\nPatient Number    : %d",temp->patientno);
          printf("\nName              : %s",temp->name);
          printf("\nGender            : %s",temp->gender);
          printf("\nAge               : %d",temp->age);
          printf("\nDate of Admission : %s",temp->date);
          printf("\nProblem           : %s",temp->problem);
          printf("\nDoctor Name       : %s",temp->assigneddoc);
          printf("\nAddress           : %s",temp->address);
          printf("\nMobile Number     : %ld",temp->mobileno);
          printf("\nBill Number       : %d",temp->bill.billno);
          printf("\nAmount            : %f",temp->bill.amt);
          printf("\nBill Status       : %s",temp->bill.status);

      }

      temp=temp->next;
    }

    if (s==0)
    { printf("\n\nNo Records Found"); }

  }
  else
  {
    printf("\nNo Patient Record Exists\n");
  }
  
}

void searchda(int dn)
{
  if( !isEmpty() )
  {
    temp=start;
    s=0;

    printf("\n\nPatient Records with assigned Doctor Name: %s",doclist[dn-1].name);

    while(temp!=NULL)
    {
      if(strcmp(temp->assigneddoc,doclist[dn-1].name)==0)
      {
          s=1;
          printf("\n\nPatient Number    : %d",temp->patientno);
          printf("\nName              : %s",temp->name);
          printf("\nGender            : %s",temp->gender);
          printf("\nAge               : %d",temp->age);
          printf("\nDate of Admission : %s",temp->date);
          printf("\nProblem           : %s",temp->problem);
          printf("\nDoctor Name       : %s",temp->assigneddoc);
          printf("\nAddress           : %s",temp->address);
          printf("\nMobile Number     : %ld",temp->mobileno);
          printf("\nBill Number       : %d",temp->bill.billno);
          printf("\nAmount            : %f",temp->bill.amt);
          printf("\nBill Status       : %s",temp->bill.status);

      }

      temp=temp->next;
    }

    if (s==0)
    { printf("\n\nNo Records Found"); }
    
  }
  else
  {
    printf("\nNo Patient Record Exists\n");
  }
  
}

void searchprob(char* prob)
{
  if( !isEmpty() )
  {
    temp=start;
    s=0;

    printf("\n\nPatient Records with Problem: %s",prob);

    while(temp!=NULL)
    {
      if(strcmp(temp->problem,prob)==0)
      {
          s=1;
          printf("\n\nPatient Number    : %d",temp->patientno);
          printf("\nName              : %s",temp->name);
          printf("\nGender            : %s",temp->gender);
          printf("\nAge               : %d",temp->age);
          printf("\nDate of Admission : %s",temp->date);
          printf("\nProblem           : %s",temp->problem);
          printf("\nDoctor Name       : %s",temp->assigneddoc);
          printf("\nAddress           : %s",temp->address);
          printf("\nMobile Number     : %ld",temp->mobileno);
          printf("\nBill Number       : %d",temp->bill.billno);
          printf("\nAmount            : %f",temp->bill.amt);
          printf("\nBill Status       : %s",temp->bill.status);

      }

      temp=temp->next;
    }

    if (s==0)
    { printf("\n\nNo Records Found"); }
    
  }
  else
  {
    printf("\nNo Patient Record Exists\n");
  }
  
}

void searchbs(char* bs)
{
  if( !isEmpty() )
  {
    temp=start;
    s=0;

    printf("\n\nPatient Records with Bill Status: %s",bs);

    while(temp!=NULL)
    {
      if(strcmp(temp->bill.status,bs)==0)
      {
          s=1;
          printf("\n\nPatient Number    : %d",temp->patientno);
          printf("\nName              : %s",temp->name);
          printf("\nGender            : %s",temp->gender);
          printf("\nAge               : %d",temp->age);
          printf("\nDate of Admission : %s",temp->date);
          printf("\nProblem           : %s",temp->problem);
          printf("\nDoctor Name       : %s",temp->assigneddoc);
          printf("\nAddress           : %s",temp->address);
          printf("\nMobile Number     : %ld",temp->mobileno);
          printf("\nBill Number       : %d",temp->bill.billno);
          printf("\nAmount            : %f",temp->bill.amt);
          printf("\nBill Status       : %s",temp->bill.status);

      }

      temp=temp->next;
    }

    if (s==0)
    { printf("\n\nNo Records Found"); }
    
  }
  else
  {
    printf("\nNo Patient Record Exists\n");
  }
  
}

void searchmn(long int mno)

{
  if( !isEmpty() )
  {
    temp=start;
    s=0;

    printf("\n\nPatient Records with Patient Number: %ld",mno);

    while(temp!=NULL)
    {
      if(mno==temp->mobileno)
      {
          s=1;
          printf("\n\nPatient Number    : %d",temp->patientno);
          printf("\nName              : %s",temp->name);
          printf("\nGender            : %s",temp->gender);
          printf("\nAge               : %d",temp->age);
          printf("\nDate of Admission : %s",temp->date);
          printf("\nProblem           : %s",temp->problem);
          printf("\nDoctor Name       : %s",temp->assigneddoc);
          printf("\nAddress           : %s",temp->address);
          printf("\nMobile Number     : %ld",temp->mobileno);
          printf("\nBill Number       : %d",temp->bill.billno);
          printf("\nAmount            : %f",temp->bill.amt);
          printf("\nBill Status       : %s",temp->bill.status);

      }

      temp=temp->next;
    }
    if (s==0)
    { printf("\n\nNo Records Found"); }
  }

  else
  {
    printf("\nNo Patient Record Exists\n");
  }
  
}

void searchbn(int bn)

{
  if( !isEmpty() )
  {
    temp=start;
    s=0;

    printf("\n\nPatient Record with Bill Number: %d",bn);

    while(temp!=NULL)
    {
      if(bn==temp->bill.billno && temp->bill.billno!=0)
      {
          s=1;
          printf("\n\nPatient Number    : %d",temp->patientno);
          printf("\nName              : %s",temp->name);
          printf("\nGender            : %s",temp->gender);
          printf("\nAge               : %d",temp->age);
          printf("\nDate of Admission : %s",temp->date);
          printf("\nProblem           : %s",temp->problem);
          printf("\nDoctor Name       : %s",temp->assigneddoc);
          printf("\nAddress           : %s",temp->address);
          printf("\nMobile Number     : %ld",temp->mobileno);
          printf("\nBill Number       : %d",temp->bill.billno);
          printf("\nAmount            : %f",temp->bill.amt);
          printf("\nBill Status       : %s",temp->bill.status);

      }

      temp=temp->next;
    }
    if (s==0)
    { printf("\n\nNo Records Found"); }
  }

  else
  {
    printf("\nNo Patient Record Exists\n");
  }
  
}

char* returnpname(int pno)
{
  temp=start;

    while(temp!=NULL)
    {
      if(pno==temp->patientno)
      {
        return temp->name;
      }

      temp=temp->next;
    }
    if (s==0)
    { printf("\n\nNo Records Found"); }
}

void firsttoken(struct token *q[],int docno)
{
  if(!isemptyq(docno))
 {
 printf("\n%s is currently in session with %s .",returnpname(q[docno-1][front[docno-1]].patientno),doclist[docno-1].name);
 printf("\nPatient no :%d", q[docno-1][front[docno-1]].patientno);
 printf("\nDoctor no  :%d", q[docno-1][front[docno-1]].docno);
 printf("\nToken no   :%d", q[docno-1][front[docno-1]].tokenno);
 }
 else
 {
   printf("\n No Patient assigned for %s",doclist[docno-1].name);
 }
 }

void issuebill(int docno)
{ 
  float amt;
  temp=start;

  if(isemptyq(docno))
  { printf("\nNo Patient Assigned for %s ",doclist[docno-1].name); }

  else
  {

  while(temp!=NULL)
  {
   if (temp->patientno==q[docno-1][front[docno-1]].patientno)
   {
     printf("\nIssuing Bill For Patient Number : %d and Name: %s",temp->patientno,temp->name);
     printf("\nEnter Amount to pay : ");
     scanf("%f",&amt);
     strcpy(temp->bill.status,"Paid");
     temp->bill.billno=++billnum;
     temp->bill.amt=amt;
     printf("\nPatient Number    : %d",temp->patientno);
     printf("\nBill Number       : %d",temp->bill.billno);
     printf("\nAmount            : %f",temp->bill.amt);
     printf("\nBill Status       : %s",temp->bill.status);
     dqueue(q,docno);
    
    break;
   }
   temp=temp->next;
  }

  }

}

void freerecords()
{
  for(int i=0;i<5;i++)
  {
    free(q[i]);
  }

  temp=start;
  while(temp!=NULL)
  {
    free(temp);
    temp=temp->next;
  }
}

int main()
{
 int i=1,docno,pno;
 create();
 printf("\n\n******* ADAPT Hospital*******\n\n");
 printf("\nDoctor List\n");
 createdoclist();
 viewdoclist();

    while(i!=0)
    {
        printf("\n\n**Menu**\n");
        printf("\n1.Add Patient Record\n2.Display All Patient Records\n3.Update a Patient Record\n4.Search\n5.Issue Bill\n6.Patient In Session\n0.Exit\n\n**\n\n");
        scanf("%d",&i);
        
        switch(i)
        {
            case 1: { 
                      insert();
                      break;
                    }
                    
            case 2: { 
                     display();
                     break;
                    }
            
            case 3: {
                     printf("\nEnter Patient Number to Update : ");
                     scanf("%d",&pno);
                     updatepno(pno);
                     break;
                    }
            
            case 4:{
                      int j=1;
                      while(j!=0)
                      { 
                       printf("\n\n**Search Menu**\n");
                       printf("\n1.Patient Record\n2.Date of Admission\n3.Patient Name\n4.Doctor Assigned\n5.Problem\n6.Mobile Number\n7.Bill Number\n8.Bill Status\n0.Exit\n\n**\n\n");
                       scanf("%d",&j);
                       switch(j)
                      {
                          case 1: { 
                                    printf("\nEnter Patient Number to Search : ");
                                    scanf("%d",&pno);
                                    searchpno(pno);
                                    break;
                                  }

                          case 2: {
                                   char*doa;
                                   doa=(char*)malloc(30*sizeof(char));
                                   getchar();
                                   printf("\nEnter Date of Admission to Search : ");
                                   scanf("%[^\n]%*c",doa);
                                   searchdoa(doa);
                                   break;
                                  }

                          case 3: {
                                   char* pna;
                                   pna=(char*)malloc(30*sizeof(char));
                                   getchar();
                                   printf("\nEnter Patient Name to Search : ");
                                   scanf("%[^\n]%*c",pna);
                                   searchname(pna);
                                   break;
                                  }
                          case 4: {
                                   viewdoclist();
                                   int dn;
                                   printf("\n\nEnter Assigned Doctor Number to Search: ");
                                   scanf("%d",&dn);
                                   searchda(dn);
                                   break;
                                  }
                          case 5: {
                                   char* prob;
                                   prob=(char*)malloc(30*sizeof(char));
                                   getchar();
                                   printf("\nEnter Problem to Search : ");
                                   scanf("%[^\n]%*c",prob);
                                   searchprob(prob);
                                   break;
                                  }
                          case 6: {
                                   long int mno;
                                   getchar();
                                   printf("\nEnter Mobile Number to Search : ");
                                   scanf("%ld",&mno);
                                   searchmn(mno);
                                   break;
                                  }
                          case 7: {
                                   int bn;
                                   getchar();
                                   printf("\nEnter Bill Number to Search : ");
                                   scanf("%d",&bn);
                                   searchbn(bn);
                                   break;
                                  }
                          
                          case 8: {
                                   char* bs;
                                   bs=(char*)malloc(30*sizeof(char));
                                   getchar();
                                   printf("\nEnter Bill Status to Search : ");
                                   scanf("%[^\n]%*c",bs);
                                   searchbs(bs);
                                   break;
                                  }
                          
                          case 0: break;

                          default:{ printf("\n\nIncorrect Option Entered\n"); }}
                      }
                   } 

            case 5:{ 
                     printf("\nEnter Doctor Number to Issue Bill:");
                     scanf("%d",&docno);
                     
                     if(checkdocno(docno))
                     { printf("\n\nIncorrect Doctor Number"); }
                     else
                     {
                       issuebill(docno);
                     }
                
                     break;
                   }
                  
            case 6:{    
                        printf("\nEnter Doctor Number : ");
                        scanf("%d",&docno);

                        if(checkdocno(docno))
                        { printf("\n\nIncorrect Doctor Number"); }
                          else
                        {
                          firsttoken(q,docno);
                        }
                        
                        break;
                   }

            case 0:  break;

            default:{ printf("\n\nIncorrect Option Entered\n"); }
        }
    }
    freerecords();
    return 0;
}