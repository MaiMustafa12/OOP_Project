#include<iostream>
#include"Image_Class.h"
using namespace std;
/*
void invert_filter(Image &image){

     for(int i=0 ; i<image.width ; ++i){
        for(int j=0 ; j<image.height ; ++j){
            for(int k=0 ; k<image.channels ; ++k){
        
            image(i,j,k)=255-image(i,j,k);
            }
        }
    }
}*/
void darken_lighten_filter(Image &image){
    string option;
    double level;
    cout<<" Dark or Light :"<<endl;
    cin>>option;
    cout<<" choose the level from 0 to 100% : "<<endl;
    cin>>level;
    level=level/100 ;
     if (option=="dark"){
      for(int i=0 ; i<image.width ; ++i){
        for(int j=0 ; j<image.height ; ++j){
            for(int k=0 ; k<image.channels ; ++k){
                    image(i,j,k)=(1-level)*image(i,j,k);
            }}}
     }else{
        for(int i=0 ; i<image.width ; ++i){
        for(int j=0 ; j<image.height ; ++j){
            for(int k=0 ; k<image.channels ; ++k){
                image(i,j,k)=image(i,j,k)+((255-image(i,j,k))*level);
                  if(image(i,j,k)>255){
                     image(i,j,k)=255;}}}}}}

void add_frame_filter(Image &image){
    int r=255, g=255, b=0, size=15;
    for(int i=0 ; i<image.width ; ++i){
        for(int j=0 ; j<image.height ; ++j){
            if (i < size || i >= image.width - size || j < size || j >= image.height - size){
                image(i,j,0)=r;
                image(i,j,1)=g;
                image(i,j,2)=b;
            }
        }
    }
}

void blur_filter(Image &image){
    Image copy = image;
    for(int i=0 ; i<image.width ; ++i){
        for(int j=0 ; j<image.height ; ++j){
            for(int k=0 ; k<image.channels ; ++k){
                int sum = 0;
                int count = 0;
                for (int ni = -1; ni <= 1; ++ni) {
                    for (int nj = -1; nj <= 1; ++nj) {
                        int check_i = i + ni;
                        int check_j = j + nj;
                        if (check_i >= 0 && check_i < image.width && check_j >= 0 && check_j < image.height) {
                            sum += copy(check_i, check_j, k);
                            count++;
                        }
                    }
                }
                image(i, j, k) = sum / count;
            }
        }
    }
}

void infrared_filter(Image &image){
    for(int i=0 ; i<image.width ; ++i){
        for(int j=0 ; j<image.height ; ++j){
            int red = image(i,j,0);
            image(i,j,0)=255;
            image(i,j,1)=255-red;
            image(i,j,2)=255-red;
        }
    }
}

void invert_filter(Image &image){
    for(int i=0 ; i<image.width ; ++i){
        for(int j=0 ; j<image.height ; ++j){
            for(int k=0 ; k<image.channels ; ++k){
                image(i,j,k)=255-image(i,j,k);
            }
        }
    }
}


int main(){
    Image image("luffy.jpg");

    add_frame_filter(image);
    // blur_filter(image);
    // infrared_filter(image);
    // invert_filter(image);
    // darken_lighten_filter(image);

    image.saveImage("hello.png");
    return 0;
}

