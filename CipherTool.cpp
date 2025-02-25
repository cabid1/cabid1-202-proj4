#include "CipherTool.h"
// Name: CipherTool Constructor
// Desc - Creates a new CipherTool and sets m_filename based on string passed
// Preconditions - Input file passed and populated with Cipher
// Postconditions - CipherTool created
CipherTool::CipherTool(string filename){
    m_filename = filename;
}
// Name: CipherTool Destructor
// Desc - Calls destructor for all ciphers in m_ciphers
// Preconditions - m_ciphers is populated
// Postconditions - m_ciphers deallocated and vector emptied
CipherTool::~CipherTool(){
    int counter = int(m_ciphers.size())-1;
    while (!m_ciphers.empty()){// goes through vector until it is empty and deletes index
        delete m_ciphers[counter];
        m_ciphers.pop_back();
        counter--;
    }
}
// Name: LoadFile
// Desc - Opens file and reads in each Cipher. Each Cipher dynamically allocated
// and put into m_ciphers (c is Caesar, r is RailFence, and o is Ong)
// Preconditions - Input file passed and populated with Ciphers
// Postconditions - m_ciphers populated with Ciphers
void CipherTool:: LoadFile() {
    string type;
    string isEn;
    string message;
    string shift;
    int shiftInt;
    bool encripted;
    ifstream myFile;
    myFile.open(m_filename);
    if (myFile.is_open()) {
        while (myFile.good()) {
            getline(myFile, type, DELIMITER);//gets type from line
            getline(myFile, isEn, DELIMITER);//gets the 0 or 1
            getline(myFile, message, DELIMITER); // gets message
            getline(myFile, shift, '\n');// gets the shift
            if (type == "c" || type == "r") {//converts to int
                shiftInt = stoi(shift);
            }
            encripted = StringToBoolean(isEn);//converts to bool
            //creates new obj based on type and adds to vector
            if (type == "c") {
                m_ciphers.push_back(new Caesar(message, encripted, shiftInt));
            } else if (type == "r") {
                m_ciphers.push_back(new RailFence(message, encripted, shiftInt));
            } else if (type == "o") {
                m_ciphers.push_back(new Ong(message, encripted));
            }

        }
        myFile.close();
    }
}
// Name: StringToBoolean
// Desc - Helper function that converts a string to a boolean for reading in file
// Preconditions - Passed string of either 0 or 1
// Postconditions - Returns false if 0 else true
bool CipherTool::StringToBoolean(string input){//converts strings 0 and 1 to true or false
    if(input == "0"){
        return false;
    } else{
        return true;
    }
}
// Name: DisplayCiphers
// Desc - Displays each of the ciphers in the m_ciphers
// Preconditions - Input file passed and m_ciphers populated
// Postconditions - Displays ciphers
void CipherTool::DisplayCiphers(){//for each index of vector it displays the ciphers in numbered list
    int count = 1;
    for(int i = 0; i < int(m_ciphers.size()); i++){
        cout << count << ". " <<m_ciphers[i]->GetMessage() <<" ("<<m_ciphers[i]->ToString()<< ")"<< endl;
        count++;
    }
}
// Name: EncryptDecrypt
// Desc - Encrypts or decrypts each of the ciphers in the m_ciphers
// Preconditions - Input file passed and m_ciphers populated
// Postconditions - Either Encrypts or Decrypts each cipher in m_ciphers
void CipherTool::EncryptDecrypt(bool encript){
    for(int i = 0; i < int(m_ciphers.size()); i++){
        if(m_ciphers[i]->GetIsEncrypted() != encript && encript){//checks if already matches and what is wanted outcome
            m_ciphers[i]->Encrypt();
        }else if(m_ciphers[i]->GetIsEncrypted() != encript && !encript){//checks if already matches and what is wanted outcome
                m_ciphers[i]->Decrypt();

            }
    }
}
// Name: Export
// Desc - Exports each of the ciphers in the m_ciphers (so they can be reused)
// Preconditions - Input file passed and m_ciphers populated
// Postconditions - All ciphers exported
void CipherTool::Export(){
    string file;
    cout << "what would you like to call the export file?" << endl;
    cin>> file;//gets name of file from user
    ofstream myFile;
    myFile.open(file);
    for(int i = 0; int(m_ciphers.size()) > i; i++){
        myFile << m_ciphers[i]->FormatOutput() << endl;//puts the lines in the file
    }
    myFile.close();
}
// Name: Menu
// Desc - Displays menu and returns choice
// Preconditions - m_ciphers all populated
// Postconditions - Returns choice
int CipherTool::Menu() {
    int num;
    int count = 0;
    do {
        if (count > 0) {//lets user know they input the wrong thing
            cout << "option out of range" << endl;
            --count;
        }
        cout << "What would you like to do?\n"
                "1. Display All Ciphers\n"
                "2. Encrypt All Ciphers\n"
                "3. Decrypt All Ciphers\n"
                "4. Export All Ciphers\n"
                "5. Quit" << endl;
        ++count;
        cin >> num;
    } while (num < 1 || num > 5);//returns to start
    if (num >= 1 && num <= 5) {
        if (num == 1) {
            return 1;
        } else if (num == 2) {
            return 2;
        } else if (num == 3) {
            return 3;
        } else if (num == 4) {
            return 4;
        }else if(num == 5){
            return 5;
        }
    }
    return 0;
}
// Name: Start
// Desc - Loads input file, allows user to choose what to do
// Preconditions - m_ciphers populated with ciphers
// Postconditions - none
void CipherTool::Start(){
    LoadFile();
    int choice = Menu();//gets user choice
    while(choice != 5){//sends to desired outcome
        if (choice == 1){
            DisplayCiphers();
        }else if(choice == 2){
            EncryptDecrypt(true);
            cout<< m_ciphers.size() << " encrypted"<< endl;
        }else if(choice == 3){
            EncryptDecrypt(false);
            cout<< m_ciphers.size() << " Decrypted"<< endl;
        }else if(choice == 4){
            Export();
            cout<< m_ciphers.size() << " Exported"<< endl;
        }
        choice = Menu();
    }
    cout << "Thanks for using UMBC Encryption"<<endl;
}
