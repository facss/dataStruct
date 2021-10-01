
# 剑指offer

这里将剑指offer单独拿出来是因为考核的频率不一样，目前大厂的考核里，这部分题目以及相应的变形题出现的频率很高

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
<summary>【hard】数组中的逆序对</summary>
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

![分治法](https://github.com/facss/lzy2lcyDocs/blob/master/%E6%95%B0%E6%8D%AE%E7%BB%93%E6%9E%84%E5%92%8C%E7%AE%97%E6%B3%95/imgs/basis_35_1.png)

![basis_35_1.png](https://i.loli.net/2021/09/21/lmMUKTg9ecYdzf3.png)

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
            if(data[i] > data[j]){//进行合并的时候需要计算一下逆序的结果
                copy[indexcopy--] = data[i--];//在进行右边的数据合并的时候要记得把逆序数加和
                count += j - mid;//利用下标进行累加
            }
            else{
                copy[indexcopy--] = data[j--];
            }
        }
        //一旦出现前面的数组比后面的数组长，则把剩余的结果拷贝过去
        for(;i >= begin; --i){
            copy[indexcopy--] = data[i];
        }
        //这里是后面的数组比前面的数组长
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

**思路**
本题可以绘制相应的二纬表格进行推理,构造出来两个数组，然后分别相乘即可。

```
class Solution {
public:
    vector<int> constructArr(vector<int>& a) {
        int len = a.size();
        if(len == 0) {
            return {};
        }
        vector<int> arr1(a.begin(),a.end()),arr2(a.begin(),a.end()),res;
        arr1[0] = 1;
        arr2[len - 1] = 1;
        for(int i = 1;i < len ;++i) {
            arr1[i] = arr1[i-1] * a[i-1];
            arr2[len - 1 - i] = arr2[len - i] * a[len - i];
        }

        for(int i = 0;i < len;++i) {
            res.push_back(arr1[i] * arr2[i]);
        }
        return res;
    }
};

```
</details>

<details>
<summary>数组中数字出现的次数</summary>

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
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(auto& num : nums) {
            mp[num]++;
        }
        for(auto& [k,v]: mp) {
            if(v == 1) {
                return k;
            } 
        }
        return -1;
    }
};

