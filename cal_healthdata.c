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
	int exerciseCalories; //burned calories 
	char diet[100];
	int dietCalories; // calories of diets
	int totalIntakeCalories; // total intake calories
	int remainingCalories; // remaining calories = intake calories -bmr- exercising calories
}healthdata; //structure of health data


void saveData(const char* HEALTHFILEPATH, const HealthData* health_data) {
	int i;
	int remainingCalories;
	
    FILE* file = fopen(HEALTHFILEPATH, "w");
    if (file == NULL) {
        printf("There is no file for health data.\n");
        return;
    }

    // ToCode: to save the chosen exercise and total calories burned 
    fprintf(file, "[Exercises] \n");
    fprintf(file,"Exercise: %s\n", health_data->exercises);
    fprintf(file,"Calories burned: %d\n", health_data->total_calories_burned);
    
    
    // ToCode: to save the chosen diet and total calories intake 
    fprintf(file, "\n[Diets] \n");
    fprintf(file, "Diet: %s\n", health_data->diet);
    fprintf(file, "Calories intake:%d\n", health_data->total_calories_intake);



    // ToCode: to save the total remaining calrories
    fprintf(file, "\n[Total] \n");
    
   
    fclose(file); //close the file
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
	int remainingCalories;
	
	remaingCalories= total_calories_intake - total_calories_burned -1300;
	
	// ToCode: to print out the saved history of exercises
	printf("=========================== History of Exercise =======================\n");
	printf("Exercise: %s\n", health_data->exercises); //exercise history
	printf("Calories burned: %d kcal\n", health_data->total_calories_burned); // burned calories history
    printf("=======================================================================\n");

    // ToCode: to print out the saved history of diets
    printf("============================= History of Diet =========================\n");
    printf("Diet: %s\n", health_data->diet); //diets history
    printf("Calories intake: %d kcal\n", health_data->total_calories_intake); //intake calories history
    printf("=======================================================================\n");


	// ToCode: to print out the saved history of calories including basal metabolic rate, 
	// total calories burned, total calories intake, and the remaining calories
	printf("============================== Total Calories =========================\n");
	printf("Total calories burned: %d kcal\n", health_data->total_calories_burned);//total calories burned
	printf("Total calories intake: %d kcal\n", health_data->total_calories_intake);//total calories intake
	printf("Remaining calories: %d\n", remaining calories);//remaining calories	
    printf("=======================================================================\n \n");
    
	
	// ToCode: to print out the recommendtaion depending on the current total calories burned and intake    
    
    
	printf("=======================================================================\n");
	if(remainingCalories=0){
	 	printf("You have consumed all your calories for today!\n");
	 	exit(0); //end of system
		 
		 }
		 
	else if(remainingCalories<0){
	 	printf("[Warning]Too few calories!"\n);
	 	if(health_data->total_calories_burned=2000){
		  printf("Your total calories intake for today has reached your goal!\n");}
		else if(health_data->total_calories_intake<2000){
			printf("Your total calories intake for today has not reached your goal, remember to eat more!\n");}
		else
		printf("You have eaten more calories than planned today, but you have exercised too much!\n");	
		 }
	else
	    printf("Please exercise for your health!\n");
	    if(health_data->total_calories_intake=2000){
	    	printf("Your total calories intake for today has reached your goal!\n");}
	    else if(health_data->total_calories_intake<2000){
	    	printf("Your total calories intake for today has not reached your goal, remember to eat more!");}
		
	 }
}
