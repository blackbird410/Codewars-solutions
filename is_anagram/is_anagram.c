#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>

bool is_anagram(const char *s1, const char *s2);


int main()
{
  bool result = is_anagram("Creative", "Reactive"); 
  if (result)
  {
    printf("It is an anagram.");
  }
  else
  {
    printf("It is not an anagram.");
  }

  return 0;
}

bool is_anagram(const char *s1, const char *s2)
{
  int i = 0, length = strlen(s1);
  bool found = false;
  
  // Check for length equality
  if (length != strlen(s2))
  {
    return false;
  }
  
  // Make a copy of the second string
  char *copy = malloc((length + 1) * sizeof(char));
  strcpy(copy, s2);
  
  // Check each values from the first string
  for (i = 0; i < length; i++)
  {
    found = false;
    for (int j = 0; j < length; j++)
    {
      int a = tolower(s1[i]);
      int b = tolower(copy[j]);
      if (a == b)
      {
        found = true;
        copy[j] = '.';
        break;
      }
    }
    
    if (!found)
    {
      return false;
    }
  }
  
	return true;
}
