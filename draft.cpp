// #include<iostream>
// #include<vector>
// #include<cmath>
// class Solution {
// public:
//     std::vector<int> distributeCandies(int candies, int num_people) {
//         int base = 0;
//         std::vector<int> ans(num_people , 0);
//         while(candies){
//             for(int i = 0 ; i < num_people ; i++){
//                 if(candies >= base + i + 1){
//                     ans[i] += base + i + 1;
//                     candies -= (base + i + 1);
//                 }
//                 else{
//                     ans[i] += candies;
//                     candies = 0;
//                     break;
//                 }
//             }
//             base +=  num_people;
//         }
//         return ans;
//     }
// };

// class Solution {
// public:
//     std::vector<int> distributeCandies(int candies, int num_people) {
//         int p = (int) (sqrt(8*candies+1) * 0.5 - 0.5);
//         int n = num_people;
//         std::vector<int> ans(n , 0);
//         int rows = p / n , cols = p % n;

//         for(int i = 0 ; i < n ; i++){
//             ans[i] += rows * (i+1) + n * rows * (rows - 1) / 2;
//             if(i < cols){
//                 ans[i] += i + 1 + rows * n;
//             }
//         }

//         ans[p%n] += candies - p * (p+1) / 2;

//         return ans;
//     }
// };

// int main(){
//     int candies = 7 , num_people = 4;
//     Solution s;
//     std::vector<int> ans;
//     ans = s.distributeCandies(candies , num_people);

//     for(auto it : ans){
//         std::cout << it << " " ;
//     }
// }

// class MyCircularDeque2 {
// private:
//     int* data;
//     int size;
//     int l , r;
//     int MAXSIZE;
// public:
//     MyCircularDeque2(int k): data(new int[k]) {
//         size = 0;
//         l = 0;
//         r = 0;
//         MAXSIZE = k;
//     }
    
//     bool insertFront(int value) {
//         if(isFull())    return false;
//         else{
//             if(isEmpty()){
//                 l = r = 0;
//                 data[l] = value;
//             }
//             else{
//                 l = (l - 1 + MAXSIZE) % MAXSIZE;
//                 data[l] = value;
//             }
//             size++;
//             return true;
//         }
//     }
    
//     bool insertLast(int value) {
//         if(isFull())    return false;
//         else{
//             if(isEmpty()){
//                 l = r = 0;//这一行不可缺
//                 data[r] = value;
//             }
//             else{
//                 r = (r + 1) % MAXSIZE;
//                 data[r] = value;
//             }
            
//             size++;
//             return true;
//         }
//     }
    
//     bool deleteFront() {
//         if(isEmpty())   return false;
//         else{
//             l = (l+1)%MAXSIZE;
//             size--;
//             return true;
//         }
//     }
    
//     bool deleteLast() {
//         if(isEmpty())    return false;
//         else{
//             r = (r - 1 + MAXSIZE) % MAXSIZE;
//             size--;
//             return true;
//         }
//     }
    
//     int getFront() {
//         if(isEmpty())   return -1;
//         else return data[l];
//     }
    
//     int getRear() {
//         if(isEmpty())   return -1;
//         else{
//             return data[r];
//         }
//     }
    
//     bool isEmpty() {
//         return size == 0;
//     }
    
//     bool isFull() {
//         return size == MAXSIZE;
//     }

//     ~MyCircularDeque2(){
//         delete[] data;
//     }
// };

// int main()
// {
//     MyCircularDeque2 circularDeque(2); 
//     circularDeque.insertFront(7);		        
//     circularDeque.deleteLast();
//     circularDeque.getFront();
//     circularDeque.insertLast(5);
//     int a = circularDeque.insertFront(0);

//     circularDeque.getFront();
//     circularDeque.getRear();
//     circularDeque.getFront();
//     circularDeque.getFront();
//     circularDeque.getRear();
//     circularDeque.insertLast(0);


    
// }


// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode *next) : val(x), next(next) {}
// };

