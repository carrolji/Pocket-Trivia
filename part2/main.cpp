#include <allegro.h> 
#include <iostream>
#include<fstream>
#include <sstream>
#include<string>
#include<stdlib.h>
using namespace std;

void menu();
void clear_screen();
void getinput();
void get_unit();
void get_chapter();
void display_score(int correct, int total_questions);
void read_text(int chp_num,char question);
char get_answer(int num, char question);

int main(void) {
	int ret;
	int correct = 0;
	int total_questions = 1;
	allegro_init();  
	install_keyboard(); 
    install_timer();
    srand(time(NULL));
	
	ret = set_gfx_mode(GFX_AUTODETECT_WINDOWED, 640, 480, 0, 0);
	if(ret != 0){
		allegro_message(allegro_error);
		return 1;
	} 
	textout_ex(screen, font, "Welcome to Pocket Trivia Game", 5, 1, 10, -1); 
    textout_ex(screen, font, "The game is to quiz your knowledge based on the textbook ", 5, 10, 10, -1);
    textout_ex(screen, font, "Game Programming All in One, 3rd Edition textbook by Jonathan S.Harbour", 5, 20, 10, -1);
    textout_ex(screen, font, "Choose the correct answer to earn a point by entering a, b, c, or d", 5, 30, 10, -1);
    rest(1000);
    clear_screen();
    menu();
    
	char q = '1';

	while(!key[KEY_ESC]){
		

		if(key[KEY_M]){
			clear_screen();
			menu();
		}
		if (key[KEY_1]){
			clear_screen();
			display_score(correct, total_questions);
		}
			

    	else if(key[KEY_2]){
    		clear_screen();
    		display_score(correct, total_questions);
    		get_unit();
    			
		}
    	else if(key[KEY_3]){
    		clear_screen();
			get_chapter();
			rest(2000);
			for(int n=0; n <10; n++){
				clear_screen();
				display_score(correct, total_questions);
				read_text(1,q);
				get_answer(1,q);
				q++;
				rest(2000);
				total_questions++;	
			}
			
    		
		}

		
	}; 
	allegro_exit(); 
	return 0;
} 
END_OF_MAIN()

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
		//read_text();
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
  	//char question = '5'; //must pass the parameter!!
  	int lines_read = 0;
	if (myfile.is_open()){
		while(!myfile.eof()){
			getline (myfile, line);
    		
    		if (line.length() > 0 && line[0] == question){
				cout << line << '\n';
				question++;
				textprintf_ex(screen, font, 5,80, 15,-1, "%s", line.c_str());
				
				for(int n=1;n <=5;n++){
					getline (myfile, line);
					if(line.length()> 0 && line[0] == question){
						break;
					}
					else{
						textprintf_ex(screen, font, 5,90*n, 15,-1, "%s", line.c_str());
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
	
	cout<<filename;
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
						cout << answer << endl;
					}
				}
			}
		}
	}
	myfile.close();
	
	return answer;
	
}


