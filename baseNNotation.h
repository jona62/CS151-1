/*
//Name: Elvis Rodriguez
//Creation: 10/17/2017
//Version: 4.R
//Description: Takes an input of 3 bases from the user, then prints out
               a random in each base n notation where n is each user-
               -inputted base.
*/
#ifndef BASENNOTATION_H
#define BASENNOTATION_H

#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;

//variable initialized in global scope for use in void functions
string output = " ";

/*
//Name: reverseStr()
//Parameter(s): string&
//Return: none
//Label     Task                                      Goto
//01        (start: str)                              02
//02        [str.length --> int n]                    03
//03        [0 --> int i] < i < (n / 2) >             04,05
//04        [swap(str[i], str[n - i - 1]), i++]       03
//05        (exit)
*/
void reverseStr(string &str)
{
    int n = str.length();
    for (int i = 0; i < (n / 2); i++)
       swap(str[i], str[n - i - 1]);
}

/*
//Name: NumberGenerator()
//Parameter(s): int base, value
//Return: none
//Label   Task                                      Goto
//01      (start: base, value)                      02
//02      < value < 1 >                             03,07
//03      [output + "0" --> output]                 04
//04      [reverseStr(output)]                      05
//05      /print(output)/                           06
//06      [" " --> output]                          07
//07      < value > 0 >                             08,11
//08      [base + to_string((value % base)) --> ]   09
//09      [(value / base) --> value]                10
//10      [NumberGenerator(base, value)]            07
//11      (exit)
*/
void NumberGenerator(int base, int value) {
  if (value < 1)  {
    output += "0";
    reverseStr(output);
    cout << output;
    output = " ";
  } else if (value > 0) {
    output += to_string((value % base));
    value = value / base;
    NumberGenerator(base, value);
  }
}

/*
//Name: BaseConvert()
//Parameter(s): int base, value
//Return: none
//Label       Task                              Goto
//01          (start: base, value)              02
//02          < (base >= 2) and (base <=9)      03,04
//03          [NumberGenerator(base, value)]    04
//04          < base > 9 or base < 2 >          05
//05          /print(" ")/                      06
//06          (exit)
*/
void BaseConvert(int base, int value) {
  if ( (base >= 2) && (base <= 9) ) {
    NumberGenerator(base, value);
  } else {
    cout << "";
  }
}

#endif //BASENNOTATION_H
