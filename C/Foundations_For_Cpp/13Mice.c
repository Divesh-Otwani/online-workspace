#include <stdio.h>


int L(int j, int n){
    if(n==1){
        return 0;
    }
    else{
        return (j%n + L(j, n-1));
    }
};

int R(int k){
    return L(k,k)%k;
};


int mod(int m, int n){
    if (m >= 0){
        return m%n;
    }
    else{
        while (m < 0){
            m+= n;
        }
        return m;
    }
}

int EatFirst(int jumpSize, int numberMice, int IndexEat ){
    if (numberMice == jumpSize){
        return IndexEat;
    }
    else{
        numberMice++;
        IndexEat = mod((IndexEat - (jumpSize % numberMice) -1), jumpSize);
        printf("IndexEat: %d\n", IndexEat);
        return EatFirst(jumpSize, numberMice, IndexEat);
    }
}

int DiveshCat(int jump, int numAlive, int IndexEat){
    if (numAlive == jump){
        return IndexEat;
    }
    else{
        IndexEat += jump%numAlive;
        IndexEat %= jump;
        numAlive++;
        printf("%d\n", IndexEat);
        return DiveshCat(jump, numAlive, IndexEat);
    }
}

typedef enum {EATEN, THERE} MouseState;
int cat(int numMice, int jumpSize){
    MouseState mice[numMice];
    for(int i = 0; i < numMice - 1; i++) mice[i] = THERE;
    int currInd = 0;
    for(int miceLeft = numMice; miceLeft > 0; miceLeft--){
        for(int j = jumpSize; j > 0; j--,currInd++){
            if(currInd == numMice) currInd = 0;
            if(mice[currInd] == EATEN) j++;
        }
    }
    return currInd % 13;
}


int main(){
    printf("For 13 mice: %d\n", DiveshCat(13,1,0));
    printf("heman's way: %d\n", cat(13,13));
    printf("Test -4 %% 10: %d\n\n", mod(-4,10));
    return 0;
}
