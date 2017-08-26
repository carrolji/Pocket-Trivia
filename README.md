
# POCKET - TRIVIA

## Game Design Document

### General Overview
The game is to quiz learners on their knowledge on material covered in the e-textbook: Game Programming All in One, 3rd Edition. At the beginning of the game, there are options for users to choose if the quiz will be on the entire text, a particular unit, or a particular chapter. Each set of game contains 10 multiple-choice questions that will present randomly to the user each time. At the end, the game will show the points the user scored dynamically in the form of ratio.
The goal of this game is to allow learners to review the material at the end of each chapter, unit or the overall Game Programming textbook.

### Target System and Requirements
The target system for this game is Windows, which must include allegro library. Requirements are question text files and answer text files. Each line of the question text file cannot be longer than 80 characters (including white spaces), otherwise it must be on the new line. The answer text file must be in the following format where the answer must be on the next line below following each question.

### Theme: Graphics and Sound
The game contains simple theme design with simple colors. The main color for the text is white and the background color is black. There is no background music, for the user to focus on reading each question carefully without distraction. Green color text is used to represent correct answer while red color text is used to represent incorrect answer. The scoreboard is in orange color to give a neutral feel and grasp the eye of the users. This game has an introduction sound at the beginning of the game to attract users, a correct sound when the user answers the question right, an incorrect sound when the user answers the question wrong and a clapping sound at the end of the game.

### Music Credit 
* Wrong answer by SgtPepperArc360

https://freesound.org/people/SgtPepperArc360/sounds/341732/

* Retro game sound, button select by Cabeeno Rossley

https://freesound.org/people/Cabeeno%20Rossley/sounds/126418/

* Cartoon game theme loop by Mrthenoronha

https://freesound.org/people/Mrthenoronha/sounds/369920/

### Menus
The menu displays the title of the game with circle lights to get users attention as if they are in a game show. There is a description under the game title explaining what the game is about and how users can play. Users must PRESS HOLD onto ENTER key to proceed to the next menu, which displays three options for users to choose if they’d like the quiz to be on the entire text, a particular unit, or a particular chapter.

### Playing a Game
The game starts with a welcome menu and the music plays. The game prompts the users to press hold on an ENTER key to continue. Later, the game displays three choices for users to choose what kind of quiz to play. If users choose the first option which is the entire textbook, the quiz will then start. If users choose the second option, a particular unit, the game will then prompt users the enter any number between 1 to 8 then press Enter. Users can press any key between 1 to 8 to change their choice. If users choose the third option, a particular chapter, the game prompts the users to key in number between 1 to 22 then press Enter. Users can press backspace to erase and re-input a new number. Once the quiz starts users must go through all 10 multiple-choice questions randomly. The top left text displays chapter of the question that is being quiz, this allows users to be aware on the subject material. The score on the top right will keep track on users’ performance. The game prompts users to enter answer by press any key input of A, B, C and D. Once the key is pressed, users cannot reconsider their choice and the game processes for the answer. If users answer the question correctly, the score will increment by one and continues to the next question. If users answer the question incorrectly, the score will stay the same and the correct answer will display at the bottom. At the end of the game, the game score will display in percentage with a clapping sound to notify users that they have finished the game successfully. The message will displays based on the users’ performance and users can quit the game by enter Esc key.
