#include <iostream>			//Declaration.
#include <cstring>			//Another declarations.
#include <Windows.h>		//Windows.h needed to make Sleep work.
#include <time.h>			//Even more declarations.
#include <string>			//The last declaration.
#ifdef min					//Undefined the...
#undef min					//min...
#endif						//and...
#ifdef max					//max...
#undef max					//thing that stops the max...
#endif						//working in the cin.ignore statements.

using namespace std;

void Shuffle(int);			//Declaring the Shuffle function.
void PlayFunction(void);	//Declaring the Play function.
void RulesFunction(void);	//Declaring the rules function.

struct Card					//Start of Card structure.
{
	char Name[10];			//Creates char array called Name with array size of 10 as this will be the suit name word length and no card name will be longer, in length, than 10.
	char Suit[10];			//Creates char array called Suit with array size of 10 as this will be the suit name word length and no card suit name will be longer, in length, than 10.
	int Value;				//Creates int called value. This will be the card value. These will set later on in the structure.
};				

int main(void)
{
	int MenuChoice;						//Creating all int's needed for the main function.
	bool MenuSelection=true;			//Creating all bool's needed for the main function and initially setting it to true.
	
	while(MenuSelection==true)			//while loop for the menu. If the menu selection is false it will not enter the while loop.
	{
		cout << "Hi, Player, please select the number of the option that you wish to do? \n"	//On screen text for the player to read. Asks question. This is what they first see of the menu.
			 << "1. Play\n"																		//On screen text for the first option, which is Play.
			 << "2. Rules\n"																	//On screen text for the second option, which is Rules.
			 << "3. Leave\n";																	//On screen text for the second option
		
		while(!(cin>>MenuChoice))																							//While loop for menu choice. Loops if player enters something that isn't an int.
		{
			cin.clear();																									//Clears istream.
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');													//Ignores, sets limits for stream size aand sets maximun length and creates new line for the text (Below).
			cout << "Invalid input. Must be 1 (Play game) or 2 (Go to the Rules) or 3 (Leave casino). Try again: \n\n";		//On screen text to tell player they entered the wrong input. Tells them correct inputs and tells them to try again. Player then can re-input their choice.
		}

		switch(MenuChoice)																											//Switch statement for the MenuChoice options.
		{
			case 1:		PlayFunction();																								//Game goes to the Play function when 1 is inputted.
						break;																										//Then breaks out of the switch statement.
			case 2:		RulesFunction();																							//Goes to the Rules function when 2 is inputted.
						break;																										//Then breaks out of the switch statement.
			case 3:		MenuSelection=false;																						//Doesn't go to the any function and sets MenuSelection to false so it'll break out of the switch statement while loop. This therefore allows them to leave the game successfully.
						break;																										//Then breaks out of the switch statement.
			default:	cout << "Wrong Selection! Try Again. Must be 1 (Play game) or 2 (Go to the Rules) or 3 (Leave casino)";		//On screen text to tell them they ahve inputted a number that isn't 1, 2 or 3.
						Sleep(1000);																								//Sets Sleep for aa period of time, enough time so they can read the sentance.
						break;																										//Then breaks out of the switch statement.
		}
	}

	return 0;																														//Returns 0 when this point of the main function is reached, therefore setting the main function to false and ending the game.
}

void Shuffle(int DealDeck[])			//Start of Shuffle function. Output is void, therefore there will no output from this function. Inputs DealDeck array from Play function.
{
	srand((unsigned)time(0));			//Makes random dependant on time.
	for(int i=0; i<52; i++)				//For loop created to loop 52 times (52=number of cards in deck)
	{
		int RandomCard=rand()%52;		//Creates RandomCard and initialises it a random number between 0 and 2.
		DealDeck[i]=RandomCard;			//Sets each number in array to the value of the random card (Will do this 52 times due to for loop).
	}
}

