/*
 * Author: Harman Sihota
 * Student Number: 99773566

 * Purpose: To quiz the user on trivia questions and give them a score for each correct answer. The all time highest score achieved
   by any user can also be seen.
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define PLAY 1
#define CHECK_HIGHSCORE 2
#define INFO 3
#define QUIT 4
#define EASY 5
#define MEDIUM 6
#define HARD 7
#define MAX_SIZE 50

int startScreen(void);
int modeSelect(void);
void displayScore(void);
void checkHiscore(int score);
void infoScreen(void);
int easyMode(int score);
int mediumMode(int score);
int hardMode(int score);
int buildingQuestion(int score);
int sportsQuestion(int score);
int techQuestion(int score);
int chemQuestion(int score);
int historyQuestion(int score);
int geographyQuestion(int score);
int wildlifeQuestion(int score);
int astronomyQuestion(int score);
int weaponQuestion(int score);
int earthQuestion(int score);
int geographyQuestion2(int score);
int shapeQuestion(int score);
int flagQuestion(int score);
int historyQuestion2(int score);
int animalQuestion2(int score);
int natureQuestion(int score);

int main(void) {
	int score = 0;
	char proceed;
	int choice;
	

	while (TRUE) {
		choice = startScreen();

		if (choice == EASY) {
			score = 0;
			score = easyMode(score);
		}

		if (choice == MEDIUM) {
			score = 0;
			score = mediumMode(score);
		}

		if (choice == HARD) {
			score = 0;
			score = hardMode(score);
		}

		if (choice == QUIT)
			return 0;

		printf("\nYou achieved a total score of %d!\n\n", score);
		checkHiscore(score);

		printf("Enter any key to return to the main menu\n");
		scanf(" %c", &proceed);
	}


	system("PAUSE");
	return 0;
}

/*
 * Displays menu and allows user to choose what they would like to do. This includes starting a game, viewing the high score, acessing a 
 * help page, and quitting the game.
 * Returns - The option in the menu the user chose.
 */
int startScreen(void) {
	int option;
	
	printf("\n\n\n\t\t\t\t\t\t    *******************\n");
	printf("\t\t\t\t\t\t    *\t QUIZ MANIA   *\n");
	printf("\t\t\t\t\t\t    *******************\n");

	printf("Welcome to Quiz Mania!\n\n");
	printf("Select an option: \n\n");
	printf("Play (1)\n");
	printf("View Hiscores (2)\n");
	printf("Info (3)\n");
	printf("Quit (4)\n\n");

	scanf("%d", &option);

	while (option != PLAY && option != CHECK_HIGHSCORE && option != INFO && option != QUIT) {

		printf("That is not a valid entry, please choose again\n");
		scanf("%d", &option);
	}

	if (option == PLAY) {
		option = modeSelect();
		return option;
	}

	else if (option == CHECK_HIGHSCORE)
		displayScore();

	else if (option == INFO)
		infoScreen();

	else if (option == QUIT)
		return QUIT;

	option = startScreen();
}

/*
 * Displays the different difficulties of the game and allows the user to chose which one they would like to play.
 * Returns - the difficulty the user chose.
 */
int modeSelect(void) {
	int selection;

	printf("\nSelect a difficulty: \n");
	printf("Easy (5) \nMedium (6) \nHard (7)\n");

	scanf("%d", &selection);

	while (selection != EASY && selection != MEDIUM && selection != HARD) {
		printf("That is not a valid entry, please choose again\n");
		scanf("%d", &selection);
	}

	return selection;
}

/*
 * Displays a help page describing how to play the game and how the game works.
 */
void infoScreen(void) {
	char leave;

	printf("This is a trivia quiz. You will be awarded points each time you answer a question correct. The objective of the game\n");
	printf("is to answer as many questions correctly as possible accumulating a high score. There are three levels of difficulty\n\n");
	printf("Easy: More simple questions that award you 100 points for each correct answer\n");
	printf("Medium: Moderately difficult questions that award you 200 points for each correct answer\n");
	printf("Hard: Difficult questions that award you 400 points for each correct answer\n\n");

	printf("You can view the highest score to date from the menu and if you beat it, your name can be there!\n\nEnjoy!\n\n");

	printf("Enter any key to return to the menu\n");
	scanf(" %c", &leave);

	return;
}

