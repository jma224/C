//-----------Jingyan Ma  260783581-----------//

#include <stdio.h>
#include <queue>
#include <stack>


void test(int op){             
    std::queue<int> queue;                      //define empty standard structures of queue, stack and priority que
    std::stack<int> stack;
    std::priority_queue<int> pri_queue;
    int pq_valid=1,q_valid=1,s_valid=1;         //3 integers to indicate whether each structure is valid

    while(op--){                                //we have to run the operation for op times 
        int command, value;
        scanf("%d %d",&command, &value);        //read one line of operation from I.O.

        if(command==1){                                     //if command is 1, i.e. putting an element into the bag
            if(q_valid==1){queue.push(value);}             //while whichever structures are still valid, push the element in
            if(s_valid==1){stack.push(value);}  
            if(pq_valid==1){pri_queue.push(value);}
        }else if (command==2){                              //if command is 2, i.e. popping an element from the bag
            if(q_valid==1){                                //for each vaild structure, check if there is element to be popped, and whether the popped element meets the rules of the structure
                if (queue.empty() || queue.front() != value){
                    q_valid = 0;
                }else{
                    queue.pop();  
                }
            }
            
            if(s_valid==1){
                if (stack.empty() || stack.top() != value){
                    s_valid = 0;
                }else{
                    stack.pop();
                }
            }

            if(pq_valid==1){
                if (pri_queue.empty() || pri_queue.top() != value) {     
                    pq_valid = 0;   
                }else{
                    pri_queue.pop();       
                }
            }
        }
    }
    
    switch (q_valid+s_valid+pq_valid) {
        case 3:
        case 2:                         //if q_valid+s_valid+pq_valid=2/3 i.e. the data meets the rules of at least 2 structures, then print not sure
            printf("not sure\n");
            break;
        case 1:                        //only one structure is valid, and find out which one
            if(q_valid==1){
                printf("queue\n");
            }else if (s_valid==1){
                printf("stack\n");
            }else{
                printf("priority queue\n");
            }
            break;
        default:                        // all structures fail to be valid
            printf("impossible\n");
    }
}

int main(){
    int op;
    while (scanf("%d", &op) != EOF){
       test(op);                      //read the first line of input that indicate the number of operations 
    }   
    return 0;
}





