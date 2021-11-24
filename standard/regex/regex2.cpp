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

int main(){
    //[] match what is in the brackets
    //[^] match anything not in the brackets
    //. match any 1 character or space
    //+ match 1 or more of what proceeds
    // \n newline
    // \d any 1 number
    // \D anything but not a number
    // \w same as [a-zA-Z0-9_]
    // \W same as [^a-zA-Z0-9_]
    // \s same as [\f\n\r\t\v]
    // \S same as [^\f\n\r\t\v]
    // {5} match of what proceeds the curly brackets
    // {5,7} matches values that are between 5 and 7 in length
    // () return only what is between ()
    //? match 0 or 1
    //* match 0 or more
    

    string str1 = "cat cats";
    regex reg1 ("([cat]+s?)");
    Printmatches(str1, reg1);

    string str2 = "doctor doctors doctor's";
    regex reg2 ("([doctor]+['s]*)");
    Printmatches(str2, reg2);

    string str3 = "Just some words\nand some more words\r\nand more\n";
    regex reg3 ("[\r\n]?\n");
    string line = regex_replace(str3, reg3, " ");
    cout<<line<<endl<<endl;
    //Printmatches(str3, reg3);

    string str4 = "<name>Life On Mars</name> <name>Freaks and Geeks</name>";
    regex reg4 ("<name>(.*?)</name>");
    Printmatches(str4, reg4);
    //greedy matching
    //<name>(.*)</name>
    //output: Life On Mars</name> <name>Freaks and Geeks
    //its the biggest amount that can possibly be grabbed
    //-----
    //lazy matching
    //<name>(.*?)</name>
    //output: Life On Mars Freaks and Geeks
    //its the smallest amount that can possibly be grabbed

    // \b matches the start or the end of a word
    string str5 = "ape at the apex";
    regex reg5 ("(\\bape\\b)");
    //samo ("(ape)") wyswietli ape tyle razy w ilu slowach znajduje sie
    //ten ciag znakow: "ape" jak damy \bape\b to zwroci nam ile
    //razy ten ciag znakow wystepuje samoistnie
    Printmatches(str5, reg5);


    string str6 = "Match everything up to @";
    regex reg6 ("(^.*[^@])");
    Printmatches(str6, reg6);

    string str7 = "@ get this string";
    regex reg7 ("([^@\\s].*$)");
    Printmatches(str7, reg7);

    string str8 = "206-709-3100 202-459-1111 212-832-2000";
    regex reg8 (".{3}-(.{8})");
    Printmatches(str8, reg8);

    string str9 = "My number is 904-285-3700";
    regex reg9 ("(.{3})-(.*)-(.*)");
    smatch matches;
    if(regex_search(str9, matches, reg9)){
        for(int i = 1; i < matches.size(); i++){
            cout<<matches[i]<<endl;
        }
    }
    
    return 0;
}