/*
 * After the user completes a game, checks their score against the all time highscore saved in a file. If score is higher than highscore,
 * a message is displayed and the user is prompted to enter a username and their new highscore is saved under that username.
 * Parameter - The score the user as accumulated.
 */
void checkHiscore(int score) {
	FILE* hiscoreFile;
	int scoreVal;
	char username[MAX_SIZE];

	hiscoreFile = fopen("hiscore.txt", "r");

	if (hiscoreFile == NULL) {
		printf("There was an error opening the file, closing menu...\n");
		return;
	}

	else {
		fscanf(hiscoreFile, "%d", &scoreVal);

		if (score > scoreVal) {
			printf("\nCongratualtions! You have achieved the top score!\n");
			printf("Please enter your username: ");
			
			scanf(" %s", username);
			
			hiscoreFile = fopen("hiscore.txt", "w");

			fprintf(hiscoreFile, "%d...................%s", score, username);
		}
			
	}

	fclose(hiscoreFile);

	return;

}

/*
 * Displays current all time highscore.
 */
void displayScore(void) {
	FILE* hiscoreFile;
	char hiscoreMsg[MAX_SIZE];
	char leave;

	hiscoreFile = fopen("hiscore.txt", "r");

	if (hiscoreFile == NULL) {
		printf("There was an error opening the file, closing menu...\n");
		return;
	}

	else {
		fscanf(hiscoreFile, "%[^\n]", hiscoreMsg);
		printf("\n%s\n\n", hiscoreMsg);
	}

	printf("Enter any key to return to the menu\n");
	scanf(" %c", &leave);

	fclose(hiscoreFile);

	return;
}

/*
 * Displays all 'easy' questions and prompts user to answer, adding to their score if their answer is correct.
 * Returns - The score of the user after answering all of the 'easy' questions.
 */ 
int easyMode(int score) {
	
	score = astronomyQuestion(score);
	score = chemQuestion(score);
	score = historyQuestion(score);
	score = geographyQuestion2(score);
	score = shapeQuestion(score);
	score = flagQuestion(score);

	return score;
}

/*
 * Displays all 'hard' questions and prompts user to answer, adding to their score if their answer is correct.
 * Returns - The score of the user after answering all of the 'easy' questions.
 */
int mediumMode(int score) {
	score = techQuestion(score);
	score = wildlifeQuestion(score);
	score = buildingQuestion(score);
	score = sportsQuestion(score);
	score = geographyQuestion(score);
	score = earthQuestion(score);

	return score;
}

/*
 * Displays all 'hard' questions and prompts user to answer, adding to their score if their answer is correct.
 * Returns - The score of the user after answering all of the 'easy' questions.
 */
int hardMode(int score) {
	score = weaponQuestion(score);
	score = historyQuestion2(score);
	score = animalQuestion2(score);
	score = natureQuestion(score);
	
	return score;
}

/*
 * Displays a question about buildings and possible answers. If the user enters the letter corresponding to the correct answer,
 * points are added to their score.
 * Returns - The user's score after anwering the question
 * Parameter - The user's score before the question
 */
int buildingQuestion(int score) {
	char ans;
	
	printf("\n\nWhich of these buildings is the talllest building in North America? \n");
	printf("\n A. CN Tower \t\t\t B. One World Trade Center");
	printf("\n C. Empire State Building  \t D. Willis Tower\n\n");

	scanf(" %c", &ans);

	if (ans == 'B' || ans == 'b') {
		score += 200;
		printf("\nThat is the correct answer!\n\n");
		printf("Your score is now %d\n\n", score);
	}

	else {
		printf("\nThat is incorrect\n");
		printf("Your score is %d\n", score);
	}

	return score;
}

