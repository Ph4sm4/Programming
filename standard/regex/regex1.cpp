#include <iostream>
#include <regex>
using namespace std;

void PrintMatches(string str, regex reg){
    smatch matches;
    cout<<boolalpha;
    while(regex_search(str, matches, reg)){
        // cout<<"Is there a match: "<<matches.ready()<<endl;
        // cout<<"Are there no matches: "<<matches.empty()<<endl;
        // cout<<"Number of matches: "<<matches.size()<<endl;
        cout<<matches.str(1)<<endl;
        str = matches.suffix().str();
        cout<<endl;
    }
}

void PrintMatches2(string str, regex reg){
    sregex_iterator currentMatch(str.begin(), str.end(), reg);
    sregex_iterator lastMatch;

    while(currentMatch != lastMatch){
        smatch match = *currentMatch;
        cout<<match.str()<<endl;
        currentMatch++;
    }
    cout<<endl;
}

int main(){

    string str = "The ape was at the apex";
    regex reg ("(ape[^ ]?)");//ape apex
    PrintMatches(str, reg);

    string str2 = "I picked the pickle";
    regex reg2 ("(pick([^ ]+)?)"); //picked pickle
    PrintMatches2(str2, reg2);

    string str3 = "Cat rat mat fat pat";
    regex reg3("([Crmfp]at)"); //Cat rat mat fat pat
    PrintMatches2(str3, reg3);

    regex reg4("([C-Fc-f]at)"); //Cat fat 
    PrintMatches2(str3, reg4);

    regex reg5("[^Cr]at"); //mat fat pat
    PrintMatches2(str3, reg5);

    string str6 = "Cat rat mat fat pat";
    regex reg6("([Cr]at)");
    string replaced = regex_replace(str6, reg6, "zmienione");//zmienione zmienione mat fat pat
    cout<<endl<<replaced<<endl<<endl;


    string str7 = "F.B.I. I.R.S CIA";
    regex reg7("([^ ]\..\..\.)"); //F.B.I. I.R.S.

    PrintMatches2(str7, reg7);


    string str8 = "This is a\n multiline string\n that has many lines";
    regex reg8("\n");
    string noLBStr = regex_replace(str8, reg8, " ");
    cout<<noLBStr<<endl<<endl<<endl;

    //mozna tez zamieniac
    // \b backspace
    // \f form feed
    // \r carriage return
    // \t tab
    // \v vertical tab

    //---------------liczby

    // \d [0-9] jakikolwiek numer
    // \D [^0-9] cokolwiek innego niz numer

    string str9 = "12345";
    regex reg9("\\d");
    PrintMatches2(str9, reg9);

    string str10 = "123 12345 123456 1234567";
    regex reg10("\\d{5,7}"); //czy maja dlugosc od 5 do 7 cyfr
    PrintMatches2(str10, reg10);


    // \w [a-zA-Z0-9]
    // \W [^a-zA-Z0-9]
    string str11 = "412-867-5309";
    regex reg11 ("\\w{3}-\\w{3}-\\w{4}");
    PrintMatches2(str11, reg11);


    // \s [\f\n\r\t\v]
    // \S [^\f\n\r\t\v]

    string str12 = "Toshio Muramatsu";
    regex reg12 ("\\w{2,20}\\s\\w{2,20}");
    PrintMatches2(str12, reg12);

    string str13 = "a as ape bug";
    regex reg13 ("a[a-z]+");
    PrintMatches2(str13, reg13);

    string str14 = "db@aol.com m@.com @apple.com db@.com";
    regex reg14 ("[\\w._%-+]{1,20}\@[\\w.-]{2,20}\.[a-zA-Z]{2,3}");
    PrintMatches2(str14, reg14);

    return 0;
}


