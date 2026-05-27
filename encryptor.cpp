#include <iostream>
#include <string>
#include <cstdlib>
#include <cctype>
using namespace std;

void clearScreen(){
    #if defined(_WIN32) || defined(_WIN64)
        system("cls");
    
    #elif defined(__linux__) || defined(__apple__)
        system("clear");
    
    #else 
        for (int i = 0; i < 50; i++) cout << '\n';

    #endif
}


//Rot 13 ///////////////////////
string rot13(string inp){
    for (char &c : inp){
        if (c >= 'a' && c <= 'z'){
            c = ((c - 'a' + 13) % 26) + 'a';
        }
        else if(c >= 'A' && c <= 'Z'){
            c = ((c - 'A' + 13) % 26) + 'A';
        }
    }
    return inp;
}
///////////////////////////////

//Caesar Cipher ///////////////
string caesarCipherEncrypt(string inp, int shift){
    for(char &c : inp){
        if (c >= 'a' && c <= 'z'){
            c = ((c - 'a' + shift) % 26) + 'a';
        }
        else if (c >= 'A' && c <= 'Z'){
            c = ((c - 'A' + shift) % 26) + 'A';
        }
    }
    return inp;
}

string caesarCipherDecrypt(string inp, int shift){
    for(char &c : inp){
        if (c >= 'a' && c <= 'z'){
            c = ((c - 'a' - shift + 26) % 26) + 'a';
        }
        else if (c >= 'A' && c <= 'Z'){
            c = ((c - 'A' - shift + 26) % 26) + 'A';
        }
    }
    return inp;
}
//////////////////////////////

//Atbash Cipher //////////////
string atbashCipher(string teks){
    string hasil = "";
    int panjang_teks = teks.length();

    for (int i = 0; i < panjang_teks; i++){
        char c = teks[i];

        if (isupper(c)){
            char update = 'Z' + 'A' - c;
            hasil += update;
        }
        else if (islower(c)){
            char update = 'z' + 'a' -c;
            hasil += update;
        }
        else {
            hasil += c;
        }
    }
    return hasil;
}


