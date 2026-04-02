#ifndef _CLINIC_MANAGEMENT_SYSTEM_H_
#define _CLINIC_MANAGEMENT_SYSTEM_H_

#include"STD_DATA.h"
#define PASSWORD 1234
#define NoOfSlots 6
#define MAX_NAME_LENGTH 50
#define MAX_GENDER_LENGTH 10


//function for select mode
void select_mode(void);

//functions for admin

void check_pass(void);//check password

void Admin_mode(void);
void AddNewPatient(void);
void EditRecord(void);
void ReserveSlot(void);
void CancelReserve(void);

//functions for user
void User_mode(void);
void ViewRecord(void);
void ViewReserve(void);

//patient data type

typedef struct 
{
	u8 name[MAX_NAME_LENGTH];
	u8 gender[MAX_GENDER_LENGTH];
	u32 age;
	u32 ID;
	u32 slot;
	struct patient *next;
	
}patient;

patient *head=NULL;
u32 availableSlots=6;
u32 arr[NoOfSlots] = {1,2,3,4,5,6};


#endif