// #include<iostream>
// #include<vector>
// class Solution {
// public:
//     ListNode* removeNthFromEnd(ListNode* head, int n) {
//         std::vector<ListNode*> ptr;
//         ListNode* t = head;
//         while(t!= nullptr){
//             ptr.push_back(t);
//             t = t->next;
//         }

//         int len = ptr.size();

//         if(len == n){
//             ListNode* tmp = head;
//             head = head->next;
//             delete tmp;
//             return head;
//         }
//         else{
//             ptr[len-n-1]->next = ptr[len-n]->next;
//             delete ptr[len-n];
//             return head;
//         }

//         return head;
//     }
// };

// #include<vector>
// #include<iostream>
// using namespace std;
// class Solution {
// private:
//     bool spell(const string& word , int map[26]){
//         for(char it : word){
//             if(map[it - 'a'] == 0){
//                 return false;
//             }
//             else{
//                 map[it - 'a']--;
//             }
//         }
//         return true;
//     }
// public:
//     int countCharacters(vector<string>& words, string chars) {
//         int ans = 0;
//         int map[26] = {0};
//         for(char it : chars){
//             map[it - 'a']++;
//         }

//         for(string word : words){
//             if(spell(word , map))   ans += word.size();
//         }

//         return ans;
//     }
// };


// int  main()
// {
//     string chars = "atach";
//     vector<string> words = {"cat","bt","hat","tree"};
//     Solution s;
//     int ans = s.countCharacters(words , chars); 
// }

// #include<iostream>
// #include<cmath>
// using namespace std;
// class Solution {
// private:
//     bool is_prime(int n){
//         if(n <= 1)  return false;
//         if(n == 2)  return true;
//         if(!(n%2))  return false;

//         for(int i = 3 ; i <= (int)sqrt(n) ; i += 2){
//             if(n%i == 0) return false;
//         }
//         return true;
//     }

//     bool is_palindrome(int n){
//         int reverse = 0;
//         int _n = n;
//         while(n > 0){
//             int t = n % 10;
//             n /= 10;
//             reverse = reverse * 10 + t;
//         }

//         return reverse == _n ? true : false;
//     }
// public:
//     int primePalindrome(int n) {
//         for(int root = )
//     }
// };

// int main()
// {
//     int n = 6;
//     Solution s;
//     cout << s.primePalindrome(n) << endl; 
// }

// #include<iostream>
// #include<vector>
// using namespace std;
// class Solution {
// private:
//     int help[50001];

//     void merge(vector<int>& nums , int l , int m , int r){
//         int i = l , j = m + 1;
//         int k = l;

//         while(i <= m && j <= r){
//             help[k++] = nums[i] <= nums[j] ? nums[i++] : nums[j++];
//         }

//         while(i <= m)   help[k++] = nums[i++];
//         while(j <= r)   help[k++] = nums[j++];

//         for(int i = l ; i <= r ; i++){
//             nums[i] = help[i];
//         }
//     }
// public:
//     vector<int> sortArray(vector<int>& nums) {
//         int n = nums.size();

//         for(int l , m , r , step = 1 ; step <= n ; step <<= 1){
//             l = 0;
//             while(l < n){
//                 m = l + step - 1;
//                 if(m >= n-1)    break;
//                 r = min(l + (step<<1) - 1 , n-1);
//                 merge(nums , l , m , r);
//                 l = r + 1;
//             }
//         }

//         return nums;
//     }
// };


// int main()
// {
//     Solution s;
//     vector<int> nums = {5,1,1,2,0,0};
//     s.sortArray(nums);

//     for(auto it : nums)
//         cout << it << " ";
// }


// #include<iostream>
// #include<vector>
// #include<ctime>
// #include<array>
// class Solution{
// private:
//     int help[501];
//     long merge(std::vector<int>& nums , int l , int mid , int r){
//         //统计部分
//         long sum = 0 , ans = 0;
//         for(int i = l , j = mid + 1 ; j <= r ; j++){
//             while(i <= mid && nums[i] <= nums[j]){
//                 sum += nums[i++];
//             }
//             ans += sum;
//         }

