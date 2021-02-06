#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include "hands.h"


void generate_secret(char* secret[], int digit) {  // To evaluate entered values
	int i, r_digit, found_n[] = { 0,0,0,0,0,0,0,0,0,0 }, number[10];
	char secr[11];
	srand(time(NULL));   // to prevent sequence repetition between runs
	char* num = (char*)malloc(sizeof(char) * 3);


	for (i = 0; i < digit;)
	{
		if (i == 0) {
			r_digit = (rand() % 9) + 1;  // returns a random positive integer in the range from 1 to 9
			found_n[r_digit] = 1;
			number[i] = r_digit;
			i++;
		}
		else
		{
			r_digit = rand() % 10;
			if (found_n[r_digit] == 0)
			{
				number[i] = r_digit;
				found_n[r_digit] = 1;
				i++;
			}
		}
	}
	sprintf(secr, "%d", number[0]);

	for (i = 1; i < digit; i++) {

		sprintf(num, "%d", number[i]);
		strcat(secr, num);

	}
	strcpy(secret, secr);  //function copies the string pointed by source

	printf("Ok, I have chosen a number... \n");

}

void bull_cow_game(struct hands* h, int digit) {   //It checks whether the desired conditions are met and also increases and decreases bull and cow values according to the number entered by the user


	int cow, bull;
	int res = 0, i, atp = 0;
	char control[11];

	while (res == 0) {

		bull = 0;
		cow = 0;

		printf("\nWhat is your guess:  ");
		scanf("%s", &control);


		if (strcmp(control, "quit") == 0) {   //To compare these two variables
			printf("You lose..\n");
			(*h).result = 0;
			return;
		}

		for (i = 0; i < digit; i++) {

			if (control[i] < '0' || control[i]>'9')

				printf("Contains non-numbers, try again...\n");
			break;


		}
		if (strlen(control) != digit) {   //To check length of digit

			printf("Guess must have length of %s, try again..\n",digit);

		}
		for (int d = 0; d < digit; d++) {
			for (int j = 0; j < digit; j++) {

				if (control[d] == h->secret[j]) {
					if (d == j) {
						bull++;


					}
					else {

						cow++;
					}
				}
			}
		}

		if (bull == digit) {

			strcpy(h->guess_list[atp], control);
			h->attempt_count = atp;

			atp++;
			printf("You win!...\n");
			h->result = 1;

			return;
		}
		else {

			printf("Bulls: %d and Cows: %d\n", bull, cow);
			strcpy(h->guess_list[atp], control);
			atp++;
			h->attempt_count = atp;
			h->result = 0;
		}
	}

}


void print_history(struct hands h) {  //To suppress all successful numbers entered


	FILE* f;
	int i = 0;

	if (h.index == 1)
	{
		f = fopen("histroy.txt", "w");
	}
	else {

		f = fopen("histroy.txt", "a");
	}
	fprintf(f, "%d ", h.index);
	fprintf(f, "%s  ", h.secret);
	for (i = 0; i < h.attempt_count; i++) {
		fprintf(f, " %s ", h.guess_list[i]);
	}
	fprintf(f, " %d ", h.attempt_count);
	fprintf(f, " %d \n", h.result);



	fclose(f);

}








