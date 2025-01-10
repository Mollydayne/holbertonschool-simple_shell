
![catmeme](https://github.com/user-attachments/assets/02f8dbac-ab01-46ae-a786-f1e96ebeebe0)

# 🐚 Simple Shell

Welcome to **Simple Shell**, we've tried to create a minimalist shell that functions as a command interpreter on Linux. This project was developed as part of the Holberton School program, in 2025. 🚀

---

## 📋 Description

The **Simple Shell** project is a simplified replica of the Bash shell. It provides basic functionalities to interpret and execute user-typed commands.

### 🌟 Key Features:
- Reads commands from the standard input.
- Searches for and executes programs located in directories defined by the `$PATH` environment variable.
- Handles arguments passed to commands.
- Error handling
- Supports built-in commands like `exit`.

---

## 📂 Project Structure

```
.
├── AUTHORS              # List of project contributors
├── README.md            # Project documentation
├── main.h               # Header file containing prototypes and definitions
├── main.c               # Main entry point of the shell
├── signal.c             # Signal intercepter command
├── splitline.c          # Command parsing and processing
├── userinput.c          # Command to get the input from the user
└── .gitignore           # File used to avoid pushing temp files or anything useless
```

---

## 🚀 Compilation and Execution

### ⚙️ Compilation
To compile the project, use `gcc` with the following options:
```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```

### ▶️ Execution
Run the shell in either interactive or non-interactive mode:
- **Interactive Mode:**
  ```bash
  ./hsh
  $ ls -l
  ```

- **Non-Interactive Mode:**
  ```bash
  echo "ls -l" | ./hsh
  ```

---

## 🛠️ Usage

### 📝 Supported Commands
- Any command available in directories defined by `$PATH`.
- Built-in commands such as:
  - `exit`: Exits the shell.

---

## 👩‍💻 Contributors

The authors of this project are listed in the [AUTHORS](./AUTHORS) file.

---

## 📖 Resources

- [Introduction to Shell](https://en.wikipedia.org/wiki/Shell_(computing)) 🐚
- [Thompson Shell : first Unix Shell](https://en.wikipedia.org/wiki/Thompson_shell)
- [Ken Thompson : creator of the unix shell](https://en.wikipedia.org/wiki/Ken_Thompson)

---

## 📜 License
Feel free to try to enhanced this project or add any functions ! 📚

---

Thank you for testing our shell! 🙌 If you have suggestions or feedback, just send a message. 😊

🐦‍⬛ 🌸 Mollydayne 🌸 🐦‍⬛
