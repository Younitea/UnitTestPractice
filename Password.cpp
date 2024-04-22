#include "Password.h"
#include <string>
#include <cctype>

using std::string;

/*
  The function receives a string counts how many times the same character 
  occurs at the beginning of the string, before any other characters (or the
  end of the string). The function is case-sensitive so 'Z' is different than
  'z' and any ASCII characters are allowed.
*/

void Password::set(string input){
  if(input.size() < 8 || input.size() > 20)
    return;
  if(count_leading_characters(input) > 3)
    return;
  if(!(has_mixed_case(input)))
    return;
  for(unsigned long int i = 0; i < pass_history.size(); i++){
    if(pass_history.at(i) == input)
      return;
  }
  pass_history.push_back(input);
  return;
}

bool Password::authenticate(string input){
  return(pass_history.back() == input);
}

Password::Password(){
  set("ChicoCA-95929");
}

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

bool Password::has_mixed_case(string str){
  //My function
  bool upper = false;
  bool lower = false;
  unsigned long int i = 0;
  while(i < str.length() && (!upper || !lower)){
    if(isupper(str.at(i)))
      upper = true;
    else if(islower(str.at(i)))
      lower = true;
    i++;
  }
  return(upper && lower);
  //Function A - PASS
  //Implementation B - FAIL
  //Implementation C - PASS
  //Implementation D - FAIL
  //Implemenation E - FAIL
}
