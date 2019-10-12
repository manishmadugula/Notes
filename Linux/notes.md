# Power User
* ###  to delete last typed word
        ctrl + w 

* ###  to delete up to the end of line
        ctrl + k 

* ###  to delete all the way back to start of line
        ctrl + u

* ### to clear the screen
        ctrl + l

* ### to retrieve nth argument
        !:n 

* ### to retrieve last 2 arguments
        !:1-2

* ### to cycle through arguments.
        Alt + .

* ### to redo last command.
        !!

* ### to run last command with sudo.
        sudo !!

* ### to open the command in default editor.
        ctrl + x + e

* ### to edit the previous messed up command in default editor
        fc

* ### Quickly create subfolders (No spaces).
        mkdir -p manish/Notes/{Code,Databases,OS,Networking,Linux,System_Design}/{Videos,Text}

* ### exit terminal but leave all processes running
        disown -a && exit

* ### Use tags in conjunction with Ctrl + R to get commonly used commands instantaneously.

        some_command -some_flag some_path #useful


# Help in Building Code

* ### analyses filename
        file "filename"

# Search

* ### find with regex 
        find -type f -regex "*/A[^/]+\.sh$"

# Conditionals

* ### && -> second command executes only if first does.
        first_command && second_command

* ### || -> second command executes only if first does not.
        first_command || second_command

* ### ; -> commands execute sequentially.
        first_command ; second_command

# Utility

* ### Working with zip files

    * #### To decompress

           gzip -d file.gz

    *  #### To compress

            gzip file.gz

# Networking
* ### Network Adapters

        ifconfig

* ### CURL

    * #### To simply see the webpage
            curl www.google.com

    * #### To download from webpage
            curl -o new_file_name file_url

* ### Ping
    Sends tiny network packets and diagnoses network problems.

            ping www.google.com

* ### TraceRoute
    Displays all the hops between your PC and destination server.

            traceroute www.google.com

* ### Local port forwarding
    If you don't have access to some site say imgur.com but you have access to a remotehost which has access to imgur you can perform local port forwarding to access the site. The key here is -L which says we’re doing local port forwarding. -N prevents disconnection. Forward user's local port 9000 to imgur.com at port 80 on server/remotehost.

            ssh -L -N 9000:imgur.com:80 user@remotehost

     If you need to access a port on your server which can only be accessed from localhost and not remotely. Forward user's local port 9000 to port 5432 on the server.

             ssh -L -N 9000:localhost:5432 user@example.com

* ### Remote port forwarding

    [Link](https://blog.trackets.com/2014/05/17/ssh-tunnel-local-and-remote-port-forwarding-explained-with-examples.html)

* ### SSH
    [Link](https://vimeo.com/54505525?cjevent=e05dfa7087a311e9839b011f0a180510)


        ssh -L 3337:127.0.0.1:6379 root@emkc.org -N

* ### escape sequences

     To break from the ssh session

        hit enter and then ~ + .

     More escape sequences can be listed by pressing

        hit enter then ~ + ?

* ### SSH LOGS

        /var/log/auth.log

# Misc

* ### woof
* ### fuzzy finder

# Facts
* ### Adding space in front of command makes the command not stored by bash_history. 

# Not Useful Yet

* ### rsync

* ### searches the man pages of all commands.
        apropos "query"

* ### Terminal Incognito


# From office
- top
- Jobs
- Ps
- Htop
- Ptree
- Kill
- Killall
- Denice
- netstat -nutlp
- fuser PORT_NUMBER/tcp
- sudo fuser -k PORTNUMBER/tcp
- tcptrack
- nslookup
- Tcpdump
- Ifconfig
- Ping
- dig domain
- dig -x IP
- netstat -an
- curl --libcurl
- Which
- Whereis
- dpkg 
- dpkg-query -L Firefox
- find /-name Google -type f 2>&1 | grep google
- locate
- grep -inr
- sed
- w
- Last
- Uptime
- Users
- Who
- Whoami
- Rsync
- Ash
- Unlimited history
- Chmod
- strace -o logfile -fF make 
- Use absolute paths in Linux
- ./configure 
- Change release by git checkout tags/tagname
- ln -s source linkname : Softlink
- ln source linkname : Hardlink
- file
- nm -l
- ldd
- objdump -tTC filename
- c++filt 
- strings binary_file
- readelf --all 
- lsof
- uname -a
- lspci
- git reset - undo local changes
- Vim %s/search/replace/gc
- tty
- comm
- expr
- env
- du -sh *
- whatis
- time
- Compgen -c
- Compgen -b
- serverfault what all useful things one can add to bashrc
- Slashroot Linux processes administration and monitoring tutorial.
