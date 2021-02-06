
#ifndef HANDS_H
#define HANDS_H

struct hands {

	int index;
	char secret[11];
	char guess_list[20][20];
	int attempt_count;
	int result;

};

void generate_secret(char* secret[], int digit);
void bull_cow_game(struct hands** h, int digit);
void print_history(struct hands h);




#endif