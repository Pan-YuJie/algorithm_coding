
// 听说这题是通过率最低的top50!

// 这个题主要难点在有负数，所以感觉滑动窗口不太行（因为不存在一个单调递增的和）

// 首先区域和，可以考虑前缀和简化（假设叫sum[]）

// 然后就是高能的双端队列
// 我们知道有两个优化，在遍历数组的过程中（也就是说x1<x2）:
// 1.sum[x2]<=sum[x1]的时候，也就是说x1和x2之间的值的和是负数或者是0,这个时候如果让xn-x1(或x2)的话，肯定就会选择x2而不是x1,这个时候x1其实就可以出队列了

// 2.考虑如果已经找到了一个数x2,满足了sum[x2]-sum[x1]>k了，那这个时候其实x1就不用保留了，因为x1固定住，x2你在往后遍历，也不会比x2更靠近x1，这个时候就需要把x2-x1记录下来就好了

// 这个双端队列，里面的值是数组的下标，这肯定是递增的啊（毕竟我们是从0往后跑），但是他的和可不一定是单调递增的。

// 所以一开始遍历到i，可以通过1原则把队尾的值丢一丢

// 然后开始看看队头，如果差>=k了，也更新ans后丢掉就可了

/*
class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n=nums.size();
        deque<int> myque;
        vector<long long> sum(n+1);
        sum[0]=0;
        for(int i=1;i<=n;i++){
            sum[i]=sum[i-1]+nums[i-1];
        }

        int ans=INT_MAX;
        for(int i=0;i<sum.size();i++){
            while(!myque.empty() && sum[myque.back()]>=sum[i]){
                myque.pop_back();
            }

            while(!myque.empty() && sum[i]-sum[myque.front()]>=k){
                ans=min(ans,i-myque.front());
                myque.pop_front();
            }
            myque.push_back(i);
        }

        return ans==INT_MAX?-1:ans;
    }
};


*/
// public int shortestSubarray(int[] nums, int k) {
//         /*
//         案例模拟:
//         [1, 3, -1, 5, 6],k=7
//         [1, 4, 3, 8, 14],k=7
//         i = 0, que=[0], queVal=[1]
//         i = 1, que=[0, 1], queVal=[1,4]
//         i = 2, 满足第一个while,que=[0, 2], queVal=[1, 3]
//         i = 3, 满足第二个while,更新res=3,que = [0, 2, 3], queVal=[1, 3, 8]
//         i = 4, 满足第二个while,更新res=3,que = [0, 2, 3, 4], queVal=[1, 3, 8, 14]
//         队头->队尾单调递增(队头->队尾单调递减)  最后返回3
//         为什么要维护单调队列？
//         因为单调队列可以维护住只对最终结果有影响的元素索引
//         试想一下:queVal=[1, 4, 3, 8, 14] 这个4是一定没用的,假设8-4可以满足条件,那么8-3必定也能满足并且长度比8-4还小!那么这个单调队列就维护住了一切可能的结果;
//         怎样寻找最短长度呢?肯定是再满足>=k时进行长度的缩短,直到最后一个不满足条件;
//         */
//         // 先求前缀和(加起来可能会很大用long)
//         int len = nums.length;
//         long[] preSum = new long[len + 1];
//         // sum[0,2]=preSum[3]-preSum[0]
//         // 即sum[i,j]=preSum[j+1]-preSum[i]
//         // preSum[0] = 0;
//         for(int i = 1; i <= len; i++) {
//             preSum[i] = preSum[i - 1] + nums[i - 1];
//             // 遇到单一元素>=k的直接返回1
//             if(nums[i - 1] >= k) {
//                 return 1;
//             }
//         }
//         // 维护一个单调递增(指索引对应的元素)的索引队列
//         Deque<Integer> que = new LinkedList<>();
//         // 设一个不可能达到的长度
//         int res = Integer.MAX_VALUE;
//         for(int i = 0; i < preSum.length; i++) {
//             // 1.先维护好单调队列:队尾一直弹出直到preSum[队尾]<preSum[i]
//             while(!que.isEmpty() && preSum[i] <= preSum[que.peekLast()]) {
//                 que.pollLast();
//             }
//             // 2.再维护最短的合乎条件的长度
//             // 这里的队头是最先遍历的元素,并且是比较小的
//             // 队头元素不断弹出的过程就是i指针右移的过程
//             while(!que.isEmpty() && preSum[i] - preSum[que.peekFirst()] >= k) {
//                 // 这里的i - que.pollFirst()实际上是nums[que.pollFirst(), i - 1]段的和
//                 // 长度刚好为i - que.pollFirst()
//                 res = Math.min(res, i - que.pollFirst());
//                 // 这里为什么可以直接左移呢?很显然的,因为[i, j]满足条件,那么[i, j+1]就算满足条件也不是最短的
//                 // 因此j + 1从[i + 1,j + 1]开始才能保证长度<=之前的[i, j]段
//             }
//             // 3.最后将当前preSum的索引加入队尾
//             // 这里索引范围为[0, len],因为求子数组的和会有冗余的第0位
//             que.addLast(i);
//         }
//         return res == Integer.MAX_VALUE ? -1 : res;
//     }