//         //排序部分
//         int i = l , j = mid + 1;
//         int k = l;
//         while(i <= mid && j <= r){
//             help[k++] = nums[i] <= nums[j] ? nums[i++] : nums[j++];

//         }
//         while(i <= mid) help[k++] = nums[i++];
//         while(j <= r)   help[k++] = nums[j++];
//         for(int i = l ; i <= r ; i++){
//             nums[i] = help[i];
//         }
        
//         return ans;
//     }

//     std::vector<int> get_random_vec(int n){
//         std::vector<int> arr(n);
//         for(int i = 0 ; i < n ;i++){
//             arr[i] = rand() % 20 - 10; 
//         }

//         return arr;
//     }
// public:
//     long small_sum( std::vector<int>& nums , int l , int r){
//         if(l == r)  return 0;
//         int mid = (l + r) >> 1;
//         return small_sum(nums , l , mid) + small_sum(nums , mid + 1 , r) + merge(nums ,l , mid , r);
//     }

//     long brute_force(const std::vector<int>& nums){
//         int n = nums.size();
//         long ans = 0;
//         for(int i = 1 ; i < n ; i++){
//             int cur = nums[i];
//             for(int j = i - 1 ; j >= 0 ; --j){
//                 if(nums[j] <= cur)  ans += nums[j];
//             }
//         }

//         return ans;
//     }

//     bool validator(int times){
//         int n = 5;
//         std::vector<int> arr;
//         bool res = true;
//         while(times--){
//             arr = get_random_vec(n);

//             std::vector<int> _arr(arr);
//             long ans1 = small_sum(_arr , 0 , n-1);//small_sum会改变_arr
//             long ans2 = brute_force(arr);

//             for(auto it : arr)
//                 printf("%d " , it);
//             printf("\nsmall_sum : %ld  brute_force : %ld\n" , ans1 , ans2);
//             if(ans1 != ans2){
//                 printf("fail\n");
//                 res = false;
//                 break;
//             }
//         }

//         return res;
//     }
// };

// int main()
// {
//     srand(time(0));
//     // int n;
//     // std::cin >> n;
//     // std::vector<int> nums(n);
//     // for(int i = 0 ; i < n ; i++){
//     //     scanf("%d" , &nums[i]);
//     // }

//     Solution s;
//     s.validator(10);

//     // Solution s;
//     // std::vector<int> nums = {2 , 6 , -10 , 5 ,1};
//     // std::cout << s.small_sum(nums , 0 , 4) << std::endl;
//     // std::cout << s.brute_force(nums) << std::endl;

//     return 0;
// }



// #include<vector>
// #include<iostream>
// class Solution {
// private:
//     int help[50001];
//     int merge(std::vector<int>& nums , int l , int mid , int r){
//         //统计
//         int ans = 0;
//         for(int i = l , j = mid + 1 ; j <= r ; j++){
//             while(i <= mid){
//                 if(nums[i] > 2 * nums[j]){
//                     ans += mid - i + 1;
//                     break;
//                 }
//                 else{
//                     i++;
//                 }
//             }
            
//         }

//         //排序
//         int i = l , j = mid + 1;
//         int k = l;
//         while(i <= mid && j <= r){
//             help[k++] = nums[i] <= nums[j] ? nums[i++] : nums[j++];

//         }
//         while(i <= mid) help[k++] = nums[i++];
//         while(j <= r)   help[k++] = nums[j++];
//         for(int i = l ; i <= r ; i++)
//             nums[i] = help[i];
//         return ans;
//     }
//     int iteration(std::vector<int>& nums , int l , int r){
//         if(l == r)  return 0;
//         int mid = (l + r) >> 1;
//         return iteration(nums , l , mid) + iteration(nums , mid + 1 , r) + merge(nums , l , mid , r);
//     }
// public:
//     int reversePairs(std::vector<int>& nums) {
//         int n = nums.size();
//         return iteration(nums , 0 , n-1 );
//     }
// };

