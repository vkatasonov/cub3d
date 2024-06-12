# Cub3D
A graphic design project of 42 school curriculum, inspired by the world famous game of the 90's, Wolfenstein 3D.

The project is designed to explore the technique of ray-casting in a three-dimensional gaming environment. The program allows the parsing of a scene description file (with a .cub extension), the rendering of a three-dimensional view from the player's perspective (akin to a first-person shooter), the handling of basic user input (WASD to move, ESC to exit), and the implementation of simple collision detection.

The project is written in C and utilises the [MLX42 graphic library by Codam](https://github.com/codam-coding-college/MLX42https://github.com/codam-coding-college/MLX42). This project can be considered an introduction to the fundamentals of game development, computer graphics, and, more generally, 3D rendering.

## Dependencies

This project has several dependencies that need to be compiled and linked correctly for the project to build and run successfully. Here are the details:

1. **Libft**: This is a custom library used in the project. It is included in the project repository and will be compiled automatically. The `Makefile` includes a rule to compile this library.

2. **[MLX42 graphic library by Codam](https://github.com/codam-coding-college/MLX42https://github.com/codam-coding-college/MLX42)**: This is a graphics library used for rendering. It is also included in the project repository and also will be biult during project compilation. The `Makefile` includes a rule to compile this library.

3. **dl (Dynamic Linking Library)**: This is a standard library in Linux used for dynamic linking. It is linked using the `-ldl` flag in `Makefile`.

4. **glfw (Graphics Library Framework)**: This is an open-source library for creating windows with OpenGL contexts and managing input. It is linked using the `-lglfw` flag.

5. **pthread (POSIX Threads Library)**: This is a POSIX standard for threads programming. It is linked using the `-pthread` flag.

6. **m (Math Library)**: This is a standard library in Linux used for mathematical operations. It is linked using the `-lm` flag.

## Compilation
To compile the project, you can run the `make` command in the root directory of the project. This will compile the `libft` and `MLX42` libraries, and then compile the main project linking all the necessary libraries.

Please note that you need to have the development versions of the `dl`, `glfw`, `pthread`, and `m` libraries installed on your system. The installation commands depend on your Linux distribution. For Ubuntu, you can use the following commands:

```sh
sudo apt-get update
sudo apt-get install libglfw3-dev
sudo apt-get install libm-dev
sudo apt-get install libpthread-stubs0-dev
```

### MacOS

For macOS, you can use `Homebrew` to install the necessary libraries. If you don't have Homebrew installed, you can install it first using the following command in your terminal:

```sh
/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
```
Then, you can install the required libraries using the following commands:
```sh
brew install glfw
```
The `dl`, `pthread`, and `m libraries` are included by default in macOS, so you don't need to install them separately.

For the custom libraries (libft and MLX42), the Makefile takes care of their compilation. Make sure to pull the latest versions of these libraries from the project repository.

## Usage
After compiling this project an executable named `cub3D` will be generated in the root directory. You can run it by passing a `.cub` file as an argument to the `cub3D` executable. The `.cub` file contains the description of the scene you want to render. Examples can be found in `maps` folder. 

Use the `WASD` keys to manage movements and `arrow keys` to look around in the rendered 3D environment. Press `ESC` to exit the program.

## Authors

- [Vladimir Katasonov (@vkatasonov)](https://github.com/vkatasonov)
- [Luis Romero (@lromero-m)](https://github.com/lromero-m)
