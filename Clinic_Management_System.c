#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"STD_Types.h"
#include"Clinic_Management_System.h"

//Select if he/she is a User or an Admin
int main(){
	select_mode();
}
/*Function for mode selection */
void select_mode(void){
	u32 Mode;
	printf("                   WELCOME TO THE CLINIC\n");

	printf("For Admin click 1:\n");
	printf("For User click 2:\n");
	scanf("         %d",&Mode);
	//to handle mode selection
	switch(Mode)
	{
	case 1:
		check_pass();// Call The Function for check password
		break;
	case 2:
		User_mode();// Call The User Mode Function
		break;
	default:
		printf("               Invalid Choice\n");
		select_mode();//recursive call for invalid choice
	}
    }

/*Function for check on Admin password */
void check_pass(void){
	u32 pass;

	printf("Please,Enter the password:\n");
	scanf("         %d",&pass);
	//check for initial password
	if (pass==PASSWORD)
    {
        Admin_mode();
		return;
    }
	//give the user additional attempts
	for(u32 i=0;i<2;i++)
	{
		printf("Wrong password.Please Try Again: ");
        scanf("%d", &pass);

		if(pass==PASSWORD)
		{
			Admin_mode();
			return;
	    }
	}
	//if all attempts failed
    printf("Incorrect password, Sorry No more tries ");
	select_mode();//recursive call for Incorrect password
}

void Admin_mode(void){
	u32 choice_num;
	while(1){
		printf("Please,Enter your choice number\n");
	    printf("1- Add a new patient record\n");
	    printf("2- Edit the patient record\n");
	    printf("3- Reserve a slot with the doctor\n");
	    printf("4- Cancel reservation\n");
	    printf("5- return the previous list\n");
	    scanf("%d",&choice_num);

	   //to handle the Admin choices
	   switch(choice_num)
	   {
	   case 1:
	      AddNewPatient();
		  break;
	   case 2:
          EditRecord();
		  break;
       case 3:
          ReserveSlot();
		  break;
       case 4:
          CancelReserve();
		  break;
       case 5:
		  select_mode();
		  break;
	   default:
		  printf("        Invalid Choice. Please Choose from the choice numbers\n");
	   }
	}
  }

/*Function for add new Patient */
void AddNewPatient(void){
	u32 ID;
	if(availableSlots)
    {

		/*Create new node containing the new Patient*/
		patient* NewPatient=(patient*)malloc(sizeof(patient));
		/*Scanning the information*/
		printf("                   The Patient Information\n");
        printf("Name:");
        scanf("%s\n",NewPatient->name);
        printf("Gender:");
        scanf("%s\n",NewPatient->gender);
        printf("Age:");
        scanf("%d\n",NewPatient->age);
        printf("ID:");
        scanf("%d\n",NewPatient->ID);
        /*Intitial value of the next of the New Patient node to NULL */
	    NewPatient->next=NULL;

	    if(head==NULL)
		{
			head=NewPatient;
	    }
        else
	   {
		   patient *ptr1,*ptr2;
	       ptr1=ptr2=head;
		   while(ptr2!=NULL)
		   {
			   if(NewPatient->ID == ptr2->ID)
			   {
				   printf("This ID already exists.\n"
                           "Please Enter New ID : ");
                   scanf("%d",&NewPatient->ID);
                   ptr2 = head;
                }
                ptr1=ptr2;
                ptr2=ptr2->next;
            }
            ptr1->next=NewPatient;
        }
    }
}


/*Function to edit Patient informatiom*/
void EditRecord(void){
	u32 ID;
	u32 found=0;

	patient *ptr=head;
	

	printf("Please,Enter the ID:");
	scanf("%d",&ID);
	
	
	while(ptr->next!= NULL)
	{
		if(ID==ptr->ID)
		{
			found=1;
			printf("New Name:");
			scanf("%s\n",&ptr->name);
			printf("New Gender:");
			scanf("%s\n",&ptr->gender);
		    printf("New Age:");
			scanf("%d\n",&ptr->age);
			break;
	    }
		ptr=ptr->next;
	}
		
	if(found==0)
	{
		printf("     Invalid ID\n If you still want to edit  return to list");
	}
   
    }



