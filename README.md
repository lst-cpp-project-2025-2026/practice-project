# Practice Project: Mastering Git and GitHub Workflow

## Part 1: Initial Setup and Running the Project

---

## 💻 Section 1A: Setup for Windows (MSVC)

### Prerequisites (What to Install on Windows)

You need to install three essential tools. **Follow the instructions exactly.** We are using the **Microsoft Visual C++ (MSVC) compiler** because it provides the most stable environment for Raylib on Windows.

1.  **Git Bash:** (Download from [git-scm.com](https://git-scm.com/download/win). Use all default options.)
2.  **Visual Studio Build Tools (C++ Compiler - MSVC):** (Download Visual Studio Installer. **SELECT ONLY** the **"Desktop development with C++"** workload.)
3.  **CMake:** (Download from [cmake.org/download](https://cmake.org/download/). **CRITICAL: Select "Add CMake to the system PATH."**)

### Build Steps: Running the Existing Code (Windows)

We use the **x64 Native Tools Command Prompt** for building, as it contains the necessary path variables for the MSVC compiler.

1.  **Clone Repository (Use Git Bash - See Step 1, Part 2)**
2.  Open the **"x64 Native Tools Command Prompt for VS..."**
3.  Navigate to your project folder:
    ```batch
    cd C:\Users\YourName\Documents\practice-project 
    ```
4.  Configure and Build:
    ```batch
    mkdir build
    cd build
    cmake .. 
    cmake --build .
    ```
5.  Run the Application:
    ```batch
    .\Debug\RaylibPracticeProject.exe 
    ```

### VS Code and CMake Tools Setup (Windows)

*   **Install VS Code** and the **CMake Tools** extension.
*   **Crucial Kit Selection:** In VS Code, when prompted or via the status bar, ensure you select the **MSVC kit** (e.g., `Visual Studio Community 2022 Release - amd64`). **DO NOT** select MinGW or GCC.

---

## 🐧 Section 1B: Setup for Ubuntu / Debian Linux (GCC)

For Linux systems, the process is streamlined using the built-in package manager (`apt`).

### Prerequisites (What to Install on Ubuntu)

You must install the necessary compilers and Raylib system dependencies.

1.  **Install Essential Build Tools:** This includes the standard C++ compiler (G++) and `make`.
    ```bash
    sudo apt update
    sudo apt install build-essential git cmake
    ```

2.  **Install Raylib Dependencies:** Raylib requires libraries for graphics (OpenGL), windowing (X11), and audio (ALSA).
    ```bash
    sudo apt install libasound2-dev libx11-dev libxrandr-dev libxi-dev libgl1-mesa-dev libglu1-mesa-dev libxcursor-dev libxinerama-dev libwayland-dev libxkbcommon-dev
    ```
    *(Note: This comprehensive list ensures compatibility across most desktop environments.)*

### Build Steps: Running the Existing Code (Ubuntu)

Use your standard terminal (e.g., Gnome Terminal, Konsole, or Git Bash if installed on Linux).

1.  **Clone Repository (See Step 1, Part 2)**
2.  Navigate to the project folder:
    ```bash
    cd ~/Documents/practice-project 
    ```
3.  Configure and Build:
    ```bash
    mkdir build
    cd build
    cmake .. 
    cmake --build .
    ```
4.  Run the Application:
    ```bash
    ./RaylibPracticeProject
    ```
    *A small Raylib window should appear. Success!*

### VS Code and CMake Tools Setup (Ubuntu)

*   **Install VS Code** and the **CMake Tools** extension.
*   **Crucial Kit Selection:** In VS Code, when prompted or via the status bar, ensure you select a **GCC kit** (e.g., `GCC 11.4.0` or similar). **DO NOT** select any Visual Studio or MSVC kit.

---

## Part 2: The Contribution Workflow (Your Task)

This workflow is identical regardless of your operating system (Windows or Ubuntu), as it relies purely on Git commands and GitHub interactions.

### Your Task

Your goal is to find an open issue, add a simple colored box containing your name to the window in `src/main.cpp`, and submit a Pull Request (PR) for the code review.

### Step-by-Step GitHub Workflow

Follow these exact steps in order. **Do not skip any steps!**

#### **Step 1: Get the Assignment (On GitHub)**

1.  Go to the **Issues** tab on the original repository.
2.  Find and claim an open issue (e.g., "Add the name box for [Your Name]"). Note the **Issue Number (e.g., #1, #2)**.
3.  Comment: "I'd like to take this!" and wait for the assignment.

#### **Step 2: Fork the Repository (On GitHub)**

1.  Go to the main repository page.
2.  Click the **Fork** button to create your personal copy.

#### **Step 3: Clone Your Fork Locally (In Git Bash / Linux Terminal)**

***If you already cloned the original repository for testing (Part 1), delete the old `practice-project` folder now.***

1.  Go to **your personal fork** on GitHub. Copy the HTTPS URL.
2.  In your terminal (Git Bash or Linux Terminal), clone your fork:
    ```bash
    git clone <your-fork-url>
    cd practice-project
    ```
3.  **Re-Configure the Build:** Since you cloned a fresh copy, you must re-run the configuration and build steps (Section 1A or 1B, Step 3 & 4) before editing code.

#### **Step 4: Link to Upstream (The Original Repo) (In Terminal)**

1.  While in the project directory, add a link called `upstream`:
    ```bash
    git remote add upstream https://github.com/lst-cpp-project-2025-2026/practice-project.git
    ```
2.  Verify the remotes:
    ```bash
    git remote -v
    # You should see 'origin' (your fork) and 'upstream' (the main repo)
    ```

#### **Step 5: Create a Feature Branch (In Terminal)**

*We never work directly on the `master` branch! A feature branch isolates your work for review.*

1.  Ensure your local `master` branch is clean and up-to-date:
    ```bash
    git checkout master               # Switch to the master branch
    git pull upstream master          # Pull any recent changes from the original repo
    git push origin master            # Update your fork's master branch
    ```
2.  Create and switch to your new branch. **This name MUST clearly describe the feature you are implementing.**
    
    *   **Convention:** Use the format `type/description` (e.g., `feature/add-initial-box` or `fix/update-text-color`).
    
    ```bash
    # Example using a descriptive branch name related to the task:
    git checkout -b feature/add-your-name-box 
    ```

#### **Step 6: Code the Feature (In VS Code)**

1.  In VS Code, edit the file **`src/main.cpp`** and add the box and your name.
2.  Use the VS Code status bar **Build** and **Run** buttons to test your changes instantly.

#### **Step 7: Commit and Push Your Changes (In Terminal)**

1.  Stage the files you modified:
    ```bash
    git add src/main.cpp 
    ```
2.  Commit your changes. **CRITICAL: Use a clear, conventional message, and reference the issue number (XX):**
    ```bash
    # Example commit message:
    git commit -m "feat: Add box displaying [Your Name] and closes #XX" 
    ```
3.  Push your new branch to your personal fork on GitHub:
    ```bash
    git push origin feature/add-your-name-box
    ```

#### **Step 8: Create the Pull Request (PR) (On GitHub)**

1.  Go to the GitHub page for **your fork**.
2.  Click **"Compare & pull request."**
3.  **Verify the Direction (VERY IMPORTANT!):**
    *   **base repository:** `lst-cpp-project-2025-2026/practice-project` (The main repo)
    *   **head repository:** `YourUsername/practice-project` (Your branch)
4.  Write a brief description and ensure your title is clear (e.g., "Feature: Add Name Box - Closes #XX").
5.  Click **"Create pull request."**

#### **Step 9: Review and Merge**

1.  If changes are requested, repeat Step 6 (code), Step 7 (commit and push to the *same branch*), and the PR will automatically update.
2.  Once approved, the changes will be merged into the main project.
