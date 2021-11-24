#include <iostream>
#include <regex>
using namespace std;

void Printmatches(string str, regex reg){

    //used when you're searching a string
    smatch match;

    //determines if there is a match and match
    //results are returned in matches
    while(regex_search(str, match, reg)){

        //get the first match
        cout<<match.str(1)<<endl;

        //eliminate the previous match and create
        //a new string to search
        str = match.suffix().str();
    }
    cout<<endl<<endl;
}
// \b granica slowa
int main(){
    
    string str1 = "The cat cat fell out of window";
    regex reg1 ("(\\b\\w+)\\s+\\1");
    Printmatches(str1, reg1);

    string str2 = "<a href = '#'><b>The link</b></a>";
    regex reg2 ("<b>(.*?)</b>");
    string result;
    regex_replace(back_inserter(result), str2.begin(), str2.end(), reg2, "$1");
    cout<<result<<endl<<endl;

    string str3 = "412-555-1212";
    regex reg3 ("([\\d]{3})-([\\d]{3}-[\\d]{4})");
    string result3;
    regex_replace(back_inserter(result3), str3.begin(), str3.end(), reg3, "($1)$2");
    cout<<result3<<endl<<endl;


    string str4 = "https://www.youtube.com http://www.google.com";
    regex reg4 ("(https?://([\\w.]+))");
    string res4;
    regex_replace(back_inserter(res4), str4.begin(), str4.end(), reg4, 
    "<a href='$1'>$2</a>\n");
    cout<<res4<<endl<<endl;


    string str5 = " one two three four ";
    regex reg5("(\\w+(?=\\b))");
    Printmatches(str5, reg5);

    string str6 = "1. Dog 2. Cat 3. Turtle";
    regex reg6 ("\\d\\.\\s(Dog|Cat)");
    Printmatches(str6, reg6);


    string str7 = "12345 12345-1234 1234 123456-333";
    regex reg7 ("(\\d{5}\-\\d{4}|\\d{5}\\s)");
    Printmatches(str7, reg7);


    string str8 = "14125551212 4125551212 (412)5551212 412 555 1212 412-555-1212 1-412-555-1212";
    //regex reg8 ("(\\d{11}|\\d{10}|\\(\\d{3}\\)\\d{6}|\\d{3}\\s\\d{3}\\s\\d{4}|\\d{3}\\-\\d{3}\\-\\d{4}|\\d\\-\\d{3}\\-\\d{3}\\-\\d{4})");
    regex reg8 ("(?=\\b)((1?)(-| ?)(\\()?(\\d{3})(\\)|-| |\\)-|\\) )?(\\d{3})(-| )?(\\d{4}|\\d{4}))");
    Printmatches(str8, reg8);


    return 0;
}