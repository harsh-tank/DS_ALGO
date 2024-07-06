

/* The functions which 
builds the segment tree */

void build_tree(int l, int r, int arr[], int seg_idx, int *seg){
    if(l==r){
        seg[seg_idx]=arr[l];
        return;
    }
    
    int mid = l+((r-l)/2);
    build_tree(l ,mid, arr, (2*seg_idx)+1, seg);
    build_tree(mid+1, r, arr, (2*seg_idx)+2, seg);
    
    seg[seg_idx]=min(seg[(2*seg_idx)+1], seg[(2*seg_idx)+2]);
}
int *constructST(int arr[],int n)
{
  int sz = (int)(ceil(log2(n)));
  sz = (1<<sz);
  sz = (2*sz)-1;
  int *seg = new int[sz];
  build_tree(0, n-1, arr, 0, seg);
//   for(int i=0;i<sz;i++){
//       cout<<seg[i]<<" ";
//   }
//   cout<<"\n";
  return seg;
}


/* The functions returns the
 min element in the range
 from a and b */
int query(int l ,int r, int seg_idx, int start, int end, int *seg){
    //cout<<" l is "<<l<<" r is "<<r<<" seg_idx is "<<seg_idx<<" start is "<<start<<" end is "<<end<<"\n";
    if(r<start || l>end)return INT_MAX;
    
    else if(l<=start && end<=r){
        return seg[seg_idx];
    }
    
    else{
        int mid = start+((end-start)/2);
        //cout<<"mid is "<<mid<<"\n";
        return min(query( l, r, (2*seg_idx)+1, start, mid, seg), query( l, r, (2*seg_idx)+2, mid+1, end, seg));
        
    }
}
int RMQ(int st[] , int n, int a, int b)
{
    return query(a, b, 0, 0, n-1, st);
}