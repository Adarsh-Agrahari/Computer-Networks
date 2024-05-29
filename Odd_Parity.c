// Single bit odd parity
#include<stdio.h>
#include<string.h>

// get parity
char gp(const char *d) {
    int c=0;
    for(int i=0;i<strlen(d);i++)  if(d[i]=='1') c++;
    return (c%2==0)?'1':'0';
}

int main() {
    char d[100], dp[101], dr[101]; // dp-data parity, dr-data received 

    // Sender Side
    printf("Sender Side:\n");
    printf("Enter binary data: ");
    scanf("%s", d);

    strcpy(dp, d);
    dp[strlen(d)] = gp(d);
    dp[strlen(d)+1] = 0;

    printf("Data with parity bit: %s\n", dp);

    // Receiver Side
    printf("\nReceiver Side:\n");
    printf("Enter the transmitted binary data: ");
    scanf("%s", dr);
    
    int c=0;
    for(int i=0;i<strlen(dr);i++) if(dr[i]=='1') c++;
    if(c%2!=0) {
        printf("Parity check: Odd parity - Passed\n"); 
        printf("Received Data: ");
        for(int i=0;i<strlen(dr)-1;i++) printf("%c",dr[i]);
    } else {
        printf("Parity check: Odd parity - Failed\n");
        printf("Received Data might have errors!\n");
    }
    return 0;
}

// Sender Side:
// Enter binary data: 110110
// Data with parity bit: 1101101      

// Receiver Side:
// Enter the transmitted binary data: 1101101
// Parity check: Odd parity - Passed
// Received Data: 110110

// Sender Side:
// Enter binary data: 110110
// Data with parity bit: 1101101

// Receiver Side:
// Enter the transmitted binary data: 1101001
// Parity check: Odd parity - Failed
// Received Data might have errors!
