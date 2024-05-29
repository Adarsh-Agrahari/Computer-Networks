// CRC - Cyclic Redundency Check
#include<stdio.h>  
#include<string.h>  

char d[28],c[28],p[10];  
int n,i,j,m;  
void XOR(){  
    for(j=1;j<m;j++) c[j]=(c[j]==p[j])?'0':'1';  
}  
void crc(){  
    for(i=0;i<m;i++) c[i]=d[i];  
    do{    
        if(c[0]=='1') XOR();   
        for(j=0;j<m-1;j++) c[j]=c[j+1];  
        c[j]=d[i++];  
    } while(i<=n+m-1);  
}  
void receiver(){  
    printf("\nEnter the received data: ");  
    scanf("%s", d);  
    printf("-----------------------------");  
    printf("\nData received: %s", d);  
    crc();  
    for(i=0;i<m-1;i++) if(c[i]!='0') {printf("\nError detected"); return;}
    printf("\nNo error detected");  
}  
int main(){  
    // User Input ---------------------------------------
    printf("\nEnter data to be transmitted: ");  
    scanf("%s",d);  
    printf("\nEnter the Generating polynomial: ");  
    scanf("%s",p);
    // Direct Input -------------------------------------
    // strcpy(d,"1010101010");
    // strcpy(p,"11001");
    // OR
    // strcpy(d,"100100");
    // strcpy(p,"1101");
    n=strlen(d); 
    m=strlen(p); 
    for(i=n;i<n+m-1;i++) d[i]='0';  
    printf("\nData padded with n-1 zeros : %s",d);  
    crc();  
    printf("\nCRC : %s",c);  
    for(i=n;i<n+m-1;i++) d[i]=c[i-n];  
    printf("\nFinal data to be sent : %s",d);   
    receiver();  
    return 0;  
}  

// Data padded with n-1 zeros : 100100000
// CRC : 001
// Final data to be sent : 100100001
// Enter the received data: 100100001
// -----------------------------
// Data received: 100100001
// No error detected

// Data padded with n-1 zeros : 100100000
// CRC : 001
// Final data to be sent : 100100001
// Enter the received data: 100100000
// -----------------------------
// Data received: 100100000
// Error detected