/*
 * Displays a question about sports and possible answers. If the user enters the letter corresponding to the correct answer,
 * points are added to their score.
 * Returns - The user's score after anwering the question
 * Parameter - The user's score before the question
 */
int sportsQuestion(int score) {
	char ans;

	printf("\n\nWhich of these NBA Players has the record for most points scored of all time? \n");
	printf("\n A. Michael Jordan \t\t B. Kobe Bryant");
	printf("\n C. Kareem Abdul Jabbar  \t D. John Stockton\n\n");

	scanf(" %c", &ans);

	if (ans == 'C' || ans == 'c') {
		score += 200;
		printf("\nThat is the correct answer!\n\n");
		printf("Your score is now %d\n\n", score);
	}

	else {
		printf("\nThat is incorrect\n");
		printf("Your score is %d\n", score);
	}

	return score;

}

/*
 * Displays a question about technology and possible answers. If the user enters the letter corresponding to the correct answer,
 * points are added to their score.
 * Returns - The user's score after anwering the question
 * Parameter - The user's score before the question
 */
int techQuestion(int score) {
	char ans;

	printf("\n\nWhat year was the first iPhone released? \n");
	printf("\n A. 2005 \t\t\t B. 2006");
	printf("\n C. 2007  \t\t\t D. 2008\n\n");

	scanf(" %c", &ans);

	if (ans == 'C' || ans == 'c') {
		score += 200;
		printf("\nThat is the correct answer!\n\n");
		printf("Your score is now %d\n\n", score);
	}

	else {
		printf("\nThat is incorrect\n");
		printf("Your score is %d\n", score);
	}

	return score;
}

/*
 * Displays a question about chemistry and possible answers. If the user enters the letter corresponding to the correct answer,
 * points are added to their score.
 * Returns - The user's score after anwering the question
 * Parameter - The user's score before the question
 */
int chemQuestion(int score) {
	char ans;

	printf("\n\nWhat element do the letters 'Cl' represent on the periodic table? \n");
	printf("\n A. Oxygen \t\t\t B. Chlorine");
	printf("\n C. Carbon  \t\t\t D. Cadmium\n\n");

	scanf(" %c", &ans);

	if (ans == 'B' || ans == 'b') {
		score += 100;
		printf("\nThat is the correct answer!\n\n");
		printf("Your score is now %d\n\n", score);
	}

	else {
		printf("\nThat is incorrect\n");
		printf("Your score is %d\n", score);
	}

	return score;
}

/*
 * Displays a question about history and possible answers. If the user enters the letter corresponding to the correct answer,
 * points are added to their score.
 * Returns - The user's score after anwering the question
 * Parameter - The user's score before the question
 */
int historyQuestion(int score) {
	char ans;

	printf("\n\nIn what year was the declaration of independance written? \n");
	printf("\n A. 1867 \t\t\t B. 1778");
	printf("\n C. 1801  \t\t\t D. 1776\n\n");

	scanf(" %c", &ans);

	if (ans == 'D' || ans == 'd') {
		score += 100;
		printf("\nThat is the correct answer!\n\n");
		printf("Your score is now %d\n\n", score);
	}

	else {
		printf("\nThat is incorrect\n");
		printf("Your score is %d\n", score);
	}

	return score;
}

/*
 * Displays a question about geography and possible answers. If the user enters the letter corresponding to the correct answer,
 * points are added to their score.
 * Returns - The user's score after anwering the question
 * Parameter - The user's score before the question
 */
int geographyQuestion(int score) {
	char ans;

	printf("\n\nHow many countries are in Africa? \n");
	printf("\n A. 68 \t\t\t B. 59");
	printf("\n C. 48  \t\t D. 54\n\n");

	scanf(" %c", &ans);

	if (ans == 'D' || ans == 'd') {
		score += 200;
		printf("\nThat is the correct answer!\n\n");
		printf("Your score is now %d\n\n", score);
	}

	else {
		printf("\nThat is incorrect\n");
		printf("Your score is %d\n", score);
	}

	return score;
}

