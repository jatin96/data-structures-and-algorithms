// Jatin Narula (jatin.jt.narula)
//
#include <bits/stdc++.h>
using namespace std;
#define ms(a ,value) memset(a ,value,sizeof(a))
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define finderror1(x) cout<<#x<<" --> "<<x<<"\n";
#define finderror2(x,y) cout<<#x<<" --> "<<x<<"\t"<<#y<<" --> "<<y<<"\n";
#define finderror3(x,y,z) cout<<#x<<" --> "<<x<<"\t"<<#y<<" --> "<<y<<"\t"<<#z<<" --> "<<z<<"\n";
const double PI=3.1415926535897;
const int N=26;
typedef long long int ll;
string str;
//the trie struct
struct trie {
    char ch;
    trie * next[26];
    bool end_of_word;
};
//create a new node for trie
trie * create_new_node(char ch) {
    trie * new_node = (trie *) malloc(sizeof(struct trie));
    new_node -> ch = ch;
    new_node -> end_of_word = false;
    for(int i = 0; i < 26; i++) new_node -> next[i] = NULL;
    return new_node;
}
//function to insert the word into the trie
trie * insert_word_trie(struct trie * node, int pos) {
    if(pos == str.length()) {
        return node;
    }
    if(node -> next[str[pos] - 'a'] == NULL) node -> next[str[pos] - 'a'] = create_new_node(str[pos]);

    if(pos == str.length() - 1) node -> end_of_word = true;
    node -> next[str[pos] - 'a'] = insert_word_trie(node -> next[str[pos] - 'a'], pos + 1);
    return node;
}

trie * delete_word_trie(struct trie * node, int pos) {
    if(pos == str.length() - 1) {
        node -> end_of_word = false;
        int cnt = 0;
        for(int i = 0; i < 26; i++) {
            if(node -> next[i] == NULL) cnt++;
        }
        if(cnt == 26) {
            free(node);
            node = NULL;
        }
        return node;
    }
    for(int i = 0; i < 26; i++) {
        if(node -> next[i] != NULL && node -> next[i] -> ch == str[pos]) {
            node -> next[i] = delete_word_trie(node -> next[i], pos + 1);
            int cnt = 0;
            for(int i = 0; i < 26; i++) {
                if(node -> next[i] == NULL) cnt++;
            }
            if(cnt == 26) {
                free(node);
                node = NULL;
            }
            break;
        }
    }
    return node;
}

bool search_word_trie(struct trie * node, int pos) {
    if(node == NULL) return false;
    if(pos == str.length() - 1){
        return node -> end_of_word;
    }
    search_word_trie(node -> next[str[pos] - 'a'], pos + 1);
}
int main() {
    trie * root = (trie *)malloc(sizeof(struct trie));
    root -> ch = '#';
    root -> end_of_word = false;
    for(int i = 0; i < 26; i++) {
        root -> next[i] = NULL;
    }

    int n; //number of words which we need to insert into the trie
    cin >> n;
    cout << "enter the words you need to insert into the trie\n";
    for(int i = 0; i < n; i++) {
        cin >> str;
        root = insert_word_trie(root, 0);
    }
    str = "the";
    root = delete_word_trie(root, 0);
    cout << "enter the words you need to search (exit to quit" << "\n";
    while(true) {
        cin >> str;
        if(str == "exit") break;
        bool res = search_word_trie(root, 0);
        if(res) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
