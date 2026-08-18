#include <stdio.h>
#include <stdlib.h>

typedef struct Entry {
    int key;
    int index;
} Entry;

// Simple hash table structure
typedef struct {
    Entry* entries;
    int capacity;
    int size;
} HashMap;

int get_hash(int val, int capacity) {
    return abs(val) % capacity;
}

HashMap* create_table(int cap) {
    HashMap* map = malloc(sizeof(HashMap));
    map->capacity = cap;
    map->size = 0;
    map->entries = malloc(cap * sizeof(Entry));
    // Initialize with invalid index
    for(int i = 0; i < cap; i++) {
        map->entries[i].index = -1;
    }
    return map;
}

int contains(HashMap* map, int key) {
    int idx = get_hash(key, map->capacity);
    for(int i = 0; i < map->capacity; i++) {
        if(map->entries[idx].index != -1 && 
           map->entries[idx].key == key) {
            return map->entries[idx].index;
        }
        idx = (idx + 1) % map->capacity;
    }
    return -1;
}

void insert(HashMap* map, int key, int index) {
    int idx = get_hash(key, map->capacity);
    for(int i = 0; i < map->capacity; i++) {
        if(map->entries[idx].index == -1 || map->entries[idx].key == key) {
            map->entries[idx].key = key;
            map->entries[idx].index = index;
            return;
        }
        idx = (idx + 1) % map->capacity;
    }
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    *returnSize = 2;
    int cap = numsSize * 2;
    HashMap* map = create_table(cap);
    
    int* result = malloc(2 * sizeof(int));
    
    for(int i = 0; i < numsSize; i++) {
        int complement = target - nums[i];
        int compIndex = contains(map, complement);
        
        if(compIndex != -1) {
            result[0] = compIndex;
            result[1] = i;
            return result;
        }
        
        insert(map, nums[i], i);
    }
    
    return NULL;
}
