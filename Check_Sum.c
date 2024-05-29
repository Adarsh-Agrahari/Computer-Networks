// Check Sum
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int btd(char *s){
    int c=0,l=strlen(s);
    for(int i=0;i<l;i++){
        if(s[i]=='1') c+=pow(2,l-i-1);
    }
    return c;
}

char* dtb(int n, int k) {
    static char s[100], r[100];
    int i = 0;
    while(n>0){
        if(n%2) s[i++] = '1';
        else s[i++] = '0';
        n/=2;
    }
    s[i]=0; 
    int l=strlen(s);
    if(l<k){
        for(int j=0;j<k-l;j++) r[j] = '0';
        for(int j=0;j<l;j++) r[k-l+j]=s[l-j-1];
        r[k]=0; 
    } else {
        for(int j=0;j<l;j++) r[j]=s[l-j-1];
        r[l]=0; 
    }
    return r;
}

char* as(char *sm,int k){
    int t=strlen(sm);
    char s1[100], s2[100];
    for(int i=0;i<t-k;i++) s1[i]=sm[i];
    s1[t-k]=0;
    for(int i=t-k;i<t;i++) s2[i-t+k]=sm[i];
    s2[k]=0;
    sm = dtb(btd(s1)+btd(s2),k);
    return sm;
}

int main(){
    printf("Sender Side ~\n");
    // User Input
    int n, k;
    printf("Enter no of Segments: ");
    scanf("%d", &n);
    printf("Enter bit length of each segment: ");
    scanf("%d", &k);
    printf("Enter data bits:\n");
    char d[n][k+1];
    for(int i=0;i<n;i++){
        printf("Segment %d: ",i+1);
        scanf("%s",d[i]);
    }

    int s=0;
    for(int i=0;i<n;i++) s+=btd(d[i]);

    char* sm = dtb(s,k);
    if(strlen(sm)>k) sm=as(sm,k);
    printf("Sum : %s\n",sm);
    for(int i=0;i<k;i++) sm[i]=sm[i]=='1'?'0':'1';
    printf("Check Sum : %s\n",sm);

    printf("---------------------");
    printf("\nReceiver Side ~\n");
    printf("You are supposed to enter %d segments of %d length!\n", n, k);
    int sr=0;
    char dt[100];
    for(int i=0;i<n;i++) {
        printf("Segment %d: ",i+1);
        scanf("%s",dt);
        sr+=btd(dt);
    }
    printf("Enter the checksum : ");
    scanf("%s",dt);
    sr+=btd(dt);
    char* ans = dtb(sr,k);
    if(strlen(ans)>k) ans=as(ans,k);
    printf("%s\n",ans);
    for(int i=0;i<k;i++) if(ans[i]!='1') {printf("Rejected!"); return 0;}
    printf("Accepted!");
    return 0;
}

// Direct Input -----------------
// int n=4,k=8;
// char d[n][k+1];
// strcpy(d[0],"10011001");
// strcpy(d[1],"11100010");
// strcpy(d[2],"00100100");
// strcpy(d[3],"10000100");

// int n=2,k=8;
// char d[n][k+1];
// strcpy(d[0],"10101001");
// strcpy(d[1],"00111001");

// Test Case ------------------------------------
// Sender Side ~
// Enter no of Segments: 2
// Enter bit length of each segment: 8
// Enter data bits:
// Segment 1: 10101001
// Segment 2: 00111001
// Sum : 11100010
// Check Sum : 00011101
// ---------------------
// Receiver Side ~
// You are supposed to enter 2 segments of 8 length!        
// Segment 1: 10101001
// Segment 2: 00111001
// Enter the checksum : 00011101
// 11111111
// Accepted!
