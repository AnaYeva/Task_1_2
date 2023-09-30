#include "Cipher.h"
#include <algorithm>
#include <random>
const int Fibonacci[30]={1, 2, 3, 5, 8, 13, 21, 34, 55, 89,
                   144, 233, 377, 610, 987, 1597, 2584, 4181, 6765, 10946,
                   17711,28657,46368,75025,121393,196418,317811,514229,832040,1346269
};

void Cipher::setMessage() {
    string str;
    getline(cin, str);
    string s;// variable to store token obtained from the original string
    stringstream ss(str);
    while (getline(ss, s, ' ')) {
        message.push_back(s);
        if (message.size()>30)throw std::invalid_argument("too many words");
    }
    cout<<"";
}
bool Cipher::validNumber(const int value){
    bool check =false;
    for(int i=0;i<message.size();i++){
        if (value==Fibonacci[i]){
            check= true;
            break;
        }
    }
    return check;
}
void Cipher::setKey() {
    int value;
    int i=0;
    while (i++ < message.size() && cin >> value)
    {
        if (!validNumber(value))throw std::invalid_argument("invalid number");
        key.push_back(value);
    }
}

void Cipher::printMessage() {
    for (const string& i : message) {
        cout << i<<" ";
    }
    cout<<endl;
}
void Cipher::printKey() {
    for (int i : key) {
        cout << i << " ";
    }
    cout<<endl;
}

void Cipher::decodeUserInput() {
    cout<<"Enter encoded message:";
    this->setMessage();
    cout<<"Enter the key:";
    this->setKey();
}
void Cipher::encodeUserInput() {
    cout<<"Enter your message:";
    this->setMessage();
}

void Cipher::Decode() {
    // simple bubble sort
    for (int step = 0; step < message.size(); ++step) {
        for (int i = 0; i < message.size() - step; ++i) {
            if (key[i] > key[i + 1]) {
                swap(key[i], key[i + 1]);
                swap(message[i],message[i+1]);
            }
        }
    }
    for (int i =0;i<key.size()-1;i++) {
        if (key[i] == key[i + 1])throw std::invalid_argument("same number in the sequence");
    }
}
void Cipher::Encode(){
    copy(&Fibonacci[0], &Fibonacci[message.size()], back_inserter(key));
    auto seed = unsigned ( std::time(0) );
    std::srand ( seed );
    std::random_shuffle ( message.begin(), message.end() );
    std::srand ( seed );
    std::random_shuffle ( key.begin(), key.end() );
}
void Cipher::decodeOutput() {
    cout<<"Decoded message:";
    this->printMessage();
}
void Cipher::encodeOutput() {
    cout<<"Encoded message:";
    this->printMessage();
    cout<<"Your key:";
    this->printKey();
    cout<<endl;
}



