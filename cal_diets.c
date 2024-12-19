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
    while (file==NULL) {
    	
        if (diet_list_size >= MAX_DIETS){
        	break;
		}
    }
    fclose(file);
}
typedef struct{
	char diet[100];
	int intakeCalories;
}healthdata;//determine structure

int getIntakeCalories(int choices[], int numChoices){
	int total_intakeCalories=0;//total intake calories
	int dietCalories[]={600, 680, 925,70,900,615};//diets calories
	
	int i;
	for(i=0;i<numChoices;i++){
		int choice=choices[i];
	}//accumulate calories for selected each diets
	
	return total_intakeCalories;//return total intake calories
}


/*
    description : to enter the selected diet and the total calories intake in the health data
    input parameters : health_data - data object to which the selected diet and its calories are added 
    return value : No
    
    operation : 1. provide the options for the diets to be selected
    			2. enter the selected diet and the total calories intake in the health data
*/

void inputDiet(HealthData* health_data) {
    int choice, i;
    
    FILE*loadDiets;//file pointer
    healthdata diets[100];//array of diets
    if(diet_list_size==0){
    	printf("No diets loaded.\n");
    	
	}//number of diets
	
	printf("Choose (1-7):"); //to ask the option
    
    // ToCode: to provide the options for the diets to be selected
    printf("The list of diets:\n");
    for(i=0;i<7;i++){
    	printf("%d. %s\n", i+1, diets[i].diet);
	}//printf of diets option
	
	loadDiets=fopen('diets.txt',"r");//file open
	if(loadDiets==NULL){
		printf("There is no file for diets!\n");
		return 0;
	}//to open the file
	
	scanf("%d", &choice);//to enter the diet option
	
	if(choice<1||choice>7){
		printf("Invalid choice!\n");
		fclose(loadDiets);//close the file
	}//user misselects option
    
    
	// ToCode: to enter the diet to be chosen with exit option
    

    // ToCode: to enter the selected diet in the health data
    strcpy(health_data->diet, diet_list[choice-1].food_name);
    // ToCode: to enter the total calories intake in the health data
    health_data->total_calories_intake=diet_list[choice-1].calories_intake;//save the selected diet calory
    
    fclose(loadDiets);
    


}

