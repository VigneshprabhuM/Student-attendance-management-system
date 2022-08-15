
#define PERR(bSuccess, api){if(!(bSuccess)) printf("Error");}
#include <stdio.h>
#include <stdbool.h>
#include "struct_header.h"
#include <string.h>
#include <stdlib.h>


#include <windows.h>
#include <conio.h>
#include <unistd.h>

#define NAMES "student_names.txt"
#define REG_NO "register_number.txt"
#define PERCENTAGE "percentage.txt"
#define WEEK_PROGRESS "weekly_progress.txt"

stu candle[63];


int first_switch();
int find_by_reg_no();
void switching_first_valid();
void logExit();
void addingAttend();
void student_particular_attend();
void all_student_display();
void student_weekly_display();
void readingName();
void readingData();
void readingPercentage();
void readingRegistration();
void readingProgressWeekly();
void goSideDown();
void box();



void cls();



void goSideDown(int x, int y)
{
    COORD c = { x, y };
    SetConsoleCursorPosition(  GetStdHandle(STD_OUTPUT_HANDLE) , c);
}




 void cls( HANDLE hConsole )
 {
    COORD coordScreen = { 0, 0 };
    BOOL bSuccess;
    DWORD cCharsWritten;
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    DWORD dwConSize;



    bSuccess = GetConsoleScreenBufferInfo( hConsole, &csbi );
    PERR( bSuccess, "GetConsoleScreenBufferInfo" );
    dwConSize = csbi.dwSize.X * csbi.dwSize.Y;



    bSuccess = FillConsoleOutputCharacter( hConsole, (TCHAR) ' ',
       dwConSize, coordScreen, &cCharsWritten );
    PERR( bSuccess, "FillConsoleOutputCharacter" );



    bSuccess = GetConsoleScreenBufferInfo( hConsole, &csbi );
    PERR( bSuccess, "ConsoleScreenBufferInfo" );



    bSuccess = FillConsoleOutputAttribute( hConsole, csbi.wAttributes,
       dwConSize, coordScreen, &cCharsWritten );
    PERR( bSuccess, "FillConsoleOutputAttribute" );



    bSuccess = SetConsoleCursorPosition( hConsole, coordScreen );
    PERR( bSuccess, "SetConsoleCursorPosition" );
    return;
 }



void box(){

	int horizontal_row, vertical_column;



	for(horizontal_row=10; horizontal_row<70; horizontal_row++){
		goSideDown(horizontal_row, 3);
			printf("+");
		goSideDown(horizontal_row, 4);
			printf("=");


	}

	for(horizontal_row=10; horizontal_row<70; horizontal_row++){
		goSideDown(horizontal_row, 22);
			printf("+");
		goSideDown(horizontal_row, 21);
			printf("+");

	}

	for(vertical_column=4; vertical_column<21; vertical_column++){
		goSideDown(10, vertical_column);
			printf("+");
		goSideDown(11, vertical_column);
			printf("+");
		goSideDown(12, vertical_column);
			printf("+");


	}

	for(vertical_column=3; vertical_column<23; vertical_column++){
		goSideDown(70, vertical_column);
			printf("+");
		goSideDown(69, vertical_column);
			printf("+");
		goSideDown(68, vertical_column);
			printf("+");

	}


}




int find_by_reg_no(long unsigned number){

	int i=1;
	while(i<63){
		if(candle[i].reg_no== number)
			return i;
		else i++;
	}
	return 0;
}
int find_by_name(char name[30]){

	int i=1;
	while(i<63){
		if((strcmp(candle[i].names, name)== 0))
			return i;
			else i++;
	}
	return 0;
}


void logExit(){
	int c;
	printf("\n\n\n\n\n\t\t\t\t 1. back \n\t\t\t\t 2. exit ");
	printf("\n\nSelect(1/2):- ");
	scanf("%d", &c);
	if(c==1){

		first_switch();

	}

	else if(c==2){
		system("cls");
		printf("\n\n\n\n\n\n\n\n\n\t\t\tThank You,  Visit again !!");
		exit(0);

	}

}

