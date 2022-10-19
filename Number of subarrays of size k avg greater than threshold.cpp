class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int answer = 0;
        for(int i=1; i<arr.size();i++)
            arr[i] = arr[i] + arr[i-1];
        for(int i = k-1; i<arr.size();i++){
            int avg = (i == k-1 ?  arr[i] : arr[i] - arr[i-k])/k;
            if(avg >= threshold)
                answer++;
        }  
        return answer;        
        
    }
};
