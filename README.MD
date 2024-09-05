# OpenGL Linux Template Project

This project template is designed for OpenGL development on Linux, specifically tested on **Windows running WSL (Windows Subsystem for Linux)** with **Ubuntu**. However, it should work on any Ubuntu-based distribution with the required libraries installed.

---

## Table of Contents

- [Setting Up WSL on Windows](#setting-up-wsl-on-windows)
- [Installing Required Libraries on Ubuntu](#installing-required-libraries-on-ubuntu)
- [Setting Up VS Code](#setting-up-vs-code)
  - [Installing the C++ Extension for VS Code](#installing-the-c-extension-for-vs-code)
  - [Setting Up VS Code with WSL](#setting-up-vs-code-with-wsl)
- [Running the Project](#running-the-project)
  - [Method 1: Using the Run Button](#method-1-using-the-run-button)
  - [Method 2: Using the Build Task](#method-2-using-the-build-task)
- [Project Configuration](#project-configuration)
- [Git Configuration](#git-configuration)
- [Disclaimer](#disclaimer)

---

## Setting Up WSL on Windows

If you're using Windows, follow these steps to install WSL and set up Ubuntu:

1. Open **PowerShell** or **Command Prompt** in administrator mode (right-click and select "Run as administrator").
2. Run the following command to install WSL and the Ubuntu distribution of Linux:

    ```bash
    wsl --install
    ```

3. After the installation is complete, restart your machine.

For more information, visit the official WSL documentation:  
https://learn.microsoft.com/en-us/windows/wsl/install

---

## Installing Required Libraries on Ubuntu

To run and compile the OpenGL project, you need to install the following libraries:

```bash
sudo apt update
sudo apt install build-essential libglew-dev libglfw3-dev libgl1-mesa-dev
```

These commands will install:

- `libglew-dev` (for GLEW)
- `libglfw3-dev` (for GLFW)
- `libgl1-mesa-dev` (for OpenGL)

You also need GCC with C++17 support, which is included in the `build-essential` package.

---

## Setting Up VS Code

This section covers how to set up Visual Studio Code for C++ development and to use it with WSL (Windows Subsystem for Linux).

### [Installing the C++ Extension for VS Code](#installing-the-c-extension-for-vs-code)

Before running the project, you need to install the C++ extension for Visual Studio Code, which provides support for debugging, IntelliSense, and more.

1. Open **VS Code**.
2. Press `Ctrl+Shift+X` to open the Extensions panel.
3. In the search bar, type **C++** and install the **C/C++ extension** by Microsoft (it should be the first result).
4. Once installed, you will have support for IntelliSense, code navigation, and debugging in C++.

---

### [Setting Up VS Code with WSL](#setting-up-vs-code-with-wsl)

To set up Visual Studio Code to work with WSL, follow these steps:

1. **Install Visual Studio Code**: Download and install VS Code from https://code.visualstudio.com/.
2. **Install the WSL Extension**:
    1. Open VS Code.
    2. Press `Ctrl+Shift+X` to open the Extensions panel.
    3. Search for and install the **Remote - WSL extension** (official Microsoft extension). This extension allows you to open folders in WSL directly from VS Code.

3. **Access WSL in File Explorer**:
    1. Open **File Explorer** in Windows.
    2. In the sidebar, you should see **Linux** (under Quick Access) with the name of your Ubuntu distribution. If it's not there, you can manually access it by navigating to:  
   
    ```bash
    \\wsl.localhost\Ubuntu
    ```

    (This assumes you installed the default Ubuntu distribution using `wsl --install`).

4. It’s good practice to navigate to your home directory inside the WSL filesystem. This is usually located at:

    ```bash
    \\wsl.localhost\Ubuntu\home\<your-username>
    ```

    You can create a **Documents** folder, a **vscode** folder, or any directory of your choice where you can store your projects.

---

## [Running the Project](#running-the-project)

To compile and run the project, follow either of the two methods below:

### [Method 1: Using the Run Button](#method-1-using-the-run-button)

1. Open **VS Code** in your project folder.
2. Install the C++ Extension (see instructions above if you haven't done so already).
3. Select a source file (e.g., `main.cpp`).
4. Click the **Run** button on the top right (the play icon).
5. Select **Run ProjectName** from the drop-down menu.

### [Method 2: Using the Build Task](#method-2-using-the-build-task)

1. Open **VS Code** in your project folder.
2. Press `Ctrl+Shift+B` to run the build task. This will compile the project using the build configuration specified in the `tasks.json` file.
3. After the project builds successfully, press `F5` to start debugging or run the project.

---

## [Project Configuration](#project-configuration)

This template is specifically made for VS Code and includes `.vscode` configuration files for build and debugging.

After cloning this repository, make sure to replace the placeholder **ProjectName** with your own project name in the following files:

- `.vscode/launch.json`:

    ```json
    "name": "Run ProjectName"
    "program": "${workspaceFolder}/ProjectName"
    ```

- `.vscode/tasks.json`:

    ```bash
    "-o ProjectName" (In the g++ command for the build task)
    ```

- `main.cpp`:

    ```cpp
    Window window(800, 600, "ProjectName"); // Change the window title
    ```

- `.gitignore`:

    Replace `ProjectName` with the name of your executable to ignore it during Git operations.

---

## [Git Configuration](#git-configuration)

When using Git for your project, you may want to exclude your `.vscode` folder. Add the following line to your `.gitignore` file:

```bash
.vscode/
```

This will prevent VS Code-specific settings from being pushed to your repository.

---

## [Disclaimer](#disclaimer)

I am not a professional developer but someone who struggled to get C++ projects running on Windows using VS Code. After some trial and error, I found this setup to work well and decided to share it. Hopefully, it helps others in a similar situation!

