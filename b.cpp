#include<iostream>

int main(){
    // std::cout<<"please input the level ,and the convert it to the score"<<std::endl;

    // std::string level="";
    // std::cin>>level;
    // unsigned int ll=level.length();
    // if (ll>2 || ll==0){
    //     std::cout<<"the input string is:::"<<level<<std::endl;
    //     std::cout<<"It does not match any level, and do not get any score!"<<std::endl;
    // }else{
    //     char f=level[0];
    //     const int A='A';
    //     double score=0.0;
    //     switch (f)
    //     {
    //     case A: score=3.7;   
    //         break;
    //     case A+1:score=3.0;break;
    //     case A+2:score=2.0;break;
    //     case A+3:score=1.0;break;
    //     default:score=0.0;break;
        
    //     }
    //     std::cout<<"score::"<<score<<std::endl;
    //     if (ll==2  && score!=0){
    //         char s=level[1];
    //         if (s=='+' && (f>='A'  && f<='D')){
    //             score+=0.3;
    //         }else{
    //             score-=0.3;
    //         }
    //     }
    //     std::cout<<"the score is ::"<<score<<std::endl;

    // }
    
        double fenshu=0.0;
        std::string rslevel="";
        std::cout<<"please input the score and then get the level:"<<std::endl;

        std::cin>>fenshu;
        if(fenshu>=3.4){
            if (fenshu <3.7){
                rslevel="A-";
            }else if(fenshu>3.7){
                rslevel="A+";
            }else{
                rslevel="A";
            }
        }else if(fenshu <3.4 && fenshu>=2.7){
            if (fenshu>3){
                rslevel="B+";
            }else if(fenshu==3){
                rslevel="B";
            }else{
                rslevel="B-";
            }
        }else if (fenshu<2.7 && fenshu>=1.7){
            if (fenshu>2 ){
                rslevel="C+";

            }else if(fenshu == 2.0){
                rslevel="C";
            }else{
                rslevel="C-";
            }
        }else if(fenshu<1.7 && fenshu>=0.7){
            if (fenshu>1.0){
                rslevel="D+";
            }else if(fenshu==1.0){
                rslevel="D";
            }else{
                rslevel="D-";
            }
        }else{
            rslevel="F";
        }
    std::cout<<"the level is::"<<rslevel<<std::endl;

    std::cout<<"input shu:"<<std::endl;
    double a1,a2,a3;
    std::cin>>a1>>a2>>a3;

    double max=a1;
    if (a1<a2){
        max=a2;
        if (max<a3){
            max=a3;
        }
    }else{
        if(max<a3){
            max=a3;
        }
    }
    std::cout<<"the max number is:: "<<max<<std::endl;
    return 0;
    

}