#include<bits/stdc++.h>
using namespace std;

string encode(string msg, int shift){

string op=msg;
for (int i=0;i<op.size();i++){
    char c= op[i];
    if(c>='A' && c<='Z'){
        int x= c-'A';
        int nc= (x+shift+26)%26;
        op[i]= ('A'+nc);
    }
    else if(c>='a' && c<='z'){
        int x= c-'a';
        int nc= (x+shift+26)%26;
        op[i]= ('a'+nc);
    }
}

return op; 
}

string decode(string msg, int shift){
    string op=msg;
for (int i=0;i<op.size();i++){
    char c= op[i];
    if(c>='A' && c<='Z'){
        int x= c-'A';
        int nc= (x-shift+26)%26;
        op[i]= ('A'+nc);
    }
    else if(c>='a' && c<='z'){
        int x= c-'a';
        int nc= (x-shift+26)%26;
        op[i]= ('a'+nc);
    }
}

return op; 
}
int main() {
    string msg;
    int shift;
    char choice;

    cout << "Enter your message: ";
    getline(cin, msg);

    cout << "Enter shift value (positive or negative): ";
    cin >> shift;
    shift%=26;
    
    cout << "Do you want to Encode(E) or Decode(D) ? ";
    cin >> choice;

    if (choice == 'E' || choice == 'e') {
        string encoded = encode(msg, shift);
        cout << "Encoded message: " << encoded << endl;
    } else if (choice == 'D' || choice == 'd') {
        string decoded = decode(msg, shift);
        cout << "Decoded message: " << decoded << endl;
    } else {
        cout << "Invalid choice! Please enter E or D." << endl;
    }

    return 0;
}
