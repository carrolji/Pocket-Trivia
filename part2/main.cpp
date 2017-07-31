#include <allegro.h> 
#include <iostream>
#include<fstream>
#include <sstream>
#include<string>
#include<stdlib.h>
using namespace std;

void welcome();
void menu();
void getinput();
int get_unit();
void get_chapter();
void display_score(int correct, int total_questions);
void read_text(int chp_num,int question);
char get_answer(int num, int question,bool display);
int get_user_ans(char answer);
void check_score(int answer, int quest);
int unit_list(int unit);
int rand_num(int min, int max);

/*
char * read_string(char *str_to, int size) {
       int cur_pos = 0; // position of caret
       int the_key = 0;
       int i;
       for (i = 0; i < size; i++)
               str_to[i] = '\0'; // 'clean' the string

       while (the_key>>8 != KEY_ENTER)
       {
               the_key = readkey();
               if ((the_key & 0xff) >= ' ') // get only valid chars
               {
                       str_to[cur_pos] = the_key & 0xff;
                       cur_pos++;
                       if (cur_pos > size-2) cur_pos = size-2;
               }
               if (the_key >> 8 == KEY_BACKSPACE)
               {
                       str_to[cur_pos] = '\0'; // chop the string
                       cur_pos --;
                       if (cur_pos < 0) cur_pos = 0;
               }
               // lame redraw (use double buffer, whatever)
               clear(screen);
               textout(screen,font, str_to, 0,0, makecol(255,255,255));
               //cout << str_to << endl;
       }
    	return str_to;
}*/

int chapter;
char my_str[40];
char *test;

