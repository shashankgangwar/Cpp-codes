/*
link: https://leetcode.com/problems/maximum-units-on-a-truck/submissions/

*/
bool comp(vector<int>& a, vector<int>& b){
    if(a[1]>b[1]) return true;
    return false;
}


int maximumUnits(vector<vector<int>>& A, int t) {
    sort(A.begin(),A.end(),comp);
    int ans=0,n=A.size();
    for(int i=0;i<n;i++){
        if(t>A[i][0]){
            ans=ans+(A[i][0]*A[i][1]);
            t=t-A[i][0];
        }
        else{
            ans=ans+(t*A[i][1]);
            break;
        }
    }
    return ans;
}
