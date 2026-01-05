#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    string words[] = {"programming", "computer", "hangman", "developer", "algorithm"};
    srand(time(0));
    string word = words[rand() % 5]; 
    string guessed(word.length(), '_'); 

    int attempts = 6; 
    char guess;
    bool win = false;

    cout << "Welcome to Hangman Game!\n";

    while (attempts > 0 && !win) {
        cout << "\nWord: " << guessed << endl;
        cout << "Attempts left: " << attempts << endl;
        cout << "Enter your guess: ";
        cin >> guess;

        bool correct = false;
        for (int i = 0; i < word.length(); i++) {
            if (word[i] == guess && guessed[i] == '_') {
                guessed[i] = guess;
                correct = true;
            }
        }

        if (!correct) {
            attempts--;
            cout << "Wrong guess!" << endl;
        }

        if (guessed == word) {
            win = true;
        }
    }

    if (win)
        cout << "\nCongratulations! You guessed the word: " << word << endl;
    else
        cout << "\nGame Over! The word was: " << word << endl;

    return 0;
}
