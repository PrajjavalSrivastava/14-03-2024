class Solution {
  public:
    int largestSubsquare(int n, vector<vector<char>> a) {
        // code here
        vector<vector<int>> ver(n , vector<int>(n, 0)) , hor(n , vector<int>(n, 0));
        int side = 0;
        
        for(int i = 0; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                if(a[i][j] == 'X'){
                    ver[i][j] = i == 0 ? 1 : ver[i-1][j] + 1;
                    hor[i][j] = j == 0 ? 1 : hor[i][j-1] + 1;
                }
            }
        }
        
        for(int i = n-1 ; i >= 0 ; i--){
            for(int j = n-1 ; j >= 0 ; j--){
                int val = min(ver[i][j] , hor[i][j]);
                while(val > side){
                    if(ver[i][j-val+1] >= val and hor[i-val+1][j] >= val){
                        side = val;
                    }
                    val--;
                }
            }
        }
        
        return side;
    }
};