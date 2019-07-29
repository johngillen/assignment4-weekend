/*
 * Name: John Gillen
 * Assignment: Assignment4-weekend
 */

#include <stdio.h>
#include <stdlib.h>

char *cipher(char *string, char key)
{
    char k = (key - 'a') % 26;
    char* s = malloc(sizeof(string) + 1);
    s = string;

    for (int i = 0; s[i] != '\0'; i++) 
    {
        if ('a' <= s[i] && s[i] <= 'z')  
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
    printf("Encryption key: ");
    scanf(" %c", &key);

    char ikey = (('a' - key) + 26) % 26 + 'a';
    printf("Decryption key: %c\n", ikey);
    
    printf("Ciphertext: %s\n", cipher(plaintext, key));

    return 0;
}
