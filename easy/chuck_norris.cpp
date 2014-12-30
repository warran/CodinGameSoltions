#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string char_to_bits(char c)
{
    string result = "";
    for(int i = 0;i < 7;++i) {
        result = ((c % 2 == 0) ? "0" : "1") + result;
        c >>= 1;
    }
    return result;
}

string to_unary(string bits)
{
    string head = "", rest = "";
    string result = "";
    for(int i = 0;i < bits.size();++i) {
        if(bits[i] == '0' && head == "0" || bits[i] == '1' && head == "00") {
            result += head + " " + rest + " ";
            head = rest = "";
        }
        
        if(bits[i] == '0')
            head = "00";
        else
            head = "0";
        
        rest += "0";
    }
    result += head + " " + rest;
    
    return result;
}

string encode(string message)
{
    string result = "";
    
    for(int i = 0;i < message.size();++i) {
        result += char_to_bits(message[i]);
    }
    
    return to_unary(result);
}

int main()
{
    string MESSAGE;
    getline(cin, MESSAGE);

    cout << encode(MESSAGE) << endl;
}
