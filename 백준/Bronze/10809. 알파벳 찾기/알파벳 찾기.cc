#include <iostream>
using namespace std;

int main() {
    string s;
    cin >> s;
    
    int idxs[26];
    fill_n( idxs, 26, 200 );
    
    for ( int i = 0; i < s.length(); i++ ) {
        if ( idxs[ int( s[i] ) - 97 ] > i )
            idxs[ int( s[i] ) - 97 ] = i;
    }
    
    for ( int j = 0; j < 26; j++ ) {
        cout << ( idxs[j] == 200 ? -1 : idxs[j] ) << " ";
    }
    
    return 0;
}