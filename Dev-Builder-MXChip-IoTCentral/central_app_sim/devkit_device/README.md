# Build the Generated CMake Project on Windows

One of the features VS Code Digital Twin tooling provides is generating stub code based on the Device Capability Model (DCM) you specified.

Follow the steps to use the generated code with the Azure IoT Device C SDK source to compile a device app.

For more details about setting up your development environment for compiling the C Device SDK. Check the [instructions](https://github.com/Azure/azure-iot-sdk-c/blob/master/iothub_client/readme.md#compiling-the-c-device-sdk) for each platform.

## Prerequisite
1. Install [Build Tools for Visual Studio](https://visualstudio.microsoft.com/thank-you-downloading-visual-studio/?sku=BuildTools&rel=16) with C++ build tools and NuGet package manager component workloads. Or if you already have [Visual Studio (Community, Professional, or Enterprise) 2019, 2017 or 2015](https://www.visualstudio.com/downloads/) with same workloads installed.

1. Install [git](http://www.git-scm.com/). Confirm git is in your PATH by typing `git version` from a command prompt.

1. Install [CMake](https://cmake.org/). Make sure it is in your PATH by typing `cmake -version` from a command prompt. CMake will be used to create Visual Studio projects to build libraries and samples.

1. In order to connect to IoT Central:
    * Complete the [Create an Azure IoT Central application (preview features)](https://docs.microsoft.com/en-us/azure/iot-central/quick-deploy-iot-central-pnp?toc=/azure/iot-central-pnp/toc.json&bc=/azure/iot-central-pnp/breadcrumb/toc.json) quickstart to create an IoT Central application using the Preview application template.

    * Retrieve DPS connection infomation from Azure IoT Central, including **Device ID**, **DPS ID Scope**, **DPS Symmetric Key**, which will be pass the as paramerters of the device app executable. Please refer to [this document](https://docs.microsoft.com/en-us/azure/iot-central/concepts-connectivity) for more details. Save them to the clipboard for later use.

## Build with Vcpkg of Azure IoT Device C SDK
1. Run the following commands to set up Vcpkg package manager tool and install the `azure-iot-sdk-c` Vcpkg package.
    ```cmd
    git clone https://github.com/microsoft/vcpkg
    cd vcpkg
    .\bootstrap-vcpkg.bat
    .\vcpkg integrate install
    .\vcpkg install azure-iot-sdk-c[public-preview,use_prov_client]
    ```

1. Go to the **root folder of your generated app**.
    ```cmd
    cd devkit_device
    ```

1. Create a folder for your CMake build.
    ```cmd
    mkdir cmake
    cd cmake
    ```

1. Run CMake to generate build files with `azure-iot-sdk-c` Vcpkg. You need to specify the CMake generator based on the build tools you are using, and specify the CMake toolchain file `scripts\buildsystems\vcpkg.cmake` from your vcpkg repo to use the installed libraries:
    ```cmd
    # Either
    cmake .. -G "Visual Studio 14 2015" -DCMAKE_TOOLCHAIN_FILE={Directory of your vcpkg repo}/scripts/buildsystems/vcpkg.cmake -Duse_prov_client=ON -Dhsm_type_symm_key:BOOL=ON
    # or
    cmake .. -G "Visual Studio 15 2017" -DCMAKE_TOOLCHAIN_FILE={Directory of your vcpkg repo}/scripts/buildsystems/vcpkg.cmake -Duse_prov_client=ON -Dhsm_type_symm_key:BOOL=ON
    # or
    cmake .. -G "Visual Studio 16 2019" -A Win32 -DCMAKE_TOOLCHAIN_FILE={Directory of your vcpkg repo}/scripts/buildsystems/vcpkg.cmake -Duse_prov_client=ON -Dhsm_type_symm_key:BOOL=ON
    ```

1. When the project generation completes successfully, you can use the followin command to build the project.
    ```cmd
    cmake --build . -- /p:Configuration=Release
    ```

1. Once the build has succeeded, you can test it by specifying the DPS info (**Device Id**, **DPS ID Scope**, **DPS Symmetric Key**) as its parameter.
    ```cmd
    .\Release\devkit_device.exe [Device Id] [DPS ID Scope] [DPS symmetric key]
    ```
