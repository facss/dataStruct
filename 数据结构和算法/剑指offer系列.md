
# 剑指offer

这里将剑指offer单独拿出来是因为考核的频率不一样，目前大厂的考核里，这部分出现的频率很高

## chap 1 . 数组和字符串

<details>
<summary> 二维数组中的查找</summary>

**描述**
        
在一个二维数组array中（每个一维数组的长度相同），每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
    [
    [1,2,8,9],
    [2,4,9,12],
    [4,7,10,13],
    [6,8,11,15]
    ]
    给定 target = 7，返回 true。
    给定 target = 3，返回 false。
    0 <= array.length <= 500
    0 <= array[0].length <= 500
    你能给出时间复杂度为O(m+n) 的解法吗？（n,m为矩阵的长和宽）

+ 示例1
 
    输入：
    7,[[1,2,8,9],[2,4,9,12],[4,7,10,13],[6,8,11,15]]

    返回值：true

   说明：存在7，返回true

+ 示例2

    输入：
    3,[[1,2,8,9],[2,4,9,12],[4,7,10,13],[6,8,11,15]]
    
    返回值：
    false
 
    说明：
        不存在3，返回false 

**思路**
其实这是个二维情况下的二分法，一般我们的一维情况下，二分法直接找的是数组中间的那个位置，但是现在在二维空间中，怎么找到中间那个位置呢？由于该二维数组具有规律性，从左到右逐渐变大，从上到下逐渐变大，因此我们可以类比，中间的那个位置其实就是在整个数组的最右上角的那个位置。有了这个关键点之后，后续的做法就和一维数组下的二分查找很类似了。算法的空间复杂度O(1),时间复杂度O(n+m)

**题解代码：**
```
 class Solution {
 public:
     bool Find(int target, vector > array) {
         int rows = array.size();
         if(rows == 0) {
             return true;
         }
         int cols = array[0].size();
         int i = 0,j = cols - 1;
         while(j >=0 && i < rows) {
             if(array[i][j] == target) {
                 return true;
             } else if(array[i][j] > target){
                 --j;
             } else {
                 ++i;
             }
         }
         return false;
     }
 };
 
```
</details>

<details>
<summary>旋转数组的最小数字</summary>
把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。输入一个递增排序的数组的一个旋转，输出旋转数组的最小元素。例如，数组 [3,4,5,1,2] 为 [1,2,3,4,5] 的一个旋转，该数组的最小值为1。  

示例 1：

输入：[3,4,5,1,2]
输出：1
示例 2：

输入：[2,2,2,0,1]
输出：0

**思路**
我们考虑数组中的最后一个元素 x：在最小值右侧的元素，它们的值一定都小于等于 x；而在最小值左侧的元素，它们的值一定都大于等于 x。因此，我们可以根据这一条性质，通过二分查找的方法找出最小值。

在二分查找的每一步中，左边界为low，右边界为high，区间的中点为 pivot，最小值就在该区间内。我们将中轴元素 numbers[pivot] 与右边界元素 numbers[high] 进行比较，可能会有以下的三种情况：

第一种情况是 numbers[pivot]< numbers[high]。如下图所示，这说明numbers[pivot] 是最小值右侧的元素，因此我们可以忽略二分查找区间的右半部分。

第二种情况是 numbers[pivot]>numbers[high]。如下图所示，这说明 numbers[pivot] 是最小值左侧的元素，因此我们可以忽略二分查找区间的左半部分。

第三种情况是 numbers[pivot]==numbers[high]。如下图所示，由于重复元素的存在，我们并不能确定 numbers[pivot] 究竟在最小值的左侧还是右侧，因此我们不能莽撞地忽略某一部分的元素。我们唯一可以知道的是，由于它们的值相同，所以无论 numbers[high] 是不是最小值，都有一个它的「替代品」numbers[pivot]，因此我们可以忽略二分查找区间的右端点。


```
class Solution {
public:
    int minArray(vector<int>& numbers) {
        int low = 0;
        int high = numbers.size() - 1;
        //用开区间法，左闭右开
        while (low < high) {
            int pivot = low + (high - low) / 2;
            if (numbers[pivot] < numbers[high]) {
                high = pivot;
            }
            else if (numbers[pivot] > numbers[high]) {
                low = pivot + 1;
            }
            else {//这里主要是重复的元素出现的情况
                high -= 1;
            }
        }
        return numbers[low];
    }
};

```
</details>


<details>
<summary> 替换空格</summary>