int main(void) {
	int k;
	int user_ans;
	char answer;
	int scancode ,ascii;
	int ret;
	int correct = 0;
	int total_questions = 1;
	int q = 0;
	int unit;
	
	
	//initialize program
	allegro_init();  
	install_keyboard(); 
	install_mouse();
    install_timer();
    srand(time(NULL));
	
	ret = set_gfx_mode(GFX_AUTODETECT_WINDOWED, 640, 480, 0, 0);
	if(ret != 0){
		allegro_message(allegro_error);
		return 1;
	} 
    welcome();
    //rest(1000);
    menu();
    
    
    //////////////////RANDOM NUMBER GENERATED //////////////////
    		
	int i , r , temp;
	int num[10];
				
	//Fill array with desired numbers
	for( temp=0,i=0; temp<10; i++,temp++ )
		num[temp] = i;
		
	//Fisher–Yates shuffle algorithm
	for( i=9; i>0; i-- ){
		r = rand()%i;   //pop random number
				        //swaping using temp
		temp = num[i];
		num[i] = num[r];
		num[r] = temp;
	}
				
	//print the array
	for( i=0; i<10; i++ )
		cout << "ARRAY" << num[i] << endl;
	
	//taken from: http://www.codenirvana.net/2014/08/generate-random-number-in-range-c-program.html		
	//////////////////RANDOM NUMBER GENERATED //////////////////			
	while(!key[KEY_ESC]){

		if (key[KEY_1]){
			clear(screen);
			display_score(correct, total_questions);
			
			chapter = rand_num(1,22);
    		cout << chapter << endl;
    		
    		//test = read_string(my_str, 40);
			//cout << "USER INPUT: " <<  test << endl;
			
			break;
					    		
		}
    	else if(key[KEY_2]){
    		
    		clear(screen);
    		display_score(correct, total_questions);
    		unit = get_unit();
    		chapter = unit_list(unit);
    		
    		while(q <= 9){
				clear(screen);
				rest(1000);
				
				display_score(correct, total_questions); //displaying score
				read_text(chapter,num[q]); //read the question
				
				cout << "THIS IS CHAPTER: " << chapter << endl;
				answer = get_answer(chapter,num[q],false); //get the answer
				user_ans = get_user_ans(answer);
				
				
				if (answer == (char)user_ans){
					cout << "True" << endl;
					textout_ex(screen, font, "CORRECT!!!", 5, 370, 10, -1); 
					correct++;
				}
				else{
					cout << "FALSE" << endl;
					textout_ex(screen, font, "WRONG!!!", 5, 370, 10, -1); 
					get_answer(chapter,num[q],true);
				}
				rest(2000);
				total_questions++;	
				q++;
			}
			clear(screen);
			check_score(correct,total_questions);
    			
		}
    	else if(key[KEY_3]){
    		clear(screen);
    		//get_chapter();
    		rest(1000);
			
			chapter = 1;
    		cout << "USER INPUT: " <<  chapter << endl;
    		
			while(q <= 9){
				clear(screen);					
				rest(1000);
			
				//display score
				display_score(correct, total_questions);
				cout <<"YARRRRRRRRRRRRRRRRR " << num[q] << endl;
				
				read_text(chapter,num[q]); //read the question
				
				answer = get_answer(chapter,num[q],false); //get the answer
				user_ans = get_user_ans(answer);
				
				
				if (answer == (char)user_ans){
					cout << "Correct" << endl;
					textout_ex(screen, font, "CORRECT!!!", 5, 370, 10, -1); 
					correct++;
				}
				else{
					cout << "FALSE" << endl;
					textout_ex(screen, font, "WRONG!!!", 5, 370, 10, -1); 
					get_answer(chapter,num[q],true);
				}
				rest(2000);
				total_questions++;	
				q++;
			}
			clear(screen);
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
	
    clear(screen);
}

void menu()
{
    textout_ex(screen, font, "Pick the type of quizes you would like to play:", 5, 10, 10, -1);
    textout_ex(screen, font, "Enter (1) for entire text", 5, 20, 10, -1);
    textout_ex(screen, font, "Enter (2) for particular unit", 5, 30, 10, -1);
    textout_ex(screen, font, "Enter (3) for particular chapter", 5, 40, 10, -1);
     
 }


void getinput(){
	//Get choice from the user in the menu mode
	if (key[KEY_1])
		clear(screen);
    else if(key[KEY_2]){
    	clear(screen);
    	get_unit();
	}
    else if(key[KEY_3]){
    	clear(screen);
    	get_chapter();	
	}
}

int get_unit(){
	int unit;
	//Print out unit list
	textout_ex(screen, font, "For particular unit: ", 5, 10, 10, -1);
    textout_ex(screen, font, "Enter a number between 1 to 8 then press Enter:", 5, 20, 10, -1);
	
	while(!key[KEY_ENTER]){
    	if (key[KEY_1]){
    		unit =1;
		}
		else if (key[KEY_2]){
    		unit =2;
		}
		else if (key[KEY_3]){
    		unit =3;
		}
		else if (key[KEY_4]){
			unit =4;
		}
		else if (key[KEY_5]){ 	
			unit =5;
		}
		else if (key[KEY_6]){
  			unit =6;
		}
		else if (key[KEY_7]){
  			unit =7;
		}
		else if (key[KEY_8]){
  			unit =8;
		}
		textprintf_ex(screen, font, 200, 50, 15, 0,
            		"UNIT: %d", unit);
				
			};
	return unit;
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
    //test = read_string(my_str, 40);
	//cout << "USER INPUT: " <<  test << endl;
	
	
/*	while(!key[KEY_ENTER]){
    	if (key[KEY_1]){
    		chapter =1;
		}
		else if (key[KEY_2]){
    		chapter =2;
		}
		else if (key[KEY_3]){
    		chapter =3;
		}
		else if (key[KEY_4]){
			chapter =4;
		}
		else if (key[KEY_5]){ 	
			chapter =5;
		}
		else if (key[KEY_6]){
  			chapter =6;
		}
		else if (key[KEY_7]){
  			chapter =7;
		}
		else if (key[KEY_8]){
  			chapter =8;
		}
		else if (key[KEY_9]){
  			chapter =9;
		}
		textprintf_ex(screen, font, 200, 50, 15, 0,
            		"CHAPTER: %d", chapter);
				
			};
	return chapter;*/
}

void display_score(int correct,int total_questions){
	textprintf_right_ex(screen, font, SCREEN_W - 10, 20,
                          makecol(200, 200, 20), -1,
                          "Score %d : %d", correct,total_questions);
}

void read_text(int num,int quest){
	char question = '0'+quest; //convert int to char
	
	ifstream myfile;
	string line;
	char filename [100];
	snprintf (filename, sizeof filename, "chp%d.txt", num);
	myfile.open(filename);
	
	if(!myfile) {
   	 	cout << "Cannot open input file.\n";
  	}
  	
  	int lines_read = 0;
	if (myfile.is_open()){
		while(!myfile.eof()){
			getline (myfile, line);
    		
			if (line.length() > 0 && (line[0] == question || line[1] == question) ){
				cout <<line << '\n';
				question++;
				textprintf_ex(screen, font, 5,80, 15,-1, "%s", line.c_str()); //printing questions
				
				for(int n=1;n <= 5;n++){
					getline (myfile, line);
					
					if(line.length()> 0 && line[0] == question){
						break;
					}
					if(line.length()> 0 && line[0] == '1'){ //detect if question 10 follows question 9
						break; //break the for loop
					}
					else{
						textprintf_ex(screen, font, 5,90*n, 15,-1, "%s", line.c_str()); //printing the choices
						cout << line << endl;
					}
				}
			}
		}
	}
	myfile.close();
	
}

char get_answer(int num, int quest, bool display){
	char question = '0'+quest;
	
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
    		
    		if (line.length() > 0 && (line[0] == question || line[1] == question) ){
				question++;
				
				for(int n=1;n <=5;n++){
					getline (myfile, line);
					if(line.length()> 0 && line[0] == question){
						break;
					}
					if(line.length()> 0 && line[0] == '1'){ //detect if question 10 follows question 9
						break; //break the for loop
					}
					if(line.length() ==0){ //ignore blank spaces
						break;
					}
					else{
						if(display == true){
							textprintf_ex(screen, font, 5,400, 15,-1, "THE CORRECT ANSWER IS: %s", line.c_str());	
						}
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

int get_user_ans(char answer){
	int k;
	int scancode ,ascii;
	textout_ex(screen, font, "Enter your answer: ", 5, 350, 10, -1);	
    
    while(!(key[KEY_A] || key[KEY_B] || key[KEY_C] || key[KEY_D])) {
    	k = readkey();
    	scancode = (k >> 8);
    	ascii = scancode_to_ascii(scancode);
    	cout << "USER ANSWER: " << (char)ascii << endl; 
    	cout << "k: " << k << endl; 
    	cout << "scancode: " << scancode << endl; 
    	cout << "ascii: " << ascii << endl; 
    	ascii = ascii - 32; //convert to upper letter
    
   		textprintf_ex(screen, font, 200, 350, 15, 0,
            			"%c", (char)ascii);
    
    
	}
    
    return ascii;
    
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
	textout_ex(screen, font, "Esc to quit the game", 5, 110, 10, -1);
	
}


