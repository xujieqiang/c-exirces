#include<iostream>
#include<math.h>
int order[3];

void sortk(double k1,double k2, double k3);
int whichshape(double k1[2][2],double k2[2][2],int i,int j);
double comp_xiebian(double kx,double ky,double rx, double ry,double x,double y);

int main(){
    std::cout<<"<<<<-------------start line------------------->>\n";
    std::cout<<"input the x,y  postion   4groups:"<<std::endl;
    std::cout<<"���������4��xy����  �ж���  ����  ���� ����  �����Σ�"<<std::endl;

    // double ax,ay,bx,by,cx,cy,dx,dy;
    // std::cout<<"�����һ���㣺"<<std::endl;
    // std::cin>>ax>>ay;
    // std::cout<<"����ڶ����㣺"<<std::endl;
    // std::cin>>bx>>by;
    // std::cout<<"����������㣺"<<std::endl;
    // std::cin>>cx>>cy;
    // std::cout<<"������ĸ��㣺"<<std::endl;
    // std::cin>>dx>>dy;
    double a[4][2];
    for(int i=0;i<4;i++){
        std::cout<<"�������"<<(i+1)<<"�����(x,y)����"<<std::endl;
        for (int j=0;j<2;j++){
            
            std::cin>>a[i][j];
        }
    }

    double k1,k2,k3;
    double kx=a[0][0];
    double ky=a[0][1];
    //  key �㵽�ڶ����ڵ�����ߵ�б��
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
        std::cout<<"error ,������ϳ��ı��Σ�"<<std::endl;
    }else{
        sortk(k1,k2,k3);
        std::cout<<"k1="<<k1<<",k2="<<k2<<",k3="<<k3<<std::endl;
        int aa=order[1];
        int bb=aa;
        double rx=a[bb][0];
        double ry=a[bb][1];
        //std::cout<<bb<<"::"<<rx<<"  "<<ry<<std::endl;

        //���¼�����������������ߵ�б�� �ų��Ǹ�Զ�˵ĵ�
        int conid[2];
        double newk1[2][2];  //��һ���ǽڵ� ����   �ڶ�����ʾ��     kб��  б�߱߳���
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

        

        //Զ�˽ڵ�� б�ʺͳ���
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

        //�Ա��⼸��б�ʺͳ���
        int shapes[2]={0,0};
        int n=0;
        for(int i=0;i<2;i++){
            int ca=conid[i];
            for(int j=0;j<2;j++){
                if (ca!=conid2[j]){
                    //�Ա� newk1 ��newk2�� ��Ӧ��  i  ��j�±��е�б�� �߳�
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
                std::cout<<"������ͨ���ı���"<<std::endl;
            }else if (shapes[1]==1){
                std::cout<<"�������Σ�"<<std::endl;
            }else if (shapes[1]==2){
                std::cout<<"this is wrong!\n";
            }else{
                std::cout<<"������ͨ���ı���"<<std::endl;
            }
            break;
        case 1:  //б����ͬ ���Ȳ�ͬ
            if(shapes[1]==0){
                std::cout<<"�������Σ�"<<std::endl;
            }else if(shapes[1]==1){
                std::cout<<"this is wrong!\n";
            }else if(shapes[1]==2){
                //б����ͬ ���Ȳ�ͬ ��  б�ʳ��ȶ���ͬ �������
                std::cout<<"this is wrong!\n";
            }else{
                std::cout<<"�������Σ�"<<std::endl;
            }
        case 2: //б�ʺͳ��ȶ���ͬ
            if(shapes[1]==0){
                std::cout<<"this is wrong!\n";
            }else if(shapes[1]==1){
                // б����ͬ ���Ȳ�ͬ
                std::cout<<"this is wrong!\n";
            }else if(shapes[1]==2){
                //�ж��Ƿ���ֱ��
                //�Խ��ߵĳ���   kx  ky   rx ry    
                double aaa=kx-rx;
                double bbb=ky-ry;
                double ccc=sqrt(aaa*aaa+bbb*bbb);

                //�ҵ�����ͬһ���ڵ�ı�
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
                // temp ���
                //���� �����ڵ㵽 temp�ڵ�ı߳�
                double xiebian_temp= comp_xiebian(kx,ky,rx,ry,a[temp][0],a[temp][1]);
                // �Ա���� ��б����ͬ
                //�Ƚ��ٱ�
                std::cout<<ccc<<"   "<<xiebian_temp<<std::endl;
                if (xiebian_temp==ccc){
                    //֤����ֱ��
                    if(newk1[0][1]!=newk1[1][1]){
                        //�ڱ߲���
                        std::cout<<"����Ǿ��Σ�"<<std::endl; 
                    }else{
                        std::cout<<"�����������"<<std::endl;
                    }
                }else{
                    if(newk1[0][1]!=newk1[1][1]){
                        std::cout<<"�����ƽ���ı��Σ�"<<std::endl; 
                    }else{
                        std::cout<<"��������Σ�"<<std::endl; 
                    }
                }
                
            }
            break;
        
        default:
            // 3 �Ա���ȣ� ����б�ʲ�ͬ
            if(shapes[1]==0){
                std::cout<<"������ͨ���ı���"<<std::endl;
            }else if(shapes[1]==1){
                // б�����  ���Ȳ�ͬ
                std::cout<<"��������"<<std::endl;
            }else if(shapes[1]==2){
                // б����ͬ ������ͬ
                std::cout<<"this is wrong!\n";
            }else{
                //������ͬ  б�ʲ�ͬ
                std::cout<<"������ͨ���ı���"<<std::endl;
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
            // ����  б�����  ���Ȳ�ͬ
            return 1;
        }else{
            // û�й��� �Ա߲��� ����б�ʲ�ͬ
            return 0;
        }
    }else{
        if(xielv1==xielv2){
            //�Ա���ȣ� б��Ҳ���
            return 2;
        }else{
            //�Ա���ȣ� ����б�ʲ�ͬ
            return 3;
        }
    }
    
}