/*
 * Displays a question about wildlife and possible answers. If the user enters the letter corresponding to the correct answer,
 * points are added to their score.
 * Returns - The user's score after anwering the question
 * Parameter - The user's score before the question
 */
int wildlifeQuestion(int score) {
	char ans;

	printf("\n\nWhich of these animals cannot be found in Canada? \n");
	printf("\n A. Grizzly Bear \t\t\t B. Marmot");
	printf("\n C. Shoebill  \t\t\t\t D. Bison\n\n");

	scanf(" %c", &ans);

	if (ans == 'C' || ans == 'c') {
		score += 200;
		printf("\nThat is the correct answer!\n\n");
		printf("Your score is now %d\n\n", score);
	}

	else {
		printf("\nThat is incorrect\n");
		printf("Your score is %d\n", score);
	}

	return score;
}

/*
 * Displays a question about astronomy and possible answers. If the user enters the letter corresponding to the correct answer,
 * points are added to their score.
 * Returns - The user's score after anwering the question
 * Parameter - The user's score before the question
 */
int astronomyQuestion(int score) {
	char ans;

	printf("\n\nWhat is the fifth planet from the sun? \n");
	printf("\n A. Jupiter \t\t\t B. Saturn");
	printf("\n C. Earth  \t\t\t D. Mars\n\n");

	scanf(" %c", &ans);

	if (ans == 'A' || ans == 'a') {
		score += 100;
		printf("\nThat is the correct answer!\n\n");
		printf("Your score is now %d\n\n", score);
	}

	else {
		printf("\nThat is incorrect\n");
		printf("Your score is %d\n", score);
	}

	return score;
}

/*
 * Displays a question about weapons and possible answers. If the user enters the letter corresponding to the correct answer,
 * points are added to their score.
 * Returns - The user's score after anwering the question
 * Parameter - The user's score before the question
 */
int weaponQuestion(int score) {
	char ans;

	printf("\n\nWhat type of weapon is a falchion? \n");
	printf("\n A. Sword \t\t\t B. Gun");
	printf("\n C. Fighter Jet  \t\t D. Tank\n\n");

	scanf(" %c", &ans);

	if (ans == 'A' || ans == 'a') {
		score += 400;
		printf("\nThat is the correct answer!\n\n");
		printf("Your score is now %d\n\n", score);
	}

	else {
		printf("\nThat is incorrect\n");
		printf("Your score is %d\n", score);
	}

	return score;
}

/*
 * Displays a question about the earth and possible answers. If the user enters the letter corresponding to the correct answer,
 * points are added to their score.
 * Returns - The user's score after anwering the question
 * Parameter - The user's score before the question
 */
int earthQuestion(int score) {
	char ans;

	printf("\n\nWhich of the following is the closest to the diameter of the earth in kilometeres? \n");
	printf("\n A. 10,000 \t\t\t B. 11,000");
	printf("\n C. 9,500  \t\t\t D. 12,500\n\n");

	scanf(" %c", &ans);

	if (ans == 'D' || ans == 'd') {
		score += 200;
		printf("\nThat is the correct answer!\n\n");
		printf("Your score is now %d\n\n", score);
	}

	else {
		printf("\nThat is incorrect\n");
		printf("Your score is %d\n", score);
	}

	return score;
}

/*
 * Displays a question about geography and possible answers. If the user enters the letter corresponding to the correct answer,
 * points are added to their score.
 * Returns - The user's score after anwering the question
 * Parameter - The user's score before the question
 */
int geographyQuestion2(int score) {
	char ans;

	printf("\n\nWhich of the following is the largest continent in the world? \n");
	printf("\n A. Asia \t\t\t B. Australia");
	printf("\n C. North America  \t\t D. Europe\n\n");

	scanf(" %c", &ans);

	if (ans == 'A' || ans == 'a') {
		score += 100;
		printf("\nThat is the correct answer!\n\n");
		printf("Your score is now %d\n\n", score);
	}

	else {
		printf("\nThat is incorrect\n");
		printf("Your score is %d\n", score);
	}

	return score;
}

