# SwiftSave
A simple and fast backup program

# How to use:
1. Create a file called "backup.dirs" and another called "backup.conf" in the same path as the binary.
2. Put all file paths whose contents you want copied in "backup.dirs" separated by a new line.
3. Make the first and only line in "backup.conf" the path where all directories in "backup.dirs" should be copied to.
4. The program is now good to run.

# To-do
- [X] Add backup function to copy directory contents from backup.dirs to a specified copy location.
- [X] Make backup.location a general config file (backup.conf)
- [ ] Copy root dir along with dir contents  (Ex. /backupLocation/backedUpFiles/ instead of dumping all files into /backupLocation/)
- [ ] Add option to zip final product
- [ ] Add option to encrypt final product (only available in zip mode)
