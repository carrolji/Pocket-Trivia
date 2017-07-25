#include <allegro.h> 
#include <iostream>
#include<fstream>
#include <sstream>
#include<string>
#include<stdlib.h>
using namespace std;

void welcome();
void menu();
void clear_screen();
void getinput();
void get_unit();
void get_chapter();
void display_score(int correct, int total_questions);
void read_text(int chp_num,char question);
char get_answer(int num, char question);
void get_user_ans();
void check_score(int answer, int question);
int unit_list(int unit);
int rand_num(int min, int max);

int main(void) {
	int ret;
	int correct = 0;
	int total_questions = 1;
	char q = '0';
	int chapter;
	allegro_init();  
	install_keyboard(); 
    install_timer();
    srand(time(NULL));
	
	ret = set_gfx_mode(GFX_AUTODETECT_WINDOWED, 640, 480, 0, 0);
	if(ret != 0){
		allegro_message(allegro_error);
		return 1;
	} 
    welcome();
    menu();
    
	while(!key[KEY_ESC]){

		if(key[KEY_M]){
			clear_screen();
			menu();
		}
		if (key[KEY_1]){
			clear_screen();
			display_score(correct, total_questions);
			
			chapter = rand_num(1,22);
    		cout << chapter << endl;
		}
    	else if(key[KEY_2]){
    		clear_screen();
    		display_score(correct, total_questions);
    		get_unit();
    		while(!key[KEY_ENTER]);
    		int unit =1; //testing
    		chapter = unit_list(unit); 
    		
    		while(q <= '9'){
				clear_screen();
				display_score(correct, total_questions); //displaying score
				read_text(chapter,q); //read the question
				rest(1000);
				cout << "THIS IS CHAPTER: " << chapter << endl;
				get_user_ans();
				get_answer(chapter,q); //get the answer 
				total_questions++;	
				q++;
			}
			clear_screen();
			check_score(correct,total_questions);
    			
		}
    	else if(key[KEY_3]){
    		clear_screen();
			get_chapter();
			rest(2000);
			//clear_screen();
			//read_text(2,'9');
			while(q <= '9'){
				clear_screen();
				display_score(correct, total_questions); //displaying score
				read_text(1,q); //read the question
				get_user_ans();
				get_answer(1,q); //get the answer 
				total_questions++;	
				q++;
			}
			clear_screen();
			check_score(correct,total_questions);
		}
		

		
	}; 
	allegro_exit(); 
	return 0;
} 
END_OF_MAIN()

void welcome(){
	while (!key[KEY_ENTER]){
		textout_ex(screen, font, "Welcome to Pocket Trivia Game", 5, 1, 10, -1); 
    	textout_ex(screen, font, "The game is to quiz your knowledge based on the textbook ", 5, 10, 10, -1);
    	textout_ex(screen, font, "Game Programming All in One, 3rd Edition textbook by Jonathan S.Harbour", 5, 20, 10, -1);
    	textout_ex(screen, font, "Each set of game will present you 10 random multiple-choice questions", 5, 30, 10, -1);
    	textout_ex(screen, font, "Choose the correct answer to earn a point by entering a, b, c, or d", 5, 40, 10, -1);	
    	textout_ex(screen, font, "Enter to continue...", 5, 50, 10, -1);
	};
	
    clear_screen();
}

void menu()
{
    textout_ex(screen, font, "Pick the type of quizes you would like to play:", 5, 10, 10, -1);
    textout_ex(screen, font, "Enter (1) for entire text", 5, 20, 10, -1);
    textout_ex(screen, font, "Enter (2) for particular unit", 5, 30, 10, -1);
    textout_ex(screen, font, "Enter (3) for particular chapter", 5, 40, 10, -1);
     
 }

void clear_screen(){
	//Clear the game screen by filling with black rectangle
	rectfill(screen,0,0,640,480,0);
}

void getinput(){
	//Get choice from the user in the menu mode
	if (key[KEY_1])
		clear_screen();
    else if(key[KEY_2]){
    	clear_screen();
    	get_unit();
	}
    else if(key[KEY_3]){
    	clear_screen();
    	get_chapter();	
	}
}

void get_unit(){
	//Print out unit list
	textout_ex(screen, font, "For particular unit: ", 5, 10, 10, -1);
    textout_ex(screen, font, "Enter a number between 1 to 8:", 5, 20, 10, -1);
    for(int n=1; n<=8;n++){
    	textprintf_ex(screen, font, SCREEN_W / 2,40*n, 15,-1, "Unit %d", n);
    	cout << "value of a: " << n << endl;
	}
}

