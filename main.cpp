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

/* 
Filter 2 --> black and white 
void BW filter(Image &image){

     for(int i=0 ; i<image.width ; i++){
        for(int j=0 ; j<image.height ; j++){
        int avg = 0;
            for(int k=0 ; k<image.channels ; k++){
        avg += image (i,j,k);
}
        //calc avg - bright or dark

        avg = avg/3;

        // covert bright to white and dark to black 

        for (int k = 0; k < 3; k++) {

            if (avg > 128)
                {
                    image(i, j, k) = 255; //bright //white
                }
                else
                {
                    image(i, j, k) = 0; //dark //black
                }
}
            }
        }
    }
}*/
void BW_filter(Image &image) {
   
    string option;
    double level ;

    cout << "coloured or B&W " << endl;
    cin >> option ;

    if (option == "B&W") 
    {
            
    cout << " choose level from 0 to 100% : " << endl;
    cin >> level ;

    level = level/100 ;

        for(int i=0 ; i<image.width ; i++)
        {
        for(int j=0 ; j<image.height ; j++)
        {
        int avg = 0;

        // calc avg

            for(int k=0 ; k<image.channels ; k++)
            {

        avg += image (i,j,k);
            }
        //calc avg --> bright or dark

        avg = avg/image.channels;

        // covert bright to white and dark to black 
        int BW ;

            if (avg > 128)
                {
                    BW = 255; //bright //white
                }
                else
                {
                    BW = 0; //dark //black
                }

                // apply intensity level choosed of filter to img
                 for (int k =0; k< image.channels ; k++) 
                 {
                    image (i,j,k)= (image (i,j,k) * (1-level)) + (BW*level) ;

                 }

            }
        }
    }
    } 

    int main()
{
    Image image("luffy.jpg");

    BW_filter(image);

    image.saveImage("luffy.png");

    return 0;
}
