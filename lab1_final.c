// Lab1.cpp: определяет точку входа для консольного приложения.
//

#include "stdio.h"
#include "stdlib.h"
#include "string.h"

void clean_stdin(void)
{
	int c = 0;
	do
	{
		c = getchar();
	} while (c != '\n' && c != EOF);
}
int input_data_of_pupil(int element)
{
	int element1 = 0, n = 0;
	do
	{
		if (n != 0)
		{
			clean_stdin();
		}
		element1 = scanf("%d", &element);
		clean_stdin();
		if (element1 != 1 || element < 1 || element > 20)
		{
			printf("Incorrect input! Use number from 1 to 20: ");
			n = 1;
		}
	} while (element1 != 1 || element < 1 || element > 20);
	return element;
}
int input_data_of_class(int element)
{
	int element1 = 0, n = 0;
	do
	{
		if (n != 0)
		{
			clean_stdin();
		}
		element1 = scanf("%d", &element);
		clean_stdin();
		if (element1 != 1 || element < 1 || element > 11)
		{
			printf("Incorrect input! Use number from 1 to 11: ");
			n = 1;
		}
	} while (element1 != 1 || element < 1 || element > 11);
	return element;
}
char check_letter(char letter)
{
	do
	{
		clean_stdin;
		scanf("%c", &letter);
		clean_stdin;
		if (letter == ' ' || letter == EOF || letter == '\n')
		{
			printf("Incorrect input! Use symbol from A to Z: ");
		}
	} while (letter == ' ' || letter == EOF || letter == '\n');
	return letter;
}

struct pupil
{
	char name[10];
	char surname[15];
	char name_of_class;
	int number_of_class;
};
struct homonyms
{
	char homonyms_surname[15];
	int count;
};

int main()
{
	struct pupil *ppl;
	struct homonyms *cls;
	int number_of_pupils = 0, number_of_homonyms1 = 0, number_of_homonyms2 = 0, number_of_homonyms3 = 0;
	int i = 0, j = 0, temp = 0;
	printf("Input number of pupils in school: ");
	number_of_pupils = input_data_of_pupil(number_of_pupils);
	ppl = (struct pupil*)calloc(number_of_pupils, sizeof(struct pupil));
	cls = (struct homonyms*)calloc(number_of_pupils, sizeof(struct homonyms));
	if (!ppl || !cls)
	{
		printf("Memory hasn't designed");
		free(cls);
		free(ppl);
		exit;
	}
	printf("\nInput characteristics of even pupil: ");
	for (i = 0; i < number_of_pupils; i++)
	{
		printf("\nInput number of the class of the %d pupil: ", i + 1);
		ppl[i].number_of_class = input_data_of_class(ppl[i].number_of_class);
		printf("Input letter of the class of the %d pupil: ", i + 1);
		ppl[i].name_of_class = check_letter(ppl[i].name_of_class);
		printf("Input name of the %d pupil: ", i + 1);
		clean_stdin;
		fgets(ppl[i].name, 10, stdin);
		fgets(ppl[i].name, 10, stdin);
		printf("Input surname of the %d pupil: ", i + 1);
		clean_stdin;
		fgets(ppl[i].surname, 15, stdin);
	}
	for (i = 0; i < (number_of_pupils - 1); i++)
	{
		number_of_homonyms1 = 1;
		for (j = 1; j < number_of_pupils; j++)
		{
			temp = strcmp(ppl[i].surname, ppl[j].surname);
			if (temp == 0)
			{
				number_of_homonyms1++;
				strcpy(cls[i].homonyms_surname, ppl[j].surname);
			}
		}
		cls[i].count = number_of_homonyms1;
		printf("The number of homonyms with %s\r surnames are: %d\n", cls[i].homonyms_surname, cls[i].count);
	}
	if (number_of_homonyms1 == 1)
	{
		printf("There are not homonyms in the school\n");
		return 0;
	}
	for (i = 0; i < (number_of_pupils - 1); i++)
	{
		number_of_homonyms2 = 1;
		for (j = 1; j < number_of_pupils; j++)
		{
			temp = strcmp(ppl[i].surname, ppl[j].surname);
			if ((temp == 0) && (ppl[i].number_of_class == ppl[j].number_of_class))
			{
				number_of_homonyms2++;
				strcpy(cls[i].homonyms_surname, ppl[j].surname);
			}
		}
		if (number_of_homonyms1 == 1)
		{
			printf("There are not homonyms in the parallel classes\n");
			return 0;
		}
		cls[i].count = number_of_homonyms2;
		printf("The number of homonyms with %s\r surnames in parallel classes are: %d\n", cls[i].homonyms_surname, cls[i].count);
	}
	if (number_of_homonyms2 == 1)
	{
		printf("There are not homonyms in parallel classes\n");
		return 0;
	}
	for (i = 0; i < (number_of_pupils - 1); i++)
	{
		number_of_homonyms3 = 1;
		for (j = 1; j < number_of_pupils; j++)
		{
			temp = strcmp(ppl[i].surname, ppl[j].surname);
			if ((temp == 0) && (ppl[i].number_of_class == ppl[j].number_of_class) && (ppl[i].name_of_class == ppl[j].name_of_class))
			{
				number_of_homonyms3++;
				strcpy(cls[i].homonyms_surname, ppl[j].surname);
			}
		}
		cls[i].count = number_of_homonyms3;
		printf("The number of homonyms with %s\r surnames in one class are: %d\n", cls[i].homonyms_surname, cls[i].count);
	}
	if (number_of_homonyms3 == 1)
	{
		printf("There are not homonyms in the one class\n");
		return 0;
	}
	free(ppl);
	free(cls);
	system("pause");
	return 0;
}
