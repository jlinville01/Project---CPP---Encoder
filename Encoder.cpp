#include <iostream>
#include <string>
#include <cmath>
#include <vector>
using namespace std;

class Encoder {
public:

    /*
     * Create an encoder object with the given encoding keys
     */
    Encoder(const string& encryption_key, const string& decryption_key);

    /*
     * Compute the encrypted text from the given plain text and return the encrypted text
     */
    string encrypt(string plainText);

    /*
     * Compute the decrypted text from the given encrypted text and return the plain text
     */
    string decrypt(string encryptedText);

private:
    string enc_key;
    string dec_key;
    /*
     *  Find the encoding for the given char in the given mapping and return it
     */
    char codeChar(char c, const string& mapping);
};


int main()
{
    Encoder encoder("kngcadsxbvfhjtiumylzqropwe", "eidfzkclomasqbwxuvgnpjyhrt");
    string choice, input;
    do {
        cout<<"Enter 'e' to encrypt, 'd' to decrypt, 'q' to quit: ";
        getline(cin, choice);
        if (choice == "e") {
            cout<<"Enter the text to encrypt: ";
            getline(cin, input);
            cout<<encoder.encrypt(input)<<endl;
        } else if (choice == "d") {
            cout<<"Enter the text to decrypt: ";
            getline(cin, input);
            cout<<encoder.decrypt(input)<<endl;
        }
    } while (choice != "q");
    cout<<"Good bye!"<<endl;

    return 0;
}

Encoder::Encoder (const string& encryption_key, const string& decryption_key) {
    enc_key = encryption_key;
    dec_key = decryption_key;
}

string Encoder::encrypt(string plainText) {
    for (unsigned i = 0; i < plainText.size(); i++) {
        plainText[i] = this->codeChar(plainText[i], this->enc_key);
    }
    return plainText;
}

string Encoder::decrypt(string encryptedText) {
    for (unsigned i = 0; i < encryptedText.size(); i++) {
        encryptedText[i] = this->codeChar(encryptedText[i], this->dec_key);
    }
    return encryptedText;
}

char Encoder::codeChar(char c, const string& mapping) {
    int position = c - 'a';
    return mapping[position];
}