**描述**

    请实现一个函数，将一个字符串中的每个空格替换成“%20”。例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。
    给定的字符串长度不超过100。保证字符串中的字符为大写英文字母、小写英文字母和空格中的一种。
**示例1**
+ 输入：
        "We Are Happy"
+ 返回值：
        "We%20Are%20Happy"

**思路**

步骤为：扩容，移动。第一步扩容，可以再原数组中，也可以开辟一个新的string，个人觉得开辟一个新的string更省事些，先查看一下数组中的空格个数，然后在数组的末尾扩充相应的空间，此时遍历一遍，O(n)的复杂度。此时肯定不能从头开始移动，因为新增的空格是在后面，因而从后面往前进行移动。又是一个O(n)的时间复杂度。

**题解代码：**

```
    string replaceSpace(string s) {
         // write code here
         string ans;
         for(auto &c : s) {
             if(c == ' ') {
                 ans.append("%20");
             } else {
                 ans.push_back(c);
             }
         }
         return ans;
     }
     
```
</details>
<details>
<summary> 调整数组顺序使奇数位于偶数前面</summary>

**描述**

    输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有的奇数位于数组的前半部分，所有的偶数位于数组的后半部分，并保证奇数和奇数，偶数和偶数之间的相对位置不变。

**示例1**
+ 输入：
    [1,2,3,4]
+ 返回值
    [1,3,2,4]

**示例2**

+ 输入：
        [2,4,6,5,7]
+ 返回值：
        [5,7,2,4,6]
    
**思路：** 如果该题没有要保序，那么其实代码可以如下，和颜色分类的题目是类似的，但是这样的交换其实是不保序的，时间复杂度O(n),空间复杂度O(1)：
```
 class Solution {
 public:
 vector<int> exchange(vector<int>& nums) {
    int count = 0;
    for(int i = 0;i < nums.size();++i) {
        if(nums[i] %2 ) {
            swap(nums[count++],nums[i]);
        }
    }
    return nums;
    }
 };

``` 
    保序的情况，本题的核心在于一个思想，其实就是元素应该放置的位置，原本应该放置的位置，这个核心的思路就是冒泡排序中核心的思路。和颜色分类的问题也是类似的，这类问题本质来说就是按着原有的顺序进行排序。因为冒泡排序是保序的，所以直接拿过来用。这里有个trick，就是可以利用标志法来做冒泡，算法复杂度是O(n^2)。
    题解一：
```
    vector reOrderArray(vector& array) {
        // write code here
        int len = array.size();
        bool flag = true;
        while(flag) {
            flag = false;
            for(int i = 1;i < len ;++i) {
                //if(array[i-1] > array[i] ) {原始冒泡排序的判断条件
                if (array[i -1] % 2 == 0 && array[i] %2) {
                    flag = true;
                    swap(array[i-1],array[i]);
                }
            }
        }
        return array;
    }

    当然如果只关注时间复杂度的话，本题最简单的还是直接开辟出一个新的数组，时间复杂度O(n)，空间复杂度O(n)：
    vector reOrderArray(vector& array) {
        // write code here
        vector<int> ans;
        for(int i = 0;i < array.size();++i) {
            if(array[i] % 2 ) {
                ans.push_back(array[i]);
            }
        }
        for(int i = 0;i < array.size();++i) {
            if(array[i] % 2 == 0) {
                ans.push_back(array[i]);
            }
        }
        return ans;
    }
     
```
</details>

<details>
<summary>数组中出现次数超过一半的数字</summary>

数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。

你可以假设数组是非空的，并且给定的数组总是存在多数元素。

 
+ 示例 1:

    输入: [1, 2, 3, 2, 2, 2, 5, 4, 2]
输出: 2

限制：

1 <= 数组长度 <= 50000

```
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int len = nums.size();
        unordered_map<int,int> mp;
        for(int i = 0;i < len;++i) {
            mp[nums[i]]++;
            if(mp[nums[i]] > len / 2) {
                return nums[i];
            } 
        }
        return -1;
    }
};

```

</details>



<details>

<summary>连续子数组的最大和</summary>
输入一个整型数组，数组中的一个或连续多个整数组成一个子数组。求所有子数组的和的最大值。

要求时间复杂度为O(n)。

+ 示例1:

    输入: nums = [-2,1,-3,4,-1,2,1,-5,4]
    输出: 6
    解释: 连续子数组 [4,-1,2,1] 的和最大，为 6。
 
