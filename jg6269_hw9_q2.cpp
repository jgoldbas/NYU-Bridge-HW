//
// Created by Julianna Goldbas on 3/7/20.
// HW 9 Queston 2 anagram q
/*
Two strings are anagrams if the letters can be rearranged to form each other. For example,
“Eleven plus two” is an anagram of “Twelve plus one”. Each string contains one ‘v’, three ‘e’s,
two ‘l’s, etc.
Write a program that determines if two strings are anagrams. The program should not be case
sensitive and should disregard any punctuation or spaces.
Notes:
1. Think how to break down your implementation to functions.
2. Pay attention to the running time of your program. If each input string contains �
characters, an efficient implementation would run in a linear time (that is Θ(�)). */

#include <iostream>
#include <string>
using namespace std;

void countLetters(string string);
//This function should take the string without delimiters as an arg.
// and return the number of times a letter appears.

bool areAnagrams(string one, string two);
//This function takes two strings as input, compares
// them to see if they are anagrams, if so returns True.

int main () {
    string first_string, second_string;
    first_string = "dirty room"; //need to use getline (cin, string_one)
    second_string = "dormitory"; //need to use getline (cin, string_two)
    bool anagram_status = false;
    //countLetters(first_string);
    //countLetters(second_string);
    cout << "String length of string 1: " << first_string.length() << endl;
    cout << "String length of string 2: " << second_string.length() << endl;

    }

    if (areAnagrams(first_string, second_string)) {
       cout << "The strings are anagrams." << endl;
    }
    else
       cout << "The strings are not anagrams." << endl;

    return 0;
}
void countLetters(string string) { //adapted from q1
    const int ALPHABET_SIZE = 26;
    int lettersArr1[ALPHABET_SIZE] = {0};
   // int lettersArr2[ALPHABET_SIZE] = {0};
    int letter_index1;

    for (int j = 0; j < string.length(); j++) {
        //'A'< x<'Z'=65<x<90 && 97<x<122
        if ((string[j] >= 'A' && string[j] <= 'Z') || (string[j] >= 'a' && string[j] <= 'z'))
        letter_index1 = string[j] - 'a';
            letter_index1 = letter_index1 + ('a' - 'A');
        lettersArr1[letter_index1]++;
    }
    for (int i = 0; i < ALPHABET_SIZE; i++)
        if (lettersArr1[i] != 0)
            // add 97 because the letter associated with the index in the alphabet array
            //corresponds to that index + 97 on ASCII table
            cout << lettersArr1[i] << "\t" << (char)(i + 97) << endl;
}

/*bool areAnagrams(string first_string, string second_string) {
for (char i = 0; i < first_string.length(); i++) {
        if (first_string[i] != second_string[i])
            cout << anagram_status << endl;
    for (int i = 0; i < (first_string+ second_string).length() ; i++) {
        if (first_string[i] != second_string[i])
            return anagram_status;

        return true;
    }

}*/