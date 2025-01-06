 #include<bits/stdc++.h>
using namespace std;

int main(){   //THEORY : FOR PRIORITY QUEUE:   HERE WE CAN STORE DATA INCREASING AND DECREASING ORDER ACCORDING TO THE PRIORITYH FOR OUR.
    //FOR INCREASING(1,2,3,4....) WE USE   priority_queue<int,vector<int>,greater<int>>pq1;
    // FOR DECREASING (4,3,2....)  WE USE   priority_queue<int>pq;
  cout<<" --------------the  DECREASING ORDER IS  DEFAULT:-----------"<<endl;
     priority_queue<int>pq;////******defaulut order is:  decreasing order.. 6,5,4,3,,,,,,

     pq.push(3);
     pq.push(5);
     pq.push(2);
     pq.push(1);

     cout<<"the top value is: "<<pq.top()<<endl;
     pq.pop();

     cout<<"after poping the 1st value ,the top value is:"<<pq.top()<<endl;

     while(pq.size()>0){

        cout<<pq.top()<<" ";
        pq.pop();
     }cout<<endl;

 cout<<"------------------------------------increasing order --------."<<endl;


        priority_queue<int,vector<int>,greater<int>>pq1;   //increasing order


     pq1.push(3);
     pq1.push(5);
     pq1.push(2);
     pq1.push(1);

     cout<<"the top value is: "<<pq1.top()<<endl;
     pq1.pop();

     cout<<"after poping the 1st value ,the top value is:"<<pq1.top()<<endl;

     while(pq1.size()>0){

        cout<<pq1.top()<<" ";
        pq1.pop();
     }cout<<endl;

     //     ****************************beside increasing and decreaing order ,other function like  empty(),swap(), emplace(), are same as queue .


}


//two pointer
// prefix sum: 1.prefix xor
//2. 2d prefix sum.
