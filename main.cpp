#include <iostream>
#include <string>
#include <vector>
#include <ctime> // For time()
#include <cstdlib> // For srand() and rand()

using namespace std;

int main() {
    // Seed the random number generator
    srand(time(0));
    
    vector<string> words = {"binary", "cipher", "coding", "domain", 
"router", "server", "widget", "browse", "buffer", "byte", "cache", 
"click", "cloud", "cookie", "cursor", "cyber", "debug", "decrypt", 
"delete", "digital", "driver", "encode", "encrypt", "ethernet",
"execute", "export", "firewall", "folder", "format", "glitch",
"hacker", "host", "import", "install", "kernel", "keylog", 
"laptop", "login", "malware", "memory", "mobile", "module", 
"monitor", "network", "online", "output", "password",
"plugin", "policy", "process", "program", "protocol", "proxy", 
"query", "queue", "reboot", "recycle", "refresh", "runtime", 
"script", "search", "secure", "software", "string", "syntax", 
"system", "tablet", "thread", "token", "toolbar", "traffic", 
"trojan", "upload", "user", "virus", "volume", "web", "website", 
"zoom", "gadget", "graphic", "hash", "icon", "input", "interface", 
"internet", "logic", "pixel", "query", "snippet", "utility", "virtual", "wizard"};
    char playAgain;
    
    do {
        string guess;
        int numGuesses = 0, index = 0;
        
        // Ensure there are words available to choose from
        if(words.empty()) {
            cout << "No more words available!";
            break;
        }
        
        // Pick a random word from the list
        int randomIndex = rand() % words.size();
        string answer = words[randomIndex];
        
        // Remove the chosen word from the list
        words.erase(words.begin() + randomIndex);
        
        while (numGuesses < 6 && guess != answer) {
            cout << '\n';
            cout << "Enter your guess: "; // outputs your guesses 
            cin >> guess;
            cout << '\n';
            numGuesses = numGuesses + 1;
            index = 0;
            
            // Determine the minimum length between the guess and the answer.
            size_t minLength = min(guess.length(), answer.length());
            
            // Loop over the characters up to the minimum length.
            while (index < minLength) {
                char letter = guess[index];
                if (letter == answer[index]) {
                    cout << guess[index] << " Green" << endl;
                } else {
                    bool found = false;
                    for(char c: answer){
                        if(letter == c){
                            found = true;
                            break;
                        }
                    }
                    if(found){
                        cout << letter << " Yellow" << endl;
                    } else {
                        cout << letter << " Red" << endl;
                    }
                }
                index = index + 1;
            }
        }
            if (guess == answer) {
        cout << '\n';
        cout << "You win" << endl;
    } else {
        cout << '\n';
        cout << "You loose" << endl;
        cout << "The correct word was: " << answer << endl; // Display the correct word
    }
        // Ask the user if they want to play again
        cout << '\n';
        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;
        
    } while(playAgain == 'y' || playAgain == 'Y');
    cout << '\n';
    cout << "Thanks for playing!";
}






