#include <allegro.h> 
#include <iostream>
#include<fstream>
#include <sstream>
#include<string>
#include<stdlib.h>
#include <algorithm> 

#define MODE GFX_AUTODETECT_WINDOWED
#define WIDTH 640
#define HEIGHT 480
using namespace std;

void welcome();
void menu();
void getinput();
int get_unit();
char * get_chapter(char *str_to, int size);
void display_score(int correct, int total_questions);
void read_text(int chp_num,int question);
char get_answer(int num, int question,bool display);
int get_user_ans(char answer);
void check_score(int answer, int quest);
int unit_list(int unit);
int rand_num(int min, int max);

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
	   
    //initialize music
    SAMPLE *samples[5];
    int panning = 128;
    int pitch = 1000;
    int volume = 128;
    
    //install a digital sound driver
    if (install_sound(DIGI_AUTODETECT, MIDI_NONE, "") != 0) 
    {
        allegro_message("Error initializing sound system");
        return 1;
    }
    
    //load the wave file
    samples[0] = load_sample("clapping.wav");
    samples[1] = load_sample("correct.wav");
    samples[2] = load_sample("wrong.wav");

    welcome();
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
    		
    		while(q <= 9){
    			chapter = rand_num(1,22);
    			cout << "THIS IS CHAPTER: " << chapter << endl;
    			
				clear(screen);
				rest(1000);
				textprintf_ex(screen, font, 5,5, 15,-1, "CHAPTER: %d", chapter);
				display_score(correct, total_questions); //displaying score
				read_text(chapter,num[q]); //read the question
				
				answer = get_answer(chapter,num[q],false); //get the answer
				user_ans = get_user_ans(answer);
				
				
				if (answer == (char)user_ans){
					cout << "True" << endl;
					play_sample(samples[1], volume, panning, pitch, FALSE);
					textout_ex(screen, font, "CORRECT!!!", 5, 370, 10, -1); 
					correct++;
				}
				else{
					cout << "FALSE" << endl;
					play_sample(samples[2], volume, panning, pitch, FALSE);
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
    	else if(key[KEY_2]){
    		
    		clear(screen);
    		display_score(correct, total_questions);
    		unit = get_unit();
    		
    		while(q <= 9){
				clear(screen);
				rest(1000);
    			chapter = unit_list(unit);
				
				display_score(correct, total_questions); //displaying score
				read_text(chapter,num[q]); //read the question
				textprintf_ex(screen, font, 5,5, 15,-1, "CHAPTER: %d", chapter);
				cout << "THIS IS CHAPTER: " << chapter << endl;
				answer = get_answer(chapter,num[q],false); //get the answer
				user_ans = get_user_ans(answer);
				
				
				if (answer == (char)user_ans){
					cout << "True" << endl;
					play_sample(samples[1], volume, panning, pitch, FALSE);
					textout_ex(screen, font, "CORRECT!!!", 5, 370, 10, -1); 
					correct++;
				}
				else{
					cout << "FALSE" << endl;
					play_sample(samples[2], volume, panning, pitch, FALSE);
					textout_ex(screen, font, "WRONG!!!", 5, 370, 10, -1);
					get_answer(chapter,num[q],true);
				}
				rest(2000);
				total_questions++;	
				q++;
			}
			clear(screen);
			check_score(correct,total_questions);
			//play the sample with looping
	    	play_sample(samples[0], volume, panning, pitch, TRUE);
    			
		}
    	else if(key[KEY_3]){
    		clear(screen);
    		rest(1000);
			
			
			while(!key[KEY_ENTER]){
				test = get_chapter(my_str, 40);
				cout << "USER INPUT: " <<  test << endl;
				chapter = atoi(test);
			}
    		cout << "CHAPTER!!!!" << chapter << endl;
    		
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
					play_sample(samples[1], volume, panning, pitch, FALSE);
					textout_ex(screen, font, "CORRECT!!!", 5, 370, 10, -1); 
					correct++;
				}
				else{
					cout << "FALSE" << endl;
					textout_ex(screen, font, "WRONG!!!", 5, 370, 10, -1); 
					play_sample(samples[2], volume, panning, pitch, FALSE);
					get_answer(chapter,num[q],true);
				}
				rest(2000);
				total_questions++;	
				q++;
			}
			clear(screen);
			check_score(correct,total_questions);
			//play the sample with looping
	    	play_sample(samples[0], volume, panning, pitch, TRUE);
		}
		
	    
			
	}; 
	allegro_exit(); 
	return 0;
} 
END_OF_MAIN();

