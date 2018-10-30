#include <stdio.h>

long rfibo(int n);
long sfibo(int n);
//1 1 2 3 5
int main() {
    int n;
    for(n = 0; n <= 45; n++){
        if(n % 2 == 1){
            printf("rfibo(%d) = %ld\n", n, rfibo(n));
            printf("sfibo(%d) = %ld\n", n, sfibo(n));
        }
    }
    return 0;
}

long rfibo(int n){
    if (n == 1) return 1;
    if (n == 2) return 1;

    return rfibo(n-1) + rfibo(n-2);
}

long sfibo(int n){

    static int stage = 2;
    static long nowValue = 1;
    static long prevValue = 1;
    long temp;

    if(stage < n){
        for(int i = stage; i < n; i++){
            temp = nowValue;
            nowValue = nowValue + prevValue;
            prevValue = temp;
        }

        stage = n;
    }

    else if(stage > n){
        for(int i = n; i < stage; i++){
            temp = prevValue;
            prevValue = nowValue - prevValue;
            nowValue = temp;
        }

        stage = n;
    }

    return nowValue;



}