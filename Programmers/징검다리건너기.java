class Solution {
    
    public Boolean check(int[] arr, int k, int t){
        //할 수 있는지 확인
        int cnt=0;
        for(int i=0;i<arr.length;i++){
            if(arr[i]-t<=0) cnt++;
            else cnt=0;
            if(cnt>=k) return false;
        }
        return true;
    }
    public int solution(int[] stones, int k) {
        int answer = 0;
        int end =0;
        int start = 987654321;
        for(int i=0;i<stones.length;i++){
            end = end<stones[i] ? stones[i] : end;
            start = start>stones[i] ? stones[i] :start;
        }
        while(start<=end){
            int mid = start+end;
            mid/=2;
            if(check(stones,k,mid)){
                start=mid+1;
            }
            else{
                end=mid-1;
            }
        }
        return start;
    }
}