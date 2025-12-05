# pfm_viewer
For PFM files, we typically want to normalize the data for visualization. Usage ./pfm_viewer /path/to/your/image.pfm

To compile this program, you'll need to have OpenCV installed and link against it. Here's how to compile it:
bash

g++ -std=c++11 pfm_viewer.cpp -o pfm_viewer `pkg-config --cflags --libs opencv4`
Or if you're using OpenCV 3.x:
bash

g++ -std=c++11 pfm_viewer.cpp -o pfm_viewer `pkg-config --cflags --libs opencv`
If you don't have pkg-config set up, you might need to use:
bash

g++ -std=c++11 pfm_viewer.cpp -o pfm_viewer -I/usr/include/opencv4 -lopencv_core -lopencv_highgui -lopencv_imgcodecs
Features of this program:
Command-line argument handling: Takes the PFM file path as a command-line argument
Error checking: Validates that the file was loaded successfully
Proper PFM handling: Uses OpenCV's imread with IMREAD_UNCHANGED flag to preserve the original format
Display normalization: Normalizes the image data to 0-255 range for proper visualization
Flexible display: Handles both single-channel (grayscale) and multi-channel images
User-friendly interface: Shows image information and waits for user input
Usage example:
bash

./pfm_viewer /path/to/your/image.pfm
Note: OpenCV supports PFM format through its image I/O capabilities, but make sure your OpenCV installation includes support for PFM files. If you encounter issues with PFM loading, you might need to ensure you're using a recent version of OpenCV (4.5+) or consider implementing custom PFM reading logic.
The program will:
Load the PFM file
Display basic information about the image
Show the image in a window
Wait for a keypress before closing
Handle both grayscale and color PFM files appropriately
