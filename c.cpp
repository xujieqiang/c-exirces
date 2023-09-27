#include<iostream>
#include<string>
#include<iomanip>

int main(){
    std::cout<<"please three  words and then sort by the orders in dictionary!"<<std::endl;
    std::string a1,a2,a3;
    std::cin>>a1>>a2>>a3;

    //比较a1  a2  a3的每一个位上的字符的顺序
    std::cout<<std::setw(20)<<a1<<std::endl;
    char a,b,c;
    if (!(a1.length()>=1 && a2.length()>=1 && a3.length()>=1)){
        std::cout<<"one or more word is empty! "<<std::endl;
    }else{
        a=a1[0];
        b=a2[0];
        c=a3[0];
        std::string first ,second, third;
        if(a<b){
           
            if (b<c){  
                 first=a1;              
                second=a2;
                third=a3;
            }else{
                if (a<c){
                    //a c b
                    first=a1;
                    second=a3;
                    third=a2;
                }else{
                    // c a b
                    first=a3;
                    second=a1;
                    third=a2;
                }
            }
        }else{
            if(a<c){
                //b  a  c
                first=a2;
                second=a1;
                third=a3;
            }else{
                if (b>c){
                    //c b a
                    first=a3;
                    second=a2;
                    third=a1;
                }else{
                    //b c a
                    first=a2;
                    second=a3;
                    third=a1;
                }
            }
        }


        std::cout<<"the order is:  "<<first<<"  "<<second<<"  "<<third<<std::endl;
    }
    return 0;
}