void edit_attendance(){
	long int number;
	system("cls");
	float add;
	int choice;
	box();
	goSideDown(25,5);
	printf("\n\n\t\t\t***Edit Attendance***");
	printf("\n\n\t\tyou want to:- ");
	printf("\n\n\n\t\t\t 1. Increase Attendance");
	printf("\n\n\t\t\t 2. Decrease Attendance");
	printf("\n\n\t\tSelect(1-2):-  ");
	scanf("%d", &choice);
	if(choice ==1){
		system("cls");
		box();
		goSideDown(20,6);
		printf("\n\n\t\tEnter the registration number of student:- ");
		scanf("%ld", &number);
		int code = find_by_reg_no(number);
		printf("\n\n\t\tHow many percent you want to add:- ");
		scanf("%f", &add);
		system("cls");
		box();
		goSideDown(20,6);
		candle[code].attendance_percent+=add;
		printf("\n\n\t\t\t*** %s ***\n\n\t\t\t\t*** %lu ***\n\n\t\t\t attendance increamented by \n\n\t\t\t\t*** %0.2f ***", candle[code].names,candle[code].reg_no, add);
		printf("\n\t\tEarlier attendance:- %0.2f%%", candle[code].attendance_percent-add);
		printf("\n\t\tPresent attendance:- %0.2f%%", candle[code].attendance_percent);


	else if( choice ==2){
		system("cls");
		box();
		goSideDown(20,6);
		printf("\n\n\t\tEnter the registration number of student:- ");
		scanf("%ld", &number);
		int code = find_by_reg_no(number);
		printf("\n\n\t\tHow many percent you want to decrease:- ");
		scanf("%f", &add);
		system("cls");
		box();
		goSideDown(20,6);
		candle[code].attendance_percent-=add;
		printf("\n\n\t\t\t*** %s ***\n\n\t\t\t\t*** %lu ***\n\n\t\t\t attendance decremented by \n\n\t\t\t\t*** %0.2f ***", candle[code].names,candle[code].reg_no, add);
		printf("\n\t\tEarlier attendance:- %0.2f%%", candle[code].attendance_percent+add);
		printf("\n\t\tPresent attendance:- %f", candle[code].attendance_percent);
		if( candle[code].attendance_percent)
        {
                printf("%f",candle[code].attendance_percent);
            printf("You are not allowed to attend the exam");
        }
        }
	}
	else{
		char y_n;
		printf("\n\t\tInvalid input !!");
		printf("\n\n\t\tDo you want to try again (y/n):- ");
		scanf(" %c", &y_n);
		if(y_n=='y'){
			edit_attendance();
		}
		else exit(0);
	}

	logExit();
}



void student_particular_attend(){

	long int number;
	int choice, code;
	char name[40];
	system("cls");
	box();
	goSideDown(20,5);
	printf("\n\t\t\tsearch by what ?");
	printf("\n\n\t\t\t\t1. Name\n\n\t\t\t\t 2. Registration number");
	printf("\n\n\t\tSelect(1-2):- ");
	scanf("%d", &choice);
	if(choice ==2){
		printf("\n\t\tEnter the registration number of student:- ");
		scanf("%ld", &number);
		code = find_by_reg_no(number);
		system("cls");
		box();
		goSideDown(20,7);
		printf("\n\n\t\t\t The Attendance percentage of \n\n\t\t\t***  %s  *** \n\n\t\t\t\t*** %lu *** \n\n\t\t\t\t   is \n\n\t\t\t\t   %0.2f %% ", candle[code].names,candle[code].reg_no, candle[code].attendance_percent);

	}
	else if(choice== 1){
		printf("\n\t\tEnter the name of student:- ");
		scanf(" %[^\n]s", name);
		code = find_by_name(name);
		system("cls");
		box();
		goSideDown(20,7);
		printf("\n\n\t\t\t  The Attendance percentage of \n\n\t\t\t***  %s  *** \n\n\t\t\t\t*** %lu *** \n\n\t\t\t\t   is \n\n\t\t\t\t   %0.2f %% ", candle[code].names,candle[code].reg_no, candle[code].attendance_percent);

	}
	else{
		char y_n;
		printf("\nInvalid input !!");
		printf("\n\nDo you want to try again (y/n):- ");
		scanf(" %c", &y_n);
		if(y_n=='y'){
			student_particular_attend();
		}
		else exit(0);
	}

	logExit();
}

void all_student_display(){
	system("cls");
	printf("\n\n\t\t*** RAMCO Attendance Record ***\n");
	printf("\n\t\tAttendance\t\tNames\n\n");
	for(int i=1; i<63; i++){
		printf("\n\t\t%0.2f%%\t\t%s", candle[i].attendance_percent,  candle[i].names);
	}
	logExit();
}

void display_name_reg_no(){

	system("cls");
	printf("\n\n\t\t\t*** RAMCO Students Record ***\n");
	printf("\n\t\tRegister  \t Names\n");
	for(int i=1; i<63; i++){
		printf("\n\t\t%lu\t\t%s", candle[i].reg_no, candle[i].names );
	}
	logExit();

}

void student_weekly_display(){
	system("cls");
	printf("\n\n\t\t*** Weekly Progress of RAMCO - by Register ***");
	printf("\n\n\n\t\tRegister\tWeekly Progress\n\n");
	for(int i=1; i<63; i++){
		printf("\n\t\t%lu\t\t%0.2f%%", candle[i].reg_no, candle[i].weekly_progress);
	}
	logExit();
}

