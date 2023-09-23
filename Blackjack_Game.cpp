// Brandon Tillman
// Praeses Blackjack Assesment
// 9/22/2023

#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>

using namespace std;

void line()
{
    cout << "********************************************" << '\n';
}

int main()
{
    //Scoreboard
    int winScore = 0;
    int lossScore = 0;

    int choice; // choice to play the game
    int retry; // To loop the program
    choice = 0; // reset the choice
    do 
    {
        retry = 1;
        retry--;
        do 
        {
            // Basic menu
            line();
            cout << "Welcome to the Menu! PLease press 1 to begin" << '\n';
            cout << "Press 2 to quit the game. " << '\n';
            cin >> choice;
        } while (choice < 1 || choice > 2); // Loop until correct input

        if (choice == 1)
        // Start of the BlackJack program
        {
            int cardNumArray[11] = {1, 2, 3, 4, 5,
                                    6, 7, 8, 9, 10, 11};

            srand(time(0));
            int play;
            int ace;

            cout << "Welcome to BlackJack!" << '\n' << '\n';
            cout << "Wins: " << winScore << "  " << "Losses: " << lossScore << '\n';
            cout << "Press 1 to begin ";
            cin >> play;

            // All of the variables for the cards that will be generated

            // Computer cards        
            int computerCard1 = (cardNumArray[rand() % 11]);
            int computerCard2 = (cardNumArray[rand() % 11]);
            int computerCard3 = (cardNumArray[rand() % 11]);
            int computerCard4 = (cardNumArray[rand() % 11]);
            int computerCard5 = (cardNumArray[rand() % 11]);
            int computerCard6 = (cardNumArray[rand() % 11]);
            //Rounds that will be used/ Sum of cards obtained
            int comRound1 = computerCard1 + computerCard2;
            int comRound2 = comRound1 + computerCard3;
            int comRound3 = comRound2 + computerCard4;
            int comRound4 = comRound3 + computerCard5;
            int comRound5 = comRound4 + computerCard6;
            // End of Computer variables

            // Players cards
            int firstRandomCard = cardNumArray[rand() % 11];
            int secondRandomCard = cardNumArray[rand() % 11];
            int thirdRandomCard = cardNumArray[rand() % 11];
            int fourthRandomCard = cardNumArray[rand() % 11];
            int fifthRandomCard = cardNumArray[rand() % 11];
            int sixthRandomCard = cardNumArray[rand() % 11];

            //Rounds that will be used/ Sum of cards obtained
            int round1, round2, round3, round4, round5;
            // End of Player variables

// ROUND 1
            line();
            cout << "Round 1." << '\n' << '\n';
            cout << "The computer has dealt itself a card. " << '\n';

            cout << "It deals you a card. You have: " << firstRandomCard << '\n' << '\n';
            if(firstRandomCard == 1 || firstRandomCard == 11)
            {
                cout << "You have an ace! Choose to be a 1. '1' or 2. '11' " << '\n';
                cin >> ace;
                if (ace == 1)
                {
                    cout << "The ace is now 1 " << '\n';
                    firstRandomCard = 1;
                    round1 = firstRandomCard;
                }
                if (ace == 2)
                {
                    cout << "The ace is now 11 " << '\n';
                    firstRandomCard = 11;
                    round1 = firstRandomCard;
                }
            }
            cout << "The computer draws another card. The computer gets " << computerCard2 << '\n'; // computer second card
            cout << "The computer draws you another card. You have: " << secondRandomCard << '\n' << '\n'; // Second card
            round1 =  firstRandomCard + secondRandomCard; 
            if(secondRandomCard == 1 || secondRandomCard == 11) // Could make this a function. Would I have to move the random cards to global variables???
            {
                cout << "You have an ace! Choose to be a 1. '1' or 2. '11' " << '\n';
                cin >> ace;
                if (ace == 1)
                {
                    secondRandomCard = 1;
                    round1 = firstRandomCard + secondRandomCard;

                }
                if (ace == 2)
                {
                    secondRandomCard = 11;
                    round1 = firstRandomCard + secondRandomCard;
                }
            }
            cout << "Your total: " << round1 << '\n' << '\n';

            if (comRound1 > 21)
            {
                cout << "Computer bust with: " << comRound1 << " First. You win!" << '\n';
                winScore++;
                cout << "Press 1 to play again." << '\n';
                cin >> retry;
            }
            else if (round1 > 21 && comRound1 < 21)
            {
                cout << "You lose. You have over 21." << '\n';
                lossScore++;
                cout << "Press 1 to play again." << '\n';
                cin >> retry;
            }
            if (round1 == 21 && comRound1 < 21)
            {
                cout << "Congratulations! " << '\n';
                winScore++;
                cout << "Press 1 to play again." << '\n';
                cin >> retry;
            }
            if (round1 < 21 && comRound1 < 21)
            {
                cout << "Do you want to 1. Hit or 2.Stay ";
                cin >> play;
            }
// Round 1 Stay
            if (play == 2) 
            {
                cout << "You have stayed with " << round1 << '\n';
                cout << "The computer has " << comRound1 << '\n';

                if (round1 > comRound1 && round1 <= 21)
                {
                    cout << "You win with " << round1 << " being closer to 21!" << '\n';
                    winScore++;
                    cout << "Press 1 to play again." << '\n';
                    cin >> retry;
                }
                else if(round1 < comRound1 && comRound1 <= 21)
                { 
                    cout << "Sorry you lose." << '\n';
                    lossScore++;
                    cout << "Press 1 to play again." << '\n';
                    cin >> retry;
                }
            }
// ROUND 2
            if (play == 1 && retry != 1)
            {
                line();
                cout << "Round 2." << '\n' << '\n';
                cout << "The computer gets " << computerCard3 <<'\n';
                cout << "You get: " << thirdRandomCard << '\n' << '\n';
                round2 =  round1 + thirdRandomCard; 

                if(thirdRandomCard == 1 || thirdRandomCard == 11)
                {
                    cout << "You have an ace! Choose to be a 1. '1' or 2. '11' " << '\n';
                    cin >> ace;
                    if (ace == 1)
                    {
                        thirdRandomCard = 1;
                        round2 =  round1 + thirdRandomCard; 

                    }
                    if (ace == 2)
                    {
                        thirdRandomCard = 11;
                        round2 =  round1 + thirdRandomCard; 
                    }
                }
                cout << "Your total: " << round2 << '\n' << '\n';

                if (comRound2 > 21)
                {
                    cout << "Computer bust with: " << comRound2 << " First. You win!" << '\n';
                    winScore++;
                    cout << "Press 1 to play again." << '\n';
                    cin >> retry;
                }
                else if (round2 > 21 && comRound2 < 21)
                {
                    cout << "You bust." << '\n';
                    lossScore++;
                    cout << "Press 1 to play again." << '\n';
                    cin >> retry;
                }
                if (round2 == 21 && comRound2 < 21)
                {
                    cout << "Congratulations!!" << '\n';
                    winScore++;
                    cout << "Press 1 to play again." << '\n';
                    cin >> retry;
                }
                if (comRound2 < 21 && round2 < 21)
                {
                    cout << "Do you want to 1.Hit or 2.Stay ";
                    cin >> play;
                }
// Round 2 stay
                if (play == 2) 
                {
                    cout << "You have stayed with " << round2 << '\n';
                    cout << "The computer has " << comRound2 << '\n';

                    if (round2 > comRound2 && round2 <= 21)
                    {
                        cout << "You win with " << round2 << " being closer to 21!" << '\n';
                        winScore++;
                        cout << "Press 1 to play again." << '\n';
                        cin >> retry;
                    }
                    else if(round2 < comRound2 && comRound2 <= 21)
                    { 
                        cout << "Sorry you lose." << '\n';
                        lossScore++;
                        cout << "Press 1 to play again." << '\n';
                        cin >> retry;
                    }
                }
            }
// ROUND 3
            if (play == 1 && retry != 1)
            {
                line();
                cout << "Round 3." << '\n' << '\n';
                cout << "The computer gets " << computerCard4 << '\n';// comRound3                    
                cout << "You get: " << fourthRandomCard << '\n' << '\n';
                round3 = round2 + fourthRandomCard;

                if(fourthRandomCard == 1 || fourthRandomCard == 11)
                {
                    cout << "You have an ace! Choose to be a 1. '1' or 2. '11' " << '\n';
                    cin >> ace;
                    if (ace == 1)
                    {
                        fourthRandomCard = 1;
                        round3 =  round2 + fourthRandomCard; 
                    }
                    if (ace == 2)
                    {
                        fourthRandomCard = 11;
                        round3 =  round2 + fourthRandomCard; 
                    }
                }
                cout << "Your total: " << round3 << '\n' << '\n';

                if (comRound3 > 21)
                {
                    cout << "Computer bust with: " << comRound3 << " First. You win!" << '\n';
                    winScore++;
                    cout << "Press 1 to play again." << '\n';
                    cin >> retry;
                }
                else if (round3 > 21 && comRound3 < 21)
                {
                    cout << "You bust." << '\n';
                    lossScore++;
                    cout << "Press 1 to play again." << '\n';
                    cin >> retry;
                }
                if (round3 == 21 && comRound3 < 21)
                {
                    cout << "Congratulations!!" << '\n';
                    winScore++;
                    cout << "Press 1 to play again." << '\n';
                    cin >> retry;
                }
                if (comRound3 < 21 && round3 < 21)
                {
                    cout << "Do you want to 1.Hit or 2.Stay ";
                    cin >> play;
                }
// Round 3 Stay
                if (play == 2)
                {
                    cout << "You have stayed with: " << round3 << '\n';
                    cout << "The computer has: " << comRound3 << '\n';  

                    if (round3 > comRound3 && round3 <= 21)
                    {
                        cout << "You win with " << round3 << " being closer to 21!" << '\n';
                        winScore++;
                        cout << "Press 1 to play again." << '\n';
                        cin >> retry;
                    }
                    else if(round3 < comRound3 && comRound3 <= 21)
                    { 
                        cout << "Sorry you lose." << '\n';
                        lossScore++;
                        cout << "Press 1 to play again." << '\n';
                        cin >> retry;
                    }
                } 
            }
// ROUND 4
            if (play == 1 && retry != 1)
            {
                line();
                cout << "Round 4." << '\n' << '\n';
                cout << "Computer gets: " << computerCard5 << '\n';
                cout << "You get: " << fifthRandomCard << '\n' << '\n';
                round4 = round3 + fifthRandomCard;

                if(fifthRandomCard == 1 || fifthRandomCard == 11)
                {
                    cout << "You have an ace! Choose to be a 1. '1' or 2. '11' " << '\n';
                    cin >> ace;
                    if (ace == 1)
                    {
                        fifthRandomCard = 1;
                    }
                    if (ace == 2)
                    {
                        fifthRandomCard = 11;
                    }
                }
                cout << "Your total: " << round4 << '\n' << '\n';

                if (comRound4 > 21)
                {
                    cout << "Computer bust with: " << comRound4 << " First. You win!" << '\n';
                    winScore++;
                    cout << "Press 1 to play again." << '\n';
                    cin >> retry;
                }
                else if (round4 > 21 && comRound4 < 21)
                {
                    cout << "You bust." << '\n';
                    lossScore++;
                    cout << "Press 1 to play again." << '\n';
                    cin >> retry;
                }
                if (round4 == 21 && comRound4 < 21)
                {
                    cout << "Congratulations!!" << '\n';
                    winScore++;
                    cout << "Press 1 to play again." << '\n';
                    cin >> retry;
                }
                if (comRound4 < 21 && round4 < 21)
                {
                    cout << "Do you want to 1.Hit or 2.Stay ";
                    cin >> play;
                }
// Round 4 Stay                                
                if (play == 2) 
                {
                    cout << "You have stayed with " << round4 << '\n';
                    cout << "The computer has " << comRound4 << '\n';

                    if (round4 > comRound4 && round4 <= 21)
                    {
                        cout << "You win with " << round4 << " being closer to 21!" << '\n';
                        winScore++;
                        cout << "Press 1 to play again." << '\n';
                        cin >> retry;
                    }
                    else if(round4 < comRound4 && comRound4 <= 21)
                    { 
                        cout << "Sorry you lose." << '\n';
                        lossScore++;
                        cout << "Press 1 to play again." << '\n';
                        cin >> retry;
                    }
                } 
            }
// ROUND 5
            if (play == 1 && retry != 1)
            {
                line();
                cout << "Round 5." << '\n' << '\n';
                cout << "Computer gets: " << computerCard6 << '\n';
                cout << "You get: " << sixthRandomCard << '\n' << '\n';
                round5 = round4 + sixthRandomCard;

                if(sixthRandomCard == 1 || sixthRandomCard == 11)
                {
                    cout << "You have an ace! Choose to be a 1. '1' or 2. '11' " << '\n';
                    cin >> ace;
                    if (ace == 1)
                    {
                        sixthRandomCard = 1;
                    }
                    if (ace == 2)
                    {
                        sixthRandomCard = 11;
                    }
                }
                cout << "Your total: " << round5 << '\n' << '\n';

                if (comRound5 > 21)
                {
                    cout << "Computer bust with: " << comRound5 << " First. You win!" << '\n';
                    winScore++;
                    cout << "Press 1 to play again." << '\n';
                    cin >> retry;
                }
                else if (round5 > 21 && comRound5 < 21)
                {
                    cout << "You bust." << '\n';
                    lossScore++;
                    cout << "Press 1 to play again." << '\n';
                    cin >> retry;
                }
                if (round5 == 21 && comRound5 < 21)
                {
                    cout << "Congratulations!!" << '\n';
                    winScore++;
                    cout << "Press 1 to play again." << '\n';
                    cin >> retry;
                }
                if (comRound5 < 21 && round5 < 21)
                {
                    cout << "Do you want to 1.Hit or 2.Stay ";
                    cin >> play;
                }
// Round 5 Stay
                if (play == 2) 
                {
                    cout << "You have stayed with " << round5 << '\n';
                    cout << "The computer has " << comRound5 << '\n';

                    if (round5 > comRound5 && round5 <= 21)
                    {
                        cout << "You win with " << round5 << " being closer to 21!" << '\n';
                        winScore++;
                        cout << "Press 1 to play again." << '\n';
                        cin >> retry;
                    }
                    else if(round5 < comRound5 && comRound5 <= 21)
                    { 
                        cout << "Sorry you lose." << '\n';
                        lossScore++;
                        cout << "Press 1 to play again." << '\n';
                        cin >> retry;
                    }
                }
            }
        }
        if (retry == 2) // to quit at any time
        {
            return 0;
        }   
    } while (retry == 1); // To loop the program 
} // You got this!!!