/*
 * Displays a question about shapes and possible answers. If the user enters the letter corresponding to the correct answer,
 * points are added to their score.
 * Returns - The user's score after anwering the question
 * Parameter - The user's score before the question
 */
int shapeQuestion(int score) {
	char ans;

	printf("\n\nHow many sides does a hexagon have? \n");
	printf("\n A. 6 \t\t\t B. 7");
	printf("\n C. 8  \t\t\t D. 4\n\n");

	scanf(" %c", &ans);

	if (ans == 'A' || ans == 'a') {
		score += 100;
		printf("\nThat is the correct answer!\n\n");
		printf("Your score is now %d\n\n", score);
	}

	else {
		printf("\nThat is incorrect\n");
		printf("Your score is %d\n", score);
	}

	return score;
}

/*
 * Displays a question about flags and possible answers. If the user enters the letter corresponding to the correct answer,
 * points are added to their score.
 * Returns - The user's score after anwering the question
 * Parameter - The user's score before the question
 */
int flagQuestion(int score) {
	char ans;

	printf("\n\nWhat colours does the United Kingdoms flag consist of? \n");
	printf("\n A. green, yellow, orange \t\t B. blue, red, white");
	printf("\n C. blue and red \t\t\t D. white, red, orange\n\n");

	scanf(" %c", &ans);

	if (ans == 'B' || ans == 'b') {
		score += 100;
		printf("\nThat is the correct answer!\n\n");
		printf("Your score is now %d\n\n", score);
	}

	else {
		printf("\nThat is incorrect\n");
		printf("Your score is %d\n", score);
	}

	return score;
}

/*
 * Displays a question about history and possible answers. If the user enters the letter corresponding to the correct answer,
 * points are added to their score.
 * Returns - The user's score after anwering the question
 * Parameter - The user's score before the question
 */
int historyQuestion2(int score) {
	char ans;

	printf("\n\nBefore the Euro, which country used the Lira as their currency? \n");
	printf("\n A. France \t\t B. England");
	printf("\n C. Italy  \t\t D. Sweden\n\n");

	scanf(" %c", &ans);

	if (ans == 'C' || ans == 'c') {
		score += 400;
		printf("\nThat is the correct answer!\n\n");
		printf("Your score is now %d\n\n", score);
	}

	else {
		printf("\nThat is incorrect\n");
		printf("Your score is %d\n", score);
	}

	return score;
}

/*
 * Displays a question about animals and possible answers. If the user enters the letter corresponding to the correct answer,
 * points are added to their score.
 * Returns - The user's score after anwering the question
 * Parameter - The user's score before the question
 */
int animalQuestion2(int score) {
	char ans;

	printf("\n\nIn Swedish, a skvader is a rabbit with what unusual feature? \n");
	printf("\n A. glasses \t\t B. hat");
	printf("\n C. wings  \t\t D. giant hands\n\n");

	scanf(" %c", &ans);

	if (ans == 'C' || ans == 'c') {
		score += 400;
		printf("\nThat is the correct answer!\n\n");
		printf("Your score is now %d\n\n", score);
	}

	else {
		printf("\nThat is incorrect\n");
		printf("Your score is %d\n", score);
	}

	return score;
}

/*
 * Displays a question about nature and possible answers. If the user enters the letter corresponding to the correct answer,
 * points are added to their score.
 * Returns - The user's score after anwering the question
 * Parameter - The user's score before the question
 */
int natureQuestion(int score) {
	char ans;

	printf("\n\nThe Kiwi fruit is native to which country? \n");
	printf("\n A. Australia \t\t B. India");
	printf("\n C. Kenya  \t\t D. China\n\n");

	scanf(" %c", &ans);

	if (ans == 'D' || ans == 'd') {
		score += 400;
		printf("\nThat is the correct answer!\n\n");
		printf("Your score is now %d\n\n", score);
	}

	else {
		printf("\nThat is incorrect\n");
		printf("Your score is %d\n", score);
	}

	return score;
}