int rand_num(int min, int max){
	srand(time(NULL)); // Seed the time
	int finalNum = rand()%(max-min+1)+min;
	return finalNum;
	
	//taken from: https://stackoverflow.com/questions/12657962/how-do-i-generate-a-random-number-between-two-variables-that-i-have-stored 
}
int unit_list(int unit){
	// List of unit with the following chapter(s)
	int chapter;
	switch(unit){
		case 1:
			chapter = rand_num(1,3);
			break; 
		case 2:
			chapter = rand_num(4,6);
			break;
		case 3:
			chapter = 17;
			break;
		case 4:
			chapter = rand_num(7,10);
			break;
		case 5:
			chapter = 11;
			break;
		case 6:
			chapter = rand_num(12,16);
			break;
		case 7:
			chapter = rand_num(18,19);
			break;
		case 8:
			chapter = rand_num(20,22);
			break;
	}
	return chapter;
	
}
void get_chapter(){
	//Print out chapter list
	textout_ex(screen, font, "For particular chapter: ", 5, 10, 10, -1);
    textout_ex(screen, font, "Enter a number between 1 to 22:", 5, 20, 10, -1);
	for(int n=1; n<=22;n++){
    			
    	if(n>=12){
   			textprintf_ex(screen, font, SCREEN_W/2,(n*40)-440, 15,-1, "Chapter %d", n);
  			cout << "value of a: " << n << endl;
		}
		else{
			textprintf_ex(screen, font, 20,40*n, 15,-1, "Chapter %d", n);
		}
    			
	}
}

void display_score(int correct,int total_questions){
	textprintf_right_ex(screen, font, SCREEN_W - 10, 20,
                          makecol(200, 200, 20), -1,
                          "Score %d : %d", correct,total_questions);
}

void read_text(int num,char question){
	
	ifstream myfile;
	string line;
	char filename [100];
	snprintf (filename, sizeof filename, "chp%d.txt", num);
	myfile.open(filename);
	//myfile.open("chp" + std::to_string(num)+ ".txt");
	if(!myfile) {
   	 	cout << "Cannot open input file.\n";
  	}
  	//char question = '9'; //must pass the parameter!!
  	int lines_read = 0;
	if (myfile.is_open()){
		while(!myfile.eof()){
			getline (myfile, line);
    		cout << "****"<<question << endl;
    		if (line.length() > 0 && (line[0] == question || line[1] == question) ){
				cout << line << '\n';
				question++;
				textprintf_ex(screen, font, 5,80, 15,-1, "%s", line.c_str());
				
				for(int n=1;n <= 5;n++){
					getline (myfile, line);
					
					if(line.length()> 0 && line[0] == question){
						break;
					}
					if(line.length()> 0 && line[0] == '1'){ //detect if question 10 follows question 9
						break; //break the for loop
					}
					else{
						textprintf_ex(screen, font, 5,90*n, 15,-1, "%s", line.c_str());
						//cout << "YOOOOOO: " << line[0] << endl;
						cout << line << endl;
					}
				}
			}
		}
	}
	myfile.close();
	
}

char get_answer(int num, char question){
	
	ifstream myfile;
	string line;
	char filename [100];
	snprintf (filename, sizeof filename, "answer%d.txt", num);
	myfile.open(filename);

	if(!myfile) {
   	 	cout << "Cannot open input file.\n";
  	}
  	
  	int lines_read = 0;
  	char answer;
	if (myfile.is_open()){
		while(!myfile.eof()){
			getline (myfile, line);
    		
    		if (line.length() > 0 && line[0] == question){
				cout << line << '\n';
				question++;
				
				for(int n=1;n <=5;n++){
					getline (myfile, line);
					if(line.length()> 0 && line[0] == question){
						break;
					}
					else{
						textprintf_ex(screen, font, 5,400, 15,-1, "ANSWER: %s", line.c_str());
						cout << line << endl;
						answer = line[0];
						cout << "ANSWER CHARACTER: " << answer << endl;
					}
				}
			}
		}
	}
	myfile.close();
	
	return answer;
	
}

void get_user_ans(){
	while (!key[KEY_ENTER]){
        textout_ex(screen, font, "Enter your answer: ", 5, 400, 10, -1);
    }
}

void check_score(int answer, int question){
	question--;
	float total_score = (float)answer/ (float)question;
	textprintf_ex(screen, font, 5,80, 15,-1, "You have scored: %f", total_score);
	if(total_score==1){
		textout_ex(screen, font, "WOW! Perfect score! Congratulations!", 5, 90, 10, -1);
	}
	else if(total_score>0.8){
		textout_ex(screen, font, "Great job!", 5, 90, 10, -1);
	}
	else if(total_score>0.5){
		textout_ex(screen, font, "Well done!", 5, 90, 10, -1);
	}
	else if(total_score==0.5){
		textout_ex(screen, font, "You passed!", 5, 90, 10, -1);
	}
	else{
		textout_ex(screen, font, "Sorry try again next time", 5, 90, 10, -1);
	}
	textout_ex(screen, font, "Enter m to go back to the main menu", 5, 100, 10, -1);
	textout_ex(screen, font, "Esc to quit the game", 5, 110, 10, -1);
	
}