// int main()
// {
//     Solution s;
//     std::vector<int> nums = {1 , 3 , 2 , 3 ,1};
//     std::cout << s.reversePairs(nums);
// }

// #include<vector>
// using namespace std;
// class Solution {
// private:
//     int help[50001];

//     void merge(vector<int>& nums , int l , int mid , int r){
//         int i = l , j = mid + 1;
//         int k = l;
//         while(i <= mid && j  <= r){
//             help[k++] = nums[i] <= nums[j] ? nums[i++] : nums[j++];
//         }
//         while(i <= mid) help[k++] = nums[i++];
//         while(j <= r)   help[k++] = nums[j++];

//         for(int i = l ; i <= r ; i++){
//             nums[i] = help[i];
//         }
//     }
// public:
//     vector<int> sortArray(vector<int>& nums) {
        
//         int n = nums.size();
//         for(int l , mid , r , step = 1 ; step <= n ; step <<= 1){
//             l = 0;
//             while(l < n){
//                 mid = l + step - 1;
//                 if(mid >= n-1){
//                     break;
//                 }
//                 r = (l + 2 * step - 1) <= n-1 ? (l + 2 * step - 1) : n-1;
//                 merge(nums , l , mid , r);
//                 l = r + 1;
//             }
//         }

//         return  nums;
//     }
// };


// #include<vector>
// #include<random>
// #include<iostream>
// class Solution {
// private:
//     void swap(int& a , int& b){
//         int t = a;
//         a = b;
//         b = t;
//     }

//     int first , last;
//     void partition(std::vector<int>& nums , int l , int r , int x){
//         // if(l >= r)  return;
//         //

//         first = l ;
//         last = r;
//         int i = l;
//         while(i <= last){
//             if(nums[i] < x){
//                 swap(nums[i++] , nums[first++]);
//             }
//             else if(nums[i] == x){
//                 i++;
//             }
//             else {
//                 swap(nums[i] , nums[last--]);
//             }
//         }
//     }
// public:
//     int findKthLargest(std::vector<int>& nums, int k) {
//         int l = 0 , r = nums.size() - 1;
//         int idx = r - k + 1;//第k个最大的数，对应排序后数组索引为r-k+1的数
//         int ans = 0;
//         while(l <= r){

//             int i = (l + r) >> 1;
//             partition(nums , l , r , nums[i]);

//             if(idx < first){
//                 r = first - 1;
//             }
//             else if(idx > last){
//                 l = last + 1;
//             }
//             else{
//                 ans = nums[first];
//                 break;
//             }
//         }

//         return ans;
//     }
// };


// int main()
// {
//     Solution s;
//     std::vector<int> nums = {2 , 1};
//     int k = 2;
//     std::cout << s.findKthLargest(nums , k);
// }



// #include<iostream>
// #include<vector>
// class heap{
// private:
//     void swap(int& a , int& b){
//         int t = a;
//         a = b;
//         b = t;
//     }
// public:
//     void heap_insert(std::vector<int>& arr , int i){
//         // 在i 位置插入一个数，向上调整，维护大根堆
//         while(arr[i] > arr[(i - 1) / 2]){
//             swap(arr[i] , arr[(i - 1) / 2]);
//         }
//     }

//     void heapify(std::vector<int>& arr , int i , int size){
//         //i位置的数发生变化，变小了
//         //向下调整，维护大根堆

//         int l = 2 * i + 1;//左孩子索引
//         while(l < size){

// 			int bigger = (l + 1 < size && arr[l+1] > arr[l] ) ? l + 1 : l;
//             bigger = arr[i] > arr[bigger] ? i : bigger;
//             if(bigger == i) break;

//             swap(arr[i] , arr[bigger]);
//             i = bigger;
//             l = 2 * i + 1;
//         }
//     }
// };


// int main()
// {
//     std::vector<int> arr = { 4 , 3 , 2 , 1 , 2 , 0 , 1};
//     arr[1] = 1;
//     heap H;
//     H.heapify(arr , 1 , 7);
// }

