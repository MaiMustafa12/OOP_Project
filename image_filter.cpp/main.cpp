
// ====================================================================
// 📸 OOP Project - Image Processor (Milestone 1)
// 📌 Section: S15 & S16
// ====================================================================
// Team Members & Filter Contributions:
// --------------------------------------------------------------------
// 1. Mai Mustafa
//    - ID: 20251443
//    - Assigned Filters: 4 (Infrared), 8 (Inverted)
//
// 2. Fatma Alzahraa Aballah
//    - ID: 20250462
//    - Assigned Filters: 1 (Grayscale), 5 (Flip)
//
// 3. Malak 
//    - ID: 20251414
//    - Assigned Filters: 2 (Black and White), 6 (Rotate)
//
// 4. Mai Hussain 
//    - ID: 20251442
//    - Assigned Filters: 3 (Darken / Lighten), 7 (Add Frame)
// ====================================================================





#include <iostream>
#include "../include/Image_Class.h"
#include <string>
#include <algorithm>
using namespace std;

void invert_filter(Image &image)
{

    for (int i = 0; i < image.width; ++i)
    {
        for (int j = 0; j < image.height; ++j)
        {
            for (int k = 0; k < image.channels; ++k)
            {

                image(i, j, k) = 255 - image(i, j, k);
            }
        }
    }
}

void darken_lighten_filter(Image &image)
{
    string option;
    double level;

    cout << " Dark or Light :" << endl;
    cin >> option;

    cout << " choose the level from 0 to 100% : " << endl;
    cin >> level;

    level = level / 100;

    if (option == "dark")
    {
        for (int i = 0; i < image.width; ++i)
        {
            for (int j = 0; j < image.height; ++j)
            {
                for (int k = 0; k < image.channels; ++k)
                {
                    image(i, j, k) = (1 - level) * image(i, j, k);
                }
            }
        }
    }
    else
    {
        for (int i = 0; i < image.width; ++i)
        {
            for (int j = 0; j < image.height; ++j)
            {
                for (int k = 0; k < image.channels; ++k)
                {
                    image(i, j, k) = image(i, j, k) + ((255 - image(i, j, k)) * level);

                    if (image(i, j, k) > 255)
                    {
                        image(i, j, k) = 255;
                    }
                }
            }
        }
    }
}