+ 提示：

    1 <= arr.length <= 10^5
    -100 <= arr[i] <= 100
**思路**
本题的解法很多，可以利用动态规划，也可以利用贪心

```
//贪心的解法
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int len = nums.size();
        int max_val = INT_MIN;
        int sum = 0;
        for(int j =0;j < len;++j) {
            sum += nums[j];
            if(sum < nums[j]) {//一旦出现往右加，反而比原来的少，就直接以后续的值为结果
                sum = nums[j];
            } 
            max_val = sum > max_val ? sum : max_val;
        }
        return max_val;
    }
};

```

</details>


<details>
<summary>把数组排成最小的数</summary>
输入一个正整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个。例如输入数组{3，32，321}，则打印出这三个数字能排成的最小数字为321323。

**思路**
本质上讲这个题目就是要做排序，只不过这里的排序需要题目要求的来

```
//利用sort函数，然后定义我们自己的排序
class Solution {
public:
    string minNumber(vector<int>& nums) {
        int len = nums.size();
        if(len == 0) {
            return "";
        }
        sort(nums.begin(),nums.end(),[] (int a,int b) {
            string A = std::to_string(a) + std::to_string(b);
            string B = std::to_string(b) + std::to_string(a);
            return A < B ;
        });
        string res;
        for(auto & num: nums) {
            res += std::to_string(num);
        }
        return res;
    }

};
//思路2，自己写快速排序的代码，然后再进行修改
```

</details>

<details>
<summary>数组中的逆序对</summary>
在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。输入一个数组,求出这个数组中的逆序对的总数P。并将P对1000000007取模的结果输出。 即输出P%1000000007。

+ 示例 1:

    输入: [7,5,6,4]
    输出: 5

输入描述：

题目保证输入的数组中没有的相同的数字

数据范围：

对于%50的数据,size<=10^4
对于%75的数据,size<=10^5
对于%100的数据,size<=2*10^5

**思路**
分治思想，采用归并排序的思路来处理，如下图，先分后治：

先把数组分解成两个长度为2的子数组，再把这两个子数组分解成两个长度为1的子数组。接下来一边合并相邻的子数组，一边统计逆序对的数目。在第一对长度为1的子数组{7}、{5}中7>5，因此（7,5）组成一个逆序对。同样在第二对长度为1的子数组{6}，{4}中也有逆序对（6,4），由于已经统计了这两对子数组内部的逆序对，因此需要把这两对子数组进行排序，避免在之后的统计过程中重复统计。

```
class Solution {
public:
    int InversePairs(vector<int> data) {
        if(data.size() == 0){
            return 0;
        }
        // 排序的辅助数组
        vector<int> copy;
        for(int i = 0; i < data.size(); ++i){
            copy.push_back(data[i]);
        }
        return InversePairsCore(data, copy, 0, data.size() - 1) % 1000000007;
    }
    long InversePairsCore(vector<int> &data, vector<int> &copy, int begin, int end){
        // 如果指向相同位置，则没有逆序对。
        if(begin == end){
            copy[begin] = data[end];
            return 0;
        }
        // 求中点
        int mid = (end + begin) >> 1;
        // 使data左半段有序，并返回左半段逆序对的数目
        long leftCount = InversePairsCore(copy, data, begin, mid);
        // 使data右半段有序，并返回右半段逆序对的数目
        long rightCount = InversePairsCore(copy, data, mid + 1, end);
        
        int i = mid; // i初始化为前半段最后一个数字的下标
        int j = end; // j初始化为后半段最后一个数字的下标
        int indexcopy = end; // 辅助数组复制的数组的最后一个数字的下标
        long count = 0; // 计数，逆序对的个数，注意类型
        
        while(i >= begin && j >= mid + 1){
            if(data[i] > data[j]){
                copy[indexcopy--] = data[i--];
                count += j - mid;
            }
            else{
                copy[indexcopy--] = data[j--];
            }
        }
        for(;i >= begin; --i){
            copy[indexcopy--] = data[i];
        }
        for(;j >= mid + 1; --j){
            copy[indexcopy--] = data[j];
        }
        return leftCount + rightCount + count;
    }
};

```
</details>

<details>
<summary>构建乘积数组</summary>
给定一个数组A[0,1,...,n-1],请构建一个数组B[0,1,...,n-1],其中B中的元素B[i]=A[0]*A[1]*...*A[i-1]*A[i+1]*...*A[n-1]。不能使用除法。

```

```
</details>

