#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "settings.h"

double target = 0.0;
double learnRate = 0.0;
int maxIterations = 0.0;

void loadSettings(const char *settingsFile){
	FILE *f = fopen(settingsFile, "r");
	if (!f){
		perror("Unable to open settings.ini");
		exit(EXIT_FAILURE);
	}
	char line[128];
	char key[64];
	double value;
	while(fgets(line, sizeof(line), f)) {
	if(sscanf(line, "%63[^=]= %lf", key, &value) == 2){
		if(strcmp(key, "target") == 0){
			target = value;
			printf("Value %lf loaded as the target prediction from settings.ini. \n", target);
		} else if(strcmp(key, "learnrate")==0) {
			learnRate = value;
			printf("Value %lf loaded as the learn rate from settings.ini. \n", learnRate);
		}
		else if(strcmp(key, "max_iterations")==0){
			maxIterations = (int)value;
			// printf("DEBUG: Loaded %lf, converted to int %d \n", value, maxIterations);
			printf("Maximum amount of iterations set to %d. \n", maxIterations);
		}
	}
	}
	fclose(f);
}

