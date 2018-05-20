//this is the tx code
//if left stick is reading 0,
//send 0 to rx so that it wont fly.
/*
	Ranges for flight:
	THROTTLE:0 -> 200
	ROLL:1000 -> 1200, -1200 -> -1000
	PITCH:10000 -> 10200, -10200 -> -10000
	YAW:20000 -> 20200, -20200 -> 20000
	flightMode0(): 100000
	flightMode1(): 200000
*/
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

int
LeftStickX = 14,  //A0
LeftStickY = 15,  //A1
RightStickX = 16, //A2
RightStickY = 17; //A3

const byte address[5] = {'R','o','M','e','O'};

RF24 radio(9, 10);

long command;
bool sending;

void setup()
{
	pinMode(LeftStickX, INPUT);
	pinMode(LeftStickY, INPUT);
	pinMode(RightStickX, INPUT);
	pinMode(RightStickY, INPUT);
	
	radio.begin();
	radio.setDataRate(RF24_250KBPS);
	radio.setRetries(2, 15)
	radio.openWritingPipe(address);
}

void loop()
{
	int THROTTLE, ROLL, PITCH, YAW;
	
	YAW =
	analogRead(LeftStickX);
	YAW =
	map(YAW, 0,1023,-20200, 20200);
		
	
	THROTTLE =
	analogRead(LeftStickY);
	THROTTLE = 
	map(THROTTLE,0,1023,0,200);
	
	ROLL =
	analogRead(RightStickX);
	ROLL =
	map(ROLL,0,1023,-1200,1200);
	
	PITCH =
	analogRead(RightStickY);
	PITCH =
	map(PITCH,,0,1023,-10200,10200)
	
	radio.write(YAW, THROTTLE, ROLL, PITCH &sizeof(command));
}
    
    
void OutOfRange()
{
	
}