void PlayFunction(void)		//Start of Play function. Void output and input. Therefore, function needs no return and will just play through.
{
	int Chips=0;			//Creates Chips as an int and initialises it to 0.
	bool Play=true;			//Createss Play as a bool and initialises it to true.

	system("CLS");														//Clears screen.
	cout << "Firstly, here's 1000 chips on the house to start.\n\n"		//On screen text to tell player they've been given 1000 chips to start the game.
		 << "PRESS ENTER TO CONTINUE\n";								//On screen text to tell player to press enter to continue.
	cin.get();															//Cin.get() requires user needs to press enter. First cin.get() is already taken as the user pressed enter when coming into this function from the menu.
	cin.get();															//Cin.get() requires user to press enter to continue.
	Chips=Chips+1000;													//Adds 1000 chips to the players' original amount of 0.
	
	while(Play==true)													//Start of while loop. Loops when Play is true.
	{
		int DealDeck[52],PlayerHand=0,DealerHand=0,CardNumber[40],PlayerChoice=0,PlayAgain=0,FaceDownCard=0,TempHand=0,Bet=0;															//Creates and initialises all ints for this function. These are set in the play loop as some of these will need to be reset when a new games has been started.
		bool Bust=false,BlackJack=false,Hit=false,DealerTurn=true,DBust=false,DBlackJack=false,Winner=false,Stand=false,Tie=false,ValidBet=false,Outcome=false,ValidSelection=false;	//Creates and initialises all bools for thiss function. These are set in the play loop as some of these will need to be reset when a new games has been started.
	
		struct Card Deck[52];											//Start of Card structure. Deck array has been passed into this.
	
		for(int i=0; i<52; i+=13)										//Start of for loop. Creates int called i. After each go through the for loop, it adds 13 to i, which is the same amount as the amount as the different card names, not taking into account suits. Stops loop when i reaches 52, which is the same amount as te number of cards in a deck (Not including jokers).
		{
			for(int k=0; k<13; k++)										//Start of for loop. Creates int called k. Adds 1 to K after each go through loop, until it reaches 12, which is because this is to initialise each card, one suit at a time.
			{
				if(i==0)												//If statement is entered if i is equal to 0.
				{
					strcpy(Deck[i+k].Suit,"Clubs");						//If if statement is entered the word 'Clubs' to the suit array attached to Deck[i+k]
				}

				if(i==13)												//If statement is entered if i is equal to 13.
				{
					strcpy(Deck[i+k].Suit,"Diamonds");					//If if statement is entered the word 'Diamonds' to the suit array attached to Deck[i+k]
				}

				if(i==26)												//If statement is entered if i is equal to 26.
				{
					strcpy(Deck[i+k].Suit,"Hearts");					//If if statement is entered the word 'Hearts' to the suit array attached to Deck[i+k]
				}

				if(i==39)												//If statement is entered if i is equal to 39.
				{
					strcpy(Deck[i+k].Suit,"Spades");					//If if statement is entered the word 'Spades' to the suit array attached to Deck[i+k]
				}

				switch(k)												//Start of switch statement for k.
				{
					case 0:		strcpy(Deck[i+k].Name, "Ace");			//Copies the word 'Ace' to the name array attached to Deck[i+k].
								Deck[i+k].Value=11;						//Sets value to 11 for the Value int attached to Deck[i+k].
								break;									//Breaks from switch statement when all things for this case have been completed.
					case 1:		strcpy(Deck[i+k].Name, "Two");			//Copies the word 'Two' to the name array attached to Deck[i+k].
								Deck[i+k].Value=(k+1);					//Sets value to (k+1) for the Value int attached to Deck[i+k].
								break;									//Breaks from switch statement when all things for this case have been completed.
					case 2:		strcpy(Deck[i+k].Name, "Three");		//Copies the word 'Three' to the name array attached to Deck[i+k].
								Deck[i+k].Value=(k+1);					//Sets value to (k+1) for the Value int attached to Deck[i+k].
								break;									//Breaks from switch statement when all things for this case have been completed.
					case 3:		strcpy(Deck[i+k].Name, "Four");			//Copies the word 'Four' to the name array attached to Deck[i+k].
								Deck[i+k].Value=(k+1);					//Sets value to (k+1) for the Value int attached to Deck[i+k].
								break;									//Breaks from switch statement when all things for this case have been completed.
					case 4:		strcpy(Deck[i+k].Name, "Five");			//Copies the word 'Five' to the name array attached to Deck[i+k].
								Deck[i+k].Value=(k+1);					//Sets value to (k+1) for the Value int attached to Deck[i+k].
								break;									//Breaks from switch statement when all things for this case have been completed.
					case 5:		strcpy(Deck[i+k].Name, "Six");			//Copies the word 'Six' to the name array attached to Deck[i+k].
								Deck[i+k].Value=(k+1);					//Sets value to (k+1) for the Value int attached to Deck[i+k].
								break;									//Breaks from switch statement when all things for this case have been completed.
					case 6:		strcpy(Deck[i+k].Name, "Seven");		//Copies the word 'Seven' to the name array attached to Deck[i+k].
								Deck[i+k].Value=(k+1);					//Sets value to (k+1) for the Value int attached to Deck[i+k].
								break;									//Breaks from switch statement when all things for this case have been completed.
					case 7:		strcpy(Deck[i+k].Name, "Eight");		//Copies the word 'Eight' to the name array attached to Deck[i+k].
								Deck[i+k].Value=(k+1);					//Sets value to (k+1) for the Value int attached to Deck[i+k].
								break;									//Breaks from switch statement when all things for this case have been completed.
					case 8:		strcpy(Deck[i+k].Name, "Nine");			//Copies the word 'Nine' to the name array attached to Deck[i+k].
								Deck[i+k].Value=(k+1);					//Sets value to (k+1) for the Value int attached to Deck[i+k].
								break;									//Breaks from switch statement when all things for this case have been completed.
					case 9:		strcpy(Deck[i+k].Name, "Ten");			//Copies the word 'Ten' to the name array attached to Deck[i+k].
								Deck[i+k].Value=10;						//Sets value to (k+1) for the Value int attached to Deck[i+k].
								break;									//Breaks from switch statement when all things for this case have been completed.
					case 10:	strcpy(Deck[i+k].Name, "Jack");			//Copies the word 'Jack' to the name array attached to Deck[i+k].
								Deck[i+k].Value=10;						//Sets value to (k+1) for the Value int attached to Deck[i+k].
								break;									//Breaks from switch statement when all things for this case have been completed.
					case 11:	strcpy(Deck[i+k].Name, "Queen");		//Copies the word 'Queen' to the name array attached to Deck[i+k].
								Deck[i+k].Value=10;						//Sets value to (k+1) for the Value int attached to Deck[i+k].
								break;									//Breaks from switch statement when all things for this case have been completed.
					case 12:	strcpy(Deck[i+k].Name, "King");			//Copies the word 'King' to the name array attached to Deck[i+k].
								Deck[i+k].Value=10;						//Sets value to (k+1) for the Value int attached to Deck[i+k].
								break;									//Breaks from switch statement when all things for this case have been completed.
					default:	cout << "Broken!";						//If k doesn't match any of the cases, the default will be activated aand it wil tell the plaayer tha it is broken. Unlikely to happen, unless the switch statement or k is changed, due to k being set as a whole number from 0 until 12;
								break;									//Breaks from switch statement when all things for this case have been completed.
				}
			}
		}

	
		Shuffle(DealDeck);				//Accesses the Shuffle function. Goes into it, goes through it and then comes back to here.

		for(int X=0; X<40; X++)			//For statement to set CardNumber array.
		{
			CardNumber[X]=X;			//Sets each value of array to it's place in the array.
		}
		
		while(ValidBet==false)																//While loop to loop if valid bet is false
		{
			system("CLS");																	//Clears screen.
			cout << "Current Chips: " << Chips << "		Current Bet: " << Bet << "\n\n"		//On screen text to tell user their current chips annd current bet.
				 << "Now, how much would you like to bet?\n\n";								//on screen text to ask how much the user would like to bet.
			
			while(!(cin>>Bet))																//While loop loops if cin is not a correct bet. Therefore, will loop if they input something that isn't an int for Bet.
			{
				cin.clear();																//Clears istream.
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');				//Ignores, sets limits for stream size aand sets maximun length and creates new line for the text (Below).
				cout << "Invalid input. Must be a number. Try again: \n\n";					//On screen text to tell player they entered the wrong input. Tells them correct inputs and tells them to try again. Player then can re-input their choice.
			}

			if(Bet>Chips || Bet<=0)													//If statement entered if, Bet is of a higher value than Chips, or Bet is equal or 0 or less.
			{
				ValidBet=false;														//Sets valid bet to false if the if statement is entered.
				cout << "Invalid bet. Try again. (Cannot bet 0 or less)\n\n";		//On screen text to tell user they've entered an invalid Bbet. Tells them to try and again and tells tham what they should be entering.
				system("CLS");														//Clear screen.
			}
			else																	//If if statement is not entered, else will be entered.
			{
				Chips=Chips-Bet;													//If else is entered Bet is taken away from Chips to give a new value to Chips.
				cout << "Right, let's go.\n\n";										//On screen text to tell user that we're now going forward.
				ValidBet=true;														//Sets ValidBet to true.
				cout << "PRESS ENTER TO CONTINUE\n";								//On screen text tell user to press enter to continue.
				cin.get();															//Cin.get() requires user needs to press enter. First cin.get() is already taken as the user pressed enter when coming into this function from the menu.
				cin.get();															//Cin.get() requires user to press enter to continue.
				system("CLS");														//Clears screen.
			}
		}

		cout << "Current Chips: " << Chips << "		Current Bet: " << Bet << "\n\n"																		//On screen text to tell user their current chips annd current bet.
			 << "Initial Deal: \n"																														//On screen text saying 'Initial Deal: '.
			 << "Player has been drawn the " << Deck[DealDeck[CardNumber[0]]].Name << " of " << Deck[DealDeck[CardNumber[0]]].Suit << "\n\n";			//On screen text tells user the card they've drawn a card, complete with name of card and name of card suit.

		CardNumber[0]=Deck[DealDeck[CardNumber[0]]].Value;																								//Sets value of CardNumber to the value of Deck[DealDeck[CardNumber[0]]].
		Sleep(1000);																																	//Pauses program for around a second, I think.

		cout << "The Dealer has been drawn the " << Deck[DealDeck[CardNumber[1]]].Name << " of " << Deck[DealDeck[CardNumber[1]]].Suit << "\n\n";		//On screen text tells user that the dealer has been drawn a card, complete with name of card and name of card suit.

		CardNumber[1]=Deck[DealDeck[CardNumber[1]]].Value;																								//Sets value of CardNumber to the value of Deck[DealDeck[CardNumber[1]]].
		DealerHand=DealerHand+CardNumber[1];																											
		Sleep(1000);																																	//Pauses program for around a second, I think.
	
		cout << "Player has been drawn the " << Deck[DealDeck[CardNumber[2]]].Name << " of " << Deck[DealDeck[CardNumber[2]]].Suit << "\n\n";			//On screen text tells user the card they've drawn a card, complete with name of card and name of card suit.
	
		CardNumber[2]=Deck[DealDeck[CardNumber[2]]].Value;																								//Sets value of CardNumber to the value of Deck[DealDeck[CardNumber[2]]].
		Sleep(1000);																																	//Pauses program for around a second, I think.
	
		cout << "The Dealer has been drawn a card but it will remain face down until you \n"															//On screen text tells user that the dealer has drawn a card but it is currently face down. The Dealer's facedown card will be revealed after the player has had his turn.
			 << "finish your go.\n\n";																													//On screen text finishing the sentance above.

		FaceDownCard=CardNumber[3];																														//Sets value of CardNumber[3] to an int called FaceDownCard, which will be used to draw the facedown card after the player haas had his turn.
		Sleep(1000);																																	//Pauses program for around a second, I think.

		TempHand=CardNumber[0]+CardNumber[2];						//Sets TempHand value to the value of CardNumber[0] plus the value of CardNumber[2].
		if(TempHand>21)												//Enters if statement if TempHand has a value of over 21.
		{
			if(CardNumber[0]==11 || CardNumber[2]==11)				//Enters if statement if CardNumber[0] or CardNumber[2] is equal to 11.
			{
				for(int	D=0; D<52; D++)								//For loop loops until D is equal to 52, starting at 0 and going up 1 at a time.
				{
					if(Deck[DealDeck[D]].Value==11)					//Enters if statement if the value of Deck[DealDeck[D]] is equal to 11.
					{
						Deck[DealDeck[D]].Value=1;					//Then changes value of Deck[DealDeck[D]] to 1.
					}
				}

				if(CardNumber[0]==11)								//Enters if statement if the value of CardNumber[0] is equal to 11.
				{
					CardNumber[0]=1;								//Changes the value of CardNumber[0] from 11 to 1, if the if statement has been entered.
				}

				if(CardNumber[2]==11)								//Enters if statement if the value of CardNumber[0] is equal to 11.
				{
					CardNumber[2]=1;								//Changes the value of CardNumber[0] from 11 to 1, if the if statement has been entered.
				}
			}
		}

		PlayerHand=CardNumber[0]+CardNumber[2];										//Sets the value of PlayerHand to the value of CardNumber[0] plus the value of CardNumber[2].
		cout << "Giving the player a hand value of " << PlayerHand << "\n\n";		//On screen text tells user the value of their hand.
		Sleep(1000);																//Pauses program for around a second, I think.

		if(PlayerHand>21)								//Enters if statement if PlayerHand has a value of over 21.
		{
			Bust=true;									//Sets Bust to true.
			cout << "\nBust! Haha, you lose.\n"			//On screen text tells that they're lost and also laughs at the user.
				 << "TO MOVE ON, PRESS ENTER.\n\n";		//On screen text tells user to press enter to continue with their game.
			cin.get();									//Cin.get() requires user needs to press enter. First cin.get() is already taken as the user pressed enter when coming into this function from the menu.
			cin.get();									//Cin.get() requires user to press enter to continue.
		}

		if(PlayerHand==21)																							//Enters if statement if PlayerHand has a value of 21.
		{
			BlackJack=true;																							//Sets BlackJack to true.
			cout << "BlackJack! But not so fast, if The Dealer also gets a BlackJack then you'll only tie.\n\n";	//On screen texts tells user that they have a BlackJack but they haven't won because The Dealer could also get a BlackJack and then the player would only draw.
			Sleep(1000);																							//Pauses program for around a second, I think.
			Hit=false;																								//Sets Hit to false.
			Stand=true;																								//Sets Stand to true.
		}
		else
		{
			cout << "Player's Turn: \n";																			//If if statement isn't else is entered and on screen text tells user that it's now the player's turn.
		}

		for(int z=4; z<20; z++)																		//for statement loops for z, starting from 4 and looping until z becomes 20.
		{
			while(Bust==false && BlackJack==false && Stand==false)									//Enters while loop if the player hasn't Bust, the player hasn't hit a BlackJack and the Player hasn't Standed.
			{
				cout << "Would you like to...? (Type the number of the option you'd like to do)\n"	//On screen text asks they is they want to...
					 << "1.Stand\n"																	//Stand...
					 << "or\n"																		//Or...
					 << "2.Hit\n\n";																//Hit...
				
				while(ValidSelection==false)															//Enters while loop is ValidSelection is false, which is at the beginning will continue to be until the player makes a correct selection.
				{
					while(!(cin>>PlayerChoice))														//While loop for PlayerChoice. Loops if player enters something that isn't an int.
					{
						cin.clear();																//Clears istream.
						cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');				//Ignores, sets limits for stream size aand sets maximun length and creates new line for the text (Below).
						cout << "Invalid input. Must be 1 (Stand) or 2 (Hit). Try again: \n\n";		//On screen text to tell player they entered the wrong input. Tells them correct inputs and tells them to try again. Player then can re-input their choice.
					}

					if(PlayerChoice==1)																		//Enters if statement if PlayerChoice is equal to 1, which equates to the Player choosing to Stand.
					{
						Stand=true;																			//Sets Stand to true.
						Hit=false;																			//Sets Hit to false.
						ValidSelection=true;																//The Player has selected a correct selection and valid selection is set to true. This allows the user to leave the while loop.
					}
					else
					{
						if(PlayerChoice==2)																	//If the Player hasn't selected 1, then it goes into else and then this if statement is entered if the Player has selected 2.
						{
							Hit=true;																		//Sets Hit to true.
							Stand=false;																	//Sets Stand to false.
							ValidSelection=true;															//The Player has selected a correct selection and valid selection is set to true. This allows the user to leave the while loop.
						}
						else																				//Enters else if PlayerChoice isn't 1 or 2
						{
							ValidSelection=false;															//Sets ValidSelection to false.
							cout << "Invaild selection. Needs to be 1 (Hit) or 2 (Stand). Try Again.\n";	//On screen text tell user that they've entered the wrong input. Tells them they should be inputting 1 or 2 and then tells them to try again.
						}
					}
				}

				while(Hit==true)																																//Enters while loop if the player has just selected Hit.
				{
					cout << "\nPlayer has been drawn the " << Deck[DealDeck[CardNumber[z]]].Name << " of " << Deck[DealDeck[CardNumber[z]]].Suit << "\n";		//On screen text tells user the card they've drawn a card, complete with name of card and name of card suit.

					CardNumber[z]=Deck[DealDeck[CardNumber[z]]].Value;						//Sets the value of CardNumber[z] to the value of Deck[DealDeck[CardNumber[z]]].Value.
					TempHand=PlayerHand+CardNumber[z];										//Sets TempHand value to the value of PlayerHand plus CardNumber[z].
					Sleep(1000);															//Pauses program for roughly a second.

					if(TempHand>21)															//Enters if statement if TempHand has a value of over 21.
					{
						if(CardNumber[0]==11 || CardNumber[2]==11 || CardNumber[z]==11)		//Enters if statement if CardNumber[0], CardNumber[2] or CardNumber[z] is equal to 11.
						{
							for(int	D=0; D<52; D++)											//For loop loops until D is equal to 52, starting at 0 and going up 1 at a time.
							{
								if(Deck[DealDeck[D]].Value==11)								//Enters if statement if the value of Deck[DealDeck[D]] is equal to 11.
								{
									Deck[DealDeck[D]].Value=1;								//Then changes value of Deck[DealDeck[D]] to 1.
								}
							}

							for(int K=0; K<20; K++)											//For loop loops until K is 20, with K starting at 0 and going until 20. K is used because this allows the for look to go throughthe first 20 values in the CardNumber array and check it.
							{
								if(CardNumber[K]==11)										//Enters if statement if CardNumber[K] has a value of 11.
								{
									CardNumber[K]=1;										//Then sets the value of CardNumber[K] to 1.
								}
							}
						}
					}

					Hit=false;																//Sets Hit to false.
					PlayerHand=PlayerHand+CardNumber[z];									//Adds previous value of PlayerHand to the value of the card that The Player haas just drawn to give a new value to PlayerHand.
				}

				cout << "Giving the player a hand value of " << PlayerHand << "\n\n";		//On screen text tells the player the value of their hand.
				Sleep(1000);																//Pauses program for around a second, I think.

				if(PlayerHand>21)								//Enters if statement if their hand iss less than 21.
				{
					Bust=true;									//Sets Bust to true.
					cout << "\nBust! Haha, you lose.\n\n";		//On screen text tells that they're lost and also laughs at the user.
					cin.get();									//Cin.get() requires user to press enter to continue.
				}

				if(PlayerHand==21)																								//Enters if statement if PlayerHand has a value of 21.
				{
					BlackJack=true;																								//Sets BlackJack to true.
					cout << "BlackJack! But not so fast, if The Dealer also gets a BlackJack then you'll only tie.\n\n";		//On screen text tells user that they've got a BlackJack but if The Dealer also gets a BlackJack then they will only draw.
					cin.get();																									//Cin.get() requires user to press enter to continue.
					Hit=false;																									//Sets Hit to false.
					Stand=true;																									//Sets Stand to true.
				}
			}
		}

		while(Bust==false && Hit==false && Stand==true && Outcome==false)																						//Enters while loop and loops if the player hasn't gone Bust, hasn't hit/stopped Hitting and the Outcome hasn't been decided.
		{
			cout << "Dealer's Turn: \n"																															//On screen text tells user that it's the Dealer's Turn.
				 << "The Dealer's facedown card was the " << Deck[DealDeck[FaceDownCard]].Name << " of " << Deck[DealDeck[FaceDownCard]].Suit << "\n\n";		//On screen text tells user what the dealer's FaceDownCard was, complete with name of card and name of card suit.

			CardNumber[3]=Deck[DealDeck[FaceDownCard]].Value;																									//Sets value of CardNumber[3] to the value of FaceDownCard.
			DealerHand=DealerHand+CardNumber[3];																												//Adds previous value of DealerHand to the value of CardNumber[3] to give a new value to DealerHand.
			Sleep(1000);																																		//Pauses program for around a second, I think.

			cout << "Giving The Dealer a hand value of " << DealerHand << "\n\n";																				//On screen text tells user the value of The Dealer's hand.
		
			for(int N=20; N<40; N++)			//For loop loops from N=20, until N is 40. This is used to help change the CardNumber every time it loops, therefore, allowing a new card to be drawn every time it loops, until it stops looping.
			{	
				if(DealerHand<17)				//Enters if loop if The Dealer has a hand value of less than 17.
				{
					DealerTurn=true;			//Then sets the DealerTurn to true.
				}
				else							//Enters else if DealerHand has a value that isn't less than 17 (therefore, equal to 17 or more).
				{
					DealerTurn=false;			//Then sets the DealerTurn to false.
				}
			

				while(DealerTurn==true)																															//While loop loops while DealerTurn is true.
				{
					cout << "The Dealer has been drawn the " << Deck[DealDeck[CardNumber[N]]].Name << " of " << Deck[DealDeck[CardNumber[N]]].Suit << "\n\n";	//On screen text tells user that the dealer has been drawn a card, complete with name of card and name of card suit.
					CardNumber[N]=Deck[DealDeck[CardNumber[N]]].Value;																							//Sets value of CardNumber to the value of Deck[DealDeck[CardNumber[N]]].
					TempHand=DealerHand+CardNumber[N];																											//Sets TempHand value to the value of DealerHand plus CardNumber[N].
					Sleep(1000);																																//Pauses program for roughly a second.

					if(TempHand>21)															//Enters if statement if TempHand has a value of over 21.
					{
						if(CardNumber[1]==11 || CardNumber[3]==11 || CardNumber[N]==11)		//Enters if statement if CardNumber[1], CardNumber[3] or CardNumber[N] is equal to 11.
						{
							for(int	D=0; D<52; D++)											//For loop loops until D is equal to 52, starting at 0 and going up 1 at a time.
							{
								if(Deck[DealDeck[D]].Value==11)								//Enters if statement if the value of Deck[DealDeck[D]] is equal to 11.
								{
									Deck[DealDeck[D]].Value=1;								//Then changes value of Deck[DealDeck[D]] to 1.
								}
							}

							for(int K=20; K<40; K++)										//For loop loops until K is 20, with K starting at 0 and going until 20. K is used because this allows the for look to go throughthe first 20 values in the CardNumber array and check it.
							{
								if(CardNumber[K]==11)										//Enters if statement if CardNumber[K] has a value of 11.
								{
									CardNumber[K]=1;										//Then sets the value of CardNumber[K] to 1.
								}
							}
						}
					}

					DealerHand=DealerHand+CardNumber[N];									//Adds the previous value of DealerHand to the value of most recent card drawn to create a new value for DealerHand.

					cout << "The Dealer has a hand value of " << DealerHand << "\n\n";		//On screen text tells user the value of The Dealer's Hand.
					Sleep(1000);															//Pauses program for around a second, I think.

					if(DealerHand>21)																										//Enters if statement if DealerHand has a value of over 21.
					{
						cout << "PRESS ENTER TO CONTINUE\n";																				//On screen text tells user to press enter to continue.
						cin.get();																											//Cin.get() requires user needs to press enter. First cin.get() is already taken as the user pressed enter when coming into this function from the menu.
						cin.get();																											//Cin.get() requires user to press enter to continue.
						system("CLS");																										//Clears screen.
						cout << "Current Chips: " << Chips << "		Current Bet: " << Bet << "\n\n";										//On screen text tells user their current Chips and their current Bet.
						DBust=true;																											//Sets DBust to true.
						Winner=true;																										//As The Dealer has gone Bust and and player hasn't gone Bust, winner is then set to true...
						Outcome=true;																										//and the Outcome is set to true.
						DealerTurn=false;																									//The Dealer has got BlackJack, so it sets DealerHand to false, thus ending the loop.
						cout << "Lucky for you, The Dealer went Bust. I guess you win then.\n\n";											//On screen text tells user they've won because The Dealer has gone Bust.
						cout << "You won your 2x original bet of " << Bet <<" back, meaning your available chips is now " << Chips << "\n\n";//On screen texts tells the user that they've won they 2x their original Bet. It then tells the user the amount of the chips they have after winning.
					}

					if(DealerHand==21)		//Enters if statement the Dealer has got more than 21, meaning he has hit a BlackJack.
					{
						DBlackJack=true;	//Sets DBlackJack to true.
						DealerTurn=false;	//The Dealer has got BlackJack, so it sets DealerHand to false, thus ending the loop.
					}
					Sleep(1000);			//Pauses program for around a second.
				}
			}

			while(Outcome==false)																	//Enters while loop and loops while the Outcome of the game is false.
			{
				cout << "PRESS ENTER TO CONTINUE\n";												//Tells user to press enter to continue.
				cin.get();																			//Cin.get() requires user needs to press enter. First cin.get() is already taken as the user pressed enter when coming into this function from the menu.
				cin.get();																			//Cin.get() requires user to press enter to continue.
				system("CLS");																		//Clears screen.
				cout << "Current Chips: " << Chips << "		Current Bet: " << Bet << "\n\n";		//On screen text tells the user their current Chips and their current Bet.
				cout << "Showdown: \n";																//On screen text tells the user that it is now the showdown, which is the final stage of the game and will decide the Outcome.
				cout << "Player has a hand value of " << PlayerHand << "\n\n";						//On screen text tells the user the value of their current hand.
				cout << "The Dealer has a hand value of " << DealerHand << "\n\n";					//On screen text tells the suer the value of The Dealer's current hand.
				Sleep(1000);																		//Pauses program for around a second.

				if(BlackJack==true && DBlackJack==false && Outcome==false)											//Enters if statement if The Player has got a BlackJack, The Dealer hasn't got a BlackJack and the Outcome hasn't aalready been decided.
				{
					Winner=true;																					//Sets winner to true.
					Outcome=true;																					//Sets Outcome to true.
					cout << "Well Done, you won. Lucky. Probably can't do it again though.\n";						//On screen text tells user that they won.
					Chips=Chips+(Bet*2);																			//Previous value of Chips is added to current bet x2 to give a new value for Chips.
					cout << "You won " << (Bet*2) <<", meaning your available chips is now " << Chips << "\n"		//On screen text tells user that they won they original bet x2 and tells the user their new value of their Chips.
						 << "TO MOVE ON, PRESS ENTER.\n\n";															//On screen text tells the user to press enter to continue.
					cin.get();																						//Cin.get() requires user needs to press enter. First cin.get() is already taken as the user pressed enter when coming into this function from the menu.
					cin.get();																						//Cin.get() requires user to press enter to continue.
				}

				if(PlayerHand>DealerHand && Outcome==false)																					//Enters if statement if The Player's hand is higher than The Dealer's hand and an outcome hasn't already been decided. The Player's hand is either 21 or less than 21 at this point
				{
					Winner=true;																											//Sets winner to true.
					Outcome=true;																											//Sets Outcome to true.
					cout << "Well Done, you won. Lucky. Probably can't do it again though.\n";												//On screen text tells user they have won.
					Chips=Chips+(Bet*2);																									//On screen text tells user that they won they original bet x2 and tells the user their new value of their Chips.
					cout << "You wn your original bet of " << (Bet*2) <<" back, meaning your available chips is now " << Chips << "\n"		//On screen text tells the user what they won and what the new value of their Chips is.
						 << "TO MOVE ON, PRESS ENTER.\n\n";																					//On screen text tells user to press enter to continue.
					cin.get();																												//Cin.get() requires user needs to press enter. First cin.get() is already taken as the user pressed enter when coming into this function from the menu.
					cin.get();																												//Cin.get() requires user to press enter to continue.
				}

				if(BlackJack==true && DBlackJack==true && Outcome==false)																			//If The Player and The Dealer both get aa BlackJack, and the outcome hasn't been decided, then this if statement is entered.
				{
					Tie=true;																														//Them both having a BlackJack means they tie, thus Tie is set to true.
					Outcome=true;																													//Sets Outcome to true.
					cout << "You both got a BlackJack. Haha, your BlackJack was in vain. You still didn't win. Anyway have your bet back.";			//On screen text tells user that they're got a BlackJack but The Dealer ha also got a BlackJack so The Player has only tied.
					Chips=Chips+(Bet/2);																											//Previous value of Chips is added to half of their bet to create a new value for thei Chips.
					cout << "You won " << (Bet*0.5) <<", meaning your available chips is now " << Chips << "\n"										//On screen text tells the user what they won and what the new value of their Chips is.
						 << "(Bets of an odd amount will be rounded down when halfed as a result of a tie (You can't have half a chip))\n"			//On screen text tells user they cannot have half a chip so, if need be, then decimals will be rounded down for Chip and Bet amount.
						 << "TO MOVE ON, PRESS ENTER.\n\n";																							//On screen text tells user to press enter to continue.
					cin.get();																														//Cin.get() requires user needs to press enter. First cin.get() is already taken as the user pressed enter when coming into this function from the menu.
					cin.get();																														//Cin.get() requires user to press enter to continue.
				}

				if(PlayerHand==DealerHand && Outcome==false)																					//If statement is entered is the PlayerHand is equal to The Dealer's hand and an Outcome hasn't already been decided.
				{
					Tie=true;																													//This results in a  Tie and therefore, Tie is set to true
					Outcome=true;																												//and outcome is set true
					cout << "Tie. Haha, no win for you.\n";																						//On screen text tells the user that they're tied.
					Chips=Chips+(Bet*0.5);																										//Previous value of Chips is added to half of their bet to create a new value for thei Chips.
					cout << "You won " << (Bet*0.5) <<", meaning your available chips is now " << Chips << "\n"									//On screen text tells the user what they won and what the new value of their Chips is.
						 << "(Bets of an odd amount will be rounded down when halfed as a result of a tie (You can't have half a chip))\n"		//On screen text tells user they cannot have half a chip so, if need be, then decimals will be rounded down for Chip and Bet amount.
						 << "TO MOVE ON, PRESS ENTER.\n\n";																						//On screen text tells user to press enter to continue.
					cin.get();																													//Cin.get() requires user needs to press enter. First cin.get() is already taken as the user pressed enter when coming into this function from the menu.
					cin.get();																													//Cin.get() requires user to press enter to continue.
				}

				if(Winner==false && Tie==false && Outcome==false)			//Enters this if statement if the player hasn't won, hasn't tied and the outcome hasn't already been decided.
				{
					Winner=false;											//Winner is then set to false
					Outcome=true;											//Outcome is then set to true as outcome is that The Player has lost.
					cout << "Haha, You Lost.\n"								//On screen text tells user that they're lost.
						 << "TO MOVE ON, PRESS ENTER.\n\n";					//On screen text tells user to press enter to continue.
					cin.get();												//Cin.get() requires user needs to press enter. First cin.get() is already taken as the user pressed enter when coming into this function from the menu.
					cin.get();												//Cin.get() requires user to press enter to continue.
				}
			}
		}

		cout << "Would you like to....?\n"									//On screen text asks user if he would like to...
			 << "1.Play Again\n"											//Play again...
			 << "Or\n"														//Or...
			 << "2.Leave Game and Go Back to the Menu\n\n";					//Leave game and go back to the main menu.
		
		while(!(cin>>PlayAgain))																							//While loop for PlayAgain. Loops if player enters something that isn't an int.
		{
			cin.clear();																									//Clears istream.
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');													//Ignores, sets limits for stream size aand sets maximun length and creates new line for the text (Below).
			cout << "Invalid input. Must bbe 1 (Play again) or 2 (Leave game and return to the menu). Try again: \n\n";		//On screen text to tell player they entered the wrong input. Tells them correct inputs and tells them to try again. Player then can re-input their choice.
		}
		
		ValidSelection=false;																		//Sets ValidSelection to false.
		while(ValidSelection=false)																	//Enters while loop if ValidSelection has been set to false. Before it enters loop it is set to false and the only way the user can leave this loop, is if they inputted either 1 or 2.
		{
			if(PlayAgain==2)																		//Enters if statement if player has chosen 2, which is leave game and go back to the menu.
			{
				Play=false;																			//Sets Play to false, which will allow the player to exit the main while loop
				ValidSelection=true;																//The Player has selected a correct selection and valid selection is set to true. This allows the user to leave the while loop.
				cout << "I guess you're not man enough to play again. Bye then.\n";					//On screen text tells player bye.
				cout << "PRESS ENTER TO CONTINUE\n\n";												//On screen text tells user to press enter to continue.
				cin.get();																			//Cin.get() requires user needs to press enter. First cin.get() is already taken as the user pressed enter when coming into this function from the menu.
				cin.get();																			//Cin.get() requires user to press enter to continue.
				system("CLS");																		//Clears screen.
			}
			else																					//Else is entered if the user doesn't choose 2.
			{
				if(PlayAgain==1)																	//Enters this if statement if the user has selected 1.
				{
					Play=true;																		//Sets Play to true, to stay in the loop, because they have chosen 1, which is play again.
					ValidSelection=true;															//The Player has selected a correct selection and valid selection is set to true. This allows the user to leave the while loop.

					if(Chips<=0)																	//If they have 0 or less chips then they will not be able to play again.
					{
						Play=false;																	//Sets Play to false because they are not allowed to play again, due to having no Chips left.
						cout << "Available Chips: " << Chips << "\n"								//On screen text tells the user their current available Chips.
							 << "Sorry, you've ran out of chips, you may not play again.\n";		//On screen text telling user that they do not have enough text therefore they cannot play again.
						cout << "PRESS ENTER TO CONTINUE\n\n";										//On screen text tells user to press enter to continue.
						cin.get();																	//Cin.get() requires user needs to press enter. First cin.get() is already taken as the user pressed enter when coming into this function from the menu.
						cin.get();																	//Cin.get() requires user to press enter to continue.
						system("CLS");																//Clear screen.
					}
				}
				else																				//Else is entered if the user hasn't inputted a 1 or 2.
				{
					cout << "Invaild selection. Needs to be 1 (Hit) or 2 (Stand). Try Again.\n";	//On screen text tells the user to try again to input ether 1 or 2.
					ValidSelection=false;															//Sets ValidSelection to false to make the while loop stay looping and therefore make them re-input their choice.
				}
			}
		}
	}
}

