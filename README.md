# ps3dev Hello World

A minimal PlayStation 3 homebrew `hello world` project and packaging example. This repository demonstrates building a PS3 executable and producing a `.pkg` installer suitable for installation in RPCS3 (or on a real PS3).

<img width="1792" height="931" alt="image" src="https://github.com/user-attachments/assets/8f49fbb1-6ca3-47b2-b2fd-9beb3202ed3c" />

---

## Prerequisites

- **Docker** (for devcontainer)
- JetBrains **CLion** IDE
- **RPCS3** (recommended emulator for testing .pkg files)
- Familiarity with Make and C++

Note: The devcontainer image provided in this repo should already include the PS3 toolchain and required utilities.

---

## Using the devcontainer
Clone this repo using the devcontainer with CLion, build the image, and open it.  
Then, build the pkg file:  

<img width="205" height="77" alt="image" src="https://github.com/user-attachments/assets/50c1a15d-40ff-418e-992b-b25482efafa4" />

---

## Testing the .pkg with RPCS3

RPCS3 is a mature PS3 emulator that can install and run .pkg files (homebrew or retail packages).  
To test your generated .pkg:

1. Install RPCS3 on your host OS. Follow RPCS3's official installation guide for your platform.
2. Start RPCS3.
3. Install the .pkg:
   - Menu: `File` → `Install Packages`
   - Select the generated .pkg file from the project.
4. Launch the installed package from RPCS3's Games list.
5. Use RPCS3 TTY logs for debugging.

---

### Why use a devcontainer and CLion

**Reproducible build environment**: PS3 cross-compilation and packaging requires a specific toolchain (ps3dev / ps3toolchain, SDK bits, etc.). A devcontainer lets you pin an exact environment (toolchain versions, SDKs, OS packages) so builds are repeatable.

**Easy setup for contributors** New contributors can open the repository in a container and immediately have the correct toolchain and dependencies available (no manual host setup).

---

## Simple build commands
From inside the devcontainer terminal:
**Build**
```BASH 
make
```

Build the PKG file:
```BASH
make pkg
```
