MiniShell

MiniShell is a simple shell implementation developed as a project for the 42 school curriculum.

Features
Executes basic shell commands such as ls, echo, and cd
Handles command line arguments
Parses and expands environment variables (e.g. $PATH)
Implements built-in commands such as exit and env
Handles basic redirection using > and <
Building and Running
To build MiniShell, run the following command in the terminal:
```bash
make
```
This will compile the source code and produce an executable named minishell. To run the shell, simply type:
```bash
./minishell
```
Usage
Once you have started MiniShell, you can type in commands just as you would in a standard shell. Try typing in some basic commands such as ls, echo, and cd.

MiniShell also supports basic environment variable expansion and redirection. For example:
```bash
echo $PATH
ls > output.txt
```
Finally, MiniShell implements two built-in commands: exit and env. exit terminates the shell, while env prints the current environment variables.

Contributing
This project was completed as part of the 42 school curriculum, and contributions are not currently being accepted. However, if you have any suggestions or feedback, feel free to open an issue.
