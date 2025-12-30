#/!bin/bash

# GIT IGNORE DIRECTORY ADITION FOR PLATFORMIO PROJECTS

echo $(pwd)/build/ >> ~/Documents/School/.gitignore
echo $(pwd)/.cache/ >> ~/Documents/School/.gitignore
echo $(pwd)/.vscode/ >> ~/Documents/School/.gitignore
echo $(pwd)/.devcontainer/ >> ~/Documents/School/.gitignore
echo $(pwd)/sdkconfig >> ~/Documents/School/.gitignore
echo $(pwd)/sdkconfig.old >> ~/Documents/School/.gitignore
echo $(pwd)/.pio >> ~/Documents/School/.gitignore
echo $(pwd)/.gitignore >> ~/Documents/School/.gitignore


echo "Directory $(pwd)/"
echo "successfully gitIngnored"