// #include<iostream>
// #include<vector>
// class heap{
// private:
//     void swap(int& a , int& b){
//         int t = a;
//         a = b;
//         b = t;
//     }

// public:
//     void heap_insert(std::vector<int>& arr , int i){
//         while(arr[i] < arr[(i - 1) >> 1]){
//             swap(arr[(i - 1) >> 1] , arr[i]);
//             i = (i - 1) / 2; 
//         }
//     }

//     void heapify(std::vector<int>& arr , int i , int size){

//         int l = 2 * i + 1;
//         while(l < size){
//             int bigger = (l + 1 < size && arr[l + 1] > arr[l]) ? l + 1 : l;
//             bigger = arr[i] > arr[bigger] ? i : bigger;
//             if(i == bigger) break;

//             swap(arr[bigger] , arr[i]);
//             i = bigger;
//             l = 2 * i + 1;
//         }
//     }

//     void heap_sort1(std::vector<int>& arr){
//         //从顶到底
//         int n = arr.size();
//         for(int i = 0 ; i < n ; i++){
//             heap_insert(arr , i);
//         }

//         while(n > 0){
//             swap(arr[0] , arr[--n]);
//             heapify(arr , 0 , n);
//         }
//     }

//     void heap_sort2(std::vector<int>& arr){
//         int n = arr.size();
//         for(int i = n - 1 ; i >= 0 ; --i){
//             heapify(arr , i , n);
//         }

//         while(n > 0){
//             swap(arr[0] , arr[--n]);
//             heapify(arr , 0 , n);
//         }
//     }
// };


// #include<iostream>

// int main()
// {
//     int x = 10;
//     auto f = [x] (int y) -> int { return x + y; }; // 值捕获 x，相当于执行这一行时复制了一份x的值进入了lambda表达式
//     x = 20; // 修改外部的 x
//     std::cout << f(5) << std::endl; // 输出 15，不受外部 x 的影响

//     auto f2 = [&x](int y) {return x + y;} ;  // return type可以省略，由表达式自动推导
//     x = 30;
//     std::cout << f2(5) << std::endl; // 输出35 ， 受外部x的影响

//     auto f3 = [&x]() {x++; return 0;};// 引用捕获可以在lamda表达式内修改参数值
//     f3();
//     std::cout << "x = " << x << std::endl;//31

//     auto f4 = [&](int y) {return x + y;};//对所有外部变量采用引用捕获
//     auto f5 = [=](int y) {return x + y;};//对所有外部变量采用值捕获

//     x = 100;

//     std::cout << "f4 : " << f4(5) << std::endl;// 105
//     std::cout << "f5 : " << f5(5) << std::endl;// 36

//     int a = 10;
//     auto f6 = [& , a](int y){return x + a + y;};//引用捕获所有除了a的变量，值捕获a
//     auto f7 = [= , &a](int y) {return x + a + y;};//值捕获所有除了a的变量

// }


// #include<iostream>
// #include<vector>

// class heap{
// private:
//     void swap(int& a , int& b){
//         int t = a;
//         a = b;
//         b = t;
//     }

// public:
//     void heap_insert(std::vector<int>& arr , int i){
//         while(arr[i] > arr[(i - 1) / 2]){
//             swap(arr[i] , arr[(i - 1) / 2]);
//             i = (i - 1) / 2;
//         }
//     }

//     void heapify(std::vector<int>& arr , int i , int size){
//         int l = 2 * i + 1;
//         while(l < size){
//             int bigger = (l + 1 < size && arr[l] < arr[l + 1]) ? l + 1 : l;
//             bigger = arr[bigger] > arr[i] ? bigger : i;
//             if(bigger == i) break;
//             swap(arr[bigger] , arr[i]);

//             i = bigger;
//             l = 2 * i + 1;
//         }
//     }

//     void heap_sort1(std::vector<int>& arr){
//         int n = arr.size();
//         for(int i = 0 ; i < n ; i++){
//             heap_insert(arr , i);
//         }

