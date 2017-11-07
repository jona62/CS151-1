/*
//Name: Elvis Rodriguez
//Creation: 11/06/2017
//Version: 5.R
//Description: Takes three inputs from the user (minimum value, maximum value,
               and amount of tries), then picks a random number from within the
               range of minimum to maximum, and has the user guess; with the
               user getting x amount of tries where x is the user_inputted
               amount of tries. The users attempts are then shown to the user
               regardless of whether they passed or failed.
*/

#ifndef GUESS_H
#define GUESS_H

/*
//Name: GuessNumber()
//Paramter(s): int ( min, max, limit, list(guess_log) )
//Returns: none
//Label   Task                                                              Goto
//01      (start: min,max,limit,guess_log)                                  02
//02      [srand( (unsigned)time(0) )]                                      03
//03      [init randomNum, (rand() % (max - min) + min) --> randomNum]      04
//04      [init guess]                                                      05
//05      [init i, m, n]                                                    06
//06      < [0 --> i], < i < (limit - 1) >, [i++] >                         07,23
//07      < i == 0 >                                                        08,10
//08      /print("Guess my number")/                                        09
//09      /input --> guess/                                                 10
//10      < guess == randomNum >                                            11,19
//11      [guess --> guesslog[i]]                                           12
//12      /print("You got it!\n")/                                          13
//13      /print("Your guess were [")/                                      14
//14      < [0 --> m], < m < i >, [m++] >                                   15,16
//15      /print(guesslog[m], ",")/                                         14
//16      /print(guess)/                                                    17
//18      [break]                                                           31
//17      /print("]\n")/                                                    18
//19      < guess != randomNum >                                            20,23
//20      [guess --> guess_log[i]]                                          21
//21      /print("Incorrect. Guess Again: ")/                               22
//22      /input --> guess/                                                 07
//23      < i == limit - 1 >                                                24,31
//24      /print("You didn't guess my number!\n")/                          25
//25      /print("Your guesses were [")/                                    26
//26      < [n = 0], < n < i >, [n++] >                                     27,28
//27      /print(guess_log[n], ",")/                                        26
//28      /print(guess)/                                                    29
//29      /print{"]\n"}/                                                    30
//30      /print("My number was ", randomNum, "\n")/                        31
//31      (exit)
*/
void GuessNumber(int min, int max, int limit, int guess_log[]) {
  srand( (unsigned)time(0) );

  int randomNum = (rand() % (max - min) + min);
  int guess;
  int i, m, n;

  for (i = 0; i < limit - 1; i++)  {
    if (i == 0) {
      cout << "Guess my number: ";
      cin >> guess;
    }

    if (guess == randomNum) {
      guess_log[i] = guess;
      cout << "You got it!\n";
      cout << "Your guesses were [";
        for (m = 0; m < i; m++) {
          cout << guess_log[m] << ",";
        }
      cout << guess;
      cout << "]\n";
      break;
    } else if (guess != randomNum) {
        guess_log[i] = guess;
        cout << "Incorrect. Guess Again: ";
        cin >> guess;
      }
    }

    if (i == limit - 1) {
      cout << "You didn't guess my number!\n";
      cout << "Your guesses were [";
        for (n = 0; n < i; n++) {
          cout << guess_log[n] << ",";
        }
      cout << guess;
      cout << "]\n";
      cout << "My number was " << randomNum << endl;
    }
}

#endif //GUESS_H
