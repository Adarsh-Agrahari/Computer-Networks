// Hamming Code
#include <stdio.h>
void main() {
    int d[10];
    int rd[10], c1, c2, c3, c;

    printf("Enter 4-bit binary data : ");
    scanf("%d",&d[0]);
    scanf("%d",&d[1]);
    scanf("%d",&d[2]);
    scanf("%d",&d[4]);

    d[6] = d[4] ^ d[2] ^ d[0];
    d[5] = d[4] ^ d[1] ^ d[0];
    d[3] = d[2] ^ d[1] ^ d[0];

    printf("Transmitted Hamming Code : ");
    for(int i=0;i<7;i++) printf("%d ",d[i]);

    printf("\nReceived Data : ");
    for(int i=0;i<7;i++) scanf("%d",&rd[i]);
    c3 = rd [6] ^ rd[4] ^ rd[2] ^ rd[0];
    c2 = rd [5] ^ rd[4] ^ rd[1] ^ rd[0];
    c1 = rd [3] ^ rd[2] ^ rd[1] ^ rd[0];
    c = (c1*4)+(c2*2)+c3;

    if(c==0) printf("No error detected");
    else {
        printf("Error on position in: %d",c);

        printf("\nData sent : ");
        for(int i=0;i<7;i++) printf("%d ",d[i]);

        printf("\nData received : ");
        for(int i=0;i<7;i++) printf("%d ",rd[i]);

        rd[7-c]=1-rd[7-c];
        printf("\nCorrect Data : ");
        for(int i=0;i<7;i++) printf("%d ",rd[i]);
    }
}

// Enter 4-bit binary data : 1 0 1 1
// Transmitted Hamming Code : 1 0 1 0 1 0 1 
// Received Data : 1 0 1 0 1 0 1
// No error detected

// Enter 4-bit binary data : 1 0 1 1
// Transmitted Hamming Code : 1 0 1 0 1 0 1 
// Received Data : 1 0 1 0 1 1 1
// Error on position in: 2
// Data sent : 1 0 1 0 1 0 1
// Data received : 1 0 1 0 1 1 1
// Correct Data : 1 0 1 0 1 0 1

// Enter 4-bit binary data : 1 0 1 1  
// Transmitted Hamming Code : 1 0 1 0 1 0 1 
// Received Data : 1 0 1 1 1 0 1
// Error on position in: 4
// Data sent : 1 0 1 0 1 0 1
// Data received : 1 0 1 1 1 0 1
// Correct Data : 1 0 1 0 1 0 1
