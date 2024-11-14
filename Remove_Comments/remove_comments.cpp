#include <iostream>
#include <fstream>
#include <string>

// Note - You must create a file named input.cpp and then run the code.
// The code will remove all the comments from the input.cpp file and give output in the output.cpp file 


void removeComments(std::string &code) {
    bool singleLineComment = false;
    bool multiLineComment = false;
    std::string result;

    for (size_t i = 0; i < code.length(); ++i) {
        if (singleLineComment && code[i] == '\n') {
            singleLineComment = false;
            result += code[i];
        } 
        else if (multiLineComment && code[i] == '*' && code[i + 1] == '/') {
            multiLineComment = false;
            ++i;
        } 
        else if (!singleLineComment && !multiLineComment) {
            if (code[i] == '/' && code[i + 1] == '/') {
                singleLineComment = true;
                ++i;
            } 
            else if (code[i] == '/' && code[i + 1] == '*') {
                multiLineComment = true;
                ++i;
            } 
            else {
                result += code[i];
            }
        }
    }

    code = result;
}

int main() {
    std::ifstream inputFile("input.cpp");  // Input file with code
    std::ofstream outputFile("output.cpp"); // Output file without comments

    if (!inputFile.is_open() || !outputFile.is_open()) {
        std::cerr << "Error opening files!" << std::endl;
        return 1;
    }

    std::string code((std::istreambuf_iterator<char>(inputFile)),
                     std::istreambuf_iterator<char>());

    removeComments(code);

    outputFile << code;
    std::cout << "Comments removed. Check 'output.cpp' for the result." << std::endl;

    inputFile.close();
    outputFile.close();
    return 0;
}
