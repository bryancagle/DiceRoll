/*
Author: Bryan Cagle (bryancagle@my.unt.edu)
Date: 4/25/2014
Purpose: This program rolls the dice 100-5000 times (depending on user's request), and displays the result
of each value in the form of a graph
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int RandomNumber() //generates a random number from 1 to 6, the same as dice
{
	return (rand()%6+1);
}

int graph(int counter[11]) //Draws the graph for each number
{
	int i,j,scale=0;
	for (i=0;i<11;i++) //adds all the numbers up
	{
		scale+=counter[i];
	}
	//these if statements are used to create a scale, so that the graphs look similar to each other no matter what number the user inputs
	if(scale>=100&&scale<=1000){scale=10;}
	if(scale>=1001&&scale<=2000){scale=20;}
	if(scale>=2001&&scale<=3000){scale=30;}
	if(scale>=3001&&scale<=4000){scale=40;}
	if(scale>=4001&&scale<=5000){scale=50;}
	printf("\n");
	//prints a * character in relation to the number of rolls for a certain number and applying the scale
	for (i=0;i<11;i++)
	{
		printf("Rolled %d\t|",i+2);
		for(j=0;j<counter[i]/scale;j++)
		{printf("*");}
		printf("\t%d",counter[i]);
		printf("\n");
	}
	printf("----------------------------------------------\n");
	printf("\t\t* = %d rolls\n\n",scale);
}

int rolldice(int counter[11])
{
	int i,j=100,die1,die2,diceadded;
	do{
	//incase the use inputs a number that is out of range
	if(j<100||j>5000)
	{
		printf("This number is out of range, please try again\n");
	}
	printf("\nHow many times would you like to roll the dice? (100 to 5000 times): ");
	scanf("%d",&j);
	}while(j<100||j>5000);
	//User tell program how many times to roll dice, program loops to simulate dice rolls, and then tellies them in an array
	for(i=0;i<j;i++)
	{
		die1=RandomNumber();
		die2=RandomNumber();
		diceadded=die1+die2;
		switch (diceadded)
		{
			case 2: counter[0]++;break;
			case 3: counter[1]++;break;
			case 4: counter[2]++;break;
			case 5: counter[3]++;break;
			case 6: counter[4]++;break;
			case 7: counter[5]++;break;
			case 8: counter[6]++;break;
			case 9: counter[7]++;break;
			case 10: counter[8]++;break;
			case 11: counter[9]++;break;
			case 12: counter[10]++;break;
		}

	}
}
int main()
{
	srand((unsigned)time(NULL)); //used so that the random generated number is different every time the program is ran
	int counter[11]={0}; //array to hold the counts of each dice roll
	printf("\nCSCE 1030\nHomework 5\nBryan Cagle (bryancagle@my.unt.edu)\nbmc0149\n");
	rolldice(counter);
	graph(counter);
	return 0;
}
