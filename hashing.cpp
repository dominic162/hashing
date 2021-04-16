#include<bits/stdc++.h>
using namespace std;

class node{
    public:
        int data;
        node* p=NULL;
};

class hashing{
    private:
        node* a;
        int number;
    public:
        int hashfn(int r2){
            return r2%number;
        }
        void push(int r1){
            int index;
            index=hashfn(r1);
            if(a[index].data==-1){
                a[index].data=r1;
            }
            else{
                node* r;
                if(a[index].p==NULL){
                    a[index].p=new node;
                    r=a[index].p;
                }
                else{
                    r=a[index].p;
                    while(r->p!=NULL){
                        r=r->p;
                    }
                    r->p=new node;
                    r=r->p;
                }
                r->data=r1;
            }
        }
        bool search(int r3){
            int index=hashfn(r3);
            if(a[index].data==r3){
                return true;
            }
            node* pr=a[index].p;
            while(pr!=NULL){
                if(pr->data==r3){
                    return true;
                }
                pr=pr->p;
            }
            return false;
        }
        hashing(int n){
            this->a=new node[n];
            for(int i=0;i<n;i++){
                a[i].data=-1;
            }
            this->number=n;
        }
};

int main(){
    int n,i,r,sn,element;
    cout<<"enter number of elements:- ";
    cin>>n;
    hashing h1(n);
    cout<<"enter elements:- ";
    for(i=0;i<n;i++){
        cin>>r;
        h1.push(r);
    }
    cout<<"enter number of elements to be searched:- ";
    cin>>sn;
    for(i=0;i<sn;i++){
        cin>>element;
        if(h1.search(element)){
            cout<<"element present "<<endl;
        }
        else{
            cout<<"not present "<<endl;
        }
    }

    return 0;
}