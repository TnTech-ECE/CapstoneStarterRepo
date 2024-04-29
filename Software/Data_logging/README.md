* What the software does
    - log_serial_to_csv.py
        - This script reads serial data from the chosen COM port, appends the current time, and stores it in a csv file.

    - organize_data.py
        - This script cleans up and organizes the raw serial data read by "log_serial_to_csv.py" and outputs to a new file.


* All dependencies
    - Python interpreter
    - csv module
    - re module
    - pyserial module

* How to Install
    - You will need a python interpreter to run these scripts. I recommend using PyCharm for running and editing these scripts.
    - You can install the python modules to your project by running "pip install <module_name>" in the terminal.

* How to run/How to use 
    - In PyCharm you simply need to configure a python interpreter for your project and hit the play button. If you get a busy COM port error, make sure VSCode or some other program is not already reading the COM port you have selected.