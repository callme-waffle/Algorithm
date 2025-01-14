#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(string letter) {
    map<string,char> morse;
    morse[".-"] = 'a';
    morse["-..."] = 'b'; 
    morse["-.-."] = 'c'; 
    morse["-.."] = 'd';     
    morse["."] = 'e'; 
    morse["..-."] = 'f'; 
    morse["--."] = 'g';
    morse["...."] = 'h';
    morse[".."] = 'i'; 
    morse[".---"] = 'j'; 
    morse["-.-"] = 'k';
    morse[".-.."] = 'l';
    morse["--"] = 'm';
    morse["-."] = 'n';
    morse["---"] = 'o';
    morse[".--."] = 'p';
    morse["--.-"] = 'q';
    morse[".-."] = 'r';
    morse["..."] = 's';
    morse["-"] = 't';
    morse["..-"] = 'u';
    morse["...-"] = 'v';
    morse[".--"] = 'w';
    morse["-..-"] = 'x';
    morse["-.--"] = 'y';
    morse["--.."] = 'z';
    
    string answer = "";
    
    int start = 0;
    do {
        int idx = letter.find(' ', start);
        
        string code = letter.substr(start, idx-start);
        start = idx+1;
        
        answer.push_back(morse[code]);
        
        if (idx == string::npos) break;
    } while(true);
    
    return answer;
}