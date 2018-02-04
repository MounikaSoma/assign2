#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <wiringPi.h>
//defining the pin to be used for the interrupt.
#define PIN 1
//defining the pins to be used to read
#define PIN1 2
#define PIN2 3
#define PIN3 4
#define PIN4 5

void handle_interrupts()
{
	//reading the pin values
	int pin1 = digitalRead(PIN1);
	int pin2 = digitalRead(PIN2);
	int pin3 = digitalRead(PIN3);
	int pin4 = digitalRead(PIN4);
	//printing the pin values
	printf("PIN1 value:%d\n",pin1);
	printf("PIN2 value:%d\n",pin2);
	printf("PIN3 value:%d\n",pin3);
	printf("PIN4 value:%d\n",pin4);
	
} 
void main()
{
	//set up
	wiringPiSetup(); 
	//setting the modes of the pins
	pinMode (PIN, INPUT);
	pinMode (PIN1, INPUT); 
	pinMode (PIN2, INPUT); 
	pinMode (PIN3, INPUT); 
	pinMode (PIN4, INPUT);
	int p1,p1_temp;
	int p2,p2_temp;
	int p3,p3_temp;
	int p4,p4_temp;
	//Assign handler function to PIN 1 by creating an ISR to it. 
	
	while(1) 
	{
		p1 = digitalRead(PIN1);
		p2 = digitalRead(PIN2);
		p3 = digitalRead(PIN3);
		p4 = digitalRead(PIN4);
		usleep(2000);
		p1_temp = digitalRead(PIN1);
		p2_temp = digitalRead(PIN2);
		p4_temp = digitalRead(PIN4);
		if(p1 != p1_temp)
		p3_temp = digitalRead(PIN3);
		{
			handle_interrupts();
		}
		else if(p2 != p2_temp)
		{
			handle_interrupts();	
		}
		else if(p3 != p3_temp)
		{
			handle_interrupts();
		}
		else if(p4 != p4_temp)
		{
			handle_interrupts();
		}	 	
	}
}

