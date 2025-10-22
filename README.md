# Practice Project: Mastering Git and GitHub Workflow

Welcome to your first collaborative project! This simple C++ application uses the Raylib library and the CMake build system.

The primary goal of this exercise is **not** the C++ code itself, but to master the professional development workflow: **Forking, Cloning, Branching, Committing, and creating Pull Requests (PRs).**

Mastering this workflow now will ensure our main project runs smoothly and professionally.

---

## Part 1: Initial Setup and Running the Project

Before you write a single line of code, you must set up your development environment and successfully compile and run the base project.

### Prerequisites (What to Install on Windows)

You need to install three essential tools. **Follow the instructions exactly.** We are using the **Microsoft Visual C++ (MSVC) compiler** because it provides the most stable environment for Raylib on Windows.

1.  **Git Bash:** This provides the professional Linux-style terminal commands needed for all your Git operations.
    *   **Installation:** Download and run the installer from [git-scm.com](https://git-scm.com/download/win). Use all the **default installation options**.
    *   *Verification:* Open the **Git Bash** application and type `git --version`. Ensure a version number is displayed.

2.  **Visual Studio Build Tools (The C++ Compiler - MSVC):** This provides the compiler and necessary build tools.
    *   **Installation:** Download the **Visual Studio Installer** from the official Microsoft site.
    *   **CRUCIAL STEP:** When prompted for workloads, **SELECT ONLY** the **"Desktop development with C++"** workload. You do not need the full Visual Studio IDE.
    *   *Verification:* After installation, search your Windows Start Menu for **"x64 Native Tools Command Prompt for VS..."** (The specific year may vary). Open it and type `cl`. It should show compiler information, indicating the environment is set up.

3.  **CMake:** This tool manages the building of our C++ project across different environments.
    *   **Installation:** Download the installer from [cmake.org/download](https://cmake.org/download/).
    *   **CRUCIAL STEP:** When prompted about the PATH, select the option: **"Add CMake to the system PATH for all users."**
    *   *Verification:* Open **Git Bash** and type `cmake --version`. Ensure a version number is displayed.

### VS Code and CMake Tools Setup (The Primary Development Environment)

1.  **Install VS Code:** If you don't have it, download and install Visual Studio Code.
2.  **Install the CMake Tools Extension:**
    *   In VS Code, go to the Extensions view (`Ctrl+Shift+X`).
    *   Search for and install **"CMake Tools"** by Microsoft.

---

### Build Steps: Running the Existing Code

We will use two different terminal environments for these initial steps:

1.  **Git Bash:** For all version control (Git) operations.
2.  **x64 Native Tools Command Prompt:** For initial configuration (because it is pre-configured to find the MSVC compiler).

#### Step 1: Clone the Repository (Use Git Bash)

1.  Open **Git Bash**.
2.  Navigate to the directory where you want your project stored (e.g., your Documents folder).
    ```bash
    cd ~/Documents 
    ```
3.  Clone the project repository:
    ```bash
    # This creates the 'practice-project' folder
    git clone https://github.com/lst-cpp-project-2025-2026/practice-project.git
    cd practice-project # Move into the new project folder
    ```

#### Step 2: Configure and Build (Use the Native Tools Command Prompt)

1.  Search your Windows Start Menu for and open the **"x64 Native Tools Command Prompt for VS..."**
2.  Navigate to the project folder you just cloned:
    ```batch
    cd C:\Users\YourName\Documents\practice-project 
    ```
3.  Create the separate build directory:
    ```batch
    mkdir build
    cd build
    ```
4.  **Configure CMake:** This generates the build files needed by the compiler.
    ```batch
    cmake .. 
    ```
5.  **Build the Project:** This compiles the source code.
    ```batch
    cmake --build .
    ```
6.  **Run the Application:**
    ```batch
    .\Debug\RaylibPracticeProject.exe 
    ```
    *   A small, Raylib window should appear. **Success!**

---

### Step 3: Configuring CMake Tools in VS Code

We must ensure VS Code uses the **Microsoft Visual C++ (MSVC) compiler** for Raylib compatibility.

#### Scenario A: First-Time Setup (Recommended)

1.  Open VS Code and choose **File > Open Folder**. Select the `practice-project` folder.
2.  **Select the Compiler Kit:** The CMake Tools extension should detect your environment. Look at the VS Code status bar (the blue bar at the bottom).
3.  Click the item that says **"[No active kit]"** or a detected compiler name.
4.  **CRITICALLY, you must select the MSVC kit.** Choose the option that includes **"Visual Studio Community"**, **"Visual Studio Build Tools"**, or **"MSVC"** for the **x64 architecture** (e.g., `Visual Studio Community 2022 Release - amd64`).

    ***DO NOT select any kit labeled "MinGW" or "GCC" if it appears.***

---

#### Scenario B: Troubleshooting - Switching from MinGW/GCC

If you previously used VS Code for C++ and CMake Tools automatically selected a different compiler (like MinGW), you must manually force the switch to MSVC.

1.  **Delete the Cache:** Close VS Code. In your file explorer or Git Bash, delete the entire `build` folder inside your `practice-project` directory. This forces CMake to re-configure cleanly.
2.  **Open VS Code.** The extension will notice the missing configuration.
3.  **Access the Kit Selection:** Click the item in the VS Code status bar that shows the incorrect compiler (e.g., `MinGW`).
4.  **Force Select MSVC:**
    *   Scroll through the list and **explicitly select the MSVC kit** (e.g., `Visual Studio Community 2022 Release - amd64`).
    *   If you still don't see the correct MSVC kit, click **"[Scan for Kits]"** at the top of the selection menu and then try selecting again.
5.  **Configure and Build:** Once MSVC is selected, CMake Tools will automatically Configure the project. Click the **Build** button in the status bar to verify the new compiler works.

---

#### Using VS Code for Development (The Standard Workflow)

Once the correct MSVC kit is active, you can use the status bar at the bottom of VS Code:

| Status Bar Element | Action | Purpose |
| :--- | :--- | :--- |
| **[Build]** | Click **Build** | Compiles your current changes. |
| **[RaylibPracticeProject]** | Click the **Play button** next to the target name. | Runs the compiled executable. |
| **[x64-Debug]** | Click this to change the configuration. | Should usually be set to `Debug`. |

---

## Part 2: The Contribution Workflow (Your Task)

This section details the professional Git/GitHub workflow for accepting a task, coding it, and submitting it for review.

### Your Task

Your goal is to find an open issue, add a simple colored box containing your name to the window in `src/main.cpp`, and submit a Pull Request (PR) for the code review.

### Step-by-Step GitHub Workflow

Follow these exact steps in order. **Do not skip any steps!**

#### **Step 1: Get the Assignment (On GitHub)**

1.  Go to the **Issues** tab on the original repository on GitHub.
2.  Find an open issue assigned for you (e.g., "Add the name box for [Your Name]"). Note the **Issue Number (e.g., #1, #2)**.
3.  **Comment on the issue:** Write "I'd like to take this!" to officially claim it.
4.  Wait for the group lead (`bilal-houari`) to assign the issue to you.

#### **Step 2: Fork the Repository (On GitHub)**

1.  Go to the main repository page on GitHub.
2.  Click the **Fork** button (usually in the top right).
3.  This creates a personal, independent copy of the project under your own GitHub account. **We always work from our personal fork.**

#### **Step 3: Clone Your Fork Locally (In Git Bash)**

***If you completed Part 1, you must delete the original `practice-project` folder and its `build` folder now, as we need to clone your personal fork.***

1.  Go to **your personal fork** on GitHub (your URL will look like `github.com/YourUsername/practice-project`).
2.  Click the **Code** button and copy the HTTPS URL for your fork.
3.  In **Git Bash**, clone your fork (if you deleted the old one):
    ```bash
    # This downloads YOUR copy of the repository
    git clone <your-fork-url>
    cd practice-project
    ```
4.  **Re-configure the Build:** Since you cloned a fresh copy, you must re-run the configuration steps (Part 1, Step 2) using the **x64 Native Tools Command Prompt** once, or configure entirely using VS Code (Part 1, Step 3).

#### **Step 4: Link to Upstream (The Original Repo) (In Git Bash)**

*The **upstream** link allows you to pull updates from the original project into your fork, keeping your work synchronized with the team.*

1.  While still in the project directory in Git Bash, add a link called `upstream`:
    ```bash
    git remote add upstream https://github.com/lst-cpp-project-2025-2026/practice-project.git
    ```
2.  Verify the remotes:
    ```bash
    git remote -v
    # You should see 'origin' (your fork) and 'upstream' (the main repo)
    ```

#### **Step 5: Create a Feature Branch (In Git Bash)**

*We never work directly on the `master` branch! A feature branch isolates your work for review.*

1.  Ensure your local `master` branch is clean and up-to-date:
    ```bash
    git checkout master               # Switch to the master branch
    git pull upstream master          # Pull any recent changes from the original repo
    git push origin master            # Update your fork's master branch
    ```
2.  Create and switch to your new branch. **Use a clear, descriptive name (e.g., matching your issue):**
    ```bash
    # Replace 'your-name' with your actual name
    git checkout -b feature/add-your-name 
    ```

#### **Step 6: Code the Feature (In VS Code)**

1.  In **VS Code**, edit the file **`src/main.cpp`** and add the box and your name as specified in your assigned issue.

2.  **Test your code repeatedly using CMake Tools!**
    *   Use the **Build** and **Run** buttons in the VS Code status bar to test your changes instantly.

#### **Step 7: Commit and Push Your Changes (In Git Bash)**

1.  Go back to **Git Bash**. Stage the files you modified:
    ```bash
    git add src/main.cpp 
    ```
2.  "Commit" your changes (save them locally with a descriptive message):
    ```bash
    # CRITICAL: Use a clear message, and always reference the issue number (XX)!
    git commit -m "feat: Add box for [Your Name] and closes #XX" 
    ```
3.  "Push" your new branch to your personal fork on GitHub:
    ```bash
    git push origin feature/add-your-name
    ```

#### **Step 8: Create the Pull Request (PR) (On GitHub)**

1.  Go to the GitHub page for **your fork**.
2.  GitHub will notice you just pushed a new branch and prompt you to click **"Compare & pull request."**
3.  **Verify the Direction (VERY IMPORTANT!):**
    *   **base repository:** `lst-cpp-project-2025-2026/practice-project` (The original project)
    *   **head repository:** `YourUsername/practice-project` (Your fork/feature branch)
4.  Write a brief description and ensure your title is clear (e.g., "Add feature for [Your Name] - Closes #XX").
5.  Click **"Create pull request."**

#### **Step 9: Review and Merge**

1.  The group lead (`bilal-houari`) will review your code.
2.  If changes are requested, repeat Step 6 (code), Step 7 (commit and push to the *same branch*), and the PR will automatically update!
3.  Once approved, the changes will be merged into the main project! **You have successfully completed the workflow!**