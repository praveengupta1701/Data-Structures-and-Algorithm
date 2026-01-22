#include <iostream>
#include <string>

class Chatbot {
private:
    static Chatbot* instance; // static pointer to the singleton instance
    Chatbot() {} // private constructor to prevent instantiation
public:
    static Chatbot* getInstance() {
        if (instance == nullptr) { // check if instance already exists
            instance = new Chatbot(); // create new instance if it does not exist
        }
        return instance; // return instance
    }
    void startChat() {
        std::cout << "Hello, I am your chatbot. How can I help you today?" << std::endl;
        std::string input;
        while (true) { // loop until exit command is entered
            std::getline(std::cin, input); // read user input
            if (input == "exit") { // check if user wants to exit
                break; // break out of loop
            }
            std::cout << "You said: " << input << std::endl; // echo user input
        }
        std::cout << "Goodbye!" << std::endl;
    }
};

Chatbot* Chatbot::instance = nullptr; // initialize static pointer to null

int main() {
    Chatbot* bot = Chatbot::getInstance(); // get instance of chatbot
    bot->startChat(); // start chat with chatbot
    return 0;
}