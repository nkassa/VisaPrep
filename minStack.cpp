class MinStack {
public:

    vector<pair<int,int>> list;
    MinStack() 
    {  

    }
    void push(int val) 
    {
        if(list.size() == 0)
        {
            list.push_back({val, val});
        }
        else
        {
            list.push_back({val, min(list.back().second, val)});
        }
    }
    
    void pop() 
    {
        list.pop_back();
    }
    
    int top() 
    {
        return list.back().first;
    }
    
    int getMin() 
    {
        return list.back().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */