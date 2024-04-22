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
  if(count_leading_chracters(input) > 3)
    return;
  if(!(has_mixed_case(input)))
    return;
  for(unsigned long int i = 0; i < pass_history.length(); i++){
    if(pass_history.at(i) == input)
      return;
  }
  pass_history.push_back(input);
  return;
}

bool Password::authenticate(string input){
  return(pass_history.back() == input);
}

bool Password::Password(){
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
  /*bool has_lower = false;
  bool has_upper = false;
  for (char ch : str)
  {
    if (std::islower(ch))
    {
      has_lower = true;
    }
    else if (std::isupper(ch))
    {
      has_upper = true;
    }
  }
  return has_lower && has_upper;
  */
  //Implementation B - FAIL
  /*int count_lower = 0;
  for (int i = 0; i < str.length(); i++)
  {
    if (str[i] >= 'a' && str[i] <= 'z')
    {
      count_lower++;
    }
  }
  return count_lower > 0 && count_lower < str.length();
  */
  //Implementation C - PASS
  /*bool lower = false;
  bool upper = false;
  for (int i = 0; i < str.length(); i++)
  {
    if (str[i] >= 'a' && str[i] <= 'z')
    {
      lower = true;
    }
    else if (str[i] >= 'A' && str[i] <= 'Z')
    {
      upper = true;
    }
  }
  return upper && lower;
  */
  //Implementation D - FAIL
  /*bool is_lower = false;
  bool is_upper = false;
  for (char c : str)
  {
    if (std::islower(c))
    {
      is_lower = true;
    }
    else
    {
      is_upper = true;
    }
  }
  return is_lower && is_upper;
  */
  //Implemenation E - FAIL
  /*bool found = false;
  for(char c : str){
    if( !found && c >= 'A' && c <= 'Z' ){
      found = true;
    }
    else if( found && c >= 'a' && c <= 'z'){
      return true;
    }
  }
  return false;
  */
}
