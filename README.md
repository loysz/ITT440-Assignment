# Multi-Process Communication Using Pipes

This C program demonstrates multi-process communication using pipes. It creates a parent process that communicates with multiple child processes through a pipe. The parent process sends a message to the child processes, and each child process receives and displays the message.

## Table of Contents

- [Prerequisites](#prerequisites)
- [Getting Started](#getting-started)
- [Usage](#usage)
- [Customization](#customization)
- [Signals](#signals)
- [License](#license)

## Prerequisites

Before running the program, make sure you have the following:

- A C compiler (e.g., GCC) installed on your system.
- Basic knowledge of C programming.
- A Unix-like operating system (Linux, macOS) to run the signals.

## Getting Started

1. Clone this repository or download the `Assignment1.c` file to your local machine.

2. Compile the program using your C compiler:

   ```bash
   gcc Assignment1.c -o Assignment1
   ```

3. Run the compiled program:

   ```bash
   ./Assignment1
   ```

## Usage

1. The program will prompt you to enter a message for the parent process.

2. After entering the message, the program will ask how many child processes you want to create.

3. The parent process will send the message to the child processes through a pipe.

4. Each child process will receive the message and display it.

5. The parent process will wait for all child processes to finish before exiting.

6. You can exit the program by pressing `Ctrl+C` (SIGINT), `Ctrl+Z` (SIGTSTP), or `Ctrl+Backspace` (SIGQUIT) to capture and display specific signals.

## Customization

- You can modify the `buffer` size to change the maximum message length that can be sent between processes.

- Customize the code as needed to change the message handling logic, error handling, or any other functionality.

## Signals

The program includes signal handlers for three signals:

- `Ctrl+C` (SIGINT): Captured by the `sigint_handler`. It displays a message when the user presses `Ctrl+C`.

- `Ctrl+Z` (SIGTSTP): Captured by the `sigtstp_handler`. It displays a message when the user presses `Ctrl+Z`.

- `Ctrl+Backspace` (SIGQUIT): Captured by the `sigquit_handler`. It displays a message when the user presses `Ctrl+Backspace`.
