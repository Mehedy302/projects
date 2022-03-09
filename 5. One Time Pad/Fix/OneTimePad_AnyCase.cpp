#include <iostream>
#include <string>
#include <fstream>
using namespace std;

string PlaintextToCipher(string text)
{
    ifstream read_key;
    string key;

    read_key.open("EncryptKey.txt");

    if(read_key.is_open())
    {
        string line;

        getline(read_key, line);

        key = line;

        read_key.close();
    }

    int i,j;

    for(i = 0, j=0; i < text.size() && j < key.size(); i++, j++)
    {

        if ((text [i] >= 'A' && text[i] <= 'Z') || (text[i] >= 'a' && text[i] <= 'z'))
        {

            if (text [i] >= 'A' && text[i] <= 'Z')
            {

                int code = (int) (text[i] + key[j]);

                code = code - (int) 'A';


                while ((code - 26) >= 0)
                {
                    code = code - 26;
                }

                code = code + (int) 'A';

                text[i] = (char) code;
            }


            if (text[i] >= 'a' && text[i] <= 'z')
            {
                int code = (int) (text[i] + key[j]);

                code = code - (int) 'a';


                while ((code - 26) >= 0)
                {
                    code = code - 26;
                }

                code = code + (int) 'a';

                text[i] = (char) code;
            }

        }

    }





    ofstream outdata;
    outdata.open("DecryptKey.txt");
    outdata<<key;
    outdata.close();

    return text;
}


string CipherToPlaintext(string encrypt)
{
    ifstream read_key;
    string key;

    read_key.open("DecryptKey.txt");

    if(read_key.is_open())
    {
        string line;

        getline(read_key, line);

        key = line;

        read_key.close();
    }

    int i,j;

    for(i = 0, j=0; i < encrypt.size() && j < key.size(); i++, j++)
    {
        if ((encrypt [i] >= 'A' && encrypt[i] <= 'Z') || (encrypt[i] >= 'a' && encrypt[i] <= 'z'))
        {

            if (encrypt [i] >= 'A' && encrypt[i] <= 'Z')
            {
                int code = (int) (encrypt[i] - key[j]);

                code = code - (int) 'A';


                while (code < 0)
                {
                    code = code + 26;
                }

                code = code + (int) 'A';

                encrypt[i] = (char) code;
            }


            if (encrypt[i] >= 'a' && encrypt[i] <= 'z')
            {
                int code = (int) (encrypt[i] - key[j]);

                code = code - (int) 'a';


                while (code < 0)
                {
                    code = code + 26;
                }

                code = code + (int) 'a';

                encrypt[i] = (char) code;
            }
        }
    }



    ofstream writeFile;

    writeFile.open("DecryptKey.txt");

    if (writeFile.is_open())
    {
        writeFile << key;

        writeFile.close();
    }
    else
    {
        cout << "can not open the file" << endl;
    }

    return encrypt;
}


int main()
{
	char plainText[10000];
	char encrypedText[10000];

      int ch,i=0;

      FILE *file = fopen("plaintext.txt", "r");
      if (file == NULL)
       {
        fputs("Failed to open the file\n", stderr);
        return -1;
       }
    while ((ch = fgetc(file)) != EOF)
    {
        plainText[i] = ch;
        i  = i +1;
    }

    string text = string(plainText);



	string encrypt = PlaintextToCipher(text);

    ofstream outdata;
    outdata.open("encrypted.txt");
    outdata<<encrypt;
    outdata.close();





     i = 0;
    file = fopen("encrypted.txt", "r");
      if (file == NULL)
       {
        fputs("Failed to open the file\n", stderr);
        return -1;
       }
    while ((ch = fgetc(file)) != EOF)
    {
        encrypedText[i] = ch;
        i  = i +1;
    }

    text = string(encrypedText);






	string decrypt = CipherToPlaintext(text);
    outdata.open("decrypted.txt");
    outdata<<decrypt;
    outdata.close();



	return 0;
}

