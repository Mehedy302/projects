#include<bits/stdc++.h>
using namespace std;

string encrypt(string msg, int width){
    string cipher = "";

    int trailing_space = width - msg.size()%width;

    for(int i = 0; i < trailing_space; i++){
        msg += ' ';
    }

    for(int i = 0; i < width; i ++){
        for(int j = i; j < msg.size(); j += width){
            cipher += msg[j];

        }
    }

    return cipher;
}

string decrypt(string cipher, int width){

    string msg = "";

    int rows = ceil(cipher.size()/(double)width);

    for(int i = 0; i < rows; i ++){
        for(int j = i; j < cipher.size(); j += rows){
            msg += cipher[j];
        }
    }

    int cnt = 0;
    for(int i = msg.size()-1; i >= 0; i--){
        if(msg[i]==' ')cnt ++;
        else break;
    }
    msg = msg.substr(0, msg.size()-cnt);

    return msg;
}


int main(){

    int width;
    string plainText;

    string decrypted;

    string cipher;

    ifstream input;
    ofstream output;
    ofstream output2;

    input.open("in.txt");
    output.open("out.txt");
    output2.open("decrypted.txt");
     cout<<"Enter Width : ";
    cin>>width;
    getline(input, plainText);


    cipher = encrypt(plainText, width);
    decrypted = decrypt(cipher, width);

    output2<<"Decrypted message : "<<decrypted<<endl;
    output<<"Cipher message : "<<cipher<<endl;

    input.close();
    output.close();

    return 0;
}
