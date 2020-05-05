#include <stack>
#include <vector>
using namespace std;

// 方案一:逆序遍历,压栈之前操作
class Solution_1 {
public:
    vector<int> dailyTemperatures(vector<int>& T)
    {
        int len = T.size();
        vector<int> res(len, 0);
        stack<int> st;

        // 逆序压栈 维护递减栈
        for (int i = len - 1; i >= 0; --i) {
            while (st.empty() == false) {
                if (T[st.top()] > T[i]) {
                    res[i] = st.top() - i;
                    break;
                } else {
                    st.pop();
                }
            }

            // 当前元素没有找到后续更大值,赋值为0
            if (st.empty() == true) {
                res[i] = 0;
            }

            st.push(i);
        }

        return res;
    }
};

// 方案二: 顺序遍历,弹栈之前操作
class Solution_2 {
public:
    vector<int> dailyTemperatures(vector<int>& T)
    {
        int len = T.size();
        vector<int> res(len, 0);
        stack<int> st;

        // 顺序压栈
        for (int i = 0; i < len; ++i) {
            while (st.empty() == false) {
                if (T[st.top()] >= T[i]) {
                    break;
                } else {
                    res[st.top()] = i - st.top();
                    st.pop();
                }
            }
            st.push(i);
        }

        // 之后都不会升高的日期
        for (int j = 0; j < st.size(); ++j) {
            res[st.top()] = 0;
            st.pop();
        }

        return res;
    }
};
