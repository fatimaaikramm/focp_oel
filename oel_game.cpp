#include <iostream>
using namespace std;
// Functions for game 
int shiftDecode(int code, int shift);
int reverseNumber(int number);
void showInstructions();
void playGame(int& score);
int main()
{
    int choice;
    int score = 0;

    // Menu will show until user selects exit 
    do
    {
        cout << "\n===== CODE BREAKER GAME =====" << endl;
        cout << "1. Instructions" << endl;
        cout << "2. Start Game" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        //switch cases for choice
        switch (choice)
        {
        //if user selects 1 instructions will be shown on screen
        case 1:
            showInstructions();
            break;
        //if user selects 2 the game will start
        case 2:
            score = 0;
            playGame(score);
            break;
        //if user selects 3 the game will be exited
        case 3:
            cout << "\nThank you for playing!" << endl;
            break;

        default:
            cout << "\nInvalid choice. Try again." << endl;
        }

    } while (choice != 3);
    return 0;
}


// Function to decode a shift cipher
int shiftDecode(int code, int shift)
{
    int digit;
    int decoded = 0;
    int place = 1;
    while (code > 0)
    {
        //this formula is used to extract the last digit
        digit = code % 10;

        //this will decode the digit
        digit = (digit - shift + 10) % 10;

        //this will add decoded digit to the answer
        decoded = decoded + (digit * place);

        //this will move to the next decimal place
        place = place * 10;

        //this will remove the last digit
        code = code / 10;
    }
    return decoded;
}
// Function to reverse a number
int reverseNumber(int number)
{
    int digit;
    int reversed = 0;

    while (number > 0)
    {
        //extract the last digit
        digit = number % 10;

        //add digit to reversed number
        reversed = reversed * 10 + digit;

        //remove the last digit
        number = number / 10;
    }

    return reversed;
}


//Function to display instructions
void showInstructions()
{
    cout << "\n===== GAME INSTRUCTIONS =====" << endl;
    cout << "1. The game has 5 levels." << endl;
    cout << "2. Each level contains a coded number." << endl;
    cout << "3. Decode the number and enter your answer." << endl;
    cout << "4. You get 2 attempts for each level." << endl;
    cout << "5. You earn 10 points for each completed level." << endl;
    cout << "6. You must pass a level to unlock the next level." << endl;
    cout << "7. If you fail both attempts, the game ends." << endl;
    cout << "8. Maximum score is 50 points." << endl;
}
// Main game function
void playGame(int& score)
{
    int level;
    int attempt;
    int encryptedCode;
    int correctAnswer;
    int shift;
    int playerAnswer;
    int passed;
    // Outer loop controls the 5 levels
    for (level = 1; level <= 5; level++)
    {
        passed = 0;

        cout << "\n==========================" << endl;
        cout << "         LEVEL " << level << endl;
        cout << "==========================" << endl;
        //Select the encrypted code for each level
        string hint;
        switch (level)
        {
        case 1:
            encryptedCode = 5791;
            correctAnswer = 2468;
            shift = 3;
            hint = "Each digit was shifted forward by 3.";
            break;

        case 2:
            encryptedCode = 1385;
            correctAnswer = 5831;
            shift = 0;
            hint = "The original number was reversed.";
            break;

        case 3:
            encryptedCode = 4680;
            correctAnswer = 2468;
            shift = 2;
            hint = "Each digit was shifted forward by 2.";
            break;

        case 4:
            encryptedCode = 7294;
            correctAnswer = 4927;
            shift = 0;
            hint = "The original number was reversed.";
            break;

        case 5:
            encryptedCode = 6802;
            correctAnswer = 2468;
            shift = 4;
            hint = "Each digit was shifted forward by 4.";
            break;
        }

        cout << "Encrypted Code: " << encryptedCode << endl;
        cout << "Hint: " << hint << endl;
        // Inner loop controls the 2 attempts
        for (attempt = 1; attempt <= 2; attempt++)
        {
            cout << "\nAttempt " << attempt << " of 2" << endl;
            cout << "Enter the decoded number: ";
            cin >> playerAnswer;
            if (playerAnswer == correctAnswer)
            {
                cout << "\nCorrect Answer!" << endl;
                score = score + 10;
                passed = 1;
                cout << "You earned 10 points!" << endl;
                cout << "Current Score: " << score << endl;
                break;
            }
            else
            {
                cout << "\nIncorrect Answer!" << endl;

                if (attempt == 1)
                {
                    cout << "Try again!" << endl;
                    continue;
                }
                else
                {
                    cout << "Correct Answer was: "
                        << correctAnswer << endl;
                }
            }
        }
        // Check whether the player passed the level
        if (passed == 0)
        {
            cout << "\nLEVEL FAILED!" << endl;
            cout << "You cannot unlock the next level." << endl;

            break;
        }

        cout << "\nLevel " << level << " completed!" << endl;
    }

    cout << "\n===== GAME OVER =====" << endl;
    cout << "Your Final Score: " << score << " / 50" << endl;

    if (score == 50)
    {
        cout << "Congratulations! You completed all levels!" << endl;
    }
    else
    {
        cout << "Good effort! Keep practicing!" << endl;
    }
}