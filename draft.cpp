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


#include<iostream>

int main()
{
    int x = 10;
    auto f = [x] (int y) -> int { return x + y; }; // 值捕获 x，相当于执行这一行时复制了一份x的值进入了lambda表达式
    x = 20; // 修改外部的 x
    std::cout << f(5) << std::endl; // 输出 15，不受外部 x 的影响

    auto f2 = [&x](int y) {return x + y;} ;  // return type可以省略，由表达式自动推导
    x = 30;
    std::cout << f2(5) << std::endl; // 输出35 ， 受外部x的影响

    auto f3 = [&x]() {x++; return 0;};// 引用捕获可以在lamda表达式内修改参数值
    f3();
    std::cout << "x = " << x << std::endl;//31

    auto f4 = [&](int y) {return x + y;};//对所有外部变量采用引用捕获
    auto f5 = [=](int y) {return x + y;};//对所有外部变量采用值捕获

    x = 100;

    std::cout << "f4 : " << f4(5) << std::endl;// 105
    std::cout << "f5 : " << f5(5) << std::endl;// 36

    int a = 10;
    auto f6 = [& , a](int y){return x + a + y;};//引用捕获所有除了a的变量，值捕获a
    auto f7 = [= , &a](int y) {return x + a + y;};//值捕获所有除了a的变量

}