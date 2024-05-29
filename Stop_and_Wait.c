// Stop & Wait
#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>

int main(){
  int tf;
  printf("Enter total frames to send : ");
  scanf("%d", &tf);

  int n = 1, r;
  while (n <= tf)  {
    printf("Sending frame %d\n", n);
    printf("Enter acknowledgment for frame %d (ACK:1, NACK:0): ", n);
    scanf("%d", &r);
    if(r){
      printf("Receiver: Received frame %d\n", n);
      n++;
    }
    else{
      printf("\nWaiting for %d seconds\n", 1);
      sleep(1);
    }
  }
  return 0;
}

// Enter total frames to send : 5
// Sending frame 1
// Enter acknowledgment for frame 1 (ACK:1, NACK:0): 1
// Receiver: Received frame 1
// Sending frame 2
// Enter acknowledgment for frame 2 (ACK:1, NACK:0): 0

// Waiting for 1 seconds
// Sending frame 2
// Enter acknowledgment for frame 2 (ACK:1, NACK:0): 1
// Receiver: Received frame 2
// Sending frame 3
// Enter acknowledgment for frame 3 (ACK:1, NACK:0): 1
// Receiver: Received frame 3
// Sending frame 4
// Enter acknowledgment for frame 4 (ACK:1, NACK:0): 0

// Waiting for 1 seconds
// Sending frame 4
// Enter acknowledgment for frame 4 (ACK:1, NACK:0): 1
// Receiver: Received frame 4
// Sending frame 5
// Enter acknowledgment for frame 5 (ACK:1, NACK:0): 1
// Receiver: Received frame 5
