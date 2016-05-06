/***************************************************************
CSCI 240         Program 9   Spring 2016

Programmer: Alex Boyle

Section: 0009


Note:
	- Ludum dare game jam entry:
		http://ludumdare.com/compo/ludum-dare-35/?action=preview&uid=46816



Purpose: This program is a dice game
***************************************************************/

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <unistd.h>
using namespace std;



class Die
{
public:
	static const int NUM_SIDES;
	/************************
	*Die()
	*This is a constructer that 
	*creates the die class
	************************/
	Die();
	
	/************************
	*void roll();
	*This method changes the number
	*stored in the Die class
	************************/
	void roll();
	
	/************************
	*int getValue();
	*This method gets the current number
	*stored in the Die class
	*return: int stored in the Die class
	************************/
  	int getValue();

private:
  int val;
};


class Renderer
{
public:
	/************************
	*Renderer()
	*This is the constructer for 
	*the renderer class
	************************/
	Renderer();
	
	/************************
	*void clear();
	*This method clears all changes made to the base
	*template
	************************/
	void clear();
	
	/************************
	*void write(int,int,const char [],int);
	*This method writes single lines to the rendering template
	*Params:
	*		int - X position
	*		int - Y position
	*		const char [] - what is being written
	*		int - lenght of input array
	************************/
	void write(int,int,const char [],int);
	
	/************************
	*void draw(int,int,const char [],int,int);
	*This method draws a 2D ascii image
	*Params:
	*		int - X position
	*		int - Y position
	*		const char [] - what is being written
	*		int - width of image
	*		int - total chars in image
	************************/
	void draw(int,int,const char [],int,int);
	
	/************************
	*void render();
	*THis method prints out the base template will all changes 
	*since last clear call
	************************/
	void render();
private:
	char blank[60 * 15];
	char rend[60 * 15];
	
};






