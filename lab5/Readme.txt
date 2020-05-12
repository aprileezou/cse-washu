Qi Yang: Question 1,2,4,6, Readme.txt
Yixuan Cheng: Question 3, Readme.txt
Jingxuan Zou: Question 5, Readme.txt


***Test 1***  ls
We can successfully show all the name of each file in the directory.

[Output]:
To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root $ ls
file.txt
image.img
dir


***Test 2*** ls -1
We can successfully show all the type and size of each file in the directory.

[Output]:
To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root $ ls -1
file.txt        text     size: 6
image.img       image    size: 0
dir     directory        size: 0

***Test 3*** cat file.txt 
We can successfully re-write the file with the command ":wq" while the input will now be saved with the command ":q"

[Output]
[:wq]
To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root $ cat file.txt
Enter data you would like to write to the file. Enter :wq to save the file and exit, enter :q to exit without saving
1234
:wq
To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root $ ds file.txt
1234

[:q]
To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root $ cat file.txt
Enter data you would like to write to the file. Enter :wq to save the file and exit, enter :q to exit without saving
4567
:q
To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root $ ds file.txt
1234


***Test 4*** cat file.txt -a 
We can successfully append the file with the command ":wq" while the input will now be saved with the command ":q"

[Output]
[:wq]
To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root $ cat file.txt -a
root/file.txt
Enter data you would like to write to the file. Enter :wq to save the file and exit, enter :q to exit without saving
1234
:wq
To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root $ ds file.txt
1234
1234

[:q]
To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root $ cat file.txt -a
root/file.txt
Enter data you would like to write to the file. Enter :wq to save the file and exit, enter :q to exit without saving
4567
:q
To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root $ ds file.txt
1234
1234

***Test 5*** ds image.img
We can successfully show the formated file.

[Output]
To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root $ ds image.img
X X
 X
X X

***Test 6*** ds image.img -d 
We can successfully show the unformatted files.

[Output]
To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root $ ds image.img -d
X X X X X


***Test 7*** cp file.txt root/dir
successfully copy the file.txt to the root/dir directory

[Output]
To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root $ cp file.txt root/dir
To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root $ cd dir
To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root/dir $ ls
file.txt

***Test 8*** cd dir
open the dir and we can see the file.txt inside

[Output]
root $ cd dir
To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root/dir $ ls
file.txt

***Test 9*** cat file.txt
the file.txt in root/dir is changed but the file.txt in root is still the original

[Output]
To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root $ cp file.txt root/dir
To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root $ ls
file.txt
image.img
dir
To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root $ cd dir
To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root/dir $ ls
file.txt
To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root/dir $ cat file.txt
Enter data you would like to write to the file. Enter :wq to save the file and exit, enter :q to exit without saving
1234
:wq
To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root/dir $ ds file.txt
1234
To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root/dir $ cd ..
To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root $ ls
file.txt
image.img
dir
To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root $ ds file.txt
cse332

***Test 10*** rm dir
We cannot remove a folder which has a file in it.

[Output]
To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root $ cd dir
To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root/dir $ ls
file.txt
To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root $ rm dir
unable to remove non-empty directory

***Test 11*** rm dir -r
We can successfully remove a folder with this command.

[Output]
To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root $ rm dir -r
To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root $ ls
file.txt
image.img


*** Errors and warnings ***
a. 'CatCommand::execute': not all control paths return a value	lab5	H:\lab5\lab5\CatCommand.cpp	88	

b. 'return': conversion from 'size_t' to 'unsigned int', possible loss of data	lab5	H:\lab5\lab5\DirectoryFile.cpp	16	

c. 'directorynotcopable': undeclared identifier	lab5	H:\lab5\lab5\CopyCommand.cpp	17	

d. Arithmetic overflow: Using operator '*' on a 4 byte value and then casting the result to a 8 byte value. Cast the value to the wider type before calling operator '*' to avoid overflow (io.2).	lab5	H:\LAB5\LAB5\IMAGEFILE.CPP	35	