```
</details>
<details>

<summary>排序数组中只出现一次的数字</summary>

给定一个只包含整数的有序数组 nums ，每个元素都会出现两次，唯有一个数只会出现一次，请找出这个唯一的数字。

+ 示例 1:

    输入: nums = [1,1,2,3,3,4,4,8,8]
    输出: 2

+ 示例 2:

输入: nums =  [3,3,7,7,10,11,11]
输出: 10

提示:

1 <= nums.length <= 105
0 <= nums[i] <= 105

```
O(n)的解法,利用亦或
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int ret = 0;
        for(auto & num : nums) {
            ret ^= num;
        }
        return ret;
    }
};
```
![tupian](https://pic.leetcode-cn.com/1630467212-hQBvAE-3c432ff0c7741e9f215c187bdd326da.jpg)

要求O(logn)时间复杂度，就用二分查找，不过这里的二分要按照两个数字作为一对，因为由于单个数字的介入，导致了数据出现了一对中有不一致的情况，如果没有单个数字，那么每一对数据都是完全一样的，也即是说我们只要找到了不一致的第一对数组，就可以得到结果。
```
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int len = nums.size();
        int left = 0, right = len / 2 -1 ;//这里是以一对作为一组元素
        while(left <= right) {//利用闭区间来做
            int mid = left + (right - left) / 2;
            int i = 2 * mid;//一对数据的左边
            if(nums[i] != nums[i + 1]) {
                if(i == 0 || nums[i-1] == nums[i-2]) {//找到了第一个不同的位置
                    return nums[i];
                }
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return nums.back();
    }
};
```
</details>

<details>
<summary>数组中重复的数字</summary>
找出数组中重复的数字。


在一个长度为 n 的数组 nums 里的所有数字都在 0～n-1 的范围内。数组中某些数字是重复的，但不知道有几个数字重复了，也不知道每个数字重复了几次。请找出数组中任意一个重复的数字。

示例 1：

输入：
[2, 3, 1, 0, 2, 5, 3]
输出：2 或 3 

```
class Solution {
public:
    int countRange(vector<int> nums, int left,int right) {
        int len = nums.size();
        if(len== 0) {
            return 0;
        }
        int count = 0;
        for(int i =0;i < len;++i) {
            if(nums[i] >= left && nums[i] <= right) {
                ++count;
            }
        }
        return count;
    }
    int findRepeatNumber(vector<int>& nums) {
        //题解1，要求时间最佳，空间次要，数组位置不可移动，则用hashmap, 时间复杂度o(n),空间复杂度o(n)
        /*
        unordered_map<int,int> mp;
        for(auto& num:nums) {
            if(mp.count(num)) {
                return num;
            } else {
                mp[num]++;
            }
        }
        return -1;
        */
        //解法2，要求空间最佳，时间不能太差，数组位置可移动，先用排序，再判断相邻的元素是否想相等
        //时间复杂度o(nlogn),空间复杂度o(1)
        /*
        sort(nums.begin(),nums.end());
        for(int i = 0;i < nums.size()-1; ++i) {
            if(nums[i] == nums[i+1] ) {
                return nums[i];
            }
        }
        return -1;*/
        //解法3.空间复杂度o(1),时间复杂度o(n),数组可以移动，不用额外分配内存
        //i表示索引下标就是应该放置的位置， nums[i]表示数组索引下的元素，nums[nums[i]]表示数组nums[i]应该放置的位置
        //nums[i]是自家的萝卜，nums[nums[i]]是别人家的萝卜,i是原本自家的萝卜应该有的样子
        /*
        for(int i = 0;i < nums.size();++i) {
            while(nums[i] != i) {
                if(nums[i] == nums[nums[i]]) {
                    return nums[i];
                }
                swap(nums[i],nums[nums[i]]);
            }
        }
        return -1;
        */
        //解法4.如果要求空间复杂度o(1)，空间复杂度O(nlogn),不能移动数组,用二分法
        int left = 1,right = nums.size() - 1;
        while(left <= right) {
            int mid = ((right - left) >> 1) + left;
            int count = countRange(nums,left,mid);
            if(left == right) {
                if(count > 1) {
                    return left;
                } else {
                    break;
                }
            }
            if(count > (mid - left + 1)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return -1;
         
    }
};
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
        if(rows == 0) {
            return {};
        }
        int cols = matrix[0].size();
        vector<int> res;
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

<details>
<summary>【hard】字符串的排列</summary>
输入一个字符串，打印出该字符串中字符的所有排列。

你可以以任意顺序返回这个字符串数组，但里面不能有重复元素。

+ 示例:

    输入：s = "abc"
    输出：["abc","acb","bac","bca","cab","cba"]

**需要用到回溯法**

```
class Solution {
public:
    vector<string> rec;
    vector<int> vis;

    void backtrack(const string& s, int i, int n, string& perm) {
        if (i == n) {
            rec.push_back(perm);
            return;
        }
        for (int j = 0; j < n; j++) {
            if (vis[j] || (j > 0 && !vis[j - 1] && s[j - 1] == s[j])) {
                continue;
            }
            vis[j] = true;
            perm.push_back(s[j]);
            backtrack(s, i + 1, n, perm);
            perm.pop_back();
            vis[j] = false;
        }
    }

    vector<string> permutation(string s) {
        int n = s.size();
        vis.resize(n);
        sort(s.begin(), s.end());
        string perm;
        backtrack(s, 0, n, perm);
        return rec;
    }
};
```
</details>

<details>
<summary>左旋转字符串</summary>

字符串的左旋转操作是把字符串前面的若干个字符转移到字符串的尾部。请定义一个函数实现字符串左旋转操作的功能。比如，输入字符串"abcdefg"和数字2，该函数将返回左旋转两位得到的结果"cdefgab"。

+ 示例 1：

    输入: s = "abcdefg", k = 2
    输出: "cdefgab"

+ 示例 2：

    输入: s = "lrloseumgh", k = 6
    输出: "umghlrlose"

```
class Solution {
public:
    string reverseLeftWords(string s, int n) {
        reverse(s.begin(),s.begin() + n);
        reverse(s.begin() + n,s.end());
        reverse(s.begin(),s.end());
        return s;
    }
};
```

</details>

<details>
<summary>第一个只出现一次的字符</summary>
在字符串 s 中找出第一个只出现一次的字符。如果没有，返回一个单空格。 s 只包含小写字母。

示例 1:

输入：s = "abaccdeff"
输出：'b'
示例 2:

输入：s = "" 
输出：' '

```
class Solution {
public:
    char firstUniqChar(string s) {
        unordered_map<char,int> mp;
        for(auto & c : s) {
            mp[c]++;
        }
        for(auto & c : s) {
            if(mp[c] == 1) {
                return c;
            }
        }
        return ' ';
    }
};
```
</details>

<details>
<summary>翻转单词顺序</summary>
输入一个英文句子，翻转句子中单词的顺序，但单词内字符的顺序不变。为简单起见，标点符号和普通字母一样处理。例如输入字符串"I am a student. "，则输出"student. a am I"。

+ 示例 1：

    输入: "the sky is blue"
    输出: "blue is sky the"
+ 示例 2：

    输入: "  hello world!  "
    输出: "world! hello"
    解释: 输入字符串可以在前面或者后面包含多余的空格，但是反转后的字符不能包括。
+ 示例 3：

    输入: "a good   example"
    输出: "example good a"
    解释: 如果两个单词间有多余的空格，将反转后单词间的空格减少到只含一个。

```
class Solution {
public:
    string reverseWords(string s) {
        stack<string> st;
        int len = s.size();
        string tmp_s;
        for(int i = 0;i <= len;++i) {   
            if(s[i] != ' ' && s[i] != '\0') {
                tmp_s += s[i];
            } else {
                st.push(tmp_s);
                tmp_s="";
            }
        }
        string res;
        while(!st.empty()) {
            string ss = st.top();
            if (ss=="") {
                st.pop();
                continue;
            }
            res += ss + ' ';
            st.pop();
        }
        res.pop_back();
        return res;
    }
};
```
</details>

<details>
<summary>字符串转换成整数</summary>
写一个函数 StrToInt，实现把字符串转换成整数这个功能。不能使用 atoi 或者其他类似的库函数。 

首先，该函数会根据需要丢弃无用的开头空格字符，直到寻找到第一个非空格的字符为止。

当我们寻找到的第一个非空字符为正或者负号时，则将该符号与之后面尽可能多的连续数字组合起来，作为该整数的正负号；假如第一个非空字符是数字，则直接将其与之后连续的数字字符组合起来，形成整数。

该字符串除了有效的整数部分之后也可能会存在多余的字符，这些字符可以被忽略，它们对于函数不应该造成影响。

注意：假如该字符串中的第一个非空格字符不是一个有效整数字符、字符串为空或字符串仅包含空白字符时，则你的函数不需要进行转换。

在任何情况下，若函数不能进行有效的转换时，请返回 0。

说明：

假设我们的环境只能存储 32 位大小的有符号整数，那么其数值范围为 [−231,  231 − 1]。如果数值超过这个范围，请返回  INT_MAX (231 − 1) 或 INT_MIN (−231) 。

+ 示例 1:

    输入: "42"
    输出: 42
+ 示例 2:

    输入: "   -42"
    输出: -42
    解释: 第一个非空白字符为 '-', 它是一个负号。
         我们尽可能将负号与后面所有连续出现的数字组合起来，最后得到 -42 。
+ 示例 3:

    输入: "4193 with words"
    输出: 4193
    解释: 转换截止于数字 '3' ，因为它的下一个字符不为数字。
+ 示例 4:

    输入: "words and 987"
    输出: 0
    解释: 第一个非空字符是 'w', 但它不是数字或正、负号。
        因此无法执行有效的转换。
+ 示例 5:

    输入: "-91283472332"
    输出: -2147483648
    解释: 数字 "-91283472332" 超过 32 位有符号整数范围。 
         因此返回 INT_MIN (−231) 。

```
class Solution {
public:
    int strToInt(string str) {
        if(str.empty()) return 0;
        if(str[0] >= 'a' && str[0] <= 'z') {
            return 0;
        }
        int i = 0;//索引下标
        long res = 0;
        //空格
        while(str[i] == ' ') {
            ++i;
        }
        int sign = 1;
        //负号
        if(str[i] == '-') {
            sign = -1;
            ++i;
        } else if (str[i] == '+') {//正符号
            ++i;
        }
        //正式循环
        while(i < str.size()) {
            if(str[i] >= '0' && str[i] <= '9') {
                res = res * 10 + sign * (str[i] - '0');
                //超出范围就停止循环,防止溢出
                if(res > INT_MAX) {
                    return INT_MAX;
                } else if (res < INT_MIN) {
                    return INT_MIN;
                }
            } else {
                return res;//只要遇到不是数字的就停止循环
            }
            i++;
        }
        return res;
    }
};
```

</details>

<details>
<summary>[hard]正则表达式匹配</summary>

请实现一个函数用来匹配包含'. '和'*'的正则表达式。模式中的字符'.'表示任意一个字符，而'*'表示它前面的字符可以出现任意次（含0次）。在本题中，匹配是指字符串的所有字符匹配整个模式。例如，字符串"aaa"与模式"a.a"和"ab*ac*a"匹配，但与"aa.a"和"ab*a"均不匹配。

+ 示例 1:

    输入:
    s = "aa"
    p = "a"
    输出: false
    解释: "a" 无法匹配 "aa" 整个字符串。
+ 示例 2:

    输入:
    s = "aa"
    p = "a*"
    输出: true
    解释: 因为 '*' 代表可以匹配零个或多个前面的那一个元素, 在这里前面的元素就是 'a'。因此，字符串 "aa" 可被视为 'a' 重复了一次。
+ 示例 3:

    输入:
    s = "ab"
    p = ".*"
    输出: true
    解释: ".*" 表示可匹配零个或多个（'*'）任意字符（'.'）。
+ 示例 4:

    输入:
    s = "aab"
    p = "c*a*b"
    输出: true
    解释: 因为 '*' 表示零个或多个，这里 'c' 为 0 个, 'a' 被重复一次。因此可以匹配字符串 "aab"。
+ 示例 5:

    输入:
    s = "mississippi"
    p = "mis*is*p*."
    输出: false
    s 可能为空，且只包含从 a-z 的小写字母。
    p 可能为空，且只包含从 a-z 的小写字母以及字符 . 和 *，无连续的 '*'。

```
class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();

        auto matches = [&](int i, int j) {
            if (i == 0) {
                return false;
            }
            if (p[j - 1] == '.') {
                return true;
            }
            return s[i - 1] == p[j - 1];
        };

        vector<vector<int>> f(m + 1, vector<int>(n + 1));
        f[0][0] = true;
        for (int i = 0; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (p[j - 1] == '*') {
                    f[i][j] |= f[i][j - 2];
                    if (matches(i, j - 1)) {
                        f[i][j] |= f[i - 1][j];
                    }
                }
                else {
                    if (matches(i, j)) {
                        f[i][j] |= f[i - 1][j - 1];
                    }
                }
            }
        }
        return f[m][n];
    }
};

```
</details>

<details>
<summary>表示数值的字符串</summary>

请实现一个函数用来判断字符串是否表示数值（包括整数和小数）。

数值（按顺序）可以分成以下几个部分：

若干空格
一个 小数 或者 整数
（可选）一个 'e' 或 'E' ，后面跟着一个 整数
若干空格
小数（按顺序）可以分成以下几个部分：

（可选）一个符号字符（'+' 或 '-'）
下述格式之一：
至少一位数字，后面跟着一个点 '.'
至少一位数字，后面跟着一个点 '.' ，后面再跟着至少一位数字
一个点 '.' ，后面跟着至少一位数字
整数（按顺序）可以分成以下几个部分：

（可选）一个符号字符（'+' 或 '-'）
至少一位数字
部分数值列举如下：

["+100", "5e2", "-123", "3.1416", "-1E-16", "0123"]
部分非数值列举如下：

["12e", "1a3.14", "1.2.3", "+-5", "12e+5.4"]
 

+ 示例 1：

    输入：s = "0"
    输出：true
+ 示例 2：

    输入：s = "e"
    输出：false
+ 示例 3：

    输入：s = "."
    输出：false
+ 示例 4：

    输入：s = "    .1  "
    输出：true
 
提示：

1 <= s.length <= 20
s 仅含英文字母（大写和小写），数字（0-9），加号 '+' ，减号 '-' ，空格 ' ' 或者点 '.' 。

**思路**
确定有限状态自动机
预备知识

确定有限状态自动机（以下简称「自动机」）是一类计算模型。它包含一系列状态，这些状态中：

有一个特殊的状态，被称作「初始状态」。
还有一系列状态被称为「接受状态」，它们组成了一个特殊的集合。其中，一个状态可能既是「初始状态」，也是「接受状态」。
起初，这个自动机处于「初始状态」。随后，它顺序地读取字符串中的每一个字符，并根据当前状态和读入的字符，按照某个事先约定好的「转移规则」，从当前状态转移到下一个状态；当状态转移完成后，它就读取下一个字符。当字符串全部读取完毕后，如果自动机处于某个「接受状态」，则判定该字符串「被接受」；否则，判定该字符串「被拒绝」。

注意：如果输入的过程中某一步转移失败了，即不存在对应的「转移规则」，此时计算将提前中止。在这种情况下我们也判定该字符串「被拒绝」。

一个自动机，总能够回答某种形式的「对于给定的输入字符串 S，判断其是否满足条件 P」的问题。在本题中，条件 P 即为「构成合法的表示数值的字符串」。

自动机驱动的编程，可以被看做一种暴力枚举方法的延伸：它穷尽了在任何一种情况下，对应任何的输入，需要做的事情。

自动机在计算机科学领域有着广泛的应用。在算法领域，它与大名鼎鼎的字符串查找算法「KMP」算法有着密切的关联；在工程领域，它是实现「正则表达式」的基础。

问题描述：
在 C++ 文档 中，描述了一个合法的数值字符串应当具有的格式。具体而言，它包含以下部分：

符号位，即 ++、-− 两种符号
整数部分，即由若干字符 0-90−9 组成的字符串
小数点
小数部分，其构成与整数部分相同
指数部分，其中包含开头的字符 \text{e}e（大写小写均可）、可选的符号位，和整数部分
相比于 C++ 文档而言，本题还有一点额外的不同，即允许字符串首末两端有一些额外的空格。

在上面描述的五个部分中，每个部分都不是必需的，但也受一些额外规则的制约，如：

如果符号位存在，其后面必须跟着数字或小数点。
小数点的前后两侧，至少有一侧是数字。

根据上面的描述，现在可以定义自动机的「状态集合」了。那么怎么挖掘出所有可能的状态呢？一个常用的技巧是，用「当前处理到字符串的哪个部分」当作状态的表述。根据这一技巧，不难挖掘出所有状态：

起始的空格
符号位
整数部分
左侧有整数的小数点
左侧无整数的小数点（根据前面的第二条额外规则，需要对左侧有无整数的两种小数点做区分）
小数部分
字符 \text{e}e
指数部分的符号位
指数部分的整数部分
末尾的空格
下一步是找出「初始状态」和「接受状态」的集合。根据题意，「初始状态」应当为状态 1，而「接受状态」的集合则为状态 3、状态 4、状态 6、状态 9 以及状态 10。换言之，字符串的末尾要么是空格，要么是数字，要么是小数点，但前提是小数点的前面有数字。

最后，需要定义「转移规则」。结合数值字符串应当具备的格式，将自动机转移的过程以图解的方式表示出来：


```
class Solution {
public:
    enum State {
        STATE_INITIAL,
        STATE_INT_SIGN,
        STATE_INTEGER,
        STATE_POINT,
        STATE_POINT_WITHOUT_INT,
        STATE_FRACTION,
        STATE_EXP,
        STATE_EXP_SIGN,
        STATE_EXP_NUMBER,
        STATE_END
    };

    enum CharType {
        CHAR_NUMBER,
        CHAR_EXP,
        CHAR_POINT,
        CHAR_SIGN,
        CHAR_SPACE,
        CHAR_ILLEGAL
    };

    CharType toCharType(char ch) {
        if (ch >= '0' && ch <= '9') {
            return CHAR_NUMBER;
        } else if (ch == 'e' || ch == 'E') {
            return CHAR_EXP;
        } else if (ch == '.') {
            return CHAR_POINT;
        } else if (ch == '+' || ch == '-') {
            return CHAR_SIGN;
        } else if (ch == ' ') {
            return CHAR_SPACE;
        } else {
            return CHAR_ILLEGAL;
        }
    }

    bool isNumber(string s) {
        unordered_map<State, unordered_map<CharType, State>> transfer{
            {
                STATE_INITIAL, {
                    {CHAR_SPACE, STATE_INITIAL},
                    {CHAR_NUMBER, STATE_INTEGER},
                    {CHAR_POINT, STATE_POINT_WITHOUT_INT},
                    {CHAR_SIGN, STATE_INT_SIGN}
                }
            }, {
                STATE_INT_SIGN, {
                    {CHAR_NUMBER, STATE_INTEGER},
                    {CHAR_POINT, STATE_POINT_WITHOUT_INT}
                }
            }, {
                STATE_INTEGER, {
                    {CHAR_NUMBER, STATE_INTEGER},
                    {CHAR_EXP, STATE_EXP},
                    {CHAR_POINT, STATE_POINT},
                    {CHAR_SPACE, STATE_END}
                }
            }, {
                STATE_POINT, {
                    {CHAR_NUMBER, STATE_FRACTION},
                    {CHAR_EXP, STATE_EXP},
                    {CHAR_SPACE, STATE_END}
                }
            }, {
                STATE_POINT_WITHOUT_INT, {
                    {CHAR_NUMBER, STATE_FRACTION}
                }
            }, {
                STATE_FRACTION,
                {
                    {CHAR_NUMBER, STATE_FRACTION},
                    {CHAR_EXP, STATE_EXP},
                    {CHAR_SPACE, STATE_END}
                }
            }, {
                STATE_EXP,
                {
                    {CHAR_NUMBER, STATE_EXP_NUMBER},
                    {CHAR_SIGN, STATE_EXP_SIGN}
                }
            }, {
                STATE_EXP_SIGN, {
                    {CHAR_NUMBER, STATE_EXP_NUMBER}
                }
            }, {
                STATE_EXP_NUMBER, {
                    {CHAR_NUMBER, STATE_EXP_NUMBER},
                    {CHAR_SPACE, STATE_END}
                }
            }, {
                STATE_END, {
                    {CHAR_SPACE, STATE_END}
                }
            }
        };

        int len = s.length();
        State st = STATE_INITIAL;

        for (int i = 0; i < len; i++) {
            CharType typ = toCharType(s[i]);
            if (transfer[st].find(typ) == transfer[st].end()) {
                return false;
            } else {
                st = transfer[st][typ];
            }
        }
        return st == STATE_INTEGER || st == STATE_POINT || st == STATE_FRACTION || st == STATE_EXP_NUMBER || st == STATE_END;
    }
};


```
</details>

## chap 2 hash table

<detials>
<summary>第一个只出现一次的字符</summary>
在字符串 s 中找出第一个只出现一次的字符。如果没有，返回一个单空格。 s 只包含小写字母。

+ 示例 1:

输入：s = "abaccdeff"
输出：'b'

+ 示例 2:

输入：s = "" 
输出：' '

```
class Solution {
public:
    char firstUniqChar(string s) {
        unordered_map<char,int> mp;
        for(auto & c : s) {
            mp[c]++;
        }
        for(auto & c : s) {
            if(mp[c] == 1) {
                return c;
            }
        }
        return ' ';
    }
};
```

</details>

## chap 3 栈和队列

<details>
<summary>用两个栈实现队列</summary>
用两个栈实现一个队列。队列的声明如下，请实现它的两个函数 appendTail 和 deleteHead ，分别完成在队列尾部插入整数和在队列头部删除整数的功能。(若队列中没有元素，deleteHead 操作返回 -1 )

+ 示例 1：

    输入：
    ["CQueue","appendTail","deleteHead","deleteHead"]
    [[],[3],[],[]]
    输出：[null,null,3,-1]
+ 示例 2：

    输入：
    ["CQueue","deleteHead","appendTail","appendTail","deleteHead","deleteHead"]
    [[],[],[5],[2],[],[]]
    输出：[null,-1,null,null,5,2]

```
class CQueue {
public:
    CQueue() {
        while(!s1.empty()) {
            s1.pop();
        }
        while(!s2.empty()) {
            s2.pop();
        }
    }
    
    void appendTail(int value) {
        s1.push(value);
    }
    
    int deleteHead() {
        if(s2.empty()) {
            while(!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        if(s2.empty()) {
            return -1;
        } else {
            int res = s2.top();
            s2.pop();
            return res;
        }
    }

private:
    stack<int> s1;
    stack<int> s2;
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */
```

</details>

<details>
<summary>包含min函数的栈</summary>

**描述**

 定义栈的数据结构，请在该类型中实现一个能够得到栈中所含最小元素的min函数，并且调用 min函数、push函数 及 pop函数 的时间复杂度都是 O(1)
    push(value):将value压入栈中
    pop():弹出栈顶元素
    top():获取栈顶元素
    min():获取栈中最小元素
    
+ 示例:

        输入:    ["PSH-1","PSH2","MIN","TOP","POP","PSH1","TOP","MIN"]
        输出:    -1,2,1,-1
    
+ 解析:
        "PSH-1"表示将-1压入栈中，栈中元素为-1
        "PSH2"表示将2压入栈中，栈中元素为2，-1
        “MIN”表示获取此时栈中最小元素==>返回-1
        "TOP"表示获取栈顶元素==>返回2
        "POP"表示弹出栈顶元素，弹出2，栈中元素为-1
        "PSH-1"表示将1压入栈中，栈中元素为1，-1
        "TOP"表示获取栈顶元素==>返回1
        “MIN”表示获取此时栈中最小元素==>返回-1
    
**题解：**
```
     class Solution {
     public:
         void push(int value) {
             s.push(value);
             if(!m.empty()) {
                 m.push(value< m.top() ? value : m.top());
             } else {
                 m.push(value);
             }
         }
         void pop() {
             s.pop();
             m.pop();
         }
         int top() {
             return s.top();
         }
         int min() {
             return m.top();
         }
     private:
         stack<int> s ;
         stack<int> m;
     };
```
</details>

<details>
<summary>栈的压入、弹出序列</summary>

**描述**

    输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否可能为该栈的弹出顺序。假设压入栈的所有数字均不相等。例如序列1,2,3,4,5是某栈的压入顺序，序列4,5,3,2,1是该压栈序列对应的一个弹出序列，但4,3,5,1,2就不可能是该压栈序列的弹出序列。（注意：这两个序列的长度是相等的）
    
+ 示例1
    输入：
    [1,2,3,4,5],[4,3,5,1,2]
    返回值：
    false
    
题解：
```
 class Solution {
 public:
     bool IsPopOrder(vector<int> pushV,vector<int> popV) {
         if(pushV.size() == 0 ) {
             return false;
         }
         vector<int> stack;
         for(int i = 0,j=0;i < pushV.size();) {
             stack.push_back(pushV[i++]);
             while(j < popV.size() && stack.back() == popV[j]) {
                 stack.pop_back();
                 j++;
             }
         }
         return stack.empty();
     }
 };
 
```
</details>

## chap 4 链表

<details>
<summary>从尾到头打印链表</summary>
输入一个链表的头节点，从尾到头反过来返回每个节点的值（用数组返回）。

+ 示例 1：

    输入：head = [1,3,2]
    输出：[2,3,1]


解法1，遍历链表，存到数组中，然后翻转数组
```
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> reversePrint(ListNode* head) {
        vector<int> res;
        while(head) {
            res.push_back(head->val);
            head = head -> next;
        }
        int len = res.size();
        for(int i = 0;i < len /2;++i) {
            swap(res[i],res[len - 1 - i]);
        }
        return res;
    }
};
```
解法2，反转链表，然后遍历链表到数组中
```
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> reversePrint(ListNode* head) {
        vector<int> res;
        ListNode * prev = nullptr;
        ListNode * cur = head;
        while(cur) {
            ListNode * tmp = cur->next;//切记，存的是后面的节点
            cur->next = prev;
            prev = cur;
            cur = tmp;
        }
        ListNode * now_node = prev;
        while(now_node) {
            res.push_back(now_node->val);
            now_node = now_node->next;
        }
        return res;
    }
};
```

</details>

<details>
<summary>链表中倒数最后k个结点</summary>

描述

    输入一个长度为n的链表，设链表中的元素的值为ai，输出一个链表，该输出链表包含原链表中从倒数第k个结点至尾节点的全部节点。如果该链表长度小于k，请返回一个长度为 0 的链表。
    
+ 示例1

    输入：
    {1,2,3,4,5},3
    返回值：
    {3,4,5}

+ 示例2

    输入：
    {2},8
    返回值：
    {}

**思路：**

    本质上来说，这个还是个模拟的过程，解法1可以先遍历一遍，看看链表的长度len，然后减去k后得到len-k， 最后再遍历到len-k得到最后的结果。解法2,可以先走k步，然后再通过另一个指针同时走，以第二个指针的结果返回，这样不需要重复走，时间复杂度是严格的O(n)

解法1
```
     /**
      * struct ListNode {
              *    int val;
              *    struct ListNode next;
              *    ListNode(int x) : val(x), next(nullptr) {}
      * };
      */
     class Solution {
     public:
         /*
          * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
          *
          * 
          * @param pHead ListNode类 
          * @param k int整型 
          * @return ListNode类
          /
         ListNode FindKthToTail(ListNode* pHead, int k) {
             // write code here
             ListNode * pTmp = pHead;
             
            int len = 0;
            while(pTmp) {
                ++len;
                pTmp = pTmp->next;
            }
            int count = len - k;
            if(len < k) {
                return NULL;
            }
            while(count--) {
                pHead = pHead->next;
            }
            return pHead;
         }
     };
    解法2：
     /**
      * struct ListNode {
              *    int val;
              *    struct ListNode next;
              *    ListNode(int x) : val(x), next(nullptr) {}
      * };
      */
     class Solution {
     public:
         /*
          * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
          *
          * 
          * @param pHead ListNode类 
          * @param k int整型 
          * @return ListNode类
          /
         ListNode FindKthToTail(ListNode* pHead, int k) {
             // write code here
             ListNode * pTmp1 = pHead;
             
            ListNode* pTmp2 = pHead;
            while(k && pTmp1 != NULL) {
                --k;
                pTmp1 = pTmp1->next;
            }
            if(k) {//如果k没有减为0，说明数据长度小于链表长度
                return NULL;
            }
            while(pTmp1 != NULL) {
                pTmp1 = pTmp1->next;
                    pTmp2 = pTmp2->next;
            }
             return pTmp2;
         }
     };
    
``` 
</details>

<details>
<summary>翻转链表</summary>

描述
    输入一个链表，反转链表后，输出新链表的表头。
+ 示例1

    输入：
        {1,2,3}
        返回值：
        {3,2,1}
**思路：**
用prev和cur进行标志，先对指针进行翻转，然后再移动前后的prev和cur

题解
```
     class Solution {
     public:
         ListNode* ReverseList(ListNode* pHead) {
            ListNode* cur = pHead;
           
            ListNode * prev = NULL;
            ListNode * tmp;
            while(cur) {
                tmp = cur->next;
                cur->next = prev;
                prev = cur;
                cur = tmp;
            }
            return prev;
         }
     };
     
```
</details>

<details>
<summary>合并两个排序的链表</summary>

**描述**
        输入两个单调递增的链表，输出两个链表合成后的链表，当然我们需要合成后的链表满足单调不减规则。
    
**思路：**
这题虽然是模拟的过程，不过是用到了归并排序的最后合并的思路，就是两两比对，然后再合并，构造一个虚拟头节点，然后在两个链表中进行比对
    
题解
```
     ListNode* Merge(ListNode* pHead1, ListNode* pHead2) {
         ListNode * dummy_head = new ListNode(-1);//虚拟头节点
             ListNode * head = dummy_head;
             while(pHead1 && pHead2) {
                 if( pHead1->val > pHead2->val) {
                    head->next = pHead2;
                    pHead2 = pHead2->next;
     
                } else {
                    head->next = pHead1;
                    pHead1 = pHead1->next;
     
                } 
                head = head->next;
             }
             if(pHead1 == NULL && pHead2 != NULL) {
                 head->next = pHead2;
             }
             if(pHead2 == NULL && pHead1 != NULL) {
                 head->next = pHead1;
             }
     
         return dummy_head->next;
     }
     
```
</details>

<details>
<summary>复杂链表的复制</summary>

**描述**

    输入一个复杂链表（每个节点中有节点值，以及两个指针，一个指向下一个节点，另一个特殊指针random指向一个随机节点），请对此链表进行深拷贝，并返回拷贝后的头结点。（注意，输出结果中请不要返回参数中的节点引用，否则判题程序会直接返回空）。 下图是一个含有5个结点的复杂链表。图中实线箭头表示next指针，虚线箭头表示random指针。为简单起见，指向null的指针没有画出。
如图：
            
+ 示例1

    输入：
    {1,2,3,4,5,3,5,#,2,#}
    返回值：
    {1,2,3,4,5,3,5,#,2,#}

    输入:{1,2,3,4,5,3,5,#,2,#}
    输出:{1,2,3,4,5,3,5,#,2,#}
    解析:我们将链表分为两段，前半部分{1,2,3,4,5}为ListNode，后半部分{3,5,#,2,#}是随机指针域表示。
    以上示例前半部分可以表示链表为的ListNode:1->2->3->4->5
    后半部分，3，5，#，2，#分别的表示为
    1的位置指向3，2的位置指向5，3的位置指向null，4的位置指向2，5的位置指向null
    如下图:

**思路：**
            用一个hash表装映射关系
        题解
```
    /*
    struct RandomListNode {
        int label;
        struct RandomListNode next, *random;
        RandomListNode(int x) :
                label(x), next(NULL), random(NULL) {
        }
    };
    */
    class Solution {
    public:
        RandomListNode Clone(RandomListNode* pHead) {
            RandomListNode* cur = pHead;
            unordered_map mp;
            //复制各节点，并建立 “原节点 -> 新节点” 的 Map 映射
            while(cur) {
                mp[cur] = new RandomListNode(cur->label);
                cur=cur->next;
            }
            cur = pHead;
            while(cur) {
                mp[cur]->next = mp[cur->next];
                mp[cur]->random = mp[cur->random];
                cur = cur->next;
            }
            return mp[pHead];
        }
    };
         
```
</details>

<details>
<summary>两个链表的第一个公共结点</summary>

**描述**

        输入两个无环的单链表，找出它们的第一个公共结点。（注意因为传入数据是链表，所以错误测试数据的提示是用其他方式显示的，保证传入数据是正确的）
+ 示例1

    输入：
        {1,2,3},{4,5},{6,7}
    返回值：
        {6,7}
    说明：
        第一个参数{1,2,3}代表是第一个链表非公共部分，第二个参数{4,5}代表是第二个链表非公共部分，最后的{6,7}表示的是2个链表的公共部分这3个参数最后在后台会组装成为2个两个无环的单链表，且是有公共节点的  

+ 示例2
    输入：
        {1},{2,3},{}
    返回值：
        {}
    说明：
        2个链表没有公共节点 ,返回null，后台打印{}

**思路：**
还是比较清晰的，先分别走完两条链表，分别计算出长度，然后减去得到差值，先让长链表走完差值的部分，接着再两个链表同时走，直到两个链表的值相等为止
    
题解：
```
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int len1=0,len2=0;
        ListNode *tmp1=headA,*tmp2=headB;
        while(headA==NULL || headB==NULL)
            return NULL;
        while(tmp1->next!=NULL) {
            ++len1;
            tmp1=tmp1->next;
        }
        while( tmp2->next!=NULL) {
            ++len2;
            tmp2=tmp2->next;
        }
        tmp1=headA,tmp2=headB;
        int diff=len1-len2;
        while(diff>0 && tmp1!=NULL) {
            --diff;
            tmp1=tmp1->next;
        }
        while(diff<0 && tmp2!=NULL ) {
            ++diff;
            tmp2=tmp2->next;
        }
        while(tmp1!=NULL&&tmp2!=NULL) {
            if(tmp1==tmp2)
                return tmp1;
            tmp1=tmp1->next;
            tmp2=tmp2->next;
            
        }
        return NULL;
    }
};
```
</details>

<details>
<summary>链表中环的入口结点</summary>
给定一个链表，返回链表开始入环的第一个节点。 如果链表无环，则返回 null。

为了表示给定链表中的环，我们使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。 如果 pos 是 -1，则在该链表中没有环。注意，pos 仅仅是用于标识环的情况，并不会作为参数传递到函数中。

说明：不允许修改给定的链表。

进阶：

你是否可以使用 O(1) 空间解决此题？


```
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
		ListNode * fast = head;
		while(fast != nullptr && fast->next != nullptr) {
		    slow = slow->next;
			fast = fast->next->next;
			// 快慢指针相遇，此时从head 和 相遇点，同时查找直至相遇
			if(slow == fast) {
			    ListNode* idx1 = fast;
				ListNode * idx2 = head;
				while(idx1 != idx2) {
				    idx1 = idx1->next;
					idx2 = idx2->next;
				}
				return idx2;// 返回环的入口
			}
		}
		return nullptr;     
    }
};
```
</details>

<details>
<summary>删除链表中的重复节点</summary>
    
**描述**

    在一个排序的链表中，存在重复的结点，请删除该链表中重复的结点，重复的结点不保留，返回链表头指针。 例如，链表1->2->3->3->4->4->5 处理后为 1->2->5
    
+ 示例1

        输入：
        {1,2,3,3,4,4,5}
        返回值：
        {1,2,5}

**思路：**

```
     /*
     struct ListNode {
         int val;
         struct ListNode next;
         ListNode(int x) :
             val(x), next(NULL) {
         }
     };
     */
     class Solution {
     public:
         ListNode* deleteDuplication(ListNode pHead) {
             ListNode* dummy_head = new ListNode(-1);
             dummy_head->next = pHead;
             ListNode * prev = dummy_head;
             ListNode * cur = pHead;
             while(cur && cur->next) {
                 if(cur->val == cur->next->val) {
                     int v = cur->val;
                     while(cur && cur->val == v) {
                         cur = cur->next;
                     }
                     prev->next = cur;
                 } else {
                     prev = cur;
                     cur = cur->next;
                 }
             }
             return dummy_head->next;
         }
     };
     
```
</details>

## chap 5 二叉树

<details>
<summary>重建二叉树</summary>
输入某二叉树的前序遍历和中序遍历的结果，请构建该二叉树并返回其根节点。
假设输入的前序遍历和中序遍历的结果中都不含重复的数字。

+ 示例 1:

![tree.jpeg](https://i.loli.net/2021/09/24/qNXi2FELp61gksr.jpg)

+ Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
Output: [3,9,20,null,null,15,7]

+ 示例 2:
    Input: preorder = [-1], inorder = [-1] 
    Output: [-1]


**题解**
其实本题的思路显然也有递归和迭代两种解法。
首先是递归解法，我们需要根据前序遍历的结果中第一个元素获得根节点，然后再去中序遍历中找到对应的区间进行切分，分别得到左子树和右子树的中序遍历，然后再根据中旬遍历的切分重新回到原来的前序遍历中，切分得到左子树的前序遍历和右子树的前序遍历。在切分的时候一定要注意好左右区间， 我这里采用了左闭右开的方式。

优化1:可以将每次去中序遍历查索引下表的数据放到哈希表中加速查询

递归解法：

```
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* TraversalbuildSubtree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size() == 0 ) {
            return nullptr;
        }
        int val = preorder[0];
        TreeNode * root = new TreeNode(val); 
        if(preorder.size() == 1) {
            return root;
        }
        int i ;
        for(i = 0;i < inorder.size();++i) {
            if(inorder[i] == val) {
                break;
            }
        }
        //左闭右开区间：[0, i)
        vector<int> left_inorder(inorder.begin(),inorder.begin() + i);
        vector<int> right_inorder(inorder.begin() + 1 + i,inorder.end());
        
        //左闭右开状态：[）
        vector<int> left_preorder(preorder.begin() + 1, preorder.begin() + left_inorder.size() + 1);
        vector<int> right_preorder(preorder.begin() + left_inorder.size() + 1, preorder.end());

        root->left =  TraversalbuildSubtree(left_preorder,left_inorder);
        root->right = TraversalbuildSubtree(right_preorder,right_inorder);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size() == 0 || inorder.size() == 0) {
            return nullptr;
        }
        return TraversalbuildSubtree(preorder,inorder);
    }
};
```

迭代写法：

```
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (!preorder.size()) {
            return nullptr;
        }
        TreeNode* root = new TreeNode(preorder[0]);
        stack<TreeNode*> stk;
        stk.push(root);
        int inorderIndex = 0;
        for (int i = 1; i < preorder.size(); ++i) {
            int preorderVal = preorder[i];
            TreeNode* node = stk.top();
            if (node->val != inorder[inorderIndex]) {
                node->left = new TreeNode(preorderVal);
                stk.push(node->left);
            }
            else {
                while (!stk.empty() && stk.top()->val == inorder[inorderIndex]) {
                    node = stk.top();
                    stk.pop();
                    ++inorderIndex;
                }
                node->right = new TreeNode(preorderVal);
                stk.push(node->right);
            }
        }
        return root;
    }
};

```

变形题

通过

</details>

<details>
<summary>树的子结构</summary>
输入两棵二叉树A和B，判断B是不是A的子结构。(约定空树不是任意一个树的子结构)
B是A的子结构， 即 A中有出现和B相同的结构和节点值。

+ 例如:
给定的树 A:
```
     3
    / \
   4   5
  / \
 1   2
```
给定的树 B：
```
   4 
  /
 1
```
返回 true，因为 B 与 A 的一个子树拥有相同的结构和节点值。

+ 示例 1：

输入：A = [1,2,3], B = [3,1]
输出：false

+ 示例 2：

输入：A = [3,4,5,1,2], B = [4,1]
输出：true
限制：

0 <= 节点个数 <= 10000

```

```

</details>

<details>
<summary></summary>
</details>

<details>
<summary></summary>
</details>

<details>
<summary></summary>
</details>

<details>
<summary></summary>
</details>

<details>
<summary></summary>
</details>

<details>
<summary></summary>
</details>

<details>
<summary></summary>
</details>

<details>
<summary></summary>
</details>

<details>
<summary></summary>
</details>

<details>
<summary></summary>
</details>

<details>
<summary></summary>
</details>

<details>
<summary></summary>
</details>

<details>
<summary></summary>
</details>

<details>
<summary></summary>
</details>

<details>
<summary></summary>
</details>

# chap 6 动态规划
<details>
<summary>最长不含重复字符的子字符串</summary>
示例 1:

输入: "abcabcbb"
输出: 3 
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
示例 2:

输入: "bbbbb"
输出: 1
解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
示例 3:

输入: "pwwkew"
输出: 3
解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
     请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。

**思路**
首先要理清题目意思，子串是连续的，例如pwwkew中，pww是子串，但是pwk不是连续的，因而只能是子序列，不能算是子串。

```
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxsub = 0, left = 0, pos = 0;
        vector<bool> used(256, false);
        while(pos < s.size()){
            while(used[s[pos]]) used[s[left++]] = false;  
            maxsub = max(maxsub, pos - left + 1);
            used[s[pos++]] = true;
        }
        return maxsub;
    }
};


```

</details>

# chap 7 其他
<details>
<summary>滑动窗口最大值</summary>
给你一个整数数组 nums，有一个大小为 k 的滑动窗口从数组的最左侧移动到数组的最右侧。你只可以看到在滑动窗口内的 k 个数字。滑动窗口每次只向右移动一位。

返回滑动窗口中的最大值。

+ 示例 1：

输入：nums = [1,3,-1,-3,5,3,6,7], k = 3
输出：[3,3,5,5,6,7]
解释：

```
滑动窗口的位置                最大值
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
 ```
+ 示例 2：

输入：nums = [1], k = 1
输出：[1]

+ 示例 3：

输入：nums = [1,-1], k = 1
输出：[1,-1]

+ 示例 4：

输入：nums = [9,11], k = 2
输出：[11]

**思路**
参考：
https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0239.%E6%BB%91%E5%8A%A8%E7%AA%97%E5%8F%A3%E6%9C%80%E5%A4%A7%E5%80%BC.md

这是单调队列的经典题目
优先级队列和单调队列的区别在于，优先级队列其实是个堆，假如使用大顶堆，每次只能弹出最大的元素，并不能操作其他的元素，因此对于滑动窗口而言，并不能满足需求。此时我们需要一个队列，这个队列呢，放进去窗口里的元素，然后随着窗口的移动，队列也一进一出，每次移动之后，队列告诉我们里面的最大值是什么。

时间复杂度是 O(n)。空间复杂度因为定义一个辅助队列，所以是O(k)。

```
class Solution {
private:
    class MyQueue { //单调队列（从大到小）
    public:
        deque<int> que; // 使用deque来实现单调队列
        // 每次弹出的时候，比较当前要弹出的数值是否等于队列出口元素的数值，如果相等则弹出。
        // 同时pop之前判断队列当前是否为空。
        void pop(int value) {
            if (!que.empty() && value == que.front()) {
                que.pop_front();
            }
        }
        // 如果push的数值大于入口元素的数值，那么就将队列后端的数值弹出，直到push的数值小于等于队列入口元素的数值为止。
        // 这样就保持了队列里的数值是单调从大到小的了。
        void push(int value) {
            while (!que.empty() && value > que.back()) {
                que.pop_back();
            }
            que.push_back(value);

        }
        // 查询当前队列里的最大值 直接返回队列前端也就是front就可以了。
        int front() {
            return que.front();
        }
    };
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        MyQueue que;
        vector<int> result;
        for (int i = 0; i < k; i++) { // 先将前k的元素放进队列
            que.push(nums[i]);
        }
        result.push_back(que.front()); // result 记录前k的元素的最大值
        for (int i = k; i < nums.size(); i++) {
            que.pop(nums[i - k]); // 滑动窗口移除最前面元素
            que.push(nums[i]); // 滑动窗口前加入最后面的元素
            result.push_back(que.front()); // 记录对应的最大值
        }
        return result;
    }
};

```

</details>

<details>
<summary>数据流中的中位数</summary>

如何得到一个数据流中的中位数？如果从数据流中读出奇数个数值，那么中位数就是所有数值排序之后位于中间的数值。如果从数据流中读出偶数个数值，那么中位数就是所有数值排序之后中间两个数的平均值。

例如，

[2,3,4] 的中位数是 3

[2,3] 的中位数是 (2 + 3) / 2 = 2.5

设计一个支持以下两种操作的数据结构：

void addNum(int num) - 从数据流中添加一个整数到数据结构中。
double findMedian() - 返回目前所有元素的中位数。

+ 示例 1：

输入：
```
["MedianFinder","addNum","addNum","findMedian","addNum","findMedian"]
[[],[1],[2],[],[3],[]]
```
输出：
```
[null,null,null,1.50000,null,2.00000]
```

+ 示例 2：

输入：
```
["MedianFinder","addNum","findMedian","addNum","findMedian"]
[[],[2],[],[3],[]]
```
输出：
```
[null,null,2.00000,null,2.50000]
```
 

**思路**

使用两个堆来管理，当两堆的数据个数相等时候，左边堆添加元素。采用的方法不是直接将数据插入左边堆，而是将数据先插入右边堆，算法调整后将堆顶的数据插入到左边堆，这样保证左边堆插入的元素始终是右边堆的最小值。同理左边数据多，往右边堆添加数据的时候，先将数据放入左边堆，选出最大值放到右边堆中。

```
class MedianFinder {
private:
    // 最大堆，存储左边一半的数据，堆顶为最大值
    priority_queue<int,vector<int>,less<int>> max_heap;
    // 最小堆， 存储右边一半的数据，堆顶为最小值
    priority_queue<int,vector<int>,greater<int>> min_heap;
public:
    /** initialize your data structure here. */
    MedianFinder() {

    }
    // 维持堆数据平衡，并保证左边堆的最大值小于或等于右边堆的最小值
    void addNum(int num) {
        /*
         * 当两堆的数据个数相等时候，左边堆添加元素。
         * 采用的方法不是直接将数据插入左边堆，而是将数据先插入右边堆，算法调整后
         * 将堆顶的数据插入到左边堆，这样保证左边堆插入的元素始终是右边堆的最小值。
         * 同理左边数据多，往右边堆添加数据的时候，先将数据放入左边堆，选出最大值放到右边堆中。
         */
        if(max_heap.size() == min_heap.size()) {
            min_heap.push(num);
            int top = min_heap.top();
            min_heap.pop();
            max_heap.push(top);
        } else {
            max_heap.push(num);
            int top = max_heap.top();
            max_heap.pop();
            min_heap.push(top);
        }
    }
    
    double findMedian() {
        if (max_heap.size() == min_heap.size()) {
            return (max_heap.top()+min_heap.top())*1.0/2;
        } else {
            return max_heap.top()*1.0;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

```

</details>

<details>
<summary>不用加减乘除的加法</summary>
写一个函数，求两个整数之和，要求在函数体内不得使用 “+”、“-”、“*”、“/” 四则运算符号。

+ 示例:

输入: a = 1, b = 1
输出: 2

+ 提示：

a, b 均可能是负数或 0
结果不会溢出 32 位整数

如果进位，可以使用(a&b) << 1的方式进行保存，如果是非进位，则直接用异或

![image.png](https://i.loli.net/2021/10/01/CEiO3njBFW5H2TU.png)

```
class Solution {
public:
    int add(int a, int b) {
        //因为不允许用+号，所以求出异或部分和进位部分依然不能用+ 号，所以只能循环到没有进位为止        
        while(b!=0) {
            //保存进位值，下次循环用
            int c=(unsigned int)(a&b)<<1;//C++中负数不支持左移位，因为结果是不定的
            //保存不进位值，下次循环用，
            a^=b;
            //如果还有进位，再循环，如果没有，则直接输出没有进位部分即可。
            b=c;   
        }
        return a;
    }
};
```

</details>

<details>
<summary>求1+2+3+…+n</summary>
求 1+2+...+n ，要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）。

+ 示例 1：

输入: n = 3
输出: 6

+ 示例 2：

输入: n = 9
输出: 45

**思路**
简单的递归就可以解决

```
class Solution {
public:
    int sumNums(int n) {
        if(n == 1) {
            return 1;
        }
        return n + sumNums(n-1);
    }
};
```

</details>

<details>
<summary>孩子们的游戏（圆圈中最后剩下的数）</summary>
0,1,···,n-1这n个数字排成一个圆圈，从数字0开始，每次从这个圆圈里删除第m个数字（删除后从下一个数字开始计数）。求出这个圆圈里剩下的最后一个数字。

例如，0、1、2、3、4这5个数字组成一个圆圈，从数字0开始每次删除第3个数字，则删除的前4个数字依次是2、0、4、1，因此最后剩下的数字是3。

+ 示例 1：

输入: n = 5, m = 3
输出: 3

+ 示例 2：

输入: n = 10, m = 17
输出: 2

```
class Solution {
    int f(int n, int m) {
        if (n == 1) {
            return 0;
        }
        int x = f(n - 1, m);
        return (m + x) % n;
    }
public:
    int lastRemaining(int n, int m) {
        return f(n, m);
    }
};
```

</details>