void ReserveSlot(void){
	u32 ID;
	struct patient *ptr=head;
	if(ptr!=NULL)
	{
		printf("Please,Enter the ID:");
		scanf("%d\n",&ID);
		while(ptr!=NULL){
			if(ID == ptr->ID)
			{
				for(u32 i=1,j=1;i<=availableSlots,j<=availableSlots;i++,j++)
				{
					switch(arr[j])
					{
						case 1:
						printf("1- From 2:00 PM To 2:30 PM \n");
                        break;
						case 2:
						printf("2- From 2:30 PM To 3:00 PM \n");
                        break;
						case 3:
						printf("3- From 3:00 PM To 3:30 PM \n");
                        break;
						case 4:
						printf("4- From 3:30 PM To 4:00 PM \n");
                        break;
						case 5:
						printf("5- From 4:00 PM To 4:30 PM \n");
                        break;
						case 6:
						printf("6- From 4:30 PM To 5:00 PM \n");
                        break;
					}

				}
			}
			else
			{
			ptr= ptr->next;
			}

		}
	}
    else
	{
	 printf("There are no patients \n");
	}
}

void CancelReserve(void){
	struct patient *ptr;
    u32 ID;
    ptr= head;

    if(ptr!= NULL)
    {
        printf("Please Enter The Patient ID That you want to Cancel The Reservation : ");
        scanf("%d\n",&ID);

        while(ptr!= NULL)
        {
            if(ptr->ID == ID)
            {
                arr[ptr->slot-1] = ptr->slot;
                availableSlots++;
                return;
            }
            else
            {
				ptr= ptr->next;
            }
        }

    }
	else
	{
		printf("There are no patients\n");

    }
}

//Functions for User
void User_mode(void){
	u32 choice_num;
	while(1){
		printf("Please,Enter your choice number\n");
	    printf("1- View Patient Informations\n");
	    printf("2- View Today Reservations \n");
	    printf("3- return the previous list\n");
	    scanf("%d",&choice_num);

	   //to handle the User choices
	   switch(choice_num)
	   {
	   case 1:
          ViewRecord();
		  break;
	   case 2:
          ViewReserve();
		  break;
       case 3:
          select_mode();
		  break;
	   default:
		  printf("        Invalid Choice. Please Choose from the choice numbers\n");
	   }
	}


}
void ViewRecord(void){

	patient *ptr;
    u32 ID;
    ptr= head;
    if(ptr!= NULL)
    {
        printf("Enter patient ID : ");
        scanf("%d\n",&ID);
        /*Make loop On all the nodes and print every patient informations */
        while(ptr!= NULL)
        {
            if(ID == ptr->ID)
            {
                printf("Patient Name : %s\n",ptr->name);
                printf("Patient Gender : %s\n",ptr->gender);
                printf("Patient Age : %d\n",ptr->age);
                printf("Patient ID : %d\n",ptr->ID);
                return;
            }
            else
            {
                ptr=ptr->next;
            }
        }
    }
	else
	{
		printf("There are no patients \n");
	}

    }


void ViewReserve(void){
	patient *ptr=head;
    u32 slot;
    if(ptr!= NULL)
    {
        /* Print all the Reservations of all the patients */
        printf("ID: reservation slot:\n");
        while(ptr!= NULL)
        {
            switch(ptr->slot)
            {
            case 1:
                printf("%d   2:00 PM : 2:30 PM.\n",ptr->ID);
                break;

            case 2:
                printf("%d   2:30 PM : 3:00 PM.\n",ptr->ID);
                break;
			case 3:
			    printf("%d   3:00 PM : 3:30 PM.\n",ptr->ID);
                break;
            case 4:
                printf("%d   3:30 PM : 4:00 PM.\n",ptr->ID);
                break;

            case 5:
                printf("%d   4:00 PM : 4:30 PM.\n",ptr->ID);
                break;

            case 6:
                printf("%d   4:30 PM : 5:00 PM.\n",ptr->ID);
                break;

            default :
                break;
            }
            ptr=ptr->next;
        }
    }
	else
	{
		printf("There are no patients \n");
	}

}
