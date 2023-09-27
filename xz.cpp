#include<iostream>
#include<math.h>
int order[3];

void sortk(double k1,double k2, double k3);
int whichshape(double k1[2][2],double k2[2][2],int i,int j);
double comp_xiebian(double kx,double ky,double rx, double ry,double x,double y);

int main(){
    std::cout<<"<<<<-------------start line------------------->>\n";
    std::cout<<"input the x,y  postion   4groups:"<<std::endl;
    std::cout<<"根据输入的4组xy坐标  判断是  矩形  梯形 菱形  正方形！"<<std::endl;

    // double ax,ay,bx,by,cx,cy,dx,dy;
    // std::cout<<"输入第一个点："<<std::endl;
    // std::cin>>ax>>ay;
    // std::cout<<"输入第二个点："<<std::endl;
    // std::cin>>bx>>by;
    // std::cout<<"输入第三个点："<<std::endl;
    // std::cin>>cx>>cy;
    // std::cout<<"输入第四个点："<<std::endl;
    // std::cin>>dx>>dy;
    double a[4][2];
    for(int i=0;i<4;i++){
        std::cout<<"请输入第"<<(i+1)<<"个点的(x,y)坐标"<<std::endl;
        for (int j=0;j<2;j++){
            
            std::cin>>a[i][j];
        }
    }

    double k1,k2,k3;
    double kx=a[0][0];
    double ky=a[0][1];
    //  key 点到第二个节点的连线的斜率
    double cx,cy;
    cx=a[1][0]-kx;
    cy=a[1][1]-ky;
    double xiebian=sqrt(cx*cx +cy*cy);
    k1=cy/xiebian;

    cx=a[2][0]-kx;
    cy=a[2][1]-ky;
    xiebian=sqrt(cx*cx+cy*cy);
    k2=cy/xiebian;

    cx=a[3][0]-kx;
    cy=a[3][1]-ky;
    xiebian=sqrt(cx*cx+cy*cy);
    k3=cy/xiebian;

    for(int i=1;i<=3;i++) order[i]=i;

    if ((k1==k2  && k1==k3) ||(k1==k2) ||(k1==k3)||(k2==k3)){
        std::cout<<"error ,不能组合成四边形！"<<std::endl;
    }else{
        sortk(k1,k2,k3);
        std::cout<<"k1="<<k1<<",k2="<<k2<<",k3="<<k3<<std::endl;
        int aa=order[1];
        int bb=aa;
        double rx=a[bb][0];
        double ry=a[bb][1];
        //std::cout<<bb<<"::"<<rx<<"  "<<ry<<std::endl;

        //重新计算另外两个点的连线的斜率 排除那个远端的点
        int conid[2];
        double newk1[2][2];  //第一个是节点 个数   第二个表示【     k斜率  斜边边长】
        int j=0;
        for (int i=1;i<4;i++){
            if(i==bb) continue;
            cx=a[i][0]-kx;
            cy=a[i][1]-ky;
            xiebian=sqrt(cx*cx+cy*cy);
            newk1[j][1]=xiebian;
            newk1[j][0]=cy/xiebian;
            conid[j]=i;             
            j++;
        }

        

        //远端节点的 斜率和长度
        int conid2[2];
        double newk2[2][2];
        j=0;
        for(int i=1;i<4;i++){
            if (i==bb)continue;
            cx=a[i][0]-rx;
            cy=a[i][1]-ry;
            xiebian=sqrt(cx*cx+cy*cy);
            newk2[j][1]=xiebian;
            if (cy!=0) cy=-cy;
            newk2[j][0]=cy/xiebian;
            conid2[j]=i;
            j++;
        }
        for(int i=0;i<2;i++){             
            std::cout<<conid2[i]<<"::"<<newk2[i][0]<<"  "<<newk2[i][1]<<std::endl;             
        }

        //对比这几组斜率和长度
        int shapes[2]={0,0};
        int n=0;
        for(int i=0;i<2;i++){
            int ca=conid[i];
            for(int j=0;j<2;j++){
                if (ca!=conid2[j]){
                    //对比 newk1 和newk2中 对应的  i  和j下标中的斜率 边长
                    int shape=whichshape(newk1,newk2,i,j);
                    shapes[n]=shape;
                    n++;
                }
            }
        }
        int ss=shapes[0];
        switch (ss)
        {
        case 0:
            if(shapes[1]==0){
                std::cout<<"这是普通的四边形"<<std::endl;
            }else if (shapes[1]==1){
                std::cout<<"这是梯形！"<<std::endl;
            }else if (shapes[1]==2){
                std::cout<<"this is wrong!\n";
            }else{
                std::cout<<"这是普通的四边形"<<std::endl;
            }
            break;
        case 1:  //斜率相同 长度不同
            if(shapes[1]==0){
                std::cout<<"这是梯形！"<<std::endl;
            }else if(shapes[1]==1){
                std::cout<<"this is wrong!\n";
            }else if(shapes[1]==2){
                //斜率相同 长度不同 和  斜率长度都相同 不能配对
                std::cout<<"this is wrong!\n";
            }else{
                std::cout<<"这是梯形！"<<std::endl;
            }
        case 2: //斜率和长度都相同
            if(shapes[1]==0){
                std::cout<<"this is wrong!\n";
            }else if(shapes[1]==1){
                // 斜率相同 长度不同
                std::cout<<"this is wrong!\n";
            }else if(shapes[1]==2){
                //判断是否是直角
                //对角线的长度   kx  ky   rx ry    
                double aaa=kx-rx;
                double bbb=ky-ry;
                double ccc=sqrt(aaa*aaa+bbb*bbb);

                //找到链接同一个节点的边
                int temp=-1;
                for(int ii=0;ii<2;ii++){
                    int kk1=conid[ii];
                    for(int jj=0;jj<2;jj++){
                        if(kk1==conid2[jj]){
                            temp=kk1;
                             break;
                        }
                    }
                    if (temp!=-1)break;
                }
                // temp 编号
                //计算 两个节点到 temp节点的边长
                double xiebian_temp= comp_xiebian(kx,ky,rx,ry,a[temp][0],a[temp][1]);
                // 对边相等 且斜率相同
                //比较临边
                std::cout<<ccc<<"   "<<xiebian_temp<<std::endl;
                if (xiebian_temp==ccc){
                    //证明是直角
                    if(newk1[0][1]!=newk1[1][1]){
                        //邻边不等
                        std::cout<<"这个是矩形！"<<std::endl; 
                    }else{
                        std::cout<<"这个是正方形"<<std::endl;
                    }
                }else{
                    if(newk1[0][1]!=newk1[1][1]){
                        std::cout<<"这个是平行四边形！"<<std::endl; 
                    }else{
                        std::cout<<"这个是菱形！"<<std::endl; 
                    }
                }
                
            }
            break;
        
        default:
            // 3 对边相等， 但是斜率不同
            if(shapes[1]==0){
                std::cout<<"这是普通的四边形"<<std::endl;
            }else if(shapes[1]==1){
                // 斜率相等  长度不同
                std::cout<<"这是梯形"<<std::endl;
            }else if(shapes[1]==2){
                // 斜率相同 长度相同
                std::cout<<"this is wrong!\n";
            }else{
                //长度相同  斜率不同
                std::cout<<"这是普通的四边形"<<std::endl;
            }
            break;
        }
        std::cout<<"<<<<<<--------------end line---------------->>>>>>"<<std::endl;

    }

}
double comp_xiebian(double kx,double ky,double rx, double ry,double x,double y){
    double k_x=kx-x;
    double k_y=ky-y;
    double kk1=sqrt(k_x*k_x+k_y*k_y);
    double r_x=rx-x;
    double r_y=ry-y;
    double kk2=sqrt(r_x*r_x+r_y*r_y);

    double xiebian=sqrt(kk1*kk1+kk2*kk2);
    return xiebian;
}
void sortk(double k1,double k2, double k3){
    double max=k1;
    if (k1>k2){
        if (k2<k3){
            if(k1<k3){
                //k3  k1  k2
                order[0]=3;order[1]=1;order[2]=2;
            }else{
                //k1  k3  k2
                order[2]=3;
                order[3]=2;
            }
        }
    }else{
        if(k1>k3){
            //k2   k1  k3
            order[0]=2;order[1]=1;order[2]=3;
        }else{
            //k2>k1
            // k3>k1
            if (k2>k3){
                //k2  k3  k1
                order[0]=2;order[1]=3;order[2]=1;
            }else{
                //k3  k2  k1
                order[0]=3;order[1]=2;order[3]=1;
            }
        }
    }
}
int whichshape(double k1[2][2], double k2[2][2],int i,int j ){
    double xiebian1=k1[i][1];
    double  xielv1=k1[i][0];
    double  xiebian2=k2[j][1];
    double  xielv2=k2[j][0];
    if (xiebian1!=xiebian2){
        if(xielv2==xielv1){
            // 梯形  斜率相等  长度不同
            return 1;
        }else{
            // 没有规则 对边不等 并且斜率不同
            return 0;
        }
    }else{
        if(xielv1==xielv2){
            //对边相等， 斜率也相等
            return 2;
        }else{
            //对边相等， 但是斜率不同
            return 3;
        }
    }
    
}
