#include "cv.hpp"
#include "stdio.h"
#include "stdlib.h"
Mat img;//(400,400,CV_8UC1,Scalar(255));
int isvalid(int i,int j)
{
  if(i<0||j<0||i>=img.rows||j>=img.cols||img.at<uchar>(i,j)<250)
    return 0;
  else
    return 1;
}
typedef struct NODE
{
  int i,j;
  struct NODE *pre;
}Node;
Node *node;
int flage=1;
Node end;
int flag;
int a=0;
int color(int i)
{
  if(end.i==node[i].i&&end.j==node[i].j)
    {
      flag=1;
      end.pre=node+i;
      return 0;
    }
  img.at<uchar>(node[i].i,node[i].j)=100;
  if(isvalid((node[i].i),(node[i].j)-1)==1)
    {
      node[flage].i=(node[i].i);
      node[flage].j=(node[i].j)-1;
      img.at<uchar>((node[i].i),(node[i].j)-1)=100;
      node[flage].pre=node+i;
      flage++;
    }

  if(isvalid((node[i].i)+1,node[i].j)==1)
    {
      node[flage].i=(node[i].i)+1;
      node[flage].j=node[i].j;
      img.at<uchar>((node[i].i)+1,node[i].j)=100;
      node[flage].pre=node+i;
      flage++;
    }
 

  if(isvalid((node[i].i),(node[i].j)+1)==1)
    {
      node[flage].i=(node[i].i);
      node[flage].j=(node[i].j)+1;
      img.at<uchar>((node[i].i),(node[i].j)+1)=100;
      node[flage].pre=node+i;
      flage++;
    }
  if(isvalid((node[i].i)-1,(node[i].j)+1)==1)
   {
      node[flage].i=(node[i].i)-1;
      node[flage].j=(node[i].j)+1;
      img.at<uchar>((node[i].i)-1,(node[i].j)+1)=100;
      node[flage].pre=node+i;
      flage++;
    }  
  
  if(isvalid((node[i].i)-1,node[i].j)==1)
    {
      node[flage].i=(node[i].i)-1;
      node[flage].j=node[i].j;
      img.at<uchar>((node[i].i)-1,node[i].j)=100;
      node[flage].pre=node+i;
      flage++;
    }
 
  if(isvalid((node[i].i)+1,(node[i].j)-1)==1)
    {
      node[flage].i=(node[i].i)+1;
      node[flage].j=(node[i].j)-1;
      img.at<uchar>((node[i].i)+1,(node[i].j)-1)=100;
      node[flage].pre=node+i;
      flage++;
    }
  if(isvalid((node[i].i)+1,(node[i].j)+1)==1)
    {
      node[flage].i=(node[i].i)+1;
      node[flage].j=(node[i].j)+1;
      img.at<uchar>((node[i].i)+1,(node[i].j)+1)=100;
      node[flage].pre=node+i;
      flage++;
    }
 if(isvalid((node[i].i)-1,(node[i].j)-1)==1)
    {
      node[flage].i=(node[i].i)-1;
      node[flage].j=(node[i].j)-1;
      img.at<uchar>((node[i].i)-1,(node[i].j)-1)=100;
      node[flage].pre=node+i;
      flage++;
    }
 if(isvalid((node[i].i)-1,(node[i].j)-1)==1)
    {
      node[flage].i=(node[i].i)-1;
      node[flage].j=(node[i].j)-1;
      img.at<uchar>((node[i].i)-1,(node[i].j)-1)=100;
      node[flage].pre=node+i;
      flage++;
    }
 
 
  
}
// void fun(int event,int x,int y,int flage,void *data)
// {
//   Mat *img1=(Mat*)data;
//   if(event==EVENT_LBUTTONDOWN)
//     {
//       //node[0].i=y;
//       //node[0].j=x;
//       //   end.i=y;
//       //end.j=x;
//       // return 0;
//        cout<<"(x,y)=("<<x<<","<<y<<")"<<endl; 
//     }
// }
int main()
{
  img=imread("graph1.png",CV_LOAD_IMAGE_GRAYSCALE);
  Mat img1(img.rows,img.cols,CV_8UC3);
  //setMouseCallback("2d",fun,(void*)&img);
  //imshow("2d",img);
  //waitKey(0);
  int n=img.rows*img.cols,count=1;
  for(int i=0;i<img.rows;i++)
    for(int j=0;j<img.cols;j++)
      if(img.at<uchar>(i,j)>=250)
	count++;
  for(int i=0;i<img.rows;i++)
    {
      for(int j=0;j<img.cols;j++)
	{
	  if(img.at<uchar>(i,j)>250)
	    {
	      for(int a=0;a<3;a++)
		img1.at<Vec3b>(i,j)[a]=255;
	    }
	  if(img.at<uchar>(i,j)<5)
	    {
	      for(int a=0;a<3;a++)
		img1.at<Vec3b>(i,j)[a]=0;
	    }
	}
    }
  node =(Node*)malloc(sizeof(Node)*count);
  end.i=305;
  end.j=217;
  //printf("%d\t%d\n",img.rows,img.cols);
  //printf("enter starting i,j");
  //scanf("%d%d",&end.i,&end.j);
  node[0].i=46;
  node[0].j=32;
  node[0].pre=NULL;
  for(int i=0;i<count-4;i++)
    {
      if(flag==1)
	break;
      color(i);
      imshow("gf",img);
      //  waitKey(1);
    }
  Node *p;
  p=&end;
  while(p!=NULL)
    {
      img1.at<Vec3b>(p->i,p->j)[2]=255;
      img1.at<Vec3b>(p->i,p->j)[0]=0;
      img1.at<Vec3b>(p->i,p->j)[1]=0;
      p=p->pre;
      //imshow("asfs",img1);
      // waitKey(20);
    }
 imshow("asfs",img1);
  waitKey(0);
  return 0;
}
