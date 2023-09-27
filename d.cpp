#include <iostream>

int main(){
    double  x=0;
    int married=0;  // 0 没有结婚
    std::cout<<"please input your income :: "<<std::endl;
    std::cin>>x;
    std::cout<<"Are you married?0  no   1  yes!"<<std::endl;

    
    std::cin>>married;
    int level=0;
    if (married==0){
        if (x<=8000 ){
            level=1;
        }else if(x>8000 && x<=32000  ){
            level=2;
        }else if(x>32000 ){
            level=3;
        }
    }else{
        if (x<=16000  ){
            level=4;
        }else if(x>16000 && x<=64000 ){
            level=5;
        }else if(x>64000  ){
            level=6;
        }
    }
   
    
    double shui=0;
    switch (level)
    {
    case 1:shui=x*0.1;break;
        /* code */
    case 2:shui=800+0.15*(x-8000);break;
    case 3:shui=4400+0.25*(x-32000);break;
    case 4:shui=0.1*x;break;
    case 5 :shui=1600+0.15*(x-16000);break;
    case 6:shui=8800+0.25*(x-64000);break;
    
    default:
        break;
    }
    std::cout<<"the shuikuan  tax is  :"<<shui<<std::endl;
    return 0;
}