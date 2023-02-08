#include <cstdlib>
#include <iostream>
#include <vector>

// OpenCV
#include <opencv2/opencv.hpp>

int main(int argc, char* argv[]) {
  if (argc != 2) {
    std::cerr << "usage: " << argv[0] << " classifier.xml\n";
    std::exit(EXIT_FAILURE);
  }

  // Load a classifier from its XML description
  cv::CascadeClassifier classifier(argv[1]);

  // Prepare a display window
  const char* const window_name{"Facial Recognition Window"};

  cv::namedWindow(window_name, cv::WINDOW_AUTOSIZE);

  // Prepare a video capture device
  cv::VideoCapture capture(0); // `0` means "default video capture"
  if (not capture.isOpened()) {
    std::cerr << "cannot open video capture device\n";
    std::exit(EXIT_FAILURE);
  }

  // Prepare an image where to store the video frames, and an image to store a
  // grayscale version
  cv::Mat image;
  cv::Mat grayscale_image;

  // Prepare a vector where the detected features will be stored
  std::vector<cv::Rect> features;

  // Main loop
  while (capture.read(image) and (not image.empty())) {
    // Create a normalized, gray-scale version of the captured image
    cv::cvtColor(image, grayscale_image, cv::COLOR_BGR2GRAY);
    cv::equalizeHist(grayscale_image, grayscale_image);

    // Detect the features in the normalized, gray-scale version of the
    // image. You don't need to clear the previously-found features because the
    // detectMultiScale method will clear before adding new features.
    classifier.detectMultiScale(grayscale_image, features, 1.1, 5,
                                0 | cv::CASCADE_SCALE_IMAGE, cv::Size(30, 30));

    // Draw each feature as a separate green rectangle
    for (auto&& feature : features) {
      cv::rectangle(image, feature, cv::Scalar(0, 255, 0), 2);
    }

    // Show the captured image and the detected features
    cv::imshow(window_name, image);

    // Wait for input or process the next frame
    switch (cv::waitKey(10)) {
      case 'q':
        std::exit(EXIT_SUCCESS);
      case 'Q':
        std::exit(EXIT_SUCCESS);
      default:
        break;
    }
  }
  return EXIT_SUCCESS;
}