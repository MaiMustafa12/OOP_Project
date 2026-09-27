#include<iostream>
#include"Image_Class.h"
#include <string>
#include <algorithm>
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


/* 
Filter 2 --> black and white 
*/
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


/* 
Filter #6 --> rotate
*/
void rotate_filter(Image &image)
{

int angle ; 

cout << "choose rotation angle (90, 180, 270): "<< endl;

cin >> angle ;

Image rotated ( image.height, image.width );

if ( angle == 90 ) 
{
for (int i=0 ; i<image.width ; i++) 
{
for (int j = 0; j< image.height ; j++) 
{
for (int k=0 ; k<image.channels ; k++) {
                    rotated(image.height - 1 - j, i, k)
                        = image(i,j,k);
                }
}
}
}

    else if(angle == 180)
    {
        for(int i = 0; i < image.width; i++)
        {
            for(int j = 0; j < image.height; j++)
            {
                for(int k = 0; k < image.channels; k++)
                {
                    rotated(image.height - 1 - j,
                            image.width - 1 - i, k)
                        = image(i,j,k);
                }
            }
        }
    }

    else if(angle == 270)
    {
        for(int i = 0; i < image.width; i++)
        {
            for(int j = 0; j < image.height; j++)
            {
                for(int k = 0; k < image.channels; k++)
                {
                    rotated(j, image.width - 1 - i, k)
                        = image(i,j,k);
                }
            }
        }
    }

    image = rotated;
}
// ====== Filter 1 =====
void grayscale_filter(Image& image){
    for (int i = 0; i < image.width; i++){
        for (int j = 0; j < image.height; j++){
            int red = image(i, j, 0);
            int green = image(i, j, 1);
            int blue = image(i, j, 2);
            int avg = (red + green + blue) / 3;
            image(i, j, 0) = avg;
            image(i, j, 1) = avg;
            image(i, j, 2) = avg;
        }
    }
}
// ======Filter 5 =======
void flip_filter(Image& image){
    int choice;
    cout << "Choose flip type: " << endl;
    cout << "1 => flip horizontally" << endl;
    cout << "2 => flip vertically" << endl;
    cin >> choice;
    if (choice == 1){
        for (int i = 0; i < image.width / 2; i++){
            for (int j = 0; j < image.height; j++){
                for (int k = 0; k < 3; k++){
                    swap(image(i, j, k),image(image.width - 1 - i, j, k));
                }
            }
        }
    }else if (choice == 2){
        for (int i = 0; i < image.width; i++){
            for (int j = 0; j < image.height / 2; j++){
                for (int k = 0; k < 3; k++){
                    swap(image(i, j, k),image(i, image.height - 1 - j, k));
                }
            }
        }
    }
}
int main() 
{ 
    string imageName; 
    int choice; 
 
    cout << "choose image: "; 
    cin >> imageName; 
 
    Image image(imageName); 
 
    cout << "Choose filter:" << endl; 
    cout << "1 => Grayscale" << endl; 
    cout << "2 => Black and White" << endl; 
    cout << "3 => Darken / Lighten" << endl; 
    cout << "4 => Infrared" << endl; 
    cout << "5 => Flip" << endl; 
    cout << "6 => Rotate" << endl; 
    cout << "7 => Add Frame" << endl; 
 
    cin >> choice; 
 
    if (choice == 1) 
    { 
        grayscale_filter(image); 
    } 
    else if (choice == 2) 
    { 
        BW_filter(image); 
    } 
    else if (choice == 3) 
    { 
        darken_lighten_filter(image); 
    } 
    else if (choice == 4) 
    { 
        infrared_filter(image); 
    } 
    else if (choice == 5) 
    { 
        flip_filter(image); 
    } 
    else if (choice == 6) 
    { 
        rotate_filter(image); 
    } 
    else if (choice == 7) 
    { 
        add_frame_filter(image); 
    } 
    else 
    { 
        cout << "Invalid choice!" << endl; 
        return 0; 
    } 
     
 string newImageName;
string extension;

cout << "choose new image name : ";
cin >> newImageName;

cout << "choose extension (.JPG, .JPEG, .BMP, .PNG, .TGA): ";
cin >> extension;

newImageName = newImageName + extension;

image.saveImage(newImageName);

cout << "Image saved successfully!" << endl;
 
    cout << "Image saved successfully!" << endl; 
 
    return 0; 
}
