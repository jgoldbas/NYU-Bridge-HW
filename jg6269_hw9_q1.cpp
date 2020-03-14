//
// Created by Julianna Goldbas on 3/7/20.
//  HW 9 question 1
/*Question 1:
Write a program that will read in a line of text and output the
number of words in the line and the number of occurrences of each letter.
Define a word to be any string of letters that is delimited at each end by either
whitespace, a period, a comma, or the beginning or end of the line \n.
You can assume that the input consists entirely of letters, whitespace, commas, and periods.
When outputting the number of letters that occur in a line, be sure to count upper and
lowercase versions of a letter as the same letter. Output the letters in
alphabetical order and list only those letters that do occur in the input line.
Your program should interact with the user exactly as it shows in the following example:
Please enter a line of text:
I say Hi.
3 words
1 a
1 h
2 i
1 s
1 y */

#include <iostream>
#include <string>
using namespace std;

string countWords(string user_input);
//This takes user input and counts how many words based on delimiters.

string keepOnlyLetters(string user_input);
//This function takes a string of words containing chars and removes the
//characters.

void countLetters(string line_without_delimiters);
//This function should take the string without delimiters as an arg.
// and return the number of times a letter appears.

int main () {
    string line_of_text;
    string only_letters, out_words;

    cout << "Please enter your line of text: " << endl;
    getline(cin, line_of_text);

    //counts how many words
    countWords(line_of_text);

    //counts how many occurrences of a ltr
    countLetters(line_of_text);

    //removes delimiters
    //out_words = keepOnlyLetters(only_letters);

    return 0;
}

string countWords(string line_of_text) {
    int words_count = 0;
    string words;
    for (int i = 0; i <= line_of_text.length(); i++) {
        // if the char is a letter it will enter this loop
        if ((line_of_text[i] >= 'A' || line_of_text[i] <= 'Z') &&
            (line_of_text[i] >= 'a' || line_of_text[i] <= 'z') &&
            (line_of_text[i + 1] == '.' || line_of_text[i + 1] == ',' || line_of_text[i + 1] == ' '))  {

            words_count++;
        }
        else {
            words += line_of_text[i];
        }
    }
    cout << words_count << "\twords" << endl;



    return words;
}

//string keepOnlyLetters(string line_of_text) {
//    string line_of_text;
//    for (int i = 0; i <= line_of_text.length() - 1; i += 1) {
//        if (line_of_text[i] < 'A' || line_of_text[i] > 'z') {
//            words += line_of_text[i];
//        }
//        else {
//            words += line_of_text[i];
//        }
//    }
//    cout << "outWords: " << words << endl;
//    return words;
//}

void countLetters(string words) {
    const int ALPHABET_SIZE = 26;
    int lettersArr[ALPHABET_SIZE] = {0};
    int letter_index;

    for (int i = 0; i < words.length(); i++) {
        //cout << "char at each i " << words[i] << endl; //this line gives a char
        letter_index = words[i] - 'a';//ascii value of the character based on ascii value of 'a'
        if (letter_index < 0)
            letter_index = letter_index + ('a' - 'A');
        //then add to that letter's count
        lettersArr[letter_index]++;
    }

    for (int i = 0; i < ALPHABET_SIZE; i++)
        if (lettersArr[i] != 0)
            // add 97 because the letter associated with the index in the alphabet array
            //corresponds to that index + 97 on ASCII table
            cout << lettersArr[i] << "\t" << (char)(i + 97) << endl;
}
