#include "Caesar.h"
// Name: Caesar (Default Constructor)
// Desc: Constructor to build an empty Caesar Cipher (Defaults to shift 3)
// Preconditions - None
// Postconditions - Creates a Caesar cipher to be encrypted
Caesar::Caesar():Cipher(){//creates caesar obj(default) and sends info to parent(default)
    m_shift=3;
}
// Name: Caesar (Overloaded Constructor)
// Desc: Constructor to build a populated Caesar Cipher (Defaults to shift 3)
// Preconditions - Pass it the message, isEncrypted, and shift (any integer)
// Postconditions - Creates a Caesar cipher to be encrypted
Caesar::Caesar(string message, bool isEnc, int shift): Cipher(message,isEnc){//creates caesar obj and sends info to parent
    m_shift = shift;
}
// Name: Caesar (Destructor)
// Desc: Destructor - Anything specific to Caesar to delete?
// Preconditions - ~Caesar exists
// Postconditions - Caesar destroyed
Caesar::~Caesar(){}
// Name: Encrypt
// Desc: Shifts characters right based on shift (lower stay lower, upper stay upper)
// Preconditions - Message exists
// Postconditions - Shifts each character "right".
void Caesar::Encrypt() {
    char letter;
    int letterNum;
    string newMessage = "";
    for (int i = 0; i < int(GetMessage().length()); i++) {
        letterNum = int(GetMessage()[i]);
        if ((letterNum >= 65 && letterNum <= 90) ||(letterNum >= 97 && letterNum <= 122)) {//checks if it is a letter
            if (letterNum >= 65 && letterNum <= 90) {//uppercase letter
                letterNum += m_shift;//adds shift
                if (letterNum > 90){//adjusts if it goes over
                    letterNum = 67 + (letterNum - 90)-1;
                }
                letter = char(letterNum);
                newMessage += letter;
            }else if (letterNum >= 97 && letterNum <= 122) {//lowercase letter
                letterNum += m_shift;//adds shift
                if (letterNum > 122) {//adjusts if it goes over
                    letterNum = 97 + (letterNum - 122)-1;
                }
                letter = char(letterNum);//converts back to char

                newMessage += letter;
            }
        } else{//isnt a letter
            newMessage += GetMessage()[i];
        }
    }
    SetMessage(newMessage);
    ToggleEncrypted();
}
// Name: Decrypt
// Desc: Shifts characters left based on shift (lower stay lower, upper stay upper)
// Preconditions - Message exists
// Postconditions - Shifts each character "left".
void Caesar::Decrypt(){
    char letter;
    int letterNum;
    string newMessage = "";
    for (int i = 0; i < int(GetMessage().length()); i++) {
        letterNum = int(GetMessage()[i]);
        if ((letterNum >= 65 && letterNum <= 90) ||(letterNum >= 97 && letterNum <= 122)) {//letter check
            if (letterNum >= 65 && letterNum <= 90) {//uppercase
                letterNum -= m_shift;//takes away the shift
                if (letterNum < 65){//adjusts if it goes under
                    letterNum = 90 - (65 -letterNum )+1;
                }
                letter = char(letterNum);
                newMessage += letter;
            }else if (letterNum >= 97 && letterNum <= 122) {//lowercase
                letterNum -= m_shift;//takes away the shift
                if (letterNum < 97) {//adjusts if it goes under
                    letterNum = 122 - (97 - letterNum )+1;
                }
                letter = char(letterNum);

                newMessage += letter;
            }
        } else{
            newMessage += GetMessage()[i];
        }

    }
    SetMessage(newMessage);
    ToggleEncrypted();
}
// Name: ToString
// Desc - A function that returns the string of the object type
// Preconditions - The object exists
// Postconditions - The subtype is returned (Caesar in this case)
string Caesar::ToString(){//for display
    return "Caesar";
}
// Name: FormatOutput()
// Desc - A function that returns the formatted output for Output function
// Preconditions - The object exists (use stringstream)
// Postconditions - c, delimiter, isencrypted, delimiter,
//                  message, delimiter, m_shift are returned for output
string Caesar::FormatOutput(){//for export
    if(GetIsEncrypted()){
        string mess = "c|1|"+GetMessage()+"|"+to_string(m_shift);
        return mess;
    }else{
        string mess = "c|0|"+GetMessage()+"|"+to_string(m_shift);
        return mess;
    }
}
