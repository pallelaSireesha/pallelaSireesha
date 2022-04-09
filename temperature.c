// Using strtok() and CURL in a program to print the weatherreport of a given city.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LENGTH 150
#define CITY_NAME_LENGTH 25
#define WEATHER_LENGTH 1000
int main()
{
	char cityName[CITY_NAME_LENGTH];
	char command[LENGTH];
	char weatherReport[WEATHER_LENGTH];
	char *words;
	printf("Enter the city name: ");
	scanf("%s", cityName);
	sprintf(command, "curl -sk \"https://api.openweathermap.org/data/2.5/weather?q=%s&appid=a52817a2f4c1545dd63a8f157f8752b7&units=metric\">weather.txt", cityName);
	system(command);
	FILE *fpCurlweather;
	fpCurlweather = fopen("weather.txt", "r");
	fgets(weatherReport, WEATHER_LENGTH, fpCurlweather);
	words = strtok(weatherReport, ": ,");
	while (words != NULL)
	{
		// printf("%s\n", words);
		words = strtok(NULL, ": ,");
		if(strstr(words, "\"temp\"") != NULL)
		{
			printf("Temperature = ");
			words = strtok(NULL, ": ,");
			printf("%s degrees Celcius.", words);
			break;
		}
	}
	fclose(fpCurlweather);	
}
