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

void interrupt_handler()
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
	//Assign handler function to PIN 1 by creating an ISR to it. 
	wiringPiISR(PIN, INT_EDGE_BOTH, &interrupt_handler); 
	while(1) 
	{
	}
}