<details>
<summary>数字在排序数组中出现的次数</summary>
一个整型数组 nums 里除两个数字之外，其他数字都出现了两次。请写程序找出这两个只出现一次的数字。要求时间复杂度是O(n)，空间复杂度是O(1)。

 

示例 1：

输入：nums = [4,1,4,6]
输出：[1,6] 或 [6,1]
示例 2：

输入：nums = [1,2,10,4,1,4,3,3]
输出：[2,10] 或 [10,2]
**思路**
让我们先来考虑一个比较简单的问题：
如果除了一个数字以外，其他数字都出现了两次，那么如何找到出现一次的数字？
答案很简单：全员进行异或操作即可。考虑异或操作的性质：对于两个操作数的每一位，相同结果为 00，不同结果为 11。那么在计算过程中，成对出现的数字的所有位会两两抵消为 00，最终得到的结果就是那个出现了一次的数字。
那么这一方法如何扩展到找出两个出现一次的数字呢？
如果我们可以把所有数字分成两组，使得：
两个只出现一次的数字在不同的组中；
相同的数字会被分到相同的组中。
那么对两个组分别进行异或操作，即可得到答案的两个数字。这是解决这个问题的关键。
那么如何实现这样的分组呢？

​
在实际操作的过程中，我们拿到序列的异或和 xx之后，对于这个「位」是可以任取的，只要它满足 x_i = 1x 
i=1。但是为了方便，这里的代码选取的是「不为 00 的最低位」，当然你也可以选择其他不为 0 的位置。


**算法**

先对所有数字进行一次异或，得到两个出现一次的数字的异或值。
在异或结果中找到任意为 1 的位。

根据这一位对所有的数字进行分组。

在每个组内进行异或操作，得到两个数字。


```
class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        int ret = 0;
        for (int n : nums)
            ret ^= n;//全员亦或，找到目标的a和b的亦或结果
        int div = 1;
        while ((div & ret) == 0)//二进制中，找到第一位不是0的，核心要点就是要区分出b和a
            div <<= 1;
        int a = 0, b = 0;
        for (int n : nums)//最后再根据该位是否为0将全员分为两组
            if (div & n)
                a ^= n;
            else
                b ^= n;
        return vector<int>{a, b};
    }
};


```

变形题：在一个数组 nums 中除一个数字只出现一次之外，其他数字都出现了三次。请找出那个只出现一次的数字。

+ 示例 1：

    输入：nums = [3,4,3,3]
    输出：4
    
+ 示例 2：

    输入：nums = [9,1,7,9,7,9,7]
    输出：1

```

```
</details>

<details>

<summary> 顺时针打印矩阵</summary>

**描述**

输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字，例如，如果输入如下4 X 4矩阵：
        [[1,2,3,4],[5,6,7,8],[9,10,11,12],[13,14,15,16]]
    则依次打印出数字
        [1,2,3,4,8,12,16,15,14,13,9,5,6,7,11,10]
**示例1**

+ 输入：

    [[1,2],[3,4]]

+ 返回值：

    [1,2,4,3]

思路：本题主要就是一个模拟过程，首先需要注意的是数据的规模问题，有些情况是可能出现一行或者一列的，实际上出现逆向遍历是因为出现了多行或者多列的情况，例如从右到左是因为出现了多行的情况，以及从下到上是因为出现了多列，那么一旦只有一行，那么就无需从下到上，只有一列也不需要反向再回去从右到左。整体遍历的时候需要注意边界的情况。
    题解代码:
```
class Solution {
public:
    vector printMatrix(vector > matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector res;
        if(rows == 0 || cols == 0) {
            return res;
        }
        int left = 0,right = cols - 1,top = 0,bottom = rows - 1;
        while(left <= right && top <= bottom) {
            //left to right,区间范围[left,right]
            for(int i = left;i <= right;++i) {
                res.push_back(matrix[top][i]);
            }
            //top to bottom 区间范围(top,bottom]
            for(int i = top + 1;i <= bottom;++i) {
                res.push_back(matrix[i][right]);
            }
            //right to left 区间范围 (right,left]
            if (top != bottom) {//避免
                for(int i = right - 1;i >= left;--i) {
                    res.push_back(matrix[bottom][i]);
                    }
            }
            //bottom to top (bottom,top)
            if (left != right) {
                for(int i = bottom - 1;i > top;--i) {
                    res.push_back(matrix[i][left]);
                    }
            }
            ++top;++left;--right;--bottom;        
        }
        return res;
    }
};
     
```  
</details>
