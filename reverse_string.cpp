#include <iostream>
#include <string>
#include <algorithm>
// Helper function to reverse a specific segment of the string
void reverseSegment(std::string& str, int start, int end) 
{
    while (start < end) {
    std::swap(str[start], str[end]);
    start++;
    end--;
}
}
// Function to reverse the order of words in a sentence
std::string reverseWords(std::string sentence) {
// Step 1: Reverse the entire sentence string
reverseSegment(sentence, 0, sentence.length() - 1);
int start = 0;
// Step 2: Traverse the string and reverse each individual word back
 for (int end = 0; end <= sentence.length(); ++end) {
// If we hit a space or the end of the string, we have found a word boundary
 if (end == sentence.length() || sentence[end] == ' ') {
 reverseSegment(sentence, start, end - 1);
start = end + 1; // Move the start pointer to the beginning of the next word
 }
}
return sentence;
}

int main() 
{
 std::string inputSentence = "OMKAR GIRI";
 std::cout << "Original Sentence: " << inputSentence << std::endl;
std::string result = reverseWords(inputSentence);
std::cout << "Reversed Words : " << result << std::endl;
return 0;
}