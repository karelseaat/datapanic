 # Project Overview

This project is a collection of C++ classes for game development, focusing on essential components such as `Timer`, `Vector2D`, and `Animation`. These classes are designed to facilitate the creation of 2D games or simulations by providing convenient methods for handling time, vectors, and animations.

## Key Classes

### Timer

The `Timer` class provides functionality for managing game time. It offers methods to start, stop, pause, and unpause a timer, as well as retrieving the elapsed time in ticks. The `Timer` class uses the Simple DirectMedia Layer (SDL) library for its underlying time management.

### Vector2D

The `Vector2D` class offers various methods to manipulate 2D vectors, including rotation, magnitude calculation, normalization, dot product, cross product, and vector addition/subtraction. The class also provides a zero vector constant, distance calculation between two vectors, and static factory functions for creating new vectors.

### Animation

The `Animation` class manages sequences of integers (animation frames) and offers methods to retrieve the next frame, previous frame, current frame, index, name, length, and more. It supports setting the animation sequence and frame index, as well as adding a new animation by name from a collection of animations. The `Animation` class also includes a test function for demonstrating its functionality.

### Base64

The `Base64` namespace contains two functions for encoding and decoding base64 strings in C++. These functions can be used to handle data that needs to be represented as ASCII text, such as configuration files or image data.

## Getting Started

To use this project, follow these steps:

1. Compile the source code using a C++ compiler like gcc or Clang. Ensure you have the SDL library installed and linked correctly.
2. Include the required header files in your own projects to utilize the classes and functions provided here.
3. Use the provided classes and functions as needed for your game development tasks.

## Contributing

Contributions are welcome! If you find any issues, have suggestions for improvements, or would like to add new features, please open an issue or submit a pull request.

## License

This project is licensed under the MIT License – see the [LICENSE](LICENSE) file for details.