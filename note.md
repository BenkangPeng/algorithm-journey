### 插入排序

第一次写成了：

```cpp
template <typename T>
        std::vector<T> insert_sort(const std::vector<T>& arr){
            int len = arr.size();
            if(len < 2) return arr;

            std::vector<T> _arr(arr);

            for(int i = 1 ; i < len ; i++){
                for(int j = i-1 ; j >= 0; j--){
                    if(_arr[j] > _arr[j+1])
                    	swap(_arr[j] , _arr[j+1]);
                }
            }

            return _arr;
        }
```

* 这样写当然也行，但写成这样可以省去一些计算

```cpp
template <typename T>
        std::vector<T> insert_sort(const std::vector<T>& arr){
            int len = arr.size();
            if(len < 2) return arr;

            std::vector<T> _arr(arr);

            for(int i = 1 ; i < len ; i++){
                for(int j = i-1 ; j >= 0 && _arr[j] > _arr[j+1]; j--){
                    swap(_arr[j] , _arr[j+1]);
                }
            }

            return _arr;
        }
```

* 将判断条件`_arr[j] > _arr[j+1]`放在`for`循环中，若`_arr[j] < _arr[j+1]`，那`_arr[j+1]`左边的数一定都比它小了，不需要向右插入了。



### 循环队列

* 队列长度要多开辟一段空间(`len = k + 1`)
* 队列满时判断条件`(rear+1)%len == front`
* 队列取队尾的数时`return q[(rear-1+len)%len]`

```cpp
// https://leetcode.cn/problems/design-circular-queue/

class MyCircularQueue {
private:
    int* q;
    int len;
    int front = 0 , rear = 0;

public:
    MyCircularQueue(int k): len(k+1) {
        q = new int[k+1];
    }
    
    bool enQueue(int value) {
        if((rear+1)%len == front){
            return false;
        }
        else{
            q[rear] = value;
            rear = (rear + 1) % len;
            return true;
        }
    }
    
    bool deQueue() {
        if(front == rear)   return false;
        else{
            front = (front + 1) % len;
            return true;
        }
    }
    
    int Front() {
        if(front == rear)   return -1;
        else    return q[front];
    }
    
    int Rear() {
        if(front == rear)   return -1;
        else return q[(rear-1+len) % len];
    }
    
    bool isEmpty() {
        if(front == rear)   return true;
        else return false;
    }
    
    bool isFull() {
        if((rear+1)%len == front)   return true;
        else return false;
    }
};
```



### 用栈模拟队列

这道题的`in2out`方法的设计简直太绝了！！！

时间复杂度是O(1)：对于每一个数，`push`和`pop`最多经历4次出入栈，复杂度为O(1)

[232. 用栈实现队列 - 力扣（LeetCode）](https://leetcode.cn/problems/implement-queue-using-stacks/)

[225. 用队列实现栈 - 力扣（LeetCode）](https://leetcode.cn/problems/implement-stack-using-queues/submissions/536758851/)

```cpp
class MyQueue {

private:
    std::stack<int> in;//in用来入队列，out用来出队列
    std::stack<int> out;
    void in2out(){
        // 倒数据
		// 从in栈，把数据倒入out栈
		// 1) out空了，才能倒数据
		// 2) 如果倒数据，in必须倒完

        if(out.empty()){
            while(!in.empty()){
                int x = in.top();
                in.pop();
                out.push(x);
            }
        }
    }
public:
    MyQueue() {

    }
    
    void push(int x) {
        in2out();
        in.push(x);
    }
    
    int pop() {
        in2out();
        int x = out.top();
        out.pop();
        return x;
    }
    
    int peek() {
        in2out();
        return out.top();
    }
    
    bool empty() {
        return in.empty() && out.empty();
    }
};
```



















