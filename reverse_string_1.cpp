#include <iostream>
#include <string>
#include <algorithm>

int stringCharCount(const std::string &string, char ch);

void stringConcatenate(std::string &destination, const std::string &source);

int main()
{
    std::string inputSentence;
    std::cout << "Enter a sentence:";
    //std::cin >> inputSentence;
    std::getline(std::cin,inputSentence);
    // std::cout << "original sentence: "<<inputSentence<<std::endl;

    // std::reverse(inputSentence.begin(),inputSentence.end());
    // std::cout << "reversed sentence: "<<inputSentence<<std::endl;

    // int count= stringCharCount(inputSentence,'a');
    // std::cout<<"no of 'a in string: "<<count<<std::endl;

    stringConcatenate(inputSentence,"welcome to COEP");
    
    return 0;

}
//reverse a segment of string


// 1. Calculate string length (excluding '\0')
int stringLength(const char* str) {
    int length=0;
    while(str[length]!='\0'){
        length++;

    }
    return length;
}

// 2. Copy source string into destination array
void stringCopy(char* destination, const char* source) {
    int i=0;
    while(source[i]!='\0'){
        destination[i]=source[i];
        i++;
    }
    destination[i]='\0'; // Null-terminate the destination string
}

//3. Compares two strings lexicographically.
int stringCompare(const char* str1, const char* str2) {
    int i=0;
    while(str1[i]!='\0' && str2[i]!='\0'){
        if(str1[i]!=str2[i]){
            return str1[i]-str2[i]; // Return the difference of the first non-matching characters
        }
        i++;
    }
    // If one string is a prefix of the other, return the difference in lengths
    return str1[i]-str2[i];
}
//concatenate the source string to the destination string
void stringConcatenate(std::string &destination, const std::string &source) {
   source += destination ;
}

// no of character in the string
int stringCharCount(const std::string &string, char ch) {
    int count=0;
    int i=0;
    while(i<string.length()){
        if(string[i]==ch){
            count++;
        }
        i++;
    }
    return count;
}