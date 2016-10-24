#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>

int MOD = 10000019;
int PRIME = 101;

unsigned long long hash(char string[], int len){
    unsigned long long hashVal = 0;
    for(int i = 0; i < len; i++){
        hashVal = (PRIME * hashVal + string[i]) % MOD;
    }
    return hashVal;
}

unsigned long long hashAll(char string[]){
    int len = strlen(string);
    return hash(string, len);
}

//x^p % m
unsigned long long modPow(int x, int pow, int mod){
    unsigned long long result = 1;
    for(int i = 0; i < pow; i++){
        result = (result * x) % mod;
    }
    return result;
}

int matchCount(char host[], char query[]){
    int tally = 0;
    
    unsigned int queryLen = strlen(query);
    unsigned long long targetHash = hash(query, queryLen);
    unsigned long long hostHash = hash(host, queryLen);
    
    unsigned long long mp = modPow(PRIME, queryLen - 1, MOD);
    
    if(hostHash == targetHash)
        tally++;
    
    for(int i = queryLen; i < strlen(host); i++){
        hostHash = (hostHash + MOD - (mp*host[i-queryLen] % MOD)) % MOD;
        hostHash = (hostHash*PRIME + host[i]) % MOD;
        
        if(hostHash == targetHash){
            tally++;
        }
    }
    return tally;
}

int matchCountFile(char query[], FILE* file){
    int tally = 0;
    
    unsigned int queryLen = strlen(query);
    char buffer[queryLen];
    int oldest = 0;
    
    fgets(buffer, queryLen+1, file);
    
    
    unsigned long long targetHash = hashAll(query);
    unsigned long long hostHash = hashAll(buffer);
    unsigned long long mp = modPow(PRIME, queryLen - 1, MOD);
    
    if(hostHash == targetHash)
        tally++;
    
    char nextChar;
    while((nextChar = fgetc(file)) != EOF){
        hostHash = (hostHash + MOD - (mp*buffer[oldest] % MOD)) % MOD;
        hostHash = (hostHash*PRIME + nextChar) % MOD;
        
        buffer[oldest] = nextChar;
        oldest = (oldest + 1) % queryLen;
        
        if(hostHash == targetHash){
            tally++;
        }
    }
    return tally;
}


int main(){
    char query[80];
    scanf("%s", query);
    
    FILE *file;
    file = fopen("mobydick.txt", "r");
    
    printf("Found %d matches\n", matchCountFile(query, file));
    
    return 0;
}
