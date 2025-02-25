#include "Ong.h"
// Name: Ong (Default Constructor)
// Desc: Constructor to build an empty Ong Cipher
// Preconditions - None
// Postconditions - Creates a Ong cipher to be encrypted
Ong::Ong():Cipher(){

}
// Name: Ong (Overloaded Constructor)
// Desc: Constructor to build a populated Ong Cipher
// Preconditions - Pass it the message and isEncrypted
// Postconditions - Creates a Ong cipher to be encrypted
Ong::Ong(string mess, bool isEncript):Cipher(mess,isEncript){

}
// Name: Ong (Destructor)
// Desc: Destructor - Anything unique to Ong to delete?
// Preconditions - ~Ong exists
// Postconditions - Ong destroyed
Ong::~Ong(){

}
// Name: IsVowel (Helper function)
// Desc: Returns true if vowel, space, or punctuation
// Preconditions - Message exists
// Postconditions - Returns true or false as above
bool Ong::IsVowel(char letter){
    int letterNum = int(letter);//converts to ascii
    //checks for vowels and other characters
    if(letter == 'a'|| letter == 'e' || letter == 'i'||letter == 'o'||letter == 'u'|| (letterNum >= 32 && letterNum <= 47) || (letterNum >= 58 && letterNum <= 64) || (letterNum >= 91 && letterNum <= 96) || (letterNum >= 123 && letterNum <= 127)||letter == 'A'|| letter == 'E' || letter == 'I'||letter == 'O'||letter == 'U'){
        return true;
    }else{
        return false;
    }
}
// Name: Encrypt
// Desc: If vowel then vowel and dash displayed. dog = dong-o-gong
// If consonant then consonant and ong and dash displayed.
// Preconditions - Message exists
// Postconditions - Encrypts as above
void Ong :: Encrypt() {
    string newMess = "";
    char letter;
    for (int i = 0; i < int(GetMessage().length()); i++) {
        letter = GetMessage()[i];
        if (!IsVowel(letter)) {//adds ong and - to end of nonvowels
            if ((i + 1) < int(GetMessage().length())) {
                if (GetMessage()[i + 1] != ' ') {
                    newMess += letter + ong + '-';
                } else {
                    newMess += letter + ong;
                }
            } else {
                newMess += letter + ong;
            }

        } else if (letter == 'a' || letter == 'e' || letter == 'i' || letter == 'o' || letter == 'u' || letter == 'A' ||
                   letter == 'E' || letter == 'I' || letter == 'O' || letter == 'U') {//adds - to vowels specifically
            if ((i + 1) < int(GetMessage().length())) {
                if (GetMessage()[i + 1] != ' ') {
                    newMess += letter;
                    newMess += '-';
                } else {
                    newMess += letter;
                }
            } else {
                newMess += letter;
            }
        } else {
            newMess += letter;
        }
    }
    SetMessage(newMess);
    ToggleEncrypted();
}
// Name: Decrypt
// Desc: Removes the dashes and "ong" when necessary cong-a-tong = cat
// Double check words like "wrong" so that they work correctly!
// Preconditions - Message exists
// Postconditions - Original message is displayed
void Ong ::Decrypt(){
    string newMess = "";// empty string to add letters to
    string temp = GetMessage();
    for(int i =0; i<int(temp.length()); i++){//iterates through and finds instances where the letter should be added to newMess
        if((i+1)<int(temp.length()) &&(i+2)<int(temp.length())&&(i+3)<int(temp.length())){
            if((temp[i+1]== 'o' && temp[i+2]== 'n'&& temp[i+3]== 'g') || (i != 0 && temp[i-1] == '-') || temp[i] == ' '||(IsVowel(temp[i]) && temp[i+1] == '-')||((IsVowel(temp[i]) && temp[i] != 'o' && temp[i] != '-'))){
                newMess += temp[i];
            }
        }else if(temp[i] == ')'){
            newMess += temp[i];
        }
    }
    SetMessage(newMess);
    ToggleEncrypted();


}
// Name: ToString
// Desc - A function that returns the string of the object type
// Preconditions - The object exists
// Postconditions - The subtype is returned (Ong in this case)
string Ong :: ToString(){//for display
    return "Ong";
}
// Name: FormatOutput()
// Desc - A function that returns the formatted output for Output function
// Preconditions - The object exists (use stringstream)
// Postconditions - o, delimiter, isencrypted, delimiter,
//                  message, delimiter, blank are output
string Ong ::FormatOutput(){//for export
    if(GetIsEncrypted()){
        string mess = "o|1|"+GetMessage()+"|";
        return mess;
    }else{
        string mess = "o|0|"+GetMessage()+"|";
        return mess;
    }
}
