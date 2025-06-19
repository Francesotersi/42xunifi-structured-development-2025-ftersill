#include "grade_mapping.h"

void insert_plus_minus(const int score, char grade, char **mapped_grades, int i)
{
	mapped_grades[i][2] = '\0';
	mapped_grades[i][0] = grade;
	if (score % 10 >= 3 && score % 10 <= 6)
		mapped_grades[i][1] = '\0';
	else if (score % 10 >= 7 || score == 100)
		mapped_grades[i][1] = '+';
	else if (score % 10 <= 2)
		mapped_grades[i][1] = '-';
}

void plusminus(const int *scores, int size, const char **mapped_grades)
{
	for (int i = 0; i < size; i++)
	{
		if (scores[i] >= 90)
			insert_plus_minus(scores[i], 'A', (char **)mapped_grades, i);
		else if (scores[i] >= 80)
			insert_plus_minus(scores[i], 'B', (char **)mapped_grades, i);
		else if (scores[i] >= 70)
			insert_plus_minus(scores[i], 'C', (char **)mapped_grades, i);
		else if (scores[i] >= 60)
			insert_plus_minus(scores[i], 'D', (char **)mapped_grades, i);
		else
			mapped_grades[i] = "F";
	}
}

void standard(const int *scores, int size, const char **mapped_grades)
{
	for (int i = 0; i < size; i++)
	{
		if (scores[i] >= 90)
			mapped_grades[i] = "A";
		else if (scores[i] >= 80)
			mapped_grades[i] = "B";
		else if (scores[i] >= 70)
			mapped_grades[i] = "C";
		else if (scores[i] >= 60)
			mapped_grades[i] = "D";
		else
			mapped_grades[i] = "F";
	}
}

void passfail(const int *scores, int size, const char **mapped_grades)
{
	for (int i = 0; i < size; i++)
	{
		if (scores[i] >= 60)
			mapped_grades[i] = "P";
		else
			mapped_grades[i] = "F";
	}
}

// ongni stringa della matrice mapped_grades deve essere allocata con spazio sufficiente
// per contenere il voto e il terminatore null (ad esempio, 3 caratteri per il voto con 
// segno più o meno, o 2 caratteri per il voto standard o pass/fail).
void map_scores(const int *scores, int size, GradeMapper mapper, const char **mapped_grades)
{
	if (mapper.mapper_type == PLUSMINUS)
		plusminus(scores, size, mapped_grades);
	else if (mapper.mapper_type == STANDARD)
		standard(scores, size, mapped_grades);
	else if (mapper.mapper_type == PASSFAIL)
		passfail(scores, size, mapped_grades);
}

// #include <stdio.h>
// #include <stdlib.h>
// #include "grade_mapping.h"

// void print_results(const int *scores, const char **grades, int size)
// {
// 	printf("Scores: ");
// 	for (int i = 0; i < size; i++)
// 	{
// 		printf("%3d ", scores[i]);
// 	}
// 	printf("\nGrades: ");
// 	for (int i = 0; i < size; i++)
// {
// 		printf("%3s ", grades[i]);
// 	}
// 	printf("\n\n");
// }

// void test_mapping(GradeMapper mapper, const int *scores, int size)
// {
// 	const char **mapped_grades = malloc(size * sizeof(char *));
// 	for (int i = 0; i < size; i++) {
// 		mapped_grades[i] = malloc(3 * sizeof(char));
// 	}
// 	map_scores(scores, size, mapper, mapped_grades);
// 	printf("Testing %s:\n", 
// 		   mapper.mapper_type == PLUSMINUS ? "PLUSMINUS" :
// 		   mapper.mapper_type == STANDARD ? "STANDARD" : "PASSFAIL");
// 	print_results(scores, mapped_grades, size);
// }

// int main()
// {

// 	int test_scores[] = {95, 87, 73, 66, 52, 100, 0, 82, 77, 60};
// 	int size = sizeof(test_scores) / sizeof(test_scores[0]);

// 	GradeMapper plusminus_mapper = {PLUSMINUS};
// 	GradeMapper standard_mapper = {STANDARD};
// 	GradeMapper passfail_mapper = {PASSFAIL};

// 	test_mapping(plusminus_mapper, test_scores, size);
// 	test_mapping(standard_mapper, test_scores, size);
// 	test_mapping(passfail_mapper, test_scores, size);

// 	int edge_scores[] = {59, 60, 61, 69, 70, 71, 79, 80, 81, 89, 90, 91, 99, 100};
// 	int edge_size = sizeof(edge_scores) / sizeof(edge_scores[0]);

// 	printf("\nTesting edge cases:\n");
// 	test_mapping(plusminus_mapper, edge_scores, edge_size);
// 	test_mapping(standard_mapper, edge_scores, edge_size);
// 	test_mapping(passfail_mapper, edge_scores, edge_size);

// 	return 0;
// }
