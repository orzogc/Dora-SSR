---
sidebar_position: 6
---

# Engine Dev Configuration

## 1. Get the Source

```sh
git clone https://github.com/ippclub/Dora-SSR.git
```

## 2. Game Engine Development

### Windows

1. Install **Visual Studio Community 2022**.
2. Open the project file in the IDE: **Projects/Windows/Dora.sln**.
3. Compile, debug, and run the project.

### macOS

1. Install latest **Xcode**.
2. Open the project file in the IDE: **Projects/macOS/Dora.xcodeproj**.
3. Compile, debug, and run the project.

### iOS

1. Install latest **Xcode**.
2. Open the project file in the IDE: **Projects/iOS/Dora.xcodeproj**.
3. Compile, debug, and run the project.

### Android

1. Manually generate Lua bindings.

   ```sh
   # ubuntu
   sudo apt-get install lua5.1
   sudo apt-get install -y luarocks
   sudo luarocks install luafilesystem
   cd Tools/tolua++
   lua tolua++.lua

   # macOS
   cd Tools/tolua++
   ./build.sh

   # Windows
   cd Tools\tolua++
   build.bat
   ```

2. Install latest **Android Studio**.
3. Open the project directory in the IDE: **Projects/Android/Dora**.
4. Compile, debug, and run the project.

### Linux

#### Ubuntu

1. Manually generate Lua bindings.
   ```sh
   sudo apt-get install lua5.1
   sudo apt-get install -y luarocks
   sudo luarocks install luafilesystem
   cd Tools/tolua++
   lua tolua++.lua
   ```
2. Install dependent packages.
   ```sh
   sudo apt-get install -y libsdl2-dev libgl1-mesa-dev x11proto-core-dev libx11-dev
   ```
3. Run the compile scripts.

   - For the first time build

   ```sh
   # For arm architecture
   cd Projects/Linux
   make arm

   # For x86_64 architecture
   cd Projects/Linux
   make x86_64
   ```

   - For incremental build

   ```sh
   cd Projects/Linux
   make
   ```

4. Run the generated software.
   ```sh
   cd Assets
   ../Projects/Linux/build/dora-ssr
   ```

#### ArchLinux

1. Install dependent packages.

   ```sh
   sudo pacman -S lua51 luarocks sdl2 gcc make cmake --needed
   # Because the lua version must be 5.1,you need to use lua 5.1 instead of the newest version of lua
   # The easiest way is using 'ln' to create a soft link
   sudo ln -s /usr/bin/lua5.1 /usr/local/bin/lua
   ```

2. Manually generate Lua bindings.

   ```sh
   sudo luarocks --lua-version 5.1 install luafilesystem
   cd Tools/tolua++
   lua5.1 tolua++.lua
   ```

3. Run the compile scripts.

   - For the first time build

   ```sh
   # For arm architecture
   cd Projects/Linux
   make arm

   # For x86_64 architecture
   cd Projects/Linux
   make x86_64
   ```

   - For incremental build

   ```sh
   cd Projects/Linux
   make
   ```

4. Run the generated software.
   ```sh
   cd Assets
   ../Projects/Linux/build/dora-ssr
   ```

## 3. Dora Dora Editor Development

1. Compile and run the Dora SSR engine.
2. Install the latest version of **Node.js**.
3. Initialize the project and enter the Dora Dora editor development mode.
   ```sh
   cd Tools/YarnEditor && yarn && yarn build
   rm -rf ../dora-dora/public/yarn-editor
   mv dist ../dora-dora/public/yarn-editor
   cd ../../Tools/dora-dora
   yarn
   yarn start
   ```