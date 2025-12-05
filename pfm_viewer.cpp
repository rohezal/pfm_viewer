#include <opencv2/opencv.hpp>
#include <iostream>
#include <string>

int main(int argc, char* argv[]) {
    // Check if filename is provided
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <pfm_file_path>" << std::endl;
        return -1;
    }

    std::string filename = argv[1];
    
    // Read the PFM file
    cv::Mat image = cv::imread(filename, cv::IMREAD_UNCHANGED);
    
    // Check if image was loaded successfully
    if (image.empty()) {
        std::cerr << "Error: Could not load PFM file: " << filename << std::endl;
        return -1;
    }
    
    std::cout << "Loaded image: " << filename << std::endl;
    std::cout << "Image size: " << image.cols << " x " << image.rows 
              << " channels: " << image.channels() << std::endl;
    
    // For PFM files, we typically want to normalize the data for visualization
    cv::Mat normalized_image;
    
    // Convert to 3-channel BGR for display (since PFM is usually grayscale)
    if (image.channels() == 1) {
        // Normalize the grayscale image to 0-255 range for display
        cv::normalize(image, normalized_image, 0, 255, cv::NORM_MINMAX, CV_8UC1);
        
        // Convert single channel to 3 channel for display
        //cv::cvtColor(normalized_image, normalized_image, cv::COLOR_GRAY2BGR);
    } else {
        // If already 3 or 4 channels, just normalize
        cv::normalize(image, normalized_image, 0, 255, cv::NORM_MINMAX, CV_8UC1);
    }
    
    // Display the image
    cv::namedWindow("PFM Image", cv::WINDOW_NORMAL);
    cv::imshow("PFM Image", normalized_image);
    
    // Wait for a key press
    std::cout << "Press any key to exit..." << std::endl;
    cv::waitKey(0);
    
    // Clean up
    cv::destroyAllWindows();
    
    return 0;
}
