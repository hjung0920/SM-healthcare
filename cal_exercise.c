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
    while (file==NULL) {
    	
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
	int exerciseCalories;
}healthdata; //determine structure

int getExerciseCalories(int choices[], int numChoices){
	int totalExercisesCalories=0; //total consuming calories by exercising
	int exerciseCalories[]={4,11,5,12,4,2}; //calories of each option
	
	int i;
	for(i=0;i<numChoices;i++){
		int choice=choices[i];
	} //accumulate calories for selected each exercise
	
	return totalExercisesCalories; //return total consuming calories by exercising
}

void inputExercise(HealthData* health_data) {
    int choice, duration, i;
    int totalExercisesCalories=0;
    
    FILE*loadExercises; //file pointer
    healthdata exercises[100]; //array of diets
    int size=0; // number of read exercises
    
    printf("Choose (1-7):"); //to ask the option
    
    // ToCode: to provide the options for the exercises to be selected
    printf("The list of exercises: \n");
    for(i=0;i<size;i++){
    	printf("%d. %s\n", i+1, exercises[i].exercises);
	} //printf of exercises option
	
	loadExercises=fopen('exercises.txt',"r"); //file open
	
	
	if(loadExercises==NULL){
		printf("There is no file for exercises!\n");
		return ;
	} // to open the file
	



    // ToCode: to enter the exercise to be chosen with exit option
    
    scanf("%d", &choice); //to enter the exercises option
    
    if(choice<1||choice>size){
    	printf("Invalid choice!\n");
    	fclose(loadExercises); //close the file
    	return;
	} // user misselects option

    
    // To enter the duration of the exercise
    printf("Enter the duration of the exercise (in min.): ");
    scanf("%d", &duration);

    // ToCode: to enter the selected exercise and total calcories burned in the health data
    strcpy(health_data->exercises, exercises[choice-1].exercises);
    
    int exerciseCalories=getExercisesCalories(exercises,size,exercises);
    totalExercisesCalories+=exercises[choice-1].exercises; //total exercise calories
    
    fclose(loadExercises); //to close the file

}
