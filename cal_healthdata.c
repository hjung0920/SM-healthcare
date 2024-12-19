//
//  cal_healthdata.c
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


/*
    description : enter the exercise and diet history in "health_data.txt" 
    input parameters : health_data - data object in which the selected exercise and diet is stored
    return value : No
    
    operation : 1. save the chosen exercise and total calories burned 
    			2. save the chosen diet and total calories intake 
    			3. save the total remaining calrories
*/
typedef struct{
	char exercises[100];
	int exercisesCalories;//exercises calories
	char diet[100];
	int intakeCalories;
	int total_intakeCalories;
	int remainCalories;//remain calories= intake calories - exerscises calories - 1300
}healthdata;//structure of health data

void saveData(const char* HEALTHFILEPATH, const HealthData* health_data) {
	int i;
	int remainCalories;
	
    FILE* file = fopen(HEALTHFILEPATH, "w");
    if (file == NULL) {
        printf("There is no file for health data.\n");
        return;
    }

    // ToCode: to save the chosen exercise and total calories burned 
    fprintf(file, "[Exercises] \n");
    fprintf(file, "%s - %d kcal\n", health_data->exercises, health_data->total_calories_burned);
    
    // ToCode: to save the chosen diet and total calories intake 
    fprintf(file, "\n[Diets] \n");
    fprintf(file, "%s - %d kcal\n", health_data->diet, health_data->total_calories_intake);

    // ToCode: to save the total remaining calrories
    fprintf(file, "\n[Total] \n");
    fprintf(file, "Basal metabolic rate - 1300 kcal\n");
    fprintf(file,"The remaining calories - %d kcal\n", remainCalories);
    
    fclose(file);//close the file
}

/*
    description : print the history of exercised and diets
    input parameters : health_data - data object in which the history of the exercise and diet is to be printed
    return value : No
    
    operation : 1. print out the saved history of exercises
    			2. print out the saved history of diets
    			3. print out the saved history of calories
*/

void printHealthData(const HealthData* health_data) {
	int i;
	int remainCalories=0;
	
	// ToCode: to print out the saved history of exercises
	printf("=========================== History of Exercise =======================\n");
	printf("Exercise: %s, Calories burned: %d kcal\n", health_data->exercises, health_data->total_calories_burned);
  
  
    printf("=======================================================================\n");

    // ToCode: to print out the saved history of diets
    printf("============================= History of Diet =========================\n");
    printf("Food: %s, Calories intake: %d kcal\n", health_data->diet, health_data->total_calories_intake);
    


    printf("=======================================================================\n");


	// ToCode: to print out the saved history of calories including basal metabolic rate, 
	// total calories burned, total calories intake, and the remaining calories
	printf("============================== Total Calories =========================\n");
	printf("Basal Metabolic Rate: 1300 kcal\n");
	printf("Total calories burned: %d kcal\n", health_data->total_calories_burned);
	printf("Total calories intake: %d kcal\n", health_data->total_calories_intake);
	printf("The remaining calories: %d kcal\n", remainCalories);
 
 
    printf("=======================================================================\n \n");
    
	
	// ToCode: to print out the recommendtaion depending on the current total calories burned and intake    
    
    
	printf("=======================================================================\n");
	if(remainCalories=0){
	 	printf("You have consumed all your calories for today!\n");
	 	exit(0); // end of system
	 }// remain calories=0
	 
	else if(remainCalories<0){
	 	printf("[Warning]Too few calories!\n");
	 	
	 	if(health_data->total_calories_intake==2000){
	 		printf("Your total calories intake for today has reached your goal!\n");}
	 	else if(health_data->total_calories_intake<2000){
	 		printf("Your total calories intake for today has not reached your goal, remember to eat more!\n");}
		else{
			printf("You have eaten more calories than planned today, but you have exercised too much!\n");}
		}//recommendation for remain calories <0
	
	else
	{   printf("Please exercise for your health!\n");
	    if(health_data->total_calories_intake==2000){
	    	printf("Your total calories intake for today has reached your goal!\n");}
	    else if(health_data->total_calories_intake<2000){
	    	printf("Your total calories intake for today has not reached your goal, remember to eat more!\n");}
	    	
	}//recommendation for remain calories >0

}
