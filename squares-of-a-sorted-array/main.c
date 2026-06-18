#include<stdlib.h>
int compare(const void* a,const void* b){
    return (*(int*)a > *(int*)b) - (*(int*)a < *(int*)b);
}
int* sortedSquares(int* nums, int numsSize, int* returnSize) {
    for(int i=0;i<numsSize;i++){
        if(nums[i] < 0){
            nums[i]=-1*nums[i];
        }
        nums[i]=nums[i]*nums[i];
    }
    qsort(nums,numsSize,sizeof(int),compare);

    *returnSize=numsSize;
    return nums;
}