#include <iostream>
#include <string>
#include <sstream>

int main() {
    std::string input_text;
    
    // Input the string with varying spaces
    std::cout << "Enter a string with varying spaces: ";
    std::getline(std::cin, input_text);

    // Create a stringstream to normalize the spacing
    std::istringstream iss(input_text);
    std::string normalized_text;
    std::string word;

    // Read and append words with single spaces to the normalized_text
    while (iss >> word) {
        normalized_text += word + " ";
    }

    // Remove the trailing space
    if (!normalized_text.empty()) {
        normalized_text.pop_back();
    }

    // Output the normalized string
    std::cout << "Normalized string with single spaces: " << normalized_text << std::endl;

    return 0;
}