int main()
{
	//frame setup
	system("title Dice Game");
	system("mode con: cols=63 lines=20");
	system("color 27");
	
	
	//animation array, this was shorteded to var "a" for easy use
	int a[20][2] = {{5,9},{7,7},{9,4},{11,2},{13,2},
					{15,4},{17,6},{19,9},{21,8},{23,7},
					{25,6},{27,5},{29,4},{31,5},{33,6},
					{35,7},{37,8},{39,9},{41,9},{42,9}};
	
	
	//var setup
	Renderer renderer;
	Die die;
	int dice1;
	int dice2;
	int yourScore = 0;
	int dealerScore = 0;
	int input;
	bool even;
	srand(5);
	
	
	//Start Game Here
	cout<< "Note:\n -Number displays work best if you pick less than 10 iterations\n -For best effect dont resize window\n-------------------------------------------------------------";
	cout<< "\nHow Many times do you want to play? ";
	cin >> input;
	cout << "\nEven or odd (0 or 1)? ";
	cin >> even;
	for(int j = 0; j < input; j ++){
		for(int i = 0; i < 20; i ++){
			//clear renderer
			renderer.clear();
			//display roll number
			char rollnum[8] = {'R','o','l','l',' ',(char)(j + 49),':','\0'};
			renderer.write(5,1,rollnum,7);
			//die #1 display
			die.roll();
			switch(dice1 = die.getValue()){
				case 1:
					renderer.draw(a[i][0],a[i][1]," ----- |     ||  O  ||     | ----- ",7,7*5);
					break;
				case 2:
					renderer.draw(a[i][0],a[i][1]," ----- |O    ||     ||    O| ----- ",7,7*5);
					break;
				case 3:
					renderer.draw(a[i][0],a[i][1]," ----- |O    ||  O  ||    O| ----- ",7,7*5);
					break;
				case 4:
					renderer.draw(a[i][0],a[i][1]," ----- |O   O||     ||O   O| ----- ",7,7*5);
					break;
				case 5:
					renderer.draw(a[i][0],a[i][1]," ----- |O   O||  O  ||O   O| ----- ",7,7*5);
					break;
				case 6:
					renderer.draw(a[i][0],a[i][1]," ----- |O   O||O   O||O   O| ----- ",7,7*5);
					break;
			};
			//die #2 display
			die.roll();
			switch(dice2 = die.getValue()){
				case 1:
					renderer.draw(a[i][0]+8,a[i][1]," ----- |     ||  O  ||     | ----- ",7,7*5);
					break;
				case 2:
					renderer.draw(a[i][0]+8,a[i][1]," ----- |O    ||     ||    O| ----- ",7,7*5);
					break;
				case 3:
					renderer.draw(a[i][0]+8,a[i][1]," ----- |O    ||  O  ||    O| ----- ",7,7*5);
					break;
				case 4:
					renderer.draw(a[i][0]+8,a[i][1]," ----- |O   O||     ||O   O| ----- ",7,7*5);
					break;
				case 5:
					renderer.draw(a[i][0]+8,a[i][1]," ----- |O   O||  O  ||O   O| ----- ",7,7*5);
					break;
				case 6:
					renderer.draw(a[i][0]+8,a[i][1]," ----- |O   O||O   O||O   O| ----- ",7,7*5);
					break;
			};
			//render frame
			renderer.render();
			//sleep for a sec then move on to the next frame
			usleep(100000);
		}
		//this if desides who wins the roll
	 	if(even ? (dice1+dice2)%2 == 1 : (dice1+dice2)%2 == 0){
	 		cout<<"\nYou Win!\n";
	 		yourScore ++;
		}else{
			cout << "\nDealer Wins!\n";
			dealerScore ++;
		}
		system("pause");
	}
	//clear renderer
	renderer.clear();
	//end game cstring setup
	char you[30] = {'Y','o','u','r',' ','f','i','n','a','l',' ','s','c','o','r','e',' ','i','s',' ',(char)(yourScore + 48),' ','p','o','i','n','t','s','.','\0'};
	char deal[34] = {'D','e','a','l','e','r',(char)96,'s',' ','f','i','n','a','l',' ','s','c','o','r','e',' ','i','s',' ',(char)(dealerScore + 48),' ','p','o','i','n','t','s','.','\0'};
	char win[9] =  {'Y','o','u',' ','W','i','n','!','\0'};
	char loss[9] =  {'Y','o','u',' ','L','o','s','t','\0'}; 
	//setup and display end game message
	if(yourScore <= dealerScore)
			renderer.write(28,9,loss,8);
	else 
			renderer.write(28,9,win,8);
	renderer.write(16,4,you,29);
	renderer.write(14,6,deal,33);
	renderer.render();
return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////for spacing
const int Die::NUM_SIDES = 6;
Die::Die(){
	roll();
}
void Die::roll(){
	val = 1+(rand()%NUM_SIDES);
}
int Die::getValue(){

	return val;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////for spacing
Renderer::Renderer(){
	for(int i = 0; i < 60*15; i ++){
		if(i < 60)
			blank[i] = '\334';
		else if(i > 60*14)
			blank[i] = '\334';
		else if(i%60 ==0)
			blank[i] = '\335';
		else if(i%60 ==59)
			blank[i] = '\336';
		else
			blank[i] = ' ';
	}
	
	for(int i = 0; i < 60*15; i ++)
		rend[i] = blank[i];
}
void Renderer::clear(){
	for(int i = 0; i < 60*15; i ++)
		rend[i] = blank[i];
	system("cls");
}
void Renderer::write(int x,int y,const char a[],int len){
	for(int i = 0; i < len;i++)
		rend[(y * 60)+x+i] = a[i];
}
void Renderer::draw(int x,int y,const char  a[],int width,int len){
	int y1 = y-1;
	int x1 = x;
	for(int i = 0; i < len;i++){
		if(i%width == 0)
			y1 ++;
		rend[(y1 * 60)+x1+(i%width)] = a[i];
	}
}
void Renderer::render(){
	for(int i = 0; i < 60*15; i ++){
		if( (i%60) == 0)
			cout<<endl;
		printf("%c", rend[i]);//printf is used for speed
		
	}
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////for spacing
