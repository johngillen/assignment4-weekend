#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *cipher(char *string, char key)
{
    char k = (key - 'a') % 26;
    // john G helped with malloc()
    char* s = malloc(sizeof(string) + 1);
    s = string;

    for (int i = 0; s[i] != '\0'; i++) 
    {
        if ('a' <= s[i] <= 'z')  
        {
            if (s[i] + k > (int)'z')
            {
                s[i] = ((s[i] - 'a') + k) % 26 + 'a';
            } else {
                s[i] += k;
            }
            
        }
    }

    return s;
}

int main(int argc, char const *argv[])
{

    char plaintext[420];
    printf("Enter cleartext: ");
    scanf("%s", plaintext);

    char key;
    printf("Enter key: ");
    scanf(" %c", &key);
    
    printf("%s\n", cipher(plaintext, key));

    return 0;
}
