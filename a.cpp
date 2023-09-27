#include<iostream>
#include<string>
#include<string.h>

int main(){
    double r=2.0;

    if (r*r==2){
        std::cout<<"ok"<<std::endl;

    }else{
        std::cout<<"bad"<<std::endl;
    }
    std::string a="";
    while(1){
        std::cout<<"please input a string(A 2..10 J Q K; D H S C):"<<std::endl;
        std::cin>>a;
        
        if (a=="qu") break;
        long long unsigned int ll=a.length();
        // if (ll!=2 ) {
        //     std::cout<<"please input  two characters:";
        //     continue;
        // }
        std::string first="";
        int b=int(a[0]);   //A  65
        int c=int('2');   //"2"的数值
        int d=int('9');
        if (b>=c && b<=d){
            if (ll!=2) continue;
            first=a[0];
        }else{
            if(a[0]!='1' && ll!=2) continue;
            switch (b)
            {
                case 65:first="Ace";           
                    break;
                case 65+(int('J'-'A')):first="Jack";break;
                case 65+(int('Q'-'A')):first="Queen";break;
                case 65+(int('K'-'A')):first="King";break;
                case int('1'): first="10";break;        
                default:first="nothing";
                    break;
            }
        }
        
        
        
        std::string second="";       
        std::string bs=a.substr(1,1);
        int bb=int(bs[0]);
        
        //int dd=int('D');
        switch (bb)
        {
        case 65+int('D'-'A'):second="Fangkuai";            
            break;
        case 65+int('H'-'A'):second="Hongxin";break;
        case 65+int('S'-'A'):second="Heitao";break;
        default:second="Meihua";break;
        
        }
        std::cout<<"the final result!"<<std::endl;
        std::cout<<"rs:"<<first<<" of "<<second<<std::endl;
            


    }

    return 0;
}