void add_frame_filter(Image &image)
{
   
    int size;
    int color;
    cout << "Enter frame size:"<<endl;
    cin >> size;
    cout << "choose frame color:"<<endl;
    cout << "1=> red" << endl;
    cout << "2=> green" << endl;
    cout << "3=> blue" << endl;
    cout << "4=> black" << endl;
    cout << "5=> white" << endl;
    cout << "6=> gray" << endl;
    cin >> color;
    int r, g, b;
    if (color == 1) {
        r = 255, g = 0, b = 0;
    }
    else if (color == 2) {
        r = 0, g = 255, b = 0;
    }
    else if (color == 3) {
        r = 0, g = 0, b = 255;
    }
    else if (color == 4) {
        r = 0, g = 0, b = 0;
    }
    else if (color == 5) {
        r = 255, g = 255, b = 255;
    }
    else if (color == 6) {
        r = 124, g = 124, b = 124;
    }
    else {
        cout << "invalid color choice!"<<endl;
        return;

    for (int i = 0; i < image.width; ++i)
    {
        for (int j = 0; j < image.height; ++j)
        {

            if (i < size || i >= image.width - size ||
                j < size || j >= image.height - size)
            {

                image(i, j, 0) = r;
                image(i, j, 1) = g;
                image(i, j, 2) = b;
            }
        }
    }
}

void infrared_filter(Image &image)
{
    for (int i = 0; i < image.width; ++i)
    {
        for (int j = 0; j < image.height; ++j)
        {

            int red = image(i, j, 0);

            image(i, j, 0) = 255;
            image(i, j, 1) = 255 - red;
            image(i, j, 2) = 255 - red;
        }
    }
}

/*
Filter 2 --> black and white
*/
void BW_filter(Image &image)
{

    string option;
    double level;

    cout << "coloured or B&W " << endl;
    cin >> option;

    if (option == "B&W")
    {
        cout << " choose level from 0 to 100% : " << endl;
        cin >> level;

        level = level / 100;

        for (int i = 0; i < image.width; i++)
        {
            for (int j = 0; j < image.height; j++)
            {
                int avg = 0;

                // calc avg
                for (int k = 0; k < image.channels; k++)
                {
                    avg += image(i, j, k);
                }

                // calc avg --> bright or dark
                avg = avg / image.channels;

                // convert bright to white and dark to black
                int BW;

                if (avg > 128)
                {
                    BW = 255; // bright // white
                }
                else
                {
                    BW = 0; // dark // black
                }

                // apply intensity level chosen of filter to image
                for (int k = 0; k < image.channels; k++)
                {
                    image(i, j, k) =
                        (image(i, j, k) * (1 - level)) + (BW * level);
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
    int angle;

    cout << "choose rotation angle (90, 180, 270): " << endl;
    cin >> angle;

    Image rotated(image.height, image.width);

    if (angle == 90)
    {
        for (int i = 0; i < image.width; i++)
        {
            for (int j = 0; j < image.height; j++)
            {
                for (int k = 0; k < image.channels; k++)
                {
                    rotated(image.height - 1 - j, i, k) = image(i, j, k);
                }
            }
        }
    }

    else if (angle == 180)
    {
        for (int i = 0; i < image.width; i++)
        {
            for (int j = 0; j < image.height; j++)
            {
                for (int k = 0; k < image.channels; k++)
                {
                    rotated(image.height - 1 - j,
                            image.width - 1 - i, k) = image(i, j, k);
                }
            }
        }
    }

    else if (angle == 270)
    {
        for (int i = 0; i < image.width; i++)
        {
            for (int j = 0; j < image.height; j++)
            {
                for (int k = 0; k < image.channels; k++)
                {
                    rotated(j, image.width - 1 - i, k) = image(i, j, k);
                }
            }
        }
    }

    image = rotated;
}

// ====== Filter 1 =====
void grayscale_filter(Image &image)
{

    for (int i = 0; i < image.width; i++)
    {
        for (int j = 0; j < image.height; j++)
        {

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

// ====== Filter 5 =======
void flip_filter(Image &image)
{

    int choice;

    cout << "Choose flip type: " << endl;
    cout << "1 => flip horizontally" << endl;
    cout << "2 => flip vertically" << endl;

    cin >> choice;

    if (choice == 1)
    {

        for (int i = 0; i < image.width / 2; i++)
        {
            for (int j = 0; j < image.height; j++)
            {
                for (int k = 0; k < 3; k++)
                {

                    swap(image(i, j, k),
                         image(image.width - 1 - i, j, k));
                }
            }
        }
    }

    else if (choice == 2)
    {

        for (int i = 0; i < image.width; i++)
        {
            for (int j = 0; j < image.height / 2; j++)
            {
                for (int k = 0; k < 3; k++)
                {

                    swap(image(i, j, k),
                         image(i, image.height - 1 - j, k));
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
    cout << "8 => Inverted" << endl;

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
    else if (choice == 8)
    {
        invert_filter(image);
    }
    else
    {
        cout << "Invalid choice!" << endl;
        return 0;
    }

    // Save the new image

    string newImageName;
    string extension;
    int extensionChoice;

    cout << "choose new image name : ";
    cin.ignore();
    getline(cin, newImageName);

    cout << "Choose extension:" << endl;
    cout << "1 => .JPG" << endl;
    cout << "2 => .JPEG" << endl;
    cout << "3 => .BMP" << endl;
    cout << "4 => .PNG" << endl;
    cout << "5 => .TGA" << endl;

    cin >> extensionChoice;

    if (extensionChoice == 1)
    {
        extension = ".jpg";
    }
    else if (extensionChoice == 2)
    {
        extension = ".jpeg";
    }
    else if (extensionChoice == 3)
    {
        extension = ".bmp";
    }
    else if (extensionChoice == 4)
    {
        extension = ".png";
    }
    else if (extensionChoice == 5)
    {
        extension = ".tga";
    }
    else
    {
        cout << "Invalid extension!" << endl;
        return 0;
    }

    newImageName = newImageName + extension;

    image.saveImage(newImageName);

    cout << "Image saved successfully!" << endl;

    return 0;
}
