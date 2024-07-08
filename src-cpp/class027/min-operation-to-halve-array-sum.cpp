// https://leetcode.cn/problems/minimum-operations-to-halve-array-sum/description/
#include<vector>
#include<queue>
class Solution {
public:
    int halveArray(std::vector<int>& nums) {
        std::priority_queue<double> max_heap;
        double sum = 0;
        for(auto it : nums){
            max_heap.push(it);
            sum += it;
        }

        double reduce = 0;
        int step = 0;
        while(reduce <  sum / 2){
            double top = max_heap.top();
            max_heap.pop();
            max_heap.push(top / 2);
            reduce += top / 2;
            step++;
        }

        return step;

    }
};
//时间复杂度为O(N*logN)
//不利用贪心策略，达到"数组总和缩小一半"这一目标，最大的操作次数是N次，即对每一个数缩小一半
//现在使用贪心策略，操作次数一定是小于等于N的
//小于等于N次出入堆，时间复杂度为O(N*logN)


//但这样只打败了5%

//用数组模拟大根堆试一试？
class MAX_HEAP{
    private:
        double data[100001];
        int size = 0;

        void swap(double& a , double& b){
            double t = a;
            a = b;
            b = t;
        }

    public:
        void push(double x){
            data[size++] = x;
            int idx = size - 1;
            while(data[idx] > data[(idx - 1) / 2]){
                swap(data[idx] , data[(idx - 1) >> 1]);
                idx = (idx - 1) >> 1;
            }

        }
        
        void pop(){
            swap(data[0] , data[--size]);
            heapify(0);
        }

        double top(){
            return data[0];
        }

        void heapify(int idx){
            while(idx < size){
                int l = 2 * idx + 1;
                int bigger = (l + 1 < size && data[l] < data[l + 1]) ? l+1 : l;

                bigger = data[idx] < data[bigger] ? bigger : idx;
                if(bigger == idx)   break;
                
                swap(data[bigger] , data[idx]);
                idx = bigger;
            }
        }
};
class Solution2 {
public:
    int halveArray(std::vector<int>& nums) {
        // std::priority_queue<double> max_heap;
        MAX_HEAP max_heap; 
        double sum = 0;
        for(auto it : nums){
            max_heap.push(it);
            sum += it;
        }

        double reduce = 0;
        int step = 0;
        while(reduce <  sum / 2){
            double top = max_heap.top();
            max_heap.pop();
            max_heap.push(top / 2);
            reduce += top / 2;
            step++;
        }

        return step;

    }
};
