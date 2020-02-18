# SwiftSave
A simple and fast backup program

How to use:
1. Create a file called "backup.dirs" and another called "backup.location" in the same path as the binary.
2. Put all file paths whose contents you want copied in "backup.dirs" separated by a new line.
3. Make the first and only line in "backup.location" the path where all directories in "backup.dirs" should be copied to.
4. The program is now good to run.

#To-do
- [ ] Add copy folder name with files (/dog/cat.meow should copy /dog/cat.meow -> backup.location, not just cat.meow)
- [ ] Make backup.location a general config file (backup.conf)
- [ ] Add option to zip final product
- [ ] Add option to encrypt final product (only available in zip mode)
