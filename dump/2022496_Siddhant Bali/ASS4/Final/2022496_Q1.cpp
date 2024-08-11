#include<iostream>
#include<vector>
using namespace std;

//coordination func
struct coord{int x;int y;coord(int x, int y) : x(x), y(y){}};

//2d board func
struct BOard{
vector<vector<char>> table;
    int rel;
    int attrib;
    
    BOard(const vector<vector<char>>& inputtable) : table(inputtable), rel(inputtable.size()), attrib(inputtable[0].size()){}
    
    char& operator()(int i, int y1) { 
        return table[i][y1];
    }
    
    char operator()(int i, int y1) const {
return table[i][y1];}
    
    bool valid(int i, int y1) const{
        return (i >= 0 && i < rel && y1 >= 0 && y1 < attrib);
    }
    
    bool isUnfilled(int i, int y1) const{
        return (valid(i, y1) && table[i][y1] == 'N');
    }
};

//flood fill al sides 
void floodFill(BOard& bOard, int i, int y1){
    if (!bOard.valid(i, y1) || bOard(i, y1) != 'N')
        return;

    bOard(i, y1) =  'F';

int margin=1;
floodFill(bOard, i+margin,y1);
floodFill(bOard, i-margin,y1);
floodFill(bOard, i, y1+ margin);
floodFill(bOard, i, y1-margin);
}

//final func
void floodreport(BOard& bOard){
    // flood check N and F
    for ( int i =0 ; i < bOard.rel; ++i){
        for   (int y1 = 0; y1< bOard.attrib;++y1){
            if  (bOard.isUnfilled(i, y1)){
                floodFill(bOard, i, y1);return; //per region itete
            }
        }
    }
}


//board print
void printBOard(const BOard& bOard){
    for (int i = 0; i< bOard.rel; ++i){
        for(int y1 =0; y1 <bOard.attrib; ++y1){
            cout << bOard(i, y1) << " ";
        }
        cout<<endl;
    }
}

//driver code
int main(){
    vector<vector<char>> test ={
       {'F', 'F', 'F', 'F'},
       {'F', 'N', 'N','F'},
       {'F', 'F','N', 'F'},
       {'F', 'N','F', 'F'}
    };
    BOard bOard(test);
     floodreport(bOard);
     printBOard(bOard);

    return 0;
}
