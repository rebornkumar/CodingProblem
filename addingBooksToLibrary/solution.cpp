#include<bits/stdc++.h>
using namespace std;


string nextName(string str) {
    
    int M = str.size();
    int carry = 1;
    for(int i = M-1; i>=0; i--) {
        
        int val = (int)(str[i] - 'a') + carry;
        int rem = val%27;
        carry /= 27;
        str[i] = (char)(val + 'a');
    }
    if(carry != 0) {
        str = "a"+str;
    }
    return str;
}
int main() {
    
    
    //code
    int N;
    cin>>N;
    
    vector<string>books(N,"");
     unordered_set<string>hash;
    for(int i=0;i<N;i++) {
        cin>>books[i];
        if(books[i] != "?") {
            hash.insert(books[i]);
        }
    }
    
    string curr = "a";
    for(int i =0;i<N;i++) {
        if(books[i] == "?") {
            while(hash.find(curr) != hash.end()) {
                curr = nextName(curr);
            }
            books[i] = curr;
            curr = nextName(curr);
        }
    }
    
    for(int i =0; i<N;i++) {
        cout<<books[i]<<endl;
    }
    
    //code
    return 0;
}