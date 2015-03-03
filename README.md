// Lab1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "stdlib.h"
#include "string.h"

int input_data_of_pupil(int element); 
int input_data_of_class(int element);

struct pupil
{
	char name[10];
	char surname[15];
	char name_of_class;
	int number_of_class;
};

int _tmain(int argc, _TCHAR* argv[])
{
	struct pupil *ppl;
	int number_of_pupils = 0, number_of_homonyms1 = 0, number_of_homonyms2 = 0;
	int i = 0, j = 0;
	printf("Input number of pupils in school: ");
	number_of_pupils = input_data_of_pupil(number_of_pupils);
	ppl = (pupil*)calloc(number_of_pupils, sizeof(pupil));
	if (!ppl)
	{
		printf("Memory hasn't designed");
		exit;
	}
	printf("\nInput characteristics of even pupil: ");
	for (i = 0; i < number_of_pupils; i++)
	{
		printf("\nInput number of the class of the %d pupil: ", i + 1);
		ppl[i].number_of_class = input_data_of_class(ppl[i].number_of_class);
		printf("Input letter of the class of the %d pupil: ", i + 1);
		scanf("%c", &ppl[i].name_of_class);
		printf("Input name of the %d pupil: ", i + 1);
		fflush(stdin);
		fgets(ppl[i].name, 10, stdin);
		printf("Input surname of the %d pupil: ", i + 1);
		fflush(stdin);
		fgets(ppl[i].surname, 15, stdin);
	}
	for (i = 0; i < (number_of_pupils - 1); i++)
	{
		for (j = 0; j < number_of_pupils; j++)
		{
			if (strcmp(ppl[i].surname, ppl[j].surname))
			{
				number_of_homonyms1++;
				break;
			}
		}
	}
	printf("\nNumber of homonyms in school: %d ", number_of_homonyms1);
	for (i = 0; i < (number_of_pupils - 1); i++)
	{
		for (j = 0; j < number_of_pupils; j++)
		{
			if ((strcmp(ppl[i].surname, ppl[j].surname)) && (ppl[i].number_of_class == ppl[j].number_of_class))
			{
				number_of_homonyms2++;
				break;
			}
		}
	}
	printf("\nNumber of homonyms in parallel classes: %d \n", number_of_homonyms2);
	system("pause");
	return 0;
}

int input_data_of_pupil(int element)
{
	int element1 = 0;
	do
	{
		fflush(stdin);
		element1 = scanf("%d", &element);
		fflush(stdin);
		if (element1 != 1 || element < 1 || element > 20)
		{
			printf("/nIncorrect input! Use number from 1 to 20: ");
		}
	} while (element1 != 1 || element < 1 || element > 20);
	return element;
}
int input_data_of_class(int element)
{
	int element1 = 0;
	do
	{
		fflush(stdin);
		element1 = scanf("%d", &element);
		fflush(stdin);
		if (element1 != 1 || element < 1 || element > 11)
		{
			printf("\nIncorrect input! Use number from 1 to 11: ");
		}
	} while (element1 != 1 || element < 1 || element > 11);
	return element;
}
