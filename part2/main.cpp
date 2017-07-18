#include <allegro.h> 
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main(void) {
	allegro_init(); 
	set_gfx_mode(GFX_SAFE, 640, 480, 0, 0); 
	install_keyboard(); 
	textout_ex(screen, font, "Welcome to Pocket Trivia Game", 1, 1, 10, -1); 
	textout_ex(screen, font, "Press ESCape to quit.", 1, 12, 11, -1); 
	
	string line;
	ifstream myfile ("chp1.txt");
	if (myfile.is_open()){
		while(!myfile.eof()){
			getline (myfile, line);
			cout << line << '\n';
			textprintf_ex(screen, font, 0,300, makecol(255,255,255),-1, "line: %s", line.c_str());
			//textout_ex(screen, font, line, 1, 1, 10, -1); 
		}
		myfile.close();
	}
	else cout << "Unable to open file";
	
	while(!key[KEY_ESC]); 
	allegro_exit(); 
	return 0;
} 
END_OF_MAIN()
