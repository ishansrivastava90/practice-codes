#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

void swap(vector<char>& chars, int i , int j) {
  char tmp = chars[i];
  chars[i] = chars[j];
  chars[j] = tmp;
}

void print_chars(vector<char> & chars) {
  for (unsigned int i = 0; i < chars.size(); ++i) {
    cout << chars[i];
  }
  cout << endl;
}

void sort_chars(vector<char>& chars) {
  unordered_map<char, int> pos;
  for (unsigned int i = 0; i < chars.size(); ++i) {
    pos[chars[i]] = i;
  }
  
  while(1) {
    
    bool sorted = true;
    unsigned int i = 0;
    for (i = 0; i < chars.size(); ++i) {
      if (chars[i] != ('a' + (char)i))
        sorted = false;
    }
    
    if (sorted) 
      break;
    
    if (chars[0] == 'a') {
    
      int tmp =  pos['a'];
      pos['a'] = i;
      pos[chars[i]] = tmp;
      swap(chars, tmp, i);
      print_chars(chars);
    }
    
    while (chars[0] != 'a') {
      swap(chars, pos['a'], pos[pos['a'] + 'a']);
      int tmp =  pos['a'];
      pos['a'] = pos[pos['a'] + 'a'];
      pos[tmp + 'a'] = tmp;
      //print_chars(chars);
    }
  }
}

// Driver method
int main() {
  vector<char> chars;
  for (unsigned int i = 0; i < 26; ++i) {
    char t;
    cin >> t;
    chars.push_back(t);
  }
  
  print_chars(chars);
  sort_chars(chars);
  print_chars(chars);
  cout << "Done" << endl;
  return 0;
}