void RulesFunction(void)																		//Start of Rules function. Void input and output meaning function needs no input or output. Therefore, function will play through then leave back to where it was entered.
{
	system("CLS");																				//Clears screen.
	cout << "Basic Blackjack Rules\n\n"															//Start of on screen text for the Rules.
		 << "Blackjack is a banking game, where the aim of the game is to achieve a\n"
		 << "hand with a points total nearer to twently one than the banker's hand,\n"
		 << "but without exceeding twenty one. Your hand's points total is determined\n"
		 << "by adding the value of the cards in your hand. The cards 2 through to 10\n"
		 << "have a value based on their number, while the value of the Jack, Queen\n"
		 << "and King is worth 10 points each and the Ace is worth either 1 or 11\n"
		 << "points depending on the player's choice.\n"
		 << "PRESS ENTER FOR NEXT RULE \n\n";
	cin.get();																					//After the end of the paragraph, two Cin.get()'s will require the player to hit enter to move onto the next paragraph. It's two due to the istream already having a an enter in it from the menu selection.
	cin.get();																					//Cin.get() requires user to press enter to continue.
	cout << "The Deal and 'Blackjack'\n\n"
		 << "At the start of a blackjack game, the players and the dealer receive two\n"
		 << "cards each. The players' cards are dealt face up, while the dealer has\n"
		 << "one card face up and the other card face down. The face down card is called\n"
		 << "the hole card. The best possible blackjack hand is an opening deal of an\n"
		 << "Ace with any ten-point value card (Jack, Queen or King). This is called a\n"
		 << "'blackjack', or a natural 21, and the player holding this automatically\n"
		 << "wins unless the dealer also has a blackjack. If a player and the dealer\n"
		 << "each have a blackjack, the result is a push for that player, meaning that\n"
		 << "the player neither wins nor loses and win half his bet. If the \n"
		 << "dealer has a blackjack, all players not holding a blackjack lose.\n"
		 << "PRESS ENTER FOR NEXT RULE\n\n";
	cin.get();																					//After the end of the paragraph, Cin.get()'s will require the player to hit enter to move onto the next paragraph.
	cout << "The Player's Turn\n\n"
		 << "After the cards have been dealt the play can choose to leave his hand as it\n"
		 << "is (this is callled a 'Stand') or he can ask for another card (this is called\n"
		 << "a 'Hit'). This keeps happening until the player decides that he is satified \n"
		 << "with his current hand and decides to 'Stand', the players gets a twenty one,\n"
		 << "or the value of his hand excedes twenty one. When the latter happens, this is\n"
		 << " called 'Bust' and the player automatically loses.\n"
		 << "PRESS ENTER FOR NEXT RULE \n\n";
	cin.get();																					//After the end of the paragraph, two Cin.get()'s will require the player to hit enter to move onto the next paragraph.
	cout << "The Dealer's Turn\n\n"
		 << "When all players have finished their actions, either decided to stand or busted, "
		 << "the dealer turns over his hidden hole card. If the dealer has a natural 21 \n"
		 << "(blackjack) with his two cards, he won't take any more cards. All players lose, "
		 << "except players who also have a blackjack, in which case it is a push - the bet \n"
		 << "is returned to the player. If the dealer doesn't have a natural 21, he hits \n"
		 << "(takes more cards) or stands depending on the value of the hand. Contrary to \n"
		 << "the player, though, the dealer's action is completely dictated by the rules. \n"
		 << "The dealer must hit if the value of the hand is lower than 17, otherwise the \n"
		 << "dealer will stand. \n"
		 << "PRESS ENTER FOR NEXT RULE \n\n";
	cin.get();																					//After the end of the paragraph, two Cin.get()'s will require the player to hit enter to move onto the next paragraph.
	cout << "Showdown\n\n"
		 << "If the dealer goes bust, all players who are left in the game win. Otherwise \n"
		 << "players with higher point totals than the dealer win, while players with lower \n"
		 << "totals than the dealer lose. Players with a blackjack win a bet plus a bonus \n"
		 << "amount, which is normally equal to half their original wager. A blackjack hand \n"
		 << "beats any other hand, also those with a total value of 21 but with more cards. \n"
		 << "PRESS ENTER TO GO BACK TO THE MENU \n\n";
	cin.get();																					//After the end of the paragraph, two Cin.get()'s will require the player to hit enter to move onto the next paragraph.
	system("CLS");																				//Clears screen.
}