int main(){

    clearScreen();

    cout << R"(  █████▒▄▄▄       █     █░ ██▓  ▄▄▄█████▓ ▒█████   ▒█████   ██▓      ██████ 
▓██   ▒▒████▄    ▓█░ █ ░█░▓██▒  ▓  ██▒ ▓▒▒██▒  ██▒▒██▒  ██▒▓██▒    ▒██    ▒ 
▒████ ░▒██  ▀█▄  ▒█░ █ ░█ ▒██░  ▒ ▓██░ ▒░▒██░  ██▒▒██░  ██▒▒██░    ░ ▓██▄   
░▓█▒  ░░██▄▄▄▄██ ░█░ █ ░█ ▒██░  ░ ▓██▓ ░ ▒██   ██░▒██   ██░▒██░      ▒   ██▒
░▒█░    ▓█   ▓██▒░░██▒██▓ ░██████▒▒██▒ ░ ░ ████▓▒░░ ████▓▒░░██████▒▒██████▒▒
 ▒ ░    ▒▒   ▓▒█░░ ▓░▒ ▒  ░ ▒░▓  ░▒ ░░   ░ ▒░▒░▒░ ░ ▒░▒░▒░ ░ ▒░▓  ░▒ ▒▓▒ ▒ ░
 ░       ▒   ▒▒ ░  ▒ ░ ░  ░ ░ ▒  ░  ░      ░ ▒ ▒░   ░ ▒ ▒░ ░ ░ ▒  ░░ ░▒  ░ ░
 ░ ░     ░   ▒     ░   ░    ░ ░   ░      ░ ░ ░ ▒  ░ ░ ░ ▒    ░ ░   ░  ░  ░  
             ░  ░    ░        ░  ░           ░ ░      ░ ░      ░  ░      ░  
                                                                            )" << endl;

    cout << "made by kencana - 2026" << '\n';
    cout << "==================" << '\n';
    cout << "||  1. Encrypt  ||" << '\n';
    cout << "||  2. Decrypt  ||" << '\n';
    cout << "==================" << '\n';

    int input_utama;
    cout << "Masukkan opsi: ";
    cin >> input_utama;

    //encryptor
    if (input_utama == 1){ 
        cout << "==================" << '\n';
        cout << "| List:          |" << '\n';
        cout << "======================" << '\n';
        cout << "|| 1. Rot13         ||" << '\n';
        cout << "|| 2. Caesar Cipher ||" << '\n';
        cout << "|| 3. Atbash Cipher ||" << '\n';
        cout << "======================" << '\n';

        int input_enc;
        cout << "Masukkan opsi: ";
        cin >> input_enc;
        cin.ignore();

        //rot13 encrypt
        if (input_enc == 1){
            cout << "Masukkan teks: ";
            
            string input_rot13_enc;
            getline(cin, input_rot13_enc);

            cout << "==================" << '\n';
            cout << "Hasil : " << rot13(input_rot13_enc) << '\n';
        }
        //caesar cipher encrypt
        else if (input_enc == 2) {
            cout << "Masukkan teks: ";
            
            string input_caesar_enc;
            getline(cin, input_caesar_enc);

            cout << "Masukkan nilai Shift **maks 25** : ";
            int shift;
            cin >> shift;

            cout << "==================" << '\n';
            cout << "Hasil : " << caesarCipherEncrypt(input_caesar_enc, shift) << endl;
        }
        //Atbash cipher encrypt
        else if (input_enc == 3){
            cout << "Masukkan teks: ";
            
            string input_atbash_enc;
            getline(cin, input_atbash_enc);

            cout << "==================" << '\n';
            cout << "Hasil : " << atbashCipher(input_atbash_enc) << endl;
        }
        else {
            cout << "Input Invalid" << '\n';
        }

        //decryptor
    } else if (input_utama == 2){
        cout << "==================" << '\n';
        cout << "| List:          |" << '\n';
        cout << "======================" << '\n';
        cout << "|| 1. Rot13         ||" << '\n';
        cout << "|| 2. Caesar Cipher ||" << '\n';
        cout << "|| 3. Atbash Cipher ||" << '\n';
        cout << "======================" << '\n';

        int input_dec;
        cout << "Masukkan opsi: ";
        cin >> input_dec;
        cin.ignore();

        //rot13 decrypt
        if (input_dec == 1){
            cout << "Masukkan teks: ";
            
            string input_rot13_dec;
            getline(cin, input_rot13_dec);

            cout << "==================" << '\n';
            cout << "Hasil : " << rot13(input_rot13_dec) << '\n';
        }
        //caesar cipher decrypt
        else if (input_dec == 2){

            cout << "======== OPSI ========" << '\n';
            cout << "|| 1. Custom shift  ||" << '\n';
            cout << "|| 2. Bruteforce    ||" << '\n';
            cout << "======================" << '\n';
            cout << "Masukkan opsi : ";
            
            int input_opsi_caesarC;
            cin >> input_opsi_caesarC;
            cin.ignore();
            
            
            if (input_opsi_caesarC == 1){
                cout << "Masukkan teks: ";
                string input_caesar_dec;
                getline(cin, input_caesar_dec);

                cout << "Masukkan Shift **maks 25** : ";
                int shift;
                cin >> shift;
                
                cout << "==================" << '\n';
                cout << "Hasil : " << caesarCipherDecrypt(input_caesar_dec, shift) << '\n';
            }
            else if (input_opsi_caesarC == 2){
                cout << "Masukkan teks: ";
                string input_caesar_dec;
                getline(cin, input_caesar_dec);

                cout << "==================" << '\n';
                for (int i = 1; i < 26; i++){
                    cout << "[+] " << "Shift " << i << " : " << caesarCipherDecrypt(input_caesar_dec, i) << '\n';
                }
            }
            else {
                cout << "Input Invalid" << '\n';
            }
        }
        //Atbash cipher decrypt
        else if (input_dec == 3){
            cout << "Masukkan teks: ";
            
            string input_atbash_enc;
            getline(cin, input_atbash_enc);

            cout << "==================" << '\n';
            cout << "Hasil : " << atbashCipher(input_atbash_enc) << endl;
        }
        else {
            cout << "Input Invalid" << '\n';
        }
    }
    else {
        cout << "Input Invalid" << '\n';
    }
}