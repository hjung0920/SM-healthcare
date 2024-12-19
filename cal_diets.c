//
//  cal_diets.c
//  Diets for Calorie Diary
//
//  Created by Eunju Cha
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cal_exercise.h"
#include "cal_diets.h"
#include "cal_healthdata.h"

#define MAX_DIETS 100      			// Maximum number of diets
#define MAX_FOOD_NAME_LEN 50		// Maximum length of the name of food


// list of diets 
static Diet diet_list[MAX_DIETS];
static int diet_list_size = 0;


/*
    description : read the information in "diets.txt"
*/

void loadDiets(const char* DIETFILEPATH) {
    FILE *file = fopen(DIETFILEPATH, "r");
    if (file == NULL) {
        printf("There is no file for diets! \n");
        return;
    }

     // ToCode: to read a list of the diets from the given file
    while(file==NULL){
    	
        if (diet_list_size >= MAX_DIETS){
        	break;
		}
    }
    fclose(file);
}

/*
    description : to enter the selected diet and the total calories intake in the health data
    input parameters : health_data - data object to which the selected diet and its calories are added 
    return value : No
    
    operation : 1. provide the options for the diets to be selected
    			2. enter the selected diet and the total calories intake in the health data
*/
typedef struct{
  	char diet[100];
  	int intakeCalories;
  } healthdata;// determine structure


int getIntakeCalories(int choices[], int numChoices){
	int totalIntakeCalories=0; //total intake calories
	int dietCalories[]={600,680,925,70,900,615}; //calories of each option
	
	int i;
	for(i=0;i<numChoices;i++){
		int choice=choices[i];
	} //accumulate calories for selected each diets
	
	return totalIntakeCalories; //return total intake calories
}
void inputDiet(HealthData* health_data) {
    int choice, i;
    
    FILE*loadDIets; //file pointer 
	healthdata diets[100]; //array of diets
	int size=0; //number of read diets
    
    
    printf("Choose (1-7):"); // to ask the option
  
	// ToCode: to provide the options for the diets to be selected
    printf("The list of diets:\n");
    for(i=0;i<size;i++){
    	printf("%d. %s\n", i+1, diets[i].diet);
	} //printf of diets option

	loadDiets=fopen('diets.txt',"r"); // file open
    
	if(loadDiets==NULL){
    	printf("There is no file for diets! \n");
        return;
	}// to open the file
	
	loadDiets(loadDiets, diets, &size); //read data from diets.txt
    
  
	// ToCode: to enter the diet to be chosen with exit option
    
	
    
    scanf("%d", &choice); //to enter the diet option 
    
    if(choice<1||choice>size){
    	printf("Invalid choice!\n");
    	fclose(loadDiets);//close the file
    	return ;
	} //  user misselects option
	
	// ToCode: to enter the selected diet in the health data
    strcpy(health_data->diet, diet[choice -1].diet);

    // ToCode: to enter the total calories intake in the health data
    int calories = getCalories(diets,size,selectedDiets);
    totalCalories+=diets[choice -1].calories;// total calories
    
  
    fclose(loadDIets);  // to close the file

}

