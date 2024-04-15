#include "Password.h"
#include <string>

using std::string;

/*
  The function receives a string counts how many times the same character 
  occurs at the beginning of the string, before any other characters (or the
  end of the string). The function is case-sensitive so 'Z' is different than
  'z' and any ASCII characters are allowed.
*/
int Password::count_leading_characters(string phrase){
  int repetition;
  repetition = (phrase.length() > 0) ? 1 : 0; 
  int index = 0;
  while( index < phrase.length()-1 && phrase[index] == phrase[index+1] ){
    repetition++;
    index++;
  }
  return repetition;
}

bool Password::has_mixed_case(string phrase){
  bool upper = false;
  bool lower = false;
  unsigned long int i = 0;
  while(i < phrase.length() && (!upper || !lower)){
    if(isupper(phrase.at(i)))
      upper = true;
    else if(islower(phrase.at(i)))
      lower = true;
    i++;
  }
  return(upper && lower);
}
