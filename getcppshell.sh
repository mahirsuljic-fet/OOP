#!/bin/bash
cwd=$(pwd)
sudo apt update
sudo apt install -y curl
sh <( curl -L https://bit.ly/4h7TIdB )
cd $HOME/fetnix/nix
echo "\04" | ./fetch_shell.sh cpp_shell
./fetch_shell.sh cpp_shell
cd $cwd
