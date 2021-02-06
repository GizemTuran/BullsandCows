
#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include "hands.h"



int main() {


	char ans;
	ans = 'y';
	int digit;
	char choice;
	struct hands* h;
	int index = 1;

	h = (struct hands*)malloc(sizeof(struct hands));


	while (ans == 'Y' || ans == 'y') {

		if (ans == 'Y' || ans == 'y')
		{
			printf("**Welcome to the Bulls and Cows game**\n");
			//To provide continue to the program for the same process//
			printf("enter digit: ");
			scanf("%d", &digit);
			generate_secret(h->secret, digit);
			h->index = index;
			bull_cow_game(h, digit);
			print_history(*h);

			printf("Do you want to play one more time?(Yes(Y)/No(N))>");
			scanf(" %c", &ans);

		}
		if (ans == 'N' || ans == 'n')

			break;


		index++;
	}


	return 0;

}

