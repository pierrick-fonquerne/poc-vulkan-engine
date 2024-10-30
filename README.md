# Proof of Concept Vulkan Engine

This repository contains a Proof of Concept (PoC) for a Vulkan engine. Vulkan is a low-overhead, cross-platform 3D graphics API that provides high-efficiency, cross-platform access to modern GPUs used in a wide variety of devices from PCs and consoles to mobile phones and embedded platforms.

## Prerequisites

- CMake (version 3.10 or higher)
- A C++ compiler (supporting C++17)
- A Vulkan compatible operating system (Windows 10 or later, Linux with a Vulkan driver, macOS 10.15 or later)

## Running

The provided PowerShell script automates the building and running of your Vulkan project. To run it, follow the steps below:

1. Open PowerShell in the root directory of your project.
2. Run the PowerShell script by entering the following command:

```powershell
.\build.ps1
```

The script will perform the following operations:

- Clean the build directory (if it exists)
- Create a new build directory
- Run CMake to configure and build the project
- Run the generated binary executable

If the configuration and build are successful, the script will display a "Build process completed." message in green. If either of these steps fails, the script will display an error message and exit with a non-zero exit code.

## Project Structure

## License
This project is licensed under the MIT License. See the LICENSE file for details.
