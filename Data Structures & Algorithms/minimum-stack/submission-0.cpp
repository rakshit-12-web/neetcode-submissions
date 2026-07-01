class MinStack {
public:
int size=10000;
int *arr=new int[size];
int i=-1;
    MinStack() {
        

        
    }
    
    void push(int val) {
        i++;
        arr[i]=val;
    }
    
    void pop() {   
        if(i==-1){
            return ;
        }
         i--;
    }
    
    int top() {
        return arr[i];
        
    }
    
    int getMin() {
        int mini=INT_MAX;
        for(int j=0;j<=i;j++){
           mini=min(mini,arr[j]);
        }
        return mini;
    }
};