//         while(n > 1){
//             swap(arr[0] , arr[--n]);
//             heapify(arr , 0 , n);
//         }
//     }

//     void heap_sort2(std::vector<int>& arr){
//         int n = arr.size();
//         for(int i = n - 1 ; i >= 0 ; --i){
//             heapify(arr , i , n);
//         }

//         while(n > 1){
//             swap(arr[0] , arr[--n]);
//             heapify(arr , 0 , n);
//         }
//     }
// };


// #include<iostream>
// #include<cstdint>
// #include<random>
// #include<ctime>
// #include<cstdlib>
// void gemm(int32_t v0[8][8] , int32_t v1[8][8] , int32_t v2[8][8] ){
//     for(int i = 0 ; i < 8 ; i++){
//         for(int j = 0 ; j < 8 ; j++){
//             for(int k = 0 ; k < 8 ; k++){
//                 v2[i][j] += v0[i][k] * v1[k][j];
//             }
//         }
//     }
// }

// void init(int32_t data[8][8] ){
//             for(int i = 0 ; i < 8 ; i++){
//                 for(int j = 0 ; j < 8 ; j++){
//                     data[i][j] = rand() % 100 - 50; // -50 ~ 50
//                 }
//             }
// }

// void print_matrix(int32_t m[8][8]){
//     for(int i = 0 ; i < 8 ; ++i){
//         for(int j = 0 ; j < 8 ; ++j){
//             std::cout << m[i][j] << ' ';
//         }
//         std::cout << std::endl;
//     }
// }

// int main()
// {
//     srand(time(0));
//     int32_t A[8][8] , B[8][8] , C[8][8];
//     init(A[8][8]);

// }




// #include<iostream>

// int add(int a , int b){
//     return a + b;
// }

// int sub(int a , int b){
//     return a - b;
// }

// void compute_and_print(int (*funct_ptr)(int , int) , int a , int b){
//     std::cout << "Result: " << funct_ptr(a , b) << std::endl;
// }
// int main()
// {
//     compute_and_print(add , 3 , 4);
//     compute_and_print(sub , 3 , 4);

// }


// #include<iostream>
// #include<vector>
// #include<array>
// #include<queue>
// #include<algorithm>
// bool comparator(int a , int b){
//     return a > b;
// }
// int main()
// {
//     // std::array<int , 6> arr = {4, 3, 8, 1, 7, 2};
//     // // std::sort(arr.begin() , arr.end() , comparator);
//     // std::sort(arr.begin() , arr.end() , std::greater<int>());

//     // for(auto it : arr){
//     //     std::cout << it << ' ' ;
//     // }

//     bool (*func_ptr) (int , int) = comparator;
//     std::priority_queue<int , std::vector<int> , decltype(func_ptr) > min_heap(func_ptr);

//     for(int i = 10 ; i >= 0 ; i--){
//         min_heap.push(i);
//     } 

//     while(!min_heap.empty()){
//         std::cout << min_heap.top() << ' ';
//         min_heap.pop();
//     }

//     return 0;

// }


// #include<iostream>
// #include<string>
// #include<unordered_map>
// #include<algorithm>
// int main()
// {
//     std::string s = "hellloooo geek";
//     std::unordered_map<char , int> cnt;
//     int n = s.size();
//     for(int i = 0 ; i < n ; i++){
//         cnt[s[i]]++;
//     }

//     auto comparator = [&](char a , char b){
//         if(cnt[a] == cnt[b]){
//             return a > b;
//         }
//         else{
//             return cnt[a] > cnt[b];
//         }
//     };

//     std::sort(s.begin() , s.end() , comparator);
//     std::cout << s << std::endl;

// }


// #include <iostream>
// #include <queue>
// #include <vector>

// // 仿函数用于比较两个元素，以实现小根堆
// struct MinHeapComparator {
//     bool operator()(int a, int b) {
//         return a > b;
//     }
// };

// int main() {
//     // 使用std::priority_queue和MinHeapComparator仿函数创建小根堆
//     // std::priority_queue<int, std::vector<int>, MinHeapComparator> minHeap;
//     std::priority_queue<int , std::vector<int> , std::greater<int> > minHeap;

//     // 向小根堆添加元素
//     minHeap.push(5);
//     minHeap.push(2);
//     minHeap.push(8);
//     minHeap.push(1);
//     minHeap.push(6);

//     // 打印小根堆
//     while (!minHeap.empty()) {
//         std::cout << minHeap.top() << " ";
//         minHeap.pop();
//     }
//     std::cout << std::endl;

//     return 0;
// }


// #include<iostream>
// #include<vector>
// #include<queue>
// using namespace std;
// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode *next) : val(x), next(next) {}
// };

// class Solution {
// public:
//     ListNode* mergeKLists(vector<ListNode*>& lists) {
//         std::priority_queue<ListNode* , std::vector<ListNode*> , std::greater<ListNode*> > min_heap;

//         for(auto it : lists){
//             if(it != nullptr){
//                 min_heap.push(it);
//             }
//         }

//         if(min_heap.empty())    return nullptr;

//         ListNode* h = min_heap.top();
//         ListNode* cur = h;
//         min_heap.pop();
//         if(h->next != nullptr){
//             min_heap.push(h->next);
//         }

//         while(!min_heap.empty()){
//             ListNode* tmp = min_heap.top();
//             min_heap.pop();
//             cur->next = tmp;
//             cur = cur->next;
//             if(tmp->next != nullptr){
//                 min_heap.push(tmp->next);
//             }
//         }

//         return h;
//     }
// };


// int main()
// {
//     Solution s;

//     ListNode* h1 = new ListNode(1);
//     h1->next = new ListNode(4);
//     h1->next->next = new ListNode(5);
//     h1->next->next->next = nullptr;

//     ListNode* h2 = new ListNode(1);
//     h2->next = new ListNode(3);
//     h2->next->next = new ListNode(4);
//     h2->next->next->next = nullptr;

//     ListNode* h3 = new ListNode(2);
//     h3->next = new ListNode(6);
//     h3->next->next = nullptr;

//     std::vector<ListNode*> lists = {h1 , h2 , h3};

//     ListNode* head = s.mergeKLists(lists);

//     while(head != nullptr){
//         std::cout << head->val << ' ';
//         head = head->next;
//     }

//     return 0;
// }



#include<iostream>
#include<vector>
#include<algorithm>
//用数组模拟大根堆试一试？
class MAX_HEAP{
    public:
        double data[100];
        int size = 0;

        void swap(double& a , double& b){
            double t = a;
            a = b;
            b = t;
        }

    // public:
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

        bool empty(){
            return size == 0;
        }
};
class Solution {
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
        std::cout << "target: " << sum / 2 << std::endl;
        while(reduce <  sum / 2){
            double top = max_heap.top();
            max_heap.pop();
            max_heap.push(top / 2);
            reduce += top / 2;
            step++;

            std::cout << "  top:  " << top << "  reduce:  " << reduce << "  step:  " << step << std::endl;
        }

        return step;

    }
};

int main()
{
    std::vector<int> nums = {92,91,55,74,98,45,94,99,35,28,78,10,27,55,93,93,33,76,14,27,82,11,5,58,96,70,31,6};
    // 99 98 96 94 93 93 92 91 82 78 76 74 70 58 55 55 45 35 33 31 28 27 27 14 11 10 6 5
    // std::vector<int> _nums(nums);
    // std::sort(_nums.begin() , _nums.end() , [&](int a , int b){return a > b;});
    // for(auto it : _nums){
    //     std::cout << it << ' ';
    // }

    // Solution s;
    MAX_HEAP max_heap;
    for(auto it : nums){
        max_heap.push(it);
    }

    while(!max_heap.empty()){
        std::cout << max_heap.top() << ' ';
        max_heap.pop();
    }

    // std::cout << std::endl << s.halveArray(nums);
}