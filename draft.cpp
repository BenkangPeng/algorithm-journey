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

#include<iostream>
#include<cmath>
using namespace std;
class Solution {
private:
    bool is_prime(int n){
        if(n <= 1)  return false;
        if(n == 2)  return true;
        if(!(n%2))  return false;

        for(int i = 3 ; i <= (int)sqrt(n) ; i += 2){
            if(n%i == 0) return false;
        }
        return true;
    }

    bool is_palindrome(int n){
        int reverse = 0;
        int _n = n;
        while(n > 0){
            int t = n % 10;
            n /= 10;
            reverse = reverse * 10 + t;
        }

        return reverse == _n ? true : false;
    }
public:
    int primePalindrome(int n) {
        for(int root = )
    }
};

int main()
{
    int n = 6;
    Solution s;
    cout << s.primePalindrome(n) << endl; 
}