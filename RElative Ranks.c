#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
    int score;
    int index;
} ScorePair;
int compare(const void *a, const void *b) {
    return ((ScorePair*)b)->score - ((ScorePair*)a)->score;
}
char** findRelativeRanks(int* score, int scoreSize, int* returnSize) {
    char** answer = (char**)malloc(scoreSize * sizeof(char*));
    ScorePair* arr = (ScorePair*)malloc(scoreSize * sizeof(ScorePair));
    for (int i = 0; i < scoreSize; i++) {
        arr[i].score = score[i];
        arr[i].index = i;
    }
    qsort(arr, scoreSize, sizeof(ScorePair), compare);
    char gold[] = "Gold Medal";
    char silver[] = "Silver Medal";
    char bronze[] = "Bronze Medal";
    for (int i = 0; i < scoreSize; i++) {
        int rankIndex = arr[i].index;
        answer[rankIndex] = (char*)malloc(20); 
        if (i == 0) strcpy(answer[rankIndex], gold);
        else if (i == 1) strcpy(answer[rankIndex], silver);
        else if (i == 2) strcpy(answer[rankIndex], bronze);
        else {
            sprintf(answer[rankIndex], "%d", i + 1);
        }
    }
    free(arr);
    *returnSize = scoreSize;
    return answer;
}
