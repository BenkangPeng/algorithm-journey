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



### class019 输入输出

* 填函数风格

例如`leecode`

* acm风格（笔试、比赛最常见）

  * 规定数据量(BufferedReader、StreamTokenizer、PrintWriter)，其他语言有对等的写法

  * 按行读(BufferedReader、PrintWriter)，其他语言有对等的写法(cpp中用printf、scanf比cin、cout更快)

  * 不要用Scanner、System.out，IO效率慢(输出答案要一次输出，不要边运行程序边输出，一旦后台检测到输出，就会开始对比，频繁启动对比耗时比最后一次性进行对比多)。

* 不推荐：临时动态空间(①申请、释放空间耗时；②释放的空间后台仍会记录到内存消耗中：例如，在程序中，先开辟1MB的空间，使用完后释放，再开辟2MB空间，再释放，其实我们使用的空间最大是2MB，但后台不会检测是否释放，会认定使用的空间是3MB)

* 推荐：全局静态空间





### class022 归并分治

* 思考一个问题在大范围上的答案，是否等于，左部分的答案 + 右部分的答案 + 跨越左右产生的答案
* 计算“跨越左右产生的答案”时，如果加上左、右各自有序这个设定，会不会获得计算的便利性
* 如果以上两点都成立，那么该问题很可能被归并分治解决（话不说满，因为总有很毒的出题人）



### class025

堆排序的时间复杂度 ==待整理==



###　class026 比较器





#### lambda表达式

语法：

> [捕获列表] (参数列表) -> 返回类型{函数主体}
>
> [capture list] (parameter list) -> return type {function body}



* 捕获列表可以捕获`lambda`表达式外的变量，分为`值捕获`和`引用捕获`

```cpp
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
```







