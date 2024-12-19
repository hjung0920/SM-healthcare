//
//  cal_exercise.c
//  Excercise for Calorie Diary
//
//  Created by Eunju Cha
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cal_exercise.h"
#include "cal_diets.h"
#include "cal_healthdata.h"

#define MAX_EXERCISES 100  			// Maximum number of exercises
#define MAX_EXERCISE_NAME_LEN 50	// Maximum length of the name of exercise


// To declare the structure of the exercises
static Exercise exercise_list[MAX_EXERCISES];
int exercise_list_size = 0;


/*
    description : read the information in "excercises.txt"
*/

void loadExercises(const char* EXERCISEFILEPATH) {
    FILE *file = fopen(EXERCISEFILEPATH, "r");
    if (file == NULL) {
        printf("There is no file for exercises! \n");
        return;
    }

    // ToCode: to read a list of the exercises from the given file
    while (file==NULL ) {
    	
        if (exercise_list_size >= MAX_EXERCISES){
        	break;
		}
    }

    fclose(file);
}


/*
    description : to enter the selected exercise and the total calories burned in the health data
    input parameters : health_data - data object to which the selected exercise and its calories are added 
    return value : No
    
    operation : 1. provide the options for the exercises to be selected
    			2. enter the duration of the exercise
    			3. enter the selected exercise and the total calories burned in the health data
*/
typedef struct{
	char exercises[100];
	int exercisesCalories;
}healthdata;//determine structure

int getExercisesCalories(int choices[], int numChoices){
	int total_exercisesCalories=0;//total exercising calories
	int exercisesCalories[]={4,11,5,12,4,2};//calories of each option
	
	int i;
	for(i=0;i<numChoices;i++){
		int choice=choices[i];
	}// accumulate calories for selected each exercise
	return total_exercisesCalories; //return total exercising calories
}

void inputExercise(HealthData* health_data) {
    int choice, duration, i;
    int total_exercisesCalories=0;
    
    FILE*loadExercises;//file pointer
    healthdata exercises[100];//array of exercises
    if(exercise_list_size==0){
    	printf("No exercises loaded.\n");
    	return;
	}//number of exercises
	
	printf("Choose (1-7):");//to ask the option
    
    
    // ToCode: to provide the options for the exercises to be selected
    printf("The list of exercises: \n");
    for(i=0;i<7;i++){
    	printf("%d. %s\n", i+1, exercises[i].exercises);
	}//printf of exercises option
	
	loadExercises=fopen('exercises.txt',"r");//file open
	
	if(loadExercises==NULL){
		printf("There is no file for exercises!\n");
		
	}// to open the file
    
    // ToCode: to enter the exercise to be chosen with exit option
    
    scanf("%d", &choice);//to enter the exercises option
    
    if(choice<1||choice>7){
    	printf("Invalid choice!\n");
    	fclose(loadExercises);//close the file
	}//user misselects option

 
    // To enter the duration of the exercise
    printf("Enter the duration of the exercise (in min.): ");
    scanf("%d", &duration);
    
    int exercisesCalories=exercise_list[choice-1].calories_burned_per_minute*duration;
    total_exercisesCalories+=exercisesCalories;//to sum the exercises calories

    // ToCode: to enter the selected exercise and total calcories burned in the health data
    strcpy(health_data->exercises, exercises[choice-1].exercises);
    health_data[i].total_calories_burned=total_exercisesCalories;
    
    health_data->total_calories_burned=exercisesCalories;//to save exercises calories
    fclose(loadExercises);//to close the file
    
    

}
