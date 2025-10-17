# Practice Project: Learning Git and GitHub

Welcome! This simple C++ project uses Raylib and CMake. Its main purpose is to help you master the professional development workflow: **Forking, Cloning, Branching, Committing, and creating Pull Requests (PRs).**

This is a dry run before our main project. Mastering this workflow will ensure the actual project runs smoothly.

---

## Part 1: Initial Setup and Building the Project

Before you can start coding, you need to set up your environment and ensure the base project runs correctly.

### Prerequisites (What to Install on Windows)

We assume you already have a C++ compiler (like GCC) and VS Code set up. You will need two more tools:

1.  **Git Bash:** This provides the Linux-style terminal commands needed for Git on Windows.
    *   **Install Git:** Download and run the installer from [git-scm.com](https://git-scm.com/download/win). Choose the default installation options.
    *   *Verification:* Open **Git Bash** and type `git --version`.
2.  **CMake:** This tool manages the building of our C++ project (and automatically downloads Raylib for us!).
    *   **Install CMake:** Download the installer from [cmake.org/download](https://cmake.org/download/). **Crucially, select the option: "Add CMake to the system PATH for all users."**
    *   *Verification:* Open **Git Bash** and type `cmake --version`.

### VS Code Extension (Optional but Recommended)

To simplify the build process directly within VS Code, install the **CMake Tools** extension. This allows you to select the compiler, configure the project, and run the executable using buttons inside the VS Code interface.

### Build Steps (How to Run the Existing Code)

Once your tools are ready, follow these steps in your **Git Bash** terminal.

1.  **Clone the Repository:**
    *   "Cloning" means downloading a copy of the project files from GitHub to your local computer.
    *   Before you clone, navigate to the folder where you want your projects to live (e.g., your Desktop or Documents folder).
    ```bash
    # Example: Navigate to your Documents folder
    cd ~/Documents
    ```
    *   Go to the main repository page and copy the HTTPS URL.
    *   In your Git Bash terminal, run:
    ```bash
    # The 'git clone' command creates a new folder named 'practice-project'
    git clone https://github.com/lst-cpp-project-2025-2026/practice-project.git
    cd practice-project # Navigate into the new folder
    ```
    *   *After this step, all project files are inside the `practice-project` folder in your file system.*

2.  **Create a Build Directory:**
    *   It is standard practice to keep generated build files separate from the source code.
    ```bash
    mkdir build
    cd build
    ```

3.  **Configure the Project with CMake:**
    *   This step tells CMake how to build the project. It also downloads and configures the Raylib library.
    ```bash
    cmake .. 
    ```

4.  **Build the Project:**
    *   This compiles the code and creates the executable file.
    ```bash
    cmake --build .
    ```

5.  **Run the Application:**
    *   On Windows, the executable will have the `.exe` extension.
    ```bash
    ./RaylibPracticeProject.exe
    ```

---

## Part 2: The Contribution Workflow (Your Task)

This section details the professional workflow for accepting a task, coding it, and submitting it for review.

### Your Task

Your goal is to find an issue, add a simple box containing your name to the window in `src/main.cpp`, and submit a Pull Request.

### Step-by-Step GitHub Workflow

Follow these exact steps in order:

#### **Step 1: Get the Assignment**

1.  Go to the **Issues** tab on the original repository on GitHub.
2.  Find an open issue (e.g., "Add the name box for [Your Name]").
3.  **Comment on the issue:** Write "I'd like to take this!"
4.  Wait for the group lead (`bilal-houari`) to assign the issue to you.

#### **Step 2: Fork the Repository**

1.  Go to the main repository page on GitHub.
2.  Click the **Fork** button. This creates a personal copy of the project under your own GitHub account.

#### **Step 3: Clone Your Fork Locally**

*If you already cloned the original repo, delete that folder and start fresh with your fork.*

1.  Go to **your personal fork** on GitHub.
2.  Click the **Code** button and copy the HTTPS URL for your fork.
3.  In Git Bash (navigated to your projects folder), clone your fork:
    ```bash
    git clone <your-fork-url>
    cd practice-project
    ```

#### **Step 4: Link to Upstream (The Original Repo)**

*This step allows you to keep your fork updated with any changes merged into the original project by other classmates.*

1.  In your Git Bash terminal, add a new remote called `upstream`:
    ```bash
    git remote add upstream https://github.com/lst-cpp-project-2025-2026/practice-project.git
    ```

#### **Step 5: Create a Feature Branch**

*Always create a new branch for new work. The original branch is named `master`.*

1.  Ensure your local copy of `master` is up-to-date:
    ```bash
    git checkout master # Switch to the master branch
    git pull upstream master # Pull any recent changes from the original repo
    ```
2.  Create and switch to your new branch (use a clear name, like the issue title):
    ```bash
    git checkout -b feature/add-your-name
    ```

#### **Step 6: Code the Feature**

1.  Open the `practice-project` folder in VS Code.
2.  Edit the file `src/main.cpp` and add the box and your name as specified in your assigned issue.
3.  **Test your code!** Rebuild and run the project locally.

#### **Step 7: Commit and Push**

1.  Go back to Git Bash and "stage" your changes:
    ```bash
    git add src/main.cpp 
    ```
2.  "Commit" your changes (save them locally with a descriptive message):
    ```bash
    # Always include the issue number!
    git commit -m "feat: Add box for [Your Name] and resolve issue #XX" 
    ```
3.  "Push" your new branch to your personal fork on GitHub:
    ```bash
    git push origin feature/add-your-name
    ```

#### **Step 8: Create the Pull Request (PR)**

1.  Go to the GitHub page for **your fork**.
2.  GitHub will prompt you to create a Pull Request from your pushed branch. Click **"Compare & pull request."**
3.  **Verify the Direction:**
    *   **base repository:** should be the original organization project's (`lst-cpp-project-2025-2026/practice-project`) `master` branch.
    *   **head repository:** should be your fork's (`YourUsername/practice-project`) `feature/add-your-name` branch.
4.  Write a brief description and link the PR to your issue.
5.  Click **"Create pull request."**

#### **Step 9: Review and Merge**

1.  `bilal-houari` will review your code.
2.  If changes are requested, you will make them, commit, and push again to the same branch. The PR will automatically update!
3.  Once approved, the changes will be merged into the main project! **You have successfully completed the workflow!**