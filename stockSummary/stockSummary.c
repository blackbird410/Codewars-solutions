#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>


const char *const BOOKS[] = {"OERBWPAHJ 392", "HTLUU 565", "RZY 674", "S 38", "RTCD 962", "HDV 99", "VND 472", "KB 353", "X 918", "RHHR 358", "HBVADYOX 611", "SN 783", "AQXBCAOJYX 42", "EBIYFR 33", "RGAID 909", "VUPL 130", "IYMLOXJN 347", "UUISZZU 761", "ABCEJEB 941", "MC 710", "COISNRGETA 13", "SY 250", "AWR 399", "XMFYSANWCK 172", "UQGNYL 506", "MJT 804", "JMLAQMZE 337", "WTNUWZS 119", "LZGJMOKYXD 759", "MZZPRMOWF 926", "ZBPXA 115", "V 568", "BGERSCQVPC 93", "CYIQPG 925", "DY 151", "VHDLD 938", "GIHY 306", "OZDT 774", "XJEPYNMDQ 199", "K 942", "PWVRZ 693", "IB 377", "SC 984", "NUKW 765", "WO 509", "EYMQHE 535", "BZGEAOGGLA 904", "LXIXVJW 323", };
const char *const CATEGORIES[] = {"I", "J", "Z", "L", "N", "H", "C", "F", "S", };
size_t NB_BOOKS = sizeof(BOOKS) / 8;
size_t NB_CATEGORIES = sizeof(CATEGORIES) / 8;

char *stockSummary (const char *const books[], size_t nb_books,
                                        const char *const categories[], size_t nb_categories);


int main()
{
  // Help the bookseller test!
  char *record = stockSummary(BOOKS, NB_BOOKS, CATEGORIES, NB_CATEGORIES);

  printf("Record of classifying : %s\n", record);

  free(record);

  return 0;
}


char *stockSummary (const char *const books[], size_t nb_books,
                                        const char *const categories[], size_t nb_categories)
{
  size_t i = 0, j = 0, k = 0, l = 0, pos = 0, list_index = 0;
  char n[30];
  long sum = 0;
  bool found = false;
  
  // Check for empty list
  if (nb_books == 0 || nb_categories == 0)
  {
    char *emptyString = malloc(1);
    if (emptyString != NULL) {
        emptyString[0] = '\0'; // Set the first character to null terminator
        return emptyString;
    } else {
        return NULL; // Handle memory allocation failure
    }

  }

  int *list = malloc((nb_categories + 10) * sizeof(int));
  // Handle memory allocation failure
  if (list == NULL)
  {
    return NULL;
  }

  // Parse the list of books to find the number of books for each categories
  for (i = 0; i < nb_categories; i++)
  {
    sum = 0;
    for (j = 0; j < nb_books; j++)
    {
      // Check if the first character in the code is the same as the current category 
      char book[50];
      char cat[2];
      strcpy(book, books[j]);
      strcpy(cat, categories[i]);
      if (book[0] == cat[0])
      {
        // Get the number of books
        l = strlen(books[j]);
        found =  false;
        pos = 0;

        // Get the number in the string
        for (k = 0; k < l; k++)
        {
          if (found)
          {
            n[pos] = book[k];
            pos++;
          }

          if (book[k] == ' ')
          {
            found = true;
          }
        }
        n[pos] = '\0';
        
        // Convert the number found to an integer and add it to the sum
        sum += atoi(n);
      }
      
    }
    
    // Add the number of books of the latest category to the list
    list[list_index] = sum;
    list_index++;
    
  }
  
  // Create the string to return the number of books for each categories
  char *record = malloc((nb_categories * 25) * sizeof(char));
  if (record ==  NULL)
  {
    free(list);
    return NULL;
  }
  
  i = 0;
  pos = 0;
  while (i < nb_categories)
  {
    record[pos] = '(';
    record[pos + 1] = categories[i][0];
    record[pos + 2] = ' ';
    record[pos + 3] = ':';
    record[pos + 4] = ' ';
    pos += 5;
    
    //  Get the string value from the integer in the list
    char buffer[20];
    sprintf(buffer, "%d", list[i]);
    l = strlen(buffer);
    for (j = 0; j < l; j++)
    {
      record[pos] = buffer[j];
      pos++;
    }
    
    record[pos] = ')';
    record[pos + 1] = ' ';
    record[pos + 2] = '-';
    record[pos + 3] = ' ';
    pos += 4;
    i++;
  }
  
  // End the string at the end of the last parenthesis
  record[pos - 3] = '\0';
  free(list);
  
  return record;
}
