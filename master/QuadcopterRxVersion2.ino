/*
NOTES:
jerome, you still need to add radio failsafes...

btw, you switched some whiles to ifs and ifs to whules

have a variable for trimming some values and changing speed, 
ie the ones where values are subtracted from. Make those 
variables so that they can be manipulated.	
*/

#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

#include <Servo.h>

const byte address[5] = {'R','o','M','e','O'};

RF24 radio (9, 10);

long command;

bool newData = false;

//init all vars using previous code
/*motor 1 is CW, 2 is front right, 3 is back left, 4 is back right */

void setup(){
	radio.begin();
	radio.setDataRate(RF24_250KBPS);
	radio.setRetries(2, 15);
	radio.openReadingPipe(1, address);
	radio.startListening();
}

void loop(){
	bool armed = false;
	bool mode0 = true;

	preArm();

	flightMode0();

	flightMode1();

	changeMode();
}

void preArm()
{
	if(armed == false)
	{
		a.write(5);
		b.write(5);
		c.write(5);
		d.write(5);
		delay(4000);
		armed == true;
	}
}

void flightMode0()
{
	while(armed == true && mode0 = true)
	{
		if(radio.available())
		{
			radio.read(command,&sizeof(command));
			newData = true;
		}
		
		if(newData = true)
		
////////////////THROTTLE///////////////

			if(command >= 0 && command <= 200)
			{
				int throttle;
				throttle = command;
				a.write(throttle);
				b.write(throttle);
				c.write(throttle);
				d.write(throttle);
			}
		
/////////////////ROLL//////////////////

			if(command >= 1000 && command <= 1200)
			{
				int roll;
				roll = command - 1000;
				a.write(roll);
				b.write(roll -= 20);
				c.write(roll);
				d.write(roll -= 20);
			}

			if(command >= -1200 && command <= -1000)
			{
				int negRoll;
				negRoll = (command * -1) -1000;
				a.write(negRoll -= 10);
				b.write(negRoll);
				c.write(negRoll -= 10);
				d.write(negRoll);
			}

/////////////////PITCH/////////////////

			if(command >= 10000 && command <= 10200)
			{
				int pitch;
				pitch = command -= 10000;
				a.write(pitch -= 10);
				b.write(pitch -= 10);
				c.write(pitch);
				d.write(pitch);
			}

			if(command >= -10200 && command <= -10000)
			{
				int negPitch;
				negPitch = (command * -1) - 10000;
				a.write(negPitch);
				b.write(negPitch);
				c.write(negPitch -= 10);
				d.write(negPitch -= 10);
			}

/////////////////YAW///////////////////

			if(command >= 20000 && command <= 20200)
			{
				int yaw;
				yaw = command -= 20000;
				a.write(yaw);
				b.write(yaw -= 20);
				c.write(yaw -= 20);
				d.write(yaw);
			}

			if(command >= -20200 && command <= -20000)
			{
				int negYaw;
				negYaw = (command * -1) -20000;
				a.write(negYaw -= 20);
				b.write(negYaw);
				c.write(negYaw);
				d.write(negYaw -= 20);
			}
		
		newData = false;
		}
	}
}

void flightMode1(){
	//old flight mode settings here...
	while(armed == true && mode = 1){
		//main code belongs here...
		}
}

void changeMode(){
	if(command = 100000){
		mode0 = false;
		}

	if(command = 200000){
		mode0 = true;
	}
}
    
    
