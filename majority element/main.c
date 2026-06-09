int majorityElement(int* nums, int numsSize) {
    int count=1;
    int m=nums[0];
    for(int i=0;i<numsSize-1;i++){
        if( m == nums[i+1]){
            count++;
        }else{
            count--;
        }
        if(count == 0 ){
            m=nums[i+1];
            count=1;
        }
    }
    return m;
}