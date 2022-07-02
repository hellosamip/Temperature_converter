// Temperature converter. {Version 1}
#include<stdio.h>
int main(void);
int output(int, int, float);

// The functions strating from  line 7 to 30 are for specific calculations.
float getme_CF(float first_temp) {
	return (first_temp * 1.8) + 32;
}

float getme_CK(float first_temp) {
	return first_temp + 273.15;
}

float getme_FK(float first_temp) {
	return (5/9) * (first_temp - 32) + 273;
}

float getme_FC(float first_temp) {
	return (first_temp - 32) * 0.5556;
}


float getme_KC(float first_temp) {
	return first_temp - 273.15;
}

float getme_KF(float first_temp) {
	return 1.8*(first_temp-273) + 32;
}

// The route function is to determine particular function for calculation.
float route(int x, int y, float first_temp) {
	if (x == 1) {
		if (y == 2) {
			return getme_CF(first_temp);
		}
		else {
			return getme_CK(first_temp);
		}
	}
	
	if (x == 2) {
		if (y == 1) {
			return getme_FC(first_temp);
		}
		else {
			return getme_FK(first_temp);
		}	
	}
	
	if (x == 3) {
		if (y == 1) {
			return getme_KC(first_temp);
		}
		else if (y == 2) {
			return getme_KF(first_temp);
		}
	}
}

// This function is used in order to get unit while printing.
char *getme_unit (int x) {
	if (x == 1) {
		return "Celsius";
	}
	else if (x == 2) {
		return "Fahrenheit";
	}
	else if (x == 3) {
		return "Kelvin";
	}
}

// This function is for output of information.
int output(int x, int y, float first_temperature) {
	if (x < 3  &&  y < 3 ) {
		printf("%f degree %s is equal to %f degree %s.\n", first_temperature, getme_unit(x), route(x, y, first_temperature), getme_unit(y));
	}
	else if (x == 3){
		printf("%f Kelvin is equal to %f degree %s.\n", first_temperature, route(x, y, first_temperature), getme_unit(y));
	} 
	else if (y == 3) {
		printf("%f degree %s is equal to %f Kelvin.\n", first_temperature, getme_unit(x), route(x, y, first_temperature));
	}
	else {
		printf("Invalid operation!\n");
	}
}

int main(void) {
	int x,y;
	float first_temperature;
	printf("\t\tTemperature converter \n\t\t~~~~~~~~~~~~~~~~~~~~~\n");
	
	printf("Choose the initial unit: \n");
	printf("1.Celsius \n2.Fahrenheit \n3.Kelvin\n");
	scanf("%d", &x);
	printf("~~~~~~~~~~~~~~~~~~~~\n\n");
	
	printf("Temperature in %s: \n", getme_unit(x));
	scanf("%f", &first_temperature);
	printf("~~~~~~~~~~~~~~~~~~~~\n\n");
	
	printf("Choose the final unit: \n{Input 0 to get all the possible conversions}\n");
	printf("1.Celsius \n2.Fahrenheit \n3.Kelvin\n");
	scanf("%d", &y);
	printf("~~~~~~~~~~~~~~~~~~~~\n\n");
	if (x!=y) {
		output(x, y, first_temperature);
	}
	else {
		printf("Conversion is not necessary.\a\n");
	}
	main();
}