#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char *hello(const char *name) 
{
  int i = 0, j = 0, l = strlen(name);
  
  if (l == 0)
  {
    char *output = malloc(13 * sizeof(char)); // 12 characters for "Hello, World!" + 1 for '\0'
    if (output == NULL) {
      // Handle memory allocation failure
      return NULL;
    }
    strcpy(output, "Hello, World!");
    return output;
  }
  else
  {
    char *output = malloc((l + 12) * sizeof(char));
    char hello[] = "Hello, ";
    for(i = 0; i < l + 8; i++)
    {
      if(i < 7)
      {
        output[i] = hello[i]; 
      }
      else
      {
        if (j == 0)
        {
         output[i] = toupper(name[j]); 
        }
        else
        {
          output[i] = tolower(name[j]);
        }
        j++;
      }
    }
    output[l + 7] = '!';
    output[l + 8] = '\0';

    return output;
  }

}