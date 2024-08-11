#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;
// pair int
struct Pair {
    int x;
    int y;
};

//find that pair
struct tuplefind {
    vector<int> arr;
    int r;

    //find
    tuplefind(const vector<int>& array,int remainder):arr(array),r(remainder) {}

//remainder
    vector<Pair> findPairs() {
        vector<Pair> result;
        unordered_set<int> uniqueElements(arr.begin(),arr.end());

        for (int x:uniqueElements) {
            for (int y:uniqueElements) {
                if (x != y && x % y == r)   {
                        result.push_back({x,y});
                }
            }
        }

        return result;
    }

    //pair
    void printPairs(const vector<Pair>& pairs) {
    cout<<"Ordered pairs with remainder "<<r<<":"<<endl;
        for (const auto& p:pairs) {cout<<"("<<p.x<<","<<p.y<<")"<<endl;}
        cout<<endl;
    }
};

int main() {
    //Ex1
    vector<int> test1= { 4,5,2,1,3};
    int r1= 2;
    tuplefind tuplefind1(test1,r1);
    vector<Pair> pairs1= tuplefind1.findPairs();

    cout<<"Example 1:"<<endl;
    cout<<"Array: {4,5,2,1,3},r= 2"<<endl;
    tuplefind1.printPairs(pairs1);

    //eg2
    vector<int> test2= {6,1,4,10,9};
    int r2= 2;
    tuplefind tuplefind2(test2,r2);
    vector<Pair> pairs2=  tuplefind2.findPairs();

    cout<<"Example 2:"<<endl ;
    cout<<"Array: {6,1,4,10,9},r= 2" <<endl;
    tuplefind2.printPairs(pairs2);

    return 0;
}
