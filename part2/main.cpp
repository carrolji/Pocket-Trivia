#include <allegro.h> 
#include<iostream>
#include<fstream>
#include<string>
#include<stdlib.h>
using namespace std;

void start()
{
     /* stuff to clear */
     
     textout_ex(screen, font, "Pick the type of quizes:", 5, 10, makecol(1, 1, 255), makecol(150, 1,1));
     textout_ex(screen, font, "Enter (1) for entire text:", 5, 20, makecol(1, 1, 255), makecol(150,1,1));
     textout_ex(screen, font, "Enter (2) for particular unit:", 5, 30, makecol(1, 1, 255), makecol(150,1,1));
     textout_ex(screen, font, "Enter (3) for particular chapter:", 5, 40, makecol(1, 1, 255), makecol(150,1,1));
     
 }
 
 
int main(void) {
	allegro_init(); 
	set_gfx_mode(GFX_SAFE, 640, 480, 0, 0); 
	install_keyboard(); 
	textout_ex(screen, font, "Welcome to Pocket Trivia Game", 1, 1, 10, -1); 
	start();
    release_screen();
	
	
	string line;
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
	
	while(!key[KEY_ESC]){
		
		circle(screen,300,300,50,makecol(255,255,255));
	}; 
	allegro_exit(); 
	return 0;
} 
END_OF_MAIN()
