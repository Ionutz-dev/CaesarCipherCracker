#define _CRT_SECURE_NO_WARNINGS // Disables warnings related to secure functions
#include <iostream>
#include <fstream>
#include <climits> 

// Reads the letter distribution from a file and stores it in an array
void readLettersDistribution(float lettersDistribution[26]) {
    std::ifstream file("distribution.txt");
    int index = 0;
    float distribution;
    while (file >> distribution && index < 26) {
        lettersDistribution[index++] = distribution;
    }
}

// Computes the normalized frequency of letters in the given text
void computeLettersNormalizedFrequency(const char text[10000], int lettersNormalizedFrequency[26], int& totalLettersCount) {
    int index = 0;
    while (text[index] != '\0') {
        if (text[index] >= 'A' && text[index] <= 'Z')
            lettersNormalizedFrequency[text[index] - 'A']++, totalLettersCount++;
        else if (text[index] >= 'a' && text[index] <= 'z')
            lettersNormalizedFrequency[text[index] - 'a']++, totalLettersCount++;
        index++;
    }
}

// Calculates the chi-square distance between the expected and observed frequencies
float chiSquareDistance(const int totalLettersCount, const float lettersDistribution[26], const int lettersNormalizedFrequency[26]) {
    float sum = 0;
    for (int index = 0; index < 26; index++) {
        float expectedFrequency = totalLettersCount * lettersDistribution[index] * 0.01;
        sum += ((lettersNormalizedFrequency[index] - expectedFrequency) * (lettersNormalizedFrequency[index] - expectedFrequency)) / expectedFrequency;
    }
    return sum;
}

// Shifts each letter in the text to the right by one position in the alphabet
void shiftTextRight(char text[10000]) {
    int index = 0;
    while (text[index] != '\0') {
        char ch = text[index];
        if ((ch >= 'a' && ch < 'z') || (ch >= 'A' && ch < 'Z')) ch++;
        else if (ch == 'z') ch = 'a';
        else if (ch == 'Z') ch = 'A';
        text[index++] = ch;
    }
}

// Copies one string into another
void copyString(char* dest, const char* src) {
    int index = 0;
    while (src[index] != '\0') {
        dest[index] = src[index];
        index++;
    }
    dest[index] = '\0';
}

// Attempts to decipher the text using Caesar cipher and stores the result in solution
void breakCaesarCipher(char text[10000], float lettersDistributionEnglish[26], char solution[10000]) {
    float minChiSquareDiff = INT_MAX;
    for (int shift = 0; shift < 26; shift++) {
        int lettersNormalizedFrequency[26] = { 0 }, totalLettersCount = 0;
        computeLettersNormalizedFrequency(text, lettersNormalizedFrequency, totalLettersCount);

        float chiSquareDiff = chiSquareDistance(totalLettersCount, lettersDistributionEnglish, lettersNormalizedFrequency);
        if (chiSquareDiff < minChiSquareDiff) {
            minChiSquareDiff = chiSquareDiff;
            copyString(solution, text);
        }

        shiftTextRight(text);
    }
}

// Display an introductory message about the tool
void displayIntro() {
    std::cout << "Welcome to CaesarCracker, the ultimate decryption tool designed to unravel the mysteries of the ancient Caesar cipher!\n\n";
    std::cout << "Whether you're a cryptography enthusiast, a student delving into the world of classical encryption, ";
    std::cout << "or simply someone with a penchant for puzzles, CaesarCracker offers an intuitive and powerful platform ";
    std::cout << "to decode messages hidden through Caesar's time-honored shifting technique.\n\n";
}

// Display a closing message about the tool
void displayOutro() {
    std::cout << "Thanks for playing CaesarCracker! See you soon.";
}

// Main user interface function for the tool
void ui() {
    displayIntro();

    char option = '\0';
    while (option != 'N' && option != 'n') {
        char text[10000] = "", solution[10000] = "";
        float lettersDistributionEnglish[26] = { 0 };

        std::cout << "----------------------------------------------------------------------------------------------------\n";
        std::cout << "Enter the text to decipher: ";
        std::cin.getline(text, 10000); // Read input text

        readLettersDistribution(lettersDistributionEnglish); // Read letter distribution from file

        breakCaesarCipher(text, lettersDistributionEnglish, solution); // Decipher the text

        std::cout << "\nThe deciphered text is: ";
        std::cout << solution << "\n\n";

        std::cout << "Would you like to decipher another text? Enter N for no and any other character for yes.\n";
        std::cin >> option;

        // Discard the newline character left in the input buffer
        std::cin.get();
    }

    displayOutro();
}

int main() {
    ui();
    return 0;
}