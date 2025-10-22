# Practice Project: Learning Git and GitHub

Welcome! This simple C++ project uses Raylib and CMake. Its main purpose is to help you master the professional development workflow: **Forking, Cloning, Branching, Committing, and creating Pull Requests (PRs).**

This is a dry run before our main project. Mastering this workflow will ensure the actual project runs smoothly.

---

## Part 1: Initial Setup and Running the Project

Before you can start coding, you need to set up your environment and ensure the base project runs correctly.

### Prerequisites (What to Install on Windows)

You need to install three essential tools. **Follow the instructions exactly.**

1.  **Git Bash:** This provides the professional terminal commands needed for Git and Linux-style commands on Windows.
    *   **Install Git:** Download and run the installer from [git-scm.com](https://git-scm.com/download/win). Use all the default installation options.
    *   *Verification:* Open the **Git Bash** application and type `git --version`.
2.  **MinGW (GCC Compiler):** This is the C++ compiler we will use.
    *   *Verification:* Open **Git Bash** and type `g++ --version`. If this shows a version number, you are set. (If you installed MinGW via an installer like TDM-GCC, ensure its `bin` directory is in your system PATH).
3.  **CMake:** This tool manages the building of our C++ project.
    *   **Install CMake:** Download the installer from [cmake.org/download](https://cmake.org/download/). **CRUCIAL STEP: When prompted, select the option: "Add CMake to the system PATH for all users."**
    *   *Verification:* Open **Git Bash** and type `cmake --version`.

### VS Code Extension (Optional but Recommended)

To simplify building directly within VS Code, install the **CMake Tools** extension.

### Build Steps: Running the Existing Code

Once your environment is configured, follow these steps in your **Git Bash window**.

1.  **Clone the Repository:**
    *   Navigate to the folder where you want your project to live (e.g., your Documents folder).
    ```bash
    cd ~/Documents
    ```
    *   Go to the main repository page and copy the HTTPS URL.
    *   Run:
    ```bash
    # This command creates a new folder named 'practice-project'
    git clone https://github.com/lst-cpp-project-2025-2026/practice-project.git
    cd practice-project # Navigate into the new folder
    ```

2.  **Prepare to Build:**
    *   We create a separate folder for temporary build files.
    ```bash
    mkdir build
    cd build
    ```

3.  **Configure the Project (Crucial Step for MinGW):**
    *   This step tells CMake how to build the project and explicitly tells it to use the MinGW Makefiles generator, which is necessary when using MinGW outside of a dedicated IDE environment.
    ```bash
    cmake -G "MinGW Makefiles" .. 
    ```

4.  **Build the Project:**
    *   This compiles the code and creates the executable file.
    ```bash
    cmake --build .
    ```

5.  **Run the Application:**
    *   On Windows, the executable will be inside the `build` folder.
    ```bash
    ./RaylibPracticeProject.exe
    ```
    *   A blank window should appear and then close. Success!

---

## Part 2: The Contribution Workflow (Your Task)

This section details the professional workflow for accepting a task, coding it, and submitting it for review.

### Your Task

Your goal is to find an issue, add a simple box containing your name to the window in `src/main.cpp`, and submit a Pull Request (PR).

### Step-by-Step GitHub Workflow

Follow these exact steps in order. **Do not skip any steps!**

#### **Step 1: Get the Assignment (On GitHub)**

1.  Go to the **Issues** tab on the original repository on GitHub.
2.  Find an open issue (e.g., "Add the name box for [Your Name]").
3.  **Comment on the issue:** Write "I'd like to take this!"
4.  Wait for the group lead (`bilal-houari`) to assign the issue to you.

#### **Step 2: Fork the Repository (On GitHub)**

1.  Go to the main repository page on GitHub.
2.  Click the **Fork** button (usually in the top right). This creates a personal copy of the project under your own GitHub account.

#### **Step 3: Clone Your Fork Locally (In Git Bash)**

*If you previously cloned the original repository, delete that folder first and start fresh with your fork.*

1.  Go to **your personal fork** on GitHub.
2.  Click the **Code** button and copy the HTTPS URL for your fork (it will include your username).
3.  In Git Bash (navigated to your projects folder), clone your fork:
    ```bash
    git clone <your-fork-url>
    cd practice-project
    ```

#### **Step 4: Link to Upstream (The Original Repo)**

*This allows you to easily pull in changes made by other classmates.*

1.  In your Git Bash terminal, add a link called `upstream`:
    ```bash
    git remote add upstream https://github.com/lst-cpp-project-2025-2026/practice-project.git
    ```

#### **Step 5: Create a Feature Branch**

*Always work on a new branch for new tasks! This keeps your main branch clean.*

1.  Ensure your local copy of the main branch (`master`) is up-to-date:
    ```bash
    git checkout master               # Switch to the master branch
    git pull upstream master          # Pull any recent changes from the original repo
    ```
2.  Create and switch to your new branch (use a clear name, like the issue title):
    ```bash
    # Replace 'your-name' with your actual name or a simple description
    git checkout -b feature/add-your-name 
    ```

#### **Step 6: Code the Feature (In VS Code)**

1.  Open the `practice-project` folder in VS Code.
2.  Edit the file **`src/main.cpp`** and add the box and your name as specified in your assigned issue.
3.  **Test your code!** Re-run the configuration and build steps (Part 1, Steps 3, 4, 5) to make sure the program runs correctly with your changes. *(Remember to navigate back into the `build` directory before running steps 3 and 4).*

#### **Step 7: Commit and Push (In Git Bash)**

1.  Go back to Git Bash and "stage" your changes (prepare them for commit):
    ```bash
    git add src/main.cpp 
    ```
2.  "Commit" your changes (save them locally with a descriptive message):
    ```bash
    # CRITICAL: Always include the issue number (e.g., #1, #2, etc.)!
    git commit -m "feat: Add box for [Your Name] and resolve issue #XX" 
    ```
3.  "Push" your new branch to your personal fork on GitHub:
    ```bash
    git push origin feature/add-your-name
    ```

#### **Step 8: Create the Pull Request (PR) (On GitHub)**

1.  Go to the GitHub page for **your fork**.
2.  GitHub will prompt you to create a Pull Request from your pushed branch. Click **"Compare & pull request."**
3.  **Verify the Direction (VERY IMPORTANT!):**
    *   **base repository:** should be the original organization project's (`lst-cpp-project-2025-2026/practice-project`) `master` branch.
    *   **head repository:** should be your fork's (`YourUsername/practice-project`) `feature/add-your-name` branch.
4.  Write a brief description and link the PR to your issue (e.g., "Closes #XX").
5.  Click **"Create pull request."**

#### **Step 9: Review and Merge**

1.  `bilal-houari` will review your code.
2.  If changes are requested, you will make them, commit, and push again to the same branch (Step 7). The PR will automatically update!
3.  Once approved, the changes will be merged into the main project! **You have successfully completed the workflow!**