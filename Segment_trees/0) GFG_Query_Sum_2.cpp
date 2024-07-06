// User function Template for C++

class Solution{
private:
    int query_tree(int l, int r, int seg_idx, vector<int>&seg, int start, int end){
        //cout<<"l is "<<l<<" r is "<<r<<" seg_idx "<<seg_idx<<" start is "<<start<<" end is "<<end<<"\n";
        if(r<start || l>end)return 0;
        
        else if(l<=start && end<=r){
           // cout<<"Here\n";
            return seg[seg_idx];
            
        }
        
        else {
            int res = 0;
            int mid = (start+((end-start)/2)); // prevent int overflow
            res += query_tree(l, r, (2*seg_idx)+1, seg, start, mid);
            res += query_tree(l, r, (2*seg_idx)+2, seg, mid+1, end);
            return res;
        }
    }
private:
    void build_tree(int seg_idx, int l, int r, int arr[], vector<int>&seg){
        
        if(l==r){
            seg[seg_idx]=arr[l];
            return;
        } // base case
        
        int mid = (l+((r-l)/2)); // prevent int overflow
        build_tree((2*seg_idx)+1, l, mid, arr, seg); //left subtree call
        build_tree((2*seg_idx)+2, mid+1, r, arr, seg); //right subtree call
        
        seg[seg_idx] = seg[(2*seg_idx)+1]+seg[(2*seg_idx)+2];
    }
public:
    vector<int> querySum(int n, int arr[], int q, int queries[])
    {
        vector<int>ans;
        int sz = ceil(log2(n));
        sz = (1<<sz);
        sz=((2*sz)-1);
        vector<int>seg(sz);
        //cout<<"size is "<<sz<<"\n";
        build_tree(0,0,n-1,arr,seg);
        // for(int i=0;i<sz;i++){
        //     cout<<seg[i]<<" ";
        // }
        // cout<<"\n";
        int idx=0;
        for(int i=0;i<q;i++){
            int twmp = query_tree(queries[idx]-1, queries[idx+1]-1, 0, seg, 0, n-1);
            ans.push_back(twmp);
            //cout<<twmp<<"\n";
            idx+=2;
        }
        return ans;
        
    }
};