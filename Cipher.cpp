#include "Cipher.h"
// Name: Cipher (Default Constructor)
// Desc - Stores a message and if it is encrypted (or not)
// Preconditions - None
// Postconditions - A message is stored in a Cipher object
Cipher::Cipher(){
    m_isEncrypted = false;
    m_message = "message";
}
// Name: Cipher (Overloaded Constructor)
// Desc - Passed a message and if it is encrypted (or not)
// Preconditions - A message is passed to this constructor, and if it is encrypted
// Postconditions - A message is stored in a Cipher object
Cipher::Cipher(string message, bool isEncrypted){
    m_message = message;
    m_isEncrypted = isEncrypted;
}
// Name: ~Cipher (Destructor)
// Desc - Virtual destructor
// Preconditions - A derived class is being deleted
// Postconditions - A base class is deleted
Cipher :: ~Cipher(){}
// Name: GetMessage
// Desc - Returns the message
// Preconditions - The message exists
// Postconditions - A message is returned
string Cipher ::GetMessage(){
    return m_message;
}
// Name: GetIsEncrypted
// Desc - Returns isEncrypted (0 is not encrypted and 1 is encrypted) 0 is false 1 is true
// Preconditions - The cipher exists
// Postconditions - A bool is returned
bool Cipher::  GetIsEncrypted(){
    return m_isEncrypted;
}
// Name: SetMessage
// Desc - Updates a message
// Preconditions - The message exists
// Postconditions - A message is updated
void Cipher ::SetMessage(string message){
    m_message = message;
}
// Name: ToggleEncrypted
// Desc - Turns (true to false) or (false to true)
// Preconditions - The cipher exists
// Postconditions - The m_isEncrypted is toggled
void Cipher ::ToggleEncrypted(){
    if(m_isEncrypted){
        m_isEncrypted = false;
    }else{
        m_isEncrypted = true;
    }
}
// Name: Overloaded << Operator
// Desc - Outputs the message
// Preconditions - The object exists
// Postconditions - The message from the object is returned
ostream & operator<<( ostream &output, Cipher &C){
    output <<  C.m_message << endl;
    return output;
}

