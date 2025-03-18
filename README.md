# Caesar Cipher Cracker

## Overview

**CaesarCipherCracker** is a C++ console application for automatically decrypting text encrypted using the **Caesar cipher**. It analyzes letter frequencies in the encrypted text and compares them with a reference distribution (e.g., English letter frequencies) to determine the most probable shift key.

## Features

- 🔐 **Decrypt Caesar Cipher** using frequency analysis
- 📊 **Frequency Distribution Matching** with a reference file
- 🖥️ **Console Output** for decrypted text and detected key
- 📄 **Input Support** via `distribution.txt`

## Technologies Used

- **C++**
- **Visual Studio 2022+**
- **Standard C++ Libraries**

## Project Structure

```
CaesarCipherCracker/
│
├── CaesarCipherCracker.sln                  # Visual Studio solution file
│
├── CaesarCipherCracker/                     # Source code & data
│   ├── main.cpp                             # Main logic for decryption
│   ├── distribution.txt                     # Reference frequency file
│   └── CaesarCipherCracker.vcxproj          # Project file
│
├── x64/Debug/                               # Build outputs (ignored)
│   └── *.exe, *.pdb, *.obj, *.log           # Build artifacts
│
└── .gitignore                               # Ignoring build/temp files
```

## Setup Instructions

1. **Clone the Repository**:
   ```bash
   git clone https://github.com/yourusername/CaesarCipherCracker.git
   cd CaesarCipherCracker
   ```

2. **Open in Visual Studio**:
   - Open `CaesarCipherCracker.sln`.

3. **Build & Run**:
   - Press `Ctrl + Shift + B` to build.
   - Press `F5` to run.

## Sample Usage

1. Prepare an encrypted text sample.
2. Application will analyze frequencies vs. `distribution.txt`.
3. Outputs:
   - Decrypted message
   - Detected Caesar key (shift amount)
