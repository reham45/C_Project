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
	u32 Mode,check_input;
	printf("                   WELCOME TO THE CLINIC\n");

	printf("For Admin click 1:\n");
	printf("For User click 2:\n");
	check_input=scanf("         %d",&Mode);
	//to avoid user unbehavior (system crashing)
	if(check_input!=1)
	{
		while (getchar() != '\n');   
        printf("Error: Invalid input! Please enter numbers only.\n");
	}	
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
	u32 password,check_input;
	//give the user additional attempts
	printf("Please, Enter The password: ");
	for(u32 i=0;i < MAX_Tries;i++)
	{
		//To force the user to enter the integar number for the password
       check_input=scanf("%d", &password);
	   if (check_input != 1) 
        {
            while (getchar() != '\n'); 
            
            printf("Error: Invalid input! Please enter numbers only.\nTry again: ");
            i--; 
            continue; 
        }

		if(password==PASSWORD)
		{
			Admin_mode();
			return;
	    }
		if(i<(MAX_Tries-1))
		{
			printf("Wrong password.Please Try Again: ");
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
	patient *ptr1;
	patient *ptr2;
	if(availableSlots)//to sure there is any available slots
    {

		/*Create new node containing the new Patient*/
		
		patient *NewPatient=(patient*)malloc(sizeof(patient));
		
		/*Scanning the information*/
		printf("                   The Patient Information\n");
        printf("Name:");
        scanf("%s",NewPatient->name);
		printf("\n");
        printf("Gender:");
        scanf("%s",NewPatient->gender);
		printf("\n");
        printf("Age:");
        scanf("%d",&NewPatient->age);
		printf("\n");
        printf("ID:");
        scanf("%d",&NewPatient->ID);
		printf("\n");
	    NewPatient->next=NULL;//will point to null (last element)

	    if(head==NULL)
		{
			head=NewPatient;
			printf("Patient added successfully!");
			return;
	    }
        else
	   {
		   /*can use them again*/
	       ptr1=head;
		   ptr2=head;
		   
		   while(ptr2!=NULL)
		   {
			   if(ptr2->ID==NewPatient->ID)
			   {
				   printf("This ID already exists.\n"
                           "Please Enter New ID : ");
                   scanf("%d",&NewPatient->ID);
				   ptr2=head;
				   ptr1=head;
				   continue;
                }
				if(ptr2->next==NULL)
				{
					break;
				}
                				
            }
			ptr1=NewPatient;
			head=ptr1;
            printf("Patient added successfully!\n");
        }
		
    }
	else
	{
		printf("Sorry,There is any available slots.");
	}
}


/*Function to edit Patient informatiom*/

void EditRecord(void){
	u32 ID;
	u32 found=0;
	/*check head*/
	
	if(head==NULL)
	{
		printf("The list is empty! No records to edit.\n");
        return;
	}

	patient *ptr=head;
	

	printf("Please,Enter the ID:");
	scanf("%d",&ID);
	
	
	while(ptr!= NULL)
	{
		if(ptr->ID==ID)
		{
			found=1;
			printf("New Name:");
			scanf("%s",ptr->name);
			printf("\n");
			printf("New Gender:");
			scanf("%s",ptr->gender);
			printf("\n");
		    printf("New Age:");
			scanf("%d",&ptr->age);
			printf("\n");
			break;
	    }
		ptr->next;
	}
		
	if(found==0)
	{
		printf("     Invalid ID\n If you still want to edit  return to list");
	}
   
    }
	



void ReserveSlot(void){
	u32 ID;
	u32 i=0;
	u32 j=0;
	patient *ptr=head;
	/*if there is not available slots ,Exit*/
	if(ptr==NULL)
	{
		printf("there is not any available slots!");
		Admin_mode();
		return;	
	}
	if(ptr!=NULL)
	{
		printf("Please,Enter the ID:");
		scanf("%d",&ID);
		printf("\n");
		while(ptr!=NULL){
			if(ptr->ID==ID)
			{
				/*search on available slots*/
				for(i=1;i<=NoOfSlots;i++,j++)
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
						//breack time
						case 4:
						printf("4- From 4:00 PM To 4:30 PM \n");
                        break;
						case 5:
						printf("5- From 4:30 PM To 5:00 PM \n");
                        break;
					}
				}
				/*select the slot and delete*/
				printf("Please,Select the slot that you wanna reserve.");
				scanf("%d",&ptr->slot);
				arr[ptr->slot-1]=0;
				availableSlots--;
				return;
				
			}
			else
			{
			printf("The ID IS not exists!");
			Admin_mode();
			return;
			}

		}
	}
    else
	{
	 printf("There are no patients \n");
	}
}

void CancelReserve(void){
	u32 ID;
	patient *ptr;
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
				printf("The ID IS not exists!");
				Admin_mode();
				return;
            }
        }

    }
	else
	{
		printf("There are no patients\n");
		return;
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
		//to save the system from crash
		if(choice_num!=1)
		{
			while(getchar()=='\n');
			printf("Error: Invalid input! Please enter numbers only.\n");
			continue;
		}

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
    u32 ID;
	patient *ptr;
    ptr= head;
    if(ptr!= NULL)
    {
        printf("Enter patient ID : ");
        scanf("%d\n",&ID);
        /*Make loop On all the nodes and print every patient informations */
		
		
        while(ptr!= NULL)
        {
            if(ptr->ID==ID)
            {
                printf("Patient Name : %s\n",ptr->name);
                printf("Patient Gender : %s\n",ptr->gender);
                printf("Patient Age : %d\n",ptr->age);
                printf("Patient ID : %d\n",ptr->ID);
                return;
            }
            else
            {
                printf("The ID IS not exists!");
				User_mode();
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
    if(ptr!= NULL)
    {
        /* Print all the Reservations of all the patients */
		
        printf("All reservation slot:\n");
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
                printf("%d   4:00 PM : 4:30 PM.\n",ptr->ID);
                break;
            case 5:
                printf("%d   4:30 PM : 5:00 PM.\n",ptr->ID);
                break;
            default :
                break;
            }
        }
    }
	else
	{
		printf("There are no patients \n");
	}

}
