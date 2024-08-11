#include <c++/stdlib>
using namespace std;

int main() {
	int n;
    cout<<"No. of teams:";
    cin>>n;
    string s;
    getline(cin,team);
    int health[n];
    for(int j=0;j<n;j++){
        cin>>health[j];
    }
    int pos[n];
    for(int i=0;i<n;i++){
        cin>>pos[i];
    }
    for(int i=0;i<s.size();i+=2){
       if(s[i]!=s[i+1]){
           if(s[i]=="D"){
               if(pos[i]>pos[i+1]){
                   temp.push_back(max(health[i],health[i+1])-1);
                   
               }else{
                   temp.push_back({health[i],health[i+1]});
                   
               }
           }else{
               if(pos[i]<pos[i+1]){
                   temp.push_back(max(health[i],health[i+1])-1);
               }else{
                   temp.push_back({health[i],health[i+1]});
               }
           }
       }
   }
}