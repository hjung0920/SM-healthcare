//
//  main.c
//  Calorie Diary
//
//  Created by Eunju Cha
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cal_exercise.h"
#include "cal_diets.h"
#include "cal_healthdata.h"

#define EXERCISEFILEPATH "exercises.txt"
#define DIETFILEPATH "diets.txt"
#define HEALTHFILEPATH "health_data.txt"

static int choice;
int total_intakeCalories=0;
int total_exercisesCalories=0;
int remainCalories=0;
int i;

typedef struct{
	int total_intakeCalories;
	int total_exercisesCalories;
	int remainCalories;
}Healthdata;//definition structure

typedef struct{
	char name[100];
	int calories;
}exercises;//definition exercises structure

typedef struct{
	char name[100];
	int calories;
}diets;//definition diets structure


printHealthData(HealthData* health_data){
	printf("Health Data:\n");
	printf("Total calories intake: %d kcal\n", health_data->total_calories_intake);
	printf("Total calories burned: %d kcal\n", health_data->total_calories_intake);
	printf("Basal Metabolic Rate: 1300 kal\n");
	printf("The remaining calories: %d\n", total_intakeCalories - total_exercisesCalories-1300);
}// health data function 

 

int main() {
	printf("[Healthcare Manage Systems]\n");
    printf("1. Exercise\n");
    printf("2. Diet\n");
    printf("3. Show logged information\n");
    printf("4. Exit\n");
    printf("Select the desired number:");
    	
    scanf("%d", &choice);
    
	// To initialize the health data object
    HealthData health_data = {0};
    
    // Tocode: to read the list of the exercises and diets
    FILE*loadExercises=fopen("exercises.txt","r");
    FILE*loadDiets=fopen("diets.txt","r");
    
    
   
    // ToCode: to run the "Healthcare Management Systems" until all calories are used up or the user wants to exit the system
    do {
    	int intakeCalories=0;
        int total_intakeCalories=0;
        int exerciseCalories=0;
        int total_exercisesCalories=0;
        int basal_metabolic_rate =1300;
        int remainCalories=0;

    
    	remainCalories = total_intakeCalories- total_exercisesCalories- 1300;
    	
    	
    	if (remainCalories<=0){
            printf("You have consumed all your calories for today! \n");
		} 
		else{
			printf("\n=======================================================================\n");
        	printf("[Healthcare Management Systems] \n");
        	printf("1. Exercise \n");
        	printf("2. Diet \n");
        	printf("3. Show logged information \n");
        	printf("4. Exit \n");
        	printf("Select the desired number: ");
        	scanf("%d", &choice);
        	printf("=======================================================================\n");
        }
        
		// ToCode: to run the sysmtem based on the user's choice
        switch (choice) {
            case 1:
            	loadExercises=fopen(EXERCISEFILEPATH, "r");
            	if(loadExercises==NULL){
            		printf("Exercise file not found.\n");
				}
				fclose(loadExercises);
                break;
                
            case 2:
            	loadDiets=fopen(DIETFILEPATH,"r");
            	if(loadDiets==NULL){
            		printf("Diet file not found.\n");
				}
				fclose(loadDiets);
                break;
                
            case 3:
            	printf("========================== History of Exercises ===================\n");
            	for(i=0;i<health_data.exercise_count;i++){
            		printf("Exercise: %s, Calories burned: %d kcal\n", exercises[i].name, exercises[i].calories);}
            	printf("=======================================================================\n");
            	
            	printf("========================== History of Diet ===================\n");
            	for(i=0;i<health_data.diet_count;i++){
            		printf("Food: %s, Calories intake: %d kcal\n", diets[i].name, diets[i].calories);}
            	printf("=======================================================================\n");
            	
            	printf("========================== Total Calories ===================\n");
            	printf("Basal Metabolic Rate: 1300 kcal\n");
            	printf("Total calories burned: %d kcal\n", health_data->total_calories_burned);
            	printf("Total calories intake: %d kcal\n", health_data->total_calories_intake);
            	printf("The remaining calories: %d kcal\n", remainCalories);
            	printf("=======================================================================\n");
            	break;
                //show logged information
            case 4:
            	
    			printf("Exit the system.\n");
    			printf("=======================================================================\n");
                break;
                exit(0);
                
                
            default:
                printf("[Error] Invalid option. \n");
                printf("Please try again! \n");
        }
    } while(choice<1||choice>4);

    return 0;
}

