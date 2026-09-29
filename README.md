# 📸 OOP Image Processor Project

A comprehensive **C++ Image Processing Application** built as part of the Object-Oriented Programming (OOP) course requirements. The project features a well-structured, modular design that splits implementation into separate Header and Source files for clean and maintainable code.

## 📁 Project Structure

The repository is organized following professional layout standards to separate design from implementation:

```text
OOP_Project/
├── include/
│   ├── Filters.h         # Header file: Contains function declarations and filter prototypes
│   └── Image_Class.h      # Image handling core library
├── src/
│   └── main.cpp          # Application entry point: Interactive user menu and 8 filters
└── images/               # Team test images and filter outputs
```

## ✨ Implemented Filters & Features

| Filter # | Filter Name | Description |
| :--- | :--- | :--- |
| **1** | **Grayscale** | Converts the image pixels into gray shades |
| **2** | **Black and White** | Thresholds image brightness into pure black or white |
| **3** | **Darken / Lighten** | Controls image exposure by percentage levels |
| **4** | **Infrared** | Transforms image colors to simulate a thermal view |
| **5** | **Flip** | Swaps image pixels horizontally or vertically |
| **6** | **Rotate** | Alternates image alignment safely (90, 180, 270 degrees) |
| **7** | **Add Frame** | Applies a customized yellow protective border |
| **8** | **Inverted** | Inverts pixel channels to produce a negative effect |

## 🚀 How to Build and Run

To compile the project via Terminal, make sure to compile the cpp source file:

```bash
# Compilation command
g++ src/main.cpp -o ImageProcessor

# Running the application
.\ImageProcessor.exe
```

## 👥 Engineering Team & Contributors (Sections 5 & 6)

* **Mai Mustafa**
* **Fatma**
* **Malak**
* **Mai Hussein**
