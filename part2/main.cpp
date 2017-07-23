#include <allegro.h> 
#include<iostream>
#include<fstream>
#include<string>
#include<stdlib.h>
using namespace std;

void menu();
void clear_screen();
void getinput();
void chapter_list();
void read_text();
void unit_list();
void get_chapter();

int main(void) {
	int ret;
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
	

	while(!key[KEY_ESC]){

		if(key[KEY_M]){
			clear_screen();
			menu();
		}
		if (key[KEY_1])
		clear_screen();
		//read_text();
    	else if(key[KEY_2]){
    		clear_screen();
    		textout_ex(screen, font, "For particular unit: ", 5, 10, 10, -1);
    		textout_ex(screen, font, "Enter a number between 1 to 8:", 5, 20, 10, -1);
    		for(int n=1; n<=8;n++){
    			textprintf_ex(screen, font, SCREEN_W / 2,40*n, 15,-1, "Unit %d", n);
    			cout << "value of a: " << n << endl;
			}
    		
    		
		}
    	else if(key[KEY_3]){
    		clear_screen();
    		textout_ex(screen, font, "For particular chapter: ", 5, 10, 10, -1);
    		textout_ex(screen, font, "Enter a number between 1 to 22:", 5, 20, 10, -1);

    		for(int n=1; n<=22;n++){
    			
    			if(n>=12){
    				textprintf_ex(screen, font, SCREEN_W/2,(n*40)-440, 15,-1, "Unit %d", n);
    				cout << "value of a: " << n << endl;
				}
				else{
					textprintf_ex(screen, font, 20,40*n, 15,-1, "Unit %d", n);
				}
    			
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
 

void read_text(){
	string line;
	ifstream myfile ("test.txt");
	if (myfile.is_open()){
		while(!myfile.eof()){
			getline (myfile, line);
			cout << line << '\n';
			textprintf_ex(screen, font, 0,24, 15,-1, "%s", line.c_str());
		}
		myfile.close();
	}
	else cout << "Unable to open file";
	
}

void clear_screen(){
	rectfill(screen,0,0,640,480,0);
}

void getinput(){
	
	if (key[KEY_1])
		clear_screen();
		//read_text();
    else if(key[KEY_2]){
    	clear_screen();
    	textout_ex(screen, font, "For particular unit: ", 5, 10, 10, -1);
    	textout_ex(screen, font, "Enter a number between 1 to 8:", 5, 20, 10, -1);
    	
    	
		
	}
    else if(key[KEY_3]){
    	clear_screen();
    	textout_ex(screen, font, "For particular chapter: ", 5, 10, 10, -1);
    	textout_ex(screen, font, "Enter a number between 1 to 22:", 5, 20, 10, -1);
    	
    	
	}
}

void get_chapter(){
	for(int n=1; n<=8;n++){
    			textprintf_ex(screen, font, 0,30*n, 15,-1, "Chapter %d", n);
    			cout << "value of a: " << n << endl;
			}
}

