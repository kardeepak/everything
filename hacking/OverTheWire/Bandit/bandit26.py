"""
This level cannot be solved by a python script.
If you look at the /etc/passwd file you will see that the default shell for bandit26 is /usr/bin/showtext,
which uses more command to show a text file and the exits the shell.
To stop the shell from exiting, resize your terminal window so that the text file doesn't fit in your window.
Once the more command stops, you can make your terminal big again.
Press 'v' to enter into vi editor.
Then type ":set shell=/bin/bash" to change the defualt shell used by vi.
Then type ":shell" to access bash.
Now in your how folder there is a file called "bandit27-do" that will execute any command as the user bandit27.
Type command "./bandit27-do cat /etc/bandit_pass/bandit27" to read the password.
"""