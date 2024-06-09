#include<vector>
class get_max_value{

public:
    int get_max(const std::vector<int>& arr, int l , int r){
        if(l == r)  return arr[l];

        int mid = l + ((r-l) >> 1);

        int left_max = get_max(arr , l , mid);
        int right_max = get_max(arr , mid+1 , r);
        return left_max > right_max ? left_max : right_max ;
    }
};

//master 公式 T(n) = a * T(n/b) + O(n^c)