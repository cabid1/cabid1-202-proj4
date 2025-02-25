#include "RailFence.h"
// Name: RailFence (Default Constructor)
// Desc: Constructor to build an empty RailFence Cipher (Defaults to 3 rails)
// Preconditions - None
// Postconditions - Creates a RailFence cipher
RailFence :: RailFence():Cipher(){
    m_rails = 3;
}
// Name: RailFence (Overloaded Constructor)
// Desc: Constructor to build a populated RailFence Cipher (Defaults to 3 rails)
// Preconditions - Pass it the message, isEncrypted, and number of rails (any integer)
// Postconditions - Creates a RailFence cipher to be encrypted
RailFence ::RailFence(string mess, bool isEncr, int rails):Cipher(mess,isEncr){
    m_rails= rails;
}
// Name: RailFence (Destructor)
// Desc: Destructor - Anything specific part of RailFence to delete?
// Preconditions - ~RailFence exists
// Postconditions - RailFence destroyed
RailFence ::~RailFence(){}
// Name: Encrypt
// Desc: Letters are placed on a fence rail based on the number of rails
//       Letters are read from one rail at a time into a single string
// Preconditions - Message exists
// Postconditions - A single encrypted string is stored
void RailFence ::Encrypt() {
    string newMess = "";
    int count=0;
    int countDown = 0;
    string arr[m_rails][GetMessage().length()];
    bool direction = false;
    string notLetter = "***";
    for(int i = 0; i<m_rails;i++){//fills the array
        for(int x = 0; x<int(GetMessage().length());x++ ){
            arr[i][x] = notLetter;
        }
    }
    while(count<int(GetMessage().length())){
        if(!direction){//adds letters down diagonally
            arr[countDown][count] = GetMessage()[count];
            countDown++;
            if(countDown == m_rails){
                direction = true;
                countDown-=2;
            }
        } else{//adds letters up diagonally
            arr[countDown][count] = GetMessage()[count];
            countDown--;
            if(countDown < 0 ){
                direction = false;
                countDown+=2;
            }
        }
        count++;
    }

    for(int i =0; i<m_rails;i++){//puts everything together
        for(int x = 0;x < int(GetMessage().length()); x++){
            if(arr[i][x] != notLetter){
                newMess += arr[i][x];
            }
        }
    }
    SetMessage(newMess);
    ToggleEncrypted();

}

// Name: Decrypt
// Desc: Single encrypted string is pushed back on the rails and reversed
// Preconditions - Message exists
// Postconditions - The decrypted string is stored
void RailFence ::Decrypt(){
    string newMess = "";
    int count=0;
    int countDown = 0;
    string arr[m_rails][GetMessage().length()];
    bool direction = false;
    string notLetter = "*";
    for(int i = 0; i<m_rails;i++){//fills array
        for( int x = 0; x<int(GetMessage().length());x++ ){
            arr[i][x] = notLetter;
        }
    }
    while(count<int(GetMessage().length())){//marks where a letter should be put
        if(!direction){//adds letters down diagonally
            arr[countDown][count] = "x";
            countDown++;
            if(countDown == m_rails){
                direction = true;
                countDown-=2;
            }
        } else{//adds letters up diagonally
            arr[countDown][count] = "x";
            countDown--;
            if(countDown < 0 ){
                direction = false;
                countDown+=2;
            }
        }
        count++;
    }

    count = 0;
    for(int i = 0; i<m_rails;i++){//puts in the letters
        for(int x = 0; x<int(GetMessage().length());x++){
            if(arr[i][x] == "x"){
                arr[i][x] = GetMessage()[count];
                count++;
            }
        }
    }
    count=0;
    countDown = 0;
    direction = false;
    while(count<int(GetMessage().length())){//puts it all together
        if(!direction){//adds letters down diagonally
            newMess+=arr[countDown][count];
            countDown++;
            if(countDown == m_rails){
                direction = true;
                countDown-=2;
            }
        } else{//adds letters up diagonally
            newMess+=arr[countDown][count];
            countDown--;
            if(countDown < 0 ){
                direction = false;
                countDown+=2;
            }
        }
        count++;
    }
    SetMessage(newMess);
    ToggleEncrypted();




}
// Name: ToString
// Desc - A function that returns the string of the object type
// Preconditions - The object exists
// Postconditions - The subtype is returned (RailFence in this case)
string RailFence ::ToString(){//for display
    return "RailFence";
}
// Name: FormatOutput()
// Desc - A function that returns the formatted output for Output function
// Preconditions - The object exists (use stringstream)
// Postconditions - r, delimiter, isencrypted, delimiter,
//                  message, delimiter, m_rails are returned for output
string RailFence ::FormatOutput(){//for export
    if(GetIsEncrypted()){
        string mess = "r|1|"+GetMessage()+"|"+to_string(m_rails);
        return mess;
    }else{
        string mess = "r|0|"+GetMessage()+"|"+to_string(m_rails);
        return mess;
    }
}