void switching_first_valid(){
	char y;
	printf("Invalid Option choosen !\n");
	printf("Do you want to run again(y/n):- ");
	scanf("%c", &y);
	if(y=='y'){
		first_switch();
	}
	else {
		exit(0);
	}
}



int first_switch(){
	system("cls");
	box();
	char options;
	bool valid=true;
	goSideDown(19,6);
	printf("***RAMCO - Student Attendance Database***");
	printf("\n\t\t  =========================================");

	//printf("\n\nI want to :- \n");
	//printf("\n\n\n\n\t\t\t1. Add Attendance ");
	printf("\n\n\t\t\t1. Edit Attendance");
	printf("\n\t\t\t2. See perticular student Attendance");
	printf("\n\t\t\t3. All Attendance Record");
	printf("\n\t\t\t4. Weekly progress ");
	printf("\n\t\t\t5. Name with Registration number");

	do{
		printf("\n\n\n\t\tChoose an option(1-5):- ");
		scanf(" %[^\n]s", &options);
		if( (options=='1') || (options=='2') || (options=='3') || (options=='4') || (options=='5')){
			valid=false;

		}
		else switching_first_valid();

	}
	while(valid);
	int op = options- 48;

	switch(op){

		case 1: edit_attendance();
				break;
		case 2: student_particular_attend();
				break;
		case 3: all_student_display();
				break;
		case 4: student_weekly_display();
				break;
		case 5: display_name_reg_no();
				break;
		default: switching_first_valid();
				break;
	}
		return 0;
}

void readingName(char filename[30]){

	FILE *fptr;
	char file1[50];
	strncpy(file1, filename, 50);

	fptr = fopen(file1, "r");


	int row=0, col=0;
	 if(fptr == NULL){
      perror("Error in opening file names");
      exit(0);
   }else{
	char ch = fgetc(fptr);
	while(ch != EOF){
		if(ch=='\n'){

			candle[row+1].names[col]='\0';
			ch=fgetc(fptr);
			row++;
			col=0;
		}

		else if(ch==32){
			 candle[row+1].names[col]=ch;
			col++;
			ch=fgetc(fptr);
		}
		else if((ch>=65 && ch<=90)){
			 candle[row+1].names[col]=ch;
			col++;
			ch=fgetc(fptr);
		}

	}
	}
	fclose(fptr);

}


void readingRegistration(char filename[20]){


	FILE *fptr;
	char file1[50];
	strncpy(file1, filename, 50);

	fptr = fopen(file1, "r");

	if(fptr == NULL){
      perror("Error in opening file reg_no ");
      exit(0);
   }else{
	   	for(int i=0; i<62; i++){
			fscanf(fptr, "%lu\n", &candle[i+1].reg_no);
		}
	}
    fclose(fptr);
}

void readingPercentage(char filename[20]){

	FILE *fptr;
	char file1[50];
	strncpy(file1, filename, 50);

	fptr = fopen(file1, "r");
	if(fptr == NULL){
      perror("Error in opening file percent");
      exit(0);
   }else{
	   	for(int i=0; i<62; i++){
			fscanf(fptr, "%f\n", &candle[i+1].attendance_percent );
		}
	}
    fclose(fptr);
}

void readingProgressWeekly(char filename[20]){

	FILE *fptr;
	char file1[50];
	strncpy(file1, filename, 50);

	fptr = fopen(file1, "r");


	if(fptr == NULL){
      perror("Error in opening file weekly_progress");
      exit(0);
   }else{
	   	for(int i=0; i<63; i++){
			fscanf(fptr, "%f\n", &candle[i+1].weekly_progress );
		}
	}
    fclose(fptr);
}



void readingData(char name_file[20], char reg_no_file[20], char percentage[20], char week_progress[20]){

	readingName(name_file);
	readingRegistration(reg_no_file);
	readingPercentage(percentage);
	readingProgressWeekly(week_progress);
}

int thankyou(){
	system("cls");
	box();
	goSideDown(20,12);
	printf("Sorry, Invalid Username/Password !");
	printf("\n\n\t\t\tThank you, Visit again !!");
	goSideDown(20,22);
	exit(0);
	return 0;
}
int main(){

	char uname[]="admin";
	char password[]="admin123";

	char ckeckinguser[20];
	char checkingpassword[20];
	readingData(NAMES, REG_NO, PERCENTAGE, WEEK_PROGRESS);
	box();
	goSideDown(26,5);
	printf("ADMINISTRATOR LOGIN");

	goSideDown(24,7);
	goSideDown(20,10);

	printf("Username:- ");
	scanf(" %[^\n]", ckeckinguser);
	goSideDown(20,14);
	printf("Password:- ");
	scanf(" %[^\n]", checkingpassword);
	if(strcmp(ckeckinguser, uname)==0){
		if((strcmp(checkingpassword, password)==0)){
		first_switch();
		}
		else thankyou();
	}

	else{ thankyou();
	}



	return 0;
}
