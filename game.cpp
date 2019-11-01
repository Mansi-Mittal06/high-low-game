 /* HIGH/LOW GAME */
#include<iostream>
#include<conio.h>
#include<stdlib.h>
/*
This program plays a simple game.
*/
const int totchan=7;
int main()
{
 int number;        //the computer's random number
 int guess;         //the user's guess
 int chances=0,score=0,chanscor;        //chanscor stores score for 1successful chance.
 char ans;
 do
  {
   chances=score=0;
   std::cout<<"Welcome to the High/Low game. \n" ;
   std::cout<<"I will pick a random number from 0 to 100. \n";
   std::cout<<"You must try to guess the number. \n";
   number=(int)(rand()%100);
   chanscor=100/totchan;        //score for each successful chance
   do
   {
     std::cout<<"What is your guess? (0 to 100) ";
     std::cin>>guess;
     if((guess<0)||(guess>100))
     {
	std::cout<<"Sorry, but your guess "<<guess<<"must be from 0 to 100.";
     }
     else if(guess < number)
     {std::cout<<guess<<" is low.Try a higher number.";
     }
     else if(guess > number)
     {
	std::cout<<guess<<" is high.Try a lower number.";
     }
     else		//if correct number is guessed
     {			//number is correct, and the "do" loop will end below
	std::cout<<guess<<" is correct. Congratulations!";
	score=chanscor*(totchan-chances);   //score calculated for number ofchances left
	std::cout<<"Your score is "<<score<<std::endl;
        break;
     }
     chances++;
     if(guess!=number)
	 std::cout<<"Now you have "<<totchan-chances<<"chances left."<<std::endl;
     if(chances==totchan)
	 {
	     std::cout<<"Only "<<totchan<<"chances are allowed.Better luck next time";
	   std::cout<<"The actual number was "<<number<<std::endl;
	   break;
	 }
     }while (guess!=number);
     std::cout<<"Thank you for playing High/Low!";
     std::cout<<"Want to play it again? (y/n)...";
     std::cin>>ans;
   }while(ans=='y' || ans=='Y');
   return 0;
 }
