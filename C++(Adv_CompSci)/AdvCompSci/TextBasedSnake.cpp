#include <iostream>
#include <conio.h>
#include <thread>
#include <chrono>    //for using the function sleep
using namespace std;

//g++ TextBasedSnake.cpp -std=gnu++11

#define CONTROLS_SIZE 4
#define sizeX 20
#define sizeY 20
#define speed .1

typedef enum {
	NORTH, SOUTH, WEST, EAST
} Direction;

class Person{
  private:
	int pos[2];
	char look;
	Direction facing;
	char* controls;
  public:
	Person(char _look, char* _controls){
		look = _look;
		facing = EAST;
		pos[0] = 1;
		pos[1] = 1;
		controls =  _controls;
	}
	void changeFacing(Direction dir){
		facing = dir;
	}
	Direction getFacing(){
		return facing;
	}
	void checkFacing(int ch);
	void incX(){
		if (pos[0] < sizeX){
			pos[0] = pos[0] + 1;
			cout << "Pos: " << pos[0] << "\t" << pos[1] << endl;
		}
	}
	void decX(){
		if (pos[0] > 1){
			pos[0] = pos[0] - 1;
			cout << "Pos: " << pos[0] << "\t" << pos[1] << endl;
		}
	}
	void incY(){
		if (pos[1] < sizeY){
			pos[1] = pos[1] + 1;
			cout << "Pos: " << pos[0] << "\t" << pos[1] << endl;
		}
	}
	void decY(){
		if (pos[1] > 1){
			pos[1] = pos[1] - 1;
			cout << "Pos: " << pos[0] << "\t" << pos[1] << endl;
		}
	}
	void move();
	
	
};
void Person::move(){
	if (this->getFacing() == NORTH){
		incY();
	}
	else if (this->getFacing() == SOUTH){
		decY();
	}
	else if (this->getFacing() == WEST){
		decY();
	}
	else if (this->getFacing() == EAST){
		incY();
	}
}
/*void PlayerMovement(Person *Player, bool *playing){
	while(*playing == true){
		Player->move();
	}
}*/

void Person::checkFacing(int ch){
	
	if (ch == (int)controls[0]){
		this->changeFacing(NORTH);
		cout << "NORTH" << endl;
	}
	else if (ch == (int)controls[1]){
		this->changeFacing(SOUTH);
		cout << "SOUTH" << endl;
	}
	else if (ch == (int)controls[2]){
		this->changeFacing(WEST);
		cout << "WEST" << endl;
	}
	else if (ch == (int)controls[3]){
		this->changeFacing(EAST);
		cout << "EAST" << endl;
	}
}

int main(){
	bool playing = true;
	char controls[CONTROLS_SIZE] = {'w', 's', 'a', 'd'};
	Person *Player = new Person('*', controls);
	int ch = 0;
	///thread t1(task1, Player, &playing);
	typedef std::chrono::high_resolution_clock Time;
    typedef std::chrono::milliseconds ms;
    typedef std::chrono::duration<float> fsec;
	while (playing){
		auto t0 = Time::now();
		
		if (ch == 17){ //termination
			playing = false;
		}
		else if (kbhit()){
			ch = _getch(); //getting input
			Player->checkFacing(ch);
			//cout << ch;
			_putch( ch );
		}
		else{
			ch = 0;
		}
		auto t1 = Time::now();
		fsec fs = t1 - t0;
		Player->move();
		cout << chrono::milliseconds(100) << endl;
	}
	
	return 0;
}