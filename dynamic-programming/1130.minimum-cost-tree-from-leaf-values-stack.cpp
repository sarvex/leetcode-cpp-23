class Solution {
public:
    int mctFromLeafValues(vector<int>& arr)
    {
        int n = arr.size();
        vector<int>nextGreater(n,std::numeric_limits<int>::max());
        vector<int>prevGreater(n,std::numeric_limits<int>::max());

        stack<int>Stack;
        for (int i=0; i<arr.size(); i++)
        {
            if (Stack.empty() || arr[i] <= arr[Stack.top()])
                Stack.push(i);
            else
            {
                while (!Stack.empty() && arr[Stack.top()] <= arr[i])
                {
                    int idx = Stack.top();
                    nextGreater[idx] = arr[i];
                    Stack.pop();
                }
                Stack.push(i);
            }
        }

        while (!Stack.empty()) Stack.pop();
        for (int i=0; i<arr.size(); i++)
        {
            if (Stack.empty() || arr[i] <= arr[Stack.top()])
            {
                if (!Stack.empty()) prevGreater[i] = arr[Stack.top()];
                Stack.push(i);
            }
            else
            {
                while (!Stack.empty() && arr[Stack.top()] <= arr[i])
                    Stack.pop();
                if (!Stack.empty())
                    prevGreater[i] = arr[Stack.top()];
                Stack.push(i);
            }
        }

        int result = 0;
        for (int i=0; i<arr.size(); i++)
        {
            int x = min(prevGreater[i], nextGreater[i]);
            if (x!=std::numeric_limits<int>::max())
                result += arr[i]*x;
        }
        return result;
    }
};
