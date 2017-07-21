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
	menu();
	//check for keypresses
    //if (keypressed())
        //getinput();

/*	string line;
	ifstream myfile ("test.txt");
	if (myfile.is_open()){
		while(!myfile.eof()){
			getline (myfile, line);
			cout << line << '\n';
			//textprintf_ex(screen, font, 0,24, 15,-1, "%s\n", line.c_str());
		}
		myfile.close();
	}
	else cout << "Unable to open file";
*/	
	while(!key[KEY_ESC]){
    	
        if (key[KEY_1])
        	rectfill(screen,0,0,640,480,15);
    	if (key[KEY_2]){
    		clear_screen();
    		chapter_list();
		}
    	if (key[KEY_3])
    		rectfill(screen,0,0,640,480,15);
    	
	}; 
	allegro_exit(); 
	return 0;
} 
END_OF_MAIN()


void menu()
{
    textout_ex(screen, font, "Welcome to Pocket Trivia Game", 5, 1, 10, -1); 
    textout_ex(screen, font, "Pick the type of quizes:", 5, 10, makecol(1, 1, 255), makecol(150, 1,1));
    textout_ex(screen, font, "Enter (1) for entire text:", 5, 20, makecol(1, 1, 255), makecol(150,1,1));
    textout_ex(screen, font, "Enter (2) for particular unit:", 5, 30, makecol(1, 1, 255), makecol(150,1,1));
    textout_ex(screen, font, "Enter (3) for particular chapter:", 5, 40, makecol(1, 1, 255), makecol(150,1,1));
     
 }
 
void chapter_list()
{
	textout_ex(screen, font, "Welcome to Pocket Trivia Game", 5, 1, 10, -1); 
    textout_ex(screen, font, "Pick a chapter... ", 5, 10, makecol(1, 1, 255), makecol(150, 1,1));
    textout_ex(screen, font, "Enter a number between 1 to 22:", 5, 20, makecol(1, 1, 255), makecol(150,1,1));
	
}

void clear_screen(){
	rectfill(screen,0,0,640,480,0);
	rest(500);
}

void getinput()
{
    rest(1000); 
	if (key[KEY_1])
        rectfill(screen,0,0,640,480,15);
    if (key[KEY_2]){
    	clear_screen();
    	chapter_list();
	}
    if (key[KEY_3])
    	rectfill(screen,0,0,640,480,15);
}