void welcome(){
	while (!key[KEY_ENTER]){
		
		for(int n=3; n<=10 ; n++){
    		circlefill(screen, n* 50, (SCREEN_H / 3.5), 5, 10);	
    		//circlefill(screen, n* 50, (SCREEN_H / 3.5), 5, 13);
    		//circlefill(screen, n* 50, (SCREEN_H / 3.5), 5, 11);
    		circlefill(screen, n* 50, (SCREEN_H / 3.5), 5, 12); //RED
    		
    		//circlefill(screen, n* 50, (SCREEN_H / 2.5), 5, 10);	
    		//circlefill(screen, n* 50, (SCREEN_H / 2.5), 5, 13);
    		circlefill(screen, n* 50, (SCREEN_H / 2.5), 5, 11);
    		circlefill(screen, n* 50, (SCREEN_H / 2.5), 5, 12); //RED
    		
		}
		for(int n=3; n <=7; n++){
			circlefill(screen, n* 72, (SCREEN_H / 3.5), 5, 11); //BLUE
			circlefill(screen, n* 60, (SCREEN_H / 3.5), 5, 14); //YELLOW
			circlefill(screen, n* 55, (SCREEN_H / 3.5), 5, 13); //PINK
			circlefill(screen, n* 68, (SCREEN_H / 3.5), 5, 13); //PINK TOP
			circlefill(screen, n* 55, (SCREEN_H / 3.5), 5, 10); //GREEN
			
			circlefill(screen, n* 60, (SCREEN_H / 2.5), 5, 14); //YELLOW
			circlefill(screen, n* 55, (SCREEN_H / 2.5), 5, 13); //PINK
			circlefill(screen, n* 68, (SCREEN_H / 2.5), 5, 13); //PINK
			
			circlefill(screen, n* 55, (SCREEN_H / 2.5), 5, 10); //GREEN
			circlefill(screen, n* 72, (SCREEN_H / 2.5), 5, 11); //BLUE
			circlefill(screen, n* 60, (SCREEN_H / 2.5), 5, 14); //YELLOW
				
		}
		textout_centre_ex(screen, font, "Welcome to Pocket Trivia Game",  SCREEN_W / 2, SCREEN_H / 3, 15, -1); 
    	textout_centre_ex(screen, font, "The game is to quiz your knowledge based on the textbook: ", SCREEN_W / 2, 250, 15, -1);
    	textout_centre_ex(screen, font, "Game Programming All in One, 3rd Ed. by Jonathan S.Harbour", SCREEN_W / 2, 270, 15, -1);
    	textout_centre_ex(screen, font, "Each set of game will present you 10 random multiple-choice questions", SCREEN_W / 2, 290, 15, -1);
    	textout_centre_ex(screen, font, "Choose the correct answer to earn a point by entering a, b, c, or d", SCREEN_W / 2, 310, 15, -1);	
    	textout_centre_ex(screen, font, "PRESS HOLD Enter key to continue...", SCREEN_W / 2, 330, 15, -1);
	};
	
    clear(screen);
}

void menu()
{
    textout_centre_ex(screen, font, "Pick the type of quizes you would like to play:", SCREEN_W / 2, SCREEN_H / 3, 15, -1);
    textout_centre_ex(screen, font, "Enter (1) for entire text", SCREEN_W / 2, 200, 15, -1);
    textout_centre_ex(screen, font, "Enter (2) for particular unit", SCREEN_W / 2, 220, 15, -1);
    textout_centre_ex(screen, font, "Enter (3) for particular chapter", SCREEN_W / 2, 240, 15, -1);
     
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
char * get_chapter(char *str_to, int size){
	
    int cur_pos = 0; // position of caret
    int the_key = 0;
    int i;
    for (i = 0; i < size; i++)           
		str_to[i] = '\0'; // 'clean' the string

    while (the_key>>8 != KEY_ENTER){
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
        textout_ex(screen, font, "For particular chapter: ", 5, 10, 10, -1);
    	textout_ex(screen, font, "Enter a number between 1 to 22:", 5, 20, 10, -1);
        textout_ex(screen,font, "CHAPTER: ", 200, 50, 10, -1);
        textout_ex(screen,font, str_to, 270, 50, 10, -1);
       }
       
    	return str_to;
    //taken from: https://wiki.allegro.cc/index.php?title=Reading_a_string_from_the_keyboard
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
						line.erase(std::remove(line.begin(), line.end(), '\t'), line.end()); // REMOVE TAB
						textprintf_ex(screen, font, 5,100+(n*10), 15,-1, "%s", line.c_str()); //printing the choices
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
						if(display == true && (line[0] == 'C' || line[0] == 'A'|| line[0] == 'B'|| line[0] == 'D')){
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
    	ascii = ascii - 32; //convert to upper letter
    
   		textprintf_ex(screen, font, 200, 350, 15, 0,
            			"%c", (char)ascii);
    
    
	}
    
    return ascii;
    
}

void check_score(int answer, int question){
	question--;
	int total_score = ((float)answer/ (float)question)*100;
	textprintf_ex(screen, font, 5,80, 15,-1, "You have scored: %d %%", total_score);
	if(total_score==100){
		textout_ex(screen, font, "WOW! Perfect score! Congratulations!", 5, 90, 10, -1);
	}
	else if(total_score>80){
		textout_ex(screen, font, "Great job!", 5, 90, 10, -1);
	}
	else if(total_score>50){
		textout_ex(screen, font, "Well done!", 5, 90, 10, -1);
	}
	else if(total_score==50){
		textout_ex(screen, font, "You passed!", 5, 90, 10, -1);
	}
	else{
		textout_ex(screen, font, "Sorry try again next time", 5, 90, 10, -1);
	}
	textout_ex(screen, font, "Esc to quit the game", 5, 110, 10, -1);
	
}


